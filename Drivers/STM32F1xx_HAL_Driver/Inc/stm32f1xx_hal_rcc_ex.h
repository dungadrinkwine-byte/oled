#ifndef __STM32F1xx_HAL_RCC_EX_H
#define __STM32F1xx_HAL_RCC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal_def.h"

#if defined(STM32F105xC) || defined(STM32F107xC)

#define PLLI2SON_BITNUMBER           RCC_CR_PLL3ON_Pos
#define RCC_CR_PLLI2SON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (PLLI2SON_BITNUMBER * 4U)))

#define PLL2ON_BITNUMBER             RCC_CR_PLL2ON_Pos
#define RCC_CR_PLL2ON_BB             ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (PLL2ON_BITNUMBER * 4U)))

#define PLLI2S_TIMEOUT_VALUE         100U
#define PLL2_TIMEOUT_VALUE           100U

#endif

#define CR_REG_INDEX                 ((uint8_t)1)

#if defined(STM32F105xC) || defined(STM32F107xC)
#define IS_RCC_PREDIV1_SOURCE(__SOURCE__) (((__SOURCE__) == RCC_PREDIV1_SOURCE_HSE) || \
                                           ((__SOURCE__) == RCC_PREDIV1_SOURCE_PLL2))
#endif

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
#define IS_RCC_HSE_PREDIV(__DIV__) (((__DIV__) == RCC_HSE_PREDIV_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV_DIV2)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV3)  || ((__DIV__) == RCC_HSE_PREDIV_DIV4)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV5)  || ((__DIV__) == RCC_HSE_PREDIV_DIV6)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV7)  || ((__DIV__) == RCC_HSE_PREDIV_DIV8)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV9)  || ((__DIV__) == RCC_HSE_PREDIV_DIV10) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV11) || ((__DIV__) == RCC_HSE_PREDIV_DIV12) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV13) || ((__DIV__) == RCC_HSE_PREDIV_DIV14) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV15) || ((__DIV__) == RCC_HSE_PREDIV_DIV16))

#else
#define IS_RCC_HSE_PREDIV(__DIV__) (((__DIV__) == RCC_HSE_PREDIV_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV_DIV2))
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)
#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) == RCC_PLL_MUL4)  || ((__MUL__) == RCC_PLL_MUL5) || \
                                 ((__MUL__) == RCC_PLL_MUL6)  || ((__MUL__) == RCC_PLL_MUL7) || \
                                 ((__MUL__) == RCC_PLL_MUL8)  || ((__MUL__) == RCC_PLL_MUL9) || \
                                 ((__MUL__) == RCC_PLL_MUL6_5))

#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK)  || ((__SOURCE__) == RCC_MCO1SOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_HSE)     || ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_PLL2CLK) || ((__SOURCE__) == RCC_MCO1SOURCE_PLL3CLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_PLL3CLK_DIV2) || ((__SOURCE__) == RCC_MCO1SOURCE_EXT_HSE) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK))

#else
#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) == RCC_PLL_MUL2)  || ((__MUL__) == RCC_PLL_MUL3)  || \
                                 ((__MUL__) == RCC_PLL_MUL4)  || ((__MUL__) == RCC_PLL_MUL5)  || \
                                 ((__MUL__) == RCC_PLL_MUL6)  || ((__MUL__) == RCC_PLL_MUL7)  || \
                                 ((__MUL__) == RCC_PLL_MUL8)  || ((__MUL__) == RCC_PLL_MUL9)  || \
                                 ((__MUL__) == RCC_PLL_MUL10) || ((__MUL__) == RCC_PLL_MUL11) || \
                                 ((__MUL__) == RCC_PLL_MUL12) || ((__MUL__) == RCC_PLL_MUL13) || \
                                 ((__MUL__) == RCC_PLL_MUL14) || ((__MUL__) == RCC_PLL_MUL15) || \
                                 ((__MUL__) == RCC_PLL_MUL16))

#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK)  || ((__SOURCE__) == RCC_MCO1SOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_HSE)     || ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK))

#endif

