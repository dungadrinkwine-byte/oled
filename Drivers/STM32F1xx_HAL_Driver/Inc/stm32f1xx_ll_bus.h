#ifndef __STM32F1xx_LL_BUS_H
#define __STM32F1xx_LL_BUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"

#if defined(RCC)

#if defined(RCC_AHBRSTR_OTGFSRST) || defined(RCC_AHBRSTR_ETHMACRST)
#define RCC_AHBRSTR_SUPPORT
#endif

#define LL_AHB1_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU
#define LL_AHB1_GRP1_PERIPH_CRC            RCC_AHBENR_CRCEN
#define LL_AHB1_GRP1_PERIPH_DMA1           RCC_AHBENR_DMA1EN
#if defined(DMA2)
#define LL_AHB1_GRP1_PERIPH_DMA2           RCC_AHBENR_DMA2EN
#endif
#if defined(ETH)
#define LL_AHB1_GRP1_PERIPH_ETHMAC         RCC_AHBENR_ETHMACEN
#define LL_AHB1_GRP1_PERIPH_ETHMACRX       RCC_AHBENR_ETHMACRXEN
#define LL_AHB1_GRP1_PERIPH_ETHMACTX       RCC_AHBENR_ETHMACTXEN
#endif
#define LL_AHB1_GRP1_PERIPH_FLASH          RCC_AHBENR_FLITFEN
#if defined(FSMC_Bank1)
#define LL_AHB1_GRP1_PERIPH_FSMC           RCC_AHBENR_FSMCEN
#endif
#if defined(USB_OTG_FS)
#define LL_AHB1_GRP1_PERIPH_OTGFS          RCC_AHBENR_OTGFSEN
#endif
#if defined(SDIO)
#define LL_AHB1_GRP1_PERIPH_SDIO           RCC_AHBENR_SDIOEN
#endif
#define LL_AHB1_GRP1_PERIPH_SRAM           RCC_AHBENR_SRAMEN

#define LL_APB1_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU
#define LL_APB1_GRP1_PERIPH_BKP            RCC_APB1ENR_BKPEN
#if defined(CAN1)
#define LL_APB1_GRP1_PERIPH_CAN1           RCC_APB1ENR_CAN1EN
#endif
#if defined(CAN2)
#define LL_APB1_GRP1_PERIPH_CAN2           RCC_APB1ENR_CAN2EN
#endif
#if defined(CEC)
#define LL_APB1_GRP1_PERIPH_CEC            RCC_APB1ENR_CECEN
#endif
#if defined(DAC)
#define LL_APB1_GRP1_PERIPH_DAC1           RCC_APB1ENR_DACEN
#endif
#define LL_APB1_GRP1_PERIPH_I2C1           RCC_APB1ENR_I2C1EN
#if defined(I2C2)
#define LL_APB1_GRP1_PERIPH_I2C2           RCC_APB1ENR_I2C2EN
#endif
#define LL_APB1_GRP1_PERIPH_PWR            RCC_APB1ENR_PWREN
#if defined(SPI2)
#define LL_APB1_GRP1_PERIPH_SPI2           RCC_APB1ENR_SPI2EN
#endif
#if defined(SPI3)
#define LL_APB1_GRP1_PERIPH_SPI3           RCC_APB1ENR_SPI3EN
#endif
#if defined(TIM12)
#define LL_APB1_GRP1_PERIPH_TIM12          RCC_APB1ENR_TIM12EN
#endif
#if defined(TIM13)
#define LL_APB1_GRP1_PERIPH_TIM13          RCC_APB1ENR_TIM13EN
#endif
#if defined(TIM14)
#define LL_APB1_GRP1_PERIPH_TIM14          RCC_APB1ENR_TIM14EN
#endif
#define LL_APB1_GRP1_PERIPH_TIM2           RCC_APB1ENR_TIM2EN
#define LL_APB1_GRP1_PERIPH_TIM3           RCC_APB1ENR_TIM3EN
#if defined(TIM4)
#define LL_APB1_GRP1_PERIPH_TIM4           RCC_APB1ENR_TIM4EN
#endif
#if defined(TIM5)
#define LL_APB1_GRP1_PERIPH_TIM5           RCC_APB1ENR_TIM5EN
#endif
#if defined(TIM6)
#define LL_APB1_GRP1_PERIPH_TIM6           RCC_APB1ENR_TIM6EN
#endif
#if defined(TIM7)
#define LL_APB1_GRP1_PERIPH_TIM7           RCC_APB1ENR_TIM7EN
#endif
#if defined(UART4)
#define LL_APB1_GRP1_PERIPH_UART4          RCC_APB1ENR_UART4EN
#endif
#if defined(UART5)
#define LL_APB1_GRP1_PERIPH_UART5          RCC_APB1ENR_UART5EN
#endif
#define LL_APB1_GRP1_PERIPH_USART2         RCC_APB1ENR_USART2EN
#if defined(USART3)
#define LL_APB1_GRP1_PERIPH_USART3         RCC_APB1ENR_USART3EN
#endif
#if defined(USB)
#define LL_APB1_GRP1_PERIPH_USB            RCC_APB1ENR_USBEN
#endif
#define LL_APB1_GRP1_PERIPH_WWDG           RCC_APB1ENR_WWDGEN

