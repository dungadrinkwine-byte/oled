/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "OLED.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* 灯表：把“第几盏灯”和“哪个端口、哪个引脚”解耦，增删灯只改这张表 */
typedef struct
{
  GPIO_TypeDef *port;
  uint16_t      pin;
} LedDef_t;

/* 串口数据包：AA RUN DIR STEP_L STEP_H CHECK，共 6 字节
   packed 让结构体没有对齐填充，sizeof 恰好等于 6，可以直接拿来接收 */
typedef struct __attribute__((packed))
{
  uint8_t  header;      /* 固定 0xAA */
  uint8_t  run;         /* 00 暂停 / 01 运行 */
  uint8_t  dir;         /* 00 正向 / 01 反向 */
  uint16_t step_ms;     /* 低字节在前，范围 100~2000 */
  uint8_t  checksum;    /* 前 5 字节之和取低 8 位 */
} CtrlPacket_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LED_NUM                 3U
#define LED_LEVEL_ON            GPIO_PIN_SET       /* 板子为高电平点亮 */
#define LED_LEVEL_OFF           GPIO_PIN_RESET

#define STEP_MIN_MS             100U
#define STEP_MAX_MS             2000U
#define STEP_DEFAULT_MS         300U

#define KEY_LOCKOUT_MS          200U               /* 按键消抖锁定窗口 */

#define PKT_HEADER              0xAAU

#define OLED_LINE_NUM           4U
#define OLED_COL_MAX            16U

/* 屏自检：0 正常运行；1 只清屏后停住（看噪点还在不在）；2 四行写满 16 列测试图。
   用来区分“屏幕本身有问题”和“程序没写满”。平时保持 0。 */
#define OLED_SELFTEST           0
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static const LedDef_t s_ledTable[LED_NUM] =
{
  { LED0_GPIO_Port, LED0_Pin },
  { LED1_GPIO_Port, LED1_Pin },
  { LED2_GPIO_Port, LED2_Pin },
};

/* 唯一的一份运行状态：按键、串口、流水灯、OLED、串口反馈都读写这几个变量 */
static uint8_t  s_run      = 1U;                    /* 1 运行 / 0 暂停 */
static uint8_t  s_dir      = 0U;                    /* 0 正向 / 1 反向 */
static uint16_t s_stepMs   = STEP_DEFAULT_MS;       /* 相邻 LED 切换间隔 */
static uint8_t  s_ledIndex = 0U;                    /* 0~2，对应 LED1~LED3 */

static uint32_t s_lastStepTick = 0U;
static uint32_t s_dirKeyTick   = 0U;
static uint32_t s_pauseKeyTick = 0U;

/* 串口接收：s_rxPacket 由中断写入，s_readyPacket 交给主循环处理 */
static CtrlPacket_t      s_rxPacket;
static CtrlPacket_t      s_readyPacket;
static volatile uint8_t  s_packetReady = 0U;

/* 中断只置标志，具体处理都在主循环 */
static volatile uint8_t  s_keyDirFlag   = 0U;
static volatile uint8_t  s_keyPauseFlag = 0U;

/* 串口中断发送的缓冲区必须一直有效，所以不能是局部变量 */
static char             s_txBuf[48];
static volatile uint8_t s_txBusy    = 0U;
static volatile uint8_t s_txPending = 0U;