#define IS_RCC_ADCPLLCLK_DIV(__ADCCLK__) (((__ADCCLK__) == RCC_ADCPCLK2_DIV2)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV4)   || \
                                          ((__ADCCLK__) == RCC_ADCPCLK2_DIV6)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV8))

#if defined(STM32F105xC) || defined(STM32F107xC)
#define IS_RCC_I2S2CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_I2S2CLKSOURCE_SYSCLK)  || ((__SOURCE__) == RCC_I2S2CLKSOURCE_PLLI2S_VCO))

#define IS_RCC_I2S3CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_I2S3CLKSOURCE_SYSCLK)  || ((__SOURCE__) == RCC_I2S3CLKSOURCE_PLLI2S_VCO))

#define IS_RCC_USBPLLCLK_DIV(__USBCLK__) (((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV2)  || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV3))

#define IS_RCC_PLLI2S_MUL(__MUL__) (((__MUL__) == RCC_PLLI2S_MUL8)   || ((__MUL__) == RCC_PLLI2S_MUL9)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL10)  || ((__MUL__) == RCC_PLLI2S_MUL11)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL12)  || ((__MUL__) == RCC_PLLI2S_MUL13)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL14)  || ((__MUL__) == RCC_PLLI2S_MUL16)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL20))

#define IS_RCC_HSE_PREDIV2(__DIV__) (((__DIV__) == RCC_HSE_PREDIV2_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV2)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV3)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV4)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV5)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV6)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV7)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV8)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV9)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV10) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV11) || ((__DIV__) == RCC_HSE_PREDIV2_DIV12) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV13) || ((__DIV__) == RCC_HSE_PREDIV2_DIV14) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV15) || ((__DIV__) == RCC_HSE_PREDIV2_DIV16))

#define IS_RCC_PLL2(__PLL__) (((__PLL__) == RCC_PLL2_NONE) || ((__PLL__) == RCC_PLL2_OFF) || \
                              ((__PLL__) == RCC_PLL2_ON))

#define IS_RCC_PLL2_MUL(__MUL__) (((__MUL__) == RCC_PLL2_MUL8)  || ((__MUL__) == RCC_PLL2_MUL9)  || \
                                  ((__MUL__) == RCC_PLL2_MUL10)  || ((__MUL__) == RCC_PLL2_MUL11)  || \
                                  ((__MUL__) == RCC_PLL2_MUL12)  || ((__MUL__) == RCC_PLL2_MUL13)  || \
                                  ((__MUL__) == RCC_PLL2_MUL14)  || ((__MUL__) == RCC_PLL2_MUL16)  || \
                                  ((__MUL__) == RCC_PLL2_MUL20))

#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S2)  == RCC_PERIPHCLK_I2S2)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S3)   == RCC_PERIPHCLK_I2S3)   || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB)   == RCC_PERIPHCLK_USB))

#elif defined(STM32F103xE) || defined(STM32F103xG)

#define IS_RCC_I2S2CLKSOURCE(__SOURCE__) ((__SOURCE__) == RCC_I2S2CLKSOURCE_SYSCLK)

#define IS_RCC_I2S3CLKSOURCE(__SOURCE__) ((__SOURCE__) == RCC_I2S3CLKSOURCE_SYSCLK)

#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S2) == RCC_PERIPHCLK_I2S2)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S3) == RCC_PERIPHCLK_I2S3)   || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB)  == RCC_PERIPHCLK_USB))

#elif defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB)

#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC) == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC) == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB) == RCC_PERIPHCLK_USB))

#else

#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC))

#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)

#define IS_RCC_USBPLLCLK_DIV(__USBCLK__) (((__USBCLK__) == RCC_USBCLKSOURCE_PLL)  || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV1_5))

#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

typedef struct
{
  uint32_t PLL2State;

  uint32_t PLL2MUL;

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t HSEPrediv2Value;

#endif
} RCC_PLL2InitTypeDef;

#endif

typedef struct
{
  uint32_t OscillatorType;

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t Prediv1Source;

#endif

  uint32_t HSEState;

  uint32_t HSEPredivValue;

  uint32_t LSEState;

  uint32_t HSIState;

  uint32_t HSICalibrationValue;

  uint32_t LSIState;

  RCC_PLLInitTypeDef PLL;

#if defined(STM32F105xC) || defined(STM32F107xC)
  RCC_PLL2InitTypeDef PLL2;
#endif
} RCC_OscInitTypeDef;

