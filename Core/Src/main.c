/* USER CODE BEGIN Header */

/* USER CODE END Header */

#include "main.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "OLED.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PTD */

typedef struct
{
  GPIO_TypeDef *port;
  uint16_t      pin;
} LedDef_t;

typedef struct __attribute__((packed))
{
  uint8_t  header;
  uint8_t  run;
  uint8_t  dir;
  uint16_t step_ms;
  uint8_t  checksum;
} CtrlPacket_t;
/* USER CODE END PTD */

/* USER CODE BEGIN PD */
#define LED_NUM                 3U
#define LED_LEVEL_ON            GPIO_PIN_SET
#define LED_LEVEL_OFF           GPIO_PIN_RESET

#define STEP_MIN_MS             100U
#define STEP_MAX_MS             2000U
#define STEP_DEFAULT_MS         300U

#define KEY_LOCKOUT_MS          200U

#define PKT_HEADER              0xAAU

#define OLED_LINE_NUM           4U
#define OLED_COL_MAX            16U

#define OLED_SELFTEST           0
/* USER CODE END PD */

/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* USER CODE BEGIN PV */
static const LedDef_t s_ledTable[LED_NUM] =
{
  { LED0_GPIO_Port, LED0_Pin },
  { LED1_GPIO_Port, LED1_Pin },
  { LED2_GPIO_Port, LED2_Pin },
};

static uint8_t  s_run      = 1U;
static uint8_t  s_dir      = 0U;
static uint16_t s_stepMs   = STEP_DEFAULT_MS;
static uint8_t  s_ledIndex = 0U;

static uint32_t s_lastStepTick = 0U;
static uint32_t s_dirKeyTick   = 0U;
static uint32_t s_pauseKeyTick = 0U;

static CtrlPacket_t      s_rxPacket;
static CtrlPacket_t      s_readyPacket;
static volatile uint8_t  s_packetReady = 0U;

static volatile uint8_t  s_keyDirFlag   = 0U;
static volatile uint8_t  s_keyPauseFlag = 0U;

static char             s_txBuf[48];
static volatile uint8_t s_txBusy    = 0U;
static volatile uint8_t s_txPending = 0U;

static volatile uint8_t s_displayDirty = 1U;
/* USER CODE END PV */

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

/* USER CODE BEGIN 0 */

static void Led_Write(uint8_t idx, uint8_t on)
{
  GPIO_PinState level = (on != 0U) ? LED_LEVEL_ON : LED_LEVEL_OFF;
  HAL_GPIO_WritePin(s_ledTable[idx].port, s_ledTable[idx].pin, level);
}

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

static void LedFlow_Task(void)
{
  uint32_t now = HAL_GetTick();

  if (s_run == 0U)
  {
    return;
  }

  if ((uint32_t)(now - s_lastStepTick) < (uint32_t)s_stepMs)
  {
    return;
  }

  s_lastStepTick = now;

  if (s_dir == 0U)
  {
    s_ledIndex = (uint8_t)((s_ledIndex + 1U) % LED_NUM);
  }
  else
  {
    s_ledIndex = (uint8_t)((s_ledIndex + LED_NUM - 1U) % LED_NUM);
  }

  Led_ShowIndex(s_ledIndex);
  s_displayDirty = 1U;
}

static void Key_Task(void)
{
  uint32_t now = HAL_GetTick();

  if (s_keyDirFlag != 0U)
  {
    s_keyDirFlag = 0U;

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
        s_lastStepTick = now;
      }

      s_displayDirty = 1U;
      Status_Send();
    }
  }
}

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
  pkt   = s_readyPacket;
  bytes = (const uint8_t *)&pkt;

  expected = (uint8_t)(bytes[0] + bytes[1] + bytes[2] + bytes[3] + bytes[4]);

  if (pkt.header != PKT_HEADER)
  {
    return;
  }
  if (pkt.checksum != expected)
  {
    return;
  }
  if ((pkt.run > 1U) || (pkt.dir > 1U))
  {
    return;
  }
  if ((pkt.step_ms < STEP_MIN_MS) || (pkt.step_ms > STEP_MAX_MS))
  {
    return;
  }

  s_run    = pkt.run;
  s_dir    = pkt.dir;
  s_stepMs = pkt.step_ms;

  s_lastStepTick = HAL_GetTick();

  s_displayDirty = 1U;
  Status_Send();
}

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

  OLED_BufClear();

  (void)snprintf(buf, sizeof(buf), "STATE: %s", (s_run != 0U) ? "RUN" : "PAUSE");
  Display_Line(1U, buf);

  (void)snprintf(buf, sizeof(buf), "DIR: %s", (s_dir != 0U) ? "REV" : "FWD");
  Display_Line(2U, buf);

  (void)snprintf(buf, sizeof(buf), "STEP: %ums", (unsigned int)s_stepMs);
  Display_Line(3U, buf);

  (void)snprintf(buf, sizeof(buf), "LED: %u", (unsigned int)(s_ledIndex + 1U));
  Display_Line(4U, buf);

  OLED_Flush();
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

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  OLED_Init();
  LedFlow_Init();

#if (OLED_SELFTEST == 1)

  for (;;)
  {
  }
#elif (OLED_SELFTEST == 2)

  {
    uint8_t x, y, i;

    OLED_BufClear();

    for (x = 0U; x < 128U; x++)
    {
      OLED_BufPixel(x, 0U, 1U);
      OLED_BufPixel(x, 63U, 1U);
    }
    for (y = 0U; y < 64U; y++)
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

  s_displayDirty = 1U;

  (void)HAL_UART_Receive_IT(&huart1, (uint8_t *)&s_rxPacket, sizeof(s_rxPacket));

  Status_Send();
  /* USER CODE END 2 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    Key_Task();
    Packet_Task();
    LedFlow_Task();
    Display_Task();
    Uart_Task();
  }
  /* USER CODE END 3 */
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    if (s_packetReady == 0U)
    {
      s_readyPacket = s_rxPacket;
      s_packetReady = 1U;
    }

    (void)HAL_UART_Receive_IT(&huart1, (uint8_t *)&s_rxPacket, sizeof(s_rxPacket));
  }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    s_txBusy = 0U;
  }
}
/* USER CODE END 4 */

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */

  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */

  /* USER CODE END 6 */
}
#endif