#define LL_APB2_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU
#define LL_APB2_GRP1_PERIPH_ADC1           RCC_APB2ENR_ADC1EN
#if defined(ADC2)
#define LL_APB2_GRP1_PERIPH_ADC2           RCC_APB2ENR_ADC2EN
#endif
#if defined(ADC3)
#define LL_APB2_GRP1_PERIPH_ADC3           RCC_APB2ENR_ADC3EN
#endif
#define LL_APB2_GRP1_PERIPH_AFIO           RCC_APB2ENR_AFIOEN
#define LL_APB2_GRP1_PERIPH_GPIOA          RCC_APB2ENR_IOPAEN
#define LL_APB2_GRP1_PERIPH_GPIOB          RCC_APB2ENR_IOPBEN
#define LL_APB2_GRP1_PERIPH_GPIOC          RCC_APB2ENR_IOPCEN
#define LL_APB2_GRP1_PERIPH_GPIOD          RCC_APB2ENR_IOPDEN
#if defined(GPIOE)
#define LL_APB2_GRP1_PERIPH_GPIOE          RCC_APB2ENR_IOPEEN
#endif
#if defined(GPIOF)
#define LL_APB2_GRP1_PERIPH_GPIOF          RCC_APB2ENR_IOPFEN
#endif
#if defined(GPIOG)
#define LL_APB2_GRP1_PERIPH_GPIOG          RCC_APB2ENR_IOPGEN
#endif
#define LL_APB2_GRP1_PERIPH_SPI1           RCC_APB2ENR_SPI1EN
#if defined(TIM10)
#define LL_APB2_GRP1_PERIPH_TIM10          RCC_APB2ENR_TIM10EN
#endif
#if defined(TIM11)
#define LL_APB2_GRP1_PERIPH_TIM11          RCC_APB2ENR_TIM11EN
#endif
#if defined(TIM15)
#define LL_APB2_GRP1_PERIPH_TIM15          RCC_APB2ENR_TIM15EN
#endif
#if defined(TIM16)
#define LL_APB2_GRP1_PERIPH_TIM16          RCC_APB2ENR_TIM16EN
#endif
#if defined(TIM17)
#define LL_APB2_GRP1_PERIPH_TIM17          RCC_APB2ENR_TIM17EN
#endif
#define LL_APB2_GRP1_PERIPH_TIM1           RCC_APB2ENR_TIM1EN
#if defined(TIM8)
#define LL_APB2_GRP1_PERIPH_TIM8           RCC_APB2ENR_TIM8EN
#endif
#if defined(TIM9)
#define LL_APB2_GRP1_PERIPH_TIM9           RCC_APB2ENR_TIM9EN
#endif
#define LL_APB2_GRP1_PERIPH_USART1         RCC_APB2ENR_USART1EN

__STATIC_INLINE void LL_AHB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHBENR, Periphs);

  tmpreg = READ_BIT(RCC->AHBENR, Periphs);
  (void)tmpreg;
}

__STATIC_INLINE uint32_t LL_AHB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCC->AHBENR, Periphs) == Periphs);
}

__STATIC_INLINE void LL_AHB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHBENR, Periphs);
}

#if defined(RCC_AHBRSTR_SUPPORT)

__STATIC_INLINE void LL_AHB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->AHBRSTR, Periphs);
}

__STATIC_INLINE void LL_AHB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHBRSTR, Periphs);
}
#endif

__STATIC_INLINE void LL_APB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB1ENR, Periphs);

  tmpreg = READ_BIT(RCC->APB1ENR, Periphs);
  (void)tmpreg;
}

__STATIC_INLINE uint32_t LL_APB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCC->APB1ENR, Periphs) == Periphs);
}

__STATIC_INLINE void LL_APB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1ENR, Periphs);
}

__STATIC_INLINE void LL_APB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB1RSTR, Periphs);
}

__STATIC_INLINE void LL_APB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1RSTR, Periphs);
}

__STATIC_INLINE void LL_APB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB2ENR, Periphs);

  tmpreg = READ_BIT(RCC->APB2ENR, Periphs);
  (void)tmpreg;
}

__STATIC_INLINE uint32_t LL_APB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCC->APB2ENR, Periphs) == Periphs);
}

__STATIC_INLINE void LL_APB2_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2ENR, Periphs);
}

__STATIC_INLINE void LL_APB2_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB2RSTR, Periphs);
}

__STATIC_INLINE void LL_APB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2RSTR, Periphs);
}

#endif

#ifdef __cplusplus
}
#endif

#endif