#if defined(STM32F105xC) || defined(STM32F107xC)

typedef struct
{
  uint32_t PLLI2SMUL;

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t HSEPrediv2Value;

#endif
} RCC_PLLI2SInitTypeDef;
#endif

typedef struct
{
  uint32_t PeriphClockSelection;

  uint32_t RTCClockSelection;

  uint32_t AdcClockSelection;

#if defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
  uint32_t I2s2ClockSelection;

  uint32_t I2s3ClockSelection;

#if defined(STM32F105xC) || defined(STM32F107xC)
  RCC_PLLI2SInitTypeDef PLLI2S;

#endif
#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t UsbClockSelection;

#endif
} RCC_PeriphCLKInitTypeDef;

#define RCC_PERIPHCLK_RTC           0x00000001U
#define RCC_PERIPHCLK_ADC           0x00000002U
#if defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_PERIPHCLK_I2S2          0x00000004U
#define RCC_PERIPHCLK_I2S3          0x00000008U
#endif
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_PERIPHCLK_USB          0x00000010U
#endif

#define RCC_ADCPCLK2_DIV2              RCC_CFGR_ADCPRE_DIV2
#define RCC_ADCPCLK2_DIV4              RCC_CFGR_ADCPRE_DIV4
#define RCC_ADCPCLK2_DIV6              RCC_CFGR_ADCPRE_DIV6
#define RCC_ADCPCLK2_DIV8              RCC_CFGR_ADCPRE_DIV8

#if defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)

#define RCC_I2S2CLKSOURCE_SYSCLK              0x00000000U
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_I2S2CLKSOURCE_PLLI2S_VCO          RCC_CFGR2_I2S2SRC
#endif

#define RCC_I2S3CLKSOURCE_SYSCLK              0x00000000U
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_I2S3CLKSOURCE_PLLI2S_VCO          RCC_CFGR2_I2S3SRC
#endif

#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)

#define RCC_USBCLKSOURCE_PLL              RCC_CFGR_USBPRE
#define RCC_USBCLKSOURCE_PLL_DIV1_5       0x00000000U

#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

#define RCC_USBCLKSOURCE_PLL_DIV2              RCC_CFGR_OTGFSPRE
#define RCC_USBCLKSOURCE_PLL_DIV3              0x00000000U

#define RCC_PLLI2S_MUL8                   RCC_CFGR2_PLL3MUL8
#define RCC_PLLI2S_MUL9                   RCC_CFGR2_PLL3MUL9
#define RCC_PLLI2S_MUL10                  RCC_CFGR2_PLL3MUL10
#define RCC_PLLI2S_MUL11                  RCC_CFGR2_PLL3MUL11
#define RCC_PLLI2S_MUL12                  RCC_CFGR2_PLL3MUL12
#define RCC_PLLI2S_MUL13                  RCC_CFGR2_PLL3MUL13
#define RCC_PLLI2S_MUL14                  RCC_CFGR2_PLL3MUL14
#define RCC_PLLI2S_MUL16                  RCC_CFGR2_PLL3MUL16
#define RCC_PLLI2S_MUL20                  RCC_CFGR2_PLL3MUL20

#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

#define RCC_PREDIV1_SOURCE_HSE           RCC_CFGR2_PREDIV1SRC_HSE
#define RCC_PREDIV1_SOURCE_PLL2          RCC_CFGR2_PREDIV1SRC_PLL2

#endif

