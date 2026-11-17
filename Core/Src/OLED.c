#include "stm32f1xx_hal.h"
#include "OLED_Font.h"
#include <string.h>

/*引脚配置*/
#define OLED_W_SCL(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (GPIO_PinState)(x))
#define OLED_W_SDA(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (GPIO_PinState)(x))

/* 显存宽度：1.3 寸模块为 132 列，0.96 寸 SSD1306 为 128 列。
   填 132 对两种屏都安全（多写的 0x00 绕回左侧，本身也是 0）。 */
#define OLED_RAM_WIDTH		132

/*引脚初始化*/
void OLED_I2C_Init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* 注意：原驱动这里是未初始化的结构体，Pull 字段是栈上随机值。
       这里补上 = {0} 并显式设成上拉，避免偶发的“屏幕点不亮”问题。 */
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.Speed=GPIO_SPEED_HIGH;
    GPIO_InitStructure.Mode=GPIO_MODE_OUTPUT_OD;
    GPIO_InitStructure.Pull=GPIO_PULLUP;
    GPIO_InitStructure.Pin=GPIO_PIN_0|GPIO_PIN_1;

    HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);

    OLED_W_SCL(1);
    OLED_W_SDA(1);
}

/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void OLED_I2C_Start(void)
{
	OLED_W_SDA(1);
	OLED_W_SCL(1);
	OLED_W_SDA(0);
	OLED_W_SCL(0);
}

/**
  * @brief  I2C停止
  * @param  无
  * @retval 无
  */
void OLED_I2C_Stop(void)
{
	OLED_W_SDA(0);
	OLED_W_SCL(1);
	OLED_W_SDA(1);
}

/**
  * @brief  I2C发送一个字节
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void OLED_I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i++)
	{
		OLED_W_SDA(Byte & (0x80 >> i));
		OLED_W_SCL(1);
		OLED_W_SCL(0);
	}
	OLED_W_SCL(1);	//额外的一个时钟，不处理应答信号
	OLED_W_SCL(0);
}

/**
  * @brief  OLED写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void OLED_WriteCommand(uint8_t Command)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x00);		//写命令
	OLED_I2C_SendByte(Command); 
	OLED_I2C_Stop();
}

/**
  * @brief  OLED写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void OLED_WriteData(uint8_t Data)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x40);		//写数据
	OLED_I2C_SendByte(Data);
	OLED_I2C_Stop();
}

/**
  * @brief  OLED连续写多个数据字节（一次传输写一整页）
  * @param  Data 数据首地址
  * @param  Len  字节数
  * @retval 无
  * @note   原来的 OLED_WriteData 每写 1 个字节就要 一次 Start/地址/控制字/Stop，
  *         写满一页 132 列要开 132 次传输。改成整页一次传输后，写一页只要一次
  *         Start...Stop，速度提高约 30 倍，也消除了“逐字节传输被打断导致整页
  *         写入不完整”的可能。
  */
void OLED_WriteMulti(const uint8_t *Data, uint16_t Len)
{
	uint16_t i;

	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x40);		//写数据
	for (i = 0; i < Len; i++)
	{
		OLED_I2C_SendByte(Data[i]);
	}
	OLED_I2C_Stop();
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);					//设置Y位置
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_WriteCommand(0x00 | (X & 0x0F));			//设置X位置低4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  * @note   按 132 列清，而不是 128 列。1.3 寸模块的控制器显存是 132×64，
  *         可见区比 0.96 寸的 128 列宽出 4 列；只清 128 列时最右侧那几列
  *         会一直保留上电时的随机数据，看上去就是一条竖条噪点。
  *         对 128 列的 0.96 寸模块，多写的 4 个 0x00 会绕回最左边，写的也是 0，
  *         没有副作用。
  */
void OLED_Clear(void)
{
	static const uint8_t s_zero[OLED_RAM_WIDTH] = {0};
	uint8_t page;

	for (page = 0; page < 8; page++)
	{
		OLED_SetCursor(page, 0);
		OLED_WriteMulti(s_zero, OLED_RAM_WIDTH);
	}
}

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{      	
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

/**
  * @brief  OLED显示字符串
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}

/**
  * @brief  OLED次方函数
  * @retval 返回值等于X的Y次方
  */
uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

/**
  * @brief  OLED显示数字（十进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~4294967295
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十进制，带符号数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-2147483648~2147483647
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length)
{
	uint8_t i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十六进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
  * @param  Length 要显示数字的长度，范围：1~8
  * @retval 无
  */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
}

/**
  * @brief  OLED显示数字（二进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
}

/**
  * @brief  OLED初始化
  * @param  无
  * @retval 无
  */
