#include "stm32f1xx_hal.h"
#include "OLED_Font.h"
#include <string.h>

#define OLED_W_SCL(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (GPIO_PinState)(x))
#define OLED_W_SDA(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (GPIO_PinState)(x))

#define OLED_RAM_WIDTH		132

void OLED_I2C_Init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.Speed=GPIO_SPEED_HIGH;
    GPIO_InitStructure.Mode=GPIO_MODE_OUTPUT_OD;
    GPIO_InitStructure.Pull=GPIO_PULLUP;
    GPIO_InitStructure.Pin=GPIO_PIN_0|GPIO_PIN_1;

    HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);

    OLED_W_SCL(1);
    OLED_W_SDA(1);
}

void OLED_I2C_Start(void)
{
	OLED_W_SDA(1);
	OLED_W_SCL(1);
	OLED_W_SDA(0);
	OLED_W_SCL(0);
}

void OLED_I2C_Stop(void)
{
	OLED_W_SDA(0);
	OLED_W_SCL(1);
	OLED_W_SDA(1);
}

void OLED_I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i++)
	{
		OLED_W_SDA(Byte & (0x80 >> i));
		OLED_W_SCL(1);
		OLED_W_SCL(0);
	}
	OLED_W_SCL(1);
	OLED_W_SCL(0);
}

void OLED_WriteCommand(uint8_t Command)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);
	OLED_I2C_SendByte(0x00);
	OLED_I2C_SendByte(Command);
	OLED_I2C_Stop();
}

void OLED_WriteData(uint8_t Data)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);
	OLED_I2C_SendByte(0x40);
	OLED_I2C_SendByte(Data);
	OLED_I2C_Stop();
}

void OLED_WriteMulti(const uint8_t *Data, uint16_t Len)
{
	uint16_t i;

	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);
	OLED_I2C_SendByte(0x40);
	for (i = 0; i < Len; i++)
	{
		OLED_I2C_SendByte(Data[i]);
	}
	OLED_I2C_Stop();
}

void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));
	OLED_WriteCommand(0x00 | (X & 0x0F));
}

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

void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);
	}
}

void OLED_ShowString(uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}

uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

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

void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
}

void OLED_Init(void)
{
	uint32_t i, j;

	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 1000; j++);
	}

	OLED_I2C_Init();

	OLED_WriteCommand(0xAE);

	OLED_WriteCommand(0xD5);
	OLED_WriteCommand(0x80);

	OLED_WriteCommand(0xA8);
	OLED_WriteCommand(0x3F);

	OLED_WriteCommand(0xD3);
	OLED_WriteCommand(0x00);

	OLED_WriteCommand(0x40);

	OLED_WriteCommand(0xA1);

	OLED_WriteCommand(0xC8);

	OLED_WriteCommand(0xDA);
	OLED_WriteCommand(0x12);

	OLED_WriteCommand(0x81);
	OLED_WriteCommand(0xCF);

	OLED_WriteCommand(0xD9);
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);

	OLED_WriteCommand(0xA6);

	OLED_WriteCommand(0x8D);
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);

	OLED_Clear();
}

#define OLED_PAGE_NUM		8
#define OLED_WIDTH			128

static uint8_t s_gram[OLED_PAGE_NUM][OLED_RAM_WIDTH];

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

void OLED_BufChar(uint8_t Line, uint8_t Column, char Char)
{
	const uint8_t *glyph;
	uint8_t page, x, i;

	if ((Line < 1U) || (Line > 4U) || (Column < 1U) || (Column > 16U))
	{
		return;
	}
	if ((Char < ' ') || (Char > '~'))
	{
		Char = ' ';
	}

	glyph = OLED_F8x16[Char - ' '];
	page  = (uint8_t)((Line - 1U) * 2U);
	x     = (uint8_t)((Column - 1U) * 8U);

	for (i = 0; i < 8U; i++)
	{
		s_gram[page][x + i]     = glyph[i];
		s_gram[page + 1U][x + i] = glyph[i + 8U];
	}
}

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

void OLED_Flush(void)
{
	uint8_t page;

	for (page = 0; page < OLED_PAGE_NUM; page++)
	{
		OLED_SetCursor(page, 0);
		OLED_WriteMulti(s_gram[page], OLED_RAM_WIDTH);
	}
}