#define RCC_HSE_PREDIV_DIV1              0x00000000U

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR2_PREDIV1_DIV2
#define RCC_HSE_PREDIV_DIV3              RCC_CFGR2_PREDIV1_DIV3
#define RCC_HSE_PREDIV_DIV4              RCC_CFGR2_PREDIV1_DIV4
#define RCC_HSE_PREDIV_DIV5              RCC_CFGR2_PREDIV1_DIV5
#define RCC_HSE_PREDIV_DIV6              RCC_CFGR2_PREDIV1_DIV6
#define RCC_HSE_PREDIV_DIV7              RCC_CFGR2_PREDIV1_DIV7
#define RCC_HSE_PREDIV_DIV8              RCC_CFGR2_PREDIV1_DIV8
#define RCC_HSE_PREDIV_DIV9              RCC_CFGR2_PREDIV1_DIV9
#define RCC_HSE_PREDIV_DIV10             RCC_CFGR2_PREDIV1_DIV10
#define RCC_HSE_PREDIV_DIV11             RCC_CFGR2_PREDIV1_DIV11
#define RCC_HSE_PREDIV_DIV12             RCC_CFGR2_PREDIV1_DIV12
#define RCC_HSE_PREDIV_DIV13             RCC_CFGR2_PREDIV1_DIV13
#define RCC_HSE_PREDIV_DIV14             RCC_CFGR2_PREDIV1_DIV14
#define RCC_HSE_PREDIV_DIV15             RCC_CFGR2_PREDIV1_DIV15
#define RCC_HSE_PREDIV_DIV16             RCC_CFGR2_PREDIV1_DIV16
#else
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR_PLLXTPRE
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

#define RCC_HSE_PREDIV2_DIV1                RCC_CFGR2_PREDIV2_DIV1
#define RCC_HSE_PREDIV2_DIV2                RCC_CFGR2_PREDIV2_DIV2
#define RCC_HSE_PREDIV2_DIV3                RCC_CFGR2_PREDIV2_DIV3
#define RCC_HSE_PREDIV2_DIV4                RCC_CFGR2_PREDIV2_DIV4
#define RCC_HSE_PREDIV2_DIV5                RCC_CFGR2_PREDIV2_DIV5
#define RCC_HSE_PREDIV2_DIV6                RCC_CFGR2_PREDIV2_DIV6
#define RCC_HSE_PREDIV2_DIV7                RCC_CFGR2_PREDIV2_DIV7
#define RCC_HSE_PREDIV2_DIV8                RCC_CFGR2_PREDIV2_DIV8
#define RCC_HSE_PREDIV2_DIV9                RCC_CFGR2_PREDIV2_DIV9
#define RCC_HSE_PREDIV2_DIV10               RCC_CFGR2_PREDIV2_DIV10
#define RCC_HSE_PREDIV2_DIV11               RCC_CFGR2_PREDIV2_DIV11
#define RCC_HSE_PREDIV2_DIV12               RCC_CFGR2_PREDIV2_DIV12
#define RCC_HSE_PREDIV2_DIV13               RCC_CFGR2_PREDIV2_DIV13
#define RCC_HSE_PREDIV2_DIV14               RCC_CFGR2_PREDIV2_DIV14
#define RCC_HSE_PREDIV2_DIV15               RCC_CFGR2_PREDIV2_DIV15
#define RCC_HSE_PREDIV2_DIV16               RCC_CFGR2_PREDIV2_DIV16

#define RCC_PLL2_NONE                      0x00000000U
#define RCC_PLL2_OFF                       0x00000001U
#define RCC_PLL2_ON                        0x00000002U

#define RCC_PLL2_MUL8                   RCC_CFGR2_PLL2MUL8
#define RCC_PLL2_MUL9                   RCC_CFGR2_PLL2MUL9
#define RCC_PLL2_MUL10                  RCC_CFGR2_PLL2MUL10
#define RCC_PLL2_MUL11                  RCC_CFGR2_PLL2MUL11
#define RCC_PLL2_MUL12                  RCC_CFGR2_PLL2MUL12
#define RCC_PLL2_MUL13                  RCC_CFGR2_PLL2MUL13
#define RCC_PLL2_MUL14                  RCC_CFGR2_PLL2MUL14
#define RCC_PLL2_MUL16                  RCC_CFGR2_PLL2MUL16
#define RCC_PLL2_MUL20                  RCC_CFGR2_PLL2MUL20

#endif

