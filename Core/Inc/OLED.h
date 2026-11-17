#ifndef __OLED_H
#define __OLED_H

#include <stdint-gcc.h>

void OLED_Init(void);
void OLED_Clear(void);
void OLED_WriteMulti(const uint8_t *Data, uint16_t Len);

void OLED_BufClear(void);
void OLED_BufPixel(uint8_t X, uint8_t Y, uint8_t On);
void OLED_BufChar(uint8_t Line, uint8_t Column, char Char);
void OLED_BufString(uint8_t Line, uint8_t Column, const char *String);
void OLED_Flush(void);

void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