/* 显示：dirty 表示状态变过，只有变过才重画一次整屏 */
static volatile uint8_t s_displayDirty = 1U;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static void Led_Write(uint8_t idx, uint8_t on);
static void Led_ShowIndex(uint8_t idx);
static void LedFlow_Init(void);
static void LedFlow_Task(void);
static void Key_Task(void);
static void Packet_Task(void);
static void Display_Line(uint8_t line, const char *text);
static void Display_Refresh(void);
static void Display_Task(void);
static void Status_Send(void);
static void Uart_Task(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* 写第 idx 盏灯，on 为 1 点亮、0 熄灭 */
static void Led_Write(uint8_t idx, uint8_t on)
{
  GPIO_PinState level = (on != 0U) ? LED_LEVEL_ON : LED_LEVEL_OFF;
  HAL_GPIO_WritePin(s_ledTable[idx].port, s_ledTable[idx].pin, level);
}

/* 同一时刻只点亮一盏：目标灯点亮，其余全灭 */
static void Led_ShowIndex(uint8_t idx)
{
  uint8_t i;

  for (i = 0U; i < LED_NUM; i++)
  {
    Led_Write(i, (i == idx) ? 1U : 0U);
  }
}

static void LedFlow_Init(void)
{
  s_run      = 1U;
  s_dir      = 0U;
  s_stepMs   = STEP_DEFAULT_MS;
  s_ledIndex = 0U;

  Led_ShowIndex(s_ledIndex);
  s_lastStepTick = HAL_GetTick();
}

/* 非阻塞流水灯：每次路过只问一句“距离上次换灯够一个间隔了吗” */
static void LedFlow_Task(void)
{
  uint32_t now = HAL_GetTick();

  if (s_run == 0U)
  {
    return;                                   /* 暂停：保留当前灯，计时也不推进 */
  }

  if ((uint32_t)(now - s_lastStepTick) < (uint32_t)s_stepMs)
  {
    return;
  }

  s_lastStepTick = now;                       /* 以实际换灯时刻为基准，误差不累积 */

  if (s_dir == 0U)
  {
    s_ledIndex = (uint8_t)((s_ledIndex + 1U) % LED_NUM);
  }
  else
  {
    s_ledIndex = (uint8_t)((s_ledIndex + LED_NUM - 1U) % LED_NUM);
  }

  Led_ShowIndex(s_ledIndex);
  s_displayDirty = 1U;                        /* 点亮的灯换了，OLED 的 LED 编号要跟着改 */
}

/* 按键处理：标志在中断里置位，消抖和状态更新都在这里做 */
static void Key_Task(void)
{
  uint32_t now = HAL_GetTick();

  if (s_keyDirFlag != 0U)
  {
    s_keyDirFlag = 0U;

    /* 锁定窗口 + 回读电平：抖动期间产生的多次下降沿只认第一次 */
    if (((uint32_t)(now - s_dirKeyTick) >= KEY_LOCKOUT_MS) &&
        (HAL_GPIO_ReadPin(KEY_DIR_GPIO_Port, KEY_DIR_Pin) == GPIO_PIN_RESET))
    {
      s_dirKeyTick   = now;
      s_dir         ^= 1U;
      s_displayDirty = 1U;
      Status_Send();
    }
  }

  if (s_keyPauseFlag != 0U)
  {
    s_keyPauseFlag = 0U;

    if (((uint32_t)(now - s_pauseKeyTick) >= KEY_LOCKOUT_MS) &&
        (HAL_GPIO_ReadPin(KEY_PAUSE_GPIO_Port, KEY_PAUSE_Pin) == GPIO_PIN_RESET))
    {
      s_pauseKeyTick = now;
      s_run         ^= 1U;

      if (s_run != 0U)
      {
        s_lastStepTick = now;                 /* 恢复运行：从现在起重新计时 */
      }

      s_displayDirty = 1U;
      Status_Send();
    }
  }
}

/* 数据包校验与应用：帧头、校验和、取值范围全部通过才生效 */
static void Packet_Task(void)
{
  CtrlPacket_t    pkt;
  const uint8_t  *bytes;
  uint8_t         expected;

  if (s_packetReady == 0U)
  {
    return;
  }

  s_packetReady = 0U;
  pkt   = s_readyPacket;                      /* 先拷出来，处理期间不影响接收下一包 */
  bytes = (const uint8_t *)&pkt;

  expected = (uint8_t)(bytes[0] + bytes[1] + bytes[2] + bytes[3] + bytes[4]);

  if (pkt.header != PKT_HEADER)               /* 帧头不对 */
  {
    return;
  }
  if (pkt.checksum != expected)               /* 校验和不对 */
  {
    return;
  }
  if ((pkt.run > 1U) || (pkt.dir > 1U))       /* 标志位只允许 0/1 */
  {
    return;
  }
  if ((pkt.step_ms < STEP_MIN_MS) || (pkt.step_ms > STEP_MAX_MS))
  {
    return;                                   /* 间隔越界 */
  }

  s_run    = pkt.run;
  s_dir    = pkt.dir;
  s_stepMs = pkt.step_ms;

  s_lastStepTick = HAL_GetTick();             /* 按新的间隔重新计时 */

  s_displayDirty = 1U;
  Status_Send();
}

/* 画一行：不足 16 字符用空格补齐，写进 RAM 帧缓冲（不直接发 I2C）。
   补齐是为了让整行 128 像素都被有效内容覆盖；真正推屏由 OLED_Flush() 一次完成。 */
static void Display_Line(uint8_t line, const char *text)
{
  char    buf[OLED_COL_MAX + 1U];
  uint8_t i;

  if ((line == 0U) || (line > OLED_LINE_NUM))
  {
    return;
  }

  for (i = 0U; i < OLED_COL_MAX; i++)
  {
    buf[i] = (text[i] != '\0') ? text[i] : ' ';
  }
  buf[OLED_COL_MAX] = '\0';

  OLED_BufString(line, 1U, buf);
}

static void Display_Refresh(void)
{
  char buf[OLED_COL_MAX + 1U];

  OLED_BufClear();                            /* 整帧从全 0 开始拼 */

  (void)snprintf(buf, sizeof(buf), "STATE: %s", (s_run != 0U) ? "RUN" : "PAUSE");
  Display_Line(1U, buf);

  (void)snprintf(buf, sizeof(buf), "DIR: %s", (s_dir != 0U) ? "REV" : "FWD");
  Display_Line(2U, buf);

  (void)snprintf(buf, sizeof(buf), "STEP: %ums", (unsigned int)s_stepMs);
  Display_Line(3U, buf);

  (void)snprintf(buf, sizeof(buf), "LED: %u", (unsigned int)(s_ledIndex + 1U));
  Display_Line(4U, buf);

  OLED_Flush();                               /* 8 页整块推送，每页一次传输 */
}

static void Display_Task(void)
{
  if (s_displayDirty == 0U)
  {
    return;
  }
  s_displayDirty = 0U;
  Display_Refresh();
}

/* 串口中断发送状态反馈；发送忙时只记一个“待发”，由主循环补发 */
static void Status_Send(void)
{
  int len;

  if (s_txBusy != 0U)
  {
    s_txPending = 1U;
    return;
  }

  len = snprintf(s_txBuf, sizeof(s_txBuf),
                 "STATE=%s,DIR=%s,STEP=%u,LED=%u\r\n",
                 (s_run != 0U) ? "RUN" : "PAUSE",
                 (s_dir != 0U) ? "REV" : "FWD",
                 (unsigned int)s_stepMs,
                 (unsigned int)(s_ledIndex + 1U));

  if (len <= 0)
  {
    return;
  }

  if (HAL_UART_Transmit_IT(&huart1, (uint8_t *)s_txBuf, (uint16_t)len) == HAL_OK)
  {
    s_txBusy = 1U;
  }
}

static void Uart_Task(void)
{
  if ((s_txBusy == 0U) && (s_txPending != 0U))
  {
    s_txPending = 0U;
    Status_Send();
  }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  OLED_Init();
  LedFlow_Init();

#if (OLED_SELFTEST == 1)
  /* 只清屏：如果这时右边缘的竖条噪点还在，说明那几列根本没被清到，
     与主程序无关，问题在驱动的列寻址或屏幕本身。 */
  for (;;)
  {
  }
#elif (OLED_SELFTEST == 2)
  /* 边框 + 四行 14 字符：边框把可见区四边标出来，用来判断
     ① 屏幕可见宽度到底是不是 128 列（右边框应的外框之外还有没有像素）；
     ② 16 列字符能不能完整写入（末尾缺字符 = 那些列写不进去）。 */
  {
    uint8_t x, y, i;

    OLED_BufClear();

    for (x = 0U; x < 128U; x++)               /* 上、下边框 */
    {
      OLED_BufPixel(x, 0U, 1U);
      OLED_BufPixel(x, 63U, 1U);
    }
    for (y = 0U; y < 64U; y++)                /* 左、右边框 */
    {
      OLED_BufPixel(0U, y, 1U);
      OLED_BufPixel(127U, y, 1U);
    }
    for (i = 0U; i < OLED_LINE_NUM; i++)
    {
      OLED_BufString((uint8_t)(i + 1U), 2U, "0123456789ABCD");
    }

    OLED_Flush();

    for (;;)
    {
    }
  }
#endif

  s_displayDirty = 1U;                        /* 让主循环第一轮画出完整状态 */

  /* 先启动一次接收，之后每次收满都在回调里重新启动 */
  (void)HAL_UART_Receive_IT(&huart1, (uint8_t *)&s_rxPacket, sizeof(s_rxPacket));

  Status_Send();                              /* 上电先回一行状态，方便确认串口通了 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    Key_Task();                               /* 按键消抖 + 状态切换 */
    Packet_Task();                            /* 数据包校验 + 应用设置 */
    LedFlow_Task();                           /* 非阻塞流水灯推进 */
    Display_Task();                           /* 状态变了才刷新 OLED */
    Uart_Task();                              /* 补发被忙时挤掉的反馈 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/**
  * @brief  外部中断回调：PA11 / PA12 出现下降沿时调用。
  * @note   回调里只置标志，消抖和状态更新留给主循环，保证中断足够短。
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == KEY_DIR_Pin)
  {
    s_keyDirFlag = 1U;
  }
  else if (GPIO_Pin == KEY_PAUSE_Pin)
  {
    s_keyPauseFlag = 1U;
  }
}

/**
  * @brief  串口接收完成回调：一包收满 6 字节后进入。
  * @note   先把数据整体复制到 s_readyPacket，再立刻重启接收，
  *         这样主循环处理当前包的同时还能继续收下一包。
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    if (s_packetReady == 0U)                  /* 主循环还没处理完上一包就丢弃新包 */
    {
      s_readyPacket = s_rxPacket;
      s_packetReady = 1U;
    }

    (void)HAL_UART_Receive_IT(&huart1, (uint8_t *)&s_rxPacket, sizeof(s_rxPacket));
  }
}

/**
  * @brief  串口发送完成回调：清忙标志，允许发送下一包反馈。
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    s_txBusy = 0U;
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