#if defined(STM32F105xC) || defined(STM32F107xC)
#else
#define RCC_PLL_MUL2                    RCC_CFGR_PLLMULL2
#define RCC_PLL_MUL3                    RCC_CFGR_PLLMULL3
#endif
#define RCC_PLL_MUL4                    RCC_CFGR_PLLMULL4
#define RCC_PLL_MUL5                    RCC_CFGR_PLLMULL5
#define RCC_PLL_MUL6                    RCC_CFGR_PLLMULL6
#define RCC_PLL_MUL7                    RCC_CFGR_PLLMULL7
#define RCC_PLL_MUL8                    RCC_CFGR_PLLMULL8
#define RCC_PLL_MUL9                    RCC_CFGR_PLLMULL9
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_PLL_MUL6_5                  RCC_CFGR_PLLMULL6_5
#else
#define RCC_PLL_MUL10                   RCC_CFGR_PLLMULL10
#define RCC_PLL_MUL11                   RCC_CFGR_PLLMULL11
#define RCC_PLL_MUL12                   RCC_CFGR_PLLMULL12
#define RCC_PLL_MUL13                   RCC_CFGR_PLLMULL13
#define RCC_PLL_MUL14                   RCC_CFGR_PLLMULL14
#define RCC_PLL_MUL15                   RCC_CFGR_PLLMULL15
#define RCC_PLL_MUL16                   RCC_CFGR_PLLMULL16
#endif

#define RCC_MCO1SOURCE_NOCLOCK           ((uint32_t)RCC_CFGR_MCO_NOCLOCK)
#define RCC_MCO1SOURCE_SYSCLK            ((uint32_t)RCC_CFGR_MCO_SYSCLK)
#define RCC_MCO1SOURCE_HSI               ((uint32_t)RCC_CFGR_MCO_HSI)
#define RCC_MCO1SOURCE_HSE               ((uint32_t)RCC_CFGR_MCO_HSE)
#define RCC_MCO1SOURCE_PLLCLK            ((uint32_t)RCC_CFGR_MCO_PLLCLK_DIV2)
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_MCO1SOURCE_PLL2CLK           ((uint32_t)RCC_CFGR_MCO_PLL2CLK)
#define RCC_MCO1SOURCE_PLL3CLK_DIV2      ((uint32_t)RCC_CFGR_MCO_PLL3CLK_DIV2)
#define RCC_MCO1SOURCE_EXT_HSE           ((uint32_t)RCC_CFGR_MCO_EXT_HSE)
#define RCC_MCO1SOURCE_PLL3CLK           ((uint32_t)RCC_CFGR_MCO_PLL3CLK)
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

#define RCC_IT_PLL2RDY                   ((uint8_t)RCC_CIR_PLL2RDYF)
#define RCC_IT_PLLI2SRDY                 ((uint8_t)RCC_CIR_PLL3RDYF)

#define RCC_FLAG_PLL2RDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL2RDY_Pos))
#define RCC_FLAG_PLLI2SRDY                ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL3RDY_Pos))

#endif

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined  (STM32F107xC)\
 || defined  (STM32F100xE)
#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DMA2_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_DMA2EN))
#endif

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
#define __HAL_RCC_FSMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_FSMC_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_FSMCEN))
#endif

#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_SDIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SDIO_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_SDIOEN))
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()       (RCC->AHBENR &= ~(RCC_AHBENR_OTGFSEN))
#endif

#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ETHMACTX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ETHMACRX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ETHMAC_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACEN))
#define __HAL_RCC_ETHMACTX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACTXEN))
#define __HAL_RCC_ETHMACRX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACRXEN))

#define __HAL_RCC_ETH_CLK_ENABLE() do {                                     \
                                        __HAL_RCC_ETHMAC_CLK_ENABLE();      \
                                        __HAL_RCC_ETHMACTX_CLK_ENABLE();    \
                                        __HAL_RCC_ETHMACRX_CLK_ENABLE();    \
                                      } while(0U)

#define __HAL_RCC_ETH_CLK_DISABLE()  do {                                      \
                                          __HAL_RCC_ETHMACTX_CLK_DISABLE();    \
                                          __HAL_RCC_ETHMACRX_CLK_DISABLE();    \
                                          __HAL_RCC_ETHMAC_CLK_DISABLE();      \
                                        } while(0U)