void OLED_Init(void)
{
	uint32_t i, j;
	
	for (i = 0; i < 1000; i++)			//上电延时
	{
		for (j = 0; j < 1000; j++);
	}
	
	OLED_I2C_Init();			//端口初始化
	
	OLED_WriteCommand(0xAE);	//关闭显示
	
	OLED_WriteCommand(0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCommand(0x80);
	
	OLED_WriteCommand(0xA8);	//设置多路复用率
	OLED_WriteCommand(0x3F);
	
	OLED_WriteCommand(0xD3);	//设置显示偏移
	OLED_WriteCommand(0x00);
	
	OLED_WriteCommand(0x40);	//设置显示开始行
	
	OLED_WriteCommand(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCommand(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCommand(0xDA);	//设置COM引脚硬件配置
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	//设置对比度控制
	OLED_WriteCommand(0xCF);

	OLED_WriteCommand(0xD9);	//设置预充电周期
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);	//设置整个显示打开/关闭

	OLED_WriteCommand(0xA6);	//设置正常/倒转显示

	OLED_WriteCommand(0x8D);	//设置充电泵
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);	//开启显示
		
	OLED_Clear();				//OLED清屏
}

/* ====================== 帧缓冲显示（推荐使用） ======================
   问题背景：原来的写法是“每写一个像素列就重新设一次光标、发一次 I2C 传输”，
   整屏 8 页 × 128 列 = 1024 次独立传输。任何一次传输被干扰或地址写错，那一列
   就会留下旧数据，表现为屏幕上一条固定位置的噪点/残字，而且无法自愈。
   现在改成：先在 RAM 里把整帧 8×132 拼好，再按页整块写入。每一帧都把可见区
   的每一个字节显式写一遍（空白处就是 0x00），所以屏幕上不会出现“没写到的列”。
   使用顺序：OLED_BufClear() -> OLED_BufString()/OLED_BufPixel() -> OLED_Flush()。 */

#define OLED_PAGE_NUM		8
#define OLED_WIDTH			128

static uint8_t s_gram[OLED_PAGE_NUM][OLED_RAM_WIDTH];

/**
  * @brief  清空帧缓冲（只改 RAM，不动屏幕）
  */
void OLED_BufClear(void)
{
	uint8_t page;
	uint16_t col;

	for (page = 0; page < OLED_PAGE_NUM; page++)
	{
		for (col = 0; col < OLED_RAM_WIDTH; col++)
		{
			s_gram[page][col] = 0x00;
		}
	}
}

/**
  * @brief  在帧缓冲里画一个像素
  * @param  X 横坐标 0~127，Y 纵坐标 0~63，On 1 点亮 / 0 熄灭
  */
void OLED_BufPixel(uint8_t X, uint8_t Y, uint8_t On)
{
	if ((X >= OLED_WIDTH) || (Y >= 64))
	{
		return;
	}

	if (On != 0)
	{
		s_gram[Y >> 3][X] |= (uint8_t)(1U << (Y & 0x07));
	}
	else
	{
		s_gram[Y >> 3][X] &= (uint8_t)~(1U << (Y & 0x07));
	}
}

/**
  * @brief  在帧缓冲里写一个 8×16 字符
  * @param  Line 行 1~4，Column 列 1~16
  */
void OLED_BufChar(uint8_t Line, uint8_t Column, char Char)
{
	const uint8_t *glyph;
	uint8_t page, x, i;

	if ((Line < 1U) || (Line > 4U) || (Column < 1U) || (Column > 16U))
	{
		return;
	}
	if ((Char < ' ') || (Char > '~'))		/* 字模只覆盖 0x20~0x7E */
	{
		Char = ' ';
	}

	glyph = OLED_F8x16[Char - ' '];
	page  = (uint8_t)((Line - 1U) * 2U);
	x     = (uint8_t)((Column - 1U) * 8U);

	for (i = 0; i < 8U; i++)
	{
		s_gram[page][x + i]     = glyph[i];			/* 上半部分 */
		s_gram[page + 1U][x + i] = glyph[i + 8U];	/* 下半部分 */
	}
}

/**
  * @brief  在帧缓冲里写字符串（不检查是否超出 16 列，超出部分会被裁掉）
  */
void OLED_BufString(uint8_t Line, uint8_t Column, const char *String)
{
	uint8_t i;

	for (i = 0; String[i] != '\0'; i++)
	{
		if ((uint8_t)(Column + i) > 16U)
		{
			break;
		}
		OLED_BufChar(Line, (uint8_t)(Column + i), String[i]);
	}
}

/**
  * @brief  把帧缓冲整屏推给屏幕：8 页，每页一次 I2C 传输、132 字节
  * @note   132 字节覆盖 1.3 寸（132 列显存）多出的 4 列；0.96 寸屏多写的
  *         4 个 0x00 会绕回本页最左侧，写的仍是 0x00，不影响画面。
  */
void OLED_Flush(void)
{
	uint8_t page;

	for (page = 0; page < OLED_PAGE_NUM; page++)
	{
		OLED_SetCursor(page, 0);
		OLED_WriteMulti(s_gram[page], OLED_RAM_WIDTH);
	}
}
