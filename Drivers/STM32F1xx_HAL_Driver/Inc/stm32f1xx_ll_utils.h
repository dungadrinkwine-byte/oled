#ifndef __STM32F1xx_LL_UTILS_H
#define __STM32F1xx_LL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"

#define LL_MAX_DELAY                  0xFFFFFFFFU

#define UID_BASE_ADDRESS              UID_BASE

#define FLASHSIZE_BASE_ADDRESS        FLASHSIZE_BASE

typedef struct
{
  uint32_t PLLMul;

  uint32_t Prediv;

} LL_UTILS_PLLInitTypeDef;

typedef struct
{
  uint32_t AHBCLKDivider;

  uint32_t APB1CLKDivider;

  uint32_t APB2CLKDivider;

} LL_UTILS_ClkInitTypeDef;

#define LL_UTILS_HSEBYPASS_OFF        0x00000000U
#define LL_UTILS_HSEBYPASS_ON         0x00000001U

__STATIC_INLINE uint32_t LL_GetUID_Word0(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)UID_BASE_ADDRESS)));
}

__STATIC_INLINE uint32_t LL_GetUID_Word1(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE_ADDRESS + 4U))));
}

__STATIC_INLINE uint32_t LL_GetUID_Word2(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE_ADDRESS + 8U))));
}

__STATIC_INLINE uint32_t LL_GetFlashSize(void)
{
  return (uint16_t)(READ_REG(*((uint32_t *)FLASHSIZE_BASE_ADDRESS)));
}

__STATIC_INLINE void LL_InitTick(uint32_t HCLKFrequency, uint32_t Ticks)
{

  SysTick->LOAD  = (uint32_t)((HCLKFrequency / Ticks) - 1UL);
  SysTick->VAL   = 0UL;
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_ENABLE_Msk;
}

void        LL_Init1msTick(uint32_t HCLKFrequency);
void        LL_mDelay(uint32_t Delay);

void        LL_SetSystemCoreClock(uint32_t HCLKFrequency);
#if defined(FLASH_ACR_LATENCY)
ErrorStatus LL_SetFlashLatency(uint32_t Frequency);
#endif
ErrorStatus LL_PLL_ConfigSystemClock_HSI(LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct,
                                         LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
ErrorStatus LL_PLL_ConfigSystemClock_HSE(uint32_t HSEFrequency, uint32_t HSEBypass,
                                         LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
#if defined(RCC_PLL2_SUPPORT)
ErrorStatus LL_PLL_ConfigSystemClock_PLL2(uint32_t HSEFrequency, uint32_t HSEBypass, LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct,
                                          LL_UTILS_PLLInitTypeDef *UTILS_PLL2InitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
#endif

#ifdef __cplusplus
}
#endif

#endif