#endif

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined  (STM32F107xC)\
 || defined  (STM32F100xE)
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) != RESET)
#define __HAL_RCC_DMA2_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) == RESET)
#endif
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
#define __HAL_RCC_FSMC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) != RESET)
#define __HAL_RCC_FSMC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) == RESET)
#endif
#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_SDIO_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) != RESET)
#define __HAL_RCC_SDIO_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) == RESET)
#endif
#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) != RESET)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) == RESET)
#endif
#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) != RESET)
#define __HAL_RCC_ETHMAC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) == RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) != RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) == RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACRXEN)) != RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACRXEN)) == RESET)
#endif

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
#define __HAL_RCC_CAN1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CAN1_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN1EN))
#endif

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_USART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM4_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN))
#define __HAL_RCC_SPI2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define __HAL_RCC_USART3_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_USART3EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_USB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_USB_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_USBEN))
#endif

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
#endif

#if defined(STM32F100xB) || defined  (STM32F100xE)
#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CEC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
#define __HAL_RCC_CEC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_CECEN))
#endif

#ifdef STM32F100xE
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_CAN2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CAN2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN2EN))
#endif

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#endif

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) != RESET)
#define __HAL_RCC_CAN1_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) == RESET)
#endif
#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) != RESET)
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) == RESET)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) != RESET)
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) == RESET)
#define __HAL_RCC_USART3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) != RESET)
#define __HAL_RCC_USART3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) == RESET)
#endif
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_USB_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) != RESET)
#define __HAL_RCC_USB_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) == RESET)
#endif
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
#endif
#if defined(STM32F100xB) || defined  (STM32F100xE)
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
#define __HAL_RCC_CEC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) != RESET)
#define __HAL_RCC_CEC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) == RESET)
#endif
#ifdef STM32F100xE
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
#define __HAL_RCC_CAN2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) != RESET)
#define __HAL_RCC_CAN2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) == RESET)
#endif
#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#endif
#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#endif

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
#define __HAL_RCC_ADC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC2_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC2EN))
#endif

#if defined(STM32F100xB) || defined(STM32F100xE)
#define __HAL_RCC_TIM15_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM16_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM17_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM15_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM15EN))
#define __HAL_RCC_TIM16_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM16EN))
#define __HAL_RCC_TIM17_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM17EN))
#endif

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
#define __HAL_RCC_GPIOE_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOE_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPEEN))
#endif

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif

#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_TIM8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM8_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8EN))
#define __HAL_RCC_ADC3_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC3EN))
#endif

#if defined(STM32F100xE)
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM9_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM10_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM11_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                          \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM9_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM9EN))
#define __HAL_RCC_TIM10_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM10EN))
#define __HAL_RCC_TIM11_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM11EN))
#endif

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
#define __HAL_RCC_ADC2_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) != RESET)
#define __HAL_RCC_ADC2_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) == RESET)
#endif
#if defined(STM32F100xB) || defined(STM32F100xE)
#define __HAL_RCC_TIM15_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) != RESET)
#define __HAL_RCC_TIM15_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) == RESET)
#define __HAL_RCC_TIM16_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) != RESET)
#define __HAL_RCC_TIM16_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) == RESET)
#define __HAL_RCC_TIM17_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) != RESET)
#define __HAL_RCC_TIM17_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) == RESET)
#endif
#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) != RESET)
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) == RESET)
#endif
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif
#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) != RESET)
#define __HAL_RCC_TIM8_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) == RESET)
#define __HAL_RCC_ADC3_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) != RESET)
#define __HAL_RCC_ADC3_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) == RESET)
#endif
#if defined(STM32F100xE)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif
#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM9_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) != RESET)
#define __HAL_RCC_TIM9_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) == RESET)
#define __HAL_RCC_TIM10_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) != RESET)
#define __HAL_RCC_TIM10_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) == RESET)
#define __HAL_RCC_TIM11_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) != RESET)
#define __HAL_RCC_TIM11_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) == RESET)
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

#define __HAL_RCC_AHB_FORCE_RESET()         (RCC->AHBRSTR = 0xFFFFFFFFU)
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()       (RCC->AHBRSTR |= (RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_FORCE_RESET()      (RCC->AHBRSTR |= (RCC_AHBRSTR_ETHMACRST))
#endif

#define __HAL_RCC_AHB_RELEASE_RESET()       (RCC->AHBRSTR = 0x00)
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()     (RCC->AHBRSTR &= ~(RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_RELEASE_RESET()    (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ETHMACRST))
#endif

#endif

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
#define __HAL_RCC_CAN1_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN1RST))

#define __HAL_RCC_CAN1_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN1RST))
#endif

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM4_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_SPI2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_USART3_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_I2C2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))

#define __HAL_RCC_TIM4_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_SPI2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_USART3_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_USB_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_USBRST))
#define __HAL_RCC_USB_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USBRST))
#endif

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))

#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
#endif

#if defined(STM32F100xB) || defined  (STM32F100xE)
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))
#define __HAL_RCC_CEC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_CECRST))

#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
#define __HAL_RCC_CEC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CECRST))
#endif

#if defined  (STM32F100xE)
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))

#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_CAN2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN2RST))

#define __HAL_RCC_CAN2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN2RST))
#endif

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))

#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
#endif

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
#define __HAL_RCC_ADC2_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC2RST))

#define __HAL_RCC_ADC2_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC2RST))
#endif

#if defined(STM32F100xB) || defined(STM32F100xE)
#define __HAL_RCC_TIM15_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM17RST))

#define __HAL_RCC_TIM15_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM17RST))
#endif

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
#define __HAL_RCC_GPIOE_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPERST))

#define __HAL_RCC_GPIOE_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPERST))
#endif

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif

#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_TIM8_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_ADC3_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC3RST))

#define __HAL_RCC_TIM8_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_ADC3_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC3RST))
#endif

#if defined(STM32F100xE)
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM9_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM11RST))

#define __HAL_RCC_TIM9_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM11RST))
#endif

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)

#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV1, (uint32_t)(__HSE_PREDIV_VALUE__))
#else

#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) \
                  MODIFY_REG(RCC->CFGR,RCC_CFGR_PLLXTPRE, (uint32_t)(__HSE_PREDIV_VALUE__))

#endif

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)

#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1)

#else

#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR, RCC_CFGR_PLLXTPRE)

#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

#define __HAL_RCC_PLLI2S_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = ENABLE)

#define __HAL_RCC_PLLI2S_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = DISABLE)

#define __HAL_RCC_PLLI2S_CONFIG(__PLLI2SMUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL3MUL,(__PLLI2SMUL__))

#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)

#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, (uint32_t)(__USBCLKSOURCE__))

#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))

#endif

#if defined(STM32F105xC) || defined(STM32F107xC)

#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_OTGFSPRE, (uint32_t)(__USBCLKSOURCE__))

#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_OTGFSPRE)))

#endif

#define __HAL_RCC_ADC_CONFIG(__ADCCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADCCLKSOURCE__))

#define __HAL_RCC_GET_ADC_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_ADCPRE)))

#if defined(STM32F105xC) || defined(STM32F107xC)

#define __HAL_RCC_HSE_PREDIV2_CONFIG(__HSE_PREDIV2_VALUE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV2, (uint32_t)(__HSE_PREDIV2_VALUE__))

#define __HAL_RCC_HSE_GET_PREDIV2() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV2)

#define __HAL_RCC_PLL2_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = ENABLE)

#define __HAL_RCC_PLL2_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = DISABLE)

#define __HAL_RCC_PLL2_CONFIG(__PLL2MUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL2MUL,(__PLL2MUL__))

#define __HAL_RCC_I2S2_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S2SRC, (uint32_t)(__I2S2CLKSOURCE__))

#define __HAL_RCC_GET_I2S2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S2SRC)))

#define __HAL_RCC_I2S3_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S3SRC, (uint32_t)(__I2S2CLKSOURCE__))

#define __HAL_RCC_GET_I2S3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S3SRC)))

#endif

HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

#if defined(STM32F105xC) || defined(STM32F107xC)

HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);

HAL_StatusTypeDef HAL_RCCEx_EnablePLL2(RCC_PLL2InitTypeDef  *PLL2Init);
HAL_StatusTypeDef HAL_RCCEx_DisablePLL2(void);

#endif

#ifdef __cplusplus
}
#endif

#endif

