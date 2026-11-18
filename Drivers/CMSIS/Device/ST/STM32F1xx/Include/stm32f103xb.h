#ifndef __STM32F103xB_H
#define __STM32F103xB_H

#ifdef __cplusplus
 extern "C" {
#endif

#define __CM3_REV                  0x0200U
 #define __MPU_PRESENT             0U
#define __NVIC_PRIO_BITS           4U
#define __Vendor_SysTickConfig     0U

typedef enum
{

  NonMaskableInt_IRQn         = -14,
  HardFault_IRQn              = -13,
  MemoryManagement_IRQn       = -12,
  BusFault_IRQn               = -11,
  UsageFault_IRQn             = -10,
  SVCall_IRQn                 = -5,
  DebugMonitor_IRQn           = -4,
  PendSV_IRQn                 = -2,
  SysTick_IRQn                = -1,

  WWDG_IRQn                   = 0,
  PVD_IRQn                    = 1,
  TAMPER_IRQn                 = 2,
  RTC_IRQn                    = 3,
  FLASH_IRQn                  = 4,
  RCC_IRQn                    = 5,
  EXTI0_IRQn                  = 6,
  EXTI1_IRQn                  = 7,
  EXTI2_IRQn                  = 8,
  EXTI3_IRQn                  = 9,
  EXTI4_IRQn                  = 10,
  DMA1_Channel1_IRQn          = 11,
  DMA1_Channel2_IRQn          = 12,
  DMA1_Channel3_IRQn          = 13,
  DMA1_Channel4_IRQn          = 14,
  DMA1_Channel5_IRQn          = 15,
  DMA1_Channel6_IRQn          = 16,
  DMA1_Channel7_IRQn          = 17,
  ADC1_2_IRQn                 = 18,
  USB_HP_CAN1_TX_IRQn         = 19,
  USB_LP_CAN1_RX0_IRQn        = 20,
  CAN1_RX1_IRQn               = 21,
  CAN1_SCE_IRQn               = 22,
  EXTI9_5_IRQn                = 23,
  TIM1_BRK_IRQn               = 24,
  TIM1_UP_IRQn                = 25,
  TIM1_TRG_COM_IRQn           = 26,
  TIM1_CC_IRQn                = 27,
  TIM2_IRQn                   = 28,
  TIM3_IRQn                   = 29,
  TIM4_IRQn                   = 30,
  I2C1_EV_IRQn                = 31,
  I2C1_ER_IRQn                = 32,
  I2C2_EV_IRQn                = 33,
  I2C2_ER_IRQn                = 34,
  SPI1_IRQn                   = 35,
  SPI2_IRQn                   = 36,
  USART1_IRQn                 = 37,
  USART2_IRQn                 = 38,
  USART3_IRQn                 = 39,
  EXTI15_10_IRQn              = 40,
  RTC_Alarm_IRQn              = 41,
  USBWakeUp_IRQn              = 42,
} IRQn_Type;

#include "core_cm3.h"
#include "system_stm32f1xx.h"
#include <stdint.h>

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SMPR1;
  __IO uint32_t SMPR2;
  __IO uint32_t JOFR1;
  __IO uint32_t JOFR2;
  __IO uint32_t JOFR3;
  __IO uint32_t JOFR4;
  __IO uint32_t HTR;
  __IO uint32_t LTR;
  __IO uint32_t SQR1;
  __IO uint32_t SQR2;
  __IO uint32_t SQR3;
  __IO uint32_t JSQR;
  __IO uint32_t JDR1;
  __IO uint32_t JDR2;
  __IO uint32_t JDR3;
  __IO uint32_t JDR4;
  __IO uint32_t DR;
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  uint32_t  RESERVED[16];
  __IO uint32_t DR;
} ADC_Common_TypeDef;

typedef struct
{
  uint32_t  RESERVED0;
  __IO uint32_t DR1;
  __IO uint32_t DR2;
  __IO uint32_t DR3;
  __IO uint32_t DR4;
  __IO uint32_t DR5;
  __IO uint32_t DR6;
  __IO uint32_t DR7;
  __IO uint32_t DR8;
  __IO uint32_t DR9;
  __IO uint32_t DR10;
  __IO uint32_t RTCCR;
  __IO uint32_t CR;
  __IO uint32_t CSR;
} BKP_TypeDef;

typedef struct
{
  __IO uint32_t TIR;
  __IO uint32_t TDTR;
  __IO uint32_t TDLR;
  __IO uint32_t TDHR;
} CAN_TxMailBox_TypeDef;

typedef struct
{
  __IO uint32_t RIR;
  __IO uint32_t RDTR;
  __IO uint32_t RDLR;
  __IO uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  __IO uint32_t FR1;
  __IO uint32_t FR2;
} CAN_FilterRegister_TypeDef;

typedef struct
{
  __IO uint32_t MCR;
  __IO uint32_t MSR;
  __IO uint32_t TSR;
  __IO uint32_t RF0R;
  __IO uint32_t RF1R;
  __IO uint32_t IER;
  __IO uint32_t ESR;
  __IO uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  __IO uint32_t FMR;
  __IO uint32_t FM1R;
  uint32_t  RESERVED2;
  __IO uint32_t FS1R;
  uint32_t  RESERVED3;
  __IO uint32_t FFA1R;
  uint32_t  RESERVED4;
  __IO uint32_t FA1R;
  uint32_t  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;

typedef struct
{
  __IO uint32_t DR;
  __IO uint8_t  IDR;
  uint8_t       RESERVED0;
  uint16_t      RESERVED1;
  __IO uint32_t CR;
} CRC_TypeDef;

typedef struct
{
  __IO uint32_t IDCODE;
  __IO uint32_t CR;
}DBGMCU_TypeDef;

typedef struct
{
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
} DMA_TypeDef;

typedef struct
{
  __IO uint32_t IMR;
  __IO uint32_t EMR;
  __IO uint32_t RTSR;
  __IO uint32_t FTSR;
  __IO uint32_t SWIER;
  __IO uint32_t PR;
} EXTI_TypeDef;

typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  __IO uint32_t RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;
} FLASH_TypeDef;

typedef struct
{
  __IO uint16_t RDP;
  __IO uint16_t USER;
  __IO uint16_t Data0;
  __IO uint16_t Data1;
  __IO uint16_t WRP0;
  __IO uint16_t WRP1;
  __IO uint16_t WRP2;
  __IO uint16_t WRP3;
} OB_TypeDef;

typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;

typedef struct
{
  __IO uint32_t EVCR;
  __IO uint32_t MAPR;
  __IO uint32_t EXTICR[4];
  uint32_t RESERVED0;
  __IO uint32_t MAPR2;
} AFIO_TypeDef;

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t OAR1;
  __IO uint32_t OAR2;
  __IO uint32_t DR;
  __IO uint32_t SR1;
  __IO uint32_t SR2;
  __IO uint32_t CCR;
  __IO uint32_t TRISE;
} I2C_TypeDef;

typedef struct
{
  __IO uint32_t KR;
  __IO uint32_t PR;
  __IO uint32_t RLR;
  __IO uint32_t SR;
} IWDG_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CSR;
} PWR_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;

} RCC_TypeDef;

typedef struct
{
  __IO uint32_t CRH;
  __IO uint32_t CRL;
  __IO uint32_t PRLH;
  __IO uint32_t PRLL;
  __IO uint32_t DIVH;
  __IO uint32_t DIVL;
  __IO uint32_t CNTH;
  __IO uint32_t CNTL;
  __IO uint32_t ALRH;
  __IO uint32_t ALRL;
} RTC_TypeDef;

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t CRCPR;
  __IO uint32_t RXCRCR;
  __IO uint32_t TXCRCR;
  __IO uint32_t I2SCFGR;
} SPI_TypeDef;

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SMCR;
  __IO uint32_t DIER;
  __IO uint32_t SR;
  __IO uint32_t EGR;
  __IO uint32_t CCMR1;
  __IO uint32_t CCMR2;
  __IO uint32_t CCER;
  __IO uint32_t CNT;
  __IO uint32_t PSC;
  __IO uint32_t ARR;
  __IO uint32_t RCR;
  __IO uint32_t CCR1;
  __IO uint32_t CCR2;
  __IO uint32_t CCR3;
  __IO uint32_t CCR4;
  __IO uint32_t BDTR;
  __IO uint32_t DCR;
  __IO uint32_t DMAR;
  __IO uint32_t OR;
}TIM_TypeDef;

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t BRR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t CR3;
  __IO uint32_t GTPR;
} USART_TypeDef;

typedef struct
{
  __IO uint16_t EP0R;
  __IO uint16_t RESERVED0;
  __IO uint16_t EP1R;
  __IO uint16_t RESERVED1;
  __IO uint16_t EP2R;
  __IO uint16_t RESERVED2;
  __IO uint16_t EP3R;
  __IO uint16_t RESERVED3;
  __IO uint16_t EP4R;
  __IO uint16_t RESERVED4;
  __IO uint16_t EP5R;
  __IO uint16_t RESERVED5;
  __IO uint16_t EP6R;
  __IO uint16_t RESERVED6;
  __IO uint16_t EP7R;
  __IO uint16_t RESERVED7[17];
  __IO uint16_t CNTR;
  __IO uint16_t RESERVED8;
  __IO uint16_t ISTR;
  __IO uint16_t RESERVED9;
  __IO uint16_t FNR;
  __IO uint16_t RESERVEDA;
  __IO uint16_t DADDR;
  __IO uint16_t RESERVEDB;
  __IO uint16_t BTABLE;
  __IO uint16_t RESERVEDC;
} USB_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFR;
  __IO uint32_t SR;
} WWDG_TypeDef;

#define FLASH_BASE            0x08000000UL
#define FLASH_BANK1_END       0x0801FFFFUL
#define SRAM_BASE             0x20000000UL
#define PERIPH_BASE           0x40000000UL

#define SRAM_BB_BASE          0x22000000UL
#define PERIPH_BB_BASE        0x42000000UL

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x00000400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x00000800UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x00003800UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x00004800UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x00005800UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x00006400UL)
#define BKP_BASE              (APB1PERIPH_BASE + 0x00006C00UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000UL)
#define AFIO_BASE             (APB2PERIPH_BASE + 0x00000000UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400UL)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x00000800UL)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x00000C00UL)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x00001000UL)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x00001400UL)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x00001800UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x00002400UL)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x00002800UL)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x00002C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800UL)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000UL)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x00000008UL)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x0000001CUL)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x00000030UL)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x00000044UL)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x00000058UL)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x0000006CUL)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x00000080UL)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000UL)

#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000UL)
#define FLASHSIZE_BASE        0x1FFFF7E0UL
#define UID_BASE              0x1FFFF7E8UL
#define OB_BASE               0x1FFFF800UL

#define DBGMCU_BASE          0xE0042000UL

#define USB_BASE              (APB1PERIPH_BASE + 0x00005C00UL)
#define USB_PMAADDR           (APB1PERIPH_BASE + 0x00006000UL)

#define TIM2                ((TIM_TypeDef *)TIM2_BASE)
#define TIM3                ((TIM_TypeDef *)TIM3_BASE)
#define TIM4                ((TIM_TypeDef *)TIM4_BASE)
#define RTC                 ((RTC_TypeDef *)RTC_BASE)
#define WWDG                ((WWDG_TypeDef *)WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *)IWDG_BASE)
#define SPI2                ((SPI_TypeDef *)SPI2_BASE)
#define USART2              ((USART_TypeDef *)USART2_BASE)
#define USART3              ((USART_TypeDef *)USART3_BASE)
#define I2C1                ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                ((I2C_TypeDef *)I2C2_BASE)
#define USB                 ((USB_TypeDef *)USB_BASE)
#define CAN1                ((CAN_TypeDef *)CAN1_BASE)
#define BKP                 ((BKP_TypeDef *)BKP_BASE)
#define PWR                 ((PWR_TypeDef *)PWR_BASE)
#define AFIO                ((AFIO_TypeDef *)AFIO_BASE)
#define EXTI                ((EXTI_TypeDef *)EXTI_BASE)
#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *)GPIOE_BASE)
#define ADC1                ((ADC_TypeDef *)ADC1_BASE)
#define ADC2                ((ADC_TypeDef *)ADC2_BASE)
#define ADC12_COMMON        ((ADC_Common_TypeDef *)ADC1_BASE)
#define TIM1                ((TIM_TypeDef *)TIM1_BASE)
#define SPI1                ((SPI_TypeDef *)SPI1_BASE)
#define USART1              ((USART_TypeDef *)USART1_BASE)
#define DMA1                ((DMA_TypeDef *)DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *)DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *)DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *)DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *)DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *)DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *)DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *)DMA1_Channel7_BASE)
#define RCC                 ((RCC_TypeDef *)RCC_BASE)
#define CRC                 ((CRC_TypeDef *)CRC_BASE)
#define FLASH               ((FLASH_TypeDef *)FLASH_R_BASE)
#define OB                  ((OB_TypeDef *)OB_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *)DBGMCU_BASE)

#define LSI_STARTUP_TIME                85U

#define CRC_DR_DR_Pos                       (0U)
#define CRC_DR_DR_Msk                       (0xFFFFFFFFUL << CRC_DR_DR_Pos)
#define CRC_DR_DR                           CRC_DR_DR_Msk

#define CRC_IDR_IDR_Pos                     (0U)
#define CRC_IDR_IDR_Msk                     (0xFFUL << CRC_IDR_IDR_Pos)
#define CRC_IDR_IDR                         CRC_IDR_IDR_Msk

#define CRC_CR_RESET_Pos                    (0U)
#define CRC_CR_RESET_Msk                    (0x1UL << CRC_CR_RESET_Pos)
#define CRC_CR_RESET                        CRC_CR_RESET_Msk

#define PWR_CR_LPDS_Pos                     (0U)
#define PWR_CR_LPDS_Msk                     (0x1UL << PWR_CR_LPDS_Pos)
#define PWR_CR_LPDS                         PWR_CR_LPDS_Msk
#define PWR_CR_PDDS_Pos                     (1U)
#define PWR_CR_PDDS_Msk                     (0x1UL << PWR_CR_PDDS_Pos)
#define PWR_CR_PDDS                         PWR_CR_PDDS_Msk
#define PWR_CR_CWUF_Pos                     (2U)
#define PWR_CR_CWUF_Msk                     (0x1UL << PWR_CR_CWUF_Pos)
#define PWR_CR_CWUF                         PWR_CR_CWUF_Msk
#define PWR_CR_CSBF_Pos                     (3U)
#define PWR_CR_CSBF_Msk                     (0x1UL << PWR_CR_CSBF_Pos)
#define PWR_CR_CSBF                         PWR_CR_CSBF_Msk
#define PWR_CR_PVDE_Pos                     (4U)
#define PWR_CR_PVDE_Msk                     (0x1UL << PWR_CR_PVDE_Pos)
#define PWR_CR_PVDE                         PWR_CR_PVDE_Msk

#define PWR_CR_PLS_Pos                      (5U)
#define PWR_CR_PLS_Msk                      (0x7UL << PWR_CR_PLS_Pos)
#define PWR_CR_PLS                          PWR_CR_PLS_Msk
#define PWR_CR_PLS_0                        (0x1UL << PWR_CR_PLS_Pos)
#define PWR_CR_PLS_1                        (0x2UL << PWR_CR_PLS_Pos)
#define PWR_CR_PLS_2                        (0x4UL << PWR_CR_PLS_Pos)

#define PWR_CR_PLS_LEV0                      0x00000000U
#define PWR_CR_PLS_LEV1                      0x00000020U
#define PWR_CR_PLS_LEV2                      0x00000040U
#define PWR_CR_PLS_LEV3                      0x00000060U
#define PWR_CR_PLS_LEV4                      0x00000080U
#define PWR_CR_PLS_LEV5                      0x000000A0U
#define PWR_CR_PLS_LEV6                      0x000000C0U
#define PWR_CR_PLS_LEV7                      0x000000E0U

#define PWR_CR_PLS_2V2                       PWR_CR_PLS_LEV0
#define PWR_CR_PLS_2V3                       PWR_CR_PLS_LEV1
#define PWR_CR_PLS_2V4                       PWR_CR_PLS_LEV2
#define PWR_CR_PLS_2V5                       PWR_CR_PLS_LEV3
#define PWR_CR_PLS_2V6                       PWR_CR_PLS_LEV4
#define PWR_CR_PLS_2V7                       PWR_CR_PLS_LEV5
#define PWR_CR_PLS_2V8                       PWR_CR_PLS_LEV6
#define PWR_CR_PLS_2V9                       PWR_CR_PLS_LEV7

#define PWR_CR_DBP_Pos                      (8U)
#define PWR_CR_DBP_Msk                      (0x1UL << PWR_CR_DBP_Pos)
#define PWR_CR_DBP                          PWR_CR_DBP_Msk

#define PWR_CSR_WUF_Pos                     (0U)
#define PWR_CSR_WUF_Msk                     (0x1UL << PWR_CSR_WUF_Pos)
#define PWR_CSR_WUF                         PWR_CSR_WUF_Msk
#define PWR_CSR_SBF_Pos                     (1U)
#define PWR_CSR_SBF_Msk                     (0x1UL << PWR_CSR_SBF_Pos)
#define PWR_CSR_SBF                         PWR_CSR_SBF_Msk
#define PWR_CSR_PVDO_Pos                    (2U)
#define PWR_CSR_PVDO_Msk                    (0x1UL << PWR_CSR_PVDO_Pos)
#define PWR_CSR_PVDO                        PWR_CSR_PVDO_Msk
#define PWR_CSR_EWUP_Pos                    (8U)
#define PWR_CSR_EWUP_Msk                    (0x1UL << PWR_CSR_EWUP_Pos)
#define PWR_CSR_EWUP                        PWR_CSR_EWUP_Msk

#define BKP_DR1_D_Pos                       (0U)
#define BKP_DR1_D_Msk                       (0xFFFFUL << BKP_DR1_D_Pos)
#define BKP_DR1_D                           BKP_DR1_D_Msk

#define BKP_DR2_D_Pos                       (0U)
#define BKP_DR2_D_Msk                       (0xFFFFUL << BKP_DR2_D_Pos)
#define BKP_DR2_D                           BKP_DR2_D_Msk

#define BKP_DR3_D_Pos                       (0U)
#define BKP_DR3_D_Msk                       (0xFFFFUL << BKP_DR3_D_Pos)
#define BKP_DR3_D                           BKP_DR3_D_Msk

#define BKP_DR4_D_Pos                       (0U)
#define BKP_DR4_D_Msk                       (0xFFFFUL << BKP_DR4_D_Pos)
#define BKP_DR4_D                           BKP_DR4_D_Msk

#define BKP_DR5_D_Pos                       (0U)
#define BKP_DR5_D_Msk                       (0xFFFFUL << BKP_DR5_D_Pos)
#define BKP_DR5_D                           BKP_DR5_D_Msk

#define BKP_DR6_D_Pos                       (0U)
#define BKP_DR6_D_Msk                       (0xFFFFUL << BKP_DR6_D_Pos)
#define BKP_DR6_D                           BKP_DR6_D_Msk

#define BKP_DR7_D_Pos                       (0U)
#define BKP_DR7_D_Msk                       (0xFFFFUL << BKP_DR7_D_Pos)
#define BKP_DR7_D                           BKP_DR7_D_Msk

#define BKP_DR8_D_Pos                       (0U)
#define BKP_DR8_D_Msk                       (0xFFFFUL << BKP_DR8_D_Pos)
#define BKP_DR8_D                           BKP_DR8_D_Msk

#define BKP_DR9_D_Pos                       (0U)
#define BKP_DR9_D_Msk                       (0xFFFFUL << BKP_DR9_D_Pos)
#define BKP_DR9_D                           BKP_DR9_D_Msk

#define BKP_DR10_D_Pos                      (0U)
#define BKP_DR10_D_Msk                      (0xFFFFUL << BKP_DR10_D_Pos)
#define BKP_DR10_D                          BKP_DR10_D_Msk

#define RTC_BKP_NUMBER 10

#define BKP_RTCCR_CAL_Pos                   (0U)
#define BKP_RTCCR_CAL_Msk                   (0x7FUL << BKP_RTCCR_CAL_Pos)
#define BKP_RTCCR_CAL                       BKP_RTCCR_CAL_Msk
#define BKP_RTCCR_CCO_Pos                   (7U)
#define BKP_RTCCR_CCO_Msk                   (0x1UL << BKP_RTCCR_CCO_Pos)
#define BKP_RTCCR_CCO                       BKP_RTCCR_CCO_Msk
#define BKP_RTCCR_ASOE_Pos                  (8U)
#define BKP_RTCCR_ASOE_Msk                  (0x1UL << BKP_RTCCR_ASOE_Pos)
#define BKP_RTCCR_ASOE                      BKP_RTCCR_ASOE_Msk
#define BKP_RTCCR_ASOS_Pos                  (9U)
#define BKP_RTCCR_ASOS_Msk                  (0x1UL << BKP_RTCCR_ASOS_Pos)
#define BKP_RTCCR_ASOS                      BKP_RTCCR_ASOS_Msk

#define BKP_CR_TPE_Pos                      (0U)
#define BKP_CR_TPE_Msk                      (0x1UL << BKP_CR_TPE_Pos)
#define BKP_CR_TPE                          BKP_CR_TPE_Msk
#define BKP_CR_TPAL_Pos                     (1U)
#define BKP_CR_TPAL_Msk                     (0x1UL << BKP_CR_TPAL_Pos)
#define BKP_CR_TPAL                         BKP_CR_TPAL_Msk

#define BKP_CSR_CTE_Pos                     (0U)
#define BKP_CSR_CTE_Msk                     (0x1UL << BKP_CSR_CTE_Pos)
#define BKP_CSR_CTE                         BKP_CSR_CTE_Msk
#define BKP_CSR_CTI_Pos                     (1U)
#define BKP_CSR_CTI_Msk                     (0x1UL << BKP_CSR_CTI_Pos)
#define BKP_CSR_CTI                         BKP_CSR_CTI_Msk
#define BKP_CSR_TPIE_Pos                    (2U)
#define BKP_CSR_TPIE_Msk                    (0x1UL << BKP_CSR_TPIE_Pos)
#define BKP_CSR_TPIE                        BKP_CSR_TPIE_Msk
#define BKP_CSR_TEF_Pos                     (8U)
#define BKP_CSR_TEF_Msk                     (0x1UL << BKP_CSR_TEF_Pos)
#define BKP_CSR_TEF                         BKP_CSR_TEF_Msk
#define BKP_CSR_TIF_Pos                     (9U)
#define BKP_CSR_TIF_Msk                     (0x1UL << BKP_CSR_TIF_Pos)
#define BKP_CSR_TIF                         BKP_CSR_TIF_Msk

#define RCC_CR_HSION_Pos                     (0U)
#define RCC_CR_HSION_Msk                     (0x1UL << RCC_CR_HSION_Pos)
#define RCC_CR_HSION                         RCC_CR_HSION_Msk
#define RCC_CR_HSIRDY_Pos                    (1U)
#define RCC_CR_HSIRDY_Msk                    (0x1UL << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSIRDY                        RCC_CR_HSIRDY_Msk
#define RCC_CR_HSITRIM_Pos                   (3U)
#define RCC_CR_HSITRIM_Msk                   (0x1FUL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM                       RCC_CR_HSITRIM_Msk
#define RCC_CR_HSICAL_Pos                    (8U)
#define RCC_CR_HSICAL_Msk                    (0xFFUL << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL                        RCC_CR_HSICAL_Msk
#define RCC_CR_HSEON_Pos                     (16U)
#define RCC_CR_HSEON_Msk                     (0x1UL << RCC_CR_HSEON_Pos)
#define RCC_CR_HSEON                         RCC_CR_HSEON_Msk
#define RCC_CR_HSERDY_Pos                    (17U)
#define RCC_CR_HSERDY_Msk                    (0x1UL << RCC_CR_HSERDY_Pos)
#define RCC_CR_HSERDY                        RCC_CR_HSERDY_Msk
#define RCC_CR_HSEBYP_Pos                    (18U)
#define RCC_CR_HSEBYP_Msk                    (0x1UL << RCC_CR_HSEBYP_Pos)
#define RCC_CR_HSEBYP                        RCC_CR_HSEBYP_Msk
#define RCC_CR_CSSON_Pos                     (19U)
#define RCC_CR_CSSON_Msk                     (0x1UL << RCC_CR_CSSON_Pos)
#define RCC_CR_CSSON                         RCC_CR_CSSON_Msk
#define RCC_CR_PLLON_Pos                     (24U)
#define RCC_CR_PLLON_Msk                     (0x1UL << RCC_CR_PLLON_Pos)
#define RCC_CR_PLLON                         RCC_CR_PLLON_Msk
#define RCC_CR_PLLRDY_Pos                    (25U)
#define RCC_CR_PLLRDY_Msk                    (0x1UL << RCC_CR_PLLRDY_Pos)
#define RCC_CR_PLLRDY                        RCC_CR_PLLRDY_Msk

#define RCC_CFGR_SW_Pos                      (0U)
#define RCC_CFGR_SW_Msk                      (0x3UL << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW                          RCC_CFGR_SW_Msk
#define RCC_CFGR_SW_0                        (0x1UL << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_1                        (0x2UL << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SW_HSI                      0x00000000U
#define RCC_CFGR_SW_HSE                      0x00000001U
#define RCC_CFGR_SW_PLL                      0x00000002U

#define RCC_CFGR_SWS_Pos                     (2U)
#define RCC_CFGR_SWS_Msk                     (0x3UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS                         RCC_CFGR_SWS_Msk
#define RCC_CFGR_SWS_0                       (0x1UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_1                       (0x2UL << RCC_CFGR_SWS_Pos)

#define RCC_CFGR_SWS_HSI                     0x00000000U
#define RCC_CFGR_SWS_HSE                     0x00000004U
#define RCC_CFGR_SWS_PLL                     0x00000008U

#define RCC_CFGR_HPRE_Pos                    (4U)
#define RCC_CFGR_HPRE_Msk                    (0xFUL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE                        RCC_CFGR_HPRE_Msk
#define RCC_CFGR_HPRE_0                      (0x1UL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_1                      (0x2UL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_2                      (0x4UL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_3                      (0x8UL << RCC_CFGR_HPRE_Pos)

#define RCC_CFGR_HPRE_DIV1                   0x00000000U
#define RCC_CFGR_HPRE_DIV2                   0x00000080U
#define RCC_CFGR_HPRE_DIV4                   0x00000090U
#define RCC_CFGR_HPRE_DIV8                   0x000000A0U
#define RCC_CFGR_HPRE_DIV16                  0x000000B0U
#define RCC_CFGR_HPRE_DIV64                  0x000000C0U
#define RCC_CFGR_HPRE_DIV128                 0x000000D0U
#define RCC_CFGR_HPRE_DIV256                 0x000000E0U
#define RCC_CFGR_HPRE_DIV512                 0x000000F0U

#define RCC_CFGR_PPRE1_Pos                   (8U)
#define RCC_CFGR_PPRE1_Msk                   (0x7UL << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1                       RCC_CFGR_PPRE1_Msk
#define RCC_CFGR_PPRE1_0                     (0x1UL << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_1                     (0x2UL << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_2                     (0x4UL << RCC_CFGR_PPRE1_Pos)

#define RCC_CFGR_PPRE1_DIV1                  0x00000000U
#define RCC_CFGR_PPRE1_DIV2                  0x00000400U
#define RCC_CFGR_PPRE1_DIV4                  0x00000500U
#define RCC_CFGR_PPRE1_DIV8                  0x00000600U
#define RCC_CFGR_PPRE1_DIV16                 0x00000700U

#define RCC_CFGR_PPRE2_Pos                   (11U)
#define RCC_CFGR_PPRE2_Msk                   (0x7UL << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2                       RCC_CFGR_PPRE2_Msk
#define RCC_CFGR_PPRE2_0                     (0x1UL << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_1                     (0x2UL << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_2                     (0x4UL << RCC_CFGR_PPRE2_Pos)

#define RCC_CFGR_PPRE2_DIV1                  0x00000000U
#define RCC_CFGR_PPRE2_DIV2                  0x00002000U
#define RCC_CFGR_PPRE2_DIV4                  0x00002800U
#define RCC_CFGR_PPRE2_DIV8                  0x00003000U
#define RCC_CFGR_PPRE2_DIV16                 0x00003800U

#define RCC_CFGR_ADCPRE_Pos                  (14U)
#define RCC_CFGR_ADCPRE_Msk                  (0x3UL << RCC_CFGR_ADCPRE_Pos)
#define RCC_CFGR_ADCPRE                      RCC_CFGR_ADCPRE_Msk
#define RCC_CFGR_ADCPRE_0                    (0x1UL << RCC_CFGR_ADCPRE_Pos)
#define RCC_CFGR_ADCPRE_1                    (0x2UL << RCC_CFGR_ADCPRE_Pos)

#define RCC_CFGR_ADCPRE_DIV2                 0x00000000U
#define RCC_CFGR_ADCPRE_DIV4                 0x00004000U
#define RCC_CFGR_ADCPRE_DIV6                 0x00008000U
#define RCC_CFGR_ADCPRE_DIV8                 0x0000C000U

#define RCC_CFGR_PLLSRC_Pos                  (16U)
#define RCC_CFGR_PLLSRC_Msk                  (0x1UL << RCC_CFGR_PLLSRC_Pos)
#define RCC_CFGR_PLLSRC                      RCC_CFGR_PLLSRC_Msk

#define RCC_CFGR_PLLXTPRE_Pos                (17U)
#define RCC_CFGR_PLLXTPRE_Msk                (0x1UL << RCC_CFGR_PLLXTPRE_Pos)
#define RCC_CFGR_PLLXTPRE                    RCC_CFGR_PLLXTPRE_Msk

#define RCC_CFGR_PLLMULL_Pos                 (18U)
#define RCC_CFGR_PLLMULL_Msk                 (0xFUL << RCC_CFGR_PLLMULL_Pos)
#define RCC_CFGR_PLLMULL                     RCC_CFGR_PLLMULL_Msk
#define RCC_CFGR_PLLMULL_0                   (0x1UL << RCC_CFGR_PLLMULL_Pos)
#define RCC_CFGR_PLLMULL_1                   (0x2UL << RCC_CFGR_PLLMULL_Pos)
#define RCC_CFGR_PLLMULL_2                   (0x4UL << RCC_CFGR_PLLMULL_Pos)
#define RCC_CFGR_PLLMULL_3                   (0x8UL << RCC_CFGR_PLLMULL_Pos)

#define RCC_CFGR_PLLXTPRE_HSE                0x00000000U
#define RCC_CFGR_PLLXTPRE_HSE_DIV2           0x00020000U

#define RCC_CFGR_PLLMULL2                    0x00000000U
#define RCC_CFGR_PLLMULL3_Pos                (18U)
#define RCC_CFGR_PLLMULL3_Msk                (0x1UL << RCC_CFGR_PLLMULL3_Pos)
#define RCC_CFGR_PLLMULL3                    RCC_CFGR_PLLMULL3_Msk
#define RCC_CFGR_PLLMULL4_Pos                (19U)
#define RCC_CFGR_PLLMULL4_Msk                (0x1UL << RCC_CFGR_PLLMULL4_Pos)
#define RCC_CFGR_PLLMULL4                    RCC_CFGR_PLLMULL4_Msk
#define RCC_CFGR_PLLMULL5_Pos                (18U)
#define RCC_CFGR_PLLMULL5_Msk                (0x3UL << RCC_CFGR_PLLMULL5_Pos)
#define RCC_CFGR_PLLMULL5                    RCC_CFGR_PLLMULL5_Msk
#define RCC_CFGR_PLLMULL6_Pos                (20U)
#define RCC_CFGR_PLLMULL6_Msk                (0x1UL << RCC_CFGR_PLLMULL6_Pos)
#define RCC_CFGR_PLLMULL6                    RCC_CFGR_PLLMULL6_Msk
#define RCC_CFGR_PLLMULL7_Pos                (18U)
#define RCC_CFGR_PLLMULL7_Msk                (0x5UL << RCC_CFGR_PLLMULL7_Pos)
#define RCC_CFGR_PLLMULL7                    RCC_CFGR_PLLMULL7_Msk
#define RCC_CFGR_PLLMULL8_Pos                (19U)
#define RCC_CFGR_PLLMULL8_Msk                (0x3UL << RCC_CFGR_PLLMULL8_Pos)
#define RCC_CFGR_PLLMULL8                    RCC_CFGR_PLLMULL8_Msk
#define RCC_CFGR_PLLMULL9_Pos                (18U)
#define RCC_CFGR_PLLMULL9_Msk                (0x7UL << RCC_CFGR_PLLMULL9_Pos)
#define RCC_CFGR_PLLMULL9                    RCC_CFGR_PLLMULL9_Msk
#define RCC_CFGR_PLLMULL10_Pos               (21U)
#define RCC_CFGR_PLLMULL10_Msk               (0x1UL << RCC_CFGR_PLLMULL10_Pos)
#define RCC_CFGR_PLLMULL10                   RCC_CFGR_PLLMULL10_Msk
#define RCC_CFGR_PLLMULL11_Pos               (18U)
#define RCC_CFGR_PLLMULL11_Msk               (0x9UL << RCC_CFGR_PLLMULL11_Pos)
#define RCC_CFGR_PLLMULL11                   RCC_CFGR_PLLMULL11_Msk
#define RCC_CFGR_PLLMULL12_Pos               (19U)
#define RCC_CFGR_PLLMULL12_Msk               (0x5UL << RCC_CFGR_PLLMULL12_Pos)
#define RCC_CFGR_PLLMULL12                   RCC_CFGR_PLLMULL12_Msk
#define RCC_CFGR_PLLMULL13_Pos               (18U)
#define RCC_CFGR_PLLMULL13_Msk               (0xBUL << RCC_CFGR_PLLMULL13_Pos)
#define RCC_CFGR_PLLMULL13                   RCC_CFGR_PLLMULL13_Msk
#define RCC_CFGR_PLLMULL14_Pos               (20U)
#define RCC_CFGR_PLLMULL14_Msk               (0x3UL << RCC_CFGR_PLLMULL14_Pos)
#define RCC_CFGR_PLLMULL14                   RCC_CFGR_PLLMULL14_Msk
#define RCC_CFGR_PLLMULL15_Pos               (18U)
#define RCC_CFGR_PLLMULL15_Msk               (0xDUL << RCC_CFGR_PLLMULL15_Pos)
#define RCC_CFGR_PLLMULL15                   RCC_CFGR_PLLMULL15_Msk
#define RCC_CFGR_PLLMULL16_Pos               (19U)
#define RCC_CFGR_PLLMULL16_Msk               (0x7UL << RCC_CFGR_PLLMULL16_Pos)
#define RCC_CFGR_PLLMULL16                   RCC_CFGR_PLLMULL16_Msk
#define RCC_CFGR_USBPRE_Pos                  (22U)
#define RCC_CFGR_USBPRE_Msk                  (0x1UL << RCC_CFGR_USBPRE_Pos)
#define RCC_CFGR_USBPRE                      RCC_CFGR_USBPRE_Msk

#define RCC_CFGR_MCO_Pos                     (24U)
#define RCC_CFGR_MCO_Msk                     (0x7UL << RCC_CFGR_MCO_Pos)
#define RCC_CFGR_MCO                         RCC_CFGR_MCO_Msk
#define RCC_CFGR_MCO_0                       (0x1UL << RCC_CFGR_MCO_Pos)
#define RCC_CFGR_MCO_1                       (0x2UL << RCC_CFGR_MCO_Pos)
#define RCC_CFGR_MCO_2                       (0x4UL << RCC_CFGR_MCO_Pos)

#define RCC_CFGR_MCO_NOCLOCK                 0x00000000U
#define RCC_CFGR_MCO_SYSCLK                  0x04000000U
#define RCC_CFGR_MCO_HSI                     0x05000000U
#define RCC_CFGR_MCO_HSE                     0x06000000U
#define RCC_CFGR_MCO_PLLCLK_DIV2             0x07000000U

 #define RCC_CFGR_MCOSEL                      RCC_CFGR_MCO
 #define RCC_CFGR_MCOSEL_0                    RCC_CFGR_MCO_0
 #define RCC_CFGR_MCOSEL_1                    RCC_CFGR_MCO_1
 #define RCC_CFGR_MCOSEL_2                    RCC_CFGR_MCO_2
 #define RCC_CFGR_MCOSEL_NOCLOCK              RCC_CFGR_MCO_NOCLOCK
 #define RCC_CFGR_MCOSEL_SYSCLK               RCC_CFGR_MCO_SYSCLK
 #define RCC_CFGR_MCOSEL_HSI                  RCC_CFGR_MCO_HSI
 #define RCC_CFGR_MCOSEL_HSE                  RCC_CFGR_MCO_HSE
 #define RCC_CFGR_MCOSEL_PLL_DIV2             RCC_CFGR_MCO_PLLCLK_DIV2

#define RCC_CIR_LSIRDYF_Pos                  (0U)
#define RCC_CIR_LSIRDYF_Msk                  (0x1UL << RCC_CIR_LSIRDYF_Pos)
#define RCC_CIR_LSIRDYF                      RCC_CIR_LSIRDYF_Msk
#define RCC_CIR_LSERDYF_Pos                  (1U)
#define RCC_CIR_LSERDYF_Msk                  (0x1UL << RCC_CIR_LSERDYF_Pos)
#define RCC_CIR_LSERDYF                      RCC_CIR_LSERDYF_Msk
#define RCC_CIR_HSIRDYF_Pos                  (2U)
#define RCC_CIR_HSIRDYF_Msk                  (0x1UL << RCC_CIR_HSIRDYF_Pos)
#define RCC_CIR_HSIRDYF                      RCC_CIR_HSIRDYF_Msk
#define RCC_CIR_HSERDYF_Pos                  (3U)
#define RCC_CIR_HSERDYF_Msk                  (0x1UL << RCC_CIR_HSERDYF_Pos)
#define RCC_CIR_HSERDYF                      RCC_CIR_HSERDYF_Msk
#define RCC_CIR_PLLRDYF_Pos                  (4U)
#define RCC_CIR_PLLRDYF_Msk                  (0x1UL << RCC_CIR_PLLRDYF_Pos)
#define RCC_CIR_PLLRDYF                      RCC_CIR_PLLRDYF_Msk
#define RCC_CIR_CSSF_Pos                     (7U)
#define RCC_CIR_CSSF_Msk                     (0x1UL << RCC_CIR_CSSF_Pos)
#define RCC_CIR_CSSF                         RCC_CIR_CSSF_Msk
#define RCC_CIR_LSIRDYIE_Pos                 (8U)
#define RCC_CIR_LSIRDYIE_Msk                 (0x1UL << RCC_CIR_LSIRDYIE_Pos)
#define RCC_CIR_LSIRDYIE                     RCC_CIR_LSIRDYIE_Msk
#define RCC_CIR_LSERDYIE_Pos                 (9U)
#define RCC_CIR_LSERDYIE_Msk                 (0x1UL << RCC_CIR_LSERDYIE_Pos)
#define RCC_CIR_LSERDYIE                     RCC_CIR_LSERDYIE_Msk
#define RCC_CIR_HSIRDYIE_Pos                 (10U)
#define RCC_CIR_HSIRDYIE_Msk                 (0x1UL << RCC_CIR_HSIRDYIE_Pos)
#define RCC_CIR_HSIRDYIE                     RCC_CIR_HSIRDYIE_Msk
#define RCC_CIR_HSERDYIE_Pos                 (11U)
#define RCC_CIR_HSERDYIE_Msk                 (0x1UL << RCC_CIR_HSERDYIE_Pos)
#define RCC_CIR_HSERDYIE                     RCC_CIR_HSERDYIE_Msk
#define RCC_CIR_PLLRDYIE_Pos                 (12U)
#define RCC_CIR_PLLRDYIE_Msk                 (0x1UL << RCC_CIR_PLLRDYIE_Pos)
#define RCC_CIR_PLLRDYIE                     RCC_CIR_PLLRDYIE_Msk
#define RCC_CIR_LSIRDYC_Pos                  (16U)
#define RCC_CIR_LSIRDYC_Msk                  (0x1UL << RCC_CIR_LSIRDYC_Pos)
#define RCC_CIR_LSIRDYC                      RCC_CIR_LSIRDYC_Msk
#define RCC_CIR_LSERDYC_Pos                  (17U)
#define RCC_CIR_LSERDYC_Msk                  (0x1UL << RCC_CIR_LSERDYC_Pos)
#define RCC_CIR_LSERDYC                      RCC_CIR_LSERDYC_Msk
#define RCC_CIR_HSIRDYC_Pos                  (18U)
#define RCC_CIR_HSIRDYC_Msk                  (0x1UL << RCC_CIR_HSIRDYC_Pos)
#define RCC_CIR_HSIRDYC                      RCC_CIR_HSIRDYC_Msk
#define RCC_CIR_HSERDYC_Pos                  (19U)
#define RCC_CIR_HSERDYC_Msk                  (0x1UL << RCC_CIR_HSERDYC_Pos)
#define RCC_CIR_HSERDYC                      RCC_CIR_HSERDYC_Msk
#define RCC_CIR_PLLRDYC_Pos                  (20U)
#define RCC_CIR_PLLRDYC_Msk                  (0x1UL << RCC_CIR_PLLRDYC_Pos)
#define RCC_CIR_PLLRDYC                      RCC_CIR_PLLRDYC_Msk
#define RCC_CIR_CSSC_Pos                     (23U)
#define RCC_CIR_CSSC_Msk                     (0x1UL << RCC_CIR_CSSC_Pos)
#define RCC_CIR_CSSC                         RCC_CIR_CSSC_Msk

#define RCC_APB2RSTR_AFIORST_Pos             (0U)
#define RCC_APB2RSTR_AFIORST_Msk             (0x1UL << RCC_APB2RSTR_AFIORST_Pos)
#define RCC_APB2RSTR_AFIORST                 RCC_APB2RSTR_AFIORST_Msk
#define RCC_APB2RSTR_IOPARST_Pos             (2U)
#define RCC_APB2RSTR_IOPARST_Msk             (0x1UL << RCC_APB2RSTR_IOPARST_Pos)
#define RCC_APB2RSTR_IOPARST                 RCC_APB2RSTR_IOPARST_Msk
#define RCC_APB2RSTR_IOPBRST_Pos             (3U)
#define RCC_APB2RSTR_IOPBRST_Msk             (0x1UL << RCC_APB2RSTR_IOPBRST_Pos)
#define RCC_APB2RSTR_IOPBRST                 RCC_APB2RSTR_IOPBRST_Msk
#define RCC_APB2RSTR_IOPCRST_Pos             (4U)
#define RCC_APB2RSTR_IOPCRST_Msk             (0x1UL << RCC_APB2RSTR_IOPCRST_Pos)
#define RCC_APB2RSTR_IOPCRST                 RCC_APB2RSTR_IOPCRST_Msk
#define RCC_APB2RSTR_IOPDRST_Pos             (5U)
#define RCC_APB2RSTR_IOPDRST_Msk             (0x1UL << RCC_APB2RSTR_IOPDRST_Pos)
#define RCC_APB2RSTR_IOPDRST                 RCC_APB2RSTR_IOPDRST_Msk
#define RCC_APB2RSTR_ADC1RST_Pos             (9U)
#define RCC_APB2RSTR_ADC1RST_Msk             (0x1UL << RCC_APB2RSTR_ADC1RST_Pos)
#define RCC_APB2RSTR_ADC1RST                 RCC_APB2RSTR_ADC1RST_Msk

#define RCC_APB2RSTR_ADC2RST_Pos             (10U)
#define RCC_APB2RSTR_ADC2RST_Msk             (0x1UL << RCC_APB2RSTR_ADC2RST_Pos)
#define RCC_APB2RSTR_ADC2RST                 RCC_APB2RSTR_ADC2RST_Msk

#define RCC_APB2RSTR_TIM1RST_Pos             (11U)
#define RCC_APB2RSTR_TIM1RST_Msk             (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)
#define RCC_APB2RSTR_TIM1RST                 RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos             (12U)
#define RCC_APB2RSTR_SPI1RST_Msk             (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)
#define RCC_APB2RSTR_SPI1RST                 RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos           (14U)
#define RCC_APB2RSTR_USART1RST_Msk           (0x1UL << RCC_APB2RSTR_USART1RST_Pos)
#define RCC_APB2RSTR_USART1RST               RCC_APB2RSTR_USART1RST_Msk

#define RCC_APB2RSTR_IOPERST_Pos             (6U)
#define RCC_APB2RSTR_IOPERST_Msk             (0x1UL << RCC_APB2RSTR_IOPERST_Pos)
#define RCC_APB2RSTR_IOPERST                 RCC_APB2RSTR_IOPERST_Msk

#define RCC_APB1RSTR_TIM2RST_Pos             (0U)
#define RCC_APB1RSTR_TIM2RST_Msk             (0x1UL << RCC_APB1RSTR_TIM2RST_Pos)
#define RCC_APB1RSTR_TIM2RST                 RCC_APB1RSTR_TIM2RST_Msk
#define RCC_APB1RSTR_TIM3RST_Pos             (1U)
#define RCC_APB1RSTR_TIM3RST_Msk             (0x1UL << RCC_APB1RSTR_TIM3RST_Pos)
#define RCC_APB1RSTR_TIM3RST                 RCC_APB1RSTR_TIM3RST_Msk
#define RCC_APB1RSTR_WWDGRST_Pos             (11U)
#define RCC_APB1RSTR_WWDGRST_Msk             (0x1UL << RCC_APB1RSTR_WWDGRST_Pos)
#define RCC_APB1RSTR_WWDGRST                 RCC_APB1RSTR_WWDGRST_Msk
#define RCC_APB1RSTR_USART2RST_Pos           (17U)
#define RCC_APB1RSTR_USART2RST_Msk           (0x1UL << RCC_APB1RSTR_USART2RST_Pos)
#define RCC_APB1RSTR_USART2RST               RCC_APB1RSTR_USART2RST_Msk
#define RCC_APB1RSTR_I2C1RST_Pos             (21U)
#define RCC_APB1RSTR_I2C1RST_Msk             (0x1UL << RCC_APB1RSTR_I2C1RST_Pos)
#define RCC_APB1RSTR_I2C1RST                 RCC_APB1RSTR_I2C1RST_Msk

#define RCC_APB1RSTR_CAN1RST_Pos             (25U)
#define RCC_APB1RSTR_CAN1RST_Msk             (0x1UL << RCC_APB1RSTR_CAN1RST_Pos)
#define RCC_APB1RSTR_CAN1RST                 RCC_APB1RSTR_CAN1RST_Msk

#define RCC_APB1RSTR_BKPRST_Pos              (27U)
#define RCC_APB1RSTR_BKPRST_Msk              (0x1UL << RCC_APB1RSTR_BKPRST_Pos)
#define RCC_APB1RSTR_BKPRST                  RCC_APB1RSTR_BKPRST_Msk
#define RCC_APB1RSTR_PWRRST_Pos              (28U)
#define RCC_APB1RSTR_PWRRST_Msk              (0x1UL << RCC_APB1RSTR_PWRRST_Pos)
#define RCC_APB1RSTR_PWRRST                  RCC_APB1RSTR_PWRRST_Msk

#define RCC_APB1RSTR_TIM4RST_Pos             (2U)
#define RCC_APB1RSTR_TIM4RST_Msk             (0x1UL << RCC_APB1RSTR_TIM4RST_Pos)
#define RCC_APB1RSTR_TIM4RST                 RCC_APB1RSTR_TIM4RST_Msk
#define RCC_APB1RSTR_SPI2RST_Pos             (14U)
#define RCC_APB1RSTR_SPI2RST_Msk             (0x1UL << RCC_APB1RSTR_SPI2RST_Pos)
#define RCC_APB1RSTR_SPI2RST                 RCC_APB1RSTR_SPI2RST_Msk
#define RCC_APB1RSTR_USART3RST_Pos           (18U)
#define RCC_APB1RSTR_USART3RST_Msk           (0x1UL << RCC_APB1RSTR_USART3RST_Pos)
#define RCC_APB1RSTR_USART3RST               RCC_APB1RSTR_USART3RST_Msk
#define RCC_APB1RSTR_I2C2RST_Pos             (22U)
#define RCC_APB1RSTR_I2C2RST_Msk             (0x1UL << RCC_APB1RSTR_I2C2RST_Pos)
#define RCC_APB1RSTR_I2C2RST                 RCC_APB1RSTR_I2C2RST_Msk

#define RCC_APB1RSTR_USBRST_Pos              (23U)
#define RCC_APB1RSTR_USBRST_Msk              (0x1UL << RCC_APB1RSTR_USBRST_Pos)
#define RCC_APB1RSTR_USBRST                  RCC_APB1RSTR_USBRST_Msk

#define RCC_AHBENR_DMA1EN_Pos                (0U)
#define RCC_AHBENR_DMA1EN_Msk                (0x1UL << RCC_AHBENR_DMA1EN_Pos)
#define RCC_AHBENR_DMA1EN                    RCC_AHBENR_DMA1EN_Msk
#define RCC_AHBENR_SRAMEN_Pos                (2U)
#define RCC_AHBENR_SRAMEN_Msk                (0x1UL << RCC_AHBENR_SRAMEN_Pos)
#define RCC_AHBENR_SRAMEN                    RCC_AHBENR_SRAMEN_Msk
#define RCC_AHBENR_FLITFEN_Pos               (4U)
#define RCC_AHBENR_FLITFEN_Msk               (0x1UL << RCC_AHBENR_FLITFEN_Pos)
#define RCC_AHBENR_FLITFEN                   RCC_AHBENR_FLITFEN_Msk
#define RCC_AHBENR_CRCEN_Pos                 (6U)
#define RCC_AHBENR_CRCEN_Msk                 (0x1UL << RCC_AHBENR_CRCEN_Pos)
#define RCC_AHBENR_CRCEN                     RCC_AHBENR_CRCEN_Msk

#define RCC_APB2ENR_AFIOEN_Pos               (0U)
#define RCC_APB2ENR_AFIOEN_Msk               (0x1UL << RCC_APB2ENR_AFIOEN_Pos)
#define RCC_APB2ENR_AFIOEN                   RCC_APB2ENR_AFIOEN_Msk
#define RCC_APB2ENR_IOPAEN_Pos               (2U)
#define RCC_APB2ENR_IOPAEN_Msk               (0x1UL << RCC_APB2ENR_IOPAEN_Pos)
#define RCC_APB2ENR_IOPAEN                   RCC_APB2ENR_IOPAEN_Msk
#define RCC_APB2ENR_IOPBEN_Pos               (3U)
#define RCC_APB2ENR_IOPBEN_Msk               (0x1UL << RCC_APB2ENR_IOPBEN_Pos)
#define RCC_APB2ENR_IOPBEN                   RCC_APB2ENR_IOPBEN_Msk
#define RCC_APB2ENR_IOPCEN_Pos               (4U)
#define RCC_APB2ENR_IOPCEN_Msk               (0x1UL << RCC_APB2ENR_IOPCEN_Pos)
#define RCC_APB2ENR_IOPCEN                   RCC_APB2ENR_IOPCEN_Msk
#define RCC_APB2ENR_IOPDEN_Pos               (5U)
#define RCC_APB2ENR_IOPDEN_Msk               (0x1UL << RCC_APB2ENR_IOPDEN_Pos)
#define RCC_APB2ENR_IOPDEN                   RCC_APB2ENR_IOPDEN_Msk
#define RCC_APB2ENR_ADC1EN_Pos               (9U)
#define RCC_APB2ENR_ADC1EN_Msk               (0x1UL << RCC_APB2ENR_ADC1EN_Pos)
#define RCC_APB2ENR_ADC1EN                   RCC_APB2ENR_ADC1EN_Msk

#define RCC_APB2ENR_ADC2EN_Pos               (10U)
#define RCC_APB2ENR_ADC2EN_Msk               (0x1UL << RCC_APB2ENR_ADC2EN_Pos)
#define RCC_APB2ENR_ADC2EN                   RCC_APB2ENR_ADC2EN_Msk

#define RCC_APB2ENR_TIM1EN_Pos               (11U)
#define RCC_APB2ENR_TIM1EN_Msk               (0x1UL << RCC_APB2ENR_TIM1EN_Pos)
#define RCC_APB2ENR_TIM1EN                   RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_SPI1EN_Pos               (12U)
#define RCC_APB2ENR_SPI1EN_Msk               (0x1UL << RCC_APB2ENR_SPI1EN_Pos)
#define RCC_APB2ENR_SPI1EN                   RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_USART1EN_Pos             (14U)
#define RCC_APB2ENR_USART1EN_Msk             (0x1UL << RCC_APB2ENR_USART1EN_Pos)
#define RCC_APB2ENR_USART1EN                 RCC_APB2ENR_USART1EN_Msk

#define RCC_APB2ENR_IOPEEN_Pos               (6U)
#define RCC_APB2ENR_IOPEEN_Msk               (0x1UL << RCC_APB2ENR_IOPEEN_Pos)
#define RCC_APB2ENR_IOPEEN                   RCC_APB2ENR_IOPEEN_Msk

#define RCC_APB1ENR_TIM2EN_Pos               (0U)
#define RCC_APB1ENR_TIM2EN_Msk               (0x1UL << RCC_APB1ENR_TIM2EN_Pos)
#define RCC_APB1ENR_TIM2EN                   RCC_APB1ENR_TIM2EN_Msk
#define RCC_APB1ENR_TIM3EN_Pos               (1U)
#define RCC_APB1ENR_TIM3EN_Msk               (0x1UL << RCC_APB1ENR_TIM3EN_Pos)
#define RCC_APB1ENR_TIM3EN                   RCC_APB1ENR_TIM3EN_Msk
#define RCC_APB1ENR_WWDGEN_Pos               (11U)
#define RCC_APB1ENR_WWDGEN_Msk               (0x1UL << RCC_APB1ENR_WWDGEN_Pos)
#define RCC_APB1ENR_WWDGEN                   RCC_APB1ENR_WWDGEN_Msk
#define RCC_APB1ENR_USART2EN_Pos             (17U)
#define RCC_APB1ENR_USART2EN_Msk             (0x1UL << RCC_APB1ENR_USART2EN_Pos)
#define RCC_APB1ENR_USART2EN                 RCC_APB1ENR_USART2EN_Msk
#define RCC_APB1ENR_I2C1EN_Pos               (21U)
#define RCC_APB1ENR_I2C1EN_Msk               (0x1UL << RCC_APB1ENR_I2C1EN_Pos)
#define RCC_APB1ENR_I2C1EN                   RCC_APB1ENR_I2C1EN_Msk

#define RCC_APB1ENR_CAN1EN_Pos               (25U)
#define RCC_APB1ENR_CAN1EN_Msk               (0x1UL << RCC_APB1ENR_CAN1EN_Pos)
#define RCC_APB1ENR_CAN1EN                   RCC_APB1ENR_CAN1EN_Msk

#define RCC_APB1ENR_BKPEN_Pos                (27U)
#define RCC_APB1ENR_BKPEN_Msk                (0x1UL << RCC_APB1ENR_BKPEN_Pos)
#define RCC_APB1ENR_BKPEN                    RCC_APB1ENR_BKPEN_Msk
#define RCC_APB1ENR_PWREN_Pos                (28U)
#define RCC_APB1ENR_PWREN_Msk                (0x1UL << RCC_APB1ENR_PWREN_Pos)
#define RCC_APB1ENR_PWREN                    RCC_APB1ENR_PWREN_Msk

#define RCC_APB1ENR_TIM4EN_Pos               (2U)
#define RCC_APB1ENR_TIM4EN_Msk               (0x1UL << RCC_APB1ENR_TIM4EN_Pos)
#define RCC_APB1ENR_TIM4EN                   RCC_APB1ENR_TIM4EN_Msk
#define RCC_APB1ENR_SPI2EN_Pos               (14U)
#define RCC_APB1ENR_SPI2EN_Msk               (0x1UL << RCC_APB1ENR_SPI2EN_Pos)
#define RCC_APB1ENR_SPI2EN                   RCC_APB1ENR_SPI2EN_Msk
#define RCC_APB1ENR_USART3EN_Pos             (18U)
#define RCC_APB1ENR_USART3EN_Msk             (0x1UL << RCC_APB1ENR_USART3EN_Pos)
#define RCC_APB1ENR_USART3EN                 RCC_APB1ENR_USART3EN_Msk
#define RCC_APB1ENR_I2C2EN_Pos               (22U)
#define RCC_APB1ENR_I2C2EN_Msk               (0x1UL << RCC_APB1ENR_I2C2EN_Pos)
#define RCC_APB1ENR_I2C2EN                   RCC_APB1ENR_I2C2EN_Msk

#define RCC_APB1ENR_USBEN_Pos                (23U)
#define RCC_APB1ENR_USBEN_Msk                (0x1UL << RCC_APB1ENR_USBEN_Pos)
#define RCC_APB1ENR_USBEN                    RCC_APB1ENR_USBEN_Msk

#define RCC_BDCR_LSEON_Pos                   (0U)
#define RCC_BDCR_LSEON_Msk                   (0x1UL << RCC_BDCR_LSEON_Pos)
#define RCC_BDCR_LSEON                       RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos                  (1U)
#define RCC_BDCR_LSERDY_Msk                  (0x1UL << RCC_BDCR_LSERDY_Pos)
#define RCC_BDCR_LSERDY                      RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos                  (2U)
#define RCC_BDCR_LSEBYP_Msk                  (0x1UL << RCC_BDCR_LSEBYP_Pos)
#define RCC_BDCR_LSEBYP                      RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_RTCSEL_Pos                  (8U)
#define RCC_BDCR_RTCSEL_Msk                  (0x3UL << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL                      RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                    (0x1UL << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL_1                    (0x2UL << RCC_BDCR_RTCSEL_Pos)

#define RCC_BDCR_RTCSEL_NOCLOCK              0x00000000U
#define RCC_BDCR_RTCSEL_LSE                  0x00000100U
#define RCC_BDCR_RTCSEL_LSI                  0x00000200U
#define RCC_BDCR_RTCSEL_HSE                  0x00000300U

#define RCC_BDCR_RTCEN_Pos                   (15U)
#define RCC_BDCR_RTCEN_Msk                   (0x1UL << RCC_BDCR_RTCEN_Pos)
#define RCC_BDCR_RTCEN                       RCC_BDCR_RTCEN_Msk
#define RCC_BDCR_BDRST_Pos                   (16U)
#define RCC_BDCR_BDRST_Msk                   (0x1UL << RCC_BDCR_BDRST_Pos)
#define RCC_BDCR_BDRST                       RCC_BDCR_BDRST_Msk

#define RCC_CSR_LSION_Pos                    (0U)
#define RCC_CSR_LSION_Msk                    (0x1UL << RCC_CSR_LSION_Pos)
#define RCC_CSR_LSION                        RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos                   (1U)
#define RCC_CSR_LSIRDY_Msk                   (0x1UL << RCC_CSR_LSIRDY_Pos)
#define RCC_CSR_LSIRDY                       RCC_CSR_LSIRDY_Msk
#define RCC_CSR_RMVF_Pos                     (24U)
#define RCC_CSR_RMVF_Msk                     (0x1UL << RCC_CSR_RMVF_Pos)
#define RCC_CSR_RMVF                         RCC_CSR_RMVF_Msk
#define RCC_CSR_PINRSTF_Pos                  (26U)
#define RCC_CSR_PINRSTF_Msk                  (0x1UL << RCC_CSR_PINRSTF_Pos)
#define RCC_CSR_PINRSTF                      RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos                  (27U)
#define RCC_CSR_PORRSTF_Msk                  (0x1UL << RCC_CSR_PORRSTF_Pos)
#define RCC_CSR_PORRSTF                      RCC_CSR_PORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                  (28U)
#define RCC_CSR_SFTRSTF_Msk                  (0x1UL << RCC_CSR_SFTRSTF_Pos)
#define RCC_CSR_SFTRSTF                      RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos                 (29U)
#define RCC_CSR_IWDGRSTF_Msk                 (0x1UL << RCC_CSR_IWDGRSTF_Pos)
#define RCC_CSR_IWDGRSTF                     RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos                 (30U)
#define RCC_CSR_WWDGRSTF_Msk                 (0x1UL << RCC_CSR_WWDGRSTF_Pos)
#define RCC_CSR_WWDGRSTF                     RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos                 (31U)
#define RCC_CSR_LPWRRSTF_Msk                 (0x1UL << RCC_CSR_LPWRRSTF_Pos)
#define RCC_CSR_LPWRRSTF                     RCC_CSR_LPWRRSTF_Msk

#define GPIO_CRL_MODE_Pos                    (0U)
#define GPIO_CRL_MODE_Msk                    (0x33333333UL << GPIO_CRL_MODE_Pos)
#define GPIO_CRL_MODE                        GPIO_CRL_MODE_Msk

#define GPIO_CRL_MODE0_Pos                   (0U)
#define GPIO_CRL_MODE0_Msk                   (0x3UL << GPIO_CRL_MODE0_Pos)
#define GPIO_CRL_MODE0                       GPIO_CRL_MODE0_Msk
#define GPIO_CRL_MODE0_0                     (0x1UL << GPIO_CRL_MODE0_Pos)
#define GPIO_CRL_MODE0_1                     (0x2UL << GPIO_CRL_MODE0_Pos)

#define GPIO_CRL_MODE1_Pos                   (4U)
#define GPIO_CRL_MODE1_Msk                   (0x3UL << GPIO_CRL_MODE1_Pos)
#define GPIO_CRL_MODE1                       GPIO_CRL_MODE1_Msk
#define GPIO_CRL_MODE1_0                     (0x1UL << GPIO_CRL_MODE1_Pos)
#define GPIO_CRL_MODE1_1                     (0x2UL << GPIO_CRL_MODE1_Pos)

#define GPIO_CRL_MODE2_Pos                   (8U)
#define GPIO_CRL_MODE2_Msk                   (0x3UL << GPIO_CRL_MODE2_Pos)
#define GPIO_CRL_MODE2                       GPIO_CRL_MODE2_Msk
#define GPIO_CRL_MODE2_0                     (0x1UL << GPIO_CRL_MODE2_Pos)
#define GPIO_CRL_MODE2_1                     (0x2UL << GPIO_CRL_MODE2_Pos)

#define GPIO_CRL_MODE3_Pos                   (12U)
#define GPIO_CRL_MODE3_Msk                   (0x3UL << GPIO_CRL_MODE3_Pos)
#define GPIO_CRL_MODE3                       GPIO_CRL_MODE3_Msk
#define GPIO_CRL_MODE3_0                     (0x1UL << GPIO_CRL_MODE3_Pos)
#define GPIO_CRL_MODE3_1                     (0x2UL << GPIO_CRL_MODE3_Pos)

#define GPIO_CRL_MODE4_Pos                   (16U)
#define GPIO_CRL_MODE4_Msk                   (0x3UL << GPIO_CRL_MODE4_Pos)
#define GPIO_CRL_MODE4                       GPIO_CRL_MODE4_Msk
#define GPIO_CRL_MODE4_0                     (0x1UL << GPIO_CRL_MODE4_Pos)
#define GPIO_CRL_MODE4_1                     (0x2UL << GPIO_CRL_MODE4_Pos)

#define GPIO_CRL_MODE5_Pos                   (20U)
#define GPIO_CRL_MODE5_Msk                   (0x3UL << GPIO_CRL_MODE5_Pos)
#define GPIO_CRL_MODE5                       GPIO_CRL_MODE5_Msk
#define GPIO_CRL_MODE5_0                     (0x1UL << GPIO_CRL_MODE5_Pos)
#define GPIO_CRL_MODE5_1                     (0x2UL << GPIO_CRL_MODE5_Pos)

#define GPIO_CRL_MODE6_Pos                   (24U)
#define GPIO_CRL_MODE6_Msk                   (0x3UL << GPIO_CRL_MODE6_Pos)
#define GPIO_CRL_MODE6                       GPIO_CRL_MODE6_Msk
#define GPIO_CRL_MODE6_0                     (0x1UL << GPIO_CRL_MODE6_Pos)
#define GPIO_CRL_MODE6_1                     (0x2UL << GPIO_CRL_MODE6_Pos)

#define GPIO_CRL_MODE7_Pos                   (28U)
#define GPIO_CRL_MODE7_Msk                   (0x3UL << GPIO_CRL_MODE7_Pos)
#define GPIO_CRL_MODE7                       GPIO_CRL_MODE7_Msk
#define GPIO_CRL_MODE7_0                     (0x1UL << GPIO_CRL_MODE7_Pos)
#define GPIO_CRL_MODE7_1                     (0x2UL << GPIO_CRL_MODE7_Pos)

#define GPIO_CRL_CNF_Pos                     (2U)
#define GPIO_CRL_CNF_Msk                     (0x33333333UL << GPIO_CRL_CNF_Pos)
#define GPIO_CRL_CNF                         GPIO_CRL_CNF_Msk

#define GPIO_CRL_CNF0_Pos                    (2U)
#define GPIO_CRL_CNF0_Msk                    (0x3UL << GPIO_CRL_CNF0_Pos)
#define GPIO_CRL_CNF0                        GPIO_CRL_CNF0_Msk
#define GPIO_CRL_CNF0_0                      (0x1UL << GPIO_CRL_CNF0_Pos)
#define GPIO_CRL_CNF0_1                      (0x2UL << GPIO_CRL_CNF0_Pos)

#define GPIO_CRL_CNF1_Pos                    (6U)
#define GPIO_CRL_CNF1_Msk                    (0x3UL << GPIO_CRL_CNF1_Pos)
#define GPIO_CRL_CNF1                        GPIO_CRL_CNF1_Msk
#define GPIO_CRL_CNF1_0                      (0x1UL << GPIO_CRL_CNF1_Pos)
#define GPIO_CRL_CNF1_1                      (0x2UL << GPIO_CRL_CNF1_Pos)

#define GPIO_CRL_CNF2_Pos                    (10U)
#define GPIO_CRL_CNF2_Msk                    (0x3UL << GPIO_CRL_CNF2_Pos)
#define GPIO_CRL_CNF2                        GPIO_CRL_CNF2_Msk
#define GPIO_CRL_CNF2_0                      (0x1UL << GPIO_CRL_CNF2_Pos)
#define GPIO_CRL_CNF2_1                      (0x2UL << GPIO_CRL_CNF2_Pos)

#define GPIO_CRL_CNF3_Pos                    (14U)
#define GPIO_CRL_CNF3_Msk                    (0x3UL << GPIO_CRL_CNF3_Pos)
#define GPIO_CRL_CNF3                        GPIO_CRL_CNF3_Msk
#define GPIO_CRL_CNF3_0                      (0x1UL << GPIO_CRL_CNF3_Pos)
#define GPIO_CRL_CNF3_1                      (0x2UL << GPIO_CRL_CNF3_Pos)

#define GPIO_CRL_CNF4_Pos                    (18U)
#define GPIO_CRL_CNF4_Msk                    (0x3UL << GPIO_CRL_CNF4_Pos)
#define GPIO_CRL_CNF4                        GPIO_CRL_CNF4_Msk
#define GPIO_CRL_CNF4_0                      (0x1UL << GPIO_CRL_CNF4_Pos)
#define GPIO_CRL_CNF4_1                      (0x2UL << GPIO_CRL_CNF4_Pos)

#define GPIO_CRL_CNF5_Pos                    (22U)
#define GPIO_CRL_CNF5_Msk                    (0x3UL << GPIO_CRL_CNF5_Pos)
#define GPIO_CRL_CNF5                        GPIO_CRL_CNF5_Msk
#define GPIO_CRL_CNF5_0                      (0x1UL << GPIO_CRL_CNF5_Pos)
#define GPIO_CRL_CNF5_1                      (0x2UL << GPIO_CRL_CNF5_Pos)

#define GPIO_CRL_CNF6_Pos                    (26U)
#define GPIO_CRL_CNF6_Msk                    (0x3UL << GPIO_CRL_CNF6_Pos)
#define GPIO_CRL_CNF6                        GPIO_CRL_CNF6_Msk
#define GPIO_CRL_CNF6_0                      (0x1UL << GPIO_CRL_CNF6_Pos)
#define GPIO_CRL_CNF6_1                      (0x2UL << GPIO_CRL_CNF6_Pos)

#define GPIO_CRL_CNF7_Pos                    (30U)
#define GPIO_CRL_CNF7_Msk                    (0x3UL << GPIO_CRL_CNF7_Pos)
#define GPIO_CRL_CNF7                        GPIO_CRL_CNF7_Msk
#define GPIO_CRL_CNF7_0                      (0x1UL << GPIO_CRL_CNF7_Pos)
#define GPIO_CRL_CNF7_1                      (0x2UL << GPIO_CRL_CNF7_Pos)

#define GPIO_CRH_MODE_Pos                    (0U)
#define GPIO_CRH_MODE_Msk                    (0x33333333UL << GPIO_CRH_MODE_Pos)
#define GPIO_CRH_MODE                        GPIO_CRH_MODE_Msk

#define GPIO_CRH_MODE8_Pos                   (0U)
#define GPIO_CRH_MODE8_Msk                   (0x3UL << GPIO_CRH_MODE8_Pos)
#define GPIO_CRH_MODE8                       GPIO_CRH_MODE8_Msk
#define GPIO_CRH_MODE8_0                     (0x1UL << GPIO_CRH_MODE8_Pos)
#define GPIO_CRH_MODE8_1                     (0x2UL << GPIO_CRH_MODE8_Pos)

#define GPIO_CRH_MODE9_Pos                   (4U)
#define GPIO_CRH_MODE9_Msk                   (0x3UL << GPIO_CRH_MODE9_Pos)
#define GPIO_CRH_MODE9                       GPIO_CRH_MODE9_Msk
#define GPIO_CRH_MODE9_0                     (0x1UL << GPIO_CRH_MODE9_Pos)
#define GPIO_CRH_MODE9_1                     (0x2UL << GPIO_CRH_MODE9_Pos)

#define GPIO_CRH_MODE10_Pos                  (8U)
#define GPIO_CRH_MODE10_Msk                  (0x3UL << GPIO_CRH_MODE10_Pos)
#define GPIO_CRH_MODE10                      GPIO_CRH_MODE10_Msk
#define GPIO_CRH_MODE10_0                    (0x1UL << GPIO_CRH_MODE10_Pos)
#define GPIO_CRH_MODE10_1                    (0x2UL << GPIO_CRH_MODE10_Pos)

#define GPIO_CRH_MODE11_Pos                  (12U)
#define GPIO_CRH_MODE11_Msk                  (0x3UL << GPIO_CRH_MODE11_Pos)
#define GPIO_CRH_MODE11                      GPIO_CRH_MODE11_Msk
#define GPIO_CRH_MODE11_0                    (0x1UL << GPIO_CRH_MODE11_Pos)
#define GPIO_CRH_MODE11_1                    (0x2UL << GPIO_CRH_MODE11_Pos)

#define GPIO_CRH_MODE12_Pos                  (16U)
#define GPIO_CRH_MODE12_Msk                  (0x3UL << GPIO_CRH_MODE12_Pos)
#define GPIO_CRH_MODE12                      GPIO_CRH_MODE12_Msk
#define GPIO_CRH_MODE12_0                    (0x1UL << GPIO_CRH_MODE12_Pos)
#define GPIO_CRH_MODE12_1                    (0x2UL << GPIO_CRH_MODE12_Pos)

#define GPIO_CRH_MODE13_Pos                  (20U)
#define GPIO_CRH_MODE13_Msk                  (0x3UL << GPIO_CRH_MODE13_Pos)
#define GPIO_CRH_MODE13                      GPIO_CRH_MODE13_Msk
#define GPIO_CRH_MODE13_0                    (0x1UL << GPIO_CRH_MODE13_Pos)
#define GPIO_CRH_MODE13_1                    (0x2UL << GPIO_CRH_MODE13_Pos)

#define GPIO_CRH_MODE14_Pos                  (24U)
#define GPIO_CRH_MODE14_Msk                  (0x3UL << GPIO_CRH_MODE14_Pos)
#define GPIO_CRH_MODE14                      GPIO_CRH_MODE14_Msk
#define GPIO_CRH_MODE14_0                    (0x1UL << GPIO_CRH_MODE14_Pos)
#define GPIO_CRH_MODE14_1                    (0x2UL << GPIO_CRH_MODE14_Pos)

#define GPIO_CRH_MODE15_Pos                  (28U)
#define GPIO_CRH_MODE15_Msk                  (0x3UL << GPIO_CRH_MODE15_Pos)
#define GPIO_CRH_MODE15                      GPIO_CRH_MODE15_Msk
#define GPIO_CRH_MODE15_0                    (0x1UL << GPIO_CRH_MODE15_Pos)
#define GPIO_CRH_MODE15_1                    (0x2UL << GPIO_CRH_MODE15_Pos)

#define GPIO_CRH_CNF_Pos                     (2U)
#define GPIO_CRH_CNF_Msk                     (0x33333333UL << GPIO_CRH_CNF_Pos)
#define GPIO_CRH_CNF                         GPIO_CRH_CNF_Msk

#define GPIO_CRH_CNF8_Pos                    (2U)
#define GPIO_CRH_CNF8_Msk                    (0x3UL << GPIO_CRH_CNF8_Pos)
#define GPIO_CRH_CNF8                        GPIO_CRH_CNF8_Msk
#define GPIO_CRH_CNF8_0                      (0x1UL << GPIO_CRH_CNF8_Pos)
#define GPIO_CRH_CNF8_1                      (0x2UL << GPIO_CRH_CNF8_Pos)

#define GPIO_CRH_CNF9_Pos                    (6U)
#define GPIO_CRH_CNF9_Msk                    (0x3UL << GPIO_CRH_CNF9_Pos)
#define GPIO_CRH_CNF9                        GPIO_CRH_CNF9_Msk
#define GPIO_CRH_CNF9_0                      (0x1UL << GPIO_CRH_CNF9_Pos)
#define GPIO_CRH_CNF9_1                      (0x2UL << GPIO_CRH_CNF9_Pos)

#define GPIO_CRH_CNF10_Pos                   (10U)
#define GPIO_CRH_CNF10_Msk                   (0x3UL << GPIO_CRH_CNF10_Pos)
#define GPIO_CRH_CNF10                       GPIO_CRH_CNF10_Msk
#define GPIO_CRH_CNF10_0                     (0x1UL << GPIO_CRH_CNF10_Pos)
#define GPIO_CRH_CNF10_1                     (0x2UL << GPIO_CRH_CNF10_Pos)

#define GPIO_CRH_CNF11_Pos                   (14U)
#define GPIO_CRH_CNF11_Msk                   (0x3UL << GPIO_CRH_CNF11_Pos)
#define GPIO_CRH_CNF11                       GPIO_CRH_CNF11_Msk
#define GPIO_CRH_CNF11_0                     (0x1UL << GPIO_CRH_CNF11_Pos)
#define GPIO_CRH_CNF11_1                     (0x2UL << GPIO_CRH_CNF11_Pos)

#define GPIO_CRH_CNF12_Pos                   (18U)
#define GPIO_CRH_CNF12_Msk                   (0x3UL << GPIO_CRH_CNF12_Pos)
#define GPIO_CRH_CNF12                       GPIO_CRH_CNF12_Msk
#define GPIO_CRH_CNF12_0                     (0x1UL << GPIO_CRH_CNF12_Pos)
#define GPIO_CRH_CNF12_1                     (0x2UL << GPIO_CRH_CNF12_Pos)

#define GPIO_CRH_CNF13_Pos                   (22U)
#define GPIO_CRH_CNF13_Msk                   (0x3UL << GPIO_CRH_CNF13_Pos)
#define GPIO_CRH_CNF13                       GPIO_CRH_CNF13_Msk
#define GPIO_CRH_CNF13_0                     (0x1UL << GPIO_CRH_CNF13_Pos)
#define GPIO_CRH_CNF13_1                     (0x2UL << GPIO_CRH_CNF13_Pos)

#define GPIO_CRH_CNF14_Pos                   (26U)
#define GPIO_CRH_CNF14_Msk                   (0x3UL << GPIO_CRH_CNF14_Pos)
#define GPIO_CRH_CNF14                       GPIO_CRH_CNF14_Msk
#define GPIO_CRH_CNF14_0                     (0x1UL << GPIO_CRH_CNF14_Pos)
#define GPIO_CRH_CNF14_1                     (0x2UL << GPIO_CRH_CNF14_Pos)

#define GPIO_CRH_CNF15_Pos                   (30U)
#define GPIO_CRH_CNF15_Msk                   (0x3UL << GPIO_CRH_CNF15_Pos)
#define GPIO_CRH_CNF15                       GPIO_CRH_CNF15_Msk
#define GPIO_CRH_CNF15_0                     (0x1UL << GPIO_CRH_CNF15_Pos)
#define GPIO_CRH_CNF15_1                     (0x2UL << GPIO_CRH_CNF15_Pos)

#define GPIO_IDR_IDR0_Pos                    (0U)
#define GPIO_IDR_IDR0_Msk                    (0x1UL << GPIO_IDR_IDR0_Pos)
#define GPIO_IDR_IDR0                        GPIO_IDR_IDR0_Msk
#define GPIO_IDR_IDR1_Pos                    (1U)
#define GPIO_IDR_IDR1_Msk                    (0x1UL << GPIO_IDR_IDR1_Pos)
#define GPIO_IDR_IDR1                        GPIO_IDR_IDR1_Msk
#define GPIO_IDR_IDR2_Pos                    (2U)
#define GPIO_IDR_IDR2_Msk                    (0x1UL << GPIO_IDR_IDR2_Pos)
#define GPIO_IDR_IDR2                        GPIO_IDR_IDR2_Msk
#define GPIO_IDR_IDR3_Pos                    (3U)
#define GPIO_IDR_IDR3_Msk                    (0x1UL << GPIO_IDR_IDR3_Pos)
#define GPIO_IDR_IDR3                        GPIO_IDR_IDR3_Msk
#define GPIO_IDR_IDR4_Pos                    (4U)
#define GPIO_IDR_IDR4_Msk                    (0x1UL << GPIO_IDR_IDR4_Pos)
#define GPIO_IDR_IDR4                        GPIO_IDR_IDR4_Msk
#define GPIO_IDR_IDR5_Pos                    (5U)
#define GPIO_IDR_IDR5_Msk                    (0x1UL << GPIO_IDR_IDR5_Pos)
#define GPIO_IDR_IDR5                        GPIO_IDR_IDR5_Msk
#define GPIO_IDR_IDR6_Pos                    (6U)
#define GPIO_IDR_IDR6_Msk                    (0x1UL << GPIO_IDR_IDR6_Pos)
#define GPIO_IDR_IDR6                        GPIO_IDR_IDR6_Msk
#define GPIO_IDR_IDR7_Pos                    (7U)
#define GPIO_IDR_IDR7_Msk                    (0x1UL << GPIO_IDR_IDR7_Pos)
#define GPIO_IDR_IDR7                        GPIO_IDR_IDR7_Msk
#define GPIO_IDR_IDR8_Pos                    (8U)
#define GPIO_IDR_IDR8_Msk                    (0x1UL << GPIO_IDR_IDR8_Pos)
#define GPIO_IDR_IDR8                        GPIO_IDR_IDR8_Msk
#define GPIO_IDR_IDR9_Pos                    (9U)
#define GPIO_IDR_IDR9_Msk                    (0x1UL << GPIO_IDR_IDR9_Pos)
#define GPIO_IDR_IDR9                        GPIO_IDR_IDR9_Msk
#define GPIO_IDR_IDR10_Pos                   (10U)
#define GPIO_IDR_IDR10_Msk                   (0x1UL << GPIO_IDR_IDR10_Pos)
#define GPIO_IDR_IDR10                       GPIO_IDR_IDR10_Msk
#define GPIO_IDR_IDR11_Pos                   (11U)
#define GPIO_IDR_IDR11_Msk                   (0x1UL << GPIO_IDR_IDR11_Pos)
#define GPIO_IDR_IDR11                       GPIO_IDR_IDR11_Msk
#define GPIO_IDR_IDR12_Pos                   (12U)
#define GPIO_IDR_IDR12_Msk                   (0x1UL << GPIO_IDR_IDR12_Pos)
#define GPIO_IDR_IDR12                       GPIO_IDR_IDR12_Msk
#define GPIO_IDR_IDR13_Pos                   (13U)
#define GPIO_IDR_IDR13_Msk                   (0x1UL << GPIO_IDR_IDR13_Pos)
#define GPIO_IDR_IDR13                       GPIO_IDR_IDR13_Msk
#define GPIO_IDR_IDR14_Pos                   (14U)
#define GPIO_IDR_IDR14_Msk                   (0x1UL << GPIO_IDR_IDR14_Pos)
#define GPIO_IDR_IDR14                       GPIO_IDR_IDR14_Msk
#define GPIO_IDR_IDR15_Pos                   (15U)
#define GPIO_IDR_IDR15_Msk                   (0x1UL << GPIO_IDR_IDR15_Pos)
#define GPIO_IDR_IDR15                       GPIO_IDR_IDR15_Msk

#define GPIO_ODR_ODR0_Pos                    (0U)
#define GPIO_ODR_ODR0_Msk                    (0x1UL << GPIO_ODR_ODR0_Pos)
#define GPIO_ODR_ODR0                        GPIO_ODR_ODR0_Msk
#define GPIO_ODR_ODR1_Pos                    (1U)
#define GPIO_ODR_ODR1_Msk                    (0x1UL << GPIO_ODR_ODR1_Pos)
#define GPIO_ODR_ODR1                        GPIO_ODR_ODR1_Msk
#define GPIO_ODR_ODR2_Pos                    (2U)
#define GPIO_ODR_ODR2_Msk                    (0x1UL << GPIO_ODR_ODR2_Pos)
#define GPIO_ODR_ODR2                        GPIO_ODR_ODR2_Msk
#define GPIO_ODR_ODR3_Pos                    (3U)
#define GPIO_ODR_ODR3_Msk                    (0x1UL << GPIO_ODR_ODR3_Pos)
#define GPIO_ODR_ODR3                        GPIO_ODR_ODR3_Msk
#define GPIO_ODR_ODR4_Pos                    (4U)
#define GPIO_ODR_ODR4_Msk                    (0x1UL << GPIO_ODR_ODR4_Pos)
#define GPIO_ODR_ODR4                        GPIO_ODR_ODR4_Msk
#define GPIO_ODR_ODR5_Pos                    (5U)
#define GPIO_ODR_ODR5_Msk                    (0x1UL << GPIO_ODR_ODR5_Pos)
#define GPIO_ODR_ODR5                        GPIO_ODR_ODR5_Msk
#define GPIO_ODR_ODR6_Pos                    (6U)
#define GPIO_ODR_ODR6_Msk                    (0x1UL << GPIO_ODR_ODR6_Pos)
#define GPIO_ODR_ODR6                        GPIO_ODR_ODR6_Msk
#define GPIO_ODR_ODR7_Pos                    (7U)
#define GPIO_ODR_ODR7_Msk                    (0x1UL << GPIO_ODR_ODR7_Pos)
#define GPIO_ODR_ODR7                        GPIO_ODR_ODR7_Msk
#define GPIO_ODR_ODR8_Pos                    (8U)
#define GPIO_ODR_ODR8_Msk                    (0x1UL << GPIO_ODR_ODR8_Pos)
#define GPIO_ODR_ODR8                        GPIO_ODR_ODR8_Msk
#define GPIO_ODR_ODR9_Pos                    (9U)
#define GPIO_ODR_ODR9_Msk                    (0x1UL << GPIO_ODR_ODR9_Pos)
#define GPIO_ODR_ODR9                        GPIO_ODR_ODR9_Msk
#define GPIO_ODR_ODR10_Pos                   (10U)
#define GPIO_ODR_ODR10_Msk                   (0x1UL << GPIO_ODR_ODR10_Pos)
#define GPIO_ODR_ODR10                       GPIO_ODR_ODR10_Msk
#define GPIO_ODR_ODR11_Pos                   (11U)
#define GPIO_ODR_ODR11_Msk                   (0x1UL << GPIO_ODR_ODR11_Pos)
#define GPIO_ODR_ODR11                       GPIO_ODR_ODR11_Msk
#define GPIO_ODR_ODR12_Pos                   (12U)
#define GPIO_ODR_ODR12_Msk                   (0x1UL << GPIO_ODR_ODR12_Pos)
#define GPIO_ODR_ODR12                       GPIO_ODR_ODR12_Msk
#define GPIO_ODR_ODR13_Pos                   (13U)
#define GPIO_ODR_ODR13_Msk                   (0x1UL << GPIO_ODR_ODR13_Pos)
#define GPIO_ODR_ODR13                       GPIO_ODR_ODR13_Msk
#define GPIO_ODR_ODR14_Pos                   (14U)
#define GPIO_ODR_ODR14_Msk                   (0x1UL << GPIO_ODR_ODR14_Pos)
#define GPIO_ODR_ODR14                       GPIO_ODR_ODR14_Msk
#define GPIO_ODR_ODR15_Pos                   (15U)
#define GPIO_ODR_ODR15_Msk                   (0x1UL << GPIO_ODR_ODR15_Pos)
#define GPIO_ODR_ODR15                       GPIO_ODR_ODR15_Msk

#define GPIO_BSRR_BS0_Pos                    (0U)
#define GPIO_BSRR_BS0_Msk                    (0x1UL << GPIO_BSRR_BS0_Pos)
#define GPIO_BSRR_BS0                        GPIO_BSRR_BS0_Msk
#define GPIO_BSRR_BS1_Pos                    (1U)
#define GPIO_BSRR_BS1_Msk                    (0x1UL << GPIO_BSRR_BS1_Pos)
#define GPIO_BSRR_BS1                        GPIO_BSRR_BS1_Msk
#define GPIO_BSRR_BS2_Pos                    (2U)
#define GPIO_BSRR_BS2_Msk                    (0x1UL << GPIO_BSRR_BS2_Pos)
#define GPIO_BSRR_BS2                        GPIO_BSRR_BS2_Msk
#define GPIO_BSRR_BS3_Pos                    (3U)
#define GPIO_BSRR_BS3_Msk                    (0x1UL << GPIO_BSRR_BS3_Pos)
#define GPIO_BSRR_BS3                        GPIO_BSRR_BS3_Msk
#define GPIO_BSRR_BS4_Pos                    (4U)
#define GPIO_BSRR_BS4_Msk                    (0x1UL << GPIO_BSRR_BS4_Pos)
#define GPIO_BSRR_BS4                        GPIO_BSRR_BS4_Msk
#define GPIO_BSRR_BS5_Pos                    (5U)
#define GPIO_BSRR_BS5_Msk                    (0x1UL << GPIO_BSRR_BS5_Pos)
#define GPIO_BSRR_BS5                        GPIO_BSRR_BS5_Msk
#define GPIO_BSRR_BS6_Pos                    (6U)
#define GPIO_BSRR_BS6_Msk                    (0x1UL << GPIO_BSRR_BS6_Pos)
#define GPIO_BSRR_BS6                        GPIO_BSRR_BS6_Msk
#define GPIO_BSRR_BS7_Pos                    (7U)
#define GPIO_BSRR_BS7_Msk                    (0x1UL << GPIO_BSRR_BS7_Pos)
#define GPIO_BSRR_BS7                        GPIO_BSRR_BS7_Msk
#define GPIO_BSRR_BS8_Pos                    (8U)
#define GPIO_BSRR_BS8_Msk                    (0x1UL << GPIO_BSRR_BS8_Pos)
#define GPIO_BSRR_BS8                        GPIO_BSRR_BS8_Msk
#define GPIO_BSRR_BS9_Pos                    (9U)
#define GPIO_BSRR_BS9_Msk                    (0x1UL << GPIO_BSRR_BS9_Pos)
#define GPIO_BSRR_BS9                        GPIO_BSRR_BS9_Msk
#define GPIO_BSRR_BS10_Pos                   (10U)
#define GPIO_BSRR_BS10_Msk                   (0x1UL << GPIO_BSRR_BS10_Pos)
#define GPIO_BSRR_BS10                       GPIO_BSRR_BS10_Msk
#define GPIO_BSRR_BS11_Pos                   (11U)
#define GPIO_BSRR_BS11_Msk                   (0x1UL << GPIO_BSRR_BS11_Pos)
#define GPIO_BSRR_BS11                       GPIO_BSRR_BS11_Msk
#define GPIO_BSRR_BS12_Pos                   (12U)
#define GPIO_BSRR_BS12_Msk                   (0x1UL << GPIO_BSRR_BS12_Pos)
#define GPIO_BSRR_BS12                       GPIO_BSRR_BS12_Msk
#define GPIO_BSRR_BS13_Pos                   (13U)
#define GPIO_BSRR_BS13_Msk                   (0x1UL << GPIO_BSRR_BS13_Pos)
#define GPIO_BSRR_BS13                       GPIO_BSRR_BS13_Msk
#define GPIO_BSRR_BS14_Pos                   (14U)
#define GPIO_BSRR_BS14_Msk                   (0x1UL << GPIO_BSRR_BS14_Pos)
#define GPIO_BSRR_BS14                       GPIO_BSRR_BS14_Msk
#define GPIO_BSRR_BS15_Pos                   (15U)
#define GPIO_BSRR_BS15_Msk                   (0x1UL << GPIO_BSRR_BS15_Pos)
#define GPIO_BSRR_BS15                       GPIO_BSRR_BS15_Msk

#define GPIO_BSRR_BR0_Pos                    (16U)
#define GPIO_BSRR_BR0_Msk                    (0x1UL << GPIO_BSRR_BR0_Pos)
#define GPIO_BSRR_BR0                        GPIO_BSRR_BR0_Msk
#define GPIO_BSRR_BR1_Pos                    (17U)
#define GPIO_BSRR_BR1_Msk                    (0x1UL << GPIO_BSRR_BR1_Pos)
#define GPIO_BSRR_BR1                        GPIO_BSRR_BR1_Msk
#define GPIO_BSRR_BR2_Pos                    (18U)
#define GPIO_BSRR_BR2_Msk                    (0x1UL << GPIO_BSRR_BR2_Pos)
#define GPIO_BSRR_BR2                        GPIO_BSRR_BR2_Msk
#define GPIO_BSRR_BR3_Pos                    (19U)
#define GPIO_BSRR_BR3_Msk                    (0x1UL << GPIO_BSRR_BR3_Pos)
#define GPIO_BSRR_BR3                        GPIO_BSRR_BR3_Msk
#define GPIO_BSRR_BR4_Pos                    (20U)
#define GPIO_BSRR_BR4_Msk                    (0x1UL << GPIO_BSRR_BR4_Pos)
#define GPIO_BSRR_BR4                        GPIO_BSRR_BR4_Msk
#define GPIO_BSRR_BR5_Pos                    (21U)
#define GPIO_BSRR_BR5_Msk                    (0x1UL << GPIO_BSRR_BR5_Pos)
#define GPIO_BSRR_BR5                        GPIO_BSRR_BR5_Msk
#define GPIO_BSRR_BR6_Pos                    (22U)
#define GPIO_BSRR_BR6_Msk                    (0x1UL << GPIO_BSRR_BR6_Pos)
#define GPIO_BSRR_BR6                        GPIO_BSRR_BR6_Msk
#define GPIO_BSRR_BR7_Pos                    (23U)
#define GPIO_BSRR_BR7_Msk                    (0x1UL << GPIO_BSRR_BR7_Pos)
#define GPIO_BSRR_BR7                        GPIO_BSRR_BR7_Msk
#define GPIO_BSRR_BR8_Pos                    (24U)
#define GPIO_BSRR_BR8_Msk                    (0x1UL << GPIO_BSRR_BR8_Pos)
#define GPIO_BSRR_BR8                        GPIO_BSRR_BR8_Msk
#define GPIO_BSRR_BR9_Pos                    (25U)
#define GPIO_BSRR_BR9_Msk                    (0x1UL << GPIO_BSRR_BR9_Pos)
#define GPIO_BSRR_BR9                        GPIO_BSRR_BR9_Msk
#define GPIO_BSRR_BR10_Pos                   (26U)
#define GPIO_BSRR_BR10_Msk                   (0x1UL << GPIO_BSRR_BR10_Pos)
#define GPIO_BSRR_BR10                       GPIO_BSRR_BR10_Msk
#define GPIO_BSRR_BR11_Pos                   (27U)
#define GPIO_BSRR_BR11_Msk                   (0x1UL << GPIO_BSRR_BR11_Pos)
#define GPIO_BSRR_BR11                       GPIO_BSRR_BR11_Msk
#define GPIO_BSRR_BR12_Pos                   (28U)
#define GPIO_BSRR_BR12_Msk                   (0x1UL << GPIO_BSRR_BR12_Pos)
#define GPIO_BSRR_BR12                       GPIO_BSRR_BR12_Msk
#define GPIO_BSRR_BR13_Pos                   (29U)
#define GPIO_BSRR_BR13_Msk                   (0x1UL << GPIO_BSRR_BR13_Pos)
#define GPIO_BSRR_BR13                       GPIO_BSRR_BR13_Msk
#define GPIO_BSRR_BR14_Pos                   (30U)
#define GPIO_BSRR_BR14_Msk                   (0x1UL << GPIO_BSRR_BR14_Pos)
#define GPIO_BSRR_BR14                       GPIO_BSRR_BR14_Msk
#define GPIO_BSRR_BR15_Pos                   (31U)
#define GPIO_BSRR_BR15_Msk                   (0x1UL << GPIO_BSRR_BR15_Pos)
#define GPIO_BSRR_BR15                       GPIO_BSRR_BR15_Msk

#define GPIO_BRR_BR0_Pos                     (0U)
#define GPIO_BRR_BR0_Msk                     (0x1UL << GPIO_BRR_BR0_Pos)
#define GPIO_BRR_BR0                         GPIO_BRR_BR0_Msk
#define GPIO_BRR_BR1_Pos                     (1U)
#define GPIO_BRR_BR1_Msk                     (0x1UL << GPIO_BRR_BR1_Pos)
#define GPIO_BRR_BR1                         GPIO_BRR_BR1_Msk
#define GPIO_BRR_BR2_Pos                     (2U)
#define GPIO_BRR_BR2_Msk                     (0x1UL << GPIO_BRR_BR2_Pos)
#define GPIO_BRR_BR2                         GPIO_BRR_BR2_Msk
#define GPIO_BRR_BR3_Pos                     (3U)
#define GPIO_BRR_BR3_Msk                     (0x1UL << GPIO_BRR_BR3_Pos)
#define GPIO_BRR_BR3                         GPIO_BRR_BR3_Msk
#define GPIO_BRR_BR4_Pos                     (4U)
#define GPIO_BRR_BR4_Msk                     (0x1UL << GPIO_BRR_BR4_Pos)
#define GPIO_BRR_BR4                         GPIO_BRR_BR4_Msk
#define GPIO_BRR_BR5_Pos                     (5U)
#define GPIO_BRR_BR5_Msk                     (0x1UL << GPIO_BRR_BR5_Pos)
#define GPIO_BRR_BR5                         GPIO_BRR_BR5_Msk
#define GPIO_BRR_BR6_Pos                     (6U)
#define GPIO_BRR_BR6_Msk                     (0x1UL << GPIO_BRR_BR6_Pos)
#define GPIO_BRR_BR6                         GPIO_BRR_BR6_Msk
#define GPIO_BRR_BR7_Pos                     (7U)
#define GPIO_BRR_BR7_Msk                     (0x1UL << GPIO_BRR_BR7_Pos)
#define GPIO_BRR_BR7                         GPIO_BRR_BR7_Msk
#define GPIO_BRR_BR8_Pos                     (8U)
#define GPIO_BRR_BR8_Msk                     (0x1UL << GPIO_BRR_BR8_Pos)
#define GPIO_BRR_BR8                         GPIO_BRR_BR8_Msk
#define GPIO_BRR_BR9_Pos                     (9U)
#define GPIO_BRR_BR9_Msk                     (0x1UL << GPIO_BRR_BR9_Pos)
#define GPIO_BRR_BR9                         GPIO_BRR_BR9_Msk
#define GPIO_BRR_BR10_Pos                    (10U)
#define GPIO_BRR_BR10_Msk                    (0x1UL << GPIO_BRR_BR10_Pos)
#define GPIO_BRR_BR10                        GPIO_BRR_BR10_Msk
#define GPIO_BRR_BR11_Pos                    (11U)
#define GPIO_BRR_BR11_Msk                    (0x1UL << GPIO_BRR_BR11_Pos)
#define GPIO_BRR_BR11                        GPIO_BRR_BR11_Msk
#define GPIO_BRR_BR12_Pos                    (12U)
#define GPIO_BRR_BR12_Msk                    (0x1UL << GPIO_BRR_BR12_Pos)
#define GPIO_BRR_BR12                        GPIO_BRR_BR12_Msk
#define GPIO_BRR_BR13_Pos                    (13U)
#define GPIO_BRR_BR13_Msk                    (0x1UL << GPIO_BRR_BR13_Pos)
#define GPIO_BRR_BR13                        GPIO_BRR_BR13_Msk
#define GPIO_BRR_BR14_Pos                    (14U)
#define GPIO_BRR_BR14_Msk                    (0x1UL << GPIO_BRR_BR14_Pos)
#define GPIO_BRR_BR14                        GPIO_BRR_BR14_Msk
#define GPIO_BRR_BR15_Pos                    (15U)
#define GPIO_BRR_BR15_Msk                    (0x1UL << GPIO_BRR_BR15_Pos)
#define GPIO_BRR_BR15                        GPIO_BRR_BR15_Msk

#define GPIO_LCKR_LCK0_Pos                   (0U)
#define GPIO_LCKR_LCK0_Msk                   (0x1UL << GPIO_LCKR_LCK0_Pos)
#define GPIO_LCKR_LCK0                       GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos                   (1U)
#define GPIO_LCKR_LCK1_Msk                   (0x1UL << GPIO_LCKR_LCK1_Pos)
#define GPIO_LCKR_LCK1                       GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos                   (2U)
#define GPIO_LCKR_LCK2_Msk                   (0x1UL << GPIO_LCKR_LCK2_Pos)
#define GPIO_LCKR_LCK2                       GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos                   (3U)
#define GPIO_LCKR_LCK3_Msk                   (0x1UL << GPIO_LCKR_LCK3_Pos)
#define GPIO_LCKR_LCK3                       GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos                   (4U)
#define GPIO_LCKR_LCK4_Msk                   (0x1UL << GPIO_LCKR_LCK4_Pos)
#define GPIO_LCKR_LCK4                       GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos                   (5U)
#define GPIO_LCKR_LCK5_Msk                   (0x1UL << GPIO_LCKR_LCK5_Pos)
#define GPIO_LCKR_LCK5                       GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos                   (6U)
#define GPIO_LCKR_LCK6_Msk                   (0x1UL << GPIO_LCKR_LCK6_Pos)
#define GPIO_LCKR_LCK6                       GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos                   (7U)
#define GPIO_LCKR_LCK7_Msk                   (0x1UL << GPIO_LCKR_LCK7_Pos)
#define GPIO_LCKR_LCK7                       GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos                   (8U)
#define GPIO_LCKR_LCK8_Msk                   (0x1UL << GPIO_LCKR_LCK8_Pos)
#define GPIO_LCKR_LCK8                       GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos                   (9U)
#define GPIO_LCKR_LCK9_Msk                   (0x1UL << GPIO_LCKR_LCK9_Pos)
#define GPIO_LCKR_LCK9                       GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos                  (10U)
#define GPIO_LCKR_LCK10_Msk                  (0x1UL << GPIO_LCKR_LCK10_Pos)
#define GPIO_LCKR_LCK10                      GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos                  (11U)
#define GPIO_LCKR_LCK11_Msk                  (0x1UL << GPIO_LCKR_LCK11_Pos)
#define GPIO_LCKR_LCK11                      GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos                  (12U)
#define GPIO_LCKR_LCK12_Msk                  (0x1UL << GPIO_LCKR_LCK12_Pos)
#define GPIO_LCKR_LCK12                      GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos                  (13U)
#define GPIO_LCKR_LCK13_Msk                  (0x1UL << GPIO_LCKR_LCK13_Pos)
#define GPIO_LCKR_LCK13                      GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos                  (14U)
#define GPIO_LCKR_LCK14_Msk                  (0x1UL << GPIO_LCKR_LCK14_Pos)
#define GPIO_LCKR_LCK14                      GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos                  (15U)
#define GPIO_LCKR_LCK15_Msk                  (0x1UL << GPIO_LCKR_LCK15_Pos)
#define GPIO_LCKR_LCK15                      GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos                   (16U)
#define GPIO_LCKR_LCKK_Msk                   (0x1UL << GPIO_LCKR_LCKK_Pos)
#define GPIO_LCKR_LCKK                       GPIO_LCKR_LCKK_Msk

#define AFIO_EVCR_PIN_Pos                    (0U)
#define AFIO_EVCR_PIN_Msk                    (0xFUL << AFIO_EVCR_PIN_Pos)
#define AFIO_EVCR_PIN                        AFIO_EVCR_PIN_Msk
#define AFIO_EVCR_PIN_0                      (0x1UL << AFIO_EVCR_PIN_Pos)
#define AFIO_EVCR_PIN_1                      (0x2UL << AFIO_EVCR_PIN_Pos)
#define AFIO_EVCR_PIN_2                      (0x4UL << AFIO_EVCR_PIN_Pos)
#define AFIO_EVCR_PIN_3                      (0x8UL << AFIO_EVCR_PIN_Pos)

#define AFIO_EVCR_PIN_PX0                    0x00000000U
#define AFIO_EVCR_PIN_PX1_Pos                (0U)
#define AFIO_EVCR_PIN_PX1_Msk                (0x1UL << AFIO_EVCR_PIN_PX1_Pos)
#define AFIO_EVCR_PIN_PX1                    AFIO_EVCR_PIN_PX1_Msk
#define AFIO_EVCR_PIN_PX2_Pos                (1U)
#define AFIO_EVCR_PIN_PX2_Msk                (0x1UL << AFIO_EVCR_PIN_PX2_Pos)
#define AFIO_EVCR_PIN_PX2                    AFIO_EVCR_PIN_PX2_Msk
#define AFIO_EVCR_PIN_PX3_Pos                (0U)
#define AFIO_EVCR_PIN_PX3_Msk                (0x3UL << AFIO_EVCR_PIN_PX3_Pos)
#define AFIO_EVCR_PIN_PX3                    AFIO_EVCR_PIN_PX3_Msk
#define AFIO_EVCR_PIN_PX4_Pos                (2U)
#define AFIO_EVCR_PIN_PX4_Msk                (0x1UL << AFIO_EVCR_PIN_PX4_Pos)
#define AFIO_EVCR_PIN_PX4                    AFIO_EVCR_PIN_PX4_Msk
#define AFIO_EVCR_PIN_PX5_Pos                (0U)
#define AFIO_EVCR_PIN_PX5_Msk                (0x5UL << AFIO_EVCR_PIN_PX5_Pos)
#define AFIO_EVCR_PIN_PX5                    AFIO_EVCR_PIN_PX5_Msk
#define AFIO_EVCR_PIN_PX6_Pos                (1U)
#define AFIO_EVCR_PIN_PX6_Msk                (0x3UL << AFIO_EVCR_PIN_PX6_Pos)
#define AFIO_EVCR_PIN_PX6                    AFIO_EVCR_PIN_PX6_Msk
#define AFIO_EVCR_PIN_PX7_Pos                (0U)
#define AFIO_EVCR_PIN_PX7_Msk                (0x7UL << AFIO_EVCR_PIN_PX7_Pos)
#define AFIO_EVCR_PIN_PX7                    AFIO_EVCR_PIN_PX7_Msk
#define AFIO_EVCR_PIN_PX8_Pos                (3U)
#define AFIO_EVCR_PIN_PX8_Msk                (0x1UL << AFIO_EVCR_PIN_PX8_Pos)
#define AFIO_EVCR_PIN_PX8                    AFIO_EVCR_PIN_PX8_Msk
#define AFIO_EVCR_PIN_PX9_Pos                (0U)
#define AFIO_EVCR_PIN_PX9_Msk                (0x9UL << AFIO_EVCR_PIN_PX9_Pos)
#define AFIO_EVCR_PIN_PX9                    AFIO_EVCR_PIN_PX9_Msk
#define AFIO_EVCR_PIN_PX10_Pos               (1U)
#define AFIO_EVCR_PIN_PX10_Msk               (0x5UL << AFIO_EVCR_PIN_PX10_Pos)
#define AFIO_EVCR_PIN_PX10                   AFIO_EVCR_PIN_PX10_Msk
#define AFIO_EVCR_PIN_PX11_Pos               (0U)
#define AFIO_EVCR_PIN_PX11_Msk               (0xBUL << AFIO_EVCR_PIN_PX11_Pos)
#define AFIO_EVCR_PIN_PX11                   AFIO_EVCR_PIN_PX11_Msk
#define AFIO_EVCR_PIN_PX12_Pos               (2U)
#define AFIO_EVCR_PIN_PX12_Msk               (0x3UL << AFIO_EVCR_PIN_PX12_Pos)
#define AFIO_EVCR_PIN_PX12                   AFIO_EVCR_PIN_PX12_Msk
#define AFIO_EVCR_PIN_PX13_Pos               (0U)
#define AFIO_EVCR_PIN_PX13_Msk               (0xDUL << AFIO_EVCR_PIN_PX13_Pos)
#define AFIO_EVCR_PIN_PX13                   AFIO_EVCR_PIN_PX13_Msk
#define AFIO_EVCR_PIN_PX14_Pos               (1U)
#define AFIO_EVCR_PIN_PX14_Msk               (0x7UL << AFIO_EVCR_PIN_PX14_Pos)
#define AFIO_EVCR_PIN_PX14                   AFIO_EVCR_PIN_PX14_Msk
#define AFIO_EVCR_PIN_PX15_Pos               (0U)
#define AFIO_EVCR_PIN_PX15_Msk               (0xFUL << AFIO_EVCR_PIN_PX15_Pos)
#define AFIO_EVCR_PIN_PX15                   AFIO_EVCR_PIN_PX15_Msk

#define AFIO_EVCR_PORT_Pos                   (4U)
#define AFIO_EVCR_PORT_Msk                   (0x7UL << AFIO_EVCR_PORT_Pos)
#define AFIO_EVCR_PORT                       AFIO_EVCR_PORT_Msk
#define AFIO_EVCR_PORT_0                     (0x1UL << AFIO_EVCR_PORT_Pos)
#define AFIO_EVCR_PORT_1                     (0x2UL << AFIO_EVCR_PORT_Pos)
#define AFIO_EVCR_PORT_2                     (0x4UL << AFIO_EVCR_PORT_Pos)

#define AFIO_EVCR_PORT_PA                    0x00000000
#define AFIO_EVCR_PORT_PB_Pos                (4U)
#define AFIO_EVCR_PORT_PB_Msk                (0x1UL << AFIO_EVCR_PORT_PB_Pos)
#define AFIO_EVCR_PORT_PB                    AFIO_EVCR_PORT_PB_Msk
#define AFIO_EVCR_PORT_PC_Pos                (5U)
#define AFIO_EVCR_PORT_PC_Msk                (0x1UL << AFIO_EVCR_PORT_PC_Pos)
#define AFIO_EVCR_PORT_PC                    AFIO_EVCR_PORT_PC_Msk
#define AFIO_EVCR_PORT_PD_Pos                (4U)
#define AFIO_EVCR_PORT_PD_Msk                (0x3UL << AFIO_EVCR_PORT_PD_Pos)
#define AFIO_EVCR_PORT_PD                    AFIO_EVCR_PORT_PD_Msk
#define AFIO_EVCR_PORT_PE_Pos                (6U)
#define AFIO_EVCR_PORT_PE_Msk                (0x1UL << AFIO_EVCR_PORT_PE_Pos)
#define AFIO_EVCR_PORT_PE                    AFIO_EVCR_PORT_PE_Msk

#define AFIO_EVCR_EVOE_Pos                   (7U)
#define AFIO_EVCR_EVOE_Msk                   (0x1UL << AFIO_EVCR_EVOE_Pos)
#define AFIO_EVCR_EVOE                       AFIO_EVCR_EVOE_Msk

#define AFIO_MAPR_SPI1_REMAP_Pos             (0U)
#define AFIO_MAPR_SPI1_REMAP_Msk             (0x1UL << AFIO_MAPR_SPI1_REMAP_Pos)
#define AFIO_MAPR_SPI1_REMAP                 AFIO_MAPR_SPI1_REMAP_Msk
#define AFIO_MAPR_I2C1_REMAP_Pos             (1U)
#define AFIO_MAPR_I2C1_REMAP_Msk             (0x1UL << AFIO_MAPR_I2C1_REMAP_Pos)
#define AFIO_MAPR_I2C1_REMAP                 AFIO_MAPR_I2C1_REMAP_Msk
#define AFIO_MAPR_USART1_REMAP_Pos           (2U)
#define AFIO_MAPR_USART1_REMAP_Msk           (0x1UL << AFIO_MAPR_USART1_REMAP_Pos)
#define AFIO_MAPR_USART1_REMAP               AFIO_MAPR_USART1_REMAP_Msk
#define AFIO_MAPR_USART2_REMAP_Pos           (3U)
#define AFIO_MAPR_USART2_REMAP_Msk           (0x1UL << AFIO_MAPR_USART2_REMAP_Pos)
#define AFIO_MAPR_USART2_REMAP               AFIO_MAPR_USART2_REMAP_Msk

#define AFIO_MAPR_USART3_REMAP_Pos           (4U)
#define AFIO_MAPR_USART3_REMAP_Msk           (0x3UL << AFIO_MAPR_USART3_REMAP_Pos)
#define AFIO_MAPR_USART3_REMAP               AFIO_MAPR_USART3_REMAP_Msk
#define AFIO_MAPR_USART3_REMAP_0             (0x1UL << AFIO_MAPR_USART3_REMAP_Pos)
#define AFIO_MAPR_USART3_REMAP_1             (0x2UL << AFIO_MAPR_USART3_REMAP_Pos)

#define AFIO_MAPR_USART3_REMAP_NOREMAP       0x00000000U
#define AFIO_MAPR_USART3_REMAP_PARTIALREMAP_Pos (4U)
#define AFIO_MAPR_USART3_REMAP_PARTIALREMAP_Msk (0x1UL << AFIO_MAPR_USART3_REMAP_PARTIALREMAP_Pos)
#define AFIO_MAPR_USART3_REMAP_PARTIALREMAP  AFIO_MAPR_USART3_REMAP_PARTIALREMAP_Msk
#define AFIO_MAPR_USART3_REMAP_FULLREMAP_Pos (4U)
#define AFIO_MAPR_USART3_REMAP_FULLREMAP_Msk (0x3UL << AFIO_MAPR_USART3_REMAP_FULLREMAP_Pos)
#define AFIO_MAPR_USART3_REMAP_FULLREMAP     AFIO_MAPR_USART3_REMAP_FULLREMAP_Msk

#define AFIO_MAPR_TIM1_REMAP_Pos             (6U)
#define AFIO_MAPR_TIM1_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM1_REMAP_Pos)
#define AFIO_MAPR_TIM1_REMAP                 AFIO_MAPR_TIM1_REMAP_Msk
#define AFIO_MAPR_TIM1_REMAP_0               (0x1UL << AFIO_MAPR_TIM1_REMAP_Pos)
#define AFIO_MAPR_TIM1_REMAP_1               (0x2UL << AFIO_MAPR_TIM1_REMAP_Pos)

#define AFIO_MAPR_TIM1_REMAP_NOREMAP         0x00000000U
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Pos (6U)
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Msk (0x1UL << AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Pos)
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP    AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Msk
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP_Pos   (6U)
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM1_REMAP_FULLREMAP_Pos)
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP       AFIO_MAPR_TIM1_REMAP_FULLREMAP_Msk

#define AFIO_MAPR_TIM2_REMAP_Pos             (8U)
#define AFIO_MAPR_TIM2_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM2_REMAP_Pos)
#define AFIO_MAPR_TIM2_REMAP                 AFIO_MAPR_TIM2_REMAP_Msk
#define AFIO_MAPR_TIM2_REMAP_0               (0x1UL << AFIO_MAPR_TIM2_REMAP_Pos)
#define AFIO_MAPR_TIM2_REMAP_1               (0x2UL << AFIO_MAPR_TIM2_REMAP_Pos)

#define AFIO_MAPR_TIM2_REMAP_NOREMAP         0x00000000U
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Pos (8U)
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Msk (0x1UL << AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Pos)
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1   AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Msk
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Pos (9U)
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Msk (0x1UL << AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Pos)
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2   AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Msk
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP_Pos   (8U)
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM2_REMAP_FULLREMAP_Pos)
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP       AFIO_MAPR_TIM2_REMAP_FULLREMAP_Msk

#define AFIO_MAPR_TIM3_REMAP_Pos             (10U)
#define AFIO_MAPR_TIM3_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM3_REMAP_Pos)
#define AFIO_MAPR_TIM3_REMAP                 AFIO_MAPR_TIM3_REMAP_Msk
#define AFIO_MAPR_TIM3_REMAP_0               (0x1UL << AFIO_MAPR_TIM3_REMAP_Pos)
#define AFIO_MAPR_TIM3_REMAP_1               (0x2UL << AFIO_MAPR_TIM3_REMAP_Pos)

#define AFIO_MAPR_TIM3_REMAP_NOREMAP         0x00000000U
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Pos (11U)
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Msk (0x1UL << AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Pos)
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP    AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Msk
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP_Pos   (10U)
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM3_REMAP_FULLREMAP_Pos)
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP       AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk

#define AFIO_MAPR_TIM4_REMAP_Pos             (12U)
#define AFIO_MAPR_TIM4_REMAP_Msk             (0x1UL << AFIO_MAPR_TIM4_REMAP_Pos)
#define AFIO_MAPR_TIM4_REMAP                 AFIO_MAPR_TIM4_REMAP_Msk

#define AFIO_MAPR_CAN_REMAP_Pos              (13U)
#define AFIO_MAPR_CAN_REMAP_Msk              (0x3UL << AFIO_MAPR_CAN_REMAP_Pos)
#define AFIO_MAPR_CAN_REMAP                  AFIO_MAPR_CAN_REMAP_Msk
#define AFIO_MAPR_CAN_REMAP_0                (0x1UL << AFIO_MAPR_CAN_REMAP_Pos)
#define AFIO_MAPR_CAN_REMAP_1                (0x2UL << AFIO_MAPR_CAN_REMAP_Pos)

#define AFIO_MAPR_CAN_REMAP_REMAP1           0x00000000U
#define AFIO_MAPR_CAN_REMAP_REMAP2_Pos       (14U)
#define AFIO_MAPR_CAN_REMAP_REMAP2_Msk       (0x1UL << AFIO_MAPR_CAN_REMAP_REMAP2_Pos)
#define AFIO_MAPR_CAN_REMAP_REMAP2           AFIO_MAPR_CAN_REMAP_REMAP2_Msk
#define AFIO_MAPR_CAN_REMAP_REMAP3_Pos       (13U)
#define AFIO_MAPR_CAN_REMAP_REMAP3_Msk       (0x3UL << AFIO_MAPR_CAN_REMAP_REMAP3_Pos)
#define AFIO_MAPR_CAN_REMAP_REMAP3           AFIO_MAPR_CAN_REMAP_REMAP3_Msk

#define AFIO_MAPR_PD01_REMAP_Pos             (15U)
#define AFIO_MAPR_PD01_REMAP_Msk             (0x1UL << AFIO_MAPR_PD01_REMAP_Pos)
#define AFIO_MAPR_PD01_REMAP                 AFIO_MAPR_PD01_REMAP_Msk

#define AFIO_MAPR_SWJ_CFG_Pos                (24U)
#define AFIO_MAPR_SWJ_CFG_Msk                (0x7UL << AFIO_MAPR_SWJ_CFG_Pos)
#define AFIO_MAPR_SWJ_CFG                    AFIO_MAPR_SWJ_CFG_Msk
#define AFIO_MAPR_SWJ_CFG_0                  (0x1UL << AFIO_MAPR_SWJ_CFG_Pos)
#define AFIO_MAPR_SWJ_CFG_1                  (0x2UL << AFIO_MAPR_SWJ_CFG_Pos)
#define AFIO_MAPR_SWJ_CFG_2                  (0x4UL << AFIO_MAPR_SWJ_CFG_Pos)

#define AFIO_MAPR_SWJ_CFG_RESET              0x00000000U
#define AFIO_MAPR_SWJ_CFG_NOJNTRST_Pos       (24U)
#define AFIO_MAPR_SWJ_CFG_NOJNTRST_Msk       (0x1UL << AFIO_MAPR_SWJ_CFG_NOJNTRST_Pos)
#define AFIO_MAPR_SWJ_CFG_NOJNTRST           AFIO_MAPR_SWJ_CFG_NOJNTRST_Msk
#define AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Pos    (25U)
#define AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Msk    (0x1UL << AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Pos)
#define AFIO_MAPR_SWJ_CFG_JTAGDISABLE        AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Msk
#define AFIO_MAPR_SWJ_CFG_DISABLE_Pos        (26U)
#define AFIO_MAPR_SWJ_CFG_DISABLE_Msk        (0x1UL << AFIO_MAPR_SWJ_CFG_DISABLE_Pos)
#define AFIO_MAPR_SWJ_CFG_DISABLE            AFIO_MAPR_SWJ_CFG_DISABLE_Msk

#define AFIO_EXTICR1_EXTI0_Pos               (0U)
#define AFIO_EXTICR1_EXTI0_Msk               (0xFUL << AFIO_EXTICR1_EXTI0_Pos)
#define AFIO_EXTICR1_EXTI0                   AFIO_EXTICR1_EXTI0_Msk
#define AFIO_EXTICR1_EXTI1_Pos               (4U)
#define AFIO_EXTICR1_EXTI1_Msk               (0xFUL << AFIO_EXTICR1_EXTI1_Pos)
#define AFIO_EXTICR1_EXTI1                   AFIO_EXTICR1_EXTI1_Msk
#define AFIO_EXTICR1_EXTI2_Pos               (8U)
#define AFIO_EXTICR1_EXTI2_Msk               (0xFUL << AFIO_EXTICR1_EXTI2_Pos)
#define AFIO_EXTICR1_EXTI2                   AFIO_EXTICR1_EXTI2_Msk
#define AFIO_EXTICR1_EXTI3_Pos               (12U)
#define AFIO_EXTICR1_EXTI3_Msk               (0xFUL << AFIO_EXTICR1_EXTI3_Pos)
#define AFIO_EXTICR1_EXTI3                   AFIO_EXTICR1_EXTI3_Msk

#define AFIO_EXTICR1_EXTI0_PA                0x00000000U
#define AFIO_EXTICR1_EXTI0_PB_Pos            (0U)
#define AFIO_EXTICR1_EXTI0_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI0_PB_Pos)
#define AFIO_EXTICR1_EXTI0_PB                AFIO_EXTICR1_EXTI0_PB_Msk
#define AFIO_EXTICR1_EXTI0_PC_Pos            (1U)
#define AFIO_EXTICR1_EXTI0_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI0_PC_Pos)
#define AFIO_EXTICR1_EXTI0_PC                AFIO_EXTICR1_EXTI0_PC_Msk
#define AFIO_EXTICR1_EXTI0_PD_Pos            (0U)
#define AFIO_EXTICR1_EXTI0_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI0_PD_Pos)
#define AFIO_EXTICR1_EXTI0_PD                AFIO_EXTICR1_EXTI0_PD_Msk
#define AFIO_EXTICR1_EXTI0_PE_Pos            (2U)
#define AFIO_EXTICR1_EXTI0_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI0_PE_Pos)
#define AFIO_EXTICR1_EXTI0_PE                AFIO_EXTICR1_EXTI0_PE_Msk
#define AFIO_EXTICR1_EXTI0_PF_Pos            (0U)
#define AFIO_EXTICR1_EXTI0_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI0_PF_Pos)
#define AFIO_EXTICR1_EXTI0_PF                AFIO_EXTICR1_EXTI0_PF_Msk
#define AFIO_EXTICR1_EXTI0_PG_Pos            (1U)
#define AFIO_EXTICR1_EXTI0_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI0_PG_Pos)
#define AFIO_EXTICR1_EXTI0_PG                AFIO_EXTICR1_EXTI0_PG_Msk

#define AFIO_EXTICR1_EXTI1_PA                0x00000000U
#define AFIO_EXTICR1_EXTI1_PB_Pos            (4U)
#define AFIO_EXTICR1_EXTI1_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI1_PB_Pos)
#define AFIO_EXTICR1_EXTI1_PB                AFIO_EXTICR1_EXTI1_PB_Msk
#define AFIO_EXTICR1_EXTI1_PC_Pos            (5U)
#define AFIO_EXTICR1_EXTI1_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI1_PC_Pos)
#define AFIO_EXTICR1_EXTI1_PC                AFIO_EXTICR1_EXTI1_PC_Msk
#define AFIO_EXTICR1_EXTI1_PD_Pos            (4U)
#define AFIO_EXTICR1_EXTI1_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI1_PD_Pos)
#define AFIO_EXTICR1_EXTI1_PD                AFIO_EXTICR1_EXTI1_PD_Msk
#define AFIO_EXTICR1_EXTI1_PE_Pos            (6U)
#define AFIO_EXTICR1_EXTI1_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI1_PE_Pos)
#define AFIO_EXTICR1_EXTI1_PE                AFIO_EXTICR1_EXTI1_PE_Msk
#define AFIO_EXTICR1_EXTI1_PF_Pos            (4U)
#define AFIO_EXTICR1_EXTI1_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI1_PF_Pos)
#define AFIO_EXTICR1_EXTI1_PF                AFIO_EXTICR1_EXTI1_PF_Msk
#define AFIO_EXTICR1_EXTI1_PG_Pos            (5U)
#define AFIO_EXTICR1_EXTI1_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI1_PG_Pos)
#define AFIO_EXTICR1_EXTI1_PG                AFIO_EXTICR1_EXTI1_PG_Msk

#define AFIO_EXTICR1_EXTI2_PA                0x00000000U
#define AFIO_EXTICR1_EXTI2_PB_Pos            (8U)
#define AFIO_EXTICR1_EXTI2_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI2_PB_Pos)
#define AFIO_EXTICR1_EXTI2_PB                AFIO_EXTICR1_EXTI2_PB_Msk
#define AFIO_EXTICR1_EXTI2_PC_Pos            (9U)
#define AFIO_EXTICR1_EXTI2_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI2_PC_Pos)
#define AFIO_EXTICR1_EXTI2_PC                AFIO_EXTICR1_EXTI2_PC_Msk
#define AFIO_EXTICR1_EXTI2_PD_Pos            (8U)
#define AFIO_EXTICR1_EXTI2_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI2_PD_Pos)
#define AFIO_EXTICR1_EXTI2_PD                AFIO_EXTICR1_EXTI2_PD_Msk
#define AFIO_EXTICR1_EXTI2_PE_Pos            (10U)
#define AFIO_EXTICR1_EXTI2_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI2_PE_Pos)
#define AFIO_EXTICR1_EXTI2_PE                AFIO_EXTICR1_EXTI2_PE_Msk
#define AFIO_EXTICR1_EXTI2_PF_Pos            (8U)
#define AFIO_EXTICR1_EXTI2_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI2_PF_Pos)
#define AFIO_EXTICR1_EXTI2_PF                AFIO_EXTICR1_EXTI2_PF_Msk
#define AFIO_EXTICR1_EXTI2_PG_Pos            (9U)
#define AFIO_EXTICR1_EXTI2_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI2_PG_Pos)
#define AFIO_EXTICR1_EXTI2_PG                AFIO_EXTICR1_EXTI2_PG_Msk

#define AFIO_EXTICR1_EXTI3_PA                0x00000000U
#define AFIO_EXTICR1_EXTI3_PB_Pos            (12U)
#define AFIO_EXTICR1_EXTI3_PB_Msk            (0x1UL << AFIO_EXTICR1_EXTI3_PB_Pos)
#define AFIO_EXTICR1_EXTI3_PB                AFIO_EXTICR1_EXTI3_PB_Msk
#define AFIO_EXTICR1_EXTI3_PC_Pos            (13U)
#define AFIO_EXTICR1_EXTI3_PC_Msk            (0x1UL << AFIO_EXTICR1_EXTI3_PC_Pos)
#define AFIO_EXTICR1_EXTI3_PC                AFIO_EXTICR1_EXTI3_PC_Msk
#define AFIO_EXTICR1_EXTI3_PD_Pos            (12U)
#define AFIO_EXTICR1_EXTI3_PD_Msk            (0x3UL << AFIO_EXTICR1_EXTI3_PD_Pos)
#define AFIO_EXTICR1_EXTI3_PD                AFIO_EXTICR1_EXTI3_PD_Msk
#define AFIO_EXTICR1_EXTI3_PE_Pos            (14U)
#define AFIO_EXTICR1_EXTI3_PE_Msk            (0x1UL << AFIO_EXTICR1_EXTI3_PE_Pos)
#define AFIO_EXTICR1_EXTI3_PE                AFIO_EXTICR1_EXTI3_PE_Msk
#define AFIO_EXTICR1_EXTI3_PF_Pos            (12U)
#define AFIO_EXTICR1_EXTI3_PF_Msk            (0x5UL << AFIO_EXTICR1_EXTI3_PF_Pos)
#define AFIO_EXTICR1_EXTI3_PF                AFIO_EXTICR1_EXTI3_PF_Msk
#define AFIO_EXTICR1_EXTI3_PG_Pos            (13U)
#define AFIO_EXTICR1_EXTI3_PG_Msk            (0x3UL << AFIO_EXTICR1_EXTI3_PG_Pos)
#define AFIO_EXTICR1_EXTI3_PG                AFIO_EXTICR1_EXTI3_PG_Msk

#define AFIO_EXTICR2_EXTI4_Pos               (0U)
#define AFIO_EXTICR2_EXTI4_Msk               (0xFUL << AFIO_EXTICR2_EXTI4_Pos)
#define AFIO_EXTICR2_EXTI4                   AFIO_EXTICR2_EXTI4_Msk
#define AFIO_EXTICR2_EXTI5_Pos               (4U)
#define AFIO_EXTICR2_EXTI5_Msk               (0xFUL << AFIO_EXTICR2_EXTI5_Pos)
#define AFIO_EXTICR2_EXTI5                   AFIO_EXTICR2_EXTI5_Msk
#define AFIO_EXTICR2_EXTI6_Pos               (8U)
#define AFIO_EXTICR2_EXTI6_Msk               (0xFUL << AFIO_EXTICR2_EXTI6_Pos)
#define AFIO_EXTICR2_EXTI6                   AFIO_EXTICR2_EXTI6_Msk
#define AFIO_EXTICR2_EXTI7_Pos               (12U)
#define AFIO_EXTICR2_EXTI7_Msk               (0xFUL << AFIO_EXTICR2_EXTI7_Pos)
#define AFIO_EXTICR2_EXTI7                   AFIO_EXTICR2_EXTI7_Msk

#define AFIO_EXTICR2_EXTI4_PA                0x00000000U
#define AFIO_EXTICR2_EXTI4_PB_Pos            (0U)
#define AFIO_EXTICR2_EXTI4_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI4_PB_Pos)
#define AFIO_EXTICR2_EXTI4_PB                AFIO_EXTICR2_EXTI4_PB_Msk
#define AFIO_EXTICR2_EXTI4_PC_Pos            (1U)
#define AFIO_EXTICR2_EXTI4_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI4_PC_Pos)
#define AFIO_EXTICR2_EXTI4_PC                AFIO_EXTICR2_EXTI4_PC_Msk
#define AFIO_EXTICR2_EXTI4_PD_Pos            (0U)
#define AFIO_EXTICR2_EXTI4_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI4_PD_Pos)
#define AFIO_EXTICR2_EXTI4_PD                AFIO_EXTICR2_EXTI4_PD_Msk
#define AFIO_EXTICR2_EXTI4_PE_Pos            (2U)
#define AFIO_EXTICR2_EXTI4_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI4_PE_Pos)
#define AFIO_EXTICR2_EXTI4_PE                AFIO_EXTICR2_EXTI4_PE_Msk
#define AFIO_EXTICR2_EXTI4_PF_Pos            (0U)
#define AFIO_EXTICR2_EXTI4_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI4_PF_Pos)
#define AFIO_EXTICR2_EXTI4_PF                AFIO_EXTICR2_EXTI4_PF_Msk
#define AFIO_EXTICR2_EXTI4_PG_Pos            (1U)
#define AFIO_EXTICR2_EXTI4_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI4_PG_Pos)
#define AFIO_EXTICR2_EXTI4_PG                AFIO_EXTICR2_EXTI4_PG_Msk

#define AFIO_EXTICR2_EXTI5_PA                0x00000000U
#define AFIO_EXTICR2_EXTI5_PB_Pos            (4U)
#define AFIO_EXTICR2_EXTI5_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI5_PB_Pos)
#define AFIO_EXTICR2_EXTI5_PB                AFIO_EXTICR2_EXTI5_PB_Msk
#define AFIO_EXTICR2_EXTI5_PC_Pos            (5U)
#define AFIO_EXTICR2_EXTI5_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI5_PC_Pos)
#define AFIO_EXTICR2_EXTI5_PC                AFIO_EXTICR2_EXTI5_PC_Msk
#define AFIO_EXTICR2_EXTI5_PD_Pos            (4U)
#define AFIO_EXTICR2_EXTI5_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI5_PD_Pos)
#define AFIO_EXTICR2_EXTI5_PD                AFIO_EXTICR2_EXTI5_PD_Msk
#define AFIO_EXTICR2_EXTI5_PE_Pos            (6U)
#define AFIO_EXTICR2_EXTI5_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI5_PE_Pos)
#define AFIO_EXTICR2_EXTI5_PE                AFIO_EXTICR2_EXTI5_PE_Msk
#define AFIO_EXTICR2_EXTI5_PF_Pos            (4U)
#define AFIO_EXTICR2_EXTI5_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI5_PF_Pos)
#define AFIO_EXTICR2_EXTI5_PF                AFIO_EXTICR2_EXTI5_PF_Msk
#define AFIO_EXTICR2_EXTI5_PG_Pos            (5U)
#define AFIO_EXTICR2_EXTI5_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI5_PG_Pos)
#define AFIO_EXTICR2_EXTI5_PG                AFIO_EXTICR2_EXTI5_PG_Msk

#define AFIO_EXTICR2_EXTI6_PA                0x00000000U
#define AFIO_EXTICR2_EXTI6_PB_Pos            (8U)
#define AFIO_EXTICR2_EXTI6_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI6_PB_Pos)
#define AFIO_EXTICR2_EXTI6_PB                AFIO_EXTICR2_EXTI6_PB_Msk
#define AFIO_EXTICR2_EXTI6_PC_Pos            (9U)
#define AFIO_EXTICR2_EXTI6_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI6_PC_Pos)
#define AFIO_EXTICR2_EXTI6_PC                AFIO_EXTICR2_EXTI6_PC_Msk
#define AFIO_EXTICR2_EXTI6_PD_Pos            (8U)
#define AFIO_EXTICR2_EXTI6_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI6_PD_Pos)
#define AFIO_EXTICR2_EXTI6_PD                AFIO_EXTICR2_EXTI6_PD_Msk
#define AFIO_EXTICR2_EXTI6_PE_Pos            (10U)
#define AFIO_EXTICR2_EXTI6_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI6_PE_Pos)
#define AFIO_EXTICR2_EXTI6_PE                AFIO_EXTICR2_EXTI6_PE_Msk
#define AFIO_EXTICR2_EXTI6_PF_Pos            (8U)
#define AFIO_EXTICR2_EXTI6_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI6_PF_Pos)
#define AFIO_EXTICR2_EXTI6_PF                AFIO_EXTICR2_EXTI6_PF_Msk
#define AFIO_EXTICR2_EXTI6_PG_Pos            (9U)
#define AFIO_EXTICR2_EXTI6_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI6_PG_Pos)
#define AFIO_EXTICR2_EXTI6_PG                AFIO_EXTICR2_EXTI6_PG_Msk

#define AFIO_EXTICR2_EXTI7_PA                0x00000000U
#define AFIO_EXTICR2_EXTI7_PB_Pos            (12U)
#define AFIO_EXTICR2_EXTI7_PB_Msk            (0x1UL << AFIO_EXTICR2_EXTI7_PB_Pos)
#define AFIO_EXTICR2_EXTI7_PB                AFIO_EXTICR2_EXTI7_PB_Msk
#define AFIO_EXTICR2_EXTI7_PC_Pos            (13U)
#define AFIO_EXTICR2_EXTI7_PC_Msk            (0x1UL << AFIO_EXTICR2_EXTI7_PC_Pos)
#define AFIO_EXTICR2_EXTI7_PC                AFIO_EXTICR2_EXTI7_PC_Msk
#define AFIO_EXTICR2_EXTI7_PD_Pos            (12U)
#define AFIO_EXTICR2_EXTI7_PD_Msk            (0x3UL << AFIO_EXTICR2_EXTI7_PD_Pos)
#define AFIO_EXTICR2_EXTI7_PD                AFIO_EXTICR2_EXTI7_PD_Msk
#define AFIO_EXTICR2_EXTI7_PE_Pos            (14U)
#define AFIO_EXTICR2_EXTI7_PE_Msk            (0x1UL << AFIO_EXTICR2_EXTI7_PE_Pos)
#define AFIO_EXTICR2_EXTI7_PE                AFIO_EXTICR2_EXTI7_PE_Msk
#define AFIO_EXTICR2_EXTI7_PF_Pos            (12U)
#define AFIO_EXTICR2_EXTI7_PF_Msk            (0x5UL << AFIO_EXTICR2_EXTI7_PF_Pos)
#define AFIO_EXTICR2_EXTI7_PF                AFIO_EXTICR2_EXTI7_PF_Msk
#define AFIO_EXTICR2_EXTI7_PG_Pos            (13U)
#define AFIO_EXTICR2_EXTI7_PG_Msk            (0x3UL << AFIO_EXTICR2_EXTI7_PG_Pos)
#define AFIO_EXTICR2_EXTI7_PG                AFIO_EXTICR2_EXTI7_PG_Msk

#define AFIO_EXTICR3_EXTI8_Pos               (0U)
#define AFIO_EXTICR3_EXTI8_Msk               (0xFUL << AFIO_EXTICR3_EXTI8_Pos)
#define AFIO_EXTICR3_EXTI8                   AFIO_EXTICR3_EXTI8_Msk
#define AFIO_EXTICR3_EXTI9_Pos               (4U)
#define AFIO_EXTICR3_EXTI9_Msk               (0xFUL << AFIO_EXTICR3_EXTI9_Pos)
#define AFIO_EXTICR3_EXTI9                   AFIO_EXTICR3_EXTI9_Msk
#define AFIO_EXTICR3_EXTI10_Pos              (8U)
#define AFIO_EXTICR3_EXTI10_Msk              (0xFUL << AFIO_EXTICR3_EXTI10_Pos)
#define AFIO_EXTICR3_EXTI10                  AFIO_EXTICR3_EXTI10_Msk
#define AFIO_EXTICR3_EXTI11_Pos              (12U)
#define AFIO_EXTICR3_EXTI11_Msk              (0xFUL << AFIO_EXTICR3_EXTI11_Pos)
#define AFIO_EXTICR3_EXTI11                  AFIO_EXTICR3_EXTI11_Msk

#define AFIO_EXTICR3_EXTI8_PA                0x00000000U
#define AFIO_EXTICR3_EXTI8_PB_Pos            (0U)
#define AFIO_EXTICR3_EXTI8_PB_Msk            (0x1UL << AFIO_EXTICR3_EXTI8_PB_Pos)
#define AFIO_EXTICR3_EXTI8_PB                AFIO_EXTICR3_EXTI8_PB_Msk
#define AFIO_EXTICR3_EXTI8_PC_Pos            (1U)
#define AFIO_EXTICR3_EXTI8_PC_Msk            (0x1UL << AFIO_EXTICR3_EXTI8_PC_Pos)
#define AFIO_EXTICR3_EXTI8_PC                AFIO_EXTICR3_EXTI8_PC_Msk
#define AFIO_EXTICR3_EXTI8_PD_Pos            (0U)
#define AFIO_EXTICR3_EXTI8_PD_Msk            (0x3UL << AFIO_EXTICR3_EXTI8_PD_Pos)
#define AFIO_EXTICR3_EXTI8_PD                AFIO_EXTICR3_EXTI8_PD_Msk
#define AFIO_EXTICR3_EXTI8_PE_Pos            (2U)
#define AFIO_EXTICR3_EXTI8_PE_Msk            (0x1UL << AFIO_EXTICR3_EXTI8_PE_Pos)
#define AFIO_EXTICR3_EXTI8_PE                AFIO_EXTICR3_EXTI8_PE_Msk
#define AFIO_EXTICR3_EXTI8_PF_Pos            (0U)
#define AFIO_EXTICR3_EXTI8_PF_Msk            (0x5UL << AFIO_EXTICR3_EXTI8_PF_Pos)
#define AFIO_EXTICR3_EXTI8_PF                AFIO_EXTICR3_EXTI8_PF_Msk
#define AFIO_EXTICR3_EXTI8_PG_Pos            (1U)
#define AFIO_EXTICR3_EXTI8_PG_Msk            (0x3UL << AFIO_EXTICR3_EXTI8_PG_Pos)
#define AFIO_EXTICR3_EXTI8_PG                AFIO_EXTICR3_EXTI8_PG_Msk

#define AFIO_EXTICR3_EXTI9_PA                0x00000000U
#define AFIO_EXTICR3_EXTI9_PB_Pos            (4U)
#define AFIO_EXTICR3_EXTI9_PB_Msk            (0x1UL << AFIO_EXTICR3_EXTI9_PB_Pos)
#define AFIO_EXTICR3_EXTI9_PB                AFIO_EXTICR3_EXTI9_PB_Msk
#define AFIO_EXTICR3_EXTI9_PC_Pos            (5U)
#define AFIO_EXTICR3_EXTI9_PC_Msk            (0x1UL << AFIO_EXTICR3_EXTI9_PC_Pos)
#define AFIO_EXTICR3_EXTI9_PC                AFIO_EXTICR3_EXTI9_PC_Msk
#define AFIO_EXTICR3_EXTI9_PD_Pos            (4U)
#define AFIO_EXTICR3_EXTI9_PD_Msk            (0x3UL << AFIO_EXTICR3_EXTI9_PD_Pos)
#define AFIO_EXTICR3_EXTI9_PD                AFIO_EXTICR3_EXTI9_PD_Msk
#define AFIO_EXTICR3_EXTI9_PE_Pos            (6U)
#define AFIO_EXTICR3_EXTI9_PE_Msk            (0x1UL << AFIO_EXTICR3_EXTI9_PE_Pos)
#define AFIO_EXTICR3_EXTI9_PE                AFIO_EXTICR3_EXTI9_PE_Msk
#define AFIO_EXTICR3_EXTI9_PF_Pos            (4U)
#define AFIO_EXTICR3_EXTI9_PF_Msk            (0x5UL << AFIO_EXTICR3_EXTI9_PF_Pos)
#define AFIO_EXTICR3_EXTI9_PF                AFIO_EXTICR3_EXTI9_PF_Msk
#define AFIO_EXTICR3_EXTI9_PG_Pos            (5U)
#define AFIO_EXTICR3_EXTI9_PG_Msk            (0x3UL << AFIO_EXTICR3_EXTI9_PG_Pos)
#define AFIO_EXTICR3_EXTI9_PG                AFIO_EXTICR3_EXTI9_PG_Msk

#define AFIO_EXTICR3_EXTI10_PA               0x00000000U
#define AFIO_EXTICR3_EXTI10_PB_Pos           (8U)
#define AFIO_EXTICR3_EXTI10_PB_Msk           (0x1UL << AFIO_EXTICR3_EXTI10_PB_Pos)
#define AFIO_EXTICR3_EXTI10_PB               AFIO_EXTICR3_EXTI10_PB_Msk
#define AFIO_EXTICR3_EXTI10_PC_Pos           (9U)
#define AFIO_EXTICR3_EXTI10_PC_Msk           (0x1UL << AFIO_EXTICR3_EXTI10_PC_Pos)
#define AFIO_EXTICR3_EXTI10_PC               AFIO_EXTICR3_EXTI10_PC_Msk
#define AFIO_EXTICR3_EXTI10_PD_Pos           (8U)
#define AFIO_EXTICR3_EXTI10_PD_Msk           (0x3UL << AFIO_EXTICR3_EXTI10_PD_Pos)
#define AFIO_EXTICR3_EXTI10_PD               AFIO_EXTICR3_EXTI10_PD_Msk
#define AFIO_EXTICR3_EXTI10_PE_Pos           (10U)
#define AFIO_EXTICR3_EXTI10_PE_Msk           (0x1UL << AFIO_EXTICR3_EXTI10_PE_Pos)
#define AFIO_EXTICR3_EXTI10_PE               AFIO_EXTICR3_EXTI10_PE_Msk
#define AFIO_EXTICR3_EXTI10_PF_Pos           (8U)
#define AFIO_EXTICR3_EXTI10_PF_Msk           (0x5UL << AFIO_EXTICR3_EXTI10_PF_Pos)
#define AFIO_EXTICR3_EXTI10_PF               AFIO_EXTICR3_EXTI10_PF_Msk
#define AFIO_EXTICR3_EXTI10_PG_Pos           (9U)
#define AFIO_EXTICR3_EXTI10_PG_Msk           (0x3UL << AFIO_EXTICR3_EXTI10_PG_Pos)
#define AFIO_EXTICR3_EXTI10_PG               AFIO_EXTICR3_EXTI10_PG_Msk

#define AFIO_EXTICR3_EXTI11_PA               0x00000000U
#define AFIO_EXTICR3_EXTI11_PB_Pos           (12U)
#define AFIO_EXTICR3_EXTI11_PB_Msk           (0x1UL << AFIO_EXTICR3_EXTI11_PB_Pos)
#define AFIO_EXTICR3_EXTI11_PB               AFIO_EXTICR3_EXTI11_PB_Msk
#define AFIO_EXTICR3_EXTI11_PC_Pos           (13U)
#define AFIO_EXTICR3_EXTI11_PC_Msk           (0x1UL << AFIO_EXTICR3_EXTI11_PC_Pos)
#define AFIO_EXTICR3_EXTI11_PC               AFIO_EXTICR3_EXTI11_PC_Msk
#define AFIO_EXTICR3_EXTI11_PD_Pos           (12U)
#define AFIO_EXTICR3_EXTI11_PD_Msk           (0x3UL << AFIO_EXTICR3_EXTI11_PD_Pos)
#define AFIO_EXTICR3_EXTI11_PD               AFIO_EXTICR3_EXTI11_PD_Msk
#define AFIO_EXTICR3_EXTI11_PE_Pos           (14U)
#define AFIO_EXTICR3_EXTI11_PE_Msk           (0x1UL << AFIO_EXTICR3_EXTI11_PE_Pos)
#define AFIO_EXTICR3_EXTI11_PE               AFIO_EXTICR3_EXTI11_PE_Msk
#define AFIO_EXTICR3_EXTI11_PF_Pos           (12U)
#define AFIO_EXTICR3_EXTI11_PF_Msk           (0x5UL << AFIO_EXTICR3_EXTI11_PF_Pos)
#define AFIO_EXTICR3_EXTI11_PF               AFIO_EXTICR3_EXTI11_PF_Msk
#define AFIO_EXTICR3_EXTI11_PG_Pos           (13U)
#define AFIO_EXTICR3_EXTI11_PG_Msk           (0x3UL << AFIO_EXTICR3_EXTI11_PG_Pos)
#define AFIO_EXTICR3_EXTI11_PG               AFIO_EXTICR3_EXTI11_PG_Msk

#define AFIO_EXTICR4_EXTI12_Pos              (0U)
#define AFIO_EXTICR4_EXTI12_Msk              (0xFUL << AFIO_EXTICR4_EXTI12_Pos)
#define AFIO_EXTICR4_EXTI12                  AFIO_EXTICR4_EXTI12_Msk
#define AFIO_EXTICR4_EXTI13_Pos              (4U)
#define AFIO_EXTICR4_EXTI13_Msk              (0xFUL << AFIO_EXTICR4_EXTI13_Pos)
#define AFIO_EXTICR4_EXTI13                  AFIO_EXTICR4_EXTI13_Msk
#define AFIO_EXTICR4_EXTI14_Pos              (8U)
#define AFIO_EXTICR4_EXTI14_Msk              (0xFUL << AFIO_EXTICR4_EXTI14_Pos)
#define AFIO_EXTICR4_EXTI14                  AFIO_EXTICR4_EXTI14_Msk
#define AFIO_EXTICR4_EXTI15_Pos              (12U)
#define AFIO_EXTICR4_EXTI15_Msk              (0xFUL << AFIO_EXTICR4_EXTI15_Pos)
#define AFIO_EXTICR4_EXTI15                  AFIO_EXTICR4_EXTI15_Msk

#define AFIO_EXTICR4_EXTI12_PA               0x00000000U
#define AFIO_EXTICR4_EXTI12_PB_Pos           (0U)
#define AFIO_EXTICR4_EXTI12_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI12_PB_Pos)
#define AFIO_EXTICR4_EXTI12_PB               AFIO_EXTICR4_EXTI12_PB_Msk
#define AFIO_EXTICR4_EXTI12_PC_Pos           (1U)
#define AFIO_EXTICR4_EXTI12_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI12_PC_Pos)
#define AFIO_EXTICR4_EXTI12_PC               AFIO_EXTICR4_EXTI12_PC_Msk
#define AFIO_EXTICR4_EXTI12_PD_Pos           (0U)
#define AFIO_EXTICR4_EXTI12_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI12_PD_Pos)
#define AFIO_EXTICR4_EXTI12_PD               AFIO_EXTICR4_EXTI12_PD_Msk
#define AFIO_EXTICR4_EXTI12_PE_Pos           (2U)
#define AFIO_EXTICR4_EXTI12_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI12_PE_Pos)
#define AFIO_EXTICR4_EXTI12_PE               AFIO_EXTICR4_EXTI12_PE_Msk
#define AFIO_EXTICR4_EXTI12_PF_Pos           (0U)
#define AFIO_EXTICR4_EXTI12_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI12_PF_Pos)
#define AFIO_EXTICR4_EXTI12_PF               AFIO_EXTICR4_EXTI12_PF_Msk
#define AFIO_EXTICR4_EXTI12_PG_Pos           (1U)
#define AFIO_EXTICR4_EXTI12_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI12_PG_Pos)
#define AFIO_EXTICR4_EXTI12_PG               AFIO_EXTICR4_EXTI12_PG_Msk

#define AFIO_EXTICR4_EXTI13_PA               0x00000000U
#define AFIO_EXTICR4_EXTI13_PB_Pos           (4U)
#define AFIO_EXTICR4_EXTI13_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI13_PB_Pos)
#define AFIO_EXTICR4_EXTI13_PB               AFIO_EXTICR4_EXTI13_PB_Msk
#define AFIO_EXTICR4_EXTI13_PC_Pos           (5U)
#define AFIO_EXTICR4_EXTI13_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI13_PC_Pos)
#define AFIO_EXTICR4_EXTI13_PC               AFIO_EXTICR4_EXTI13_PC_Msk
#define AFIO_EXTICR4_EXTI13_PD_Pos           (4U)
#define AFIO_EXTICR4_EXTI13_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI13_PD_Pos)
#define AFIO_EXTICR4_EXTI13_PD               AFIO_EXTICR4_EXTI13_PD_Msk
#define AFIO_EXTICR4_EXTI13_PE_Pos           (6U)
#define AFIO_EXTICR4_EXTI13_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI13_PE_Pos)
#define AFIO_EXTICR4_EXTI13_PE               AFIO_EXTICR4_EXTI13_PE_Msk
#define AFIO_EXTICR4_EXTI13_PF_Pos           (4U)
#define AFIO_EXTICR4_EXTI13_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI13_PF_Pos)
#define AFIO_EXTICR4_EXTI13_PF               AFIO_EXTICR4_EXTI13_PF_Msk
#define AFIO_EXTICR4_EXTI13_PG_Pos           (5U)
#define AFIO_EXTICR4_EXTI13_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI13_PG_Pos)
#define AFIO_EXTICR4_EXTI13_PG               AFIO_EXTICR4_EXTI13_PG_Msk

#define AFIO_EXTICR4_EXTI14_PA               0x00000000U
#define AFIO_EXTICR4_EXTI14_PB_Pos           (8U)
#define AFIO_EXTICR4_EXTI14_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI14_PB_Pos)
#define AFIO_EXTICR4_EXTI14_PB               AFIO_EXTICR4_EXTI14_PB_Msk
#define AFIO_EXTICR4_EXTI14_PC_Pos           (9U)
#define AFIO_EXTICR4_EXTI14_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI14_PC_Pos)
#define AFIO_EXTICR4_EXTI14_PC               AFIO_EXTICR4_EXTI14_PC_Msk
#define AFIO_EXTICR4_EXTI14_PD_Pos           (8U)
#define AFIO_EXTICR4_EXTI14_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI14_PD_Pos)
#define AFIO_EXTICR4_EXTI14_PD               AFIO_EXTICR4_EXTI14_PD_Msk
#define AFIO_EXTICR4_EXTI14_PE_Pos           (10U)
#define AFIO_EXTICR4_EXTI14_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI14_PE_Pos)
#define AFIO_EXTICR4_EXTI14_PE               AFIO_EXTICR4_EXTI14_PE_Msk
#define AFIO_EXTICR4_EXTI14_PF_Pos           (8U)
#define AFIO_EXTICR4_EXTI14_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI14_PF_Pos)
#define AFIO_EXTICR4_EXTI14_PF               AFIO_EXTICR4_EXTI14_PF_Msk
#define AFIO_EXTICR4_EXTI14_PG_Pos           (9U)
#define AFIO_EXTICR4_EXTI14_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI14_PG_Pos)
#define AFIO_EXTICR4_EXTI14_PG               AFIO_EXTICR4_EXTI14_PG_Msk

#define AFIO_EXTICR4_EXTI15_PA               0x00000000U
#define AFIO_EXTICR4_EXTI15_PB_Pos           (12U)
#define AFIO_EXTICR4_EXTI15_PB_Msk           (0x1UL << AFIO_EXTICR4_EXTI15_PB_Pos)
#define AFIO_EXTICR4_EXTI15_PB               AFIO_EXTICR4_EXTI15_PB_Msk
#define AFIO_EXTICR4_EXTI15_PC_Pos           (13U)
#define AFIO_EXTICR4_EXTI15_PC_Msk           (0x1UL << AFIO_EXTICR4_EXTI15_PC_Pos)
#define AFIO_EXTICR4_EXTI15_PC               AFIO_EXTICR4_EXTI15_PC_Msk
#define AFIO_EXTICR4_EXTI15_PD_Pos           (12U)
#define AFIO_EXTICR4_EXTI15_PD_Msk           (0x3UL << AFIO_EXTICR4_EXTI15_PD_Pos)
#define AFIO_EXTICR4_EXTI15_PD               AFIO_EXTICR4_EXTI15_PD_Msk
#define AFIO_EXTICR4_EXTI15_PE_Pos           (14U)
#define AFIO_EXTICR4_EXTI15_PE_Msk           (0x1UL << AFIO_EXTICR4_EXTI15_PE_Pos)
#define AFIO_EXTICR4_EXTI15_PE               AFIO_EXTICR4_EXTI15_PE_Msk
#define AFIO_EXTICR4_EXTI15_PF_Pos           (12U)
#define AFIO_EXTICR4_EXTI15_PF_Msk           (0x5UL << AFIO_EXTICR4_EXTI15_PF_Pos)
#define AFIO_EXTICR4_EXTI15_PF               AFIO_EXTICR4_EXTI15_PF_Msk
#define AFIO_EXTICR4_EXTI15_PG_Pos           (13U)
#define AFIO_EXTICR4_EXTI15_PG_Msk           (0x3UL << AFIO_EXTICR4_EXTI15_PG_Pos)
#define AFIO_EXTICR4_EXTI15_PG               AFIO_EXTICR4_EXTI15_PG_Msk

#define EXTI_IMR_MR0_Pos                    (0U)
#define EXTI_IMR_MR0_Msk                    (0x1UL << EXTI_IMR_MR0_Pos)
#define EXTI_IMR_MR0                        EXTI_IMR_MR0_Msk
#define EXTI_IMR_MR1_Pos                    (1U)
#define EXTI_IMR_MR1_Msk                    (0x1UL << EXTI_IMR_MR1_Pos)
#define EXTI_IMR_MR1                        EXTI_IMR_MR1_Msk
#define EXTI_IMR_MR2_Pos                    (2U)
#define EXTI_IMR_MR2_Msk                    (0x1UL << EXTI_IMR_MR2_Pos)
#define EXTI_IMR_MR2                        EXTI_IMR_MR2_Msk
#define EXTI_IMR_MR3_Pos                    (3U)
#define EXTI_IMR_MR3_Msk                    (0x1UL << EXTI_IMR_MR3_Pos)
#define EXTI_IMR_MR3                        EXTI_IMR_MR3_Msk
#define EXTI_IMR_MR4_Pos                    (4U)
#define EXTI_IMR_MR4_Msk                    (0x1UL << EXTI_IMR_MR4_Pos)
#define EXTI_IMR_MR4                        EXTI_IMR_MR4_Msk
#define EXTI_IMR_MR5_Pos                    (5U)
#define EXTI_IMR_MR5_Msk                    (0x1UL << EXTI_IMR_MR5_Pos)
#define EXTI_IMR_MR5                        EXTI_IMR_MR5_Msk
#define EXTI_IMR_MR6_Pos                    (6U)
#define EXTI_IMR_MR6_Msk                    (0x1UL << EXTI_IMR_MR6_Pos)
#define EXTI_IMR_MR6                        EXTI_IMR_MR6_Msk
#define EXTI_IMR_MR7_Pos                    (7U)
#define EXTI_IMR_MR7_Msk                    (0x1UL << EXTI_IMR_MR7_Pos)
#define EXTI_IMR_MR7                        EXTI_IMR_MR7_Msk
#define EXTI_IMR_MR8_Pos                    (8U)
#define EXTI_IMR_MR8_Msk                    (0x1UL << EXTI_IMR_MR8_Pos)
#define EXTI_IMR_MR8                        EXTI_IMR_MR8_Msk
#define EXTI_IMR_MR9_Pos                    (9U)
#define EXTI_IMR_MR9_Msk                    (0x1UL << EXTI_IMR_MR9_Pos)
#define EXTI_IMR_MR9                        EXTI_IMR_MR9_Msk
#define EXTI_IMR_MR10_Pos                   (10U)
#define EXTI_IMR_MR10_Msk                   (0x1UL << EXTI_IMR_MR10_Pos)
#define EXTI_IMR_MR10                       EXTI_IMR_MR10_Msk
#define EXTI_IMR_MR11_Pos                   (11U)
#define EXTI_IMR_MR11_Msk                   (0x1UL << EXTI_IMR_MR11_Pos)
#define EXTI_IMR_MR11                       EXTI_IMR_MR11_Msk
#define EXTI_IMR_MR12_Pos                   (12U)
#define EXTI_IMR_MR12_Msk                   (0x1UL << EXTI_IMR_MR12_Pos)
#define EXTI_IMR_MR12                       EXTI_IMR_MR12_Msk
#define EXTI_IMR_MR13_Pos                   (13U)
#define EXTI_IMR_MR13_Msk                   (0x1UL << EXTI_IMR_MR13_Pos)
#define EXTI_IMR_MR13                       EXTI_IMR_MR13_Msk
#define EXTI_IMR_MR14_Pos                   (14U)
#define EXTI_IMR_MR14_Msk                   (0x1UL << EXTI_IMR_MR14_Pos)
#define EXTI_IMR_MR14                       EXTI_IMR_MR14_Msk
#define EXTI_IMR_MR15_Pos                   (15U)
#define EXTI_IMR_MR15_Msk                   (0x1UL << EXTI_IMR_MR15_Pos)
#define EXTI_IMR_MR15                       EXTI_IMR_MR15_Msk
#define EXTI_IMR_MR16_Pos                   (16U)
#define EXTI_IMR_MR16_Msk                   (0x1UL << EXTI_IMR_MR16_Pos)
#define EXTI_IMR_MR16                       EXTI_IMR_MR16_Msk
#define EXTI_IMR_MR17_Pos                   (17U)
#define EXTI_IMR_MR17_Msk                   (0x1UL << EXTI_IMR_MR17_Pos)
#define EXTI_IMR_MR17                       EXTI_IMR_MR17_Msk
#define EXTI_IMR_MR18_Pos                   (18U)
#define EXTI_IMR_MR18_Msk                   (0x1UL << EXTI_IMR_MR18_Pos)
#define EXTI_IMR_MR18                       EXTI_IMR_MR18_Msk

#define  EXTI_IMR_IM0 EXTI_IMR_MR0
#define  EXTI_IMR_IM1 EXTI_IMR_MR1
#define  EXTI_IMR_IM2 EXTI_IMR_MR2
#define  EXTI_IMR_IM3 EXTI_IMR_MR3
#define  EXTI_IMR_IM4 EXTI_IMR_MR4
#define  EXTI_IMR_IM5 EXTI_IMR_MR5
#define  EXTI_IMR_IM6 EXTI_IMR_MR6
#define  EXTI_IMR_IM7 EXTI_IMR_MR7
#define  EXTI_IMR_IM8 EXTI_IMR_MR8
#define  EXTI_IMR_IM9 EXTI_IMR_MR9
#define  EXTI_IMR_IM10 EXTI_IMR_MR10
#define  EXTI_IMR_IM11 EXTI_IMR_MR11
#define  EXTI_IMR_IM12 EXTI_IMR_MR12
#define  EXTI_IMR_IM13 EXTI_IMR_MR13
#define  EXTI_IMR_IM14 EXTI_IMR_MR14
#define  EXTI_IMR_IM15 EXTI_IMR_MR15
#define  EXTI_IMR_IM16 EXTI_IMR_MR16
#define  EXTI_IMR_IM17 EXTI_IMR_MR17
#define  EXTI_IMR_IM18 EXTI_IMR_MR18
#define  EXTI_IMR_IM   0x0007FFFFU

#define EXTI_EMR_MR0_Pos                    (0U)
#define EXTI_EMR_MR0_Msk                    (0x1UL << EXTI_EMR_MR0_Pos)
#define EXTI_EMR_MR0                        EXTI_EMR_MR0_Msk
#define EXTI_EMR_MR1_Pos                    (1U)
#define EXTI_EMR_MR1_Msk                    (0x1UL << EXTI_EMR_MR1_Pos)
#define EXTI_EMR_MR1                        EXTI_EMR_MR1_Msk
#define EXTI_EMR_MR2_Pos                    (2U)
#define EXTI_EMR_MR2_Msk                    (0x1UL << EXTI_EMR_MR2_Pos)
#define EXTI_EMR_MR2                        EXTI_EMR_MR2_Msk
#define EXTI_EMR_MR3_Pos                    (3U)
#define EXTI_EMR_MR3_Msk                    (0x1UL << EXTI_EMR_MR3_Pos)
#define EXTI_EMR_MR3                        EXTI_EMR_MR3_Msk
#define EXTI_EMR_MR4_Pos                    (4U)
#define EXTI_EMR_MR4_Msk                    (0x1UL << EXTI_EMR_MR4_Pos)
#define EXTI_EMR_MR4                        EXTI_EMR_MR4_Msk
#define EXTI_EMR_MR5_Pos                    (5U)
#define EXTI_EMR_MR5_Msk                    (0x1UL << EXTI_EMR_MR5_Pos)
#define EXTI_EMR_MR5                        EXTI_EMR_MR5_Msk
#define EXTI_EMR_MR6_Pos                    (6U)
#define EXTI_EMR_MR6_Msk                    (0x1UL << EXTI_EMR_MR6_Pos)
#define EXTI_EMR_MR6                        EXTI_EMR_MR6_Msk
#define EXTI_EMR_MR7_Pos                    (7U)
#define EXTI_EMR_MR7_Msk                    (0x1UL << EXTI_EMR_MR7_Pos)
#define EXTI_EMR_MR7                        EXTI_EMR_MR7_Msk
#define EXTI_EMR_MR8_Pos                    (8U)
#define EXTI_EMR_MR8_Msk                    (0x1UL << EXTI_EMR_MR8_Pos)
#define EXTI_EMR_MR8                        EXTI_EMR_MR8_Msk
#define EXTI_EMR_MR9_Pos                    (9U)
#define EXTI_EMR_MR9_Msk                    (0x1UL << EXTI_EMR_MR9_Pos)
#define EXTI_EMR_MR9                        EXTI_EMR_MR9_Msk
#define EXTI_EMR_MR10_Pos                   (10U)
#define EXTI_EMR_MR10_Msk                   (0x1UL << EXTI_EMR_MR10_Pos)
#define EXTI_EMR_MR10                       EXTI_EMR_MR10_Msk
#define EXTI_EMR_MR11_Pos                   (11U)
#define EXTI_EMR_MR11_Msk                   (0x1UL << EXTI_EMR_MR11_Pos)
#define EXTI_EMR_MR11                       EXTI_EMR_MR11_Msk
#define EXTI_EMR_MR12_Pos                   (12U)
#define EXTI_EMR_MR12_Msk                   (0x1UL << EXTI_EMR_MR12_Pos)
#define EXTI_EMR_MR12                       EXTI_EMR_MR12_Msk
#define EXTI_EMR_MR13_Pos                   (13U)
#define EXTI_EMR_MR13_Msk                   (0x1UL << EXTI_EMR_MR13_Pos)
#define EXTI_EMR_MR13                       EXTI_EMR_MR13_Msk
#define EXTI_EMR_MR14_Pos                   (14U)
#define EXTI_EMR_MR14_Msk                   (0x1UL << EXTI_EMR_MR14_Pos)
#define EXTI_EMR_MR14                       EXTI_EMR_MR14_Msk
#define EXTI_EMR_MR15_Pos                   (15U)
#define EXTI_EMR_MR15_Msk                   (0x1UL << EXTI_EMR_MR15_Pos)
#define EXTI_EMR_MR15                       EXTI_EMR_MR15_Msk
#define EXTI_EMR_MR16_Pos                   (16U)
#define EXTI_EMR_MR16_Msk                   (0x1UL << EXTI_EMR_MR16_Pos)
#define EXTI_EMR_MR16                       EXTI_EMR_MR16_Msk
#define EXTI_EMR_MR17_Pos                   (17U)
#define EXTI_EMR_MR17_Msk                   (0x1UL << EXTI_EMR_MR17_Pos)
#define EXTI_EMR_MR17                       EXTI_EMR_MR17_Msk
#define EXTI_EMR_MR18_Pos                   (18U)
#define EXTI_EMR_MR18_Msk                   (0x1UL << EXTI_EMR_MR18_Pos)
#define EXTI_EMR_MR18                       EXTI_EMR_MR18_Msk

#define  EXTI_EMR_EM0 EXTI_EMR_MR0
#define  EXTI_EMR_EM1 EXTI_EMR_MR1
#define  EXTI_EMR_EM2 EXTI_EMR_MR2
#define  EXTI_EMR_EM3 EXTI_EMR_MR3
#define  EXTI_EMR_EM4 EXTI_EMR_MR4
#define  EXTI_EMR_EM5 EXTI_EMR_MR5
#define  EXTI_EMR_EM6 EXTI_EMR_MR6
#define  EXTI_EMR_EM7 EXTI_EMR_MR7
#define  EXTI_EMR_EM8 EXTI_EMR_MR8
#define  EXTI_EMR_EM9 EXTI_EMR_MR9
#define  EXTI_EMR_EM10 EXTI_EMR_MR10
#define  EXTI_EMR_EM11 EXTI_EMR_MR11
#define  EXTI_EMR_EM12 EXTI_EMR_MR12
#define  EXTI_EMR_EM13 EXTI_EMR_MR13
#define  EXTI_EMR_EM14 EXTI_EMR_MR14
#define  EXTI_EMR_EM15 EXTI_EMR_MR15
#define  EXTI_EMR_EM16 EXTI_EMR_MR16
#define  EXTI_EMR_EM17 EXTI_EMR_MR17
#define  EXTI_EMR_EM18 EXTI_EMR_MR18

#define EXTI_RTSR_TR0_Pos                   (0U)
#define EXTI_RTSR_TR0_Msk                   (0x1UL << EXTI_RTSR_TR0_Pos)
#define EXTI_RTSR_TR0                       EXTI_RTSR_TR0_Msk
#define EXTI_RTSR_TR1_Pos                   (1U)
#define EXTI_RTSR_TR1_Msk                   (0x1UL << EXTI_RTSR_TR1_Pos)
#define EXTI_RTSR_TR1                       EXTI_RTSR_TR1_Msk
#define EXTI_RTSR_TR2_Pos                   (2U)
#define EXTI_RTSR_TR2_Msk                   (0x1UL << EXTI_RTSR_TR2_Pos)
#define EXTI_RTSR_TR2                       EXTI_RTSR_TR2_Msk
#define EXTI_RTSR_TR3_Pos                   (3U)
#define EXTI_RTSR_TR3_Msk                   (0x1UL << EXTI_RTSR_TR3_Pos)
#define EXTI_RTSR_TR3                       EXTI_RTSR_TR3_Msk
#define EXTI_RTSR_TR4_Pos                   (4U)
#define EXTI_RTSR_TR4_Msk                   (0x1UL << EXTI_RTSR_TR4_Pos)
#define EXTI_RTSR_TR4                       EXTI_RTSR_TR4_Msk
#define EXTI_RTSR_TR5_Pos                   (5U)
#define EXTI_RTSR_TR5_Msk                   (0x1UL << EXTI_RTSR_TR5_Pos)
#define EXTI_RTSR_TR5                       EXTI_RTSR_TR5_Msk
#define EXTI_RTSR_TR6_Pos                   (6U)
#define EXTI_RTSR_TR6_Msk                   (0x1UL << EXTI_RTSR_TR6_Pos)
#define EXTI_RTSR_TR6                       EXTI_RTSR_TR6_Msk
#define EXTI_RTSR_TR7_Pos                   (7U)
#define EXTI_RTSR_TR7_Msk                   (0x1UL << EXTI_RTSR_TR7_Pos)
#define EXTI_RTSR_TR7                       EXTI_RTSR_TR7_Msk
#define EXTI_RTSR_TR8_Pos                   (8U)
#define EXTI_RTSR_TR8_Msk                   (0x1UL << EXTI_RTSR_TR8_Pos)
#define EXTI_RTSR_TR8                       EXTI_RTSR_TR8_Msk
#define EXTI_RTSR_TR9_Pos                   (9U)
#define EXTI_RTSR_TR9_Msk                   (0x1UL << EXTI_RTSR_TR9_Pos)
#define EXTI_RTSR_TR9                       EXTI_RTSR_TR9_Msk
#define EXTI_RTSR_TR10_Pos                  (10U)
#define EXTI_RTSR_TR10_Msk                  (0x1UL << EXTI_RTSR_TR10_Pos)
#define EXTI_RTSR_TR10                      EXTI_RTSR_TR10_Msk
#define EXTI_RTSR_TR11_Pos                  (11U)
#define EXTI_RTSR_TR11_Msk                  (0x1UL << EXTI_RTSR_TR11_Pos)
#define EXTI_RTSR_TR11                      EXTI_RTSR_TR11_Msk
#define EXTI_RTSR_TR12_Pos                  (12U)
#define EXTI_RTSR_TR12_Msk                  (0x1UL << EXTI_RTSR_TR12_Pos)
#define EXTI_RTSR_TR12                      EXTI_RTSR_TR12_Msk
#define EXTI_RTSR_TR13_Pos                  (13U)
#define EXTI_RTSR_TR13_Msk                  (0x1UL << EXTI_RTSR_TR13_Pos)
#define EXTI_RTSR_TR13                      EXTI_RTSR_TR13_Msk
#define EXTI_RTSR_TR14_Pos                  (14U)
#define EXTI_RTSR_TR14_Msk                  (0x1UL << EXTI_RTSR_TR14_Pos)
#define EXTI_RTSR_TR14                      EXTI_RTSR_TR14_Msk
#define EXTI_RTSR_TR15_Pos                  (15U)
#define EXTI_RTSR_TR15_Msk                  (0x1UL << EXTI_RTSR_TR15_Pos)
#define EXTI_RTSR_TR15                      EXTI_RTSR_TR15_Msk
#define EXTI_RTSR_TR16_Pos                  (16U)
#define EXTI_RTSR_TR16_Msk                  (0x1UL << EXTI_RTSR_TR16_Pos)
#define EXTI_RTSR_TR16                      EXTI_RTSR_TR16_Msk
#define EXTI_RTSR_TR17_Pos                  (17U)
#define EXTI_RTSR_TR17_Msk                  (0x1UL << EXTI_RTSR_TR17_Pos)
#define EXTI_RTSR_TR17                      EXTI_RTSR_TR17_Msk
#define EXTI_RTSR_TR18_Pos                  (18U)
#define EXTI_RTSR_TR18_Msk                  (0x1UL << EXTI_RTSR_TR18_Pos)
#define EXTI_RTSR_TR18                      EXTI_RTSR_TR18_Msk

#define  EXTI_RTSR_RT0 EXTI_RTSR_TR0
#define  EXTI_RTSR_RT1 EXTI_RTSR_TR1
#define  EXTI_RTSR_RT2 EXTI_RTSR_TR2
#define  EXTI_RTSR_RT3 EXTI_RTSR_TR3
#define  EXTI_RTSR_RT4 EXTI_RTSR_TR4
#define  EXTI_RTSR_RT5 EXTI_RTSR_TR5
#define  EXTI_RTSR_RT6 EXTI_RTSR_TR6
#define  EXTI_RTSR_RT7 EXTI_RTSR_TR7
#define  EXTI_RTSR_RT8 EXTI_RTSR_TR8
#define  EXTI_RTSR_RT9 EXTI_RTSR_TR9
#define  EXTI_RTSR_RT10 EXTI_RTSR_TR10
#define  EXTI_RTSR_RT11 EXTI_RTSR_TR11
#define  EXTI_RTSR_RT12 EXTI_RTSR_TR12
#define  EXTI_RTSR_RT13 EXTI_RTSR_TR13
#define  EXTI_RTSR_RT14 EXTI_RTSR_TR14
#define  EXTI_RTSR_RT15 EXTI_RTSR_TR15
#define  EXTI_RTSR_RT16 EXTI_RTSR_TR16
#define  EXTI_RTSR_RT17 EXTI_RTSR_TR17
#define  EXTI_RTSR_RT18 EXTI_RTSR_TR18

#define EXTI_FTSR_TR0_Pos                   (0U)
#define EXTI_FTSR_TR0_Msk                   (0x1UL << EXTI_FTSR_TR0_Pos)
#define EXTI_FTSR_TR0                       EXTI_FTSR_TR0_Msk
#define EXTI_FTSR_TR1_Pos                   (1U)
#define EXTI_FTSR_TR1_Msk                   (0x1UL << EXTI_FTSR_TR1_Pos)
#define EXTI_FTSR_TR1                       EXTI_FTSR_TR1_Msk
#define EXTI_FTSR_TR2_Pos                   (2U)
#define EXTI_FTSR_TR2_Msk                   (0x1UL << EXTI_FTSR_TR2_Pos)
#define EXTI_FTSR_TR2                       EXTI_FTSR_TR2_Msk
#define EXTI_FTSR_TR3_Pos                   (3U)
#define EXTI_FTSR_TR3_Msk                   (0x1UL << EXTI_FTSR_TR3_Pos)
#define EXTI_FTSR_TR3                       EXTI_FTSR_TR3_Msk
#define EXTI_FTSR_TR4_Pos                   (4U)
#define EXTI_FTSR_TR4_Msk                   (0x1UL << EXTI_FTSR_TR4_Pos)
#define EXTI_FTSR_TR4                       EXTI_FTSR_TR4_Msk
#define EXTI_FTSR_TR5_Pos                   (5U)
#define EXTI_FTSR_TR5_Msk                   (0x1UL << EXTI_FTSR_TR5_Pos)
#define EXTI_FTSR_TR5                       EXTI_FTSR_TR5_Msk
#define EXTI_FTSR_TR6_Pos                   (6U)
#define EXTI_FTSR_TR6_Msk                   (0x1UL << EXTI_FTSR_TR6_Pos)
#define EXTI_FTSR_TR6                       EXTI_FTSR_TR6_Msk
#define EXTI_FTSR_TR7_Pos                   (7U)
#define EXTI_FTSR_TR7_Msk                   (0x1UL << EXTI_FTSR_TR7_Pos)
#define EXTI_FTSR_TR7                       EXTI_FTSR_TR7_Msk
#define EXTI_FTSR_TR8_Pos                   (8U)
#define EXTI_FTSR_TR8_Msk                   (0x1UL << EXTI_FTSR_TR8_Pos)
#define EXTI_FTSR_TR8                       EXTI_FTSR_TR8_Msk
#define EXTI_FTSR_TR9_Pos                   (9U)
#define EXTI_FTSR_TR9_Msk                   (0x1UL << EXTI_FTSR_TR9_Pos)
#define EXTI_FTSR_TR9                       EXTI_FTSR_TR9_Msk
#define EXTI_FTSR_TR10_Pos                  (10U)
#define EXTI_FTSR_TR10_Msk                  (0x1UL << EXTI_FTSR_TR10_Pos)
#define EXTI_FTSR_TR10                      EXTI_FTSR_TR10_Msk
#define EXTI_FTSR_TR11_Pos                  (11U)
#define EXTI_FTSR_TR11_Msk                  (0x1UL << EXTI_FTSR_TR11_Pos)
#define EXTI_FTSR_TR11                      EXTI_FTSR_TR11_Msk
#define EXTI_FTSR_TR12_Pos                  (12U)
#define EXTI_FTSR_TR12_Msk                  (0x1UL << EXTI_FTSR_TR12_Pos)
#define EXTI_FTSR_TR12                      EXTI_FTSR_TR12_Msk
#define EXTI_FTSR_TR13_Pos                  (13U)
#define EXTI_FTSR_TR13_Msk                  (0x1UL << EXTI_FTSR_TR13_Pos)
#define EXTI_FTSR_TR13                      EXTI_FTSR_TR13_Msk
#define EXTI_FTSR_TR14_Pos                  (14U)
#define EXTI_FTSR_TR14_Msk                  (0x1UL << EXTI_FTSR_TR14_Pos)
#define EXTI_FTSR_TR14                      EXTI_FTSR_TR14_Msk
#define EXTI_FTSR_TR15_Pos                  (15U)
#define EXTI_FTSR_TR15_Msk                  (0x1UL << EXTI_FTSR_TR15_Pos)
#define EXTI_FTSR_TR15                      EXTI_FTSR_TR15_Msk
#define EXTI_FTSR_TR16_Pos                  (16U)
#define EXTI_FTSR_TR16_Msk                  (0x1UL << EXTI_FTSR_TR16_Pos)
#define EXTI_FTSR_TR16                      EXTI_FTSR_TR16_Msk
#define EXTI_FTSR_TR17_Pos                  (17U)
#define EXTI_FTSR_TR17_Msk                  (0x1UL << EXTI_FTSR_TR17_Pos)
#define EXTI_FTSR_TR17                      EXTI_FTSR_TR17_Msk
#define EXTI_FTSR_TR18_Pos                  (18U)
#define EXTI_FTSR_TR18_Msk                  (0x1UL << EXTI_FTSR_TR18_Pos)
#define EXTI_FTSR_TR18                      EXTI_FTSR_TR18_Msk

#define  EXTI_FTSR_FT0 EXTI_FTSR_TR0
#define  EXTI_FTSR_FT1 EXTI_FTSR_TR1
#define  EXTI_FTSR_FT2 EXTI_FTSR_TR2
#define  EXTI_FTSR_FT3 EXTI_FTSR_TR3
#define  EXTI_FTSR_FT4 EXTI_FTSR_TR4
#define  EXTI_FTSR_FT5 EXTI_FTSR_TR5
#define  EXTI_FTSR_FT6 EXTI_FTSR_TR6
#define  EXTI_FTSR_FT7 EXTI_FTSR_TR7
#define  EXTI_FTSR_FT8 EXTI_FTSR_TR8
#define  EXTI_FTSR_FT9 EXTI_FTSR_TR9
#define  EXTI_FTSR_FT10 EXTI_FTSR_TR10
#define  EXTI_FTSR_FT11 EXTI_FTSR_TR11
#define  EXTI_FTSR_FT12 EXTI_FTSR_TR12
#define  EXTI_FTSR_FT13 EXTI_FTSR_TR13
#define  EXTI_FTSR_FT14 EXTI_FTSR_TR14
#define  EXTI_FTSR_FT15 EXTI_FTSR_TR15
#define  EXTI_FTSR_FT16 EXTI_FTSR_TR16
#define  EXTI_FTSR_FT17 EXTI_FTSR_TR17
#define  EXTI_FTSR_FT18 EXTI_FTSR_TR18

#define EXTI_SWIER_SWIER0_Pos               (0U)
#define EXTI_SWIER_SWIER0_Msk               (0x1UL << EXTI_SWIER_SWIER0_Pos)
#define EXTI_SWIER_SWIER0                   EXTI_SWIER_SWIER0_Msk
#define EXTI_SWIER_SWIER1_Pos               (1U)
#define EXTI_SWIER_SWIER1_Msk               (0x1UL << EXTI_SWIER_SWIER1_Pos)
#define EXTI_SWIER_SWIER1                   EXTI_SWIER_SWIER1_Msk
#define EXTI_SWIER_SWIER2_Pos               (2U)
#define EXTI_SWIER_SWIER2_Msk               (0x1UL << EXTI_SWIER_SWIER2_Pos)
#define EXTI_SWIER_SWIER2                   EXTI_SWIER_SWIER2_Msk
#define EXTI_SWIER_SWIER3_Pos               (3U)
#define EXTI_SWIER_SWIER3_Msk               (0x1UL << EXTI_SWIER_SWIER3_Pos)
#define EXTI_SWIER_SWIER3                   EXTI_SWIER_SWIER3_Msk
#define EXTI_SWIER_SWIER4_Pos               (4U)
#define EXTI_SWIER_SWIER4_Msk               (0x1UL << EXTI_SWIER_SWIER4_Pos)
#define EXTI_SWIER_SWIER4                   EXTI_SWIER_SWIER4_Msk
#define EXTI_SWIER_SWIER5_Pos               (5U)
#define EXTI_SWIER_SWIER5_Msk               (0x1UL << EXTI_SWIER_SWIER5_Pos)
#define EXTI_SWIER_SWIER5                   EXTI_SWIER_SWIER5_Msk
#define EXTI_SWIER_SWIER6_Pos               (6U)
#define EXTI_SWIER_SWIER6_Msk               (0x1UL << EXTI_SWIER_SWIER6_Pos)
#define EXTI_SWIER_SWIER6                   EXTI_SWIER_SWIER6_Msk
#define EXTI_SWIER_SWIER7_Pos               (7U)
#define EXTI_SWIER_SWIER7_Msk               (0x1UL << EXTI_SWIER_SWIER7_Pos)
#define EXTI_SWIER_SWIER7                   EXTI_SWIER_SWIER7_Msk
#define EXTI_SWIER_SWIER8_Pos               (8U)
#define EXTI_SWIER_SWIER8_Msk               (0x1UL << EXTI_SWIER_SWIER8_Pos)
#define EXTI_SWIER_SWIER8                   EXTI_SWIER_SWIER8_Msk
#define EXTI_SWIER_SWIER9_Pos               (9U)
#define EXTI_SWIER_SWIER9_Msk               (0x1UL << EXTI_SWIER_SWIER9_Pos)
#define EXTI_SWIER_SWIER9                   EXTI_SWIER_SWIER9_Msk
#define EXTI_SWIER_SWIER10_Pos              (10U)
#define EXTI_SWIER_SWIER10_Msk              (0x1UL << EXTI_SWIER_SWIER10_Pos)
#define EXTI_SWIER_SWIER10                  EXTI_SWIER_SWIER10_Msk
#define EXTI_SWIER_SWIER11_Pos              (11U)
#define EXTI_SWIER_SWIER11_Msk              (0x1UL << EXTI_SWIER_SWIER11_Pos)
#define EXTI_SWIER_SWIER11                  EXTI_SWIER_SWIER11_Msk
#define EXTI_SWIER_SWIER12_Pos              (12U)
#define EXTI_SWIER_SWIER12_Msk              (0x1UL << EXTI_SWIER_SWIER12_Pos)
#define EXTI_SWIER_SWIER12                  EXTI_SWIER_SWIER12_Msk
#define EXTI_SWIER_SWIER13_Pos              (13U)
#define EXTI_SWIER_SWIER13_Msk              (0x1UL << EXTI_SWIER_SWIER13_Pos)
#define EXTI_SWIER_SWIER13                  EXTI_SWIER_SWIER13_Msk
#define EXTI_SWIER_SWIER14_Pos              (14U)
#define EXTI_SWIER_SWIER14_Msk              (0x1UL << EXTI_SWIER_SWIER14_Pos)
#define EXTI_SWIER_SWIER14                  EXTI_SWIER_SWIER14_Msk
#define EXTI_SWIER_SWIER15_Pos              (15U)
#define EXTI_SWIER_SWIER15_Msk              (0x1UL << EXTI_SWIER_SWIER15_Pos)
#define EXTI_SWIER_SWIER15                  EXTI_SWIER_SWIER15_Msk
#define EXTI_SWIER_SWIER16_Pos              (16U)
#define EXTI_SWIER_SWIER16_Msk              (0x1UL << EXTI_SWIER_SWIER16_Pos)
#define EXTI_SWIER_SWIER16                  EXTI_SWIER_SWIER16_Msk
#define EXTI_SWIER_SWIER17_Pos              (17U)
#define EXTI_SWIER_SWIER17_Msk              (0x1UL << EXTI_SWIER_SWIER17_Pos)
#define EXTI_SWIER_SWIER17                  EXTI_SWIER_SWIER17_Msk
#define EXTI_SWIER_SWIER18_Pos              (18U)
#define EXTI_SWIER_SWIER18_Msk              (0x1UL << EXTI_SWIER_SWIER18_Pos)
#define EXTI_SWIER_SWIER18                  EXTI_SWIER_SWIER18_Msk

#define  EXTI_SWIER_SWI0 EXTI_SWIER_SWIER0
#define  EXTI_SWIER_SWI1 EXTI_SWIER_SWIER1
#define  EXTI_SWIER_SWI2 EXTI_SWIER_SWIER2
#define  EXTI_SWIER_SWI3 EXTI_SWIER_SWIER3
#define  EXTI_SWIER_SWI4 EXTI_SWIER_SWIER4
#define  EXTI_SWIER_SWI5 EXTI_SWIER_SWIER5
#define  EXTI_SWIER_SWI6 EXTI_SWIER_SWIER6
#define  EXTI_SWIER_SWI7 EXTI_SWIER_SWIER7
#define  EXTI_SWIER_SWI8 EXTI_SWIER_SWIER8
#define  EXTI_SWIER_SWI9 EXTI_SWIER_SWIER9
#define  EXTI_SWIER_SWI10 EXTI_SWIER_SWIER10
#define  EXTI_SWIER_SWI11 EXTI_SWIER_SWIER11
#define  EXTI_SWIER_SWI12 EXTI_SWIER_SWIER12
#define  EXTI_SWIER_SWI13 EXTI_SWIER_SWIER13
#define  EXTI_SWIER_SWI14 EXTI_SWIER_SWIER14
#define  EXTI_SWIER_SWI15 EXTI_SWIER_SWIER15
#define  EXTI_SWIER_SWI16 EXTI_SWIER_SWIER16
#define  EXTI_SWIER_SWI17 EXTI_SWIER_SWIER17
#define  EXTI_SWIER_SWI18 EXTI_SWIER_SWIER18

#define EXTI_PR_PR0_Pos                     (0U)
#define EXTI_PR_PR0_Msk                     (0x1UL << EXTI_PR_PR0_Pos)
#define EXTI_PR_PR0                         EXTI_PR_PR0_Msk
#define EXTI_PR_PR1_Pos                     (1U)
#define EXTI_PR_PR1_Msk                     (0x1UL << EXTI_PR_PR1_Pos)
#define EXTI_PR_PR1                         EXTI_PR_PR1_Msk
#define EXTI_PR_PR2_Pos                     (2U)
#define EXTI_PR_PR2_Msk                     (0x1UL << EXTI_PR_PR2_Pos)
#define EXTI_PR_PR2                         EXTI_PR_PR2_Msk
#define EXTI_PR_PR3_Pos                     (3U)
#define EXTI_PR_PR3_Msk                     (0x1UL << EXTI_PR_PR3_Pos)
#define EXTI_PR_PR3                         EXTI_PR_PR3_Msk
#define EXTI_PR_PR4_Pos                     (4U)
#define EXTI_PR_PR4_Msk                     (0x1UL << EXTI_PR_PR4_Pos)
#define EXTI_PR_PR4                         EXTI_PR_PR4_Msk
#define EXTI_PR_PR5_Pos                     (5U)
#define EXTI_PR_PR5_Msk                     (0x1UL << EXTI_PR_PR5_Pos)
#define EXTI_PR_PR5                         EXTI_PR_PR5_Msk
#define EXTI_PR_PR6_Pos                     (6U)
#define EXTI_PR_PR6_Msk                     (0x1UL << EXTI_PR_PR6_Pos)
#define EXTI_PR_PR6                         EXTI_PR_PR6_Msk
#define EXTI_PR_PR7_Pos                     (7U)
#define EXTI_PR_PR7_Msk                     (0x1UL << EXTI_PR_PR7_Pos)
#define EXTI_PR_PR7                         EXTI_PR_PR7_Msk
#define EXTI_PR_PR8_Pos                     (8U)
#define EXTI_PR_PR8_Msk                     (0x1UL << EXTI_PR_PR8_Pos)
#define EXTI_PR_PR8                         EXTI_PR_PR8_Msk
#define EXTI_PR_PR9_Pos                     (9U)
#define EXTI_PR_PR9_Msk                     (0x1UL << EXTI_PR_PR9_Pos)
#define EXTI_PR_PR9                         EXTI_PR_PR9_Msk
#define EXTI_PR_PR10_Pos                    (10U)
#define EXTI_PR_PR10_Msk                    (0x1UL << EXTI_PR_PR10_Pos)
#define EXTI_PR_PR10                        EXTI_PR_PR10_Msk
#define EXTI_PR_PR11_Pos                    (11U)
#define EXTI_PR_PR11_Msk                    (0x1UL << EXTI_PR_PR11_Pos)
#define EXTI_PR_PR11                        EXTI_PR_PR11_Msk
#define EXTI_PR_PR12_Pos                    (12U)
#define EXTI_PR_PR12_Msk                    (0x1UL << EXTI_PR_PR12_Pos)
#define EXTI_PR_PR12                        EXTI_PR_PR12_Msk
#define EXTI_PR_PR13_Pos                    (13U)
#define EXTI_PR_PR13_Msk                    (0x1UL << EXTI_PR_PR13_Pos)
#define EXTI_PR_PR13                        EXTI_PR_PR13_Msk
#define EXTI_PR_PR14_Pos                    (14U)
#define EXTI_PR_PR14_Msk                    (0x1UL << EXTI_PR_PR14_Pos)
#define EXTI_PR_PR14                        EXTI_PR_PR14_Msk
#define EXTI_PR_PR15_Pos                    (15U)
#define EXTI_PR_PR15_Msk                    (0x1UL << EXTI_PR_PR15_Pos)
#define EXTI_PR_PR15                        EXTI_PR_PR15_Msk
#define EXTI_PR_PR16_Pos                    (16U)
#define EXTI_PR_PR16_Msk                    (0x1UL << EXTI_PR_PR16_Pos)
#define EXTI_PR_PR16                        EXTI_PR_PR16_Msk
#define EXTI_PR_PR17_Pos                    (17U)
#define EXTI_PR_PR17_Msk                    (0x1UL << EXTI_PR_PR17_Pos)
#define EXTI_PR_PR17                        EXTI_PR_PR17_Msk
#define EXTI_PR_PR18_Pos                    (18U)
#define EXTI_PR_PR18_Msk                    (0x1UL << EXTI_PR_PR18_Pos)
#define EXTI_PR_PR18                        EXTI_PR_PR18_Msk

#define  EXTI_PR_PIF0 EXTI_PR_PR0
#define  EXTI_PR_PIF1 EXTI_PR_PR1
#define  EXTI_PR_PIF2 EXTI_PR_PR2
#define  EXTI_PR_PIF3 EXTI_PR_PR3
#define  EXTI_PR_PIF4 EXTI_PR_PR4
#define  EXTI_PR_PIF5 EXTI_PR_PR5
#define  EXTI_PR_PIF6 EXTI_PR_PR6
#define  EXTI_PR_PIF7 EXTI_PR_PR7
#define  EXTI_PR_PIF8 EXTI_PR_PR8
#define  EXTI_PR_PIF9 EXTI_PR_PR9
#define  EXTI_PR_PIF10 EXTI_PR_PR10
#define  EXTI_PR_PIF11 EXTI_PR_PR11
#define  EXTI_PR_PIF12 EXTI_PR_PR12
#define  EXTI_PR_PIF13 EXTI_PR_PR13
#define  EXTI_PR_PIF14 EXTI_PR_PR14
#define  EXTI_PR_PIF15 EXTI_PR_PR15
#define  EXTI_PR_PIF16 EXTI_PR_PR16
#define  EXTI_PR_PIF17 EXTI_PR_PR17
#define  EXTI_PR_PIF18 EXTI_PR_PR18

#define DMA_ISR_GIF1_Pos                    (0U)
#define DMA_ISR_GIF1_Msk                    (0x1UL << DMA_ISR_GIF1_Pos)
#define DMA_ISR_GIF1                        DMA_ISR_GIF1_Msk
#define DMA_ISR_TCIF1_Pos                   (1U)
#define DMA_ISR_TCIF1_Msk                   (0x1UL << DMA_ISR_TCIF1_Pos)
#define DMA_ISR_TCIF1                       DMA_ISR_TCIF1_Msk
#define DMA_ISR_HTIF1_Pos                   (2U)
#define DMA_ISR_HTIF1_Msk                   (0x1UL << DMA_ISR_HTIF1_Pos)
#define DMA_ISR_HTIF1                       DMA_ISR_HTIF1_Msk
#define DMA_ISR_TEIF1_Pos                   (3U)
#define DMA_ISR_TEIF1_Msk                   (0x1UL << DMA_ISR_TEIF1_Pos)
#define DMA_ISR_TEIF1                       DMA_ISR_TEIF1_Msk
#define DMA_ISR_GIF2_Pos                    (4U)
#define DMA_ISR_GIF2_Msk                    (0x1UL << DMA_ISR_GIF2_Pos)
#define DMA_ISR_GIF2                        DMA_ISR_GIF2_Msk
#define DMA_ISR_TCIF2_Pos                   (5U)
#define DMA_ISR_TCIF2_Msk                   (0x1UL << DMA_ISR_TCIF2_Pos)
#define DMA_ISR_TCIF2                       DMA_ISR_TCIF2_Msk
#define DMA_ISR_HTIF2_Pos                   (6U)
#define DMA_ISR_HTIF2_Msk                   (0x1UL << DMA_ISR_HTIF2_Pos)
#define DMA_ISR_HTIF2                       DMA_ISR_HTIF2_Msk
#define DMA_ISR_TEIF2_Pos                   (7U)
#define DMA_ISR_TEIF2_Msk                   (0x1UL << DMA_ISR_TEIF2_Pos)
#define DMA_ISR_TEIF2                       DMA_ISR_TEIF2_Msk
#define DMA_ISR_GIF3_Pos                    (8U)
#define DMA_ISR_GIF3_Msk                    (0x1UL << DMA_ISR_GIF3_Pos)
#define DMA_ISR_GIF3                        DMA_ISR_GIF3_Msk
#define DMA_ISR_TCIF3_Pos                   (9U)
#define DMA_ISR_TCIF3_Msk                   (0x1UL << DMA_ISR_TCIF3_Pos)
#define DMA_ISR_TCIF3                       DMA_ISR_TCIF3_Msk
#define DMA_ISR_HTIF3_Pos                   (10U)
#define DMA_ISR_HTIF3_Msk                   (0x1UL << DMA_ISR_HTIF3_Pos)
#define DMA_ISR_HTIF3                       DMA_ISR_HTIF3_Msk
#define DMA_ISR_TEIF3_Pos                   (11U)
#define DMA_ISR_TEIF3_Msk                   (0x1UL << DMA_ISR_TEIF3_Pos)
#define DMA_ISR_TEIF3                       DMA_ISR_TEIF3_Msk
#define DMA_ISR_GIF4_Pos                    (12U)
#define DMA_ISR_GIF4_Msk                    (0x1UL << DMA_ISR_GIF4_Pos)
#define DMA_ISR_GIF4                        DMA_ISR_GIF4_Msk
#define DMA_ISR_TCIF4_Pos                   (13U)
#define DMA_ISR_TCIF4_Msk                   (0x1UL << DMA_ISR_TCIF4_Pos)
#define DMA_ISR_TCIF4                       DMA_ISR_TCIF4_Msk
#define DMA_ISR_HTIF4_Pos                   (14U)
#define DMA_ISR_HTIF4_Msk                   (0x1UL << DMA_ISR_HTIF4_Pos)
#define DMA_ISR_HTIF4                       DMA_ISR_HTIF4_Msk
#define DMA_ISR_TEIF4_Pos                   (15U)
#define DMA_ISR_TEIF4_Msk                   (0x1UL << DMA_ISR_TEIF4_Pos)
#define DMA_ISR_TEIF4                       DMA_ISR_TEIF4_Msk
#define DMA_ISR_GIF5_Pos                    (16U)
#define DMA_ISR_GIF5_Msk                    (0x1UL << DMA_ISR_GIF5_Pos)
#define DMA_ISR_GIF5                        DMA_ISR_GIF5_Msk
#define DMA_ISR_TCIF5_Pos                   (17U)
#define DMA_ISR_TCIF5_Msk                   (0x1UL << DMA_ISR_TCIF5_Pos)
#define DMA_ISR_TCIF5                       DMA_ISR_TCIF5_Msk
#define DMA_ISR_HTIF5_Pos                   (18U)
#define DMA_ISR_HTIF5_Msk                   (0x1UL << DMA_ISR_HTIF5_Pos)
#define DMA_ISR_HTIF5                       DMA_ISR_HTIF5_Msk
#define DMA_ISR_TEIF5_Pos                   (19U)
#define DMA_ISR_TEIF5_Msk                   (0x1UL << DMA_ISR_TEIF5_Pos)
#define DMA_ISR_TEIF5                       DMA_ISR_TEIF5_Msk
#define DMA_ISR_GIF6_Pos                    (20U)
#define DMA_ISR_GIF6_Msk                    (0x1UL << DMA_ISR_GIF6_Pos)
#define DMA_ISR_GIF6                        DMA_ISR_GIF6_Msk
#define DMA_ISR_TCIF6_Pos                   (21U)
#define DMA_ISR_TCIF6_Msk                   (0x1UL << DMA_ISR_TCIF6_Pos)
#define DMA_ISR_TCIF6                       DMA_ISR_TCIF6_Msk
#define DMA_ISR_HTIF6_Pos                   (22U)
#define DMA_ISR_HTIF6_Msk                   (0x1UL << DMA_ISR_HTIF6_Pos)
#define DMA_ISR_HTIF6                       DMA_ISR_HTIF6_Msk
#define DMA_ISR_TEIF6_Pos                   (23U)
#define DMA_ISR_TEIF6_Msk                   (0x1UL << DMA_ISR_TEIF6_Pos)
#define DMA_ISR_TEIF6                       DMA_ISR_TEIF6_Msk
#define DMA_ISR_GIF7_Pos                    (24U)
#define DMA_ISR_GIF7_Msk                    (0x1UL << DMA_ISR_GIF7_Pos)
#define DMA_ISR_GIF7                        DMA_ISR_GIF7_Msk
#define DMA_ISR_TCIF7_Pos                   (25U)
#define DMA_ISR_TCIF7_Msk                   (0x1UL << DMA_ISR_TCIF7_Pos)
#define DMA_ISR_TCIF7                       DMA_ISR_TCIF7_Msk
#define DMA_ISR_HTIF7_Pos                   (26U)
#define DMA_ISR_HTIF7_Msk                   (0x1UL << DMA_ISR_HTIF7_Pos)
#define DMA_ISR_HTIF7                       DMA_ISR_HTIF7_Msk
#define DMA_ISR_TEIF7_Pos                   (27U)
#define DMA_ISR_TEIF7_Msk                   (0x1UL << DMA_ISR_TEIF7_Pos)
#define DMA_ISR_TEIF7                       DMA_ISR_TEIF7_Msk

#define DMA_IFCR_CGIF1_Pos                  (0U)
#define DMA_IFCR_CGIF1_Msk                  (0x1UL << DMA_IFCR_CGIF1_Pos)
#define DMA_IFCR_CGIF1                      DMA_IFCR_CGIF1_Msk
#define DMA_IFCR_CTCIF1_Pos                 (1U)
#define DMA_IFCR_CTCIF1_Msk                 (0x1UL << DMA_IFCR_CTCIF1_Pos)
#define DMA_IFCR_CTCIF1                     DMA_IFCR_CTCIF1_Msk
#define DMA_IFCR_CHTIF1_Pos                 (2U)
#define DMA_IFCR_CHTIF1_Msk                 (0x1UL << DMA_IFCR_CHTIF1_Pos)
#define DMA_IFCR_CHTIF1                     DMA_IFCR_CHTIF1_Msk
#define DMA_IFCR_CTEIF1_Pos                 (3U)
#define DMA_IFCR_CTEIF1_Msk                 (0x1UL << DMA_IFCR_CTEIF1_Pos)
#define DMA_IFCR_CTEIF1                     DMA_IFCR_CTEIF1_Msk
#define DMA_IFCR_CGIF2_Pos                  (4U)
#define DMA_IFCR_CGIF2_Msk                  (0x1UL << DMA_IFCR_CGIF2_Pos)
#define DMA_IFCR_CGIF2                      DMA_IFCR_CGIF2_Msk
#define DMA_IFCR_CTCIF2_Pos                 (5U)
#define DMA_IFCR_CTCIF2_Msk                 (0x1UL << DMA_IFCR_CTCIF2_Pos)
#define DMA_IFCR_CTCIF2                     DMA_IFCR_CTCIF2_Msk
#define DMA_IFCR_CHTIF2_Pos                 (6U)
#define DMA_IFCR_CHTIF2_Msk                 (0x1UL << DMA_IFCR_CHTIF2_Pos)
#define DMA_IFCR_CHTIF2                     DMA_IFCR_CHTIF2_Msk
#define DMA_IFCR_CTEIF2_Pos                 (7U)
#define DMA_IFCR_CTEIF2_Msk                 (0x1UL << DMA_IFCR_CTEIF2_Pos)
#define DMA_IFCR_CTEIF2                     DMA_IFCR_CTEIF2_Msk
#define DMA_IFCR_CGIF3_Pos                  (8U)
#define DMA_IFCR_CGIF3_Msk                  (0x1UL << DMA_IFCR_CGIF3_Pos)
#define DMA_IFCR_CGIF3                      DMA_IFCR_CGIF3_Msk
#define DMA_IFCR_CTCIF3_Pos                 (9U)
#define DMA_IFCR_CTCIF3_Msk                 (0x1UL << DMA_IFCR_CTCIF3_Pos)
#define DMA_IFCR_CTCIF3                     DMA_IFCR_CTCIF3_Msk
#define DMA_IFCR_CHTIF3_Pos                 (10U)
#define DMA_IFCR_CHTIF3_Msk                 (0x1UL << DMA_IFCR_CHTIF3_Pos)
#define DMA_IFCR_CHTIF3                     DMA_IFCR_CHTIF3_Msk
#define DMA_IFCR_CTEIF3_Pos                 (11U)
#define DMA_IFCR_CTEIF3_Msk                 (0x1UL << DMA_IFCR_CTEIF3_Pos)
#define DMA_IFCR_CTEIF3                     DMA_IFCR_CTEIF3_Msk
#define DMA_IFCR_CGIF4_Pos                  (12U)
#define DMA_IFCR_CGIF4_Msk                  (0x1UL << DMA_IFCR_CGIF4_Pos)
#define DMA_IFCR_CGIF4                      DMA_IFCR_CGIF4_Msk
#define DMA_IFCR_CTCIF4_Pos                 (13U)
#define DMA_IFCR_CTCIF4_Msk                 (0x1UL << DMA_IFCR_CTCIF4_Pos)
#define DMA_IFCR_CTCIF4                     DMA_IFCR_CTCIF4_Msk
#define DMA_IFCR_CHTIF4_Pos                 (14U)
#define DMA_IFCR_CHTIF4_Msk                 (0x1UL << DMA_IFCR_CHTIF4_Pos)
#define DMA_IFCR_CHTIF4                     DMA_IFCR_CHTIF4_Msk
#define DMA_IFCR_CTEIF4_Pos                 (15U)
#define DMA_IFCR_CTEIF4_Msk                 (0x1UL << DMA_IFCR_CTEIF4_Pos)
#define DMA_IFCR_CTEIF4                     DMA_IFCR_CTEIF4_Msk
#define DMA_IFCR_CGIF5_Pos                  (16U)
#define DMA_IFCR_CGIF5_Msk                  (0x1UL << DMA_IFCR_CGIF5_Pos)
#define DMA_IFCR_CGIF5                      DMA_IFCR_CGIF5_Msk
#define DMA_IFCR_CTCIF5_Pos                 (17U)
#define DMA_IFCR_CTCIF5_Msk                 (0x1UL << DMA_IFCR_CTCIF5_Pos)
#define DMA_IFCR_CTCIF5                     DMA_IFCR_CTCIF5_Msk
#define DMA_IFCR_CHTIF5_Pos                 (18U)
#define DMA_IFCR_CHTIF5_Msk                 (0x1UL << DMA_IFCR_CHTIF5_Pos)
#define DMA_IFCR_CHTIF5                     DMA_IFCR_CHTIF5_Msk
#define DMA_IFCR_CTEIF5_Pos                 (19U)
#define DMA_IFCR_CTEIF5_Msk                 (0x1UL << DMA_IFCR_CTEIF5_Pos)
#define DMA_IFCR_CTEIF5                     DMA_IFCR_CTEIF5_Msk
#define DMA_IFCR_CGIF6_Pos                  (20U)
#define DMA_IFCR_CGIF6_Msk                  (0x1UL << DMA_IFCR_CGIF6_Pos)
#define DMA_IFCR_CGIF6                      DMA_IFCR_CGIF6_Msk
#define DMA_IFCR_CTCIF6_Pos                 (21U)
#define DMA_IFCR_CTCIF6_Msk                 (0x1UL << DMA_IFCR_CTCIF6_Pos)
#define DMA_IFCR_CTCIF6                     DMA_IFCR_CTCIF6_Msk
#define DMA_IFCR_CHTIF6_Pos                 (22U)
#define DMA_IFCR_CHTIF6_Msk                 (0x1UL << DMA_IFCR_CHTIF6_Pos)
#define DMA_IFCR_CHTIF6                     DMA_IFCR_CHTIF6_Msk
#define DMA_IFCR_CTEIF6_Pos                 (23U)
#define DMA_IFCR_CTEIF6_Msk                 (0x1UL << DMA_IFCR_CTEIF6_Pos)
#define DMA_IFCR_CTEIF6                     DMA_IFCR_CTEIF6_Msk
#define DMA_IFCR_CGIF7_Pos                  (24U)
#define DMA_IFCR_CGIF7_Msk                  (0x1UL << DMA_IFCR_CGIF7_Pos)
#define DMA_IFCR_CGIF7                      DMA_IFCR_CGIF7_Msk
#define DMA_IFCR_CTCIF7_Pos                 (25U)
#define DMA_IFCR_CTCIF7_Msk                 (0x1UL << DMA_IFCR_CTCIF7_Pos)
#define DMA_IFCR_CTCIF7                     DMA_IFCR_CTCIF7_Msk
#define DMA_IFCR_CHTIF7_Pos                 (26U)
#define DMA_IFCR_CHTIF7_Msk                 (0x1UL << DMA_IFCR_CHTIF7_Pos)
#define DMA_IFCR_CHTIF7                     DMA_IFCR_CHTIF7_Msk
#define DMA_IFCR_CTEIF7_Pos                 (27U)
#define DMA_IFCR_CTEIF7_Msk                 (0x1UL << DMA_IFCR_CTEIF7_Pos)
#define DMA_IFCR_CTEIF7                     DMA_IFCR_CTEIF7_Msk

#define DMA_CCR_EN_Pos                      (0U)
#define DMA_CCR_EN_Msk                      (0x1UL << DMA_CCR_EN_Pos)
#define DMA_CCR_EN                          DMA_CCR_EN_Msk
#define DMA_CCR_TCIE_Pos                    (1U)
#define DMA_CCR_TCIE_Msk                    (0x1UL << DMA_CCR_TCIE_Pos)
#define DMA_CCR_TCIE                        DMA_CCR_TCIE_Msk
#define DMA_CCR_HTIE_Pos                    (2U)
#define DMA_CCR_HTIE_Msk                    (0x1UL << DMA_CCR_HTIE_Pos)
#define DMA_CCR_HTIE                        DMA_CCR_HTIE_Msk
#define DMA_CCR_TEIE_Pos                    (3U)
#define DMA_CCR_TEIE_Msk                    (0x1UL << DMA_CCR_TEIE_Pos)
#define DMA_CCR_TEIE                        DMA_CCR_TEIE_Msk
#define DMA_CCR_DIR_Pos                     (4U)
#define DMA_CCR_DIR_Msk                     (0x1UL << DMA_CCR_DIR_Pos)
#define DMA_CCR_DIR                         DMA_CCR_DIR_Msk
#define DMA_CCR_CIRC_Pos                    (5U)
#define DMA_CCR_CIRC_Msk                    (0x1UL << DMA_CCR_CIRC_Pos)
#define DMA_CCR_CIRC                        DMA_CCR_CIRC_Msk
#define DMA_CCR_PINC_Pos                    (6U)
#define DMA_CCR_PINC_Msk                    (0x1UL << DMA_CCR_PINC_Pos)
#define DMA_CCR_PINC                        DMA_CCR_PINC_Msk
#define DMA_CCR_MINC_Pos                    (7U)
#define DMA_CCR_MINC_Msk                    (0x1UL << DMA_CCR_MINC_Pos)
#define DMA_CCR_MINC                        DMA_CCR_MINC_Msk

#define DMA_CCR_PSIZE_Pos                   (8U)
#define DMA_CCR_PSIZE_Msk                   (0x3UL << DMA_CCR_PSIZE_Pos)
#define DMA_CCR_PSIZE                       DMA_CCR_PSIZE_Msk
#define DMA_CCR_PSIZE_0                     (0x1UL << DMA_CCR_PSIZE_Pos)
#define DMA_CCR_PSIZE_1                     (0x2UL << DMA_CCR_PSIZE_Pos)

#define DMA_CCR_MSIZE_Pos                   (10U)
#define DMA_CCR_MSIZE_Msk                   (0x3UL << DMA_CCR_MSIZE_Pos)
#define DMA_CCR_MSIZE                       DMA_CCR_MSIZE_Msk
#define DMA_CCR_MSIZE_0                     (0x1UL << DMA_CCR_MSIZE_Pos)
#define DMA_CCR_MSIZE_1                     (0x2UL << DMA_CCR_MSIZE_Pos)

#define DMA_CCR_PL_Pos                      (12U)
#define DMA_CCR_PL_Msk                      (0x3UL << DMA_CCR_PL_Pos)
#define DMA_CCR_PL                          DMA_CCR_PL_Msk
#define DMA_CCR_PL_0                        (0x1UL << DMA_CCR_PL_Pos)
#define DMA_CCR_PL_1                        (0x2UL << DMA_CCR_PL_Pos)

#define DMA_CCR_MEM2MEM_Pos                 (14U)
#define DMA_CCR_MEM2MEM_Msk                 (0x1UL << DMA_CCR_MEM2MEM_Pos)
#define DMA_CCR_MEM2MEM                     DMA_CCR_MEM2MEM_Msk

#define DMA_CNDTR_NDT_Pos                   (0U)
#define DMA_CNDTR_NDT_Msk                   (0xFFFFUL << DMA_CNDTR_NDT_Pos)
#define DMA_CNDTR_NDT                       DMA_CNDTR_NDT_Msk

#define DMA_CPAR_PA_Pos                     (0U)
#define DMA_CPAR_PA_Msk                     (0xFFFFFFFFUL << DMA_CPAR_PA_Pos)
#define DMA_CPAR_PA                         DMA_CPAR_PA_Msk

#define DMA_CMAR_MA_Pos                     (0U)
#define DMA_CMAR_MA_Msk                     (0xFFFFFFFFUL << DMA_CMAR_MA_Pos)
#define DMA_CMAR_MA                         DMA_CMAR_MA_Msk

#define ADC_MULTIMODE_SUPPORT

#define ADC_SR_AWD_Pos                      (0U)
#define ADC_SR_AWD_Msk                      (0x1UL << ADC_SR_AWD_Pos)
#define ADC_SR_AWD                          ADC_SR_AWD_Msk
#define ADC_SR_EOS_Pos                      (1U)
#define ADC_SR_EOS_Msk                      (0x1UL << ADC_SR_EOS_Pos)
#define ADC_SR_EOS                          ADC_SR_EOS_Msk
#define ADC_SR_JEOS_Pos                     (2U)
#define ADC_SR_JEOS_Msk                     (0x1UL << ADC_SR_JEOS_Pos)
#define ADC_SR_JEOS                         ADC_SR_JEOS_Msk
#define ADC_SR_JSTRT_Pos                    (3U)
#define ADC_SR_JSTRT_Msk                    (0x1UL << ADC_SR_JSTRT_Pos)
#define ADC_SR_JSTRT                        ADC_SR_JSTRT_Msk
#define ADC_SR_STRT_Pos                     (4U)
#define ADC_SR_STRT_Msk                     (0x1UL << ADC_SR_STRT_Pos)
#define ADC_SR_STRT                         ADC_SR_STRT_Msk

#define  ADC_SR_EOC                          (ADC_SR_EOS)
#define  ADC_SR_JEOC                         (ADC_SR_JEOS)

#define ADC_CR1_AWDCH_Pos                   (0U)
#define ADC_CR1_AWDCH_Msk                   (0x1FUL << ADC_CR1_AWDCH_Pos)
#define ADC_CR1_AWDCH                       ADC_CR1_AWDCH_Msk
#define ADC_CR1_AWDCH_0                     (0x01UL << ADC_CR1_AWDCH_Pos)
#define ADC_CR1_AWDCH_1                     (0x02UL << ADC_CR1_AWDCH_Pos)
#define ADC_CR1_AWDCH_2                     (0x04UL << ADC_CR1_AWDCH_Pos)
#define ADC_CR1_AWDCH_3                     (0x08UL << ADC_CR1_AWDCH_Pos)
#define ADC_CR1_AWDCH_4                     (0x10UL << ADC_CR1_AWDCH_Pos)

#define ADC_CR1_EOSIE_Pos                   (5U)
#define ADC_CR1_EOSIE_Msk                   (0x1UL << ADC_CR1_EOSIE_Pos)
#define ADC_CR1_EOSIE                       ADC_CR1_EOSIE_Msk
#define ADC_CR1_AWDIE_Pos                   (6U)
#define ADC_CR1_AWDIE_Msk                   (0x1UL << ADC_CR1_AWDIE_Pos)
#define ADC_CR1_AWDIE                       ADC_CR1_AWDIE_Msk
#define ADC_CR1_JEOSIE_Pos                  (7U)
#define ADC_CR1_JEOSIE_Msk                  (0x1UL << ADC_CR1_JEOSIE_Pos)
#define ADC_CR1_JEOSIE                      ADC_CR1_JEOSIE_Msk
#define ADC_CR1_SCAN_Pos                    (8U)
#define ADC_CR1_SCAN_Msk                    (0x1UL << ADC_CR1_SCAN_Pos)
#define ADC_CR1_SCAN                        ADC_CR1_SCAN_Msk
#define ADC_CR1_AWDSGL_Pos                  (9U)
#define ADC_CR1_AWDSGL_Msk                  (0x1UL << ADC_CR1_AWDSGL_Pos)
#define ADC_CR1_AWDSGL                      ADC_CR1_AWDSGL_Msk
#define ADC_CR1_JAUTO_Pos                   (10U)
#define ADC_CR1_JAUTO_Msk                   (0x1UL << ADC_CR1_JAUTO_Pos)
#define ADC_CR1_JAUTO                       ADC_CR1_JAUTO_Msk
#define ADC_CR1_DISCEN_Pos                  (11U)
#define ADC_CR1_DISCEN_Msk                  (0x1UL << ADC_CR1_DISCEN_Pos)
#define ADC_CR1_DISCEN                      ADC_CR1_DISCEN_Msk
#define ADC_CR1_JDISCEN_Pos                 (12U)
#define ADC_CR1_JDISCEN_Msk                 (0x1UL << ADC_CR1_JDISCEN_Pos)
#define ADC_CR1_JDISCEN                     ADC_CR1_JDISCEN_Msk

#define ADC_CR1_DISCNUM_Pos                 (13U)
#define ADC_CR1_DISCNUM_Msk                 (0x7UL << ADC_CR1_DISCNUM_Pos)
#define ADC_CR1_DISCNUM                     ADC_CR1_DISCNUM_Msk
#define ADC_CR1_DISCNUM_0                   (0x1UL << ADC_CR1_DISCNUM_Pos)
#define ADC_CR1_DISCNUM_1                   (0x2UL << ADC_CR1_DISCNUM_Pos)
#define ADC_CR1_DISCNUM_2                   (0x4UL << ADC_CR1_DISCNUM_Pos)

#define ADC_CR1_DUALMOD_Pos                 (16U)
#define ADC_CR1_DUALMOD_Msk                 (0xFUL << ADC_CR1_DUALMOD_Pos)
#define ADC_CR1_DUALMOD                     ADC_CR1_DUALMOD_Msk
#define ADC_CR1_DUALMOD_0                   (0x1UL << ADC_CR1_DUALMOD_Pos)
#define ADC_CR1_DUALMOD_1                   (0x2UL << ADC_CR1_DUALMOD_Pos)
#define ADC_CR1_DUALMOD_2                   (0x4UL << ADC_CR1_DUALMOD_Pos)
#define ADC_CR1_DUALMOD_3                   (0x8UL << ADC_CR1_DUALMOD_Pos)

#define ADC_CR1_JAWDEN_Pos                  (22U)
#define ADC_CR1_JAWDEN_Msk                  (0x1UL << ADC_CR1_JAWDEN_Pos)
#define ADC_CR1_JAWDEN                      ADC_CR1_JAWDEN_Msk
#define ADC_CR1_AWDEN_Pos                   (23U)
#define ADC_CR1_AWDEN_Msk                   (0x1UL << ADC_CR1_AWDEN_Pos)
#define ADC_CR1_AWDEN                       ADC_CR1_AWDEN_Msk

#define  ADC_CR1_EOCIE                       (ADC_CR1_EOSIE)
#define  ADC_CR1_JEOCIE                      (ADC_CR1_JEOSIE)

#define ADC_CR2_ADON_Pos                    (0U)
#define ADC_CR2_ADON_Msk                    (0x1UL << ADC_CR2_ADON_Pos)
#define ADC_CR2_ADON                        ADC_CR2_ADON_Msk
#define ADC_CR2_CONT_Pos                    (1U)
#define ADC_CR2_CONT_Msk                    (0x1UL << ADC_CR2_CONT_Pos)
#define ADC_CR2_CONT                        ADC_CR2_CONT_Msk
#define ADC_CR2_CAL_Pos                     (2U)
#define ADC_CR2_CAL_Msk                     (0x1UL << ADC_CR2_CAL_Pos)
#define ADC_CR2_CAL                         ADC_CR2_CAL_Msk
#define ADC_CR2_RSTCAL_Pos                  (3U)
#define ADC_CR2_RSTCAL_Msk                  (0x1UL << ADC_CR2_RSTCAL_Pos)
#define ADC_CR2_RSTCAL                      ADC_CR2_RSTCAL_Msk
#define ADC_CR2_DMA_Pos                     (8U)
#define ADC_CR2_DMA_Msk                     (0x1UL << ADC_CR2_DMA_Pos)
#define ADC_CR2_DMA                         ADC_CR2_DMA_Msk
#define ADC_CR2_ALIGN_Pos                   (11U)
#define ADC_CR2_ALIGN_Msk                   (0x1UL << ADC_CR2_ALIGN_Pos)
#define ADC_CR2_ALIGN                       ADC_CR2_ALIGN_Msk

#define ADC_CR2_JEXTSEL_Pos                 (12U)
#define ADC_CR2_JEXTSEL_Msk                 (0x7UL << ADC_CR2_JEXTSEL_Pos)
#define ADC_CR2_JEXTSEL                     ADC_CR2_JEXTSEL_Msk
#define ADC_CR2_JEXTSEL_0                   (0x1UL << ADC_CR2_JEXTSEL_Pos)
#define ADC_CR2_JEXTSEL_1                   (0x2UL << ADC_CR2_JEXTSEL_Pos)
#define ADC_CR2_JEXTSEL_2                   (0x4UL << ADC_CR2_JEXTSEL_Pos)

#define ADC_CR2_JEXTTRIG_Pos                (15U)
#define ADC_CR2_JEXTTRIG_Msk                (0x1UL << ADC_CR2_JEXTTRIG_Pos)
#define ADC_CR2_JEXTTRIG                    ADC_CR2_JEXTTRIG_Msk

#define ADC_CR2_EXTSEL_Pos                  (17U)
#define ADC_CR2_EXTSEL_Msk                  (0x7UL << ADC_CR2_EXTSEL_Pos)
#define ADC_CR2_EXTSEL                      ADC_CR2_EXTSEL_Msk
#define ADC_CR2_EXTSEL_0                    (0x1UL << ADC_CR2_EXTSEL_Pos)
#define ADC_CR2_EXTSEL_1                    (0x2UL << ADC_CR2_EXTSEL_Pos)
#define ADC_CR2_EXTSEL_2                    (0x4UL << ADC_CR2_EXTSEL_Pos)

#define ADC_CR2_EXTTRIG_Pos                 (20U)
#define ADC_CR2_EXTTRIG_Msk                 (0x1UL << ADC_CR2_EXTTRIG_Pos)
#define ADC_CR2_EXTTRIG                     ADC_CR2_EXTTRIG_Msk
#define ADC_CR2_JSWSTART_Pos                (21U)
#define ADC_CR2_JSWSTART_Msk                (0x1UL << ADC_CR2_JSWSTART_Pos)
#define ADC_CR2_JSWSTART                    ADC_CR2_JSWSTART_Msk
#define ADC_CR2_SWSTART_Pos                 (22U)
#define ADC_CR2_SWSTART_Msk                 (0x1UL << ADC_CR2_SWSTART_Pos)
#define ADC_CR2_SWSTART                     ADC_CR2_SWSTART_Msk
#define ADC_CR2_TSVREFE_Pos                 (23U)
#define ADC_CR2_TSVREFE_Msk                 (0x1UL << ADC_CR2_TSVREFE_Pos)
#define ADC_CR2_TSVREFE                     ADC_CR2_TSVREFE_Msk

#define ADC_SMPR1_SMP10_Pos                 (0U)
#define ADC_SMPR1_SMP10_Msk                 (0x7UL << ADC_SMPR1_SMP10_Pos)
#define ADC_SMPR1_SMP10                     ADC_SMPR1_SMP10_Msk
#define ADC_SMPR1_SMP10_0                   (0x1UL << ADC_SMPR1_SMP10_Pos)
#define ADC_SMPR1_SMP10_1                   (0x2UL << ADC_SMPR1_SMP10_Pos)
#define ADC_SMPR1_SMP10_2                   (0x4UL << ADC_SMPR1_SMP10_Pos)

#define ADC_SMPR1_SMP11_Pos                 (3U)
#define ADC_SMPR1_SMP11_Msk                 (0x7UL << ADC_SMPR1_SMP11_Pos)
#define ADC_SMPR1_SMP11                     ADC_SMPR1_SMP11_Msk
#define ADC_SMPR1_SMP11_0                   (0x1UL << ADC_SMPR1_SMP11_Pos)
#define ADC_SMPR1_SMP11_1                   (0x2UL << ADC_SMPR1_SMP11_Pos)
#define ADC_SMPR1_SMP11_2                   (0x4UL << ADC_SMPR1_SMP11_Pos)

#define ADC_SMPR1_SMP12_Pos                 (6U)
#define ADC_SMPR1_SMP12_Msk                 (0x7UL << ADC_SMPR1_SMP12_Pos)
#define ADC_SMPR1_SMP12                     ADC_SMPR1_SMP12_Msk
#define ADC_SMPR1_SMP12_0                   (0x1UL << ADC_SMPR1_SMP12_Pos)
#define ADC_SMPR1_SMP12_1                   (0x2UL << ADC_SMPR1_SMP12_Pos)
#define ADC_SMPR1_SMP12_2                   (0x4UL << ADC_SMPR1_SMP12_Pos)

#define ADC_SMPR1_SMP13_Pos                 (9U)
#define ADC_SMPR1_SMP13_Msk                 (0x7UL << ADC_SMPR1_SMP13_Pos)
#define ADC_SMPR1_SMP13                     ADC_SMPR1_SMP13_Msk
#define ADC_SMPR1_SMP13_0                   (0x1UL << ADC_SMPR1_SMP13_Pos)
#define ADC_SMPR1_SMP13_1                   (0x2UL << ADC_SMPR1_SMP13_Pos)
#define ADC_SMPR1_SMP13_2                   (0x4UL << ADC_SMPR1_SMP13_Pos)

#define ADC_SMPR1_SMP14_Pos                 (12U)
#define ADC_SMPR1_SMP14_Msk                 (0x7UL << ADC_SMPR1_SMP14_Pos)
#define ADC_SMPR1_SMP14                     ADC_SMPR1_SMP14_Msk
#define ADC_SMPR1_SMP14_0                   (0x1UL << ADC_SMPR1_SMP14_Pos)
#define ADC_SMPR1_SMP14_1                   (0x2UL << ADC_SMPR1_SMP14_Pos)
#define ADC_SMPR1_SMP14_2                   (0x4UL << ADC_SMPR1_SMP14_Pos)

#define ADC_SMPR1_SMP15_Pos                 (15U)
#define ADC_SMPR1_SMP15_Msk                 (0x7UL << ADC_SMPR1_SMP15_Pos)
#define ADC_SMPR1_SMP15                     ADC_SMPR1_SMP15_Msk
#define ADC_SMPR1_SMP15_0                   (0x1UL << ADC_SMPR1_SMP15_Pos)
#define ADC_SMPR1_SMP15_1                   (0x2UL << ADC_SMPR1_SMP15_Pos)
#define ADC_SMPR1_SMP15_2                   (0x4UL << ADC_SMPR1_SMP15_Pos)

#define ADC_SMPR1_SMP16_Pos                 (18U)
#define ADC_SMPR1_SMP16_Msk                 (0x7UL << ADC_SMPR1_SMP16_Pos)
#define ADC_SMPR1_SMP16                     ADC_SMPR1_SMP16_Msk
#define ADC_SMPR1_SMP16_0                   (0x1UL << ADC_SMPR1_SMP16_Pos)
#define ADC_SMPR1_SMP16_1                   (0x2UL << ADC_SMPR1_SMP16_Pos)
#define ADC_SMPR1_SMP16_2                   (0x4UL << ADC_SMPR1_SMP16_Pos)

#define ADC_SMPR1_SMP17_Pos                 (21U)
#define ADC_SMPR1_SMP17_Msk                 (0x7UL << ADC_SMPR1_SMP17_Pos)
#define ADC_SMPR1_SMP17                     ADC_SMPR1_SMP17_Msk
#define ADC_SMPR1_SMP17_0                   (0x1UL << ADC_SMPR1_SMP17_Pos)
#define ADC_SMPR1_SMP17_1                   (0x2UL << ADC_SMPR1_SMP17_Pos)
#define ADC_SMPR1_SMP17_2                   (0x4UL << ADC_SMPR1_SMP17_Pos)

#define ADC_SMPR2_SMP0_Pos                  (0U)
#define ADC_SMPR2_SMP0_Msk                  (0x7UL << ADC_SMPR2_SMP0_Pos)
#define ADC_SMPR2_SMP0                      ADC_SMPR2_SMP0_Msk
#define ADC_SMPR2_SMP0_0                    (0x1UL << ADC_SMPR2_SMP0_Pos)
#define ADC_SMPR2_SMP0_1                    (0x2UL << ADC_SMPR2_SMP0_Pos)
#define ADC_SMPR2_SMP0_2                    (0x4UL << ADC_SMPR2_SMP0_Pos)

#define ADC_SMPR2_SMP1_Pos                  (3U)
#define ADC_SMPR2_SMP1_Msk                  (0x7UL << ADC_SMPR2_SMP1_Pos)
#define ADC_SMPR2_SMP1                      ADC_SMPR2_SMP1_Msk
#define ADC_SMPR2_SMP1_0                    (0x1UL << ADC_SMPR2_SMP1_Pos)
#define ADC_SMPR2_SMP1_1                    (0x2UL << ADC_SMPR2_SMP1_Pos)
#define ADC_SMPR2_SMP1_2                    (0x4UL << ADC_SMPR2_SMP1_Pos)

#define ADC_SMPR2_SMP2_Pos                  (6U)
#define ADC_SMPR2_SMP2_Msk                  (0x7UL << ADC_SMPR2_SMP2_Pos)
#define ADC_SMPR2_SMP2                      ADC_SMPR2_SMP2_Msk
#define ADC_SMPR2_SMP2_0                    (0x1UL << ADC_SMPR2_SMP2_Pos)
#define ADC_SMPR2_SMP2_1                    (0x2UL << ADC_SMPR2_SMP2_Pos)
#define ADC_SMPR2_SMP2_2                    (0x4UL << ADC_SMPR2_SMP2_Pos)

#define ADC_SMPR2_SMP3_Pos                  (9U)
#define ADC_SMPR2_SMP3_Msk                  (0x7UL << ADC_SMPR2_SMP3_Pos)
#define ADC_SMPR2_SMP3                      ADC_SMPR2_SMP3_Msk
#define ADC_SMPR2_SMP3_0                    (0x1UL << ADC_SMPR2_SMP3_Pos)
#define ADC_SMPR2_SMP3_1                    (0x2UL << ADC_SMPR2_SMP3_Pos)
#define ADC_SMPR2_SMP3_2                    (0x4UL << ADC_SMPR2_SMP3_Pos)

#define ADC_SMPR2_SMP4_Pos                  (12U)
#define ADC_SMPR2_SMP4_Msk                  (0x7UL << ADC_SMPR2_SMP4_Pos)
#define ADC_SMPR2_SMP4                      ADC_SMPR2_SMP4_Msk
#define ADC_SMPR2_SMP4_0                    (0x1UL << ADC_SMPR2_SMP4_Pos)
#define ADC_SMPR2_SMP4_1                    (0x2UL << ADC_SMPR2_SMP4_Pos)
#define ADC_SMPR2_SMP4_2                    (0x4UL << ADC_SMPR2_SMP4_Pos)

#define ADC_SMPR2_SMP5_Pos                  (15U)
#define ADC_SMPR2_SMP5_Msk                  (0x7UL << ADC_SMPR2_SMP5_Pos)
#define ADC_SMPR2_SMP5                      ADC_SMPR2_SMP5_Msk
#define ADC_SMPR2_SMP5_0                    (0x1UL << ADC_SMPR2_SMP5_Pos)
#define ADC_SMPR2_SMP5_1                    (0x2UL << ADC_SMPR2_SMP5_Pos)
#define ADC_SMPR2_SMP5_2                    (0x4UL << ADC_SMPR2_SMP5_Pos)

#define ADC_SMPR2_SMP6_Pos                  (18U)
#define ADC_SMPR2_SMP6_Msk                  (0x7UL << ADC_SMPR2_SMP6_Pos)
#define ADC_SMPR2_SMP6                      ADC_SMPR2_SMP6_Msk
#define ADC_SMPR2_SMP6_0                    (0x1UL << ADC_SMPR2_SMP6_Pos)
#define ADC_SMPR2_SMP6_1                    (0x2UL << ADC_SMPR2_SMP6_Pos)
#define ADC_SMPR2_SMP6_2                    (0x4UL << ADC_SMPR2_SMP6_Pos)

#define ADC_SMPR2_SMP7_Pos                  (21U)
#define ADC_SMPR2_SMP7_Msk                  (0x7UL << ADC_SMPR2_SMP7_Pos)
#define ADC_SMPR2_SMP7                      ADC_SMPR2_SMP7_Msk
#define ADC_SMPR2_SMP7_0                    (0x1UL << ADC_SMPR2_SMP7_Pos)
#define ADC_SMPR2_SMP7_1                    (0x2UL << ADC_SMPR2_SMP7_Pos)
#define ADC_SMPR2_SMP7_2                    (0x4UL << ADC_SMPR2_SMP7_Pos)

#define ADC_SMPR2_SMP8_Pos                  (24U)
#define ADC_SMPR2_SMP8_Msk                  (0x7UL << ADC_SMPR2_SMP8_Pos)
#define ADC_SMPR2_SMP8                      ADC_SMPR2_SMP8_Msk
#define ADC_SMPR2_SMP8_0                    (0x1UL << ADC_SMPR2_SMP8_Pos)
#define ADC_SMPR2_SMP8_1                    (0x2UL << ADC_SMPR2_SMP8_Pos)
#define ADC_SMPR2_SMP8_2                    (0x4UL << ADC_SMPR2_SMP8_Pos)

#define ADC_SMPR2_SMP9_Pos                  (27U)
#define ADC_SMPR2_SMP9_Msk                  (0x7UL << ADC_SMPR2_SMP9_Pos)
#define ADC_SMPR2_SMP9                      ADC_SMPR2_SMP9_Msk
#define ADC_SMPR2_SMP9_0                    (0x1UL << ADC_SMPR2_SMP9_Pos)
#define ADC_SMPR2_SMP9_1                    (0x2UL << ADC_SMPR2_SMP9_Pos)
#define ADC_SMPR2_SMP9_2                    (0x4UL << ADC_SMPR2_SMP9_Pos)

#define ADC_JOFR1_JOFFSET1_Pos              (0U)
#define ADC_JOFR1_JOFFSET1_Msk              (0xFFFUL << ADC_JOFR1_JOFFSET1_Pos)
#define ADC_JOFR1_JOFFSET1                  ADC_JOFR1_JOFFSET1_Msk

#define ADC_JOFR2_JOFFSET2_Pos              (0U)
#define ADC_JOFR2_JOFFSET2_Msk              (0xFFFUL << ADC_JOFR2_JOFFSET2_Pos)
#define ADC_JOFR2_JOFFSET2                  ADC_JOFR2_JOFFSET2_Msk

#define ADC_JOFR3_JOFFSET3_Pos              (0U)
#define ADC_JOFR3_JOFFSET3_Msk              (0xFFFUL << ADC_JOFR3_JOFFSET3_Pos)
#define ADC_JOFR3_JOFFSET3                  ADC_JOFR3_JOFFSET3_Msk

#define ADC_JOFR4_JOFFSET4_Pos              (0U)
#define ADC_JOFR4_JOFFSET4_Msk              (0xFFFUL << ADC_JOFR4_JOFFSET4_Pos)
#define ADC_JOFR4_JOFFSET4                  ADC_JOFR4_JOFFSET4_Msk

#define ADC_HTR_HT_Pos                      (0U)
#define ADC_HTR_HT_Msk                      (0xFFFUL << ADC_HTR_HT_Pos)
#define ADC_HTR_HT                          ADC_HTR_HT_Msk

#define ADC_LTR_LT_Pos                      (0U)
#define ADC_LTR_LT_Msk                      (0xFFFUL << ADC_LTR_LT_Pos)
#define ADC_LTR_LT                          ADC_LTR_LT_Msk

#define ADC_SQR1_SQ13_Pos                   (0U)
#define ADC_SQR1_SQ13_Msk                   (0x1FUL << ADC_SQR1_SQ13_Pos)
#define ADC_SQR1_SQ13                       ADC_SQR1_SQ13_Msk
#define ADC_SQR1_SQ13_0                     (0x01UL << ADC_SQR1_SQ13_Pos)
#define ADC_SQR1_SQ13_1                     (0x02UL << ADC_SQR1_SQ13_Pos)
#define ADC_SQR1_SQ13_2                     (0x04UL << ADC_SQR1_SQ13_Pos)
#define ADC_SQR1_SQ13_3                     (0x08UL << ADC_SQR1_SQ13_Pos)
#define ADC_SQR1_SQ13_4                     (0x10UL << ADC_SQR1_SQ13_Pos)

#define ADC_SQR1_SQ14_Pos                   (5U)
#define ADC_SQR1_SQ14_Msk                   (0x1FUL << ADC_SQR1_SQ14_Pos)
#define ADC_SQR1_SQ14                       ADC_SQR1_SQ14_Msk
#define ADC_SQR1_SQ14_0                     (0x01UL << ADC_SQR1_SQ14_Pos)
#define ADC_SQR1_SQ14_1                     (0x02UL << ADC_SQR1_SQ14_Pos)
#define ADC_SQR1_SQ14_2                     (0x04UL << ADC_SQR1_SQ14_Pos)
#define ADC_SQR1_SQ14_3                     (0x08UL << ADC_SQR1_SQ14_Pos)
#define ADC_SQR1_SQ14_4                     (0x10UL << ADC_SQR1_SQ14_Pos)

#define ADC_SQR1_SQ15_Pos                   (10U)
#define ADC_SQR1_SQ15_Msk                   (0x1FUL << ADC_SQR1_SQ15_Pos)
#define ADC_SQR1_SQ15                       ADC_SQR1_SQ15_Msk
#define ADC_SQR1_SQ15_0                     (0x01UL << ADC_SQR1_SQ15_Pos)
#define ADC_SQR1_SQ15_1                     (0x02UL << ADC_SQR1_SQ15_Pos)
#define ADC_SQR1_SQ15_2                     (0x04UL << ADC_SQR1_SQ15_Pos)
#define ADC_SQR1_SQ15_3                     (0x08UL << ADC_SQR1_SQ15_Pos)
#define ADC_SQR1_SQ15_4                     (0x10UL << ADC_SQR1_SQ15_Pos)

#define ADC_SQR1_SQ16_Pos                   (15U)
#define ADC_SQR1_SQ16_Msk                   (0x1FUL << ADC_SQR1_SQ16_Pos)
#define ADC_SQR1_SQ16                       ADC_SQR1_SQ16_Msk
#define ADC_SQR1_SQ16_0                     (0x01UL << ADC_SQR1_SQ16_Pos)
#define ADC_SQR1_SQ16_1                     (0x02UL << ADC_SQR1_SQ16_Pos)
#define ADC_SQR1_SQ16_2                     (0x04UL << ADC_SQR1_SQ16_Pos)
#define ADC_SQR1_SQ16_3                     (0x08UL << ADC_SQR1_SQ16_Pos)
#define ADC_SQR1_SQ16_4                     (0x10UL << ADC_SQR1_SQ16_Pos)

#define ADC_SQR1_L_Pos                      (20U)
#define ADC_SQR1_L_Msk                      (0xFUL << ADC_SQR1_L_Pos)
#define ADC_SQR1_L                          ADC_SQR1_L_Msk
#define ADC_SQR1_L_0                        (0x1UL << ADC_SQR1_L_Pos)
#define ADC_SQR1_L_1                        (0x2UL << ADC_SQR1_L_Pos)
#define ADC_SQR1_L_2                        (0x4UL << ADC_SQR1_L_Pos)
#define ADC_SQR1_L_3                        (0x8UL << ADC_SQR1_L_Pos)

#define ADC_SQR2_SQ7_Pos                    (0U)
#define ADC_SQR2_SQ7_Msk                    (0x1FUL << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7                        ADC_SQR2_SQ7_Msk
#define ADC_SQR2_SQ7_0                      (0x01UL << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_1                      (0x02UL << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_2                      (0x04UL << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_3                      (0x08UL << ADC_SQR2_SQ7_Pos)
#define ADC_SQR2_SQ7_4                      (0x10UL << ADC_SQR2_SQ7_Pos)

#define ADC_SQR2_SQ8_Pos                    (5U)
#define ADC_SQR2_SQ8_Msk                    (0x1FUL << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8                        ADC_SQR2_SQ8_Msk
#define ADC_SQR2_SQ8_0                      (0x01UL << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_1                      (0x02UL << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_2                      (0x04UL << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_3                      (0x08UL << ADC_SQR2_SQ8_Pos)
#define ADC_SQR2_SQ8_4                      (0x10UL << ADC_SQR2_SQ8_Pos)

#define ADC_SQR2_SQ9_Pos                    (10U)
#define ADC_SQR2_SQ9_Msk                    (0x1FUL << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9                        ADC_SQR2_SQ9_Msk
#define ADC_SQR2_SQ9_0                      (0x01UL << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_1                      (0x02UL << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_2                      (0x04UL << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_3                      (0x08UL << ADC_SQR2_SQ9_Pos)
#define ADC_SQR2_SQ9_4                      (0x10UL << ADC_SQR2_SQ9_Pos)

#define ADC_SQR2_SQ10_Pos                   (15U)
#define ADC_SQR2_SQ10_Msk                   (0x1FUL << ADC_SQR2_SQ10_Pos)
#define ADC_SQR2_SQ10                       ADC_SQR2_SQ10_Msk
#define ADC_SQR2_SQ10_0                     (0x01UL << ADC_SQR2_SQ10_Pos)
#define ADC_SQR2_SQ10_1                     (0x02UL << ADC_SQR2_SQ10_Pos)
#define ADC_SQR2_SQ10_2                     (0x04UL << ADC_SQR2_SQ10_Pos)
#define ADC_SQR2_SQ10_3                     (0x08UL << ADC_SQR2_SQ10_Pos)
#define ADC_SQR2_SQ10_4                     (0x10UL << ADC_SQR2_SQ10_Pos)

#define ADC_SQR2_SQ11_Pos                   (20U)
#define ADC_SQR2_SQ11_Msk                   (0x1FUL << ADC_SQR2_SQ11_Pos)
#define ADC_SQR2_SQ11                       ADC_SQR2_SQ11_Msk
#define ADC_SQR2_SQ11_0                     (0x01UL << ADC_SQR2_SQ11_Pos)
#define ADC_SQR2_SQ11_1                     (0x02UL << ADC_SQR2_SQ11_Pos)
#define ADC_SQR2_SQ11_2                     (0x04UL << ADC_SQR2_SQ11_Pos)
#define ADC_SQR2_SQ11_3                     (0x08UL << ADC_SQR2_SQ11_Pos)
#define ADC_SQR2_SQ11_4                     (0x10UL << ADC_SQR2_SQ11_Pos)

#define ADC_SQR2_SQ12_Pos                   (25U)
#define ADC_SQR2_SQ12_Msk                   (0x1FUL << ADC_SQR2_SQ12_Pos)
#define ADC_SQR2_SQ12                       ADC_SQR2_SQ12_Msk
#define ADC_SQR2_SQ12_0                     (0x01UL << ADC_SQR2_SQ12_Pos)
#define ADC_SQR2_SQ12_1                     (0x02UL << ADC_SQR2_SQ12_Pos)
#define ADC_SQR2_SQ12_2                     (0x04UL << ADC_SQR2_SQ12_Pos)
#define ADC_SQR2_SQ12_3                     (0x08UL << ADC_SQR2_SQ12_Pos)
#define ADC_SQR2_SQ12_4                     (0x10UL << ADC_SQR2_SQ12_Pos)

#define ADC_SQR3_SQ1_Pos                    (0U)
#define ADC_SQR3_SQ1_Msk                    (0x1FUL << ADC_SQR3_SQ1_Pos)
#define ADC_SQR3_SQ1                        ADC_SQR3_SQ1_Msk
#define ADC_SQR3_SQ1_0                      (0x01UL << ADC_SQR3_SQ1_Pos)
#define ADC_SQR3_SQ1_1                      (0x02UL << ADC_SQR3_SQ1_Pos)
#define ADC_SQR3_SQ1_2                      (0x04UL << ADC_SQR3_SQ1_Pos)
#define ADC_SQR3_SQ1_3                      (0x08UL << ADC_SQR3_SQ1_Pos)
#define ADC_SQR3_SQ1_4                      (0x10UL << ADC_SQR3_SQ1_Pos)

#define ADC_SQR3_SQ2_Pos                    (5U)
#define ADC_SQR3_SQ2_Msk                    (0x1FUL << ADC_SQR3_SQ2_Pos)
#define ADC_SQR3_SQ2                        ADC_SQR3_SQ2_Msk
#define ADC_SQR3_SQ2_0                      (0x01UL << ADC_SQR3_SQ2_Pos)
#define ADC_SQR3_SQ2_1                      (0x02UL << ADC_SQR3_SQ2_Pos)
#define ADC_SQR3_SQ2_2                      (0x04UL << ADC_SQR3_SQ2_Pos)
#define ADC_SQR3_SQ2_3                      (0x08UL << ADC_SQR3_SQ2_Pos)
#define ADC_SQR3_SQ2_4                      (0x10UL << ADC_SQR3_SQ2_Pos)

#define ADC_SQR3_SQ3_Pos                    (10U)
#define ADC_SQR3_SQ3_Msk                    (0x1FUL << ADC_SQR3_SQ3_Pos)
#define ADC_SQR3_SQ3                        ADC_SQR3_SQ3_Msk
#define ADC_SQR3_SQ3_0                      (0x01UL << ADC_SQR3_SQ3_Pos)
#define ADC_SQR3_SQ3_1                      (0x02UL << ADC_SQR3_SQ3_Pos)
#define ADC_SQR3_SQ3_2                      (0x04UL << ADC_SQR3_SQ3_Pos)
#define ADC_SQR3_SQ3_3                      (0x08UL << ADC_SQR3_SQ3_Pos)
#define ADC_SQR3_SQ3_4                      (0x10UL << ADC_SQR3_SQ3_Pos)

#define ADC_SQR3_SQ4_Pos                    (15U)
#define ADC_SQR3_SQ4_Msk                    (0x1FUL << ADC_SQR3_SQ4_Pos)
#define ADC_SQR3_SQ4                        ADC_SQR3_SQ4_Msk
#define ADC_SQR3_SQ4_0                      (0x01UL << ADC_SQR3_SQ4_Pos)
#define ADC_SQR3_SQ4_1                      (0x02UL << ADC_SQR3_SQ4_Pos)
#define ADC_SQR3_SQ4_2                      (0x04UL << ADC_SQR3_SQ4_Pos)
#define ADC_SQR3_SQ4_3                      (0x08UL << ADC_SQR3_SQ4_Pos)
#define ADC_SQR3_SQ4_4                      (0x10UL << ADC_SQR3_SQ4_Pos)

#define ADC_SQR3_SQ5_Pos                    (20U)
#define ADC_SQR3_SQ5_Msk                    (0x1FUL << ADC_SQR3_SQ5_Pos)
#define ADC_SQR3_SQ5                        ADC_SQR3_SQ5_Msk
#define ADC_SQR3_SQ5_0                      (0x01UL << ADC_SQR3_SQ5_Pos)
#define ADC_SQR3_SQ5_1                      (0x02UL << ADC_SQR3_SQ5_Pos)
#define ADC_SQR3_SQ5_2                      (0x04UL << ADC_SQR3_SQ5_Pos)
#define ADC_SQR3_SQ5_3                      (0x08UL << ADC_SQR3_SQ5_Pos)
#define ADC_SQR3_SQ5_4                      (0x10UL << ADC_SQR3_SQ5_Pos)

#define ADC_SQR3_SQ6_Pos                    (25U)
#define ADC_SQR3_SQ6_Msk                    (0x1FUL << ADC_SQR3_SQ6_Pos)
#define ADC_SQR3_SQ6                        ADC_SQR3_SQ6_Msk
#define ADC_SQR3_SQ6_0                      (0x01UL << ADC_SQR3_SQ6_Pos)
#define ADC_SQR3_SQ6_1                      (0x02UL << ADC_SQR3_SQ6_Pos)
#define ADC_SQR3_SQ6_2                      (0x04UL << ADC_SQR3_SQ6_Pos)
#define ADC_SQR3_SQ6_3                      (0x08UL << ADC_SQR3_SQ6_Pos)
#define ADC_SQR3_SQ6_4                      (0x10UL << ADC_SQR3_SQ6_Pos)

#define ADC_JSQR_JSQ1_Pos                   (0U)
#define ADC_JSQR_JSQ1_Msk                   (0x1FUL << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1                       ADC_JSQR_JSQ1_Msk
#define ADC_JSQR_JSQ1_0                     (0x01UL << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_1                     (0x02UL << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_2                     (0x04UL << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_3                     (0x08UL << ADC_JSQR_JSQ1_Pos)
#define ADC_JSQR_JSQ1_4                     (0x10UL << ADC_JSQR_JSQ1_Pos)

#define ADC_JSQR_JSQ2_Pos                   (5U)
#define ADC_JSQR_JSQ2_Msk                   (0x1FUL << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2                       ADC_JSQR_JSQ2_Msk
#define ADC_JSQR_JSQ2_0                     (0x01UL << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_1                     (0x02UL << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_2                     (0x04UL << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_3                     (0x08UL << ADC_JSQR_JSQ2_Pos)
#define ADC_JSQR_JSQ2_4                     (0x10UL << ADC_JSQR_JSQ2_Pos)

#define ADC_JSQR_JSQ3_Pos                   (10U)
#define ADC_JSQR_JSQ3_Msk                   (0x1FUL << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3                       ADC_JSQR_JSQ3_Msk
#define ADC_JSQR_JSQ3_0                     (0x01UL << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_1                     (0x02UL << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_2                     (0x04UL << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_3                     (0x08UL << ADC_JSQR_JSQ3_Pos)
#define ADC_JSQR_JSQ3_4                     (0x10UL << ADC_JSQR_JSQ3_Pos)

#define ADC_JSQR_JSQ4_Pos                   (15U)
#define ADC_JSQR_JSQ4_Msk                   (0x1FUL << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4                       ADC_JSQR_JSQ4_Msk
#define ADC_JSQR_JSQ4_0                     (0x01UL << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_1                     (0x02UL << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_2                     (0x04UL << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_3                     (0x08UL << ADC_JSQR_JSQ4_Pos)
#define ADC_JSQR_JSQ4_4                     (0x10UL << ADC_JSQR_JSQ4_Pos)

#define ADC_JSQR_JL_Pos                     (20U)
#define ADC_JSQR_JL_Msk                     (0x3UL << ADC_JSQR_JL_Pos)
#define ADC_JSQR_JL                         ADC_JSQR_JL_Msk
#define ADC_JSQR_JL_0                       (0x1UL << ADC_JSQR_JL_Pos)
#define ADC_JSQR_JL_1                       (0x2UL << ADC_JSQR_JL_Pos)

#define ADC_JDR1_JDATA_Pos                  (0U)
#define ADC_JDR1_JDATA_Msk                  (0xFFFFUL << ADC_JDR1_JDATA_Pos)
#define ADC_JDR1_JDATA                      ADC_JDR1_JDATA_Msk

#define ADC_JDR2_JDATA_Pos                  (0U)
#define ADC_JDR2_JDATA_Msk                  (0xFFFFUL << ADC_JDR2_JDATA_Pos)
#define ADC_JDR2_JDATA                      ADC_JDR2_JDATA_Msk

#define ADC_JDR3_JDATA_Pos                  (0U)
#define ADC_JDR3_JDATA_Msk                  (0xFFFFUL << ADC_JDR3_JDATA_Pos)
#define ADC_JDR3_JDATA                      ADC_JDR3_JDATA_Msk

#define ADC_JDR4_JDATA_Pos                  (0U)
#define ADC_JDR4_JDATA_Msk                  (0xFFFFUL << ADC_JDR4_JDATA_Pos)
#define ADC_JDR4_JDATA                      ADC_JDR4_JDATA_Msk

#define ADC_DR_DATA_Pos                     (0U)
#define ADC_DR_DATA_Msk                     (0xFFFFUL << ADC_DR_DATA_Pos)
#define ADC_DR_DATA                         ADC_DR_DATA_Msk
#define ADC_DR_ADC2DATA_Pos                 (16U)
#define ADC_DR_ADC2DATA_Msk                 (0xFFFFUL << ADC_DR_ADC2DATA_Pos)
#define ADC_DR_ADC2DATA                     ADC_DR_ADC2DATA_Msk

#define TIM_CR1_CEN_Pos                     (0U)
#define TIM_CR1_CEN_Msk                     (0x1UL << TIM_CR1_CEN_Pos)
#define TIM_CR1_CEN                         TIM_CR1_CEN_Msk
#define TIM_CR1_UDIS_Pos                    (1U)
#define TIM_CR1_UDIS_Msk                    (0x1UL << TIM_CR1_UDIS_Pos)
#define TIM_CR1_UDIS                        TIM_CR1_UDIS_Msk
#define TIM_CR1_URS_Pos                     (2U)
#define TIM_CR1_URS_Msk                     (0x1UL << TIM_CR1_URS_Pos)
#define TIM_CR1_URS                         TIM_CR1_URS_Msk
#define TIM_CR1_OPM_Pos                     (3U)
#define TIM_CR1_OPM_Msk                     (0x1UL << TIM_CR1_OPM_Pos)
#define TIM_CR1_OPM                         TIM_CR1_OPM_Msk
#define TIM_CR1_DIR_Pos                     (4U)
#define TIM_CR1_DIR_Msk                     (0x1UL << TIM_CR1_DIR_Pos)
#define TIM_CR1_DIR                         TIM_CR1_DIR_Msk

#define TIM_CR1_CMS_Pos                     (5U)
#define TIM_CR1_CMS_Msk                     (0x3UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS                         TIM_CR1_CMS_Msk
#define TIM_CR1_CMS_0                       (0x1UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS_1                       (0x2UL << TIM_CR1_CMS_Pos)

#define TIM_CR1_ARPE_Pos                    (7U)
#define TIM_CR1_ARPE_Msk                    (0x1UL << TIM_CR1_ARPE_Pos)
#define TIM_CR1_ARPE                        TIM_CR1_ARPE_Msk

#define TIM_CR1_CKD_Pos                     (8U)
#define TIM_CR1_CKD_Msk                     (0x3UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD                         TIM_CR1_CKD_Msk
#define TIM_CR1_CKD_0                       (0x1UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD_1                       (0x2UL << TIM_CR1_CKD_Pos)

#define TIM_CR2_CCPC_Pos                    (0U)
#define TIM_CR2_CCPC_Msk                    (0x1UL << TIM_CR2_CCPC_Pos)
#define TIM_CR2_CCPC                        TIM_CR2_CCPC_Msk
#define TIM_CR2_CCUS_Pos                    (2U)
#define TIM_CR2_CCUS_Msk                    (0x1UL << TIM_CR2_CCUS_Pos)
#define TIM_CR2_CCUS                        TIM_CR2_CCUS_Msk
#define TIM_CR2_CCDS_Pos                    (3U)
#define TIM_CR2_CCDS_Msk                    (0x1UL << TIM_CR2_CCDS_Pos)
#define TIM_CR2_CCDS                        TIM_CR2_CCDS_Msk

#define TIM_CR2_MMS_Pos                     (4U)
#define TIM_CR2_MMS_Msk                     (0x7UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS                         TIM_CR2_MMS_Msk
#define TIM_CR2_MMS_0                       (0x1UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_1                       (0x2UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_2                       (0x4UL << TIM_CR2_MMS_Pos)

#define TIM_CR2_TI1S_Pos                    (7U)
#define TIM_CR2_TI1S_Msk                    (0x1UL << TIM_CR2_TI1S_Pos)
#define TIM_CR2_TI1S                        TIM_CR2_TI1S_Msk
#define TIM_CR2_OIS1_Pos                    (8U)
#define TIM_CR2_OIS1_Msk                    (0x1UL << TIM_CR2_OIS1_Pos)
#define TIM_CR2_OIS1                        TIM_CR2_OIS1_Msk
#define TIM_CR2_OIS1N_Pos                   (9U)
#define TIM_CR2_OIS1N_Msk                   (0x1UL << TIM_CR2_OIS1N_Pos)
#define TIM_CR2_OIS1N                       TIM_CR2_OIS1N_Msk
#define TIM_CR2_OIS2_Pos                    (10U)
#define TIM_CR2_OIS2_Msk                    (0x1UL << TIM_CR2_OIS2_Pos)
#define TIM_CR2_OIS2                        TIM_CR2_OIS2_Msk
#define TIM_CR2_OIS2N_Pos                   (11U)
#define TIM_CR2_OIS2N_Msk                   (0x1UL << TIM_CR2_OIS2N_Pos)
#define TIM_CR2_OIS2N                       TIM_CR2_OIS2N_Msk
#define TIM_CR2_OIS3_Pos                    (12U)
#define TIM_CR2_OIS3_Msk                    (0x1UL << TIM_CR2_OIS3_Pos)
#define TIM_CR2_OIS3                        TIM_CR2_OIS3_Msk
#define TIM_CR2_OIS3N_Pos                   (13U)
#define TIM_CR2_OIS3N_Msk                   (0x1UL << TIM_CR2_OIS3N_Pos)
#define TIM_CR2_OIS3N                       TIM_CR2_OIS3N_Msk
#define TIM_CR2_OIS4_Pos                    (14U)
#define TIM_CR2_OIS4_Msk                    (0x1UL << TIM_CR2_OIS4_Pos)
#define TIM_CR2_OIS4                        TIM_CR2_OIS4_Msk

#define TIM_SMCR_SMS_Pos                    (0U)
#define TIM_SMCR_SMS_Msk                    (0x7UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS                        TIM_SMCR_SMS_Msk
#define TIM_SMCR_SMS_0                      (0x1UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_1                      (0x2UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_2                      (0x4UL << TIM_SMCR_SMS_Pos)

#define TIM_SMCR_TS_Pos                     (4U)
#define TIM_SMCR_TS_Msk                     (0x7UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS                         TIM_SMCR_TS_Msk
#define TIM_SMCR_TS_0                       (0x1UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_1                       (0x2UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_2                       (0x4UL << TIM_SMCR_TS_Pos)

#define TIM_SMCR_MSM_Pos                    (7U)
#define TIM_SMCR_MSM_Msk                    (0x1UL << TIM_SMCR_MSM_Pos)
#define TIM_SMCR_MSM                        TIM_SMCR_MSM_Msk

#define TIM_SMCR_ETF_Pos                    (8U)
#define TIM_SMCR_ETF_Msk                    (0xFUL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF                        TIM_SMCR_ETF_Msk
#define TIM_SMCR_ETF_0                      (0x1UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_1                      (0x2UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_2                      (0x4UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_3                      (0x8UL << TIM_SMCR_ETF_Pos)

#define TIM_SMCR_ETPS_Pos                   (12U)
#define TIM_SMCR_ETPS_Msk                   (0x3UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS                       TIM_SMCR_ETPS_Msk
#define TIM_SMCR_ETPS_0                     (0x1UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS_1                     (0x2UL << TIM_SMCR_ETPS_Pos)

#define TIM_SMCR_ECE_Pos                    (14U)
#define TIM_SMCR_ECE_Msk                    (0x1UL << TIM_SMCR_ECE_Pos)
#define TIM_SMCR_ECE                        TIM_SMCR_ECE_Msk
#define TIM_SMCR_ETP_Pos                    (15U)
#define TIM_SMCR_ETP_Msk                    (0x1UL << TIM_SMCR_ETP_Pos)
#define TIM_SMCR_ETP                        TIM_SMCR_ETP_Msk

#define TIM_DIER_UIE_Pos                    (0U)
#define TIM_DIER_UIE_Msk                    (0x1UL << TIM_DIER_UIE_Pos)
#define TIM_DIER_UIE                        TIM_DIER_UIE_Msk
#define TIM_DIER_CC1IE_Pos                  (1U)
#define TIM_DIER_CC1IE_Msk                  (0x1UL << TIM_DIER_CC1IE_Pos)
#define TIM_DIER_CC1IE                      TIM_DIER_CC1IE_Msk
#define TIM_DIER_CC2IE_Pos                  (2U)
#define TIM_DIER_CC2IE_Msk                  (0x1UL << TIM_DIER_CC2IE_Pos)
#define TIM_DIER_CC2IE                      TIM_DIER_CC2IE_Msk
#define TIM_DIER_CC3IE_Pos                  (3U)
#define TIM_DIER_CC3IE_Msk                  (0x1UL << TIM_DIER_CC3IE_Pos)
#define TIM_DIER_CC3IE                      TIM_DIER_CC3IE_Msk
#define TIM_DIER_CC4IE_Pos                  (4U)
#define TIM_DIER_CC4IE_Msk                  (0x1UL << TIM_DIER_CC4IE_Pos)
#define TIM_DIER_CC4IE                      TIM_DIER_CC4IE_Msk
#define TIM_DIER_COMIE_Pos                  (5U)
#define TIM_DIER_COMIE_Msk                  (0x1UL << TIM_DIER_COMIE_Pos)
#define TIM_DIER_COMIE                      TIM_DIER_COMIE_Msk
#define TIM_DIER_TIE_Pos                    (6U)
#define TIM_DIER_TIE_Msk                    (0x1UL << TIM_DIER_TIE_Pos)
#define TIM_DIER_TIE                        TIM_DIER_TIE_Msk
#define TIM_DIER_BIE_Pos                    (7U)
#define TIM_DIER_BIE_Msk                    (0x1UL << TIM_DIER_BIE_Pos)
#define TIM_DIER_BIE                        TIM_DIER_BIE_Msk
#define TIM_DIER_UDE_Pos                    (8U)
#define TIM_DIER_UDE_Msk                    (0x1UL << TIM_DIER_UDE_Pos)
#define TIM_DIER_UDE                        TIM_DIER_UDE_Msk
#define TIM_DIER_CC1DE_Pos                  (9U)
#define TIM_DIER_CC1DE_Msk                  (0x1UL << TIM_DIER_CC1DE_Pos)
#define TIM_DIER_CC1DE                      TIM_DIER_CC1DE_Msk
#define TIM_DIER_CC2DE_Pos                  (10U)
#define TIM_DIER_CC2DE_Msk                  (0x1UL << TIM_DIER_CC2DE_Pos)
#define TIM_DIER_CC2DE                      TIM_DIER_CC2DE_Msk
#define TIM_DIER_CC3DE_Pos                  (11U)
#define TIM_DIER_CC3DE_Msk                  (0x1UL << TIM_DIER_CC3DE_Pos)
#define TIM_DIER_CC3DE                      TIM_DIER_CC3DE_Msk
#define TIM_DIER_CC4DE_Pos                  (12U)
#define TIM_DIER_CC4DE_Msk                  (0x1UL << TIM_DIER_CC4DE_Pos)
#define TIM_DIER_CC4DE                      TIM_DIER_CC4DE_Msk
#define TIM_DIER_COMDE_Pos                  (13U)
#define TIM_DIER_COMDE_Msk                  (0x1UL << TIM_DIER_COMDE_Pos)
#define TIM_DIER_COMDE                      TIM_DIER_COMDE_Msk
#define TIM_DIER_TDE_Pos                    (14U)
#define TIM_DIER_TDE_Msk                    (0x1UL << TIM_DIER_TDE_Pos)
#define TIM_DIER_TDE                        TIM_DIER_TDE_Msk

#define TIM_SR_UIF_Pos                      (0U)
#define TIM_SR_UIF_Msk                      (0x1UL << TIM_SR_UIF_Pos)
#define TIM_SR_UIF                          TIM_SR_UIF_Msk
#define TIM_SR_CC1IF_Pos                    (1U)
#define TIM_SR_CC1IF_Msk                    (0x1UL << TIM_SR_CC1IF_Pos)
#define TIM_SR_CC1IF                        TIM_SR_CC1IF_Msk
#define TIM_SR_CC2IF_Pos                    (2U)
#define TIM_SR_CC2IF_Msk                    (0x1UL << TIM_SR_CC2IF_Pos)
#define TIM_SR_CC2IF                        TIM_SR_CC2IF_Msk
#define TIM_SR_CC3IF_Pos                    (3U)
#define TIM_SR_CC3IF_Msk                    (0x1UL << TIM_SR_CC3IF_Pos)
#define TIM_SR_CC3IF                        TIM_SR_CC3IF_Msk
#define TIM_SR_CC4IF_Pos                    (4U)
#define TIM_SR_CC4IF_Msk                    (0x1UL << TIM_SR_CC4IF_Pos)
#define TIM_SR_CC4IF                        TIM_SR_CC4IF_Msk
#define TIM_SR_COMIF_Pos                    (5U)
#define TIM_SR_COMIF_Msk                    (0x1UL << TIM_SR_COMIF_Pos)
#define TIM_SR_COMIF                        TIM_SR_COMIF_Msk
#define TIM_SR_TIF_Pos                      (6U)
#define TIM_SR_TIF_Msk                      (0x1UL << TIM_SR_TIF_Pos)
#define TIM_SR_TIF                          TIM_SR_TIF_Msk
#define TIM_SR_BIF_Pos                      (7U)
#define TIM_SR_BIF_Msk                      (0x1UL << TIM_SR_BIF_Pos)
#define TIM_SR_BIF                          TIM_SR_BIF_Msk
#define TIM_SR_CC1OF_Pos                    (9U)
#define TIM_SR_CC1OF_Msk                    (0x1UL << TIM_SR_CC1OF_Pos)
#define TIM_SR_CC1OF                        TIM_SR_CC1OF_Msk
#define TIM_SR_CC2OF_Pos                    (10U)
#define TIM_SR_CC2OF_Msk                    (0x1UL << TIM_SR_CC2OF_Pos)
#define TIM_SR_CC2OF                        TIM_SR_CC2OF_Msk
#define TIM_SR_CC3OF_Pos                    (11U)
#define TIM_SR_CC3OF_Msk                    (0x1UL << TIM_SR_CC3OF_Pos)
#define TIM_SR_CC3OF                        TIM_SR_CC3OF_Msk
#define TIM_SR_CC4OF_Pos                    (12U)
#define TIM_SR_CC4OF_Msk                    (0x1UL << TIM_SR_CC4OF_Pos)
#define TIM_SR_CC4OF                        TIM_SR_CC4OF_Msk

#define TIM_EGR_UG_Pos                      (0U)
#define TIM_EGR_UG_Msk                      (0x1UL << TIM_EGR_UG_Pos)
#define TIM_EGR_UG                          TIM_EGR_UG_Msk
#define TIM_EGR_CC1G_Pos                    (1U)
#define TIM_EGR_CC1G_Msk                    (0x1UL << TIM_EGR_CC1G_Pos)
#define TIM_EGR_CC1G                        TIM_EGR_CC1G_Msk
#define TIM_EGR_CC2G_Pos                    (2U)
#define TIM_EGR_CC2G_Msk                    (0x1UL << TIM_EGR_CC2G_Pos)
#define TIM_EGR_CC2G                        TIM_EGR_CC2G_Msk
#define TIM_EGR_CC3G_Pos                    (3U)
#define TIM_EGR_CC3G_Msk                    (0x1UL << TIM_EGR_CC3G_Pos)
#define TIM_EGR_CC3G                        TIM_EGR_CC3G_Msk
#define TIM_EGR_CC4G_Pos                    (4U)
#define TIM_EGR_CC4G_Msk                    (0x1UL << TIM_EGR_CC4G_Pos)
#define TIM_EGR_CC4G                        TIM_EGR_CC4G_Msk
#define TIM_EGR_COMG_Pos                    (5U)
#define TIM_EGR_COMG_Msk                    (0x1UL << TIM_EGR_COMG_Pos)
#define TIM_EGR_COMG                        TIM_EGR_COMG_Msk
#define TIM_EGR_TG_Pos                      (6U)
#define TIM_EGR_TG_Msk                      (0x1UL << TIM_EGR_TG_Pos)
#define TIM_EGR_TG                          TIM_EGR_TG_Msk
#define TIM_EGR_BG_Pos                      (7U)
#define TIM_EGR_BG_Msk                      (0x1UL << TIM_EGR_BG_Pos)
#define TIM_EGR_BG                          TIM_EGR_BG_Msk

#define TIM_CCMR1_CC1S_Pos                  (0U)
#define TIM_CCMR1_CC1S_Msk                  (0x3UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S                      TIM_CCMR1_CC1S_Msk
#define TIM_CCMR1_CC1S_0                    (0x1UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S_1                    (0x2UL << TIM_CCMR1_CC1S_Pos)

#define TIM_CCMR1_OC1FE_Pos                 (2U)
#define TIM_CCMR1_OC1FE_Msk                 (0x1UL << TIM_CCMR1_OC1FE_Pos)
#define TIM_CCMR1_OC1FE                     TIM_CCMR1_OC1FE_Msk
#define TIM_CCMR1_OC1PE_Pos                 (3U)
#define TIM_CCMR1_OC1PE_Msk                 (0x1UL << TIM_CCMR1_OC1PE_Pos)
#define TIM_CCMR1_OC1PE                     TIM_CCMR1_OC1PE_Msk

#define TIM_CCMR1_OC1M_Pos                  (4U)
#define TIM_CCMR1_OC1M_Msk                  (0x7UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M                      TIM_CCMR1_OC1M_Msk
#define TIM_CCMR1_OC1M_0                    (0x1UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_1                    (0x2UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_2                    (0x4UL << TIM_CCMR1_OC1M_Pos)

#define TIM_CCMR1_OC1CE_Pos                 (7U)
#define TIM_CCMR1_OC1CE_Msk                 (0x1UL << TIM_CCMR1_OC1CE_Pos)
#define TIM_CCMR1_OC1CE                     TIM_CCMR1_OC1CE_Msk

#define TIM_CCMR1_CC2S_Pos                  (8U)
#define TIM_CCMR1_CC2S_Msk                  (0x3UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S                      TIM_CCMR1_CC2S_Msk
#define TIM_CCMR1_CC2S_0                    (0x1UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S_1                    (0x2UL << TIM_CCMR1_CC2S_Pos)

#define TIM_CCMR1_OC2FE_Pos                 (10U)
#define TIM_CCMR1_OC2FE_Msk                 (0x1UL << TIM_CCMR1_OC2FE_Pos)
#define TIM_CCMR1_OC2FE                     TIM_CCMR1_OC2FE_Msk
#define TIM_CCMR1_OC2PE_Pos                 (11U)
#define TIM_CCMR1_OC2PE_Msk                 (0x1UL << TIM_CCMR1_OC2PE_Pos)
#define TIM_CCMR1_OC2PE                     TIM_CCMR1_OC2PE_Msk

#define TIM_CCMR1_OC2M_Pos                  (12U)
#define TIM_CCMR1_OC2M_Msk                  (0x7UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M                      TIM_CCMR1_OC2M_Msk
#define TIM_CCMR1_OC2M_0                    (0x1UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_1                    (0x2UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_2                    (0x4UL << TIM_CCMR1_OC2M_Pos)

#define TIM_CCMR1_OC2CE_Pos                 (15U)
#define TIM_CCMR1_OC2CE_Msk                 (0x1UL << TIM_CCMR1_OC2CE_Pos)
#define TIM_CCMR1_OC2CE                     TIM_CCMR1_OC2CE_Msk

#define TIM_CCMR1_IC1PSC_Pos                (2U)
#define TIM_CCMR1_IC1PSC_Msk                (0x3UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC                    TIM_CCMR1_IC1PSC_Msk
#define TIM_CCMR1_IC1PSC_0                  (0x1UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC_1                  (0x2UL << TIM_CCMR1_IC1PSC_Pos)

#define TIM_CCMR1_IC1F_Pos                  (4U)
#define TIM_CCMR1_IC1F_Msk                  (0xFUL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F                      TIM_CCMR1_IC1F_Msk
#define TIM_CCMR1_IC1F_0                    (0x1UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_1                    (0x2UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_2                    (0x4UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_3                    (0x8UL << TIM_CCMR1_IC1F_Pos)

#define TIM_CCMR1_IC2PSC_Pos                (10U)
#define TIM_CCMR1_IC2PSC_Msk                (0x3UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC                    TIM_CCMR1_IC2PSC_Msk
#define TIM_CCMR1_IC2PSC_0                  (0x1UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC_1                  (0x2UL << TIM_CCMR1_IC2PSC_Pos)

#define TIM_CCMR1_IC2F_Pos                  (12U)
#define TIM_CCMR1_IC2F_Msk                  (0xFUL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F                      TIM_CCMR1_IC2F_Msk
#define TIM_CCMR1_IC2F_0                    (0x1UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_1                    (0x2UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_2                    (0x4UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_3                    (0x8UL << TIM_CCMR1_IC2F_Pos)

#define TIM_CCMR2_CC3S_Pos                  (0U)
#define TIM_CCMR2_CC3S_Msk                  (0x3UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S                      TIM_CCMR2_CC3S_Msk
#define TIM_CCMR2_CC3S_0                    (0x1UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S_1                    (0x2UL << TIM_CCMR2_CC3S_Pos)

#define TIM_CCMR2_OC3FE_Pos                 (2U)
#define TIM_CCMR2_OC3FE_Msk                 (0x1UL << TIM_CCMR2_OC3FE_Pos)
#define TIM_CCMR2_OC3FE                     TIM_CCMR2_OC3FE_Msk
#define TIM_CCMR2_OC3PE_Pos                 (3U)
#define TIM_CCMR2_OC3PE_Msk                 (0x1UL << TIM_CCMR2_OC3PE_Pos)
#define TIM_CCMR2_OC3PE                     TIM_CCMR2_OC3PE_Msk

#define TIM_CCMR2_OC3M_Pos                  (4U)
#define TIM_CCMR2_OC3M_Msk                  (0x7UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M                      TIM_CCMR2_OC3M_Msk
#define TIM_CCMR2_OC3M_0                    (0x1UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_1                    (0x2UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_2                    (0x4UL << TIM_CCMR2_OC3M_Pos)

#define TIM_CCMR2_OC3CE_Pos                 (7U)
#define TIM_CCMR2_OC3CE_Msk                 (0x1UL << TIM_CCMR2_OC3CE_Pos)
#define TIM_CCMR2_OC3CE                     TIM_CCMR2_OC3CE_Msk

#define TIM_CCMR2_CC4S_Pos                  (8U)
#define TIM_CCMR2_CC4S_Msk                  (0x3UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S                      TIM_CCMR2_CC4S_Msk
#define TIM_CCMR2_CC4S_0                    (0x1UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S_1                    (0x2UL << TIM_CCMR2_CC4S_Pos)

#define TIM_CCMR2_OC4FE_Pos                 (10U)
#define TIM_CCMR2_OC4FE_Msk                 (0x1UL << TIM_CCMR2_OC4FE_Pos)
#define TIM_CCMR2_OC4FE                     TIM_CCMR2_OC4FE_Msk
#define TIM_CCMR2_OC4PE_Pos                 (11U)
#define TIM_CCMR2_OC4PE_Msk                 (0x1UL << TIM_CCMR2_OC4PE_Pos)
#define TIM_CCMR2_OC4PE                     TIM_CCMR2_OC4PE_Msk

#define TIM_CCMR2_OC4M_Pos                  (12U)
#define TIM_CCMR2_OC4M_Msk                  (0x7UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M                      TIM_CCMR2_OC4M_Msk
#define TIM_CCMR2_OC4M_0                    (0x1UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_1                    (0x2UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_2                    (0x4UL << TIM_CCMR2_OC4M_Pos)

#define TIM_CCMR2_OC4CE_Pos                 (15U)
#define TIM_CCMR2_OC4CE_Msk                 (0x1UL << TIM_CCMR2_OC4CE_Pos)
#define TIM_CCMR2_OC4CE                     TIM_CCMR2_OC4CE_Msk

#define TIM_CCMR2_IC3PSC_Pos                (2U)
#define TIM_CCMR2_IC3PSC_Msk                (0x3UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC                    TIM_CCMR2_IC3PSC_Msk
#define TIM_CCMR2_IC3PSC_0                  (0x1UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC_1                  (0x2UL << TIM_CCMR2_IC3PSC_Pos)

#define TIM_CCMR2_IC3F_Pos                  (4U)
#define TIM_CCMR2_IC3F_Msk                  (0xFUL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F                      TIM_CCMR2_IC3F_Msk
#define TIM_CCMR2_IC3F_0                    (0x1UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_1                    (0x2UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_2                    (0x4UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_3                    (0x8UL << TIM_CCMR2_IC3F_Pos)

#define TIM_CCMR2_IC4PSC_Pos                (10U)
#define TIM_CCMR2_IC4PSC_Msk                (0x3UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC                    TIM_CCMR2_IC4PSC_Msk
#define TIM_CCMR2_IC4PSC_0                  (0x1UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC_1                  (0x2UL << TIM_CCMR2_IC4PSC_Pos)

#define TIM_CCMR2_IC4F_Pos                  (12U)
#define TIM_CCMR2_IC4F_Msk                  (0xFUL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F                      TIM_CCMR2_IC4F_Msk
#define TIM_CCMR2_IC4F_0                    (0x1UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_1                    (0x2UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_2                    (0x4UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_3                    (0x8UL << TIM_CCMR2_IC4F_Pos)

#define TIM_CCER_CC1E_Pos                   (0U)
#define TIM_CCER_CC1E_Msk                   (0x1UL << TIM_CCER_CC1E_Pos)
#define TIM_CCER_CC1E                       TIM_CCER_CC1E_Msk
#define TIM_CCER_CC1P_Pos                   (1U)
#define TIM_CCER_CC1P_Msk                   (0x1UL << TIM_CCER_CC1P_Pos)
#define TIM_CCER_CC1P                       TIM_CCER_CC1P_Msk
#define TIM_CCER_CC1NE_Pos                  (2U)
#define TIM_CCER_CC1NE_Msk                  (0x1UL << TIM_CCER_CC1NE_Pos)
#define TIM_CCER_CC1NE                      TIM_CCER_CC1NE_Msk
#define TIM_CCER_CC1NP_Pos                  (3U)
#define TIM_CCER_CC1NP_Msk                  (0x1UL << TIM_CCER_CC1NP_Pos)
#define TIM_CCER_CC1NP                      TIM_CCER_CC1NP_Msk
#define TIM_CCER_CC2E_Pos                   (4U)
#define TIM_CCER_CC2E_Msk                   (0x1UL << TIM_CCER_CC2E_Pos)
#define TIM_CCER_CC2E                       TIM_CCER_CC2E_Msk
#define TIM_CCER_CC2P_Pos                   (5U)
#define TIM_CCER_CC2P_Msk                   (0x1UL << TIM_CCER_CC2P_Pos)
#define TIM_CCER_CC2P                       TIM_CCER_CC2P_Msk
#define TIM_CCER_CC2NE_Pos                  (6U)
#define TIM_CCER_CC2NE_Msk                  (0x1UL << TIM_CCER_CC2NE_Pos)
#define TIM_CCER_CC2NE                      TIM_CCER_CC2NE_Msk
#define TIM_CCER_CC2NP_Pos                  (7U)
#define TIM_CCER_CC2NP_Msk                  (0x1UL << TIM_CCER_CC2NP_Pos)
#define TIM_CCER_CC2NP                      TIM_CCER_CC2NP_Msk
#define TIM_CCER_CC3E_Pos                   (8U)
#define TIM_CCER_CC3E_Msk                   (0x1UL << TIM_CCER_CC3E_Pos)
#define TIM_CCER_CC3E                       TIM_CCER_CC3E_Msk
#define TIM_CCER_CC3P_Pos                   (9U)
#define TIM_CCER_CC3P_Msk                   (0x1UL << TIM_CCER_CC3P_Pos)
#define TIM_CCER_CC3P                       TIM_CCER_CC3P_Msk
#define TIM_CCER_CC3NE_Pos                  (10U)
#define TIM_CCER_CC3NE_Msk                  (0x1UL << TIM_CCER_CC3NE_Pos)
#define TIM_CCER_CC3NE                      TIM_CCER_CC3NE_Msk
#define TIM_CCER_CC3NP_Pos                  (11U)
#define TIM_CCER_CC3NP_Msk                  (0x1UL << TIM_CCER_CC3NP_Pos)
#define TIM_CCER_CC3NP                      TIM_CCER_CC3NP_Msk
#define TIM_CCER_CC4E_Pos                   (12U)
#define TIM_CCER_CC4E_Msk                   (0x1UL << TIM_CCER_CC4E_Pos)
#define TIM_CCER_CC4E                       TIM_CCER_CC4E_Msk
#define TIM_CCER_CC4P_Pos                   (13U)
#define TIM_CCER_CC4P_Msk                   (0x1UL << TIM_CCER_CC4P_Pos)
#define TIM_CCER_CC4P                       TIM_CCER_CC4P_Msk

#define TIM_CNT_CNT_Pos                     (0U)
#define TIM_CNT_CNT_Msk                     (0xFFFFFFFFUL << TIM_CNT_CNT_Pos)
#define TIM_CNT_CNT                         TIM_CNT_CNT_Msk

#define TIM_PSC_PSC_Pos                     (0U)
#define TIM_PSC_PSC_Msk                     (0xFFFFUL << TIM_PSC_PSC_Pos)
#define TIM_PSC_PSC                         TIM_PSC_PSC_Msk

#define TIM_ARR_ARR_Pos                     (0U)
#define TIM_ARR_ARR_Msk                     (0xFFFFFFFFUL << TIM_ARR_ARR_Pos)
#define TIM_ARR_ARR                         TIM_ARR_ARR_Msk

#define TIM_RCR_REP_Pos                     (0U)
#define TIM_RCR_REP_Msk                     (0xFFUL << TIM_RCR_REP_Pos)
#define TIM_RCR_REP                         TIM_RCR_REP_Msk

#define TIM_CCR1_CCR1_Pos                   (0U)
#define TIM_CCR1_CCR1_Msk                   (0xFFFFUL << TIM_CCR1_CCR1_Pos)
#define TIM_CCR1_CCR1                       TIM_CCR1_CCR1_Msk

#define TIM_CCR2_CCR2_Pos                   (0U)
#define TIM_CCR2_CCR2_Msk                   (0xFFFFUL << TIM_CCR2_CCR2_Pos)
#define TIM_CCR2_CCR2                       TIM_CCR2_CCR2_Msk

#define TIM_CCR3_CCR3_Pos                   (0U)
#define TIM_CCR3_CCR3_Msk                   (0xFFFFUL << TIM_CCR3_CCR3_Pos)
#define TIM_CCR3_CCR3                       TIM_CCR3_CCR3_Msk

#define TIM_CCR4_CCR4_Pos                   (0U)
#define TIM_CCR4_CCR4_Msk                   (0xFFFFUL << TIM_CCR4_CCR4_Pos)
#define TIM_CCR4_CCR4                       TIM_CCR4_CCR4_Msk

#define TIM_BDTR_DTG_Pos                    (0U)
#define TIM_BDTR_DTG_Msk                    (0xFFUL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG                        TIM_BDTR_DTG_Msk
#define TIM_BDTR_DTG_0                      (0x01UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_1                      (0x02UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_2                      (0x04UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_3                      (0x08UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_4                      (0x10UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_5                      (0x20UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_6                      (0x40UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_7                      (0x80UL << TIM_BDTR_DTG_Pos)

#define TIM_BDTR_LOCK_Pos                   (8U)
#define TIM_BDTR_LOCK_Msk                   (0x3UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK                       TIM_BDTR_LOCK_Msk
#define TIM_BDTR_LOCK_0                     (0x1UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK_1                     (0x2UL << TIM_BDTR_LOCK_Pos)

#define TIM_BDTR_OSSI_Pos                   (10U)
#define TIM_BDTR_OSSI_Msk                   (0x1UL << TIM_BDTR_OSSI_Pos)
#define TIM_BDTR_OSSI                       TIM_BDTR_OSSI_Msk
#define TIM_BDTR_OSSR_Pos                   (11U)
#define TIM_BDTR_OSSR_Msk                   (0x1UL << TIM_BDTR_OSSR_Pos)
#define TIM_BDTR_OSSR                       TIM_BDTR_OSSR_Msk
#define TIM_BDTR_BKE_Pos                    (12U)
#define TIM_BDTR_BKE_Msk                    (0x1UL << TIM_BDTR_BKE_Pos)
#define TIM_BDTR_BKE                        TIM_BDTR_BKE_Msk
#define TIM_BDTR_BKP_Pos                    (13U)
#define TIM_BDTR_BKP_Msk                    (0x1UL << TIM_BDTR_BKP_Pos)
#define TIM_BDTR_BKP                        TIM_BDTR_BKP_Msk
#define TIM_BDTR_AOE_Pos                    (14U)
#define TIM_BDTR_AOE_Msk                    (0x1UL << TIM_BDTR_AOE_Pos)
#define TIM_BDTR_AOE                        TIM_BDTR_AOE_Msk
#define TIM_BDTR_MOE_Pos                    (15U)
#define TIM_BDTR_MOE_Msk                    (0x1UL << TIM_BDTR_MOE_Pos)
#define TIM_BDTR_MOE                        TIM_BDTR_MOE_Msk

#define TIM_DCR_DBA_Pos                     (0U)
#define TIM_DCR_DBA_Msk                     (0x1FUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA                         TIM_DCR_DBA_Msk
#define TIM_DCR_DBA_0                       (0x01UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_1                       (0x02UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_2                       (0x04UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_3                       (0x08UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_4                       (0x10UL << TIM_DCR_DBA_Pos)

#define TIM_DCR_DBL_Pos                     (8U)
#define TIM_DCR_DBL_Msk                     (0x1FUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL                         TIM_DCR_DBL_Msk
#define TIM_DCR_DBL_0                       (0x01UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_1                       (0x02UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_2                       (0x04UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_3                       (0x08UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_4                       (0x10UL << TIM_DCR_DBL_Pos)

#define TIM_DMAR_DMAB_Pos                   (0U)
#define TIM_DMAR_DMAB_Msk                   (0xFFFFUL << TIM_DMAR_DMAB_Pos)
#define TIM_DMAR_DMAB                       TIM_DMAR_DMAB_Msk

#define RTC_CRH_SECIE_Pos                   (0U)
#define RTC_CRH_SECIE_Msk                   (0x1UL << RTC_CRH_SECIE_Pos)
#define RTC_CRH_SECIE                       RTC_CRH_SECIE_Msk
#define RTC_CRH_ALRIE_Pos                   (1U)
#define RTC_CRH_ALRIE_Msk                   (0x1UL << RTC_CRH_ALRIE_Pos)
#define RTC_CRH_ALRIE                       RTC_CRH_ALRIE_Msk
#define RTC_CRH_OWIE_Pos                    (2U)
#define RTC_CRH_OWIE_Msk                    (0x1UL << RTC_CRH_OWIE_Pos)
#define RTC_CRH_OWIE                        RTC_CRH_OWIE_Msk

#define RTC_CRL_SECF_Pos                    (0U)
#define RTC_CRL_SECF_Msk                    (0x1UL << RTC_CRL_SECF_Pos)
#define RTC_CRL_SECF                        RTC_CRL_SECF_Msk
#define RTC_CRL_ALRF_Pos                    (1U)
#define RTC_CRL_ALRF_Msk                    (0x1UL << RTC_CRL_ALRF_Pos)
#define RTC_CRL_ALRF                        RTC_CRL_ALRF_Msk
#define RTC_CRL_OWF_Pos                     (2U)
#define RTC_CRL_OWF_Msk                     (0x1UL << RTC_CRL_OWF_Pos)
#define RTC_CRL_OWF                         RTC_CRL_OWF_Msk
#define RTC_CRL_RSF_Pos                     (3U)
#define RTC_CRL_RSF_Msk                     (0x1UL << RTC_CRL_RSF_Pos)
#define RTC_CRL_RSF                         RTC_CRL_RSF_Msk
#define RTC_CRL_CNF_Pos                     (4U)
#define RTC_CRL_CNF_Msk                     (0x1UL << RTC_CRL_CNF_Pos)
#define RTC_CRL_CNF                         RTC_CRL_CNF_Msk
#define RTC_CRL_RTOFF_Pos                   (5U)
#define RTC_CRL_RTOFF_Msk                   (0x1UL << RTC_CRL_RTOFF_Pos)
#define RTC_CRL_RTOFF                       RTC_CRL_RTOFF_Msk

#define RTC_PRLH_PRL_Pos                    (0U)
#define RTC_PRLH_PRL_Msk                    (0xFUL << RTC_PRLH_PRL_Pos)
#define RTC_PRLH_PRL                        RTC_PRLH_PRL_Msk

#define RTC_PRLL_PRL_Pos                    (0U)
#define RTC_PRLL_PRL_Msk                    (0xFFFFUL << RTC_PRLL_PRL_Pos)
#define RTC_PRLL_PRL                        RTC_PRLL_PRL_Msk

#define RTC_DIVH_RTC_DIV_Pos                (0U)
#define RTC_DIVH_RTC_DIV_Msk                (0xFUL << RTC_DIVH_RTC_DIV_Pos)
#define RTC_DIVH_RTC_DIV                    RTC_DIVH_RTC_DIV_Msk

#define RTC_DIVL_RTC_DIV_Pos                (0U)
#define RTC_DIVL_RTC_DIV_Msk                (0xFFFFUL << RTC_DIVL_RTC_DIV_Pos)
#define RTC_DIVL_RTC_DIV                    RTC_DIVL_RTC_DIV_Msk

#define RTC_CNTH_RTC_CNT_Pos                (0U)
#define RTC_CNTH_RTC_CNT_Msk                (0xFFFFUL << RTC_CNTH_RTC_CNT_Pos)
#define RTC_CNTH_RTC_CNT                    RTC_CNTH_RTC_CNT_Msk

#define RTC_CNTL_RTC_CNT_Pos                (0U)
#define RTC_CNTL_RTC_CNT_Msk                (0xFFFFUL << RTC_CNTL_RTC_CNT_Pos)
#define RTC_CNTL_RTC_CNT                    RTC_CNTL_RTC_CNT_Msk

#define RTC_ALRH_RTC_ALR_Pos                (0U)
#define RTC_ALRH_RTC_ALR_Msk                (0xFFFFUL << RTC_ALRH_RTC_ALR_Pos)
#define RTC_ALRH_RTC_ALR                    RTC_ALRH_RTC_ALR_Msk

#define RTC_ALRL_RTC_ALR_Pos                (0U)
#define RTC_ALRL_RTC_ALR_Msk                (0xFFFFUL << RTC_ALRL_RTC_ALR_Pos)
#define RTC_ALRL_RTC_ALR                    RTC_ALRL_RTC_ALR_Msk

#define IWDG_KR_KEY_Pos                     (0U)
#define IWDG_KR_KEY_Msk                     (0xFFFFUL << IWDG_KR_KEY_Pos)
#define IWDG_KR_KEY                         IWDG_KR_KEY_Msk

#define IWDG_PR_PR_Pos                      (0U)
#define IWDG_PR_PR_Msk                      (0x7UL << IWDG_PR_PR_Pos)
#define IWDG_PR_PR                          IWDG_PR_PR_Msk
#define IWDG_PR_PR_0                        (0x1UL << IWDG_PR_PR_Pos)
#define IWDG_PR_PR_1                        (0x2UL << IWDG_PR_PR_Pos)
#define IWDG_PR_PR_2                        (0x4UL << IWDG_PR_PR_Pos)

#define IWDG_RLR_RL_Pos                     (0U)
#define IWDG_RLR_RL_Msk                     (0xFFFUL << IWDG_RLR_RL_Pos)
#define IWDG_RLR_RL                         IWDG_RLR_RL_Msk

#define IWDG_SR_PVU_Pos                     (0U)
#define IWDG_SR_PVU_Msk                     (0x1UL << IWDG_SR_PVU_Pos)
#define IWDG_SR_PVU                         IWDG_SR_PVU_Msk
#define IWDG_SR_RVU_Pos                     (1U)
#define IWDG_SR_RVU_Msk                     (0x1UL << IWDG_SR_RVU_Pos)
#define IWDG_SR_RVU                         IWDG_SR_RVU_Msk

#define WWDG_CR_T_Pos                       (0U)
#define WWDG_CR_T_Msk                       (0x7FUL << WWDG_CR_T_Pos)
#define WWDG_CR_T                           WWDG_CR_T_Msk
#define WWDG_CR_T_0                         (0x01UL << WWDG_CR_T_Pos)
#define WWDG_CR_T_1                         (0x02UL << WWDG_CR_T_Pos)
#define WWDG_CR_T_2                         (0x04UL << WWDG_CR_T_Pos)
#define WWDG_CR_T_3                         (0x08UL << WWDG_CR_T_Pos)
#define WWDG_CR_T_4                         (0x10UL << WWDG_CR_T_Pos)
#define WWDG_CR_T_5                         (0x20UL << WWDG_CR_T_Pos)
#define WWDG_CR_T_6                         (0x40UL << WWDG_CR_T_Pos)

#define  WWDG_CR_T0 WWDG_CR_T_0
#define  WWDG_CR_T1 WWDG_CR_T_1
#define  WWDG_CR_T2 WWDG_CR_T_2
#define  WWDG_CR_T3 WWDG_CR_T_3
#define  WWDG_CR_T4 WWDG_CR_T_4
#define  WWDG_CR_T5 WWDG_CR_T_5
#define  WWDG_CR_T6 WWDG_CR_T_6

#define WWDG_CR_WDGA_Pos                    (7U)
#define WWDG_CR_WDGA_Msk                    (0x1UL << WWDG_CR_WDGA_Pos)
#define WWDG_CR_WDGA                        WWDG_CR_WDGA_Msk

#define WWDG_CFR_W_Pos                      (0U)
#define WWDG_CFR_W_Msk                      (0x7FUL << WWDG_CFR_W_Pos)
#define WWDG_CFR_W                          WWDG_CFR_W_Msk
#define WWDG_CFR_W_0                        (0x01UL << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_1                        (0x02UL << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_2                        (0x04UL << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_3                        (0x08UL << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_4                        (0x10UL << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_5                        (0x20UL << WWDG_CFR_W_Pos)
#define WWDG_CFR_W_6                        (0x40UL << WWDG_CFR_W_Pos)

#define  WWDG_CFR_W0 WWDG_CFR_W_0
#define  WWDG_CFR_W1 WWDG_CFR_W_1
#define  WWDG_CFR_W2 WWDG_CFR_W_2
#define  WWDG_CFR_W3 WWDG_CFR_W_3
#define  WWDG_CFR_W4 WWDG_CFR_W_4
#define  WWDG_CFR_W5 WWDG_CFR_W_5
#define  WWDG_CFR_W6 WWDG_CFR_W_6

#define WWDG_CFR_WDGTB_Pos                  (7U)
#define WWDG_CFR_WDGTB_Msk                  (0x3UL << WWDG_CFR_WDGTB_Pos)
#define WWDG_CFR_WDGTB                      WWDG_CFR_WDGTB_Msk
#define WWDG_CFR_WDGTB_0                    (0x1UL << WWDG_CFR_WDGTB_Pos)
#define WWDG_CFR_WDGTB_1                    (0x2UL << WWDG_CFR_WDGTB_Pos)

#define  WWDG_CFR_WDGTB0 WWDG_CFR_WDGTB_0
#define  WWDG_CFR_WDGTB1 WWDG_CFR_WDGTB_1

#define WWDG_CFR_EWI_Pos                    (9U)
#define WWDG_CFR_EWI_Msk                    (0x1UL << WWDG_CFR_EWI_Pos)
#define WWDG_CFR_EWI                        WWDG_CFR_EWI_Msk

#define WWDG_SR_EWIF_Pos                    (0U)
#define WWDG_SR_EWIF_Msk                    (0x1UL << WWDG_SR_EWIF_Pos)
#define WWDG_SR_EWIF                        WWDG_SR_EWIF_Msk

#define  USB_EP0R                            USB_BASE
#define  USB_EP1R                            (USB_BASE + 0x00000004)
#define  USB_EP2R                            (USB_BASE + 0x00000008)
#define  USB_EP3R                            (USB_BASE + 0x0000000C)
#define  USB_EP4R                            (USB_BASE + 0x00000010)
#define  USB_EP5R                            (USB_BASE + 0x00000014)
#define  USB_EP6R                            (USB_BASE + 0x00000018)
#define  USB_EP7R                            (USB_BASE + 0x0000001C)

#define USB_EP_CTR_RX_Pos                       (15U)
#define USB_EP_CTR_RX_Msk                       (0x1UL << USB_EP_CTR_RX_Pos)
#define USB_EP_CTR_RX                           USB_EP_CTR_RX_Msk
#define USB_EP_DTOG_RX_Pos                      (14U)
#define USB_EP_DTOG_RX_Msk                      (0x1UL << USB_EP_DTOG_RX_Pos)
#define USB_EP_DTOG_RX                          USB_EP_DTOG_RX_Msk
#define USB_EPRX_STAT_Pos                       (12U)
#define USB_EPRX_STAT_Msk                       (0x3UL << USB_EPRX_STAT_Pos)
#define USB_EPRX_STAT                           USB_EPRX_STAT_Msk
#define USB_EP_SETUP_Pos                        (11U)
#define USB_EP_SETUP_Msk                        (0x1UL << USB_EP_SETUP_Pos)
#define USB_EP_SETUP                            USB_EP_SETUP_Msk
#define USB_EP_T_FIELD_Pos                      (9U)
#define USB_EP_T_FIELD_Msk                      (0x3UL << USB_EP_T_FIELD_Pos)
#define USB_EP_T_FIELD                          USB_EP_T_FIELD_Msk
#define USB_EP_KIND_Pos                         (8U)
#define USB_EP_KIND_Msk                         (0x1UL << USB_EP_KIND_Pos)
#define USB_EP_KIND                             USB_EP_KIND_Msk
#define USB_EP_CTR_TX_Pos                       (7U)
#define USB_EP_CTR_TX_Msk                       (0x1UL << USB_EP_CTR_TX_Pos)
#define USB_EP_CTR_TX                           USB_EP_CTR_TX_Msk
#define USB_EP_DTOG_TX_Pos                      (6U)
#define USB_EP_DTOG_TX_Msk                      (0x1UL << USB_EP_DTOG_TX_Pos)
#define USB_EP_DTOG_TX                          USB_EP_DTOG_TX_Msk
#define USB_EPTX_STAT_Pos                       (4U)
#define USB_EPTX_STAT_Msk                       (0x3UL << USB_EPTX_STAT_Pos)
#define USB_EPTX_STAT                           USB_EPTX_STAT_Msk
#define USB_EPADDR_FIELD_Pos                    (0U)
#define USB_EPADDR_FIELD_Msk                    (0xFUL << USB_EPADDR_FIELD_Pos)
#define USB_EPADDR_FIELD                        USB_EPADDR_FIELD_Msk

#define  USB_EPREG_MASK                      (USB_EP_CTR_RX|USB_EP_SETUP|USB_EP_T_FIELD|USB_EP_KIND|USB_EP_CTR_TX|USB_EPADDR_FIELD)

#define USB_EP_TYPE_MASK_Pos                    (9U)
#define USB_EP_TYPE_MASK_Msk                    (0x3UL << USB_EP_TYPE_MASK_Pos)
#define USB_EP_TYPE_MASK                        USB_EP_TYPE_MASK_Msk
#define USB_EP_BULK                             0x00000000U
#define USB_EP_CONTROL                          0x00000200U
#define USB_EP_ISOCHRONOUS                      0x00000400U
#define USB_EP_INTERRUPT                        0x00000600U
#define  USB_EP_T_MASK                          (~USB_EP_T_FIELD & USB_EPREG_MASK)

#define  USB_EPKIND_MASK                        (~USB_EP_KIND & USB_EPREG_MASK)

#define USB_EP_TX_DIS                           0x00000000U
#define USB_EP_TX_STALL                         0x00000010U
#define USB_EP_TX_NAK                           0x00000020U
#define USB_EP_TX_VALID                         0x00000030U
#define USB_EPTX_DTOG1                          0x00000010U
#define USB_EPTX_DTOG2                          0x00000020U
#define  USB_EPTX_DTOGMASK  (USB_EPTX_STAT|USB_EPREG_MASK)

#define USB_EP_RX_DIS                           0x00000000U
#define USB_EP_RX_STALL                         0x00001000U
#define USB_EP_RX_NAK                           0x00002000U
#define USB_EP_RX_VALID                         0x00003000U
#define USB_EPRX_DTOG1                          0x00001000U
#define USB_EPRX_DTOG2                          0x00002000U
#define  USB_EPRX_DTOGMASK  (USB_EPRX_STAT|USB_EPREG_MASK)

#define USB_EP0R_EA_Pos                         (0U)
#define USB_EP0R_EA_Msk                         (0xFUL << USB_EP0R_EA_Pos)
#define USB_EP0R_EA                             USB_EP0R_EA_Msk

#define USB_EP0R_STAT_TX_Pos                    (4U)
#define USB_EP0R_STAT_TX_Msk                    (0x3UL << USB_EP0R_STAT_TX_Pos)
#define USB_EP0R_STAT_TX                        USB_EP0R_STAT_TX_Msk
#define USB_EP0R_STAT_TX_0                      (0x1UL << USB_EP0R_STAT_TX_Pos)
#define USB_EP0R_STAT_TX_1                      (0x2UL << USB_EP0R_STAT_TX_Pos)

#define USB_EP0R_DTOG_TX_Pos                    (6U)
#define USB_EP0R_DTOG_TX_Msk                    (0x1UL << USB_EP0R_DTOG_TX_Pos)
#define USB_EP0R_DTOG_TX                        USB_EP0R_DTOG_TX_Msk
#define USB_EP0R_CTR_TX_Pos                     (7U)
#define USB_EP0R_CTR_TX_Msk                     (0x1UL << USB_EP0R_CTR_TX_Pos)
#define USB_EP0R_CTR_TX                         USB_EP0R_CTR_TX_Msk
#define USB_EP0R_EP_KIND_Pos                    (8U)
#define USB_EP0R_EP_KIND_Msk                    (0x1UL << USB_EP0R_EP_KIND_Pos)
#define USB_EP0R_EP_KIND                        USB_EP0R_EP_KIND_Msk

#define USB_EP0R_EP_TYPE_Pos                    (9U)
#define USB_EP0R_EP_TYPE_Msk                    (0x3UL << USB_EP0R_EP_TYPE_Pos)
#define USB_EP0R_EP_TYPE                        USB_EP0R_EP_TYPE_Msk
#define USB_EP0R_EP_TYPE_0                      (0x1UL << USB_EP0R_EP_TYPE_Pos)
#define USB_EP0R_EP_TYPE_1                      (0x2UL << USB_EP0R_EP_TYPE_Pos)

#define USB_EP0R_SETUP_Pos                      (11U)
#define USB_EP0R_SETUP_Msk                      (0x1UL << USB_EP0R_SETUP_Pos)
#define USB_EP0R_SETUP                          USB_EP0R_SETUP_Msk

#define USB_EP0R_STAT_RX_Pos                    (12U)
#define USB_EP0R_STAT_RX_Msk                    (0x3UL << USB_EP0R_STAT_RX_Pos)
#define USB_EP0R_STAT_RX                        USB_EP0R_STAT_RX_Msk
#define USB_EP0R_STAT_RX_0                      (0x1UL << USB_EP0R_STAT_RX_Pos)
#define USB_EP0R_STAT_RX_1                      (0x2UL << USB_EP0R_STAT_RX_Pos)

#define USB_EP0R_DTOG_RX_Pos                    (14U)
#define USB_EP0R_DTOG_RX_Msk                    (0x1UL << USB_EP0R_DTOG_RX_Pos)
#define USB_EP0R_DTOG_RX                        USB_EP0R_DTOG_RX_Msk
#define USB_EP0R_CTR_RX_Pos                     (15U)
#define USB_EP0R_CTR_RX_Msk                     (0x1UL << USB_EP0R_CTR_RX_Pos)
#define USB_EP0R_CTR_RX                         USB_EP0R_CTR_RX_Msk

#define USB_EP1R_EA_Pos                         (0U)
#define USB_EP1R_EA_Msk                         (0xFUL << USB_EP1R_EA_Pos)
#define USB_EP1R_EA                             USB_EP1R_EA_Msk

#define USB_EP1R_STAT_TX_Pos                    (4U)
#define USB_EP1R_STAT_TX_Msk                    (0x3UL << USB_EP1R_STAT_TX_Pos)
#define USB_EP1R_STAT_TX                        USB_EP1R_STAT_TX_Msk
#define USB_EP1R_STAT_TX_0                      (0x1UL << USB_EP1R_STAT_TX_Pos)
#define USB_EP1R_STAT_TX_1                      (0x2UL << USB_EP1R_STAT_TX_Pos)

#define USB_EP1R_DTOG_TX_Pos                    (6U)
#define USB_EP1R_DTOG_TX_Msk                    (0x1UL << USB_EP1R_DTOG_TX_Pos)
#define USB_EP1R_DTOG_TX                        USB_EP1R_DTOG_TX_Msk
#define USB_EP1R_CTR_TX_Pos                     (7U)
#define USB_EP1R_CTR_TX_Msk                     (0x1UL << USB_EP1R_CTR_TX_Pos)
#define USB_EP1R_CTR_TX                         USB_EP1R_CTR_TX_Msk
#define USB_EP1R_EP_KIND_Pos                    (8U)
#define USB_EP1R_EP_KIND_Msk                    (0x1UL << USB_EP1R_EP_KIND_Pos)
#define USB_EP1R_EP_KIND                        USB_EP1R_EP_KIND_Msk

#define USB_EP1R_EP_TYPE_Pos                    (9U)
#define USB_EP1R_EP_TYPE_Msk                    (0x3UL << USB_EP1R_EP_TYPE_Pos)
#define USB_EP1R_EP_TYPE                        USB_EP1R_EP_TYPE_Msk
#define USB_EP1R_EP_TYPE_0                      (0x1UL << USB_EP1R_EP_TYPE_Pos)
#define USB_EP1R_EP_TYPE_1                      (0x2UL << USB_EP1R_EP_TYPE_Pos)

#define USB_EP1R_SETUP_Pos                      (11U)
#define USB_EP1R_SETUP_Msk                      (0x1UL << USB_EP1R_SETUP_Pos)
#define USB_EP1R_SETUP                          USB_EP1R_SETUP_Msk

#define USB_EP1R_STAT_RX_Pos                    (12U)
#define USB_EP1R_STAT_RX_Msk                    (0x3UL << USB_EP1R_STAT_RX_Pos)
#define USB_EP1R_STAT_RX                        USB_EP1R_STAT_RX_Msk
#define USB_EP1R_STAT_RX_0                      (0x1UL << USB_EP1R_STAT_RX_Pos)
#define USB_EP1R_STAT_RX_1                      (0x2UL << USB_EP1R_STAT_RX_Pos)

#define USB_EP1R_DTOG_RX_Pos                    (14U)
#define USB_EP1R_DTOG_RX_Msk                    (0x1UL << USB_EP1R_DTOG_RX_Pos)
#define USB_EP1R_DTOG_RX                        USB_EP1R_DTOG_RX_Msk
#define USB_EP1R_CTR_RX_Pos                     (15U)
#define USB_EP1R_CTR_RX_Msk                     (0x1UL << USB_EP1R_CTR_RX_Pos)
#define USB_EP1R_CTR_RX                         USB_EP1R_CTR_RX_Msk

#define USB_EP2R_EA_Pos                         (0U)
#define USB_EP2R_EA_Msk                         (0xFUL << USB_EP2R_EA_Pos)
#define USB_EP2R_EA                             USB_EP2R_EA_Msk

#define USB_EP2R_STAT_TX_Pos                    (4U)
#define USB_EP2R_STAT_TX_Msk                    (0x3UL << USB_EP2R_STAT_TX_Pos)
#define USB_EP2R_STAT_TX                        USB_EP2R_STAT_TX_Msk
#define USB_EP2R_STAT_TX_0                      (0x1UL << USB_EP2R_STAT_TX_Pos)
#define USB_EP2R_STAT_TX_1                      (0x2UL << USB_EP2R_STAT_TX_Pos)

#define USB_EP2R_DTOG_TX_Pos                    (6U)
#define USB_EP2R_DTOG_TX_Msk                    (0x1UL << USB_EP2R_DTOG_TX_Pos)
#define USB_EP2R_DTOG_TX                        USB_EP2R_DTOG_TX_Msk
#define USB_EP2R_CTR_TX_Pos                     (7U)
#define USB_EP2R_CTR_TX_Msk                     (0x1UL << USB_EP2R_CTR_TX_Pos)
#define USB_EP2R_CTR_TX                         USB_EP2R_CTR_TX_Msk
#define USB_EP2R_EP_KIND_Pos                    (8U)
#define USB_EP2R_EP_KIND_Msk                    (0x1UL << USB_EP2R_EP_KIND_Pos)
#define USB_EP2R_EP_KIND                        USB_EP2R_EP_KIND_Msk

#define USB_EP2R_EP_TYPE_Pos                    (9U)
#define USB_EP2R_EP_TYPE_Msk                    (0x3UL << USB_EP2R_EP_TYPE_Pos)
#define USB_EP2R_EP_TYPE                        USB_EP2R_EP_TYPE_Msk
#define USB_EP2R_EP_TYPE_0                      (0x1UL << USB_EP2R_EP_TYPE_Pos)
#define USB_EP2R_EP_TYPE_1                      (0x2UL << USB_EP2R_EP_TYPE_Pos)

#define USB_EP2R_SETUP_Pos                      (11U)
#define USB_EP2R_SETUP_Msk                      (0x1UL << USB_EP2R_SETUP_Pos)
#define USB_EP2R_SETUP                          USB_EP2R_SETUP_Msk

#define USB_EP2R_STAT_RX_Pos                    (12U)
#define USB_EP2R_STAT_RX_Msk                    (0x3UL << USB_EP2R_STAT_RX_Pos)
#define USB_EP2R_STAT_RX                        USB_EP2R_STAT_RX_Msk
#define USB_EP2R_STAT_RX_0                      (0x1UL << USB_EP2R_STAT_RX_Pos)
#define USB_EP2R_STAT_RX_1                      (0x2UL << USB_EP2R_STAT_RX_Pos)

#define USB_EP2R_DTOG_RX_Pos                    (14U)
#define USB_EP2R_DTOG_RX_Msk                    (0x1UL << USB_EP2R_DTOG_RX_Pos)
#define USB_EP2R_DTOG_RX                        USB_EP2R_DTOG_RX_Msk
#define USB_EP2R_CTR_RX_Pos                     (15U)
#define USB_EP2R_CTR_RX_Msk                     (0x1UL << USB_EP2R_CTR_RX_Pos)
#define USB_EP2R_CTR_RX                         USB_EP2R_CTR_RX_Msk

#define USB_EP3R_EA_Pos                         (0U)
#define USB_EP3R_EA_Msk                         (0xFUL << USB_EP3R_EA_Pos)
#define USB_EP3R_EA                             USB_EP3R_EA_Msk

#define USB_EP3R_STAT_TX_Pos                    (4U)
#define USB_EP3R_STAT_TX_Msk                    (0x3UL << USB_EP3R_STAT_TX_Pos)
#define USB_EP3R_STAT_TX                        USB_EP3R_STAT_TX_Msk
#define USB_EP3R_STAT_TX_0                      (0x1UL << USB_EP3R_STAT_TX_Pos)
#define USB_EP3R_STAT_TX_1                      (0x2UL << USB_EP3R_STAT_TX_Pos)

#define USB_EP3R_DTOG_TX_Pos                    (6U)
#define USB_EP3R_DTOG_TX_Msk                    (0x1UL << USB_EP3R_DTOG_TX_Pos)
#define USB_EP3R_DTOG_TX                        USB_EP3R_DTOG_TX_Msk
#define USB_EP3R_CTR_TX_Pos                     (7U)
#define USB_EP3R_CTR_TX_Msk                     (0x1UL << USB_EP3R_CTR_TX_Pos)
#define USB_EP3R_CTR_TX                         USB_EP3R_CTR_TX_Msk
#define USB_EP3R_EP_KIND_Pos                    (8U)
#define USB_EP3R_EP_KIND_Msk                    (0x1UL << USB_EP3R_EP_KIND_Pos)
#define USB_EP3R_EP_KIND                        USB_EP3R_EP_KIND_Msk

#define USB_EP3R_EP_TYPE_Pos                    (9U)
#define USB_EP3R_EP_TYPE_Msk                    (0x3UL << USB_EP3R_EP_TYPE_Pos)
#define USB_EP3R_EP_TYPE                        USB_EP3R_EP_TYPE_Msk
#define USB_EP3R_EP_TYPE_0                      (0x1UL << USB_EP3R_EP_TYPE_Pos)
#define USB_EP3R_EP_TYPE_1                      (0x2UL << USB_EP3R_EP_TYPE_Pos)

#define USB_EP3R_SETUP_Pos                      (11U)
#define USB_EP3R_SETUP_Msk                      (0x1UL << USB_EP3R_SETUP_Pos)
#define USB_EP3R_SETUP                          USB_EP3R_SETUP_Msk

#define USB_EP3R_STAT_RX_Pos                    (12U)
#define USB_EP3R_STAT_RX_Msk                    (0x3UL << USB_EP3R_STAT_RX_Pos)
#define USB_EP3R_STAT_RX                        USB_EP3R_STAT_RX_Msk
#define USB_EP3R_STAT_RX_0                      (0x1UL << USB_EP3R_STAT_RX_Pos)
#define USB_EP3R_STAT_RX_1                      (0x2UL << USB_EP3R_STAT_RX_Pos)

#define USB_EP3R_DTOG_RX_Pos                    (14U)
#define USB_EP3R_DTOG_RX_Msk                    (0x1UL << USB_EP3R_DTOG_RX_Pos)
#define USB_EP3R_DTOG_RX                        USB_EP3R_DTOG_RX_Msk
#define USB_EP3R_CTR_RX_Pos                     (15U)
#define USB_EP3R_CTR_RX_Msk                     (0x1UL << USB_EP3R_CTR_RX_Pos)
#define USB_EP3R_CTR_RX                         USB_EP3R_CTR_RX_Msk

#define USB_EP4R_EA_Pos                         (0U)
#define USB_EP4R_EA_Msk                         (0xFUL << USB_EP4R_EA_Pos)
#define USB_EP4R_EA                             USB_EP4R_EA_Msk

#define USB_EP4R_STAT_TX_Pos                    (4U)
#define USB_EP4R_STAT_TX_Msk                    (0x3UL << USB_EP4R_STAT_TX_Pos)
#define USB_EP4R_STAT_TX                        USB_EP4R_STAT_TX_Msk
#define USB_EP4R_STAT_TX_0                      (0x1UL << USB_EP4R_STAT_TX_Pos)
#define USB_EP4R_STAT_TX_1                      (0x2UL << USB_EP4R_STAT_TX_Pos)

#define USB_EP4R_DTOG_TX_Pos                    (6U)
#define USB_EP4R_DTOG_TX_Msk                    (0x1UL << USB_EP4R_DTOG_TX_Pos)
#define USB_EP4R_DTOG_TX                        USB_EP4R_DTOG_TX_Msk
#define USB_EP4R_CTR_TX_Pos                     (7U)
#define USB_EP4R_CTR_TX_Msk                     (0x1UL << USB_EP4R_CTR_TX_Pos)
#define USB_EP4R_CTR_TX                         USB_EP4R_CTR_TX_Msk
#define USB_EP4R_EP_KIND_Pos                    (8U)
#define USB_EP4R_EP_KIND_Msk                    (0x1UL << USB_EP4R_EP_KIND_Pos)
#define USB_EP4R_EP_KIND                        USB_EP4R_EP_KIND_Msk

#define USB_EP4R_EP_TYPE_Pos                    (9U)
#define USB_EP4R_EP_TYPE_Msk                    (0x3UL << USB_EP4R_EP_TYPE_Pos)
#define USB_EP4R_EP_TYPE                        USB_EP4R_EP_TYPE_Msk
#define USB_EP4R_EP_TYPE_0                      (0x1UL << USB_EP4R_EP_TYPE_Pos)
#define USB_EP4R_EP_TYPE_1                      (0x2UL << USB_EP4R_EP_TYPE_Pos)

#define USB_EP4R_SETUP_Pos                      (11U)
#define USB_EP4R_SETUP_Msk                      (0x1UL << USB_EP4R_SETUP_Pos)
#define USB_EP4R_SETUP                          USB_EP4R_SETUP_Msk

#define USB_EP4R_STAT_RX_Pos                    (12U)
#define USB_EP4R_STAT_RX_Msk                    (0x3UL << USB_EP4R_STAT_RX_Pos)
#define USB_EP4R_STAT_RX                        USB_EP4R_STAT_RX_Msk
#define USB_EP4R_STAT_RX_0                      (0x1UL << USB_EP4R_STAT_RX_Pos)
#define USB_EP4R_STAT_RX_1                      (0x2UL << USB_EP4R_STAT_RX_Pos)

#define USB_EP4R_DTOG_RX_Pos                    (14U)
#define USB_EP4R_DTOG_RX_Msk                    (0x1UL << USB_EP4R_DTOG_RX_Pos)
#define USB_EP4R_DTOG_RX                        USB_EP4R_DTOG_RX_Msk
#define USB_EP4R_CTR_RX_Pos                     (15U)
#define USB_EP4R_CTR_RX_Msk                     (0x1UL << USB_EP4R_CTR_RX_Pos)
#define USB_EP4R_CTR_RX                         USB_EP4R_CTR_RX_Msk

#define USB_EP5R_EA_Pos                         (0U)
#define USB_EP5R_EA_Msk                         (0xFUL << USB_EP5R_EA_Pos)
#define USB_EP5R_EA                             USB_EP5R_EA_Msk

#define USB_EP5R_STAT_TX_Pos                    (4U)
#define USB_EP5R_STAT_TX_Msk                    (0x3UL << USB_EP5R_STAT_TX_Pos)
#define USB_EP5R_STAT_TX                        USB_EP5R_STAT_TX_Msk
#define USB_EP5R_STAT_TX_0                      (0x1UL << USB_EP5R_STAT_TX_Pos)
#define USB_EP5R_STAT_TX_1                      (0x2UL << USB_EP5R_STAT_TX_Pos)

#define USB_EP5R_DTOG_TX_Pos                    (6U)
#define USB_EP5R_DTOG_TX_Msk                    (0x1UL << USB_EP5R_DTOG_TX_Pos)
#define USB_EP5R_DTOG_TX                        USB_EP5R_DTOG_TX_Msk
#define USB_EP5R_CTR_TX_Pos                     (7U)
#define USB_EP5R_CTR_TX_Msk                     (0x1UL << USB_EP5R_CTR_TX_Pos)
#define USB_EP5R_CTR_TX                         USB_EP5R_CTR_TX_Msk
#define USB_EP5R_EP_KIND_Pos                    (8U)
#define USB_EP5R_EP_KIND_Msk                    (0x1UL << USB_EP5R_EP_KIND_Pos)
#define USB_EP5R_EP_KIND                        USB_EP5R_EP_KIND_Msk

#define USB_EP5R_EP_TYPE_Pos                    (9U)
#define USB_EP5R_EP_TYPE_Msk                    (0x3UL << USB_EP5R_EP_TYPE_Pos)
#define USB_EP5R_EP_TYPE                        USB_EP5R_EP_TYPE_Msk
#define USB_EP5R_EP_TYPE_0                      (0x1UL << USB_EP5R_EP_TYPE_Pos)
#define USB_EP5R_EP_TYPE_1                      (0x2UL << USB_EP5R_EP_TYPE_Pos)

#define USB_EP5R_SETUP_Pos                      (11U)
#define USB_EP5R_SETUP_Msk                      (0x1UL << USB_EP5R_SETUP_Pos)
#define USB_EP5R_SETUP                          USB_EP5R_SETUP_Msk

#define USB_EP5R_STAT_RX_Pos                    (12U)
#define USB_EP5R_STAT_RX_Msk                    (0x3UL << USB_EP5R_STAT_RX_Pos)
#define USB_EP5R_STAT_RX                        USB_EP5R_STAT_RX_Msk
#define USB_EP5R_STAT_RX_0                      (0x1UL << USB_EP5R_STAT_RX_Pos)
#define USB_EP5R_STAT_RX_1                      (0x2UL << USB_EP5R_STAT_RX_Pos)

#define USB_EP5R_DTOG_RX_Pos                    (14U)
#define USB_EP5R_DTOG_RX_Msk                    (0x1UL << USB_EP5R_DTOG_RX_Pos)
#define USB_EP5R_DTOG_RX                        USB_EP5R_DTOG_RX_Msk
#define USB_EP5R_CTR_RX_Pos                     (15U)
#define USB_EP5R_CTR_RX_Msk                     (0x1UL << USB_EP5R_CTR_RX_Pos)
#define USB_EP5R_CTR_RX                         USB_EP5R_CTR_RX_Msk

#define USB_EP6R_EA_Pos                         (0U)
#define USB_EP6R_EA_Msk                         (0xFUL << USB_EP6R_EA_Pos)
#define USB_EP6R_EA                             USB_EP6R_EA_Msk

#define USB_EP6R_STAT_TX_Pos                    (4U)
#define USB_EP6R_STAT_TX_Msk                    (0x3UL << USB_EP6R_STAT_TX_Pos)
#define USB_EP6R_STAT_TX                        USB_EP6R_STAT_TX_Msk
#define USB_EP6R_STAT_TX_0                      (0x1UL << USB_EP6R_STAT_TX_Pos)
#define USB_EP6R_STAT_TX_1                      (0x2UL << USB_EP6R_STAT_TX_Pos)

#define USB_EP6R_DTOG_TX_Pos                    (6U)
#define USB_EP6R_DTOG_TX_Msk                    (0x1UL << USB_EP6R_DTOG_TX_Pos)
#define USB_EP6R_DTOG_TX                        USB_EP6R_DTOG_TX_Msk
#define USB_EP6R_CTR_TX_Pos                     (7U)
#define USB_EP6R_CTR_TX_Msk                     (0x1UL << USB_EP6R_CTR_TX_Pos)
#define USB_EP6R_CTR_TX                         USB_EP6R_CTR_TX_Msk
#define USB_EP6R_EP_KIND_Pos                    (8U)
#define USB_EP6R_EP_KIND_Msk                    (0x1UL << USB_EP6R_EP_KIND_Pos)
#define USB_EP6R_EP_KIND                        USB_EP6R_EP_KIND_Msk

#define USB_EP6R_EP_TYPE_Pos                    (9U)
#define USB_EP6R_EP_TYPE_Msk                    (0x3UL << USB_EP6R_EP_TYPE_Pos)
#define USB_EP6R_EP_TYPE                        USB_EP6R_EP_TYPE_Msk
#define USB_EP6R_EP_TYPE_0                      (0x1UL << USB_EP6R_EP_TYPE_Pos)
#define USB_EP6R_EP_TYPE_1                      (0x2UL << USB_EP6R_EP_TYPE_Pos)

#define USB_EP6R_SETUP_Pos                      (11U)
#define USB_EP6R_SETUP_Msk                      (0x1UL << USB_EP6R_SETUP_Pos)
#define USB_EP6R_SETUP                          USB_EP6R_SETUP_Msk

#define USB_EP6R_STAT_RX_Pos                    (12U)
#define USB_EP6R_STAT_RX_Msk                    (0x3UL << USB_EP6R_STAT_RX_Pos)
#define USB_EP6R_STAT_RX                        USB_EP6R_STAT_RX_Msk
#define USB_EP6R_STAT_RX_0                      (0x1UL << USB_EP6R_STAT_RX_Pos)
#define USB_EP6R_STAT_RX_1                      (0x2UL << USB_EP6R_STAT_RX_Pos)

#define USB_EP6R_DTOG_RX_Pos                    (14U)
#define USB_EP6R_DTOG_RX_Msk                    (0x1UL << USB_EP6R_DTOG_RX_Pos)
#define USB_EP6R_DTOG_RX                        USB_EP6R_DTOG_RX_Msk
#define USB_EP6R_CTR_RX_Pos                     (15U)
#define USB_EP6R_CTR_RX_Msk                     (0x1UL << USB_EP6R_CTR_RX_Pos)
#define USB_EP6R_CTR_RX                         USB_EP6R_CTR_RX_Msk

#define USB_EP7R_EA_Pos                         (0U)
#define USB_EP7R_EA_Msk                         (0xFUL << USB_EP7R_EA_Pos)
#define USB_EP7R_EA                             USB_EP7R_EA_Msk

#define USB_EP7R_STAT_TX_Pos                    (4U)
#define USB_EP7R_STAT_TX_Msk                    (0x3UL << USB_EP7R_STAT_TX_Pos)
#define USB_EP7R_STAT_TX                        USB_EP7R_STAT_TX_Msk
#define USB_EP7R_STAT_TX_0                      (0x1UL << USB_EP7R_STAT_TX_Pos)
#define USB_EP7R_STAT_TX_1                      (0x2UL << USB_EP7R_STAT_TX_Pos)

#define USB_EP7R_DTOG_TX_Pos                    (6U)
#define USB_EP7R_DTOG_TX_Msk                    (0x1UL << USB_EP7R_DTOG_TX_Pos)
#define USB_EP7R_DTOG_TX                        USB_EP7R_DTOG_TX_Msk
#define USB_EP7R_CTR_TX_Pos                     (7U)
#define USB_EP7R_CTR_TX_Msk                     (0x1UL << USB_EP7R_CTR_TX_Pos)
#define USB_EP7R_CTR_TX                         USB_EP7R_CTR_TX_Msk
#define USB_EP7R_EP_KIND_Pos                    (8U)
#define USB_EP7R_EP_KIND_Msk                    (0x1UL << USB_EP7R_EP_KIND_Pos)
#define USB_EP7R_EP_KIND                        USB_EP7R_EP_KIND_Msk

#define USB_EP7R_EP_TYPE_Pos                    (9U)
#define USB_EP7R_EP_TYPE_Msk                    (0x3UL << USB_EP7R_EP_TYPE_Pos)
#define USB_EP7R_EP_TYPE                        USB_EP7R_EP_TYPE_Msk
#define USB_EP7R_EP_TYPE_0                      (0x1UL << USB_EP7R_EP_TYPE_Pos)
#define USB_EP7R_EP_TYPE_1                      (0x2UL << USB_EP7R_EP_TYPE_Pos)

#define USB_EP7R_SETUP_Pos                      (11U)
#define USB_EP7R_SETUP_Msk                      (0x1UL << USB_EP7R_SETUP_Pos)
#define USB_EP7R_SETUP                          USB_EP7R_SETUP_Msk

#define USB_EP7R_STAT_RX_Pos                    (12U)
#define USB_EP7R_STAT_RX_Msk                    (0x3UL << USB_EP7R_STAT_RX_Pos)
#define USB_EP7R_STAT_RX                        USB_EP7R_STAT_RX_Msk
#define USB_EP7R_STAT_RX_0                      (0x1UL << USB_EP7R_STAT_RX_Pos)
#define USB_EP7R_STAT_RX_1                      (0x2UL << USB_EP7R_STAT_RX_Pos)

#define USB_EP7R_DTOG_RX_Pos                    (14U)
#define USB_EP7R_DTOG_RX_Msk                    (0x1UL << USB_EP7R_DTOG_RX_Pos)
#define USB_EP7R_DTOG_RX                        USB_EP7R_DTOG_RX_Msk
#define USB_EP7R_CTR_RX_Pos                     (15U)
#define USB_EP7R_CTR_RX_Msk                     (0x1UL << USB_EP7R_CTR_RX_Pos)
#define USB_EP7R_CTR_RX                         USB_EP7R_CTR_RX_Msk

#define USB_CNTR_FRES_Pos                       (0U)
#define USB_CNTR_FRES_Msk                       (0x1UL << USB_CNTR_FRES_Pos)
#define USB_CNTR_FRES                           USB_CNTR_FRES_Msk
#define USB_CNTR_PDWN_Pos                       (1U)
#define USB_CNTR_PDWN_Msk                       (0x1UL << USB_CNTR_PDWN_Pos)
#define USB_CNTR_PDWN                           USB_CNTR_PDWN_Msk
#define USB_CNTR_LP_MODE_Pos                    (2U)
#define USB_CNTR_LP_MODE_Msk                    (0x1UL << USB_CNTR_LP_MODE_Pos)
#define USB_CNTR_LP_MODE                        USB_CNTR_LP_MODE_Msk
#define USB_CNTR_FSUSP_Pos                      (3U)
#define USB_CNTR_FSUSP_Msk                      (0x1UL << USB_CNTR_FSUSP_Pos)
#define USB_CNTR_FSUSP                          USB_CNTR_FSUSP_Msk
#define USB_CNTR_RESUME_Pos                     (4U)
#define USB_CNTR_RESUME_Msk                     (0x1UL << USB_CNTR_RESUME_Pos)
#define USB_CNTR_RESUME                         USB_CNTR_RESUME_Msk
#define USB_CNTR_ESOFM_Pos                      (8U)
#define USB_CNTR_ESOFM_Msk                      (0x1UL << USB_CNTR_ESOFM_Pos)
#define USB_CNTR_ESOFM                          USB_CNTR_ESOFM_Msk
#define USB_CNTR_SOFM_Pos                       (9U)
#define USB_CNTR_SOFM_Msk                       (0x1UL << USB_CNTR_SOFM_Pos)
#define USB_CNTR_SOFM                           USB_CNTR_SOFM_Msk
#define USB_CNTR_RESETM_Pos                     (10U)
#define USB_CNTR_RESETM_Msk                     (0x1UL << USB_CNTR_RESETM_Pos)
#define USB_CNTR_RESETM                         USB_CNTR_RESETM_Msk
#define USB_CNTR_SUSPM_Pos                      (11U)
#define USB_CNTR_SUSPM_Msk                      (0x1UL << USB_CNTR_SUSPM_Pos)
#define USB_CNTR_SUSPM                          USB_CNTR_SUSPM_Msk
#define USB_CNTR_WKUPM_Pos                      (12U)
#define USB_CNTR_WKUPM_Msk                      (0x1UL << USB_CNTR_WKUPM_Pos)
#define USB_CNTR_WKUPM                          USB_CNTR_WKUPM_Msk
#define USB_CNTR_ERRM_Pos                       (13U)
#define USB_CNTR_ERRM_Msk                       (0x1UL << USB_CNTR_ERRM_Pos)
#define USB_CNTR_ERRM                           USB_CNTR_ERRM_Msk
#define USB_CNTR_PMAOVRM_Pos                    (14U)
#define USB_CNTR_PMAOVRM_Msk                    (0x1UL << USB_CNTR_PMAOVRM_Pos)
#define USB_CNTR_PMAOVRM                        USB_CNTR_PMAOVRM_Msk
#define USB_CNTR_CTRM_Pos                       (15U)
#define USB_CNTR_CTRM_Msk                       (0x1UL << USB_CNTR_CTRM_Pos)
#define USB_CNTR_CTRM                           USB_CNTR_CTRM_Msk

#define USB_ISTR_EP_ID_Pos                      (0U)
#define USB_ISTR_EP_ID_Msk                      (0xFUL << USB_ISTR_EP_ID_Pos)
#define USB_ISTR_EP_ID                          USB_ISTR_EP_ID_Msk
#define USB_ISTR_DIR_Pos                        (4U)
#define USB_ISTR_DIR_Msk                        (0x1UL << USB_ISTR_DIR_Pos)
#define USB_ISTR_DIR                            USB_ISTR_DIR_Msk
#define USB_ISTR_ESOF_Pos                       (8U)
#define USB_ISTR_ESOF_Msk                       (0x1UL << USB_ISTR_ESOF_Pos)
#define USB_ISTR_ESOF                           USB_ISTR_ESOF_Msk
#define USB_ISTR_SOF_Pos                        (9U)
#define USB_ISTR_SOF_Msk                        (0x1UL << USB_ISTR_SOF_Pos)
#define USB_ISTR_SOF                            USB_ISTR_SOF_Msk
#define USB_ISTR_RESET_Pos                      (10U)
#define USB_ISTR_RESET_Msk                      (0x1UL << USB_ISTR_RESET_Pos)
#define USB_ISTR_RESET                          USB_ISTR_RESET_Msk
#define USB_ISTR_SUSP_Pos                       (11U)
#define USB_ISTR_SUSP_Msk                       (0x1UL << USB_ISTR_SUSP_Pos)
#define USB_ISTR_SUSP                           USB_ISTR_SUSP_Msk
#define USB_ISTR_WKUP_Pos                       (12U)
#define USB_ISTR_WKUP_Msk                       (0x1UL << USB_ISTR_WKUP_Pos)
#define USB_ISTR_WKUP                           USB_ISTR_WKUP_Msk
#define USB_ISTR_ERR_Pos                        (13U)
#define USB_ISTR_ERR_Msk                        (0x1UL << USB_ISTR_ERR_Pos)
#define USB_ISTR_ERR                            USB_ISTR_ERR_Msk
#define USB_ISTR_PMAOVR_Pos                     (14U)
#define USB_ISTR_PMAOVR_Msk                     (0x1UL << USB_ISTR_PMAOVR_Pos)
#define USB_ISTR_PMAOVR                         USB_ISTR_PMAOVR_Msk
#define USB_ISTR_CTR_Pos                        (15U)
#define USB_ISTR_CTR_Msk                        (0x1UL << USB_ISTR_CTR_Pos)
#define USB_ISTR_CTR                            USB_ISTR_CTR_Msk

#define USB_FNR_FN_Pos                          (0U)
#define USB_FNR_FN_Msk                          (0x7FFUL << USB_FNR_FN_Pos)
#define USB_FNR_FN                              USB_FNR_FN_Msk
#define USB_FNR_LSOF_Pos                        (11U)
#define USB_FNR_LSOF_Msk                        (0x3UL << USB_FNR_LSOF_Pos)
#define USB_FNR_LSOF                            USB_FNR_LSOF_Msk
#define USB_FNR_LCK_Pos                         (13U)
#define USB_FNR_LCK_Msk                         (0x1UL << USB_FNR_LCK_Pos)
#define USB_FNR_LCK                             USB_FNR_LCK_Msk
#define USB_FNR_RXDM_Pos                        (14U)
#define USB_FNR_RXDM_Msk                        (0x1UL << USB_FNR_RXDM_Pos)
#define USB_FNR_RXDM                            USB_FNR_RXDM_Msk
#define USB_FNR_RXDP_Pos                        (15U)
#define USB_FNR_RXDP_Msk                        (0x1UL << USB_FNR_RXDP_Pos)
#define USB_FNR_RXDP                            USB_FNR_RXDP_Msk

#define USB_DADDR_ADD_Pos                       (0U)
#define USB_DADDR_ADD_Msk                       (0x7FUL << USB_DADDR_ADD_Pos)
#define USB_DADDR_ADD                           USB_DADDR_ADD_Msk
#define USB_DADDR_ADD0_Pos                      (0U)
#define USB_DADDR_ADD0_Msk                      (0x1UL << USB_DADDR_ADD0_Pos)
#define USB_DADDR_ADD0                          USB_DADDR_ADD0_Msk
#define USB_DADDR_ADD1_Pos                      (1U)
#define USB_DADDR_ADD1_Msk                      (0x1UL << USB_DADDR_ADD1_Pos)
#define USB_DADDR_ADD1                          USB_DADDR_ADD1_Msk
#define USB_DADDR_ADD2_Pos                      (2U)
#define USB_DADDR_ADD2_Msk                      (0x1UL << USB_DADDR_ADD2_Pos)
#define USB_DADDR_ADD2                          USB_DADDR_ADD2_Msk
#define USB_DADDR_ADD3_Pos                      (3U)
#define USB_DADDR_ADD3_Msk                      (0x1UL << USB_DADDR_ADD3_Pos)
#define USB_DADDR_ADD3                          USB_DADDR_ADD3_Msk
#define USB_DADDR_ADD4_Pos                      (4U)
#define USB_DADDR_ADD4_Msk                      (0x1UL << USB_DADDR_ADD4_Pos)
#define USB_DADDR_ADD4                          USB_DADDR_ADD4_Msk
#define USB_DADDR_ADD5_Pos                      (5U)
#define USB_DADDR_ADD5_Msk                      (0x1UL << USB_DADDR_ADD5_Pos)
#define USB_DADDR_ADD5                          USB_DADDR_ADD5_Msk
#define USB_DADDR_ADD6_Pos                      (6U)
#define USB_DADDR_ADD6_Msk                      (0x1UL << USB_DADDR_ADD6_Pos)
#define USB_DADDR_ADD6                          USB_DADDR_ADD6_Msk

#define USB_DADDR_EF_Pos                        (7U)
#define USB_DADDR_EF_Msk                        (0x1UL << USB_DADDR_EF_Pos)
#define USB_DADDR_EF                            USB_DADDR_EF_Msk

#define USB_BTABLE_BTABLE_Pos                   (3U)
#define USB_BTABLE_BTABLE_Msk                   (0x1FFFUL << USB_BTABLE_BTABLE_Pos)
#define USB_BTABLE_BTABLE                       USB_BTABLE_BTABLE_Msk

#define USB_ADDR0_TX_ADDR0_TX_Pos               (1U)
#define USB_ADDR0_TX_ADDR0_TX_Msk               (0x7FFFUL << USB_ADDR0_TX_ADDR0_TX_Pos)
#define USB_ADDR0_TX_ADDR0_TX                   USB_ADDR0_TX_ADDR0_TX_Msk

#define USB_ADDR1_TX_ADDR1_TX_Pos               (1U)
#define USB_ADDR1_TX_ADDR1_TX_Msk               (0x7FFFUL << USB_ADDR1_TX_ADDR1_TX_Pos)
#define USB_ADDR1_TX_ADDR1_TX                   USB_ADDR1_TX_ADDR1_TX_Msk

#define USB_ADDR2_TX_ADDR2_TX_Pos               (1U)
#define USB_ADDR2_TX_ADDR2_TX_Msk               (0x7FFFUL << USB_ADDR2_TX_ADDR2_TX_Pos)
#define USB_ADDR2_TX_ADDR2_TX                   USB_ADDR2_TX_ADDR2_TX_Msk

#define USB_ADDR3_TX_ADDR3_TX_Pos               (1U)
#define USB_ADDR3_TX_ADDR3_TX_Msk               (0x7FFFUL << USB_ADDR3_TX_ADDR3_TX_Pos)
#define USB_ADDR3_TX_ADDR3_TX                   USB_ADDR3_TX_ADDR3_TX_Msk

#define USB_ADDR4_TX_ADDR4_TX_Pos               (1U)
#define USB_ADDR4_TX_ADDR4_TX_Msk               (0x7FFFUL << USB_ADDR4_TX_ADDR4_TX_Pos)
#define USB_ADDR4_TX_ADDR4_TX                   USB_ADDR4_TX_ADDR4_TX_Msk

#define USB_ADDR5_TX_ADDR5_TX_Pos               (1U)
#define USB_ADDR5_TX_ADDR5_TX_Msk               (0x7FFFUL << USB_ADDR5_TX_ADDR5_TX_Pos)
#define USB_ADDR5_TX_ADDR5_TX                   USB_ADDR5_TX_ADDR5_TX_Msk

#define USB_ADDR6_TX_ADDR6_TX_Pos               (1U)
#define USB_ADDR6_TX_ADDR6_TX_Msk               (0x7FFFUL << USB_ADDR6_TX_ADDR6_TX_Pos)
#define USB_ADDR6_TX_ADDR6_TX                   USB_ADDR6_TX_ADDR6_TX_Msk

#define USB_ADDR7_TX_ADDR7_TX_Pos               (1U)
#define USB_ADDR7_TX_ADDR7_TX_Msk               (0x7FFFUL << USB_ADDR7_TX_ADDR7_TX_Pos)
#define USB_ADDR7_TX_ADDR7_TX                   USB_ADDR7_TX_ADDR7_TX_Msk

#define USB_COUNT0_TX_COUNT0_TX_Pos             (0U)
#define USB_COUNT0_TX_COUNT0_TX_Msk             (0x3FFUL << USB_COUNT0_TX_COUNT0_TX_Pos)
#define USB_COUNT0_TX_COUNT0_TX                 USB_COUNT0_TX_COUNT0_TX_Msk

#define USB_COUNT1_TX_COUNT1_TX_Pos             (0U)
#define USB_COUNT1_TX_COUNT1_TX_Msk             (0x3FFUL << USB_COUNT1_TX_COUNT1_TX_Pos)
#define USB_COUNT1_TX_COUNT1_TX                 USB_COUNT1_TX_COUNT1_TX_Msk

#define USB_COUNT2_TX_COUNT2_TX_Pos             (0U)
#define USB_COUNT2_TX_COUNT2_TX_Msk             (0x3FFUL << USB_COUNT2_TX_COUNT2_TX_Pos)
#define USB_COUNT2_TX_COUNT2_TX                 USB_COUNT2_TX_COUNT2_TX_Msk

#define USB_COUNT3_TX_COUNT3_TX_Pos             (0U)
#define USB_COUNT3_TX_COUNT3_TX_Msk             (0x3FFUL << USB_COUNT3_TX_COUNT3_TX_Pos)
#define USB_COUNT3_TX_COUNT3_TX                 USB_COUNT3_TX_COUNT3_TX_Msk

#define USB_COUNT4_TX_COUNT4_TX_Pos             (0U)
#define USB_COUNT4_TX_COUNT4_TX_Msk             (0x3FFUL << USB_COUNT4_TX_COUNT4_TX_Pos)
#define USB_COUNT4_TX_COUNT4_TX                 USB_COUNT4_TX_COUNT4_TX_Msk

#define USB_COUNT5_TX_COUNT5_TX_Pos             (0U)
#define USB_COUNT5_TX_COUNT5_TX_Msk             (0x3FFUL << USB_COUNT5_TX_COUNT5_TX_Pos)
#define USB_COUNT5_TX_COUNT5_TX                 USB_COUNT5_TX_COUNT5_TX_Msk

#define USB_COUNT6_TX_COUNT6_TX_Pos             (0U)
#define USB_COUNT6_TX_COUNT6_TX_Msk             (0x3FFUL << USB_COUNT6_TX_COUNT6_TX_Pos)
#define USB_COUNT6_TX_COUNT6_TX                 USB_COUNT6_TX_COUNT6_TX_Msk

#define USB_COUNT7_TX_COUNT7_TX_Pos             (0U)
#define USB_COUNT7_TX_COUNT7_TX_Msk             (0x3FFUL << USB_COUNT7_TX_COUNT7_TX_Pos)
#define USB_COUNT7_TX_COUNT7_TX                 USB_COUNT7_TX_COUNT7_TX_Msk

#define USB_COUNT0_TX_0_COUNT0_TX_0             0x000003FFU

#define USB_COUNT0_TX_1_COUNT0_TX_1             0x03FF0000U

#define USB_COUNT1_TX_0_COUNT1_TX_0             0x000003FFU

#define USB_COUNT1_TX_1_COUNT1_TX_1             0x03FF0000U

#define USB_COUNT2_TX_0_COUNT2_TX_0             0x000003FFU

#define USB_COUNT2_TX_1_COUNT2_TX_1             0x03FF0000U

#define USB_COUNT3_TX_0_COUNT3_TX_0             0x000003FFU

#define USB_COUNT3_TX_1_COUNT3_TX_1             0x03FF0000U

#define USB_COUNT4_TX_0_COUNT4_TX_0             0x000003FFU

#define USB_COUNT4_TX_1_COUNT4_TX_1             0x03FF0000U

#define USB_COUNT5_TX_0_COUNT5_TX_0             0x000003FFU

#define USB_COUNT5_TX_1_COUNT5_TX_1             0x03FF0000U

#define USB_COUNT6_TX_0_COUNT6_TX_0             0x000003FFU

#define USB_COUNT6_TX_1_COUNT6_TX_1             0x03FF0000U

#define USB_COUNT7_TX_0_COUNT7_TX_0             0x000003FFU

#define USB_COUNT7_TX_1_COUNT7_TX_1             0x03FF0000U

#define USB_ADDR0_RX_ADDR0_RX_Pos               (1U)
#define USB_ADDR0_RX_ADDR0_RX_Msk               (0x7FFFUL << USB_ADDR0_RX_ADDR0_RX_Pos)
#define USB_ADDR0_RX_ADDR0_RX                   USB_ADDR0_RX_ADDR0_RX_Msk

#define USB_ADDR1_RX_ADDR1_RX_Pos               (1U)
#define USB_ADDR1_RX_ADDR1_RX_Msk               (0x7FFFUL << USB_ADDR1_RX_ADDR1_RX_Pos)
#define USB_ADDR1_RX_ADDR1_RX                   USB_ADDR1_RX_ADDR1_RX_Msk

#define USB_ADDR2_RX_ADDR2_RX_Pos               (1U)
#define USB_ADDR2_RX_ADDR2_RX_Msk               (0x7FFFUL << USB_ADDR2_RX_ADDR2_RX_Pos)
#define USB_ADDR2_RX_ADDR2_RX                   USB_ADDR2_RX_ADDR2_RX_Msk

#define USB_ADDR3_RX_ADDR3_RX_Pos               (1U)
#define USB_ADDR3_RX_ADDR3_RX_Msk               (0x7FFFUL << USB_ADDR3_RX_ADDR3_RX_Pos)
#define USB_ADDR3_RX_ADDR3_RX                   USB_ADDR3_RX_ADDR3_RX_Msk

#define USB_ADDR4_RX_ADDR4_RX_Pos               (1U)
#define USB_ADDR4_RX_ADDR4_RX_Msk               (0x7FFFUL << USB_ADDR4_RX_ADDR4_RX_Pos)
#define USB_ADDR4_RX_ADDR4_RX                   USB_ADDR4_RX_ADDR4_RX_Msk

#define USB_ADDR5_RX_ADDR5_RX_Pos               (1U)
#define USB_ADDR5_RX_ADDR5_RX_Msk               (0x7FFFUL << USB_ADDR5_RX_ADDR5_RX_Pos)
#define USB_ADDR5_RX_ADDR5_RX                   USB_ADDR5_RX_ADDR5_RX_Msk

#define USB_ADDR6_RX_ADDR6_RX_Pos               (1U)
#define USB_ADDR6_RX_ADDR6_RX_Msk               (0x7FFFUL << USB_ADDR6_RX_ADDR6_RX_Pos)
#define USB_ADDR6_RX_ADDR6_RX                   USB_ADDR6_RX_ADDR6_RX_Msk

#define USB_ADDR7_RX_ADDR7_RX_Pos               (1U)
#define USB_ADDR7_RX_ADDR7_RX_Msk               (0x7FFFUL << USB_ADDR7_RX_ADDR7_RX_Pos)
#define USB_ADDR7_RX_ADDR7_RX                   USB_ADDR7_RX_ADDR7_RX_Msk

#define USB_COUNT0_RX_COUNT0_RX_Pos             (0U)
#define USB_COUNT0_RX_COUNT0_RX_Msk             (0x3FFUL << USB_COUNT0_RX_COUNT0_RX_Pos)
#define USB_COUNT0_RX_COUNT0_RX                 USB_COUNT0_RX_COUNT0_RX_Msk

#define USB_COUNT0_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT0_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT0_RX_NUM_BLOCK_Pos)
#define USB_COUNT0_RX_NUM_BLOCK                 USB_COUNT0_RX_NUM_BLOCK_Msk
#define USB_COUNT0_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT0_RX_NUM_BLOCK_Pos)
#define USB_COUNT0_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT0_RX_NUM_BLOCK_Pos)
#define USB_COUNT0_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT0_RX_NUM_BLOCK_Pos)
#define USB_COUNT0_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT0_RX_NUM_BLOCK_Pos)
#define USB_COUNT0_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT0_RX_NUM_BLOCK_Pos)

#define USB_COUNT0_RX_BLSIZE_Pos                (15U)
#define USB_COUNT0_RX_BLSIZE_Msk                (0x1UL << USB_COUNT0_RX_BLSIZE_Pos)
#define USB_COUNT0_RX_BLSIZE                    USB_COUNT0_RX_BLSIZE_Msk

#define USB_COUNT1_RX_COUNT1_RX_Pos             (0U)
#define USB_COUNT1_RX_COUNT1_RX_Msk             (0x3FFUL << USB_COUNT1_RX_COUNT1_RX_Pos)
#define USB_COUNT1_RX_COUNT1_RX                 USB_COUNT1_RX_COUNT1_RX_Msk

#define USB_COUNT1_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT1_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT1_RX_NUM_BLOCK_Pos)
#define USB_COUNT1_RX_NUM_BLOCK                 USB_COUNT1_RX_NUM_BLOCK_Msk
#define USB_COUNT1_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT1_RX_NUM_BLOCK_Pos)
#define USB_COUNT1_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT1_RX_NUM_BLOCK_Pos)
#define USB_COUNT1_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT1_RX_NUM_BLOCK_Pos)
#define USB_COUNT1_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT1_RX_NUM_BLOCK_Pos)
#define USB_COUNT1_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT1_RX_NUM_BLOCK_Pos)

#define USB_COUNT1_RX_BLSIZE_Pos                (15U)
#define USB_COUNT1_RX_BLSIZE_Msk                (0x1UL << USB_COUNT1_RX_BLSIZE_Pos)
#define USB_COUNT1_RX_BLSIZE                    USB_COUNT1_RX_BLSIZE_Msk

#define USB_COUNT2_RX_COUNT2_RX_Pos             (0U)
#define USB_COUNT2_RX_COUNT2_RX_Msk             (0x3FFUL << USB_COUNT2_RX_COUNT2_RX_Pos)
#define USB_COUNT2_RX_COUNT2_RX                 USB_COUNT2_RX_COUNT2_RX_Msk

#define USB_COUNT2_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT2_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT2_RX_NUM_BLOCK_Pos)
#define USB_COUNT2_RX_NUM_BLOCK                 USB_COUNT2_RX_NUM_BLOCK_Msk
#define USB_COUNT2_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT2_RX_NUM_BLOCK_Pos)
#define USB_COUNT2_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT2_RX_NUM_BLOCK_Pos)
#define USB_COUNT2_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT2_RX_NUM_BLOCK_Pos)
#define USB_COUNT2_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT2_RX_NUM_BLOCK_Pos)
#define USB_COUNT2_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT2_RX_NUM_BLOCK_Pos)

#define USB_COUNT2_RX_BLSIZE_Pos                (15U)
#define USB_COUNT2_RX_BLSIZE_Msk                (0x1UL << USB_COUNT2_RX_BLSIZE_Pos)
#define USB_COUNT2_RX_BLSIZE                    USB_COUNT2_RX_BLSIZE_Msk

#define USB_COUNT3_RX_COUNT3_RX_Pos             (0U)
#define USB_COUNT3_RX_COUNT3_RX_Msk             (0x3FFUL << USB_COUNT3_RX_COUNT3_RX_Pos)
#define USB_COUNT3_RX_COUNT3_RX                 USB_COUNT3_RX_COUNT3_RX_Msk

#define USB_COUNT3_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT3_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT3_RX_NUM_BLOCK_Pos)
#define USB_COUNT3_RX_NUM_BLOCK                 USB_COUNT3_RX_NUM_BLOCK_Msk
#define USB_COUNT3_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT3_RX_NUM_BLOCK_Pos)
#define USB_COUNT3_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT3_RX_NUM_BLOCK_Pos)
#define USB_COUNT3_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT3_RX_NUM_BLOCK_Pos)
#define USB_COUNT3_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT3_RX_NUM_BLOCK_Pos)
#define USB_COUNT3_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT3_RX_NUM_BLOCK_Pos)

#define USB_COUNT3_RX_BLSIZE_Pos                (15U)
#define USB_COUNT3_RX_BLSIZE_Msk                (0x1UL << USB_COUNT3_RX_BLSIZE_Pos)
#define USB_COUNT3_RX_BLSIZE                    USB_COUNT3_RX_BLSIZE_Msk

#define USB_COUNT4_RX_COUNT4_RX_Pos             (0U)
#define USB_COUNT4_RX_COUNT4_RX_Msk             (0x3FFUL << USB_COUNT4_RX_COUNT4_RX_Pos)
#define USB_COUNT4_RX_COUNT4_RX                 USB_COUNT4_RX_COUNT4_RX_Msk

#define USB_COUNT4_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT4_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT4_RX_NUM_BLOCK_Pos)
#define USB_COUNT4_RX_NUM_BLOCK                 USB_COUNT4_RX_NUM_BLOCK_Msk
#define USB_COUNT4_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT4_RX_NUM_BLOCK_Pos)
#define USB_COUNT4_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT4_RX_NUM_BLOCK_Pos)
#define USB_COUNT4_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT4_RX_NUM_BLOCK_Pos)
#define USB_COUNT4_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT4_RX_NUM_BLOCK_Pos)
#define USB_COUNT4_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT4_RX_NUM_BLOCK_Pos)

#define USB_COUNT4_RX_BLSIZE_Pos                (15U)
#define USB_COUNT4_RX_BLSIZE_Msk                (0x1UL << USB_COUNT4_RX_BLSIZE_Pos)
#define USB_COUNT4_RX_BLSIZE                    USB_COUNT4_RX_BLSIZE_Msk

#define USB_COUNT5_RX_COUNT5_RX_Pos             (0U)
#define USB_COUNT5_RX_COUNT5_RX_Msk             (0x3FFUL << USB_COUNT5_RX_COUNT5_RX_Pos)
#define USB_COUNT5_RX_COUNT5_RX                 USB_COUNT5_RX_COUNT5_RX_Msk

#define USB_COUNT5_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT5_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT5_RX_NUM_BLOCK_Pos)
#define USB_COUNT5_RX_NUM_BLOCK                 USB_COUNT5_RX_NUM_BLOCK_Msk
#define USB_COUNT5_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT5_RX_NUM_BLOCK_Pos)
#define USB_COUNT5_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT5_RX_NUM_BLOCK_Pos)
#define USB_COUNT5_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT5_RX_NUM_BLOCK_Pos)
#define USB_COUNT5_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT5_RX_NUM_BLOCK_Pos)
#define USB_COUNT5_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT5_RX_NUM_BLOCK_Pos)

#define USB_COUNT5_RX_BLSIZE_Pos                (15U)
#define USB_COUNT5_RX_BLSIZE_Msk                (0x1UL << USB_COUNT5_RX_BLSIZE_Pos)
#define USB_COUNT5_RX_BLSIZE                    USB_COUNT5_RX_BLSIZE_Msk

#define USB_COUNT6_RX_COUNT6_RX_Pos             (0U)
#define USB_COUNT6_RX_COUNT6_RX_Msk             (0x3FFUL << USB_COUNT6_RX_COUNT6_RX_Pos)
#define USB_COUNT6_RX_COUNT6_RX                 USB_COUNT6_RX_COUNT6_RX_Msk

#define USB_COUNT6_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT6_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT6_RX_NUM_BLOCK_Pos)
#define USB_COUNT6_RX_NUM_BLOCK                 USB_COUNT6_RX_NUM_BLOCK_Msk
#define USB_COUNT6_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT6_RX_NUM_BLOCK_Pos)
#define USB_COUNT6_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT6_RX_NUM_BLOCK_Pos)
#define USB_COUNT6_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT6_RX_NUM_BLOCK_Pos)
#define USB_COUNT6_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT6_RX_NUM_BLOCK_Pos)
#define USB_COUNT6_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT6_RX_NUM_BLOCK_Pos)

#define USB_COUNT6_RX_BLSIZE_Pos                (15U)
#define USB_COUNT6_RX_BLSIZE_Msk                (0x1UL << USB_COUNT6_RX_BLSIZE_Pos)
#define USB_COUNT6_RX_BLSIZE                    USB_COUNT6_RX_BLSIZE_Msk

#define USB_COUNT7_RX_COUNT7_RX_Pos             (0U)
#define USB_COUNT7_RX_COUNT7_RX_Msk             (0x3FFUL << USB_COUNT7_RX_COUNT7_RX_Pos)
#define USB_COUNT7_RX_COUNT7_RX                 USB_COUNT7_RX_COUNT7_RX_Msk

#define USB_COUNT7_RX_NUM_BLOCK_Pos             (10U)
#define USB_COUNT7_RX_NUM_BLOCK_Msk             (0x1FUL << USB_COUNT7_RX_NUM_BLOCK_Pos)
#define USB_COUNT7_RX_NUM_BLOCK                 USB_COUNT7_RX_NUM_BLOCK_Msk
#define USB_COUNT7_RX_NUM_BLOCK_0               (0x01UL << USB_COUNT7_RX_NUM_BLOCK_Pos)
#define USB_COUNT7_RX_NUM_BLOCK_1               (0x02UL << USB_COUNT7_RX_NUM_BLOCK_Pos)
#define USB_COUNT7_RX_NUM_BLOCK_2               (0x04UL << USB_COUNT7_RX_NUM_BLOCK_Pos)
#define USB_COUNT7_RX_NUM_BLOCK_3               (0x08UL << USB_COUNT7_RX_NUM_BLOCK_Pos)
#define USB_COUNT7_RX_NUM_BLOCK_4               (0x10UL << USB_COUNT7_RX_NUM_BLOCK_Pos)

#define USB_COUNT7_RX_BLSIZE_Pos                (15U)
#define USB_COUNT7_RX_BLSIZE_Msk                (0x1UL << USB_COUNT7_RX_BLSIZE_Pos)
#define USB_COUNT7_RX_BLSIZE                    USB_COUNT7_RX_BLSIZE_Msk

#define USB_COUNT0_RX_0_COUNT0_RX_0             0x000003FFU

#define USB_COUNT0_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT0_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT0_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT0_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT0_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT0_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT0_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT0_RX_1_COUNT0_RX_1             0x03FF0000U

#define USB_COUNT0_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT0_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT0_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT0_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT0_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT0_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT0_RX_1_BLSIZE_1                0x80000000U

#define USB_COUNT1_RX_0_COUNT1_RX_0             0x000003FFU

#define USB_COUNT1_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT1_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT1_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT1_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT1_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT1_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT1_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT1_RX_1_COUNT1_RX_1             0x03FF0000U

#define USB_COUNT1_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT1_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT1_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT1_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT1_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT1_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT1_RX_1_BLSIZE_1                0x80000000U

#define USB_COUNT2_RX_0_COUNT2_RX_0             0x000003FFU

#define USB_COUNT2_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT2_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT2_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT2_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT2_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT2_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT2_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT2_RX_1_COUNT2_RX_1             0x03FF0000U

#define USB_COUNT2_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT2_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT2_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT2_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT2_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT2_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT2_RX_1_BLSIZE_1                0x80000000U

#define USB_COUNT3_RX_0_COUNT3_RX_0             0x000003FFU

#define USB_COUNT3_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT3_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT3_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT3_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT3_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT3_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT3_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT3_RX_1_COUNT3_RX_1             0x03FF0000U

#define USB_COUNT3_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT3_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT3_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT3_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT3_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT3_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT3_RX_1_BLSIZE_1                0x80000000U

#define USB_COUNT4_RX_0_COUNT4_RX_0             0x000003FFU

#define USB_COUNT4_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT4_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT4_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT4_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT4_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT4_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT4_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT4_RX_1_COUNT4_RX_1             0x03FF0000U

#define USB_COUNT4_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT4_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT4_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT4_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT4_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT4_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT4_RX_1_BLSIZE_1                0x80000000U

#define USB_COUNT5_RX_0_COUNT5_RX_0             0x000003FFU

#define USB_COUNT5_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT5_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT5_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT5_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT5_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT5_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT5_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT5_RX_1_COUNT5_RX_1             0x03FF0000U

#define USB_COUNT5_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT5_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT5_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT5_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT5_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT5_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT5_RX_1_BLSIZE_1                0x80000000U

#define USB_COUNT6_RX_0_COUNT6_RX_0             0x000003FFU

#define USB_COUNT6_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT6_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT6_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT6_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT6_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT6_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT6_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT6_RX_1_COUNT6_RX_1             0x03FF0000U

#define USB_COUNT6_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT6_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT6_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT6_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT6_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT6_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT6_RX_1_BLSIZE_1                0x80000000U

#define USB_COUNT7_RX_0_COUNT7_RX_0             0x000003FFU

#define USB_COUNT7_RX_0_NUM_BLOCK_0             0x00007C00U
#define USB_COUNT7_RX_0_NUM_BLOCK_0_0           0x00000400U
#define USB_COUNT7_RX_0_NUM_BLOCK_0_1           0x00000800U
#define USB_COUNT7_RX_0_NUM_BLOCK_0_2           0x00001000U
#define USB_COUNT7_RX_0_NUM_BLOCK_0_3           0x00002000U
#define USB_COUNT7_RX_0_NUM_BLOCK_0_4           0x00004000U

#define USB_COUNT7_RX_0_BLSIZE_0                0x00008000U

#define USB_COUNT7_RX_1_COUNT7_RX_1             0x03FF0000U

#define USB_COUNT7_RX_1_NUM_BLOCK_1             0x7C000000U
#define USB_COUNT7_RX_1_NUM_BLOCK_1_0           0x04000000U
#define USB_COUNT7_RX_1_NUM_BLOCK_1_1           0x08000000U
#define USB_COUNT7_RX_1_NUM_BLOCK_1_2           0x10000000U
#define USB_COUNT7_RX_1_NUM_BLOCK_1_3           0x20000000U
#define USB_COUNT7_RX_1_NUM_BLOCK_1_4           0x40000000U

#define USB_COUNT7_RX_1_BLSIZE_1                0x80000000U

#define CAN_MCR_INRQ_Pos                     (0U)
#define CAN_MCR_INRQ_Msk                     (0x1UL << CAN_MCR_INRQ_Pos)
#define CAN_MCR_INRQ                         CAN_MCR_INRQ_Msk
#define CAN_MCR_SLEEP_Pos                    (1U)
#define CAN_MCR_SLEEP_Msk                    (0x1UL << CAN_MCR_SLEEP_Pos)
#define CAN_MCR_SLEEP                        CAN_MCR_SLEEP_Msk
#define CAN_MCR_TXFP_Pos                     (2U)
#define CAN_MCR_TXFP_Msk                     (0x1UL << CAN_MCR_TXFP_Pos)
#define CAN_MCR_TXFP                         CAN_MCR_TXFP_Msk
#define CAN_MCR_RFLM_Pos                     (3U)
#define CAN_MCR_RFLM_Msk                     (0x1UL << CAN_MCR_RFLM_Pos)
#define CAN_MCR_RFLM                         CAN_MCR_RFLM_Msk
#define CAN_MCR_NART_Pos                     (4U)
#define CAN_MCR_NART_Msk                     (0x1UL << CAN_MCR_NART_Pos)
#define CAN_MCR_NART                         CAN_MCR_NART_Msk
#define CAN_MCR_AWUM_Pos                     (5U)
#define CAN_MCR_AWUM_Msk                     (0x1UL << CAN_MCR_AWUM_Pos)
#define CAN_MCR_AWUM                         CAN_MCR_AWUM_Msk
#define CAN_MCR_ABOM_Pos                     (6U)
#define CAN_MCR_ABOM_Msk                     (0x1UL << CAN_MCR_ABOM_Pos)
#define CAN_MCR_ABOM                         CAN_MCR_ABOM_Msk
#define CAN_MCR_TTCM_Pos                     (7U)
#define CAN_MCR_TTCM_Msk                     (0x1UL << CAN_MCR_TTCM_Pos)
#define CAN_MCR_TTCM                         CAN_MCR_TTCM_Msk
#define CAN_MCR_RESET_Pos                    (15U)
#define CAN_MCR_RESET_Msk                    (0x1UL << CAN_MCR_RESET_Pos)
#define CAN_MCR_RESET                        CAN_MCR_RESET_Msk
#define CAN_MCR_DBF_Pos                      (16U)
#define CAN_MCR_DBF_Msk                      (0x1UL << CAN_MCR_DBF_Pos)
#define CAN_MCR_DBF                          CAN_MCR_DBF_Msk

#define CAN_MSR_INAK_Pos                     (0U)
#define CAN_MSR_INAK_Msk                     (0x1UL << CAN_MSR_INAK_Pos)
#define CAN_MSR_INAK                         CAN_MSR_INAK_Msk
#define CAN_MSR_SLAK_Pos                     (1U)
#define CAN_MSR_SLAK_Msk                     (0x1UL << CAN_MSR_SLAK_Pos)
#define CAN_MSR_SLAK                         CAN_MSR_SLAK_Msk
#define CAN_MSR_ERRI_Pos                     (2U)
#define CAN_MSR_ERRI_Msk                     (0x1UL << CAN_MSR_ERRI_Pos)
#define CAN_MSR_ERRI                         CAN_MSR_ERRI_Msk
#define CAN_MSR_WKUI_Pos                     (3U)
#define CAN_MSR_WKUI_Msk                     (0x1UL << CAN_MSR_WKUI_Pos)
#define CAN_MSR_WKUI                         CAN_MSR_WKUI_Msk
#define CAN_MSR_SLAKI_Pos                    (4U)
#define CAN_MSR_SLAKI_Msk                    (0x1UL << CAN_MSR_SLAKI_Pos)
#define CAN_MSR_SLAKI                        CAN_MSR_SLAKI_Msk
#define CAN_MSR_TXM_Pos                      (8U)
#define CAN_MSR_TXM_Msk                      (0x1UL << CAN_MSR_TXM_Pos)
#define CAN_MSR_TXM                          CAN_MSR_TXM_Msk
#define CAN_MSR_RXM_Pos                      (9U)
#define CAN_MSR_RXM_Msk                      (0x1UL << CAN_MSR_RXM_Pos)
#define CAN_MSR_RXM                          CAN_MSR_RXM_Msk
#define CAN_MSR_SAMP_Pos                     (10U)
#define CAN_MSR_SAMP_Msk                     (0x1UL << CAN_MSR_SAMP_Pos)
#define CAN_MSR_SAMP                         CAN_MSR_SAMP_Msk
#define CAN_MSR_RX_Pos                       (11U)
#define CAN_MSR_RX_Msk                       (0x1UL << CAN_MSR_RX_Pos)
#define CAN_MSR_RX                           CAN_MSR_RX_Msk

#define CAN_TSR_RQCP0_Pos                    (0U)
#define CAN_TSR_RQCP0_Msk                    (0x1UL << CAN_TSR_RQCP0_Pos)
#define CAN_TSR_RQCP0                        CAN_TSR_RQCP0_Msk
#define CAN_TSR_TXOK0_Pos                    (1U)
#define CAN_TSR_TXOK0_Msk                    (0x1UL << CAN_TSR_TXOK0_Pos)
#define CAN_TSR_TXOK0                        CAN_TSR_TXOK0_Msk
#define CAN_TSR_ALST0_Pos                    (2U)
#define CAN_TSR_ALST0_Msk                    (0x1UL << CAN_TSR_ALST0_Pos)
#define CAN_TSR_ALST0                        CAN_TSR_ALST0_Msk
#define CAN_TSR_TERR0_Pos                    (3U)
#define CAN_TSR_TERR0_Msk                    (0x1UL << CAN_TSR_TERR0_Pos)
#define CAN_TSR_TERR0                        CAN_TSR_TERR0_Msk
#define CAN_TSR_ABRQ0_Pos                    (7U)
#define CAN_TSR_ABRQ0_Msk                    (0x1UL << CAN_TSR_ABRQ0_Pos)
#define CAN_TSR_ABRQ0                        CAN_TSR_ABRQ0_Msk
#define CAN_TSR_RQCP1_Pos                    (8U)
#define CAN_TSR_RQCP1_Msk                    (0x1UL << CAN_TSR_RQCP1_Pos)
#define CAN_TSR_RQCP1                        CAN_TSR_RQCP1_Msk
#define CAN_TSR_TXOK1_Pos                    (9U)
#define CAN_TSR_TXOK1_Msk                    (0x1UL << CAN_TSR_TXOK1_Pos)
#define CAN_TSR_TXOK1                        CAN_TSR_TXOK1_Msk
#define CAN_TSR_ALST1_Pos                    (10U)
#define CAN_TSR_ALST1_Msk                    (0x1UL << CAN_TSR_ALST1_Pos)
#define CAN_TSR_ALST1                        CAN_TSR_ALST1_Msk
#define CAN_TSR_TERR1_Pos                    (11U)
#define CAN_TSR_TERR1_Msk                    (0x1UL << CAN_TSR_TERR1_Pos)
#define CAN_TSR_TERR1                        CAN_TSR_TERR1_Msk
#define CAN_TSR_ABRQ1_Pos                    (15U)
#define CAN_TSR_ABRQ1_Msk                    (0x1UL << CAN_TSR_ABRQ1_Pos)
#define CAN_TSR_ABRQ1                        CAN_TSR_ABRQ1_Msk
#define CAN_TSR_RQCP2_Pos                    (16U)
#define CAN_TSR_RQCP2_Msk                    (0x1UL << CAN_TSR_RQCP2_Pos)
#define CAN_TSR_RQCP2                        CAN_TSR_RQCP2_Msk
#define CAN_TSR_TXOK2_Pos                    (17U)
#define CAN_TSR_TXOK2_Msk                    (0x1UL << CAN_TSR_TXOK2_Pos)
#define CAN_TSR_TXOK2                        CAN_TSR_TXOK2_Msk
#define CAN_TSR_ALST2_Pos                    (18U)
#define CAN_TSR_ALST2_Msk                    (0x1UL << CAN_TSR_ALST2_Pos)
#define CAN_TSR_ALST2                        CAN_TSR_ALST2_Msk
#define CAN_TSR_TERR2_Pos                    (19U)
#define CAN_TSR_TERR2_Msk                    (0x1UL << CAN_TSR_TERR2_Pos)
#define CAN_TSR_TERR2                        CAN_TSR_TERR2_Msk
#define CAN_TSR_ABRQ2_Pos                    (23U)
#define CAN_TSR_ABRQ2_Msk                    (0x1UL << CAN_TSR_ABRQ2_Pos)
#define CAN_TSR_ABRQ2                        CAN_TSR_ABRQ2_Msk
#define CAN_TSR_CODE_Pos                     (24U)
#define CAN_TSR_CODE_Msk                     (0x3UL << CAN_TSR_CODE_Pos)
#define CAN_TSR_CODE                         CAN_TSR_CODE_Msk

#define CAN_TSR_TME_Pos                      (26U)
#define CAN_TSR_TME_Msk                      (0x7UL << CAN_TSR_TME_Pos)
#define CAN_TSR_TME                          CAN_TSR_TME_Msk
#define CAN_TSR_TME0_Pos                     (26U)
#define CAN_TSR_TME0_Msk                     (0x1UL << CAN_TSR_TME0_Pos)
#define CAN_TSR_TME0                         CAN_TSR_TME0_Msk
#define CAN_TSR_TME1_Pos                     (27U)
#define CAN_TSR_TME1_Msk                     (0x1UL << CAN_TSR_TME1_Pos)
#define CAN_TSR_TME1                         CAN_TSR_TME1_Msk
#define CAN_TSR_TME2_Pos                     (28U)
#define CAN_TSR_TME2_Msk                     (0x1UL << CAN_TSR_TME2_Pos)
#define CAN_TSR_TME2                         CAN_TSR_TME2_Msk

#define CAN_TSR_LOW_Pos                      (29U)
#define CAN_TSR_LOW_Msk                      (0x7UL << CAN_TSR_LOW_Pos)
#define CAN_TSR_LOW                          CAN_TSR_LOW_Msk
#define CAN_TSR_LOW0_Pos                     (29U)
#define CAN_TSR_LOW0_Msk                     (0x1UL << CAN_TSR_LOW0_Pos)
#define CAN_TSR_LOW0                         CAN_TSR_LOW0_Msk
#define CAN_TSR_LOW1_Pos                     (30U)
#define CAN_TSR_LOW1_Msk                     (0x1UL << CAN_TSR_LOW1_Pos)
#define CAN_TSR_LOW1                         CAN_TSR_LOW1_Msk
#define CAN_TSR_LOW2_Pos                     (31U)
#define CAN_TSR_LOW2_Msk                     (0x1UL << CAN_TSR_LOW2_Pos)
#define CAN_TSR_LOW2                         CAN_TSR_LOW2_Msk

#define CAN_RF0R_FMP0_Pos                    (0U)
#define CAN_RF0R_FMP0_Msk                    (0x3UL << CAN_RF0R_FMP0_Pos)
#define CAN_RF0R_FMP0                        CAN_RF0R_FMP0_Msk
#define CAN_RF0R_FULL0_Pos                   (3U)
#define CAN_RF0R_FULL0_Msk                   (0x1UL << CAN_RF0R_FULL0_Pos)
#define CAN_RF0R_FULL0                       CAN_RF0R_FULL0_Msk
#define CAN_RF0R_FOVR0_Pos                   (4U)
#define CAN_RF0R_FOVR0_Msk                   (0x1UL << CAN_RF0R_FOVR0_Pos)
#define CAN_RF0R_FOVR0                       CAN_RF0R_FOVR0_Msk
#define CAN_RF0R_RFOM0_Pos                   (5U)
#define CAN_RF0R_RFOM0_Msk                   (0x1UL << CAN_RF0R_RFOM0_Pos)
#define CAN_RF0R_RFOM0                       CAN_RF0R_RFOM0_Msk

#define CAN_RF1R_FMP1_Pos                    (0U)
#define CAN_RF1R_FMP1_Msk                    (0x3UL << CAN_RF1R_FMP1_Pos)
#define CAN_RF1R_FMP1                        CAN_RF1R_FMP1_Msk
#define CAN_RF1R_FULL1_Pos                   (3U)
#define CAN_RF1R_FULL1_Msk                   (0x1UL << CAN_RF1R_FULL1_Pos)
#define CAN_RF1R_FULL1                       CAN_RF1R_FULL1_Msk
#define CAN_RF1R_FOVR1_Pos                   (4U)
#define CAN_RF1R_FOVR1_Msk                   (0x1UL << CAN_RF1R_FOVR1_Pos)
#define CAN_RF1R_FOVR1                       CAN_RF1R_FOVR1_Msk
#define CAN_RF1R_RFOM1_Pos                   (5U)
#define CAN_RF1R_RFOM1_Msk                   (0x1UL << CAN_RF1R_RFOM1_Pos)
#define CAN_RF1R_RFOM1                       CAN_RF1R_RFOM1_Msk

#define CAN_IER_TMEIE_Pos                    (0U)
#define CAN_IER_TMEIE_Msk                    (0x1UL << CAN_IER_TMEIE_Pos)
#define CAN_IER_TMEIE                        CAN_IER_TMEIE_Msk
#define CAN_IER_FMPIE0_Pos                   (1U)
#define CAN_IER_FMPIE0_Msk                   (0x1UL << CAN_IER_FMPIE0_Pos)
#define CAN_IER_FMPIE0                       CAN_IER_FMPIE0_Msk
#define CAN_IER_FFIE0_Pos                    (2U)
#define CAN_IER_FFIE0_Msk                    (0x1UL << CAN_IER_FFIE0_Pos)
#define CAN_IER_FFIE0                        CAN_IER_FFIE0_Msk
#define CAN_IER_FOVIE0_Pos                   (3U)
#define CAN_IER_FOVIE0_Msk                   (0x1UL << CAN_IER_FOVIE0_Pos)
#define CAN_IER_FOVIE0                       CAN_IER_FOVIE0_Msk
#define CAN_IER_FMPIE1_Pos                   (4U)
#define CAN_IER_FMPIE1_Msk                   (0x1UL << CAN_IER_FMPIE1_Pos)
#define CAN_IER_FMPIE1                       CAN_IER_FMPIE1_Msk
#define CAN_IER_FFIE1_Pos                    (5U)
#define CAN_IER_FFIE1_Msk                    (0x1UL << CAN_IER_FFIE1_Pos)
#define CAN_IER_FFIE1                        CAN_IER_FFIE1_Msk
#define CAN_IER_FOVIE1_Pos                   (6U)
#define CAN_IER_FOVIE1_Msk                   (0x1UL << CAN_IER_FOVIE1_Pos)
#define CAN_IER_FOVIE1                       CAN_IER_FOVIE1_Msk
#define CAN_IER_EWGIE_Pos                    (8U)
#define CAN_IER_EWGIE_Msk                    (0x1UL << CAN_IER_EWGIE_Pos)
#define CAN_IER_EWGIE                        CAN_IER_EWGIE_Msk
#define CAN_IER_EPVIE_Pos                    (9U)
#define CAN_IER_EPVIE_Msk                    (0x1UL << CAN_IER_EPVIE_Pos)
#define CAN_IER_EPVIE                        CAN_IER_EPVIE_Msk
#define CAN_IER_BOFIE_Pos                    (10U)
#define CAN_IER_BOFIE_Msk                    (0x1UL << CAN_IER_BOFIE_Pos)
#define CAN_IER_BOFIE                        CAN_IER_BOFIE_Msk
#define CAN_IER_LECIE_Pos                    (11U)
#define CAN_IER_LECIE_Msk                    (0x1UL << CAN_IER_LECIE_Pos)
#define CAN_IER_LECIE                        CAN_IER_LECIE_Msk
#define CAN_IER_ERRIE_Pos                    (15U)
#define CAN_IER_ERRIE_Msk                    (0x1UL << CAN_IER_ERRIE_Pos)
#define CAN_IER_ERRIE                        CAN_IER_ERRIE_Msk
#define CAN_IER_WKUIE_Pos                    (16U)
#define CAN_IER_WKUIE_Msk                    (0x1UL << CAN_IER_WKUIE_Pos)
#define CAN_IER_WKUIE                        CAN_IER_WKUIE_Msk
#define CAN_IER_SLKIE_Pos                    (17U)
#define CAN_IER_SLKIE_Msk                    (0x1UL << CAN_IER_SLKIE_Pos)
#define CAN_IER_SLKIE                        CAN_IER_SLKIE_Msk

#define CAN_ESR_EWGF_Pos                     (0U)
#define CAN_ESR_EWGF_Msk                     (0x1UL << CAN_ESR_EWGF_Pos)
#define CAN_ESR_EWGF                         CAN_ESR_EWGF_Msk
#define CAN_ESR_EPVF_Pos                     (1U)
#define CAN_ESR_EPVF_Msk                     (0x1UL << CAN_ESR_EPVF_Pos)
#define CAN_ESR_EPVF                         CAN_ESR_EPVF_Msk
#define CAN_ESR_BOFF_Pos                     (2U)
#define CAN_ESR_BOFF_Msk                     (0x1UL << CAN_ESR_BOFF_Pos)
#define CAN_ESR_BOFF                         CAN_ESR_BOFF_Msk

#define CAN_ESR_LEC_Pos                      (4U)
#define CAN_ESR_LEC_Msk                      (0x7UL << CAN_ESR_LEC_Pos)
#define CAN_ESR_LEC                          CAN_ESR_LEC_Msk
#define CAN_ESR_LEC_0                        (0x1UL << CAN_ESR_LEC_Pos)
#define CAN_ESR_LEC_1                        (0x2UL << CAN_ESR_LEC_Pos)
#define CAN_ESR_LEC_2                        (0x4UL << CAN_ESR_LEC_Pos)

#define CAN_ESR_TEC_Pos                      (16U)
#define CAN_ESR_TEC_Msk                      (0xFFUL << CAN_ESR_TEC_Pos)
#define CAN_ESR_TEC                          CAN_ESR_TEC_Msk
#define CAN_ESR_REC_Pos                      (24U)
#define CAN_ESR_REC_Msk                      (0xFFUL << CAN_ESR_REC_Pos)
#define CAN_ESR_REC                          CAN_ESR_REC_Msk

#define CAN_BTR_BRP_Pos                      (0U)
#define CAN_BTR_BRP_Msk                      (0x3FFUL << CAN_BTR_BRP_Pos)
#define CAN_BTR_BRP                          CAN_BTR_BRP_Msk
#define CAN_BTR_TS1_Pos                      (16U)
#define CAN_BTR_TS1_Msk                      (0xFUL << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1                          CAN_BTR_TS1_Msk
#define CAN_BTR_TS1_0                        (0x1UL << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1_1                        (0x2UL << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1_2                        (0x4UL << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1_3                        (0x8UL << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS2_Pos                      (20U)
#define CAN_BTR_TS2_Msk                      (0x7UL << CAN_BTR_TS2_Pos)
#define CAN_BTR_TS2                          CAN_BTR_TS2_Msk
#define CAN_BTR_TS2_0                        (0x1UL << CAN_BTR_TS2_Pos)
#define CAN_BTR_TS2_1                        (0x2UL << CAN_BTR_TS2_Pos)
#define CAN_BTR_TS2_2                        (0x4UL << CAN_BTR_TS2_Pos)
#define CAN_BTR_SJW_Pos                      (24U)
#define CAN_BTR_SJW_Msk                      (0x3UL << CAN_BTR_SJW_Pos)
#define CAN_BTR_SJW                          CAN_BTR_SJW_Msk
#define CAN_BTR_SJW_0                        (0x1UL << CAN_BTR_SJW_Pos)
#define CAN_BTR_SJW_1                        (0x2UL << CAN_BTR_SJW_Pos)
#define CAN_BTR_LBKM_Pos                     (30U)
#define CAN_BTR_LBKM_Msk                     (0x1UL << CAN_BTR_LBKM_Pos)
#define CAN_BTR_LBKM                         CAN_BTR_LBKM_Msk
#define CAN_BTR_SILM_Pos                     (31U)
#define CAN_BTR_SILM_Msk                     (0x1UL << CAN_BTR_SILM_Pos)
#define CAN_BTR_SILM                         CAN_BTR_SILM_Msk

#define CAN_TI0R_TXRQ_Pos                    (0U)
#define CAN_TI0R_TXRQ_Msk                    (0x1UL << CAN_TI0R_TXRQ_Pos)
#define CAN_TI0R_TXRQ                        CAN_TI0R_TXRQ_Msk
#define CAN_TI0R_RTR_Pos                     (1U)
#define CAN_TI0R_RTR_Msk                     (0x1UL << CAN_TI0R_RTR_Pos)
#define CAN_TI0R_RTR                         CAN_TI0R_RTR_Msk
#define CAN_TI0R_IDE_Pos                     (2U)
#define CAN_TI0R_IDE_Msk                     (0x1UL << CAN_TI0R_IDE_Pos)
#define CAN_TI0R_IDE                         CAN_TI0R_IDE_Msk
#define CAN_TI0R_EXID_Pos                    (3U)
#define CAN_TI0R_EXID_Msk                    (0x3FFFFUL << CAN_TI0R_EXID_Pos)
#define CAN_TI0R_EXID                        CAN_TI0R_EXID_Msk
#define CAN_TI0R_STID_Pos                    (21U)
#define CAN_TI0R_STID_Msk                    (0x7FFUL << CAN_TI0R_STID_Pos)
#define CAN_TI0R_STID                        CAN_TI0R_STID_Msk

#define CAN_TDT0R_DLC_Pos                    (0U)
#define CAN_TDT0R_DLC_Msk                    (0xFUL << CAN_TDT0R_DLC_Pos)
#define CAN_TDT0R_DLC                        CAN_TDT0R_DLC_Msk
#define CAN_TDT0R_TGT_Pos                    (8U)
#define CAN_TDT0R_TGT_Msk                    (0x1UL << CAN_TDT0R_TGT_Pos)
#define CAN_TDT0R_TGT                        CAN_TDT0R_TGT_Msk
#define CAN_TDT0R_TIME_Pos                   (16U)
#define CAN_TDT0R_TIME_Msk                   (0xFFFFUL << CAN_TDT0R_TIME_Pos)
#define CAN_TDT0R_TIME                       CAN_TDT0R_TIME_Msk

#define CAN_TDL0R_DATA0_Pos                  (0U)
#define CAN_TDL0R_DATA0_Msk                  (0xFFUL << CAN_TDL0R_DATA0_Pos)
#define CAN_TDL0R_DATA0                      CAN_TDL0R_DATA0_Msk
#define CAN_TDL0R_DATA1_Pos                  (8U)
#define CAN_TDL0R_DATA1_Msk                  (0xFFUL << CAN_TDL0R_DATA1_Pos)
#define CAN_TDL0R_DATA1                      CAN_TDL0R_DATA1_Msk
#define CAN_TDL0R_DATA2_Pos                  (16U)
#define CAN_TDL0R_DATA2_Msk                  (0xFFUL << CAN_TDL0R_DATA2_Pos)
#define CAN_TDL0R_DATA2                      CAN_TDL0R_DATA2_Msk
#define CAN_TDL0R_DATA3_Pos                  (24U)
#define CAN_TDL0R_DATA3_Msk                  (0xFFUL << CAN_TDL0R_DATA3_Pos)
#define CAN_TDL0R_DATA3                      CAN_TDL0R_DATA3_Msk

#define CAN_TDH0R_DATA4_Pos                  (0U)
#define CAN_TDH0R_DATA4_Msk                  (0xFFUL << CAN_TDH0R_DATA4_Pos)
#define CAN_TDH0R_DATA4                      CAN_TDH0R_DATA4_Msk
#define CAN_TDH0R_DATA5_Pos                  (8U)
#define CAN_TDH0R_DATA5_Msk                  (0xFFUL << CAN_TDH0R_DATA5_Pos)
#define CAN_TDH0R_DATA5                      CAN_TDH0R_DATA5_Msk
#define CAN_TDH0R_DATA6_Pos                  (16U)
#define CAN_TDH0R_DATA6_Msk                  (0xFFUL << CAN_TDH0R_DATA6_Pos)
#define CAN_TDH0R_DATA6                      CAN_TDH0R_DATA6_Msk
#define CAN_TDH0R_DATA7_Pos                  (24U)
#define CAN_TDH0R_DATA7_Msk                  (0xFFUL << CAN_TDH0R_DATA7_Pos)
#define CAN_TDH0R_DATA7                      CAN_TDH0R_DATA7_Msk

#define CAN_TI1R_TXRQ_Pos                    (0U)
#define CAN_TI1R_TXRQ_Msk                    (0x1UL << CAN_TI1R_TXRQ_Pos)
#define CAN_TI1R_TXRQ                        CAN_TI1R_TXRQ_Msk
#define CAN_TI1R_RTR_Pos                     (1U)
#define CAN_TI1R_RTR_Msk                     (0x1UL << CAN_TI1R_RTR_Pos)
#define CAN_TI1R_RTR                         CAN_TI1R_RTR_Msk
#define CAN_TI1R_IDE_Pos                     (2U)
#define CAN_TI1R_IDE_Msk                     (0x1UL << CAN_TI1R_IDE_Pos)
#define CAN_TI1R_IDE                         CAN_TI1R_IDE_Msk
#define CAN_TI1R_EXID_Pos                    (3U)
#define CAN_TI1R_EXID_Msk                    (0x3FFFFUL << CAN_TI1R_EXID_Pos)
#define CAN_TI1R_EXID                        CAN_TI1R_EXID_Msk
#define CAN_TI1R_STID_Pos                    (21U)
#define CAN_TI1R_STID_Msk                    (0x7FFUL << CAN_TI1R_STID_Pos)
#define CAN_TI1R_STID                        CAN_TI1R_STID_Msk

#define CAN_TDT1R_DLC_Pos                    (0U)
#define CAN_TDT1R_DLC_Msk                    (0xFUL << CAN_TDT1R_DLC_Pos)
#define CAN_TDT1R_DLC                        CAN_TDT1R_DLC_Msk
#define CAN_TDT1R_TGT_Pos                    (8U)
#define CAN_TDT1R_TGT_Msk                    (0x1UL << CAN_TDT1R_TGT_Pos)
#define CAN_TDT1R_TGT                        CAN_TDT1R_TGT_Msk
#define CAN_TDT1R_TIME_Pos                   (16U)
#define CAN_TDT1R_TIME_Msk                   (0xFFFFUL << CAN_TDT1R_TIME_Pos)
#define CAN_TDT1R_TIME                       CAN_TDT1R_TIME_Msk

#define CAN_TDL1R_DATA0_Pos                  (0U)
#define CAN_TDL1R_DATA0_Msk                  (0xFFUL << CAN_TDL1R_DATA0_Pos)
#define CAN_TDL1R_DATA0                      CAN_TDL1R_DATA0_Msk
#define CAN_TDL1R_DATA1_Pos                  (8U)
#define CAN_TDL1R_DATA1_Msk                  (0xFFUL << CAN_TDL1R_DATA1_Pos)
#define CAN_TDL1R_DATA1                      CAN_TDL1R_DATA1_Msk
#define CAN_TDL1R_DATA2_Pos                  (16U)
#define CAN_TDL1R_DATA2_Msk                  (0xFFUL << CAN_TDL1R_DATA2_Pos)
#define CAN_TDL1R_DATA2                      CAN_TDL1R_DATA2_Msk
#define CAN_TDL1R_DATA3_Pos                  (24U)
#define CAN_TDL1R_DATA3_Msk                  (0xFFUL << CAN_TDL1R_DATA3_Pos)
#define CAN_TDL1R_DATA3                      CAN_TDL1R_DATA3_Msk

#define CAN_TDH1R_DATA4_Pos                  (0U)
#define CAN_TDH1R_DATA4_Msk                  (0xFFUL << CAN_TDH1R_DATA4_Pos)
#define CAN_TDH1R_DATA4                      CAN_TDH1R_DATA4_Msk
#define CAN_TDH1R_DATA5_Pos                  (8U)
#define CAN_TDH1R_DATA5_Msk                  (0xFFUL << CAN_TDH1R_DATA5_Pos)
#define CAN_TDH1R_DATA5                      CAN_TDH1R_DATA5_Msk
#define CAN_TDH1R_DATA6_Pos                  (16U)
#define CAN_TDH1R_DATA6_Msk                  (0xFFUL << CAN_TDH1R_DATA6_Pos)
#define CAN_TDH1R_DATA6                      CAN_TDH1R_DATA6_Msk
#define CAN_TDH1R_DATA7_Pos                  (24U)
#define CAN_TDH1R_DATA7_Msk                  (0xFFUL << CAN_TDH1R_DATA7_Pos)
#define CAN_TDH1R_DATA7                      CAN_TDH1R_DATA7_Msk

#define CAN_TI2R_TXRQ_Pos                    (0U)
#define CAN_TI2R_TXRQ_Msk                    (0x1UL << CAN_TI2R_TXRQ_Pos)
#define CAN_TI2R_TXRQ                        CAN_TI2R_TXRQ_Msk
#define CAN_TI2R_RTR_Pos                     (1U)
#define CAN_TI2R_RTR_Msk                     (0x1UL << CAN_TI2R_RTR_Pos)
#define CAN_TI2R_RTR                         CAN_TI2R_RTR_Msk
#define CAN_TI2R_IDE_Pos                     (2U)
#define CAN_TI2R_IDE_Msk                     (0x1UL << CAN_TI2R_IDE_Pos)
#define CAN_TI2R_IDE                         CAN_TI2R_IDE_Msk
#define CAN_TI2R_EXID_Pos                    (3U)
#define CAN_TI2R_EXID_Msk                    (0x3FFFFUL << CAN_TI2R_EXID_Pos)
#define CAN_TI2R_EXID                        CAN_TI2R_EXID_Msk
#define CAN_TI2R_STID_Pos                    (21U)
#define CAN_TI2R_STID_Msk                    (0x7FFUL << CAN_TI2R_STID_Pos)
#define CAN_TI2R_STID                        CAN_TI2R_STID_Msk

#define CAN_TDT2R_DLC_Pos                    (0U)
#define CAN_TDT2R_DLC_Msk                    (0xFUL << CAN_TDT2R_DLC_Pos)
#define CAN_TDT2R_DLC                        CAN_TDT2R_DLC_Msk
#define CAN_TDT2R_TGT_Pos                    (8U)
#define CAN_TDT2R_TGT_Msk                    (0x1UL << CAN_TDT2R_TGT_Pos)
#define CAN_TDT2R_TGT                        CAN_TDT2R_TGT_Msk
#define CAN_TDT2R_TIME_Pos                   (16U)
#define CAN_TDT2R_TIME_Msk                   (0xFFFFUL << CAN_TDT2R_TIME_Pos)
#define CAN_TDT2R_TIME                       CAN_TDT2R_TIME_Msk

#define CAN_TDL2R_DATA0_Pos                  (0U)
#define CAN_TDL2R_DATA0_Msk                  (0xFFUL << CAN_TDL2R_DATA0_Pos)
#define CAN_TDL2R_DATA0                      CAN_TDL2R_DATA0_Msk
#define CAN_TDL2R_DATA1_Pos                  (8U)
#define CAN_TDL2R_DATA1_Msk                  (0xFFUL << CAN_TDL2R_DATA1_Pos)
#define CAN_TDL2R_DATA1                      CAN_TDL2R_DATA1_Msk
#define CAN_TDL2R_DATA2_Pos                  (16U)
#define CAN_TDL2R_DATA2_Msk                  (0xFFUL << CAN_TDL2R_DATA2_Pos)
#define CAN_TDL2R_DATA2                      CAN_TDL2R_DATA2_Msk
#define CAN_TDL2R_DATA3_Pos                  (24U)
#define CAN_TDL2R_DATA3_Msk                  (0xFFUL << CAN_TDL2R_DATA3_Pos)
#define CAN_TDL2R_DATA3                      CAN_TDL2R_DATA3_Msk

#define CAN_TDH2R_DATA4_Pos                  (0U)
#define CAN_TDH2R_DATA4_Msk                  (0xFFUL << CAN_TDH2R_DATA4_Pos)
#define CAN_TDH2R_DATA4                      CAN_TDH2R_DATA4_Msk
#define CAN_TDH2R_DATA5_Pos                  (8U)
#define CAN_TDH2R_DATA5_Msk                  (0xFFUL << CAN_TDH2R_DATA5_Pos)
#define CAN_TDH2R_DATA5                      CAN_TDH2R_DATA5_Msk
#define CAN_TDH2R_DATA6_Pos                  (16U)
#define CAN_TDH2R_DATA6_Msk                  (0xFFUL << CAN_TDH2R_DATA6_Pos)
#define CAN_TDH2R_DATA6                      CAN_TDH2R_DATA6_Msk
#define CAN_TDH2R_DATA7_Pos                  (24U)
#define CAN_TDH2R_DATA7_Msk                  (0xFFUL << CAN_TDH2R_DATA7_Pos)
#define CAN_TDH2R_DATA7                      CAN_TDH2R_DATA7_Msk

#define CAN_RI0R_RTR_Pos                     (1U)
#define CAN_RI0R_RTR_Msk                     (0x1UL << CAN_RI0R_RTR_Pos)
#define CAN_RI0R_RTR                         CAN_RI0R_RTR_Msk
#define CAN_RI0R_IDE_Pos                     (2U)
#define CAN_RI0R_IDE_Msk                     (0x1UL << CAN_RI0R_IDE_Pos)
#define CAN_RI0R_IDE                         CAN_RI0R_IDE_Msk
#define CAN_RI0R_EXID_Pos                    (3U)
#define CAN_RI0R_EXID_Msk                    (0x3FFFFUL << CAN_RI0R_EXID_Pos)
#define CAN_RI0R_EXID                        CAN_RI0R_EXID_Msk
#define CAN_RI0R_STID_Pos                    (21U)
#define CAN_RI0R_STID_Msk                    (0x7FFUL << CAN_RI0R_STID_Pos)
#define CAN_RI0R_STID                        CAN_RI0R_STID_Msk

#define CAN_RDT0R_DLC_Pos                    (0U)
#define CAN_RDT0R_DLC_Msk                    (0xFUL << CAN_RDT0R_DLC_Pos)
#define CAN_RDT0R_DLC                        CAN_RDT0R_DLC_Msk
#define CAN_RDT0R_FMI_Pos                    (8U)
#define CAN_RDT0R_FMI_Msk                    (0xFFUL << CAN_RDT0R_FMI_Pos)
#define CAN_RDT0R_FMI                        CAN_RDT0R_FMI_Msk
#define CAN_RDT0R_TIME_Pos                   (16U)
#define CAN_RDT0R_TIME_Msk                   (0xFFFFUL << CAN_RDT0R_TIME_Pos)
#define CAN_RDT0R_TIME                       CAN_RDT0R_TIME_Msk

#define CAN_RDL0R_DATA0_Pos                  (0U)
#define CAN_RDL0R_DATA0_Msk                  (0xFFUL << CAN_RDL0R_DATA0_Pos)
#define CAN_RDL0R_DATA0                      CAN_RDL0R_DATA0_Msk
#define CAN_RDL0R_DATA1_Pos                  (8U)
#define CAN_RDL0R_DATA1_Msk                  (0xFFUL << CAN_RDL0R_DATA1_Pos)
#define CAN_RDL0R_DATA1                      CAN_RDL0R_DATA1_Msk
#define CAN_RDL0R_DATA2_Pos                  (16U)
#define CAN_RDL0R_DATA2_Msk                  (0xFFUL << CAN_RDL0R_DATA2_Pos)
#define CAN_RDL0R_DATA2                      CAN_RDL0R_DATA2_Msk
#define CAN_RDL0R_DATA3_Pos                  (24U)
#define CAN_RDL0R_DATA3_Msk                  (0xFFUL << CAN_RDL0R_DATA3_Pos)
#define CAN_RDL0R_DATA3                      CAN_RDL0R_DATA3_Msk

#define CAN_RDH0R_DATA4_Pos                  (0U)
#define CAN_RDH0R_DATA4_Msk                  (0xFFUL << CAN_RDH0R_DATA4_Pos)
#define CAN_RDH0R_DATA4                      CAN_RDH0R_DATA4_Msk
#define CAN_RDH0R_DATA5_Pos                  (8U)
#define CAN_RDH0R_DATA5_Msk                  (0xFFUL << CAN_RDH0R_DATA5_Pos)
#define CAN_RDH0R_DATA5                      CAN_RDH0R_DATA5_Msk
#define CAN_RDH0R_DATA6_Pos                  (16U)
#define CAN_RDH0R_DATA6_Msk                  (0xFFUL << CAN_RDH0R_DATA6_Pos)
#define CAN_RDH0R_DATA6                      CAN_RDH0R_DATA6_Msk
#define CAN_RDH0R_DATA7_Pos                  (24U)
#define CAN_RDH0R_DATA7_Msk                  (0xFFUL << CAN_RDH0R_DATA7_Pos)
#define CAN_RDH0R_DATA7                      CAN_RDH0R_DATA7_Msk

#define CAN_RI1R_RTR_Pos                     (1U)
#define CAN_RI1R_RTR_Msk                     (0x1UL << CAN_RI1R_RTR_Pos)
#define CAN_RI1R_RTR                         CAN_RI1R_RTR_Msk
#define CAN_RI1R_IDE_Pos                     (2U)
#define CAN_RI1R_IDE_Msk                     (0x1UL << CAN_RI1R_IDE_Pos)
#define CAN_RI1R_IDE                         CAN_RI1R_IDE_Msk
#define CAN_RI1R_EXID_Pos                    (3U)
#define CAN_RI1R_EXID_Msk                    (0x3FFFFUL << CAN_RI1R_EXID_Pos)
#define CAN_RI1R_EXID                        CAN_RI1R_EXID_Msk
#define CAN_RI1R_STID_Pos                    (21U)
#define CAN_RI1R_STID_Msk                    (0x7FFUL << CAN_RI1R_STID_Pos)
#define CAN_RI1R_STID                        CAN_RI1R_STID_Msk

#define CAN_RDT1R_DLC_Pos                    (0U)
#define CAN_RDT1R_DLC_Msk                    (0xFUL << CAN_RDT1R_DLC_Pos)
#define CAN_RDT1R_DLC                        CAN_RDT1R_DLC_Msk
#define CAN_RDT1R_FMI_Pos                    (8U)
#define CAN_RDT1R_FMI_Msk                    (0xFFUL << CAN_RDT1R_FMI_Pos)
#define CAN_RDT1R_FMI                        CAN_RDT1R_FMI_Msk
#define CAN_RDT1R_TIME_Pos                   (16U)
#define CAN_RDT1R_TIME_Msk                   (0xFFFFUL << CAN_RDT1R_TIME_Pos)
#define CAN_RDT1R_TIME                       CAN_RDT1R_TIME_Msk

#define CAN_RDL1R_DATA0_Pos                  (0U)
#define CAN_RDL1R_DATA0_Msk                  (0xFFUL << CAN_RDL1R_DATA0_Pos)
#define CAN_RDL1R_DATA0                      CAN_RDL1R_DATA0_Msk
#define CAN_RDL1R_DATA1_Pos                  (8U)
#define CAN_RDL1R_DATA1_Msk                  (0xFFUL << CAN_RDL1R_DATA1_Pos)
#define CAN_RDL1R_DATA1                      CAN_RDL1R_DATA1_Msk
#define CAN_RDL1R_DATA2_Pos                  (16U)
#define CAN_RDL1R_DATA2_Msk                  (0xFFUL << CAN_RDL1R_DATA2_Pos)
#define CAN_RDL1R_DATA2                      CAN_RDL1R_DATA2_Msk
#define CAN_RDL1R_DATA3_Pos                  (24U)
#define CAN_RDL1R_DATA3_Msk                  (0xFFUL << CAN_RDL1R_DATA3_Pos)
#define CAN_RDL1R_DATA3                      CAN_RDL1R_DATA3_Msk

#define CAN_RDH1R_DATA4_Pos                  (0U)
#define CAN_RDH1R_DATA4_Msk                  (0xFFUL << CAN_RDH1R_DATA4_Pos)
#define CAN_RDH1R_DATA4                      CAN_RDH1R_DATA4_Msk
#define CAN_RDH1R_DATA5_Pos                  (8U)
#define CAN_RDH1R_DATA5_Msk                  (0xFFUL << CAN_RDH1R_DATA5_Pos)
#define CAN_RDH1R_DATA5                      CAN_RDH1R_DATA5_Msk
#define CAN_RDH1R_DATA6_Pos                  (16U)
#define CAN_RDH1R_DATA6_Msk                  (0xFFUL << CAN_RDH1R_DATA6_Pos)
#define CAN_RDH1R_DATA6                      CAN_RDH1R_DATA6_Msk
#define CAN_RDH1R_DATA7_Pos                  (24U)
#define CAN_RDH1R_DATA7_Msk                  (0xFFUL << CAN_RDH1R_DATA7_Pos)
#define CAN_RDH1R_DATA7                      CAN_RDH1R_DATA7_Msk

#define CAN_FMR_FINIT_Pos                    (0U)
#define CAN_FMR_FINIT_Msk                    (0x1UL << CAN_FMR_FINIT_Pos)
#define CAN_FMR_FINIT                        CAN_FMR_FINIT_Msk
#define CAN_FMR_CAN2SB_Pos                   (8U)
#define CAN_FMR_CAN2SB_Msk                   (0x3FUL << CAN_FMR_CAN2SB_Pos)
#define CAN_FMR_CAN2SB                       CAN_FMR_CAN2SB_Msk

#define CAN_FM1R_FBM_Pos                     (0U)
#define CAN_FM1R_FBM_Msk                     (0x3FFFUL << CAN_FM1R_FBM_Pos)
#define CAN_FM1R_FBM                         CAN_FM1R_FBM_Msk
#define CAN_FM1R_FBM0_Pos                    (0U)
#define CAN_FM1R_FBM0_Msk                    (0x1UL << CAN_FM1R_FBM0_Pos)
#define CAN_FM1R_FBM0                        CAN_FM1R_FBM0_Msk
#define CAN_FM1R_FBM1_Pos                    (1U)
#define CAN_FM1R_FBM1_Msk                    (0x1UL << CAN_FM1R_FBM1_Pos)
#define CAN_FM1R_FBM1                        CAN_FM1R_FBM1_Msk
#define CAN_FM1R_FBM2_Pos                    (2U)
#define CAN_FM1R_FBM2_Msk                    (0x1UL << CAN_FM1R_FBM2_Pos)
#define CAN_FM1R_FBM2                        CAN_FM1R_FBM2_Msk
#define CAN_FM1R_FBM3_Pos                    (3U)
#define CAN_FM1R_FBM3_Msk                    (0x1UL << CAN_FM1R_FBM3_Pos)
#define CAN_FM1R_FBM3                        CAN_FM1R_FBM3_Msk
#define CAN_FM1R_FBM4_Pos                    (4U)
#define CAN_FM1R_FBM4_Msk                    (0x1UL << CAN_FM1R_FBM4_Pos)
#define CAN_FM1R_FBM4                        CAN_FM1R_FBM4_Msk
#define CAN_FM1R_FBM5_Pos                    (5U)
#define CAN_FM1R_FBM5_Msk                    (0x1UL << CAN_FM1R_FBM5_Pos)
#define CAN_FM1R_FBM5                        CAN_FM1R_FBM5_Msk
#define CAN_FM1R_FBM6_Pos                    (6U)
#define CAN_FM1R_FBM6_Msk                    (0x1UL << CAN_FM1R_FBM6_Pos)
#define CAN_FM1R_FBM6                        CAN_FM1R_FBM6_Msk
#define CAN_FM1R_FBM7_Pos                    (7U)
#define CAN_FM1R_FBM7_Msk                    (0x1UL << CAN_FM1R_FBM7_Pos)
#define CAN_FM1R_FBM7                        CAN_FM1R_FBM7_Msk
#define CAN_FM1R_FBM8_Pos                    (8U)
#define CAN_FM1R_FBM8_Msk                    (0x1UL << CAN_FM1R_FBM8_Pos)
#define CAN_FM1R_FBM8                        CAN_FM1R_FBM8_Msk
#define CAN_FM1R_FBM9_Pos                    (9U)
#define CAN_FM1R_FBM9_Msk                    (0x1UL << CAN_FM1R_FBM9_Pos)
#define CAN_FM1R_FBM9                        CAN_FM1R_FBM9_Msk
#define CAN_FM1R_FBM10_Pos                   (10U)
#define CAN_FM1R_FBM10_Msk                   (0x1UL << CAN_FM1R_FBM10_Pos)
#define CAN_FM1R_FBM10                       CAN_FM1R_FBM10_Msk
#define CAN_FM1R_FBM11_Pos                   (11U)
#define CAN_FM1R_FBM11_Msk                   (0x1UL << CAN_FM1R_FBM11_Pos)
#define CAN_FM1R_FBM11                       CAN_FM1R_FBM11_Msk
#define CAN_FM1R_FBM12_Pos                   (12U)
#define CAN_FM1R_FBM12_Msk                   (0x1UL << CAN_FM1R_FBM12_Pos)
#define CAN_FM1R_FBM12                       CAN_FM1R_FBM12_Msk
#define CAN_FM1R_FBM13_Pos                   (13U)
#define CAN_FM1R_FBM13_Msk                   (0x1UL << CAN_FM1R_FBM13_Pos)
#define CAN_FM1R_FBM13                       CAN_FM1R_FBM13_Msk

#define CAN_FS1R_FSC_Pos                     (0U)
#define CAN_FS1R_FSC_Msk                     (0x3FFFUL << CAN_FS1R_FSC_Pos)
#define CAN_FS1R_FSC                         CAN_FS1R_FSC_Msk
#define CAN_FS1R_FSC0_Pos                    (0U)
#define CAN_FS1R_FSC0_Msk                    (0x1UL << CAN_FS1R_FSC0_Pos)
#define CAN_FS1R_FSC0                        CAN_FS1R_FSC0_Msk
#define CAN_FS1R_FSC1_Pos                    (1U)
#define CAN_FS1R_FSC1_Msk                    (0x1UL << CAN_FS1R_FSC1_Pos)
#define CAN_FS1R_FSC1                        CAN_FS1R_FSC1_Msk
#define CAN_FS1R_FSC2_Pos                    (2U)
#define CAN_FS1R_FSC2_Msk                    (0x1UL << CAN_FS1R_FSC2_Pos)
#define CAN_FS1R_FSC2                        CAN_FS1R_FSC2_Msk
#define CAN_FS1R_FSC3_Pos                    (3U)
#define CAN_FS1R_FSC3_Msk                    (0x1UL << CAN_FS1R_FSC3_Pos)
#define CAN_FS1R_FSC3                        CAN_FS1R_FSC3_Msk
#define CAN_FS1R_FSC4_Pos                    (4U)
#define CAN_FS1R_FSC4_Msk                    (0x1UL << CAN_FS1R_FSC4_Pos)
#define CAN_FS1R_FSC4                        CAN_FS1R_FSC4_Msk
#define CAN_FS1R_FSC5_Pos                    (5U)
#define CAN_FS1R_FSC5_Msk                    (0x1UL << CAN_FS1R_FSC5_Pos)
#define CAN_FS1R_FSC5                        CAN_FS1R_FSC5_Msk
#define CAN_FS1R_FSC6_Pos                    (6U)
#define CAN_FS1R_FSC6_Msk                    (0x1UL << CAN_FS1R_FSC6_Pos)
#define CAN_FS1R_FSC6                        CAN_FS1R_FSC6_Msk
#define CAN_FS1R_FSC7_Pos                    (7U)
#define CAN_FS1R_FSC7_Msk                    (0x1UL << CAN_FS1R_FSC7_Pos)
#define CAN_FS1R_FSC7                        CAN_FS1R_FSC7_Msk
#define CAN_FS1R_FSC8_Pos                    (8U)
#define CAN_FS1R_FSC8_Msk                    (0x1UL << CAN_FS1R_FSC8_Pos)
#define CAN_FS1R_FSC8                        CAN_FS1R_FSC8_Msk
#define CAN_FS1R_FSC9_Pos                    (9U)
#define CAN_FS1R_FSC9_Msk                    (0x1UL << CAN_FS1R_FSC9_Pos)
#define CAN_FS1R_FSC9                        CAN_FS1R_FSC9_Msk
#define CAN_FS1R_FSC10_Pos                   (10U)
#define CAN_FS1R_FSC10_Msk                   (0x1UL << CAN_FS1R_FSC10_Pos)
#define CAN_FS1R_FSC10                       CAN_FS1R_FSC10_Msk
#define CAN_FS1R_FSC11_Pos                   (11U)
#define CAN_FS1R_FSC11_Msk                   (0x1UL << CAN_FS1R_FSC11_Pos)
#define CAN_FS1R_FSC11                       CAN_FS1R_FSC11_Msk
#define CAN_FS1R_FSC12_Pos                   (12U)
#define CAN_FS1R_FSC12_Msk                   (0x1UL << CAN_FS1R_FSC12_Pos)
#define CAN_FS1R_FSC12                       CAN_FS1R_FSC12_Msk
#define CAN_FS1R_FSC13_Pos                   (13U)
#define CAN_FS1R_FSC13_Msk                   (0x1UL << CAN_FS1R_FSC13_Pos)
#define CAN_FS1R_FSC13                       CAN_FS1R_FSC13_Msk

#define CAN_FFA1R_FFA_Pos                    (0U)
#define CAN_FFA1R_FFA_Msk                    (0x3FFFUL << CAN_FFA1R_FFA_Pos)
#define CAN_FFA1R_FFA                        CAN_FFA1R_FFA_Msk
#define CAN_FFA1R_FFA0_Pos                   (0U)
#define CAN_FFA1R_FFA0_Msk                   (0x1UL << CAN_FFA1R_FFA0_Pos)
#define CAN_FFA1R_FFA0                       CAN_FFA1R_FFA0_Msk
#define CAN_FFA1R_FFA1_Pos                   (1U)
#define CAN_FFA1R_FFA1_Msk                   (0x1UL << CAN_FFA1R_FFA1_Pos)
#define CAN_FFA1R_FFA1                       CAN_FFA1R_FFA1_Msk
#define CAN_FFA1R_FFA2_Pos                   (2U)
#define CAN_FFA1R_FFA2_Msk                   (0x1UL << CAN_FFA1R_FFA2_Pos)
#define CAN_FFA1R_FFA2                       CAN_FFA1R_FFA2_Msk
#define CAN_FFA1R_FFA3_Pos                   (3U)
#define CAN_FFA1R_FFA3_Msk                   (0x1UL << CAN_FFA1R_FFA3_Pos)
#define CAN_FFA1R_FFA3                       CAN_FFA1R_FFA3_Msk
#define CAN_FFA1R_FFA4_Pos                   (4U)
#define CAN_FFA1R_FFA4_Msk                   (0x1UL << CAN_FFA1R_FFA4_Pos)
#define CAN_FFA1R_FFA4                       CAN_FFA1R_FFA4_Msk
#define CAN_FFA1R_FFA5_Pos                   (5U)
#define CAN_FFA1R_FFA5_Msk                   (0x1UL << CAN_FFA1R_FFA5_Pos)
#define CAN_FFA1R_FFA5                       CAN_FFA1R_FFA5_Msk
#define CAN_FFA1R_FFA6_Pos                   (6U)
#define CAN_FFA1R_FFA6_Msk                   (0x1UL << CAN_FFA1R_FFA6_Pos)
#define CAN_FFA1R_FFA6                       CAN_FFA1R_FFA6_Msk
#define CAN_FFA1R_FFA7_Pos                   (7U)
#define CAN_FFA1R_FFA7_Msk                   (0x1UL << CAN_FFA1R_FFA7_Pos)
#define CAN_FFA1R_FFA7                       CAN_FFA1R_FFA7_Msk
#define CAN_FFA1R_FFA8_Pos                   (8U)
#define CAN_FFA1R_FFA8_Msk                   (0x1UL << CAN_FFA1R_FFA8_Pos)
#define CAN_FFA1R_FFA8                       CAN_FFA1R_FFA8_Msk
#define CAN_FFA1R_FFA9_Pos                   (9U)
#define CAN_FFA1R_FFA9_Msk                   (0x1UL << CAN_FFA1R_FFA9_Pos)
#define CAN_FFA1R_FFA9                       CAN_FFA1R_FFA9_Msk
#define CAN_FFA1R_FFA10_Pos                  (10U)
#define CAN_FFA1R_FFA10_Msk                  (0x1UL << CAN_FFA1R_FFA10_Pos)
#define CAN_FFA1R_FFA10                      CAN_FFA1R_FFA10_Msk
#define CAN_FFA1R_FFA11_Pos                  (11U)
#define CAN_FFA1R_FFA11_Msk                  (0x1UL << CAN_FFA1R_FFA11_Pos)
#define CAN_FFA1R_FFA11                      CAN_FFA1R_FFA11_Msk
#define CAN_FFA1R_FFA12_Pos                  (12U)
#define CAN_FFA1R_FFA12_Msk                  (0x1UL << CAN_FFA1R_FFA12_Pos)
#define CAN_FFA1R_FFA12                      CAN_FFA1R_FFA12_Msk
#define CAN_FFA1R_FFA13_Pos                  (13U)
#define CAN_FFA1R_FFA13_Msk                  (0x1UL << CAN_FFA1R_FFA13_Pos)
#define CAN_FFA1R_FFA13                      CAN_FFA1R_FFA13_Msk

#define CAN_FA1R_FACT_Pos                    (0U)
#define CAN_FA1R_FACT_Msk                    (0x3FFFUL << CAN_FA1R_FACT_Pos)
#define CAN_FA1R_FACT                        CAN_FA1R_FACT_Msk
#define CAN_FA1R_FACT0_Pos                   (0U)
#define CAN_FA1R_FACT0_Msk                   (0x1UL << CAN_FA1R_FACT0_Pos)
#define CAN_FA1R_FACT0                       CAN_FA1R_FACT0_Msk
#define CAN_FA1R_FACT1_Pos                   (1U)
#define CAN_FA1R_FACT1_Msk                   (0x1UL << CAN_FA1R_FACT1_Pos)
#define CAN_FA1R_FACT1                       CAN_FA1R_FACT1_Msk
#define CAN_FA1R_FACT2_Pos                   (2U)
#define CAN_FA1R_FACT2_Msk                   (0x1UL << CAN_FA1R_FACT2_Pos)
#define CAN_FA1R_FACT2                       CAN_FA1R_FACT2_Msk
#define CAN_FA1R_FACT3_Pos                   (3U)
#define CAN_FA1R_FACT3_Msk                   (0x1UL << CAN_FA1R_FACT3_Pos)
#define CAN_FA1R_FACT3                       CAN_FA1R_FACT3_Msk
#define CAN_FA1R_FACT4_Pos                   (4U)
#define CAN_FA1R_FACT4_Msk                   (0x1UL << CAN_FA1R_FACT4_Pos)
#define CAN_FA1R_FACT4                       CAN_FA1R_FACT4_Msk
#define CAN_FA1R_FACT5_Pos                   (5U)
#define CAN_FA1R_FACT5_Msk                   (0x1UL << CAN_FA1R_FACT5_Pos)
#define CAN_FA1R_FACT5                       CAN_FA1R_FACT5_Msk
#define CAN_FA1R_FACT6_Pos                   (6U)
#define CAN_FA1R_FACT6_Msk                   (0x1UL << CAN_FA1R_FACT6_Pos)
#define CAN_FA1R_FACT6                       CAN_FA1R_FACT6_Msk
#define CAN_FA1R_FACT7_Pos                   (7U)
#define CAN_FA1R_FACT7_Msk                   (0x1UL << CAN_FA1R_FACT7_Pos)
#define CAN_FA1R_FACT7                       CAN_FA1R_FACT7_Msk
#define CAN_FA1R_FACT8_Pos                   (8U)
#define CAN_FA1R_FACT8_Msk                   (0x1UL << CAN_FA1R_FACT8_Pos)
#define CAN_FA1R_FACT8                       CAN_FA1R_FACT8_Msk
#define CAN_FA1R_FACT9_Pos                   (9U)
#define CAN_FA1R_FACT9_Msk                   (0x1UL << CAN_FA1R_FACT9_Pos)
#define CAN_FA1R_FACT9                       CAN_FA1R_FACT9_Msk
#define CAN_FA1R_FACT10_Pos                  (10U)
#define CAN_FA1R_FACT10_Msk                  (0x1UL << CAN_FA1R_FACT10_Pos)
#define CAN_FA1R_FACT10                      CAN_FA1R_FACT10_Msk
#define CAN_FA1R_FACT11_Pos                  (11U)
#define CAN_FA1R_FACT11_Msk                  (0x1UL << CAN_FA1R_FACT11_Pos)
#define CAN_FA1R_FACT11                      CAN_FA1R_FACT11_Msk
#define CAN_FA1R_FACT12_Pos                  (12U)
#define CAN_FA1R_FACT12_Msk                  (0x1UL << CAN_FA1R_FACT12_Pos)
#define CAN_FA1R_FACT12                      CAN_FA1R_FACT12_Msk
#define CAN_FA1R_FACT13_Pos                  (13U)
#define CAN_FA1R_FACT13_Msk                  (0x1UL << CAN_FA1R_FACT13_Pos)
#define CAN_FA1R_FACT13                      CAN_FA1R_FACT13_Msk

#define CAN_F0R1_FB0_Pos                     (0U)
#define CAN_F0R1_FB0_Msk                     (0x1UL << CAN_F0R1_FB0_Pos)
#define CAN_F0R1_FB0                         CAN_F0R1_FB0_Msk
#define CAN_F0R1_FB1_Pos                     (1U)
#define CAN_F0R1_FB1_Msk                     (0x1UL << CAN_F0R1_FB1_Pos)
#define CAN_F0R1_FB1                         CAN_F0R1_FB1_Msk
#define CAN_F0R1_FB2_Pos                     (2U)
#define CAN_F0R1_FB2_Msk                     (0x1UL << CAN_F0R1_FB2_Pos)
#define CAN_F0R1_FB2                         CAN_F0R1_FB2_Msk
#define CAN_F0R1_FB3_Pos                     (3U)
#define CAN_F0R1_FB3_Msk                     (0x1UL << CAN_F0R1_FB3_Pos)
#define CAN_F0R1_FB3                         CAN_F0R1_FB3_Msk
#define CAN_F0R1_FB4_Pos                     (4U)
#define CAN_F0R1_FB4_Msk                     (0x1UL << CAN_F0R1_FB4_Pos)
#define CAN_F0R1_FB4                         CAN_F0R1_FB4_Msk
#define CAN_F0R1_FB5_Pos                     (5U)
#define CAN_F0R1_FB5_Msk                     (0x1UL << CAN_F0R1_FB5_Pos)
#define CAN_F0R1_FB5                         CAN_F0R1_FB5_Msk
#define CAN_F0R1_FB6_Pos                     (6U)
#define CAN_F0R1_FB6_Msk                     (0x1UL << CAN_F0R1_FB6_Pos)
#define CAN_F0R1_FB6                         CAN_F0R1_FB6_Msk
#define CAN_F0R1_FB7_Pos                     (7U)
#define CAN_F0R1_FB7_Msk                     (0x1UL << CAN_F0R1_FB7_Pos)
#define CAN_F0R1_FB7                         CAN_F0R1_FB7_Msk
#define CAN_F0R1_FB8_Pos                     (8U)
#define CAN_F0R1_FB8_Msk                     (0x1UL << CAN_F0R1_FB8_Pos)
#define CAN_F0R1_FB8                         CAN_F0R1_FB8_Msk
#define CAN_F0R1_FB9_Pos                     (9U)
#define CAN_F0R1_FB9_Msk                     (0x1UL << CAN_F0R1_FB9_Pos)
#define CAN_F0R1_FB9                         CAN_F0R1_FB9_Msk
#define CAN_F0R1_FB10_Pos                    (10U)
#define CAN_F0R1_FB10_Msk                    (0x1UL << CAN_F0R1_FB10_Pos)
#define CAN_F0R1_FB10                        CAN_F0R1_FB10_Msk
#define CAN_F0R1_FB11_Pos                    (11U)
#define CAN_F0R1_FB11_Msk                    (0x1UL << CAN_F0R1_FB11_Pos)
#define CAN_F0R1_FB11                        CAN_F0R1_FB11_Msk
#define CAN_F0R1_FB12_Pos                    (12U)
#define CAN_F0R1_FB12_Msk                    (0x1UL << CAN_F0R1_FB12_Pos)
#define CAN_F0R1_FB12                        CAN_F0R1_FB12_Msk
#define CAN_F0R1_FB13_Pos                    (13U)
#define CAN_F0R1_FB13_Msk                    (0x1UL << CAN_F0R1_FB13_Pos)
#define CAN_F0R1_FB13                        CAN_F0R1_FB13_Msk
#define CAN_F0R1_FB14_Pos                    (14U)
#define CAN_F0R1_FB14_Msk                    (0x1UL << CAN_F0R1_FB14_Pos)
#define CAN_F0R1_FB14                        CAN_F0R1_FB14_Msk
#define CAN_F0R1_FB15_Pos                    (15U)
#define CAN_F0R1_FB15_Msk                    (0x1UL << CAN_F0R1_FB15_Pos)
#define CAN_F0R1_FB15                        CAN_F0R1_FB15_Msk
#define CAN_F0R1_FB16_Pos                    (16U)
#define CAN_F0R1_FB16_Msk                    (0x1UL << CAN_F0R1_FB16_Pos)
#define CAN_F0R1_FB16                        CAN_F0R1_FB16_Msk
#define CAN_F0R1_FB17_Pos                    (17U)
#define CAN_F0R1_FB17_Msk                    (0x1UL << CAN_F0R1_FB17_Pos)
#define CAN_F0R1_FB17                        CAN_F0R1_FB17_Msk
#define CAN_F0R1_FB18_Pos                    (18U)
#define CAN_F0R1_FB18_Msk                    (0x1UL << CAN_F0R1_FB18_Pos)
#define CAN_F0R1_FB18                        CAN_F0R1_FB18_Msk
#define CAN_F0R1_FB19_Pos                    (19U)
#define CAN_F0R1_FB19_Msk                    (0x1UL << CAN_F0R1_FB19_Pos)
#define CAN_F0R1_FB19                        CAN_F0R1_FB19_Msk
#define CAN_F0R1_FB20_Pos                    (20U)
#define CAN_F0R1_FB20_Msk                    (0x1UL << CAN_F0R1_FB20_Pos)
#define CAN_F0R1_FB20                        CAN_F0R1_FB20_Msk
#define CAN_F0R1_FB21_Pos                    (21U)
#define CAN_F0R1_FB21_Msk                    (0x1UL << CAN_F0R1_FB21_Pos)
#define CAN_F0R1_FB21                        CAN_F0R1_FB21_Msk
#define CAN_F0R1_FB22_Pos                    (22U)
#define CAN_F0R1_FB22_Msk                    (0x1UL << CAN_F0R1_FB22_Pos)
#define CAN_F0R1_FB22                        CAN_F0R1_FB22_Msk
#define CAN_F0R1_FB23_Pos                    (23U)
#define CAN_F0R1_FB23_Msk                    (0x1UL << CAN_F0R1_FB23_Pos)
#define CAN_F0R1_FB23                        CAN_F0R1_FB23_Msk
#define CAN_F0R1_FB24_Pos                    (24U)
#define CAN_F0R1_FB24_Msk                    (0x1UL << CAN_F0R1_FB24_Pos)
#define CAN_F0R1_FB24                        CAN_F0R1_FB24_Msk
#define CAN_F0R1_FB25_Pos                    (25U)
#define CAN_F0R1_FB25_Msk                    (0x1UL << CAN_F0R1_FB25_Pos)
#define CAN_F0R1_FB25                        CAN_F0R1_FB25_Msk
#define CAN_F0R1_FB26_Pos                    (26U)
#define CAN_F0R1_FB26_Msk                    (0x1UL << CAN_F0R1_FB26_Pos)
#define CAN_F0R1_FB26                        CAN_F0R1_FB26_Msk
#define CAN_F0R1_FB27_Pos                    (27U)
#define CAN_F0R1_FB27_Msk                    (0x1UL << CAN_F0R1_FB27_Pos)
#define CAN_F0R1_FB27                        CAN_F0R1_FB27_Msk
#define CAN_F0R1_FB28_Pos                    (28U)
#define CAN_F0R1_FB28_Msk                    (0x1UL << CAN_F0R1_FB28_Pos)
#define CAN_F0R1_FB28                        CAN_F0R1_FB28_Msk
#define CAN_F0R1_FB29_Pos                    (29U)
#define CAN_F0R1_FB29_Msk                    (0x1UL << CAN_F0R1_FB29_Pos)
#define CAN_F0R1_FB29                        CAN_F0R1_FB29_Msk
#define CAN_F0R1_FB30_Pos                    (30U)
#define CAN_F0R1_FB30_Msk                    (0x1UL << CAN_F0R1_FB30_Pos)
#define CAN_F0R1_FB30                        CAN_F0R1_FB30_Msk
#define CAN_F0R1_FB31_Pos                    (31U)
#define CAN_F0R1_FB31_Msk                    (0x1UL << CAN_F0R1_FB31_Pos)
#define CAN_F0R1_FB31                        CAN_F0R1_FB31_Msk

#define CAN_F1R1_FB0_Pos                     (0U)
#define CAN_F1R1_FB0_Msk                     (0x1UL << CAN_F1R1_FB0_Pos)
#define CAN_F1R1_FB0                         CAN_F1R1_FB0_Msk
#define CAN_F1R1_FB1_Pos                     (1U)
#define CAN_F1R1_FB1_Msk                     (0x1UL << CAN_F1R1_FB1_Pos)
#define CAN_F1R1_FB1                         CAN_F1R1_FB1_Msk
#define CAN_F1R1_FB2_Pos                     (2U)
#define CAN_F1R1_FB2_Msk                     (0x1UL << CAN_F1R1_FB2_Pos)
#define CAN_F1R1_FB2                         CAN_F1R1_FB2_Msk
#define CAN_F1R1_FB3_Pos                     (3U)
#define CAN_F1R1_FB3_Msk                     (0x1UL << CAN_F1R1_FB3_Pos)
#define CAN_F1R1_FB3                         CAN_F1R1_FB3_Msk
#define CAN_F1R1_FB4_Pos                     (4U)
#define CAN_F1R1_FB4_Msk                     (0x1UL << CAN_F1R1_FB4_Pos)
#define CAN_F1R1_FB4                         CAN_F1R1_FB4_Msk
#define CAN_F1R1_FB5_Pos                     (5U)
#define CAN_F1R1_FB5_Msk                     (0x1UL << CAN_F1R1_FB5_Pos)
#define CAN_F1R1_FB5                         CAN_F1R1_FB5_Msk
#define CAN_F1R1_FB6_Pos                     (6U)
#define CAN_F1R1_FB6_Msk                     (0x1UL << CAN_F1R1_FB6_Pos)
#define CAN_F1R1_FB6                         CAN_F1R1_FB6_Msk
#define CAN_F1R1_FB7_Pos                     (7U)
#define CAN_F1R1_FB7_Msk                     (0x1UL << CAN_F1R1_FB7_Pos)
#define CAN_F1R1_FB7                         CAN_F1R1_FB7_Msk
#define CAN_F1R1_FB8_Pos                     (8U)
#define CAN_F1R1_FB8_Msk                     (0x1UL << CAN_F1R1_FB8_Pos)
#define CAN_F1R1_FB8                         CAN_F1R1_FB8_Msk
#define CAN_F1R1_FB9_Pos                     (9U)
#define CAN_F1R1_FB9_Msk                     (0x1UL << CAN_F1R1_FB9_Pos)
#define CAN_F1R1_FB9                         CAN_F1R1_FB9_Msk
#define CAN_F1R1_FB10_Pos                    (10U)
#define CAN_F1R1_FB10_Msk                    (0x1UL << CAN_F1R1_FB10_Pos)
#define CAN_F1R1_FB10                        CAN_F1R1_FB10_Msk
#define CAN_F1R1_FB11_Pos                    (11U)
#define CAN_F1R1_FB11_Msk                    (0x1UL << CAN_F1R1_FB11_Pos)
#define CAN_F1R1_FB11                        CAN_F1R1_FB11_Msk
#define CAN_F1R1_FB12_Pos                    (12U)
#define CAN_F1R1_FB12_Msk                    (0x1UL << CAN_F1R1_FB12_Pos)
#define CAN_F1R1_FB12                        CAN_F1R1_FB12_Msk
#define CAN_F1R1_FB13_Pos                    (13U)
#define CAN_F1R1_FB13_Msk                    (0x1UL << CAN_F1R1_FB13_Pos)
#define CAN_F1R1_FB13                        CAN_F1R1_FB13_Msk
#define CAN_F1R1_FB14_Pos                    (14U)
#define CAN_F1R1_FB14_Msk                    (0x1UL << CAN_F1R1_FB14_Pos)
#define CAN_F1R1_FB14                        CAN_F1R1_FB14_Msk
#define CAN_F1R1_FB15_Pos                    (15U)
#define CAN_F1R1_FB15_Msk                    (0x1UL << CAN_F1R1_FB15_Pos)
#define CAN_F1R1_FB15                        CAN_F1R1_FB15_Msk
#define CAN_F1R1_FB16_Pos                    (16U)
#define CAN_F1R1_FB16_Msk                    (0x1UL << CAN_F1R1_FB16_Pos)
#define CAN_F1R1_FB16                        CAN_F1R1_FB16_Msk
#define CAN_F1R1_FB17_Pos                    (17U)
#define CAN_F1R1_FB17_Msk                    (0x1UL << CAN_F1R1_FB17_Pos)
#define CAN_F1R1_FB17                        CAN_F1R1_FB17_Msk
#define CAN_F1R1_FB18_Pos                    (18U)
#define CAN_F1R1_FB18_Msk                    (0x1UL << CAN_F1R1_FB18_Pos)
#define CAN_F1R1_FB18                        CAN_F1R1_FB18_Msk
#define CAN_F1R1_FB19_Pos                    (19U)
#define CAN_F1R1_FB19_Msk                    (0x1UL << CAN_F1R1_FB19_Pos)
#define CAN_F1R1_FB19                        CAN_F1R1_FB19_Msk
#define CAN_F1R1_FB20_Pos                    (20U)
#define CAN_F1R1_FB20_Msk                    (0x1UL << CAN_F1R1_FB20_Pos)
#define CAN_F1R1_FB20                        CAN_F1R1_FB20_Msk
#define CAN_F1R1_FB21_Pos                    (21U)
#define CAN_F1R1_FB21_Msk                    (0x1UL << CAN_F1R1_FB21_Pos)
#define CAN_F1R1_FB21                        CAN_F1R1_FB21_Msk
#define CAN_F1R1_FB22_Pos                    (22U)
#define CAN_F1R1_FB22_Msk                    (0x1UL << CAN_F1R1_FB22_Pos)
#define CAN_F1R1_FB22                        CAN_F1R1_FB22_Msk
#define CAN_F1R1_FB23_Pos                    (23U)
#define CAN_F1R1_FB23_Msk                    (0x1UL << CAN_F1R1_FB23_Pos)
#define CAN_F1R1_FB23                        CAN_F1R1_FB23_Msk
#define CAN_F1R1_FB24_Pos                    (24U)
#define CAN_F1R1_FB24_Msk                    (0x1UL << CAN_F1R1_FB24_Pos)
#define CAN_F1R1_FB24                        CAN_F1R1_FB24_Msk
#define CAN_F1R1_FB25_Pos                    (25U)
#define CAN_F1R1_FB25_Msk                    (0x1UL << CAN_F1R1_FB25_Pos)
#define CAN_F1R1_FB25                        CAN_F1R1_FB25_Msk
#define CAN_F1R1_FB26_Pos                    (26U)
#define CAN_F1R1_FB26_Msk                    (0x1UL << CAN_F1R1_FB26_Pos)
#define CAN_F1R1_FB26                        CAN_F1R1_FB26_Msk
#define CAN_F1R1_FB27_Pos                    (27U)
#define CAN_F1R1_FB27_Msk                    (0x1UL << CAN_F1R1_FB27_Pos)
#define CAN_F1R1_FB27                        CAN_F1R1_FB27_Msk
#define CAN_F1R1_FB28_Pos                    (28U)
#define CAN_F1R1_FB28_Msk                    (0x1UL << CAN_F1R1_FB28_Pos)
#define CAN_F1R1_FB28                        CAN_F1R1_FB28_Msk
#define CAN_F1R1_FB29_Pos                    (29U)
#define CAN_F1R1_FB29_Msk                    (0x1UL << CAN_F1R1_FB29_Pos)
#define CAN_F1R1_FB29                        CAN_F1R1_FB29_Msk
#define CAN_F1R1_FB30_Pos                    (30U)
#define CAN_F1R1_FB30_Msk                    (0x1UL << CAN_F1R1_FB30_Pos)
#define CAN_F1R1_FB30                        CAN_F1R1_FB30_Msk
#define CAN_F1R1_FB31_Pos                    (31U)
#define CAN_F1R1_FB31_Msk                    (0x1UL << CAN_F1R1_FB31_Pos)
#define CAN_F1R1_FB31                        CAN_F1R1_FB31_Msk

#define CAN_F2R1_FB0_Pos                     (0U)
#define CAN_F2R1_FB0_Msk                     (0x1UL << CAN_F2R1_FB0_Pos)
#define CAN_F2R1_FB0                         CAN_F2R1_FB0_Msk
#define CAN_F2R1_FB1_Pos                     (1U)
#define CAN_F2R1_FB1_Msk                     (0x1UL << CAN_F2R1_FB1_Pos)
#define CAN_F2R1_FB1                         CAN_F2R1_FB1_Msk
#define CAN_F2R1_FB2_Pos                     (2U)
#define CAN_F2R1_FB2_Msk                     (0x1UL << CAN_F2R1_FB2_Pos)
#define CAN_F2R1_FB2                         CAN_F2R1_FB2_Msk
#define CAN_F2R1_FB3_Pos                     (3U)
#define CAN_F2R1_FB3_Msk                     (0x1UL << CAN_F2R1_FB3_Pos)
#define CAN_F2R1_FB3                         CAN_F2R1_FB3_Msk
#define CAN_F2R1_FB4_Pos                     (4U)
#define CAN_F2R1_FB4_Msk                     (0x1UL << CAN_F2R1_FB4_Pos)
#define CAN_F2R1_FB4                         CAN_F2R1_FB4_Msk
#define CAN_F2R1_FB5_Pos                     (5U)
#define CAN_F2R1_FB5_Msk                     (0x1UL << CAN_F2R1_FB5_Pos)
#define CAN_F2R1_FB5                         CAN_F2R1_FB5_Msk
#define CAN_F2R1_FB6_Pos                     (6U)
#define CAN_F2R1_FB6_Msk                     (0x1UL << CAN_F2R1_FB6_Pos)
#define CAN_F2R1_FB6                         CAN_F2R1_FB6_Msk
#define CAN_F2R1_FB7_Pos                     (7U)
#define CAN_F2R1_FB7_Msk                     (0x1UL << CAN_F2R1_FB7_Pos)
#define CAN_F2R1_FB7                         CAN_F2R1_FB7_Msk
#define CAN_F2R1_FB8_Pos                     (8U)
#define CAN_F2R1_FB8_Msk                     (0x1UL << CAN_F2R1_FB8_Pos)
#define CAN_F2R1_FB8                         CAN_F2R1_FB8_Msk
#define CAN_F2R1_FB9_Pos                     (9U)
#define CAN_F2R1_FB9_Msk                     (0x1UL << CAN_F2R1_FB9_Pos)
#define CAN_F2R1_FB9                         CAN_F2R1_FB9_Msk
#define CAN_F2R1_FB10_Pos                    (10U)
#define CAN_F2R1_FB10_Msk                    (0x1UL << CAN_F2R1_FB10_Pos)
#define CAN_F2R1_FB10                        CAN_F2R1_FB10_Msk
#define CAN_F2R1_FB11_Pos                    (11U)
#define CAN_F2R1_FB11_Msk                    (0x1UL << CAN_F2R1_FB11_Pos)
#define CAN_F2R1_FB11                        CAN_F2R1_FB11_Msk
#define CAN_F2R1_FB12_Pos                    (12U)
#define CAN_F2R1_FB12_Msk                    (0x1UL << CAN_F2R1_FB12_Pos)
#define CAN_F2R1_FB12                        CAN_F2R1_FB12_Msk
#define CAN_F2R1_FB13_Pos                    (13U)
#define CAN_F2R1_FB13_Msk                    (0x1UL << CAN_F2R1_FB13_Pos)
#define CAN_F2R1_FB13                        CAN_F2R1_FB13_Msk
#define CAN_F2R1_FB14_Pos                    (14U)
#define CAN_F2R1_FB14_Msk                    (0x1UL << CAN_F2R1_FB14_Pos)
#define CAN_F2R1_FB14                        CAN_F2R1_FB14_Msk
#define CAN_F2R1_FB15_Pos                    (15U)
#define CAN_F2R1_FB15_Msk                    (0x1UL << CAN_F2R1_FB15_Pos)
#define CAN_F2R1_FB15                        CAN_F2R1_FB15_Msk
#define CAN_F2R1_FB16_Pos                    (16U)
#define CAN_F2R1_FB16_Msk                    (0x1UL << CAN_F2R1_FB16_Pos)
#define CAN_F2R1_FB16                        CAN_F2R1_FB16_Msk
#define CAN_F2R1_FB17_Pos                    (17U)
#define CAN_F2R1_FB17_Msk                    (0x1UL << CAN_F2R1_FB17_Pos)
#define CAN_F2R1_FB17                        CAN_F2R1_FB17_Msk
#define CAN_F2R1_FB18_Pos                    (18U)
#define CAN_F2R1_FB18_Msk                    (0x1UL << CAN_F2R1_FB18_Pos)
#define CAN_F2R1_FB18                        CAN_F2R1_FB18_Msk
#define CAN_F2R1_FB19_Pos                    (19U)
#define CAN_F2R1_FB19_Msk                    (0x1UL << CAN_F2R1_FB19_Pos)
#define CAN_F2R1_FB19                        CAN_F2R1_FB19_Msk
#define CAN_F2R1_FB20_Pos                    (20U)
#define CAN_F2R1_FB20_Msk                    (0x1UL << CAN_F2R1_FB20_Pos)
#define CAN_F2R1_FB20                        CAN_F2R1_FB20_Msk
#define CAN_F2R1_FB21_Pos                    (21U)
#define CAN_F2R1_FB21_Msk                    (0x1UL << CAN_F2R1_FB21_Pos)
#define CAN_F2R1_FB21                        CAN_F2R1_FB21_Msk
#define CAN_F2R1_FB22_Pos                    (22U)
#define CAN_F2R1_FB22_Msk                    (0x1UL << CAN_F2R1_FB22_Pos)
#define CAN_F2R1_FB22                        CAN_F2R1_FB22_Msk
#define CAN_F2R1_FB23_Pos                    (23U)
#define CAN_F2R1_FB23_Msk                    (0x1UL << CAN_F2R1_FB23_Pos)
#define CAN_F2R1_FB23                        CAN_F2R1_FB23_Msk
#define CAN_F2R1_FB24_Pos                    (24U)
#define CAN_F2R1_FB24_Msk                    (0x1UL << CAN_F2R1_FB24_Pos)
#define CAN_F2R1_FB24                        CAN_F2R1_FB24_Msk
#define CAN_F2R1_FB25_Pos                    (25U)
#define CAN_F2R1_FB25_Msk                    (0x1UL << CAN_F2R1_FB25_Pos)
#define CAN_F2R1_FB25                        CAN_F2R1_FB25_Msk
#define CAN_F2R1_FB26_Pos                    (26U)
#define CAN_F2R1_FB26_Msk                    (0x1UL << CAN_F2R1_FB26_Pos)
#define CAN_F2R1_FB26                        CAN_F2R1_FB26_Msk
#define CAN_F2R1_FB27_Pos                    (27U)
#define CAN_F2R1_FB27_Msk                    (0x1UL << CAN_F2R1_FB27_Pos)
#define CAN_F2R1_FB27                        CAN_F2R1_FB27_Msk
#define CAN_F2R1_FB28_Pos                    (28U)
#define CAN_F2R1_FB28_Msk                    (0x1UL << CAN_F2R1_FB28_Pos)
#define CAN_F2R1_FB28                        CAN_F2R1_FB28_Msk
#define CAN_F2R1_FB29_Pos                    (29U)
#define CAN_F2R1_FB29_Msk                    (0x1UL << CAN_F2R1_FB29_Pos)
#define CAN_F2R1_FB29                        CAN_F2R1_FB29_Msk
#define CAN_F2R1_FB30_Pos                    (30U)
#define CAN_F2R1_FB30_Msk                    (0x1UL << CAN_F2R1_FB30_Pos)
#define CAN_F2R1_FB30                        CAN_F2R1_FB30_Msk
#define CAN_F2R1_FB31_Pos                    (31U)
#define CAN_F2R1_FB31_Msk                    (0x1UL << CAN_F2R1_FB31_Pos)
#define CAN_F2R1_FB31                        CAN_F2R1_FB31_Msk

#define CAN_F3R1_FB0_Pos                     (0U)
#define CAN_F3R1_FB0_Msk                     (0x1UL << CAN_F3R1_FB0_Pos)
#define CAN_F3R1_FB0                         CAN_F3R1_FB0_Msk
#define CAN_F3R1_FB1_Pos                     (1U)
#define CAN_F3R1_FB1_Msk                     (0x1UL << CAN_F3R1_FB1_Pos)
#define CAN_F3R1_FB1                         CAN_F3R1_FB1_Msk
#define CAN_F3R1_FB2_Pos                     (2U)
#define CAN_F3R1_FB2_Msk                     (0x1UL << CAN_F3R1_FB2_Pos)
#define CAN_F3R1_FB2                         CAN_F3R1_FB2_Msk
#define CAN_F3R1_FB3_Pos                     (3U)
#define CAN_F3R1_FB3_Msk                     (0x1UL << CAN_F3R1_FB3_Pos)
#define CAN_F3R1_FB3                         CAN_F3R1_FB3_Msk
#define CAN_F3R1_FB4_Pos                     (4U)
#define CAN_F3R1_FB4_Msk                     (0x1UL << CAN_F3R1_FB4_Pos)
#define CAN_F3R1_FB4                         CAN_F3R1_FB4_Msk
#define CAN_F3R1_FB5_Pos                     (5U)
#define CAN_F3R1_FB5_Msk                     (0x1UL << CAN_F3R1_FB5_Pos)
#define CAN_F3R1_FB5                         CAN_F3R1_FB5_Msk
#define CAN_F3R1_FB6_Pos                     (6U)
#define CAN_F3R1_FB6_Msk                     (0x1UL << CAN_F3R1_FB6_Pos)
#define CAN_F3R1_FB6                         CAN_F3R1_FB6_Msk
#define CAN_F3R1_FB7_Pos                     (7U)
#define CAN_F3R1_FB7_Msk                     (0x1UL << CAN_F3R1_FB7_Pos)
#define CAN_F3R1_FB7                         CAN_F3R1_FB7_Msk
#define CAN_F3R1_FB8_Pos                     (8U)
#define CAN_F3R1_FB8_Msk                     (0x1UL << CAN_F3R1_FB8_Pos)
#define CAN_F3R1_FB8                         CAN_F3R1_FB8_Msk
#define CAN_F3R1_FB9_Pos                     (9U)
#define CAN_F3R1_FB9_Msk                     (0x1UL << CAN_F3R1_FB9_Pos)
#define CAN_F3R1_FB9                         CAN_F3R1_FB9_Msk
#define CAN_F3R1_FB10_Pos                    (10U)
#define CAN_F3R1_FB10_Msk                    (0x1UL << CAN_F3R1_FB10_Pos)
#define CAN_F3R1_FB10                        CAN_F3R1_FB10_Msk
#define CAN_F3R1_FB11_Pos                    (11U)
#define CAN_F3R1_FB11_Msk                    (0x1UL << CAN_F3R1_FB11_Pos)
#define CAN_F3R1_FB11                        CAN_F3R1_FB11_Msk
#define CAN_F3R1_FB12_Pos                    (12U)
#define CAN_F3R1_FB12_Msk                    (0x1UL << CAN_F3R1_FB12_Pos)
#define CAN_F3R1_FB12                        CAN_F3R1_FB12_Msk
#define CAN_F3R1_FB13_Pos                    (13U)
#define CAN_F3R1_FB13_Msk                    (0x1UL << CAN_F3R1_FB13_Pos)
#define CAN_F3R1_FB13                        CAN_F3R1_FB13_Msk
#define CAN_F3R1_FB14_Pos                    (14U)
#define CAN_F3R1_FB14_Msk                    (0x1UL << CAN_F3R1_FB14_Pos)
#define CAN_F3R1_FB14                        CAN_F3R1_FB14_Msk
#define CAN_F3R1_FB15_Pos                    (15U)
#define CAN_F3R1_FB15_Msk                    (0x1UL << CAN_F3R1_FB15_Pos)
#define CAN_F3R1_FB15                        CAN_F3R1_FB15_Msk
#define CAN_F3R1_FB16_Pos                    (16U)
#define CAN_F3R1_FB16_Msk                    (0x1UL << CAN_F3R1_FB16_Pos)
#define CAN_F3R1_FB16                        CAN_F3R1_FB16_Msk
#define CAN_F3R1_FB17_Pos                    (17U)
#define CAN_F3R1_FB17_Msk                    (0x1UL << CAN_F3R1_FB17_Pos)
#define CAN_F3R1_FB17                        CAN_F3R1_FB17_Msk
#define CAN_F3R1_FB18_Pos                    (18U)
#define CAN_F3R1_FB18_Msk                    (0x1UL << CAN_F3R1_FB18_Pos)
#define CAN_F3R1_FB18                        CAN_F3R1_FB18_Msk
#define CAN_F3R1_FB19_Pos                    (19U)
#define CAN_F3R1_FB19_Msk                    (0x1UL << CAN_F3R1_FB19_Pos)
#define CAN_F3R1_FB19                        CAN_F3R1_FB19_Msk
#define CAN_F3R1_FB20_Pos                    (20U)
#define CAN_F3R1_FB20_Msk                    (0x1UL << CAN_F3R1_FB20_Pos)
#define CAN_F3R1_FB20                        CAN_F3R1_FB20_Msk
#define CAN_F3R1_FB21_Pos                    (21U)
#define CAN_F3R1_FB21_Msk                    (0x1UL << CAN_F3R1_FB21_Pos)
#define CAN_F3R1_FB21                        CAN_F3R1_FB21_Msk
#define CAN_F3R1_FB22_Pos                    (22U)
#define CAN_F3R1_FB22_Msk                    (0x1UL << CAN_F3R1_FB22_Pos)
#define CAN_F3R1_FB22                        CAN_F3R1_FB22_Msk
#define CAN_F3R1_FB23_Pos                    (23U)
#define CAN_F3R1_FB23_Msk                    (0x1UL << CAN_F3R1_FB23_Pos)
#define CAN_F3R1_FB23                        CAN_F3R1_FB23_Msk
#define CAN_F3R1_FB24_Pos                    (24U)
#define CAN_F3R1_FB24_Msk                    (0x1UL << CAN_F3R1_FB24_Pos)
#define CAN_F3R1_FB24                        CAN_F3R1_FB24_Msk
#define CAN_F3R1_FB25_Pos                    (25U)
#define CAN_F3R1_FB25_Msk                    (0x1UL << CAN_F3R1_FB25_Pos)
#define CAN_F3R1_FB25                        CAN_F3R1_FB25_Msk
#define CAN_F3R1_FB26_Pos                    (26U)
#define CAN_F3R1_FB26_Msk                    (0x1UL << CAN_F3R1_FB26_Pos)
#define CAN_F3R1_FB26                        CAN_F3R1_FB26_Msk
#define CAN_F3R1_FB27_Pos                    (27U)
#define CAN_F3R1_FB27_Msk                    (0x1UL << CAN_F3R1_FB27_Pos)
#define CAN_F3R1_FB27                        CAN_F3R1_FB27_Msk
#define CAN_F3R1_FB28_Pos                    (28U)
#define CAN_F3R1_FB28_Msk                    (0x1UL << CAN_F3R1_FB28_Pos)
#define CAN_F3R1_FB28                        CAN_F3R1_FB28_Msk
#define CAN_F3R1_FB29_Pos                    (29U)
#define CAN_F3R1_FB29_Msk                    (0x1UL << CAN_F3R1_FB29_Pos)
#define CAN_F3R1_FB29                        CAN_F3R1_FB29_Msk
#define CAN_F3R1_FB30_Pos                    (30U)
#define CAN_F3R1_FB30_Msk                    (0x1UL << CAN_F3R1_FB30_Pos)
#define CAN_F3R1_FB30                        CAN_F3R1_FB30_Msk
#define CAN_F3R1_FB31_Pos                    (31U)
#define CAN_F3R1_FB31_Msk                    (0x1UL << CAN_F3R1_FB31_Pos)
#define CAN_F3R1_FB31                        CAN_F3R1_FB31_Msk

#define CAN_F4R1_FB0_Pos                     (0U)
#define CAN_F4R1_FB0_Msk                     (0x1UL << CAN_F4R1_FB0_Pos)
#define CAN_F4R1_FB0                         CAN_F4R1_FB0_Msk
#define CAN_F4R1_FB1_Pos                     (1U)
#define CAN_F4R1_FB1_Msk                     (0x1UL << CAN_F4R1_FB1_Pos)
#define CAN_F4R1_FB1                         CAN_F4R1_FB1_Msk
#define CAN_F4R1_FB2_Pos                     (2U)
#define CAN_F4R1_FB2_Msk                     (0x1UL << CAN_F4R1_FB2_Pos)
#define CAN_F4R1_FB2                         CAN_F4R1_FB2_Msk
#define CAN_F4R1_FB3_Pos                     (3U)
#define CAN_F4R1_FB3_Msk                     (0x1UL << CAN_F4R1_FB3_Pos)
#define CAN_F4R1_FB3                         CAN_F4R1_FB3_Msk
#define CAN_F4R1_FB4_Pos                     (4U)
#define CAN_F4R1_FB4_Msk                     (0x1UL << CAN_F4R1_FB4_Pos)
#define CAN_F4R1_FB4                         CAN_F4R1_FB4_Msk
#define CAN_F4R1_FB5_Pos                     (5U)
#define CAN_F4R1_FB5_Msk                     (0x1UL << CAN_F4R1_FB5_Pos)
#define CAN_F4R1_FB5                         CAN_F4R1_FB5_Msk
#define CAN_F4R1_FB6_Pos                     (6U)
#define CAN_F4R1_FB6_Msk                     (0x1UL << CAN_F4R1_FB6_Pos)
#define CAN_F4R1_FB6                         CAN_F4R1_FB6_Msk
#define CAN_F4R1_FB7_Pos                     (7U)
#define CAN_F4R1_FB7_Msk                     (0x1UL << CAN_F4R1_FB7_Pos)
#define CAN_F4R1_FB7                         CAN_F4R1_FB7_Msk
#define CAN_F4R1_FB8_Pos                     (8U)
#define CAN_F4R1_FB8_Msk                     (0x1UL << CAN_F4R1_FB8_Pos)
#define CAN_F4R1_FB8                         CAN_F4R1_FB8_Msk
#define CAN_F4R1_FB9_Pos                     (9U)
#define CAN_F4R1_FB9_Msk                     (0x1UL << CAN_F4R1_FB9_Pos)
#define CAN_F4R1_FB9                         CAN_F4R1_FB9_Msk
#define CAN_F4R1_FB10_Pos                    (10U)
#define CAN_F4R1_FB10_Msk                    (0x1UL << CAN_F4R1_FB10_Pos)
#define CAN_F4R1_FB10                        CAN_F4R1_FB10_Msk
#define CAN_F4R1_FB11_Pos                    (11U)
#define CAN_F4R1_FB11_Msk                    (0x1UL << CAN_F4R1_FB11_Pos)
#define CAN_F4R1_FB11                        CAN_F4R1_FB11_Msk
#define CAN_F4R1_FB12_Pos                    (12U)
#define CAN_F4R1_FB12_Msk                    (0x1UL << CAN_F4R1_FB12_Pos)
#define CAN_F4R1_FB12                        CAN_F4R1_FB12_Msk
#define CAN_F4R1_FB13_Pos                    (13U)
#define CAN_F4R1_FB13_Msk                    (0x1UL << CAN_F4R1_FB13_Pos)
#define CAN_F4R1_FB13                        CAN_F4R1_FB13_Msk
#define CAN_F4R1_FB14_Pos                    (14U)
#define CAN_F4R1_FB14_Msk                    (0x1UL << CAN_F4R1_FB14_Pos)
#define CAN_F4R1_FB14                        CAN_F4R1_FB14_Msk
#define CAN_F4R1_FB15_Pos                    (15U)
#define CAN_F4R1_FB15_Msk                    (0x1UL << CAN_F4R1_FB15_Pos)
#define CAN_F4R1_FB15                        CAN_F4R1_FB15_Msk
#define CAN_F4R1_FB16_Pos                    (16U)
#define CAN_F4R1_FB16_Msk                    (0x1UL << CAN_F4R1_FB16_Pos)
#define CAN_F4R1_FB16                        CAN_F4R1_FB16_Msk
#define CAN_F4R1_FB17_Pos                    (17U)
#define CAN_F4R1_FB17_Msk                    (0x1UL << CAN_F4R1_FB17_Pos)
#define CAN_F4R1_FB17                        CAN_F4R1_FB17_Msk
#define CAN_F4R1_FB18_Pos                    (18U)
#define CAN_F4R1_FB18_Msk                    (0x1UL << CAN_F4R1_FB18_Pos)
#define CAN_F4R1_FB18                        CAN_F4R1_FB18_Msk
#define CAN_F4R1_FB19_Pos                    (19U)
#define CAN_F4R1_FB19_Msk                    (0x1UL << CAN_F4R1_FB19_Pos)
#define CAN_F4R1_FB19                        CAN_F4R1_FB19_Msk
#define CAN_F4R1_FB20_Pos                    (20U)
#define CAN_F4R1_FB20_Msk                    (0x1UL << CAN_F4R1_FB20_Pos)
#define CAN_F4R1_FB20                        CAN_F4R1_FB20_Msk
#define CAN_F4R1_FB21_Pos                    (21U)
#define CAN_F4R1_FB21_Msk                    (0x1UL << CAN_F4R1_FB21_Pos)
#define CAN_F4R1_FB21                        CAN_F4R1_FB21_Msk
#define CAN_F4R1_FB22_Pos                    (22U)
#define CAN_F4R1_FB22_Msk                    (0x1UL << CAN_F4R1_FB22_Pos)
#define CAN_F4R1_FB22                        CAN_F4R1_FB22_Msk
#define CAN_F4R1_FB23_Pos                    (23U)
#define CAN_F4R1_FB23_Msk                    (0x1UL << CAN_F4R1_FB23_Pos)
#define CAN_F4R1_FB23                        CAN_F4R1_FB23_Msk
#define CAN_F4R1_FB24_Pos                    (24U)
#define CAN_F4R1_FB24_Msk                    (0x1UL << CAN_F4R1_FB24_Pos)
#define CAN_F4R1_FB24                        CAN_F4R1_FB24_Msk
#define CAN_F4R1_FB25_Pos                    (25U)
#define CAN_F4R1_FB25_Msk                    (0x1UL << CAN_F4R1_FB25_Pos)
#define CAN_F4R1_FB25                        CAN_F4R1_FB25_Msk
#define CAN_F4R1_FB26_Pos                    (26U)
#define CAN_F4R1_FB26_Msk                    (0x1UL << CAN_F4R1_FB26_Pos)
#define CAN_F4R1_FB26                        CAN_F4R1_FB26_Msk
#define CAN_F4R1_FB27_Pos                    (27U)
#define CAN_F4R1_FB27_Msk                    (0x1UL << CAN_F4R1_FB27_Pos)
#define CAN_F4R1_FB27                        CAN_F4R1_FB27_Msk
#define CAN_F4R1_FB28_Pos                    (28U)
#define CAN_F4R1_FB28_Msk                    (0x1UL << CAN_F4R1_FB28_Pos)
#define CAN_F4R1_FB28                        CAN_F4R1_FB28_Msk
#define CAN_F4R1_FB29_Pos                    (29U)
#define CAN_F4R1_FB29_Msk                    (0x1UL << CAN_F4R1_FB29_Pos)
#define CAN_F4R1_FB29                        CAN_F4R1_FB29_Msk
#define CAN_F4R1_FB30_Pos                    (30U)
#define CAN_F4R1_FB30_Msk                    (0x1UL << CAN_F4R1_FB30_Pos)
#define CAN_F4R1_FB30                        CAN_F4R1_FB30_Msk
#define CAN_F4R1_FB31_Pos                    (31U)
#define CAN_F4R1_FB31_Msk                    (0x1UL << CAN_F4R1_FB31_Pos)
#define CAN_F4R1_FB31                        CAN_F4R1_FB31_Msk

#define CAN_F5R1_FB0_Pos                     (0U)
#define CAN_F5R1_FB0_Msk                     (0x1UL << CAN_F5R1_FB0_Pos)
#define CAN_F5R1_FB0                         CAN_F5R1_FB0_Msk
#define CAN_F5R1_FB1_Pos                     (1U)
#define CAN_F5R1_FB1_Msk                     (0x1UL << CAN_F5R1_FB1_Pos)
#define CAN_F5R1_FB1                         CAN_F5R1_FB1_Msk
#define CAN_F5R1_FB2_Pos                     (2U)
#define CAN_F5R1_FB2_Msk                     (0x1UL << CAN_F5R1_FB2_Pos)
#define CAN_F5R1_FB2                         CAN_F5R1_FB2_Msk
#define CAN_F5R1_FB3_Pos                     (3U)
#define CAN_F5R1_FB3_Msk                     (0x1UL << CAN_F5R1_FB3_Pos)
#define CAN_F5R1_FB3                         CAN_F5R1_FB3_Msk
#define CAN_F5R1_FB4_Pos                     (4U)
#define CAN_F5R1_FB4_Msk                     (0x1UL << CAN_F5R1_FB4_Pos)
#define CAN_F5R1_FB4                         CAN_F5R1_FB4_Msk
#define CAN_F5R1_FB5_Pos                     (5U)
#define CAN_F5R1_FB5_Msk                     (0x1UL << CAN_F5R1_FB5_Pos)
#define CAN_F5R1_FB5                         CAN_F5R1_FB5_Msk
#define CAN_F5R1_FB6_Pos                     (6U)
#define CAN_F5R1_FB6_Msk                     (0x1UL << CAN_F5R1_FB6_Pos)
#define CAN_F5R1_FB6                         CAN_F5R1_FB6_Msk
#define CAN_F5R1_FB7_Pos                     (7U)
#define CAN_F5R1_FB7_Msk                     (0x1UL << CAN_F5R1_FB7_Pos)
#define CAN_F5R1_FB7                         CAN_F5R1_FB7_Msk
#define CAN_F5R1_FB8_Pos                     (8U)
#define CAN_F5R1_FB8_Msk                     (0x1UL << CAN_F5R1_FB8_Pos)
#define CAN_F5R1_FB8                         CAN_F5R1_FB8_Msk
#define CAN_F5R1_FB9_Pos                     (9U)
#define CAN_F5R1_FB9_Msk                     (0x1UL << CAN_F5R1_FB9_Pos)
#define CAN_F5R1_FB9                         CAN_F5R1_FB9_Msk
#define CAN_F5R1_FB10_Pos                    (10U)
#define CAN_F5R1_FB10_Msk                    (0x1UL << CAN_F5R1_FB10_Pos)
#define CAN_F5R1_FB10                        CAN_F5R1_FB10_Msk
#define CAN_F5R1_FB11_Pos                    (11U)
#define CAN_F5R1_FB11_Msk                    (0x1UL << CAN_F5R1_FB11_Pos)
#define CAN_F5R1_FB11                        CAN_F5R1_FB11_Msk
#define CAN_F5R1_FB12_Pos                    (12U)
#define CAN_F5R1_FB12_Msk                    (0x1UL << CAN_F5R1_FB12_Pos)
#define CAN_F5R1_FB12                        CAN_F5R1_FB12_Msk
#define CAN_F5R1_FB13_Pos                    (13U)
#define CAN_F5R1_FB13_Msk                    (0x1UL << CAN_F5R1_FB13_Pos)
#define CAN_F5R1_FB13                        CAN_F5R1_FB13_Msk
#define CAN_F5R1_FB14_Pos                    (14U)
#define CAN_F5R1_FB14_Msk                    (0x1UL << CAN_F5R1_FB14_Pos)
#define CAN_F5R1_FB14                        CAN_F5R1_FB14_Msk
#define CAN_F5R1_FB15_Pos                    (15U)
#define CAN_F5R1_FB15_Msk                    (0x1UL << CAN_F5R1_FB15_Pos)
#define CAN_F5R1_FB15                        CAN_F5R1_FB15_Msk
#define CAN_F5R1_FB16_Pos                    (16U)
#define CAN_F5R1_FB16_Msk                    (0x1UL << CAN_F5R1_FB16_Pos)
#define CAN_F5R1_FB16                        CAN_F5R1_FB16_Msk
#define CAN_F5R1_FB17_Pos                    (17U)
#define CAN_F5R1_FB17_Msk                    (0x1UL << CAN_F5R1_FB17_Pos)
#define CAN_F5R1_FB17                        CAN_F5R1_FB17_Msk
#define CAN_F5R1_FB18_Pos                    (18U)
#define CAN_F5R1_FB18_Msk                    (0x1UL << CAN_F5R1_FB18_Pos)
#define CAN_F5R1_FB18                        CAN_F5R1_FB18_Msk
#define CAN_F5R1_FB19_Pos                    (19U)
#define CAN_F5R1_FB19_Msk                    (0x1UL << CAN_F5R1_FB19_Pos)
#define CAN_F5R1_FB19                        CAN_F5R1_FB19_Msk
#define CAN_F5R1_FB20_Pos                    (20U)
#define CAN_F5R1_FB20_Msk                    (0x1UL << CAN_F5R1_FB20_Pos)
#define CAN_F5R1_FB20                        CAN_F5R1_FB20_Msk
#define CAN_F5R1_FB21_Pos                    (21U)
#define CAN_F5R1_FB21_Msk                    (0x1UL << CAN_F5R1_FB21_Pos)
#define CAN_F5R1_FB21                        CAN_F5R1_FB21_Msk
#define CAN_F5R1_FB22_Pos                    (22U)
#define CAN_F5R1_FB22_Msk                    (0x1UL << CAN_F5R1_FB22_Pos)
#define CAN_F5R1_FB22                        CAN_F5R1_FB22_Msk
#define CAN_F5R1_FB23_Pos                    (23U)
#define CAN_F5R1_FB23_Msk                    (0x1UL << CAN_F5R1_FB23_Pos)
#define CAN_F5R1_FB23                        CAN_F5R1_FB23_Msk
#define CAN_F5R1_FB24_Pos                    (24U)
#define CAN_F5R1_FB24_Msk                    (0x1UL << CAN_F5R1_FB24_Pos)
#define CAN_F5R1_FB24                        CAN_F5R1_FB24_Msk
#define CAN_F5R1_FB25_Pos                    (25U)
#define CAN_F5R1_FB25_Msk                    (0x1UL << CAN_F5R1_FB25_Pos)
#define CAN_F5R1_FB25                        CAN_F5R1_FB25_Msk
#define CAN_F5R1_FB26_Pos                    (26U)
#define CAN_F5R1_FB26_Msk                    (0x1UL << CAN_F5R1_FB26_Pos)
#define CAN_F5R1_FB26                        CAN_F5R1_FB26_Msk
#define CAN_F5R1_FB27_Pos                    (27U)
#define CAN_F5R1_FB27_Msk                    (0x1UL << CAN_F5R1_FB27_Pos)
#define CAN_F5R1_FB27                        CAN_F5R1_FB27_Msk
#define CAN_F5R1_FB28_Pos                    (28U)
#define CAN_F5R1_FB28_Msk                    (0x1UL << CAN_F5R1_FB28_Pos)
#define CAN_F5R1_FB28                        CAN_F5R1_FB28_Msk
#define CAN_F5R1_FB29_Pos                    (29U)
#define CAN_F5R1_FB29_Msk                    (0x1UL << CAN_F5R1_FB29_Pos)
#define CAN_F5R1_FB29                        CAN_F5R1_FB29_Msk
#define CAN_F5R1_FB30_Pos                    (30U)
#define CAN_F5R1_FB30_Msk                    (0x1UL << CAN_F5R1_FB30_Pos)
#define CAN_F5R1_FB30                        CAN_F5R1_FB30_Msk
#define CAN_F5R1_FB31_Pos                    (31U)
#define CAN_F5R1_FB31_Msk                    (0x1UL << CAN_F5R1_FB31_Pos)
#define CAN_F5R1_FB31                        CAN_F5R1_FB31_Msk

#define CAN_F6R1_FB0_Pos                     (0U)
#define CAN_F6R1_FB0_Msk                     (0x1UL << CAN_F6R1_FB0_Pos)
#define CAN_F6R1_FB0                         CAN_F6R1_FB0_Msk
#define CAN_F6R1_FB1_Pos                     (1U)
#define CAN_F6R1_FB1_Msk                     (0x1UL << CAN_F6R1_FB1_Pos)
#define CAN_F6R1_FB1                         CAN_F6R1_FB1_Msk
#define CAN_F6R1_FB2_Pos                     (2U)
#define CAN_F6R1_FB2_Msk                     (0x1UL << CAN_F6R1_FB2_Pos)
#define CAN_F6R1_FB2                         CAN_F6R1_FB2_Msk
#define CAN_F6R1_FB3_Pos                     (3U)
#define CAN_F6R1_FB3_Msk                     (0x1UL << CAN_F6R1_FB3_Pos)
#define CAN_F6R1_FB3                         CAN_F6R1_FB3_Msk
#define CAN_F6R1_FB4_Pos                     (4U)
#define CAN_F6R1_FB4_Msk                     (0x1UL << CAN_F6R1_FB4_Pos)
#define CAN_F6R1_FB4                         CAN_F6R1_FB4_Msk
#define CAN_F6R1_FB5_Pos                     (5U)
#define CAN_F6R1_FB5_Msk                     (0x1UL << CAN_F6R1_FB5_Pos)
#define CAN_F6R1_FB5                         CAN_F6R1_FB5_Msk
#define CAN_F6R1_FB6_Pos                     (6U)
#define CAN_F6R1_FB6_Msk                     (0x1UL << CAN_F6R1_FB6_Pos)
#define CAN_F6R1_FB6                         CAN_F6R1_FB6_Msk
#define CAN_F6R1_FB7_Pos                     (7U)
#define CAN_F6R1_FB7_Msk                     (0x1UL << CAN_F6R1_FB7_Pos)
#define CAN_F6R1_FB7                         CAN_F6R1_FB7_Msk
#define CAN_F6R1_FB8_Pos                     (8U)
#define CAN_F6R1_FB8_Msk                     (0x1UL << CAN_F6R1_FB8_Pos)
#define CAN_F6R1_FB8                         CAN_F6R1_FB8_Msk
#define CAN_F6R1_FB9_Pos                     (9U)
#define CAN_F6R1_FB9_Msk                     (0x1UL << CAN_F6R1_FB9_Pos)
#define CAN_F6R1_FB9                         CAN_F6R1_FB9_Msk
#define CAN_F6R1_FB10_Pos                    (10U)
#define CAN_F6R1_FB10_Msk                    (0x1UL << CAN_F6R1_FB10_Pos)
#define CAN_F6R1_FB10                        CAN_F6R1_FB10_Msk
#define CAN_F6R1_FB11_Pos                    (11U)
#define CAN_F6R1_FB11_Msk                    (0x1UL << CAN_F6R1_FB11_Pos)
#define CAN_F6R1_FB11                        CAN_F6R1_FB11_Msk
#define CAN_F6R1_FB12_Pos                    (12U)
#define CAN_F6R1_FB12_Msk                    (0x1UL << CAN_F6R1_FB12_Pos)
#define CAN_F6R1_FB12                        CAN_F6R1_FB12_Msk
#define CAN_F6R1_FB13_Pos                    (13U)
#define CAN_F6R1_FB13_Msk                    (0x1UL << CAN_F6R1_FB13_Pos)
#define CAN_F6R1_FB13                        CAN_F6R1_FB13_Msk
#define CAN_F6R1_FB14_Pos                    (14U)
#define CAN_F6R1_FB14_Msk                    (0x1UL << CAN_F6R1_FB14_Pos)
#define CAN_F6R1_FB14                        CAN_F6R1_FB14_Msk
#define CAN_F6R1_FB15_Pos                    (15U)
#define CAN_F6R1_FB15_Msk                    (0x1UL << CAN_F6R1_FB15_Pos)
#define CAN_F6R1_FB15                        CAN_F6R1_FB15_Msk
#define CAN_F6R1_FB16_Pos                    (16U)
#define CAN_F6R1_FB16_Msk                    (0x1UL << CAN_F6R1_FB16_Pos)
#define CAN_F6R1_FB16                        CAN_F6R1_FB16_Msk
#define CAN_F6R1_FB17_Pos                    (17U)
#define CAN_F6R1_FB17_Msk                    (0x1UL << CAN_F6R1_FB17_Pos)
#define CAN_F6R1_FB17                        CAN_F6R1_FB17_Msk
#define CAN_F6R1_FB18_Pos                    (18U)
#define CAN_F6R1_FB18_Msk                    (0x1UL << CAN_F6R1_FB18_Pos)
#define CAN_F6R1_FB18                        CAN_F6R1_FB18_Msk
#define CAN_F6R1_FB19_Pos                    (19U)
#define CAN_F6R1_FB19_Msk                    (0x1UL << CAN_F6R1_FB19_Pos)
#define CAN_F6R1_FB19                        CAN_F6R1_FB19_Msk
#define CAN_F6R1_FB20_Pos                    (20U)
#define CAN_F6R1_FB20_Msk                    (0x1UL << CAN_F6R1_FB20_Pos)
#define CAN_F6R1_FB20                        CAN_F6R1_FB20_Msk
#define CAN_F6R1_FB21_Pos                    (21U)
#define CAN_F6R1_FB21_Msk                    (0x1UL << CAN_F6R1_FB21_Pos)
#define CAN_F6R1_FB21                        CAN_F6R1_FB21_Msk
#define CAN_F6R1_FB22_Pos                    (22U)
#define CAN_F6R1_FB22_Msk                    (0x1UL << CAN_F6R1_FB22_Pos)
#define CAN_F6R1_FB22                        CAN_F6R1_FB22_Msk
#define CAN_F6R1_FB23_Pos                    (23U)
#define CAN_F6R1_FB23_Msk                    (0x1UL << CAN_F6R1_FB23_Pos)
#define CAN_F6R1_FB23                        CAN_F6R1_FB23_Msk
#define CAN_F6R1_FB24_Pos                    (24U)
#define CAN_F6R1_FB24_Msk                    (0x1UL << CAN_F6R1_FB24_Pos)
#define CAN_F6R1_FB24                        CAN_F6R1_FB24_Msk
#define CAN_F6R1_FB25_Pos                    (25U)
#define CAN_F6R1_FB25_Msk                    (0x1UL << CAN_F6R1_FB25_Pos)
#define CAN_F6R1_FB25                        CAN_F6R1_FB25_Msk
#define CAN_F6R1_FB26_Pos                    (26U)
#define CAN_F6R1_FB26_Msk                    (0x1UL << CAN_F6R1_FB26_Pos)
#define CAN_F6R1_FB26                        CAN_F6R1_FB26_Msk
#define CAN_F6R1_FB27_Pos                    (27U)
#define CAN_F6R1_FB27_Msk                    (0x1UL << CAN_F6R1_FB27_Pos)
#define CAN_F6R1_FB27                        CAN_F6R1_FB27_Msk
#define CAN_F6R1_FB28_Pos                    (28U)
#define CAN_F6R1_FB28_Msk                    (0x1UL << CAN_F6R1_FB28_Pos)
#define CAN_F6R1_FB28                        CAN_F6R1_FB28_Msk
#define CAN_F6R1_FB29_Pos                    (29U)
#define CAN_F6R1_FB29_Msk                    (0x1UL << CAN_F6R1_FB29_Pos)
#define CAN_F6R1_FB29                        CAN_F6R1_FB29_Msk
#define CAN_F6R1_FB30_Pos                    (30U)
#define CAN_F6R1_FB30_Msk                    (0x1UL << CAN_F6R1_FB30_Pos)
#define CAN_F6R1_FB30                        CAN_F6R1_FB30_Msk
#define CAN_F6R1_FB31_Pos                    (31U)
#define CAN_F6R1_FB31_Msk                    (0x1UL << CAN_F6R1_FB31_Pos)
#define CAN_F6R1_FB31                        CAN_F6R1_FB31_Msk

#define CAN_F7R1_FB0_Pos                     (0U)
#define CAN_F7R1_FB0_Msk                     (0x1UL << CAN_F7R1_FB0_Pos)
#define CAN_F7R1_FB0                         CAN_F7R1_FB0_Msk
#define CAN_F7R1_FB1_Pos                     (1U)
#define CAN_F7R1_FB1_Msk                     (0x1UL << CAN_F7R1_FB1_Pos)
#define CAN_F7R1_FB1                         CAN_F7R1_FB1_Msk
#define CAN_F7R1_FB2_Pos                     (2U)
#define CAN_F7R1_FB2_Msk                     (0x1UL << CAN_F7R1_FB2_Pos)
#define CAN_F7R1_FB2                         CAN_F7R1_FB2_Msk
#define CAN_F7R1_FB3_Pos                     (3U)
#define CAN_F7R1_FB3_Msk                     (0x1UL << CAN_F7R1_FB3_Pos)
#define CAN_F7R1_FB3                         CAN_F7R1_FB3_Msk
#define CAN_F7R1_FB4_Pos                     (4U)
#define CAN_F7R1_FB4_Msk                     (0x1UL << CAN_F7R1_FB4_Pos)
#define CAN_F7R1_FB4                         CAN_F7R1_FB4_Msk
#define CAN_F7R1_FB5_Pos                     (5U)
#define CAN_F7R1_FB5_Msk                     (0x1UL << CAN_F7R1_FB5_Pos)
#define CAN_F7R1_FB5                         CAN_F7R1_FB5_Msk
#define CAN_F7R1_FB6_Pos                     (6U)
#define CAN_F7R1_FB6_Msk                     (0x1UL << CAN_F7R1_FB6_Pos)
#define CAN_F7R1_FB6                         CAN_F7R1_FB6_Msk
#define CAN_F7R1_FB7_Pos                     (7U)
#define CAN_F7R1_FB7_Msk                     (0x1UL << CAN_F7R1_FB7_Pos)
#define CAN_F7R1_FB7                         CAN_F7R1_FB7_Msk
#define CAN_F7R1_FB8_Pos                     (8U)
#define CAN_F7R1_FB8_Msk                     (0x1UL << CAN_F7R1_FB8_Pos)
#define CAN_F7R1_FB8                         CAN_F7R1_FB8_Msk
#define CAN_F7R1_FB9_Pos                     (9U)
#define CAN_F7R1_FB9_Msk                     (0x1UL << CAN_F7R1_FB9_Pos)
#define CAN_F7R1_FB9                         CAN_F7R1_FB9_Msk
#define CAN_F7R1_FB10_Pos                    (10U)
#define CAN_F7R1_FB10_Msk                    (0x1UL << CAN_F7R1_FB10_Pos)
#define CAN_F7R1_FB10                        CAN_F7R1_FB10_Msk
#define CAN_F7R1_FB11_Pos                    (11U)
#define CAN_F7R1_FB11_Msk                    (0x1UL << CAN_F7R1_FB11_Pos)
#define CAN_F7R1_FB11                        CAN_F7R1_FB11_Msk
#define CAN_F7R1_FB12_Pos                    (12U)
#define CAN_F7R1_FB12_Msk                    (0x1UL << CAN_F7R1_FB12_Pos)
#define CAN_F7R1_FB12                        CAN_F7R1_FB12_Msk
#define CAN_F7R1_FB13_Pos                    (13U)
#define CAN_F7R1_FB13_Msk                    (0x1UL << CAN_F7R1_FB13_Pos)
#define CAN_F7R1_FB13                        CAN_F7R1_FB13_Msk
#define CAN_F7R1_FB14_Pos                    (14U)
#define CAN_F7R1_FB14_Msk                    (0x1UL << CAN_F7R1_FB14_Pos)
#define CAN_F7R1_FB14                        CAN_F7R1_FB14_Msk
#define CAN_F7R1_FB15_Pos                    (15U)
#define CAN_F7R1_FB15_Msk                    (0x1UL << CAN_F7R1_FB15_Pos)
#define CAN_F7R1_FB15                        CAN_F7R1_FB15_Msk
#define CAN_F7R1_FB16_Pos                    (16U)
#define CAN_F7R1_FB16_Msk                    (0x1UL << CAN_F7R1_FB16_Pos)
#define CAN_F7R1_FB16                        CAN_F7R1_FB16_Msk
#define CAN_F7R1_FB17_Pos                    (17U)
#define CAN_F7R1_FB17_Msk                    (0x1UL << CAN_F7R1_FB17_Pos)
#define CAN_F7R1_FB17                        CAN_F7R1_FB17_Msk
#define CAN_F7R1_FB18_Pos                    (18U)
#define CAN_F7R1_FB18_Msk                    (0x1UL << CAN_F7R1_FB18_Pos)
#define CAN_F7R1_FB18                        CAN_F7R1_FB18_Msk
#define CAN_F7R1_FB19_Pos                    (19U)
#define CAN_F7R1_FB19_Msk                    (0x1UL << CAN_F7R1_FB19_Pos)
#define CAN_F7R1_FB19                        CAN_F7R1_FB19_Msk
#define CAN_F7R1_FB20_Pos                    (20U)
#define CAN_F7R1_FB20_Msk                    (0x1UL << CAN_F7R1_FB20_Pos)
#define CAN_F7R1_FB20                        CAN_F7R1_FB20_Msk
#define CAN_F7R1_FB21_Pos                    (21U)
#define CAN_F7R1_FB21_Msk                    (0x1UL << CAN_F7R1_FB21_Pos)
#define CAN_F7R1_FB21                        CAN_F7R1_FB21_Msk
#define CAN_F7R1_FB22_Pos                    (22U)
#define CAN_F7R1_FB22_Msk                    (0x1UL << CAN_F7R1_FB22_Pos)
#define CAN_F7R1_FB22                        CAN_F7R1_FB22_Msk
#define CAN_F7R1_FB23_Pos                    (23U)
#define CAN_F7R1_FB23_Msk                    (0x1UL << CAN_F7R1_FB23_Pos)
#define CAN_F7R1_FB23                        CAN_F7R1_FB23_Msk
#define CAN_F7R1_FB24_Pos                    (24U)
#define CAN_F7R1_FB24_Msk                    (0x1UL << CAN_F7R1_FB24_Pos)
#define CAN_F7R1_FB24                        CAN_F7R1_FB24_Msk
#define CAN_F7R1_FB25_Pos                    (25U)
#define CAN_F7R1_FB25_Msk                    (0x1UL << CAN_F7R1_FB25_Pos)
#define CAN_F7R1_FB25                        CAN_F7R1_FB25_Msk
#define CAN_F7R1_FB26_Pos                    (26U)
#define CAN_F7R1_FB26_Msk                    (0x1UL << CAN_F7R1_FB26_Pos)
#define CAN_F7R1_FB26                        CAN_F7R1_FB26_Msk
#define CAN_F7R1_FB27_Pos                    (27U)
#define CAN_F7R1_FB27_Msk                    (0x1UL << CAN_F7R1_FB27_Pos)
#define CAN_F7R1_FB27                        CAN_F7R1_FB27_Msk
#define CAN_F7R1_FB28_Pos                    (28U)
#define CAN_F7R1_FB28_Msk                    (0x1UL << CAN_F7R1_FB28_Pos)
#define CAN_F7R1_FB28                        CAN_F7R1_FB28_Msk
#define CAN_F7R1_FB29_Pos                    (29U)
#define CAN_F7R1_FB29_Msk                    (0x1UL << CAN_F7R1_FB29_Pos)
#define CAN_F7R1_FB29                        CAN_F7R1_FB29_Msk
#define CAN_F7R1_FB30_Pos                    (30U)
#define CAN_F7R1_FB30_Msk                    (0x1UL << CAN_F7R1_FB30_Pos)
#define CAN_F7R1_FB30                        CAN_F7R1_FB30_Msk
#define CAN_F7R1_FB31_Pos                    (31U)
#define CAN_F7R1_FB31_Msk                    (0x1UL << CAN_F7R1_FB31_Pos)
#define CAN_F7R1_FB31                        CAN_F7R1_FB31_Msk

#define CAN_F8R1_FB0_Pos                     (0U)
#define CAN_F8R1_FB0_Msk                     (0x1UL << CAN_F8R1_FB0_Pos)
#define CAN_F8R1_FB0                         CAN_F8R1_FB0_Msk
#define CAN_F8R1_FB1_Pos                     (1U)
#define CAN_F8R1_FB1_Msk                     (0x1UL << CAN_F8R1_FB1_Pos)
#define CAN_F8R1_FB1                         CAN_F8R1_FB1_Msk
#define CAN_F8R1_FB2_Pos                     (2U)
#define CAN_F8R1_FB2_Msk                     (0x1UL << CAN_F8R1_FB2_Pos)
#define CAN_F8R1_FB2                         CAN_F8R1_FB2_Msk
#define CAN_F8R1_FB3_Pos                     (3U)
#define CAN_F8R1_FB3_Msk                     (0x1UL << CAN_F8R1_FB3_Pos)
#define CAN_F8R1_FB3                         CAN_F8R1_FB3_Msk
#define CAN_F8R1_FB4_Pos                     (4U)
#define CAN_F8R1_FB4_Msk                     (0x1UL << CAN_F8R1_FB4_Pos)
#define CAN_F8R1_FB4                         CAN_F8R1_FB4_Msk
#define CAN_F8R1_FB5_Pos                     (5U)
#define CAN_F8R1_FB5_Msk                     (0x1UL << CAN_F8R1_FB5_Pos)
#define CAN_F8R1_FB5                         CAN_F8R1_FB5_Msk
#define CAN_F8R1_FB6_Pos                     (6U)
#define CAN_F8R1_FB6_Msk                     (0x1UL << CAN_F8R1_FB6_Pos)
#define CAN_F8R1_FB6                         CAN_F8R1_FB6_Msk
#define CAN_F8R1_FB7_Pos                     (7U)
#define CAN_F8R1_FB7_Msk                     (0x1UL << CAN_F8R1_FB7_Pos)
#define CAN_F8R1_FB7                         CAN_F8R1_FB7_Msk
#define CAN_F8R1_FB8_Pos                     (8U)
#define CAN_F8R1_FB8_Msk                     (0x1UL << CAN_F8R1_FB8_Pos)
#define CAN_F8R1_FB8                         CAN_F8R1_FB8_Msk
#define CAN_F8R1_FB9_Pos                     (9U)
#define CAN_F8R1_FB9_Msk                     (0x1UL << CAN_F8R1_FB9_Pos)
#define CAN_F8R1_FB9                         CAN_F8R1_FB9_Msk
#define CAN_F8R1_FB10_Pos                    (10U)
#define CAN_F8R1_FB10_Msk                    (0x1UL << CAN_F8R1_FB10_Pos)
#define CAN_F8R1_FB10                        CAN_F8R1_FB10_Msk
#define CAN_F8R1_FB11_Pos                    (11U)
#define CAN_F8R1_FB11_Msk                    (0x1UL << CAN_F8R1_FB11_Pos)
#define CAN_F8R1_FB11                        CAN_F8R1_FB11_Msk
#define CAN_F8R1_FB12_Pos                    (12U)
#define CAN_F8R1_FB12_Msk                    (0x1UL << CAN_F8R1_FB12_Pos)
#define CAN_F8R1_FB12                        CAN_F8R1_FB12_Msk
#define CAN_F8R1_FB13_Pos                    (13U)
#define CAN_F8R1_FB13_Msk                    (0x1UL << CAN_F8R1_FB13_Pos)
#define CAN_F8R1_FB13                        CAN_F8R1_FB13_Msk
#define CAN_F8R1_FB14_Pos                    (14U)
#define CAN_F8R1_FB14_Msk                    (0x1UL << CAN_F8R1_FB14_Pos)
#define CAN_F8R1_FB14                        CAN_F8R1_FB14_Msk
#define CAN_F8R1_FB15_Pos                    (15U)
#define CAN_F8R1_FB15_Msk                    (0x1UL << CAN_F8R1_FB15_Pos)
#define CAN_F8R1_FB15                        CAN_F8R1_FB15_Msk
#define CAN_F8R1_FB16_Pos                    (16U)
#define CAN_F8R1_FB16_Msk                    (0x1UL << CAN_F8R1_FB16_Pos)
#define CAN_F8R1_FB16                        CAN_F8R1_FB16_Msk
#define CAN_F8R1_FB17_Pos                    (17U)
#define CAN_F8R1_FB17_Msk                    (0x1UL << CAN_F8R1_FB17_Pos)
#define CAN_F8R1_FB17                        CAN_F8R1_FB17_Msk
#define CAN_F8R1_FB18_Pos                    (18U)
#define CAN_F8R1_FB18_Msk                    (0x1UL << CAN_F8R1_FB18_Pos)
#define CAN_F8R1_FB18                        CAN_F8R1_FB18_Msk
#define CAN_F8R1_FB19_Pos                    (19U)
#define CAN_F8R1_FB19_Msk                    (0x1UL << CAN_F8R1_FB19_Pos)
#define CAN_F8R1_FB19                        CAN_F8R1_FB19_Msk
#define CAN_F8R1_FB20_Pos                    (20U)
#define CAN_F8R1_FB20_Msk                    (0x1UL << CAN_F8R1_FB20_Pos)
#define CAN_F8R1_FB20                        CAN_F8R1_FB20_Msk
#define CAN_F8R1_FB21_Pos                    (21U)
#define CAN_F8R1_FB21_Msk                    (0x1UL << CAN_F8R1_FB21_Pos)
#define CAN_F8R1_FB21                        CAN_F8R1_FB21_Msk
#define CAN_F8R1_FB22_Pos                    (22U)
#define CAN_F8R1_FB22_Msk                    (0x1UL << CAN_F8R1_FB22_Pos)
#define CAN_F8R1_FB22                        CAN_F8R1_FB22_Msk
#define CAN_F8R1_FB23_Pos                    (23U)
#define CAN_F8R1_FB23_Msk                    (0x1UL << CAN_F8R1_FB23_Pos)
#define CAN_F8R1_FB23                        CAN_F8R1_FB23_Msk
#define CAN_F8R1_FB24_Pos                    (24U)
#define CAN_F8R1_FB24_Msk                    (0x1UL << CAN_F8R1_FB24_Pos)
#define CAN_F8R1_FB24                        CAN_F8R1_FB24_Msk
#define CAN_F8R1_FB25_Pos                    (25U)
#define CAN_F8R1_FB25_Msk                    (0x1UL << CAN_F8R1_FB25_Pos)
#define CAN_F8R1_FB25                        CAN_F8R1_FB25_Msk
#define CAN_F8R1_FB26_Pos                    (26U)
#define CAN_F8R1_FB26_Msk                    (0x1UL << CAN_F8R1_FB26_Pos)
#define CAN_F8R1_FB26                        CAN_F8R1_FB26_Msk
#define CAN_F8R1_FB27_Pos                    (27U)
#define CAN_F8R1_FB27_Msk                    (0x1UL << CAN_F8R1_FB27_Pos)
#define CAN_F8R1_FB27                        CAN_F8R1_FB27_Msk
#define CAN_F8R1_FB28_Pos                    (28U)
#define CAN_F8R1_FB28_Msk                    (0x1UL << CAN_F8R1_FB28_Pos)
#define CAN_F8R1_FB28                        CAN_F8R1_FB28_Msk
#define CAN_F8R1_FB29_Pos                    (29U)
#define CAN_F8R1_FB29_Msk                    (0x1UL << CAN_F8R1_FB29_Pos)
#define CAN_F8R1_FB29                        CAN_F8R1_FB29_Msk
#define CAN_F8R1_FB30_Pos                    (30U)
#define CAN_F8R1_FB30_Msk                    (0x1UL << CAN_F8R1_FB30_Pos)
#define CAN_F8R1_FB30                        CAN_F8R1_FB30_Msk
#define CAN_F8R1_FB31_Pos                    (31U)
#define CAN_F8R1_FB31_Msk                    (0x1UL << CAN_F8R1_FB31_Pos)
#define CAN_F8R1_FB31                        CAN_F8R1_FB31_Msk

#define CAN_F9R1_FB0_Pos                     (0U)
#define CAN_F9R1_FB0_Msk                     (0x1UL << CAN_F9R1_FB0_Pos)
#define CAN_F9R1_FB0                         CAN_F9R1_FB0_Msk
#define CAN_F9R1_FB1_Pos                     (1U)
#define CAN_F9R1_FB1_Msk                     (0x1UL << CAN_F9R1_FB1_Pos)
#define CAN_F9R1_FB1                         CAN_F9R1_FB1_Msk
#define CAN_F9R1_FB2_Pos                     (2U)
#define CAN_F9R1_FB2_Msk                     (0x1UL << CAN_F9R1_FB2_Pos)
#define CAN_F9R1_FB2                         CAN_F9R1_FB2_Msk
#define CAN_F9R1_FB3_Pos                     (3U)
#define CAN_F9R1_FB3_Msk                     (0x1UL << CAN_F9R1_FB3_Pos)
#define CAN_F9R1_FB3                         CAN_F9R1_FB3_Msk
#define CAN_F9R1_FB4_Pos                     (4U)
#define CAN_F9R1_FB4_Msk                     (0x1UL << CAN_F9R1_FB4_Pos)
#define CAN_F9R1_FB4                         CAN_F9R1_FB4_Msk
#define CAN_F9R1_FB5_Pos                     (5U)
#define CAN_F9R1_FB5_Msk                     (0x1UL << CAN_F9R1_FB5_Pos)
#define CAN_F9R1_FB5                         CAN_F9R1_FB5_Msk
#define CAN_F9R1_FB6_Pos                     (6U)
#define CAN_F9R1_FB6_Msk                     (0x1UL << CAN_F9R1_FB6_Pos)
#define CAN_F9R1_FB6                         CAN_F9R1_FB6_Msk
#define CAN_F9R1_FB7_Pos                     (7U)
#define CAN_F9R1_FB7_Msk                     (0x1UL << CAN_F9R1_FB7_Pos)
#define CAN_F9R1_FB7                         CAN_F9R1_FB7_Msk
#define CAN_F9R1_FB8_Pos                     (8U)
#define CAN_F9R1_FB8_Msk                     (0x1UL << CAN_F9R1_FB8_Pos)
#define CAN_F9R1_FB8                         CAN_F9R1_FB8_Msk
#define CAN_F9R1_FB9_Pos                     (9U)
#define CAN_F9R1_FB9_Msk                     (0x1UL << CAN_F9R1_FB9_Pos)
#define CAN_F9R1_FB9                         CAN_F9R1_FB9_Msk
#define CAN_F9R1_FB10_Pos                    (10U)
#define CAN_F9R1_FB10_Msk                    (0x1UL << CAN_F9R1_FB10_Pos)
#define CAN_F9R1_FB10                        CAN_F9R1_FB10_Msk
#define CAN_F9R1_FB11_Pos                    (11U)
#define CAN_F9R1_FB11_Msk                    (0x1UL << CAN_F9R1_FB11_Pos)
#define CAN_F9R1_FB11                        CAN_F9R1_FB11_Msk
#define CAN_F9R1_FB12_Pos                    (12U)
#define CAN_F9R1_FB12_Msk                    (0x1UL << CAN_F9R1_FB12_Pos)
#define CAN_F9R1_FB12                        CAN_F9R1_FB12_Msk
#define CAN_F9R1_FB13_Pos                    (13U)
#define CAN_F9R1_FB13_Msk                    (0x1UL << CAN_F9R1_FB13_Pos)
#define CAN_F9R1_FB13                        CAN_F9R1_FB13_Msk
#define CAN_F9R1_FB14_Pos                    (14U)
#define CAN_F9R1_FB14_Msk                    (0x1UL << CAN_F9R1_FB14_Pos)
#define CAN_F9R1_FB14                        CAN_F9R1_FB14_Msk
#define CAN_F9R1_FB15_Pos                    (15U)
#define CAN_F9R1_FB15_Msk                    (0x1UL << CAN_F9R1_FB15_Pos)
#define CAN_F9R1_FB15                        CAN_F9R1_FB15_Msk
#define CAN_F9R1_FB16_Pos                    (16U)
#define CAN_F9R1_FB16_Msk                    (0x1UL << CAN_F9R1_FB16_Pos)
#define CAN_F9R1_FB16                        CAN_F9R1_FB16_Msk
#define CAN_F9R1_FB17_Pos                    (17U)
#define CAN_F9R1_FB17_Msk                    (0x1UL << CAN_F9R1_FB17_Pos)
#define CAN_F9R1_FB17                        CAN_F9R1_FB17_Msk
#define CAN_F9R1_FB18_Pos                    (18U)
#define CAN_F9R1_FB18_Msk                    (0x1UL << CAN_F9R1_FB18_Pos)
#define CAN_F9R1_FB18                        CAN_F9R1_FB18_Msk
#define CAN_F9R1_FB19_Pos                    (19U)
#define CAN_F9R1_FB19_Msk                    (0x1UL << CAN_F9R1_FB19_Pos)
#define CAN_F9R1_FB19                        CAN_F9R1_FB19_Msk
#define CAN_F9R1_FB20_Pos                    (20U)
#define CAN_F9R1_FB20_Msk                    (0x1UL << CAN_F9R1_FB20_Pos)
#define CAN_F9R1_FB20                        CAN_F9R1_FB20_Msk
#define CAN_F9R1_FB21_Pos                    (21U)
#define CAN_F9R1_FB21_Msk                    (0x1UL << CAN_F9R1_FB21_Pos)
#define CAN_F9R1_FB21                        CAN_F9R1_FB21_Msk
#define CAN_F9R1_FB22_Pos                    (22U)
#define CAN_F9R1_FB22_Msk                    (0x1UL << CAN_F9R1_FB22_Pos)
#define CAN_F9R1_FB22                        CAN_F9R1_FB22_Msk
#define CAN_F9R1_FB23_Pos                    (23U)
#define CAN_F9R1_FB23_Msk                    (0x1UL << CAN_F9R1_FB23_Pos)
#define CAN_F9R1_FB23                        CAN_F9R1_FB23_Msk
#define CAN_F9R1_FB24_Pos                    (24U)
#define CAN_F9R1_FB24_Msk                    (0x1UL << CAN_F9R1_FB24_Pos)
#define CAN_F9R1_FB24                        CAN_F9R1_FB24_Msk
#define CAN_F9R1_FB25_Pos                    (25U)
#define CAN_F9R1_FB25_Msk                    (0x1UL << CAN_F9R1_FB25_Pos)
#define CAN_F9R1_FB25                        CAN_F9R1_FB25_Msk
#define CAN_F9R1_FB26_Pos                    (26U)
#define CAN_F9R1_FB26_Msk                    (0x1UL << CAN_F9R1_FB26_Pos)
#define CAN_F9R1_FB26                        CAN_F9R1_FB26_Msk
#define CAN_F9R1_FB27_Pos                    (27U)
#define CAN_F9R1_FB27_Msk                    (0x1UL << CAN_F9R1_FB27_Pos)
#define CAN_F9R1_FB27                        CAN_F9R1_FB27_Msk
#define CAN_F9R1_FB28_Pos                    (28U)
#define CAN_F9R1_FB28_Msk                    (0x1UL << CAN_F9R1_FB28_Pos)
#define CAN_F9R1_FB28                        CAN_F9R1_FB28_Msk
#define CAN_F9R1_FB29_Pos                    (29U)
#define CAN_F9R1_FB29_Msk                    (0x1UL << CAN_F9R1_FB29_Pos)
#define CAN_F9R1_FB29                        CAN_F9R1_FB29_Msk
#define CAN_F9R1_FB30_Pos                    (30U)
#define CAN_F9R1_FB30_Msk                    (0x1UL << CAN_F9R1_FB30_Pos)
#define CAN_F9R1_FB30                        CAN_F9R1_FB30_Msk
#define CAN_F9R1_FB31_Pos                    (31U)
#define CAN_F9R1_FB31_Msk                    (0x1UL << CAN_F9R1_FB31_Pos)
#define CAN_F9R1_FB31                        CAN_F9R1_FB31_Msk

#define CAN_F10R1_FB0_Pos                    (0U)
#define CAN_F10R1_FB0_Msk                    (0x1UL << CAN_F10R1_FB0_Pos)
#define CAN_F10R1_FB0                        CAN_F10R1_FB0_Msk
#define CAN_F10R1_FB1_Pos                    (1U)
#define CAN_F10R1_FB1_Msk                    (0x1UL << CAN_F10R1_FB1_Pos)
#define CAN_F10R1_FB1                        CAN_F10R1_FB1_Msk
#define CAN_F10R1_FB2_Pos                    (2U)
#define CAN_F10R1_FB2_Msk                    (0x1UL << CAN_F10R1_FB2_Pos)
#define CAN_F10R1_FB2                        CAN_F10R1_FB2_Msk
#define CAN_F10R1_FB3_Pos                    (3U)
#define CAN_F10R1_FB3_Msk                    (0x1UL << CAN_F10R1_FB3_Pos)
#define CAN_F10R1_FB3                        CAN_F10R1_FB3_Msk
#define CAN_F10R1_FB4_Pos                    (4U)
#define CAN_F10R1_FB4_Msk                    (0x1UL << CAN_F10R1_FB4_Pos)
#define CAN_F10R1_FB4                        CAN_F10R1_FB4_Msk
#define CAN_F10R1_FB5_Pos                    (5U)
#define CAN_F10R1_FB5_Msk                    (0x1UL << CAN_F10R1_FB5_Pos)
#define CAN_F10R1_FB5                        CAN_F10R1_FB5_Msk
#define CAN_F10R1_FB6_Pos                    (6U)
#define CAN_F10R1_FB6_Msk                    (0x1UL << CAN_F10R1_FB6_Pos)
#define CAN_F10R1_FB6                        CAN_F10R1_FB6_Msk
#define CAN_F10R1_FB7_Pos                    (7U)
#define CAN_F10R1_FB7_Msk                    (0x1UL << CAN_F10R1_FB7_Pos)
#define CAN_F10R1_FB7                        CAN_F10R1_FB7_Msk
#define CAN_F10R1_FB8_Pos                    (8U)
#define CAN_F10R1_FB8_Msk                    (0x1UL << CAN_F10R1_FB8_Pos)
#define CAN_F10R1_FB8                        CAN_F10R1_FB8_Msk
#define CAN_F10R1_FB9_Pos                    (9U)
#define CAN_F10R1_FB9_Msk                    (0x1UL << CAN_F10R1_FB9_Pos)
#define CAN_F10R1_FB9                        CAN_F10R1_FB9_Msk
#define CAN_F10R1_FB10_Pos                   (10U)
#define CAN_F10R1_FB10_Msk                   (0x1UL << CAN_F10R1_FB10_Pos)
#define CAN_F10R1_FB10                       CAN_F10R1_FB10_Msk
#define CAN_F10R1_FB11_Pos                   (11U)
#define CAN_F10R1_FB11_Msk                   (0x1UL << CAN_F10R1_FB11_Pos)
#define CAN_F10R1_FB11                       CAN_F10R1_FB11_Msk
#define CAN_F10R1_FB12_Pos                   (12U)
#define CAN_F10R1_FB12_Msk                   (0x1UL << CAN_F10R1_FB12_Pos)
#define CAN_F10R1_FB12                       CAN_F10R1_FB12_Msk
#define CAN_F10R1_FB13_Pos                   (13U)
#define CAN_F10R1_FB13_Msk                   (0x1UL << CAN_F10R1_FB13_Pos)
#define CAN_F10R1_FB13                       CAN_F10R1_FB13_Msk
#define CAN_F10R1_FB14_Pos                   (14U)
#define CAN_F10R1_FB14_Msk                   (0x1UL << CAN_F10R1_FB14_Pos)
#define CAN_F10R1_FB14                       CAN_F10R1_FB14_Msk
#define CAN_F10R1_FB15_Pos                   (15U)
#define CAN_F10R1_FB15_Msk                   (0x1UL << CAN_F10R1_FB15_Pos)
#define CAN_F10R1_FB15                       CAN_F10R1_FB15_Msk
#define CAN_F10R1_FB16_Pos                   (16U)
#define CAN_F10R1_FB16_Msk                   (0x1UL << CAN_F10R1_FB16_Pos)
#define CAN_F10R1_FB16                       CAN_F10R1_FB16_Msk
#define CAN_F10R1_FB17_Pos                   (17U)
#define CAN_F10R1_FB17_Msk                   (0x1UL << CAN_F10R1_FB17_Pos)
#define CAN_F10R1_FB17                       CAN_F10R1_FB17_Msk
#define CAN_F10R1_FB18_Pos                   (18U)
#define CAN_F10R1_FB18_Msk                   (0x1UL << CAN_F10R1_FB18_Pos)
#define CAN_F10R1_FB18                       CAN_F10R1_FB18_Msk
#define CAN_F10R1_FB19_Pos                   (19U)
#define CAN_F10R1_FB19_Msk                   (0x1UL << CAN_F10R1_FB19_Pos)
#define CAN_F10R1_FB19                       CAN_F10R1_FB19_Msk
#define CAN_F10R1_FB20_Pos                   (20U)
#define CAN_F10R1_FB20_Msk                   (0x1UL << CAN_F10R1_FB20_Pos)
#define CAN_F10R1_FB20                       CAN_F10R1_FB20_Msk
#define CAN_F10R1_FB21_Pos                   (21U)
#define CAN_F10R1_FB21_Msk                   (0x1UL << CAN_F10R1_FB21_Pos)
#define CAN_F10R1_FB21                       CAN_F10R1_FB21_Msk
#define CAN_F10R1_FB22_Pos                   (22U)
#define CAN_F10R1_FB22_Msk                   (0x1UL << CAN_F10R1_FB22_Pos)
#define CAN_F10R1_FB22                       CAN_F10R1_FB22_Msk
#define CAN_F10R1_FB23_Pos                   (23U)
#define CAN_F10R1_FB23_Msk                   (0x1UL << CAN_F10R1_FB23_Pos)
#define CAN_F10R1_FB23                       CAN_F10R1_FB23_Msk
#define CAN_F10R1_FB24_Pos                   (24U)
#define CAN_F10R1_FB24_Msk                   (0x1UL << CAN_F10R1_FB24_Pos)
#define CAN_F10R1_FB24                       CAN_F10R1_FB24_Msk
#define CAN_F10R1_FB25_Pos                   (25U)
#define CAN_F10R1_FB25_Msk                   (0x1UL << CAN_F10R1_FB25_Pos)
#define CAN_F10R1_FB25                       CAN_F10R1_FB25_Msk
#define CAN_F10R1_FB26_Pos                   (26U)
#define CAN_F10R1_FB26_Msk                   (0x1UL << CAN_F10R1_FB26_Pos)
#define CAN_F10R1_FB26                       CAN_F10R1_FB26_Msk
#define CAN_F10R1_FB27_Pos                   (27U)
#define CAN_F10R1_FB27_Msk                   (0x1UL << CAN_F10R1_FB27_Pos)
#define CAN_F10R1_FB27                       CAN_F10R1_FB27_Msk
#define CAN_F10R1_FB28_Pos                   (28U)
#define CAN_F10R1_FB28_Msk                   (0x1UL << CAN_F10R1_FB28_Pos)
#define CAN_F10R1_FB28                       CAN_F10R1_FB28_Msk
#define CAN_F10R1_FB29_Pos                   (29U)
#define CAN_F10R1_FB29_Msk                   (0x1UL << CAN_F10R1_FB29_Pos)
#define CAN_F10R1_FB29                       CAN_F10R1_FB29_Msk
#define CAN_F10R1_FB30_Pos                   (30U)
#define CAN_F10R1_FB30_Msk                   (0x1UL << CAN_F10R1_FB30_Pos)
#define CAN_F10R1_FB30                       CAN_F10R1_FB30_Msk
#define CAN_F10R1_FB31_Pos                   (31U)
#define CAN_F10R1_FB31_Msk                   (0x1UL << CAN_F10R1_FB31_Pos)
#define CAN_F10R1_FB31                       CAN_F10R1_FB31_Msk

#define CAN_F11R1_FB0_Pos                    (0U)
#define CAN_F11R1_FB0_Msk                    (0x1UL << CAN_F11R1_FB0_Pos)
#define CAN_F11R1_FB0                        CAN_F11R1_FB0_Msk
#define CAN_F11R1_FB1_Pos                    (1U)
#define CAN_F11R1_FB1_Msk                    (0x1UL << CAN_F11R1_FB1_Pos)
#define CAN_F11R1_FB1                        CAN_F11R1_FB1_Msk
#define CAN_F11R1_FB2_Pos                    (2U)
#define CAN_F11R1_FB2_Msk                    (0x1UL << CAN_F11R1_FB2_Pos)
#define CAN_F11R1_FB2                        CAN_F11R1_FB2_Msk
#define CAN_F11R1_FB3_Pos                    (3U)
#define CAN_F11R1_FB3_Msk                    (0x1UL << CAN_F11R1_FB3_Pos)
#define CAN_F11R1_FB3                        CAN_F11R1_FB3_Msk
#define CAN_F11R1_FB4_Pos                    (4U)
#define CAN_F11R1_FB4_Msk                    (0x1UL << CAN_F11R1_FB4_Pos)
#define CAN_F11R1_FB4                        CAN_F11R1_FB4_Msk
#define CAN_F11R1_FB5_Pos                    (5U)
#define CAN_F11R1_FB5_Msk                    (0x1UL << CAN_F11R1_FB5_Pos)
#define CAN_F11R1_FB5                        CAN_F11R1_FB5_Msk
#define CAN_F11R1_FB6_Pos                    (6U)
#define CAN_F11R1_FB6_Msk                    (0x1UL << CAN_F11R1_FB6_Pos)
#define CAN_F11R1_FB6                        CAN_F11R1_FB6_Msk
#define CAN_F11R1_FB7_Pos                    (7U)
#define CAN_F11R1_FB7_Msk                    (0x1UL << CAN_F11R1_FB7_Pos)
#define CAN_F11R1_FB7                        CAN_F11R1_FB7_Msk
#define CAN_F11R1_FB8_Pos                    (8U)
#define CAN_F11R1_FB8_Msk                    (0x1UL << CAN_F11R1_FB8_Pos)
#define CAN_F11R1_FB8                        CAN_F11R1_FB8_Msk
#define CAN_F11R1_FB9_Pos                    (9U)
#define CAN_F11R1_FB9_Msk                    (0x1UL << CAN_F11R1_FB9_Pos)
#define CAN_F11R1_FB9                        CAN_F11R1_FB9_Msk
#define CAN_F11R1_FB10_Pos                   (10U)
#define CAN_F11R1_FB10_Msk                   (0x1UL << CAN_F11R1_FB10_Pos)
#define CAN_F11R1_FB10                       CAN_F11R1_FB10_Msk
#define CAN_F11R1_FB11_Pos                   (11U)
#define CAN_F11R1_FB11_Msk                   (0x1UL << CAN_F11R1_FB11_Pos)
#define CAN_F11R1_FB11                       CAN_F11R1_FB11_Msk
#define CAN_F11R1_FB12_Pos                   (12U)
#define CAN_F11R1_FB12_Msk                   (0x1UL << CAN_F11R1_FB12_Pos)
#define CAN_F11R1_FB12                       CAN_F11R1_FB12_Msk
#define CAN_F11R1_FB13_Pos                   (13U)
#define CAN_F11R1_FB13_Msk                   (0x1UL << CAN_F11R1_FB13_Pos)
#define CAN_F11R1_FB13                       CAN_F11R1_FB13_Msk
#define CAN_F11R1_FB14_Pos                   (14U)
#define CAN_F11R1_FB14_Msk                   (0x1UL << CAN_F11R1_FB14_Pos)
#define CAN_F11R1_FB14                       CAN_F11R1_FB14_Msk
#define CAN_F11R1_FB15_Pos                   (15U)
#define CAN_F11R1_FB15_Msk                   (0x1UL << CAN_F11R1_FB15_Pos)
#define CAN_F11R1_FB15                       CAN_F11R1_FB15_Msk
#define CAN_F11R1_FB16_Pos                   (16U)
#define CAN_F11R1_FB16_Msk                   (0x1UL << CAN_F11R1_FB16_Pos)
#define CAN_F11R1_FB16                       CAN_F11R1_FB16_Msk
#define CAN_F11R1_FB17_Pos                   (17U)
#define CAN_F11R1_FB17_Msk                   (0x1UL << CAN_F11R1_FB17_Pos)
#define CAN_F11R1_FB17                       CAN_F11R1_FB17_Msk
#define CAN_F11R1_FB18_Pos                   (18U)
#define CAN_F11R1_FB18_Msk                   (0x1UL << CAN_F11R1_FB18_Pos)
#define CAN_F11R1_FB18                       CAN_F11R1_FB18_Msk
#define CAN_F11R1_FB19_Pos                   (19U)
#define CAN_F11R1_FB19_Msk                   (0x1UL << CAN_F11R1_FB19_Pos)
#define CAN_F11R1_FB19                       CAN_F11R1_FB19_Msk
#define CAN_F11R1_FB20_Pos                   (20U)
#define CAN_F11R1_FB20_Msk                   (0x1UL << CAN_F11R1_FB20_Pos)
#define CAN_F11R1_FB20                       CAN_F11R1_FB20_Msk
#define CAN_F11R1_FB21_Pos                   (21U)
#define CAN_F11R1_FB21_Msk                   (0x1UL << CAN_F11R1_FB21_Pos)
#define CAN_F11R1_FB21                       CAN_F11R1_FB21_Msk
#define CAN_F11R1_FB22_Pos                   (22U)
#define CAN_F11R1_FB22_Msk                   (0x1UL << CAN_F11R1_FB22_Pos)
#define CAN_F11R1_FB22                       CAN_F11R1_FB22_Msk
#define CAN_F11R1_FB23_Pos                   (23U)
#define CAN_F11R1_FB23_Msk                   (0x1UL << CAN_F11R1_FB23_Pos)
#define CAN_F11R1_FB23                       CAN_F11R1_FB23_Msk
#define CAN_F11R1_FB24_Pos                   (24U)
#define CAN_F11R1_FB24_Msk                   (0x1UL << CAN_F11R1_FB24_Pos)
#define CAN_F11R1_FB24                       CAN_F11R1_FB24_Msk
#define CAN_F11R1_FB25_Pos                   (25U)
#define CAN_F11R1_FB25_Msk                   (0x1UL << CAN_F11R1_FB25_Pos)
#define CAN_F11R1_FB25                       CAN_F11R1_FB25_Msk
#define CAN_F11R1_FB26_Pos                   (26U)
#define CAN_F11R1_FB26_Msk                   (0x1UL << CAN_F11R1_FB26_Pos)
#define CAN_F11R1_FB26                       CAN_F11R1_FB26_Msk
#define CAN_F11R1_FB27_Pos                   (27U)
#define CAN_F11R1_FB27_Msk                   (0x1UL << CAN_F11R1_FB27_Pos)
#define CAN_F11R1_FB27                       CAN_F11R1_FB27_Msk
#define CAN_F11R1_FB28_Pos                   (28U)
#define CAN_F11R1_FB28_Msk                   (0x1UL << CAN_F11R1_FB28_Pos)
#define CAN_F11R1_FB28                       CAN_F11R1_FB28_Msk
#define CAN_F11R1_FB29_Pos                   (29U)
#define CAN_F11R1_FB29_Msk                   (0x1UL << CAN_F11R1_FB29_Pos)
#define CAN_F11R1_FB29                       CAN_F11R1_FB29_Msk
#define CAN_F11R1_FB30_Pos                   (30U)
#define CAN_F11R1_FB30_Msk                   (0x1UL << CAN_F11R1_FB30_Pos)
#define CAN_F11R1_FB30                       CAN_F11R1_FB30_Msk
#define CAN_F11R1_FB31_Pos                   (31U)
#define CAN_F11R1_FB31_Msk                   (0x1UL << CAN_F11R1_FB31_Pos)
#define CAN_F11R1_FB31                       CAN_F11R1_FB31_Msk

#define CAN_F12R1_FB0_Pos                    (0U)
#define CAN_F12R1_FB0_Msk                    (0x1UL << CAN_F12R1_FB0_Pos)
#define CAN_F12R1_FB0                        CAN_F12R1_FB0_Msk
#define CAN_F12R1_FB1_Pos                    (1U)
#define CAN_F12R1_FB1_Msk                    (0x1UL << CAN_F12R1_FB1_Pos)
#define CAN_F12R1_FB1                        CAN_F12R1_FB1_Msk
#define CAN_F12R1_FB2_Pos                    (2U)
#define CAN_F12R1_FB2_Msk                    (0x1UL << CAN_F12R1_FB2_Pos)
#define CAN_F12R1_FB2                        CAN_F12R1_FB2_Msk
#define CAN_F12R1_FB3_Pos                    (3U)
#define CAN_F12R1_FB3_Msk                    (0x1UL << CAN_F12R1_FB3_Pos)
#define CAN_F12R1_FB3                        CAN_F12R1_FB3_Msk
#define CAN_F12R1_FB4_Pos                    (4U)
#define CAN_F12R1_FB4_Msk                    (0x1UL << CAN_F12R1_FB4_Pos)
#define CAN_F12R1_FB4                        CAN_F12R1_FB4_Msk
#define CAN_F12R1_FB5_Pos                    (5U)
#define CAN_F12R1_FB5_Msk                    (0x1UL << CAN_F12R1_FB5_Pos)
#define CAN_F12R1_FB5                        CAN_F12R1_FB5_Msk
#define CAN_F12R1_FB6_Pos                    (6U)
#define CAN_F12R1_FB6_Msk                    (0x1UL << CAN_F12R1_FB6_Pos)
#define CAN_F12R1_FB6                        CAN_F12R1_FB6_Msk
#define CAN_F12R1_FB7_Pos                    (7U)
#define CAN_F12R1_FB7_Msk                    (0x1UL << CAN_F12R1_FB7_Pos)
#define CAN_F12R1_FB7                        CAN_F12R1_FB7_Msk
#define CAN_F12R1_FB8_Pos                    (8U)
#define CAN_F12R1_FB8_Msk                    (0x1UL << CAN_F12R1_FB8_Pos)
#define CAN_F12R1_FB8                        CAN_F12R1_FB8_Msk
#define CAN_F12R1_FB9_Pos                    (9U)
#define CAN_F12R1_FB9_Msk                    (0x1UL << CAN_F12R1_FB9_Pos)
#define CAN_F12R1_FB9                        CAN_F12R1_FB9_Msk
#define CAN_F12R1_FB10_Pos                   (10U)
#define CAN_F12R1_FB10_Msk                   (0x1UL << CAN_F12R1_FB10_Pos)
#define CAN_F12R1_FB10                       CAN_F12R1_FB10_Msk
#define CAN_F12R1_FB11_Pos                   (11U)
#define CAN_F12R1_FB11_Msk                   (0x1UL << CAN_F12R1_FB11_Pos)
#define CAN_F12R1_FB11                       CAN_F12R1_FB11_Msk
#define CAN_F12R1_FB12_Pos                   (12U)
#define CAN_F12R1_FB12_Msk                   (0x1UL << CAN_F12R1_FB12_Pos)
#define CAN_F12R1_FB12                       CAN_F12R1_FB12_Msk
#define CAN_F12R1_FB13_Pos                   (13U)
#define CAN_F12R1_FB13_Msk                   (0x1UL << CAN_F12R1_FB13_Pos)
#define CAN_F12R1_FB13                       CAN_F12R1_FB13_Msk
#define CAN_F12R1_FB14_Pos                   (14U)
#define CAN_F12R1_FB14_Msk                   (0x1UL << CAN_F12R1_FB14_Pos)
#define CAN_F12R1_FB14                       CAN_F12R1_FB14_Msk
#define CAN_F12R1_FB15_Pos                   (15U)
#define CAN_F12R1_FB15_Msk                   (0x1UL << CAN_F12R1_FB15_Pos)
#define CAN_F12R1_FB15                       CAN_F12R1_FB15_Msk
#define CAN_F12R1_FB16_Pos                   (16U)
#define CAN_F12R1_FB16_Msk                   (0x1UL << CAN_F12R1_FB16_Pos)
#define CAN_F12R1_FB16                       CAN_F12R1_FB16_Msk
#define CAN_F12R1_FB17_Pos                   (17U)
#define CAN_F12R1_FB17_Msk                   (0x1UL << CAN_F12R1_FB17_Pos)
#define CAN_F12R1_FB17                       CAN_F12R1_FB17_Msk
#define CAN_F12R1_FB18_Pos                   (18U)
#define CAN_F12R1_FB18_Msk                   (0x1UL << CAN_F12R1_FB18_Pos)
#define CAN_F12R1_FB18                       CAN_F12R1_FB18_Msk
#define CAN_F12R1_FB19_Pos                   (19U)
#define CAN_F12R1_FB19_Msk                   (0x1UL << CAN_F12R1_FB19_Pos)
#define CAN_F12R1_FB19                       CAN_F12R1_FB19_Msk
#define CAN_F12R1_FB20_Pos                   (20U)
#define CAN_F12R1_FB20_Msk                   (0x1UL << CAN_F12R1_FB20_Pos)
#define CAN_F12R1_FB20                       CAN_F12R1_FB20_Msk
#define CAN_F12R1_FB21_Pos                   (21U)
#define CAN_F12R1_FB21_Msk                   (0x1UL << CAN_F12R1_FB21_Pos)
#define CAN_F12R1_FB21                       CAN_F12R1_FB21_Msk
#define CAN_F12R1_FB22_Pos                   (22U)
#define CAN_F12R1_FB22_Msk                   (0x1UL << CAN_F12R1_FB22_Pos)
#define CAN_F12R1_FB22                       CAN_F12R1_FB22_Msk
#define CAN_F12R1_FB23_Pos                   (23U)
#define CAN_F12R1_FB23_Msk                   (0x1UL << CAN_F12R1_FB23_Pos)
#define CAN_F12R1_FB23                       CAN_F12R1_FB23_Msk
#define CAN_F12R1_FB24_Pos                   (24U)
#define CAN_F12R1_FB24_Msk                   (0x1UL << CAN_F12R1_FB24_Pos)
#define CAN_F12R1_FB24                       CAN_F12R1_FB24_Msk
#define CAN_F12R1_FB25_Pos                   (25U)
#define CAN_F12R1_FB25_Msk                   (0x1UL << CAN_F12R1_FB25_Pos)
#define CAN_F12R1_FB25                       CAN_F12R1_FB25_Msk
#define CAN_F12R1_FB26_Pos                   (26U)
#define CAN_F12R1_FB26_Msk                   (0x1UL << CAN_F12R1_FB26_Pos)
#define CAN_F12R1_FB26                       CAN_F12R1_FB26_Msk
#define CAN_F12R1_FB27_Pos                   (27U)
#define CAN_F12R1_FB27_Msk                   (0x1UL << CAN_F12R1_FB27_Pos)
#define CAN_F12R1_FB27                       CAN_F12R1_FB27_Msk
#define CAN_F12R1_FB28_Pos                   (28U)
#define CAN_F12R1_FB28_Msk                   (0x1UL << CAN_F12R1_FB28_Pos)
#define CAN_F12R1_FB28                       CAN_F12R1_FB28_Msk
#define CAN_F12R1_FB29_Pos                   (29U)
#define CAN_F12R1_FB29_Msk                   (0x1UL << CAN_F12R1_FB29_Pos)
#define CAN_F12R1_FB29                       CAN_F12R1_FB29_Msk
#define CAN_F12R1_FB30_Pos                   (30U)
#define CAN_F12R1_FB30_Msk                   (0x1UL << CAN_F12R1_FB30_Pos)
#define CAN_F12R1_FB30                       CAN_F12R1_FB30_Msk
#define CAN_F12R1_FB31_Pos                   (31U)
#define CAN_F12R1_FB31_Msk                   (0x1UL << CAN_F12R1_FB31_Pos)
#define CAN_F12R1_FB31                       CAN_F12R1_FB31_Msk

#define CAN_F13R1_FB0_Pos                    (0U)
#define CAN_F13R1_FB0_Msk                    (0x1UL << CAN_F13R1_FB0_Pos)
#define CAN_F13R1_FB0                        CAN_F13R1_FB0_Msk
#define CAN_F13R1_FB1_Pos                    (1U)
#define CAN_F13R1_FB1_Msk                    (0x1UL << CAN_F13R1_FB1_Pos)
#define CAN_F13R1_FB1                        CAN_F13R1_FB1_Msk
#define CAN_F13R1_FB2_Pos                    (2U)
#define CAN_F13R1_FB2_Msk                    (0x1UL << CAN_F13R1_FB2_Pos)
#define CAN_F13R1_FB2                        CAN_F13R1_FB2_Msk
#define CAN_F13R1_FB3_Pos                    (3U)
#define CAN_F13R1_FB3_Msk                    (0x1UL << CAN_F13R1_FB3_Pos)
#define CAN_F13R1_FB3                        CAN_F13R1_FB3_Msk
#define CAN_F13R1_FB4_Pos                    (4U)
#define CAN_F13R1_FB4_Msk                    (0x1UL << CAN_F13R1_FB4_Pos)
#define CAN_F13R1_FB4                        CAN_F13R1_FB4_Msk
#define CAN_F13R1_FB5_Pos                    (5U)
#define CAN_F13R1_FB5_Msk                    (0x1UL << CAN_F13R1_FB5_Pos)
#define CAN_F13R1_FB5                        CAN_F13R1_FB5_Msk
#define CAN_F13R1_FB6_Pos                    (6U)
#define CAN_F13R1_FB6_Msk                    (0x1UL << CAN_F13R1_FB6_Pos)
#define CAN_F13R1_FB6                        CAN_F13R1_FB6_Msk
#define CAN_F13R1_FB7_Pos                    (7U)
#define CAN_F13R1_FB7_Msk                    (0x1UL << CAN_F13R1_FB7_Pos)
#define CAN_F13R1_FB7                        CAN_F13R1_FB7_Msk
#define CAN_F13R1_FB8_Pos                    (8U)
#define CAN_F13R1_FB8_Msk                    (0x1UL << CAN_F13R1_FB8_Pos)
#define CAN_F13R1_FB8                        CAN_F13R1_FB8_Msk
#define CAN_F13R1_FB9_Pos                    (9U)
#define CAN_F13R1_FB9_Msk                    (0x1UL << CAN_F13R1_FB9_Pos)
#define CAN_F13R1_FB9                        CAN_F13R1_FB9_Msk
#define CAN_F13R1_FB10_Pos                   (10U)
#define CAN_F13R1_FB10_Msk                   (0x1UL << CAN_F13R1_FB10_Pos)
#define CAN_F13R1_FB10                       CAN_F13R1_FB10_Msk
#define CAN_F13R1_FB11_Pos                   (11U)
#define CAN_F13R1_FB11_Msk                   (0x1UL << CAN_F13R1_FB11_Pos)
#define CAN_F13R1_FB11                       CAN_F13R1_FB11_Msk
#define CAN_F13R1_FB12_Pos                   (12U)
#define CAN_F13R1_FB12_Msk                   (0x1UL << CAN_F13R1_FB12_Pos)
#define CAN_F13R1_FB12                       CAN_F13R1_FB12_Msk
#define CAN_F13R1_FB13_Pos                   (13U)
#define CAN_F13R1_FB13_Msk                   (0x1UL << CAN_F13R1_FB13_Pos)
#define CAN_F13R1_FB13                       CAN_F13R1_FB13_Msk
#define CAN_F13R1_FB14_Pos                   (14U)
#define CAN_F13R1_FB14_Msk                   (0x1UL << CAN_F13R1_FB14_Pos)
#define CAN_F13R1_FB14                       CAN_F13R1_FB14_Msk
#define CAN_F13R1_FB15_Pos                   (15U)
#define CAN_F13R1_FB15_Msk                   (0x1UL << CAN_F13R1_FB15_Pos)
#define CAN_F13R1_FB15                       CAN_F13R1_FB15_Msk
#define CAN_F13R1_FB16_Pos                   (16U)
#define CAN_F13R1_FB16_Msk                   (0x1UL << CAN_F13R1_FB16_Pos)
#define CAN_F13R1_FB16                       CAN_F13R1_FB16_Msk
#define CAN_F13R1_FB17_Pos                   (17U)
#define CAN_F13R1_FB17_Msk                   (0x1UL << CAN_F13R1_FB17_Pos)
#define CAN_F13R1_FB17                       CAN_F13R1_FB17_Msk
#define CAN_F13R1_FB18_Pos                   (18U)
#define CAN_F13R1_FB18_Msk                   (0x1UL << CAN_F13R1_FB18_Pos)
#define CAN_F13R1_FB18                       CAN_F13R1_FB18_Msk
#define CAN_F13R1_FB19_Pos                   (19U)
#define CAN_F13R1_FB19_Msk                   (0x1UL << CAN_F13R1_FB19_Pos)
#define CAN_F13R1_FB19                       CAN_F13R1_FB19_Msk
#define CAN_F13R1_FB20_Pos                   (20U)
#define CAN_F13R1_FB20_Msk                   (0x1UL << CAN_F13R1_FB20_Pos)
#define CAN_F13R1_FB20                       CAN_F13R1_FB20_Msk
#define CAN_F13R1_FB21_Pos                   (21U)
#define CAN_F13R1_FB21_Msk                   (0x1UL << CAN_F13R1_FB21_Pos)
#define CAN_F13R1_FB21                       CAN_F13R1_FB21_Msk
#define CAN_F13R1_FB22_Pos                   (22U)
#define CAN_F13R1_FB22_Msk                   (0x1UL << CAN_F13R1_FB22_Pos)
#define CAN_F13R1_FB22                       CAN_F13R1_FB22_Msk
#define CAN_F13R1_FB23_Pos                   (23U)
#define CAN_F13R1_FB23_Msk                   (0x1UL << CAN_F13R1_FB23_Pos)
#define CAN_F13R1_FB23                       CAN_F13R1_FB23_Msk
#define CAN_F13R1_FB24_Pos                   (24U)
#define CAN_F13R1_FB24_Msk                   (0x1UL << CAN_F13R1_FB24_Pos)
#define CAN_F13R1_FB24                       CAN_F13R1_FB24_Msk
#define CAN_F13R1_FB25_Pos                   (25U)
#define CAN_F13R1_FB25_Msk                   (0x1UL << CAN_F13R1_FB25_Pos)
#define CAN_F13R1_FB25                       CAN_F13R1_FB25_Msk
#define CAN_F13R1_FB26_Pos                   (26U)
#define CAN_F13R1_FB26_Msk                   (0x1UL << CAN_F13R1_FB26_Pos)
#define CAN_F13R1_FB26                       CAN_F13R1_FB26_Msk
#define CAN_F13R1_FB27_Pos                   (27U)
#define CAN_F13R1_FB27_Msk                   (0x1UL << CAN_F13R1_FB27_Pos)
#define CAN_F13R1_FB27                       CAN_F13R1_FB27_Msk
#define CAN_F13R1_FB28_Pos                   (28U)
#define CAN_F13R1_FB28_Msk                   (0x1UL << CAN_F13R1_FB28_Pos)
#define CAN_F13R1_FB28                       CAN_F13R1_FB28_Msk
#define CAN_F13R1_FB29_Pos                   (29U)
#define CAN_F13R1_FB29_Msk                   (0x1UL << CAN_F13R1_FB29_Pos)
#define CAN_F13R1_FB29                       CAN_F13R1_FB29_Msk
#define CAN_F13R1_FB30_Pos                   (30U)
#define CAN_F13R1_FB30_Msk                   (0x1UL << CAN_F13R1_FB30_Pos)
#define CAN_F13R1_FB30                       CAN_F13R1_FB30_Msk
#define CAN_F13R1_FB31_Pos                   (31U)
#define CAN_F13R1_FB31_Msk                   (0x1UL << CAN_F13R1_FB31_Pos)
#define CAN_F13R1_FB31                       CAN_F13R1_FB31_Msk

#define CAN_F0R2_FB0_Pos                     (0U)
#define CAN_F0R2_FB0_Msk                     (0x1UL << CAN_F0R2_FB0_Pos)
#define CAN_F0R2_FB0                         CAN_F0R2_FB0_Msk
#define CAN_F0R2_FB1_Pos                     (1U)
#define CAN_F0R2_FB1_Msk                     (0x1UL << CAN_F0R2_FB1_Pos)
#define CAN_F0R2_FB1                         CAN_F0R2_FB1_Msk
#define CAN_F0R2_FB2_Pos                     (2U)
#define CAN_F0R2_FB2_Msk                     (0x1UL << CAN_F0R2_FB2_Pos)
#define CAN_F0R2_FB2                         CAN_F0R2_FB2_Msk
#define CAN_F0R2_FB3_Pos                     (3U)
#define CAN_F0R2_FB3_Msk                     (0x1UL << CAN_F0R2_FB3_Pos)
#define CAN_F0R2_FB3                         CAN_F0R2_FB3_Msk
#define CAN_F0R2_FB4_Pos                     (4U)
#define CAN_F0R2_FB4_Msk                     (0x1UL << CAN_F0R2_FB4_Pos)
#define CAN_F0R2_FB4                         CAN_F0R2_FB4_Msk
#define CAN_F0R2_FB5_Pos                     (5U)
#define CAN_F0R2_FB5_Msk                     (0x1UL << CAN_F0R2_FB5_Pos)
#define CAN_F0R2_FB5                         CAN_F0R2_FB5_Msk
#define CAN_F0R2_FB6_Pos                     (6U)
#define CAN_F0R2_FB6_Msk                     (0x1UL << CAN_F0R2_FB6_Pos)
#define CAN_F0R2_FB6                         CAN_F0R2_FB6_Msk
#define CAN_F0R2_FB7_Pos                     (7U)
#define CAN_F0R2_FB7_Msk                     (0x1UL << CAN_F0R2_FB7_Pos)
#define CAN_F0R2_FB7                         CAN_F0R2_FB7_Msk
#define CAN_F0R2_FB8_Pos                     (8U)
#define CAN_F0R2_FB8_Msk                     (0x1UL << CAN_F0R2_FB8_Pos)
#define CAN_F0R2_FB8                         CAN_F0R2_FB8_Msk
#define CAN_F0R2_FB9_Pos                     (9U)
#define CAN_F0R2_FB9_Msk                     (0x1UL << CAN_F0R2_FB9_Pos)
#define CAN_F0R2_FB9                         CAN_F0R2_FB9_Msk
#define CAN_F0R2_FB10_Pos                    (10U)
#define CAN_F0R2_FB10_Msk                    (0x1UL << CAN_F0R2_FB10_Pos)
#define CAN_F0R2_FB10                        CAN_F0R2_FB10_Msk
#define CAN_F0R2_FB11_Pos                    (11U)
#define CAN_F0R2_FB11_Msk                    (0x1UL << CAN_F0R2_FB11_Pos)
#define CAN_F0R2_FB11                        CAN_F0R2_FB11_Msk
#define CAN_F0R2_FB12_Pos                    (12U)
#define CAN_F0R2_FB12_Msk                    (0x1UL << CAN_F0R2_FB12_Pos)
#define CAN_F0R2_FB12                        CAN_F0R2_FB12_Msk
#define CAN_F0R2_FB13_Pos                    (13U)
#define CAN_F0R2_FB13_Msk                    (0x1UL << CAN_F0R2_FB13_Pos)
#define CAN_F0R2_FB13                        CAN_F0R2_FB13_Msk
#define CAN_F0R2_FB14_Pos                    (14U)
#define CAN_F0R2_FB14_Msk                    (0x1UL << CAN_F0R2_FB14_Pos)
#define CAN_F0R2_FB14                        CAN_F0R2_FB14_Msk
#define CAN_F0R2_FB15_Pos                    (15U)
#define CAN_F0R2_FB15_Msk                    (0x1UL << CAN_F0R2_FB15_Pos)
#define CAN_F0R2_FB15                        CAN_F0R2_FB15_Msk
#define CAN_F0R2_FB16_Pos                    (16U)
#define CAN_F0R2_FB16_Msk                    (0x1UL << CAN_F0R2_FB16_Pos)
#define CAN_F0R2_FB16                        CAN_F0R2_FB16_Msk
#define CAN_F0R2_FB17_Pos                    (17U)
#define CAN_F0R2_FB17_Msk                    (0x1UL << CAN_F0R2_FB17_Pos)
#define CAN_F0R2_FB17                        CAN_F0R2_FB17_Msk
#define CAN_F0R2_FB18_Pos                    (18U)
#define CAN_F0R2_FB18_Msk                    (0x1UL << CAN_F0R2_FB18_Pos)
#define CAN_F0R2_FB18                        CAN_F0R2_FB18_Msk
#define CAN_F0R2_FB19_Pos                    (19U)
#define CAN_F0R2_FB19_Msk                    (0x1UL << CAN_F0R2_FB19_Pos)
#define CAN_F0R2_FB19                        CAN_F0R2_FB19_Msk
#define CAN_F0R2_FB20_Pos                    (20U)
#define CAN_F0R2_FB20_Msk                    (0x1UL << CAN_F0R2_FB20_Pos)
#define CAN_F0R2_FB20                        CAN_F0R2_FB20_Msk
#define CAN_F0R2_FB21_Pos                    (21U)
#define CAN_F0R2_FB21_Msk                    (0x1UL << CAN_F0R2_FB21_Pos)
#define CAN_F0R2_FB21                        CAN_F0R2_FB21_Msk
#define CAN_F0R2_FB22_Pos                    (22U)
#define CAN_F0R2_FB22_Msk                    (0x1UL << CAN_F0R2_FB22_Pos)
#define CAN_F0R2_FB22                        CAN_F0R2_FB22_Msk
#define CAN_F0R2_FB23_Pos                    (23U)
#define CAN_F0R2_FB23_Msk                    (0x1UL << CAN_F0R2_FB23_Pos)
#define CAN_F0R2_FB23                        CAN_F0R2_FB23_Msk
#define CAN_F0R2_FB24_Pos                    (24U)
#define CAN_F0R2_FB24_Msk                    (0x1UL << CAN_F0R2_FB24_Pos)
#define CAN_F0R2_FB24                        CAN_F0R2_FB24_Msk
#define CAN_F0R2_FB25_Pos                    (25U)
#define CAN_F0R2_FB25_Msk                    (0x1UL << CAN_F0R2_FB25_Pos)
#define CAN_F0R2_FB25                        CAN_F0R2_FB25_Msk
#define CAN_F0R2_FB26_Pos                    (26U)
#define CAN_F0R2_FB26_Msk                    (0x1UL << CAN_F0R2_FB26_Pos)
#define CAN_F0R2_FB26                        CAN_F0R2_FB26_Msk
#define CAN_F0R2_FB27_Pos                    (27U)
#define CAN_F0R2_FB27_Msk                    (0x1UL << CAN_F0R2_FB27_Pos)
#define CAN_F0R2_FB27                        CAN_F0R2_FB27_Msk
#define CAN_F0R2_FB28_Pos                    (28U)
#define CAN_F0R2_FB28_Msk                    (0x1UL << CAN_F0R2_FB28_Pos)
#define CAN_F0R2_FB28                        CAN_F0R2_FB28_Msk
#define CAN_F0R2_FB29_Pos                    (29U)
#define CAN_F0R2_FB29_Msk                    (0x1UL << CAN_F0R2_FB29_Pos)
#define CAN_F0R2_FB29                        CAN_F0R2_FB29_Msk
#define CAN_F0R2_FB30_Pos                    (30U)
#define CAN_F0R2_FB30_Msk                    (0x1UL << CAN_F0R2_FB30_Pos)
#define CAN_F0R2_FB30                        CAN_F0R2_FB30_Msk
#define CAN_F0R2_FB31_Pos                    (31U)
#define CAN_F0R2_FB31_Msk                    (0x1UL << CAN_F0R2_FB31_Pos)
#define CAN_F0R2_FB31                        CAN_F0R2_FB31_Msk

#define CAN_F1R2_FB0_Pos                     (0U)
#define CAN_F1R2_FB0_Msk                     (0x1UL << CAN_F1R2_FB0_Pos)
#define CAN_F1R2_FB0                         CAN_F1R2_FB0_Msk
#define CAN_F1R2_FB1_Pos                     (1U)
#define CAN_F1R2_FB1_Msk                     (0x1UL << CAN_F1R2_FB1_Pos)
#define CAN_F1R2_FB1                         CAN_F1R2_FB1_Msk
#define CAN_F1R2_FB2_Pos                     (2U)
#define CAN_F1R2_FB2_Msk                     (0x1UL << CAN_F1R2_FB2_Pos)
#define CAN_F1R2_FB2                         CAN_F1R2_FB2_Msk
#define CAN_F1R2_FB3_Pos                     (3U)
#define CAN_F1R2_FB3_Msk                     (0x1UL << CAN_F1R2_FB3_Pos)
#define CAN_F1R2_FB3                         CAN_F1R2_FB3_Msk
#define CAN_F1R2_FB4_Pos                     (4U)
#define CAN_F1R2_FB4_Msk                     (0x1UL << CAN_F1R2_FB4_Pos)
#define CAN_F1R2_FB4                         CAN_F1R2_FB4_Msk
#define CAN_F1R2_FB5_Pos                     (5U)
#define CAN_F1R2_FB5_Msk                     (0x1UL << CAN_F1R2_FB5_Pos)
#define CAN_F1R2_FB5                         CAN_F1R2_FB5_Msk
#define CAN_F1R2_FB6_Pos                     (6U)
#define CAN_F1R2_FB6_Msk                     (0x1UL << CAN_F1R2_FB6_Pos)
#define CAN_F1R2_FB6                         CAN_F1R2_FB6_Msk
#define CAN_F1R2_FB7_Pos                     (7U)
#define CAN_F1R2_FB7_Msk                     (0x1UL << CAN_F1R2_FB7_Pos)
#define CAN_F1R2_FB7                         CAN_F1R2_FB7_Msk
#define CAN_F1R2_FB8_Pos                     (8U)
#define CAN_F1R2_FB8_Msk                     (0x1UL << CAN_F1R2_FB8_Pos)
#define CAN_F1R2_FB8                         CAN_F1R2_FB8_Msk
#define CAN_F1R2_FB9_Pos                     (9U)
#define CAN_F1R2_FB9_Msk                     (0x1UL << CAN_F1R2_FB9_Pos)
#define CAN_F1R2_FB9                         CAN_F1R2_FB9_Msk
#define CAN_F1R2_FB10_Pos                    (10U)
#define CAN_F1R2_FB10_Msk                    (0x1UL << CAN_F1R2_FB10_Pos)
#define CAN_F1R2_FB10                        CAN_F1R2_FB10_Msk
#define CAN_F1R2_FB11_Pos                    (11U)
#define CAN_F1R2_FB11_Msk                    (0x1UL << CAN_F1R2_FB11_Pos)
#define CAN_F1R2_FB11                        CAN_F1R2_FB11_Msk
#define CAN_F1R2_FB12_Pos                    (12U)
#define CAN_F1R2_FB12_Msk                    (0x1UL << CAN_F1R2_FB12_Pos)
#define CAN_F1R2_FB12                        CAN_F1R2_FB12_Msk
#define CAN_F1R2_FB13_Pos                    (13U)
#define CAN_F1R2_FB13_Msk                    (0x1UL << CAN_F1R2_FB13_Pos)
#define CAN_F1R2_FB13                        CAN_F1R2_FB13_Msk
#define CAN_F1R2_FB14_Pos                    (14U)
#define CAN_F1R2_FB14_Msk                    (0x1UL << CAN_F1R2_FB14_Pos)
#define CAN_F1R2_FB14                        CAN_F1R2_FB14_Msk
#define CAN_F1R2_FB15_Pos                    (15U)
#define CAN_F1R2_FB15_Msk                    (0x1UL << CAN_F1R2_FB15_Pos)
#define CAN_F1R2_FB15                        CAN_F1R2_FB15_Msk
#define CAN_F1R2_FB16_Pos                    (16U)
#define CAN_F1R2_FB16_Msk                    (0x1UL << CAN_F1R2_FB16_Pos)
#define CAN_F1R2_FB16                        CAN_F1R2_FB16_Msk
#define CAN_F1R2_FB17_Pos                    (17U)
#define CAN_F1R2_FB17_Msk                    (0x1UL << CAN_F1R2_FB17_Pos)
#define CAN_F1R2_FB17                        CAN_F1R2_FB17_Msk
#define CAN_F1R2_FB18_Pos                    (18U)
#define CAN_F1R2_FB18_Msk                    (0x1UL << CAN_F1R2_FB18_Pos)
#define CAN_F1R2_FB18                        CAN_F1R2_FB18_Msk
#define CAN_F1R2_FB19_Pos                    (19U)
#define CAN_F1R2_FB19_Msk                    (0x1UL << CAN_F1R2_FB19_Pos)
#define CAN_F1R2_FB19                        CAN_F1R2_FB19_Msk
#define CAN_F1R2_FB20_Pos                    (20U)
#define CAN_F1R2_FB20_Msk                    (0x1UL << CAN_F1R2_FB20_Pos)
#define CAN_F1R2_FB20                        CAN_F1R2_FB20_Msk
#define CAN_F1R2_FB21_Pos                    (21U)
#define CAN_F1R2_FB21_Msk                    (0x1UL << CAN_F1R2_FB21_Pos)
#define CAN_F1R2_FB21                        CAN_F1R2_FB21_Msk
#define CAN_F1R2_FB22_Pos                    (22U)
#define CAN_F1R2_FB22_Msk                    (0x1UL << CAN_F1R2_FB22_Pos)
#define CAN_F1R2_FB22                        CAN_F1R2_FB22_Msk
#define CAN_F1R2_FB23_Pos                    (23U)
#define CAN_F1R2_FB23_Msk                    (0x1UL << CAN_F1R2_FB23_Pos)
#define CAN_F1R2_FB23                        CAN_F1R2_FB23_Msk
#define CAN_F1R2_FB24_Pos                    (24U)
#define CAN_F1R2_FB24_Msk                    (0x1UL << CAN_F1R2_FB24_Pos)
#define CAN_F1R2_FB24                        CAN_F1R2_FB24_Msk
#define CAN_F1R2_FB25_Pos                    (25U)
#define CAN_F1R2_FB25_Msk                    (0x1UL << CAN_F1R2_FB25_Pos)
#define CAN_F1R2_FB25                        CAN_F1R2_FB25_Msk
#define CAN_F1R2_FB26_Pos                    (26U)
#define CAN_F1R2_FB26_Msk                    (0x1UL << CAN_F1R2_FB26_Pos)
#define CAN_F1R2_FB26                        CAN_F1R2_FB26_Msk
#define CAN_F1R2_FB27_Pos                    (27U)
#define CAN_F1R2_FB27_Msk                    (0x1UL << CAN_F1R2_FB27_Pos)
#define CAN_F1R2_FB27                        CAN_F1R2_FB27_Msk
#define CAN_F1R2_FB28_Pos                    (28U)
#define CAN_F1R2_FB28_Msk                    (0x1UL << CAN_F1R2_FB28_Pos)
#define CAN_F1R2_FB28                        CAN_F1R2_FB28_Msk
#define CAN_F1R2_FB29_Pos                    (29U)
#define CAN_F1R2_FB29_Msk                    (0x1UL << CAN_F1R2_FB29_Pos)
#define CAN_F1R2_FB29                        CAN_F1R2_FB29_Msk
#define CAN_F1R2_FB30_Pos                    (30U)
#define CAN_F1R2_FB30_Msk                    (0x1UL << CAN_F1R2_FB30_Pos)
#define CAN_F1R2_FB30                        CAN_F1R2_FB30_Msk
#define CAN_F1R2_FB31_Pos                    (31U)
#define CAN_F1R2_FB31_Msk                    (0x1UL << CAN_F1R2_FB31_Pos)
#define CAN_F1R2_FB31                        CAN_F1R2_FB31_Msk

#define CAN_F2R2_FB0_Pos                     (0U)
#define CAN_F2R2_FB0_Msk                     (0x1UL << CAN_F2R2_FB0_Pos)
#define CAN_F2R2_FB0                         CAN_F2R2_FB0_Msk
#define CAN_F2R2_FB1_Pos                     (1U)
#define CAN_F2R2_FB1_Msk                     (0x1UL << CAN_F2R2_FB1_Pos)
#define CAN_F2R2_FB1                         CAN_F2R2_FB1_Msk
#define CAN_F2R2_FB2_Pos                     (2U)
#define CAN_F2R2_FB2_Msk                     (0x1UL << CAN_F2R2_FB2_Pos)
#define CAN_F2R2_FB2                         CAN_F2R2_FB2_Msk
#define CAN_F2R2_FB3_Pos                     (3U)
#define CAN_F2R2_FB3_Msk                     (0x1UL << CAN_F2R2_FB3_Pos)
#define CAN_F2R2_FB3                         CAN_F2R2_FB3_Msk
#define CAN_F2R2_FB4_Pos                     (4U)
#define CAN_F2R2_FB4_Msk                     (0x1UL << CAN_F2R2_FB4_Pos)
#define CAN_F2R2_FB4                         CAN_F2R2_FB4_Msk
#define CAN_F2R2_FB5_Pos                     (5U)
#define CAN_F2R2_FB5_Msk                     (0x1UL << CAN_F2R2_FB5_Pos)
#define CAN_F2R2_FB5                         CAN_F2R2_FB5_Msk
#define CAN_F2R2_FB6_Pos                     (6U)
#define CAN_F2R2_FB6_Msk                     (0x1UL << CAN_F2R2_FB6_Pos)
#define CAN_F2R2_FB6                         CAN_F2R2_FB6_Msk
#define CAN_F2R2_FB7_Pos                     (7U)
#define CAN_F2R2_FB7_Msk                     (0x1UL << CAN_F2R2_FB7_Pos)
#define CAN_F2R2_FB7                         CAN_F2R2_FB7_Msk
#define CAN_F2R2_FB8_Pos                     (8U)
#define CAN_F2R2_FB8_Msk                     (0x1UL << CAN_F2R2_FB8_Pos)
#define CAN_F2R2_FB8                         CAN_F2R2_FB8_Msk
#define CAN_F2R2_FB9_Pos                     (9U)
#define CAN_F2R2_FB9_Msk                     (0x1UL << CAN_F2R2_FB9_Pos)
#define CAN_F2R2_FB9                         CAN_F2R2_FB9_Msk
#define CAN_F2R2_FB10_Pos                    (10U)
#define CAN_F2R2_FB10_Msk                    (0x1UL << CAN_F2R2_FB10_Pos)
#define CAN_F2R2_FB10                        CAN_F2R2_FB10_Msk
#define CAN_F2R2_FB11_Pos                    (11U)
#define CAN_F2R2_FB11_Msk                    (0x1UL << CAN_F2R2_FB11_Pos)
#define CAN_F2R2_FB11                        CAN_F2R2_FB11_Msk
#define CAN_F2R2_FB12_Pos                    (12U)
#define CAN_F2R2_FB12_Msk                    (0x1UL << CAN_F2R2_FB12_Pos)
#define CAN_F2R2_FB12                        CAN_F2R2_FB12_Msk
#define CAN_F2R2_FB13_Pos                    (13U)
#define CAN_F2R2_FB13_Msk                    (0x1UL << CAN_F2R2_FB13_Pos)
#define CAN_F2R2_FB13                        CAN_F2R2_FB13_Msk
#define CAN_F2R2_FB14_Pos                    (14U)
#define CAN_F2R2_FB14_Msk                    (0x1UL << CAN_F2R2_FB14_Pos)
#define CAN_F2R2_FB14                        CAN_F2R2_FB14_Msk
#define CAN_F2R2_FB15_Pos                    (15U)
#define CAN_F2R2_FB15_Msk                    (0x1UL << CAN_F2R2_FB15_Pos)
#define CAN_F2R2_FB15                        CAN_F2R2_FB15_Msk
#define CAN_F2R2_FB16_Pos                    (16U)
#define CAN_F2R2_FB16_Msk                    (0x1UL << CAN_F2R2_FB16_Pos)
#define CAN_F2R2_FB16                        CAN_F2R2_FB16_Msk
#define CAN_F2R2_FB17_Pos                    (17U)
#define CAN_F2R2_FB17_Msk                    (0x1UL << CAN_F2R2_FB17_Pos)
#define CAN_F2R2_FB17                        CAN_F2R2_FB17_Msk
#define CAN_F2R2_FB18_Pos                    (18U)
#define CAN_F2R2_FB18_Msk                    (0x1UL << CAN_F2R2_FB18_Pos)
#define CAN_F2R2_FB18                        CAN_F2R2_FB18_Msk
#define CAN_F2R2_FB19_Pos                    (19U)
#define CAN_F2R2_FB19_Msk                    (0x1UL << CAN_F2R2_FB19_Pos)
#define CAN_F2R2_FB19                        CAN_F2R2_FB19_Msk
#define CAN_F2R2_FB20_Pos                    (20U)
#define CAN_F2R2_FB20_Msk                    (0x1UL << CAN_F2R2_FB20_Pos)
#define CAN_F2R2_FB20                        CAN_F2R2_FB20_Msk
#define CAN_F2R2_FB21_Pos                    (21U)
#define CAN_F2R2_FB21_Msk                    (0x1UL << CAN_F2R2_FB21_Pos)
#define CAN_F2R2_FB21                        CAN_F2R2_FB21_Msk
#define CAN_F2R2_FB22_Pos                    (22U)
#define CAN_F2R2_FB22_Msk                    (0x1UL << CAN_F2R2_FB22_Pos)
#define CAN_F2R2_FB22                        CAN_F2R2_FB22_Msk
#define CAN_F2R2_FB23_Pos                    (23U)
#define CAN_F2R2_FB23_Msk                    (0x1UL << CAN_F2R2_FB23_Pos)
#define CAN_F2R2_FB23                        CAN_F2R2_FB23_Msk
#define CAN_F2R2_FB24_Pos                    (24U)
#define CAN_F2R2_FB24_Msk                    (0x1UL << CAN_F2R2_FB24_Pos)
#define CAN_F2R2_FB24                        CAN_F2R2_FB24_Msk
#define CAN_F2R2_FB25_Pos                    (25U)
#define CAN_F2R2_FB25_Msk                    (0x1UL << CAN_F2R2_FB25_Pos)
#define CAN_F2R2_FB25                        CAN_F2R2_FB25_Msk
#define CAN_F2R2_FB26_Pos                    (26U)
#define CAN_F2R2_FB26_Msk                    (0x1UL << CAN_F2R2_FB26_Pos)
#define CAN_F2R2_FB26                        CAN_F2R2_FB26_Msk
#define CAN_F2R2_FB27_Pos                    (27U)
#define CAN_F2R2_FB27_Msk                    (0x1UL << CAN_F2R2_FB27_Pos)
#define CAN_F2R2_FB27                        CAN_F2R2_FB27_Msk
#define CAN_F2R2_FB28_Pos                    (28U)
#define CAN_F2R2_FB28_Msk                    (0x1UL << CAN_F2R2_FB28_Pos)
#define CAN_F2R2_FB28                        CAN_F2R2_FB28_Msk
#define CAN_F2R2_FB29_Pos                    (29U)
#define CAN_F2R2_FB29_Msk                    (0x1UL << CAN_F2R2_FB29_Pos)
#define CAN_F2R2_FB29                        CAN_F2R2_FB29_Msk
#define CAN_F2R2_FB30_Pos                    (30U)
#define CAN_F2R2_FB30_Msk                    (0x1UL << CAN_F2R2_FB30_Pos)
#define CAN_F2R2_FB30                        CAN_F2R2_FB30_Msk
#define CAN_F2R2_FB31_Pos                    (31U)
#define CAN_F2R2_FB31_Msk                    (0x1UL << CAN_F2R2_FB31_Pos)
#define CAN_F2R2_FB31                        CAN_F2R2_FB31_Msk

#define CAN_F3R2_FB0_Pos                     (0U)
#define CAN_F3R2_FB0_Msk                     (0x1UL << CAN_F3R2_FB0_Pos)
#define CAN_F3R2_FB0                         CAN_F3R2_FB0_Msk
#define CAN_F3R2_FB1_Pos                     (1U)
#define CAN_F3R2_FB1_Msk                     (0x1UL << CAN_F3R2_FB1_Pos)
#define CAN_F3R2_FB1                         CAN_F3R2_FB1_Msk
#define CAN_F3R2_FB2_Pos                     (2U)
#define CAN_F3R2_FB2_Msk                     (0x1UL << CAN_F3R2_FB2_Pos)
#define CAN_F3R2_FB2                         CAN_F3R2_FB2_Msk
#define CAN_F3R2_FB3_Pos                     (3U)
#define CAN_F3R2_FB3_Msk                     (0x1UL << CAN_F3R2_FB3_Pos)
#define CAN_F3R2_FB3                         CAN_F3R2_FB3_Msk
#define CAN_F3R2_FB4_Pos                     (4U)
#define CAN_F3R2_FB4_Msk                     (0x1UL << CAN_F3R2_FB4_Pos)
#define CAN_F3R2_FB4                         CAN_F3R2_FB4_Msk
#define CAN_F3R2_FB5_Pos                     (5U)
#define CAN_F3R2_FB5_Msk                     (0x1UL << CAN_F3R2_FB5_Pos)
#define CAN_F3R2_FB5                         CAN_F3R2_FB5_Msk
#define CAN_F3R2_FB6_Pos                     (6U)
#define CAN_F3R2_FB6_Msk                     (0x1UL << CAN_F3R2_FB6_Pos)
#define CAN_F3R2_FB6                         CAN_F3R2_FB6_Msk
#define CAN_F3R2_FB7_Pos                     (7U)
#define CAN_F3R2_FB7_Msk                     (0x1UL << CAN_F3R2_FB7_Pos)
#define CAN_F3R2_FB7                         CAN_F3R2_FB7_Msk
#define CAN_F3R2_FB8_Pos                     (8U)
#define CAN_F3R2_FB8_Msk                     (0x1UL << CAN_F3R2_FB8_Pos)
#define CAN_F3R2_FB8                         CAN_F3R2_FB8_Msk
#define CAN_F3R2_FB9_Pos                     (9U)
#define CAN_F3R2_FB9_Msk                     (0x1UL << CAN_F3R2_FB9_Pos)
#define CAN_F3R2_FB9                         CAN_F3R2_FB9_Msk
#define CAN_F3R2_FB10_Pos                    (10U)
#define CAN_F3R2_FB10_Msk                    (0x1UL << CAN_F3R2_FB10_Pos)
#define CAN_F3R2_FB10                        CAN_F3R2_FB10_Msk
#define CAN_F3R2_FB11_Pos                    (11U)
#define CAN_F3R2_FB11_Msk                    (0x1UL << CAN_F3R2_FB11_Pos)
#define CAN_F3R2_FB11                        CAN_F3R2_FB11_Msk
#define CAN_F3R2_FB12_Pos                    (12U)
#define CAN_F3R2_FB12_Msk                    (0x1UL << CAN_F3R2_FB12_Pos)
#define CAN_F3R2_FB12                        CAN_F3R2_FB12_Msk
#define CAN_F3R2_FB13_Pos                    (13U)
#define CAN_F3R2_FB13_Msk                    (0x1UL << CAN_F3R2_FB13_Pos)
#define CAN_F3R2_FB13                        CAN_F3R2_FB13_Msk
#define CAN_F3R2_FB14_Pos                    (14U)
#define CAN_F3R2_FB14_Msk                    (0x1UL << CAN_F3R2_FB14_Pos)
#define CAN_F3R2_FB14                        CAN_F3R2_FB14_Msk
#define CAN_F3R2_FB15_Pos                    (15U)
#define CAN_F3R2_FB15_Msk                    (0x1UL << CAN_F3R2_FB15_Pos)
#define CAN_F3R2_FB15                        CAN_F3R2_FB15_Msk
#define CAN_F3R2_FB16_Pos                    (16U)
#define CAN_F3R2_FB16_Msk                    (0x1UL << CAN_F3R2_FB16_Pos)
#define CAN_F3R2_FB16                        CAN_F3R2_FB16_Msk
#define CAN_F3R2_FB17_Pos                    (17U)
#define CAN_F3R2_FB17_Msk                    (0x1UL << CAN_F3R2_FB17_Pos)
#define CAN_F3R2_FB17                        CAN_F3R2_FB17_Msk
#define CAN_F3R2_FB18_Pos                    (18U)
#define CAN_F3R2_FB18_Msk                    (0x1UL << CAN_F3R2_FB18_Pos)
#define CAN_F3R2_FB18                        CAN_F3R2_FB18_Msk
#define CAN_F3R2_FB19_Pos                    (19U)
#define CAN_F3R2_FB19_Msk                    (0x1UL << CAN_F3R2_FB19_Pos)
#define CAN_F3R2_FB19                        CAN_F3R2_FB19_Msk
#define CAN_F3R2_FB20_Pos                    (20U)
#define CAN_F3R2_FB20_Msk                    (0x1UL << CAN_F3R2_FB20_Pos)
#define CAN_F3R2_FB20                        CAN_F3R2_FB20_Msk
#define CAN_F3R2_FB21_Pos                    (21U)
#define CAN_F3R2_FB21_Msk                    (0x1UL << CAN_F3R2_FB21_Pos)
#define CAN_F3R2_FB21                        CAN_F3R2_FB21_Msk
#define CAN_F3R2_FB22_Pos                    (22U)
#define CAN_F3R2_FB22_Msk                    (0x1UL << CAN_F3R2_FB22_Pos)
#define CAN_F3R2_FB22                        CAN_F3R2_FB22_Msk
#define CAN_F3R2_FB23_Pos                    (23U)
#define CAN_F3R2_FB23_Msk                    (0x1UL << CAN_F3R2_FB23_Pos)
#define CAN_F3R2_FB23                        CAN_F3R2_FB23_Msk
#define CAN_F3R2_FB24_Pos                    (24U)
#define CAN_F3R2_FB24_Msk                    (0x1UL << CAN_F3R2_FB24_Pos)
#define CAN_F3R2_FB24                        CAN_F3R2_FB24_Msk
#define CAN_F3R2_FB25_Pos                    (25U)
#define CAN_F3R2_FB25_Msk                    (0x1UL << CAN_F3R2_FB25_Pos)
#define CAN_F3R2_FB25                        CAN_F3R2_FB25_Msk
#define CAN_F3R2_FB26_Pos                    (26U)
#define CAN_F3R2_FB26_Msk                    (0x1UL << CAN_F3R2_FB26_Pos)
#define CAN_F3R2_FB26                        CAN_F3R2_FB26_Msk
#define CAN_F3R2_FB27_Pos                    (27U)
#define CAN_F3R2_FB27_Msk                    (0x1UL << CAN_F3R2_FB27_Pos)
#define CAN_F3R2_FB27                        CAN_F3R2_FB27_Msk
#define CAN_F3R2_FB28_Pos                    (28U)
#define CAN_F3R2_FB28_Msk                    (0x1UL << CAN_F3R2_FB28_Pos)
#define CAN_F3R2_FB28                        CAN_F3R2_FB28_Msk
#define CAN_F3R2_FB29_Pos                    (29U)
#define CAN_F3R2_FB29_Msk                    (0x1UL << CAN_F3R2_FB29_Pos)
#define CAN_F3R2_FB29                        CAN_F3R2_FB29_Msk
#define CAN_F3R2_FB30_Pos                    (30U)
#define CAN_F3R2_FB30_Msk                    (0x1UL << CAN_F3R2_FB30_Pos)
#define CAN_F3R2_FB30                        CAN_F3R2_FB30_Msk
#define CAN_F3R2_FB31_Pos                    (31U)
#define CAN_F3R2_FB31_Msk                    (0x1UL << CAN_F3R2_FB31_Pos)
#define CAN_F3R2_FB31                        CAN_F3R2_FB31_Msk

#define CAN_F4R2_FB0_Pos                     (0U)
#define CAN_F4R2_FB0_Msk                     (0x1UL << CAN_F4R2_FB0_Pos)
#define CAN_F4R2_FB0                         CAN_F4R2_FB0_Msk
#define CAN_F4R2_FB1_Pos                     (1U)
#define CAN_F4R2_FB1_Msk                     (0x1UL << CAN_F4R2_FB1_Pos)
#define CAN_F4R2_FB1                         CAN_F4R2_FB1_Msk
#define CAN_F4R2_FB2_Pos                     (2U)
#define CAN_F4R2_FB2_Msk                     (0x1UL << CAN_F4R2_FB2_Pos)
#define CAN_F4R2_FB2                         CAN_F4R2_FB2_Msk
#define CAN_F4R2_FB3_Pos                     (3U)
#define CAN_F4R2_FB3_Msk                     (0x1UL << CAN_F4R2_FB3_Pos)
#define CAN_F4R2_FB3                         CAN_F4R2_FB3_Msk
#define CAN_F4R2_FB4_Pos                     (4U)
#define CAN_F4R2_FB4_Msk                     (0x1UL << CAN_F4R2_FB4_Pos)
#define CAN_F4R2_FB4                         CAN_F4R2_FB4_Msk
#define CAN_F4R2_FB5_Pos                     (5U)
#define CAN_F4R2_FB5_Msk                     (0x1UL << CAN_F4R2_FB5_Pos)
#define CAN_F4R2_FB5                         CAN_F4R2_FB5_Msk
#define CAN_F4R2_FB6_Pos                     (6U)
#define CAN_F4R2_FB6_Msk                     (0x1UL << CAN_F4R2_FB6_Pos)
#define CAN_F4R2_FB6                         CAN_F4R2_FB6_Msk
#define CAN_F4R2_FB7_Pos                     (7U)
#define CAN_F4R2_FB7_Msk                     (0x1UL << CAN_F4R2_FB7_Pos)
#define CAN_F4R2_FB7                         CAN_F4R2_FB7_Msk
#define CAN_F4R2_FB8_Pos                     (8U)
#define CAN_F4R2_FB8_Msk                     (0x1UL << CAN_F4R2_FB8_Pos)
#define CAN_F4R2_FB8                         CAN_F4R2_FB8_Msk
#define CAN_F4R2_FB9_Pos                     (9U)
#define CAN_F4R2_FB9_Msk                     (0x1UL << CAN_F4R2_FB9_Pos)
#define CAN_F4R2_FB9                         CAN_F4R2_FB9_Msk
#define CAN_F4R2_FB10_Pos                    (10U)
#define CAN_F4R2_FB10_Msk                    (0x1UL << CAN_F4R2_FB10_Pos)
#define CAN_F4R2_FB10                        CAN_F4R2_FB10_Msk
#define CAN_F4R2_FB11_Pos                    (11U)
#define CAN_F4R2_FB11_Msk                    (0x1UL << CAN_F4R2_FB11_Pos)
#define CAN_F4R2_FB11                        CAN_F4R2_FB11_Msk
#define CAN_F4R2_FB12_Pos                    (12U)
#define CAN_F4R2_FB12_Msk                    (0x1UL << CAN_F4R2_FB12_Pos)
#define CAN_F4R2_FB12                        CAN_F4R2_FB12_Msk
#define CAN_F4R2_FB13_Pos                    (13U)
#define CAN_F4R2_FB13_Msk                    (0x1UL << CAN_F4R2_FB13_Pos)
#define CAN_F4R2_FB13                        CAN_F4R2_FB13_Msk
#define CAN_F4R2_FB14_Pos                    (14U)
#define CAN_F4R2_FB14_Msk                    (0x1UL << CAN_F4R2_FB14_Pos)
#define CAN_F4R2_FB14                        CAN_F4R2_FB14_Msk
#define CAN_F4R2_FB15_Pos                    (15U)
#define CAN_F4R2_FB15_Msk                    (0x1UL << CAN_F4R2_FB15_Pos)
#define CAN_F4R2_FB15                        CAN_F4R2_FB15_Msk
#define CAN_F4R2_FB16_Pos                    (16U)
#define CAN_F4R2_FB16_Msk                    (0x1UL << CAN_F4R2_FB16_Pos)
#define CAN_F4R2_FB16                        CAN_F4R2_FB16_Msk
#define CAN_F4R2_FB17_Pos                    (17U)
#define CAN_F4R2_FB17_Msk                    (0x1UL << CAN_F4R2_FB17_Pos)
#define CAN_F4R2_FB17                        CAN_F4R2_FB17_Msk
#define CAN_F4R2_FB18_Pos                    (18U)
#define CAN_F4R2_FB18_Msk                    (0x1UL << CAN_F4R2_FB18_Pos)
#define CAN_F4R2_FB18                        CAN_F4R2_FB18_Msk
#define CAN_F4R2_FB19_Pos                    (19U)
#define CAN_F4R2_FB19_Msk                    (0x1UL << CAN_F4R2_FB19_Pos)
#define CAN_F4R2_FB19                        CAN_F4R2_FB19_Msk
#define CAN_F4R2_FB20_Pos                    (20U)
#define CAN_F4R2_FB20_Msk                    (0x1UL << CAN_F4R2_FB20_Pos)
#define CAN_F4R2_FB20                        CAN_F4R2_FB20_Msk
#define CAN_F4R2_FB21_Pos                    (21U)
#define CAN_F4R2_FB21_Msk                    (0x1UL << CAN_F4R2_FB21_Pos)
#define CAN_F4R2_FB21                        CAN_F4R2_FB21_Msk
#define CAN_F4R2_FB22_Pos                    (22U)
#define CAN_F4R2_FB22_Msk                    (0x1UL << CAN_F4R2_FB22_Pos)
#define CAN_F4R2_FB22                        CAN_F4R2_FB22_Msk
#define CAN_F4R2_FB23_Pos                    (23U)
#define CAN_F4R2_FB23_Msk                    (0x1UL << CAN_F4R2_FB23_Pos)
#define CAN_F4R2_FB23                        CAN_F4R2_FB23_Msk
#define CAN_F4R2_FB24_Pos                    (24U)
#define CAN_F4R2_FB24_Msk                    (0x1UL << CAN_F4R2_FB24_Pos)
#define CAN_F4R2_FB24                        CAN_F4R2_FB24_Msk
#define CAN_F4R2_FB25_Pos                    (25U)
#define CAN_F4R2_FB25_Msk                    (0x1UL << CAN_F4R2_FB25_Pos)
#define CAN_F4R2_FB25                        CAN_F4R2_FB25_Msk
#define CAN_F4R2_FB26_Pos                    (26U)
#define CAN_F4R2_FB26_Msk                    (0x1UL << CAN_F4R2_FB26_Pos)
#define CAN_F4R2_FB26                        CAN_F4R2_FB26_Msk
#define CAN_F4R2_FB27_Pos                    (27U)
#define CAN_F4R2_FB27_Msk                    (0x1UL << CAN_F4R2_FB27_Pos)
#define CAN_F4R2_FB27                        CAN_F4R2_FB27_Msk
#define CAN_F4R2_FB28_Pos                    (28U)
#define CAN_F4R2_FB28_Msk                    (0x1UL << CAN_F4R2_FB28_Pos)
#define CAN_F4R2_FB28                        CAN_F4R2_FB28_Msk
#define CAN_F4R2_FB29_Pos                    (29U)
#define CAN_F4R2_FB29_Msk                    (0x1UL << CAN_F4R2_FB29_Pos)
#define CAN_F4R2_FB29                        CAN_F4R2_FB29_Msk
#define CAN_F4R2_FB30_Pos                    (30U)
#define CAN_F4R2_FB30_Msk                    (0x1UL << CAN_F4R2_FB30_Pos)
#define CAN_F4R2_FB30                        CAN_F4R2_FB30_Msk
#define CAN_F4R2_FB31_Pos                    (31U)
#define CAN_F4R2_FB31_Msk                    (0x1UL << CAN_F4R2_FB31_Pos)
#define CAN_F4R2_FB31                        CAN_F4R2_FB31_Msk

#define CAN_F5R2_FB0_Pos                     (0U)
#define CAN_F5R2_FB0_Msk                     (0x1UL << CAN_F5R2_FB0_Pos)
#define CAN_F5R2_FB0                         CAN_F5R2_FB0_Msk
#define CAN_F5R2_FB1_Pos                     (1U)
#define CAN_F5R2_FB1_Msk                     (0x1UL << CAN_F5R2_FB1_Pos)
#define CAN_F5R2_FB1                         CAN_F5R2_FB1_Msk
#define CAN_F5R2_FB2_Pos                     (2U)
#define CAN_F5R2_FB2_Msk                     (0x1UL << CAN_F5R2_FB2_Pos)
#define CAN_F5R2_FB2                         CAN_F5R2_FB2_Msk
#define CAN_F5R2_FB3_Pos                     (3U)
#define CAN_F5R2_FB3_Msk                     (0x1UL << CAN_F5R2_FB3_Pos)
#define CAN_F5R2_FB3                         CAN_F5R2_FB3_Msk
#define CAN_F5R2_FB4_Pos                     (4U)
#define CAN_F5R2_FB4_Msk                     (0x1UL << CAN_F5R2_FB4_Pos)
#define CAN_F5R2_FB4                         CAN_F5R2_FB4_Msk
#define CAN_F5R2_FB5_Pos                     (5U)
#define CAN_F5R2_FB5_Msk                     (0x1UL << CAN_F5R2_FB5_Pos)
#define CAN_F5R2_FB5                         CAN_F5R2_FB5_Msk
#define CAN_F5R2_FB6_Pos                     (6U)
#define CAN_F5R2_FB6_Msk                     (0x1UL << CAN_F5R2_FB6_Pos)
#define CAN_F5R2_FB6                         CAN_F5R2_FB6_Msk
#define CAN_F5R2_FB7_Pos                     (7U)
#define CAN_F5R2_FB7_Msk                     (0x1UL << CAN_F5R2_FB7_Pos)
#define CAN_F5R2_FB7                         CAN_F5R2_FB7_Msk
#define CAN_F5R2_FB8_Pos                     (8U)
#define CAN_F5R2_FB8_Msk                     (0x1UL << CAN_F5R2_FB8_Pos)
#define CAN_F5R2_FB8                         CAN_F5R2_FB8_Msk
#define CAN_F5R2_FB9_Pos                     (9U)
#define CAN_F5R2_FB9_Msk                     (0x1UL << CAN_F5R2_FB9_Pos)
#define CAN_F5R2_FB9                         CAN_F5R2_FB9_Msk
#define CAN_F5R2_FB10_Pos                    (10U)
#define CAN_F5R2_FB10_Msk                    (0x1UL << CAN_F5R2_FB10_Pos)
#define CAN_F5R2_FB10                        CAN_F5R2_FB10_Msk
#define CAN_F5R2_FB11_Pos                    (11U)
#define CAN_F5R2_FB11_Msk                    (0x1UL << CAN_F5R2_FB11_Pos)
#define CAN_F5R2_FB11                        CAN_F5R2_FB11_Msk
#define CAN_F5R2_FB12_Pos                    (12U)
#define CAN_F5R2_FB12_Msk                    (0x1UL << CAN_F5R2_FB12_Pos)
#define CAN_F5R2_FB12                        CAN_F5R2_FB12_Msk
#define CAN_F5R2_FB13_Pos                    (13U)
#define CAN_F5R2_FB13_Msk                    (0x1UL << CAN_F5R2_FB13_Pos)
#define CAN_F5R2_FB13                        CAN_F5R2_FB13_Msk
#define CAN_F5R2_FB14_Pos                    (14U)
#define CAN_F5R2_FB14_Msk                    (0x1UL << CAN_F5R2_FB14_Pos)
#define CAN_F5R2_FB14                        CAN_F5R2_FB14_Msk
#define CAN_F5R2_FB15_Pos                    (15U)
#define CAN_F5R2_FB15_Msk                    (0x1UL << CAN_F5R2_FB15_Pos)
#define CAN_F5R2_FB15                        CAN_F5R2_FB15_Msk
#define CAN_F5R2_FB16_Pos                    (16U)
#define CAN_F5R2_FB16_Msk                    (0x1UL << CAN_F5R2_FB16_Pos)
#define CAN_F5R2_FB16                        CAN_F5R2_FB16_Msk
#define CAN_F5R2_FB17_Pos                    (17U)
#define CAN_F5R2_FB17_Msk                    (0x1UL << CAN_F5R2_FB17_Pos)
#define CAN_F5R2_FB17                        CAN_F5R2_FB17_Msk
#define CAN_F5R2_FB18_Pos                    (18U)
#define CAN_F5R2_FB18_Msk                    (0x1UL << CAN_F5R2_FB18_Pos)
#define CAN_F5R2_FB18                        CAN_F5R2_FB18_Msk
#define CAN_F5R2_FB19_Pos                    (19U)
#define CAN_F5R2_FB19_Msk                    (0x1UL << CAN_F5R2_FB19_Pos)
#define CAN_F5R2_FB19                        CAN_F5R2_FB19_Msk
#define CAN_F5R2_FB20_Pos                    (20U)
#define CAN_F5R2_FB20_Msk                    (0x1UL << CAN_F5R2_FB20_Pos)
#define CAN_F5R2_FB20                        CAN_F5R2_FB20_Msk
#define CAN_F5R2_FB21_Pos                    (21U)
#define CAN_F5R2_FB21_Msk                    (0x1UL << CAN_F5R2_FB21_Pos)
#define CAN_F5R2_FB21                        CAN_F5R2_FB21_Msk
#define CAN_F5R2_FB22_Pos                    (22U)
#define CAN_F5R2_FB22_Msk                    (0x1UL << CAN_F5R2_FB22_Pos)
#define CAN_F5R2_FB22                        CAN_F5R2_FB22_Msk
#define CAN_F5R2_FB23_Pos                    (23U)
#define CAN_F5R2_FB23_Msk                    (0x1UL << CAN_F5R2_FB23_Pos)
#define CAN_F5R2_FB23                        CAN_F5R2_FB23_Msk
#define CAN_F5R2_FB24_Pos                    (24U)
#define CAN_F5R2_FB24_Msk                    (0x1UL << CAN_F5R2_FB24_Pos)
#define CAN_F5R2_FB24                        CAN_F5R2_FB24_Msk
#define CAN_F5R2_FB25_Pos                    (25U)
#define CAN_F5R2_FB25_Msk                    (0x1UL << CAN_F5R2_FB25_Pos)
#define CAN_F5R2_FB25                        CAN_F5R2_FB25_Msk
#define CAN_F5R2_FB26_Pos                    (26U)
#define CAN_F5R2_FB26_Msk                    (0x1UL << CAN_F5R2_FB26_Pos)
#define CAN_F5R2_FB26                        CAN_F5R2_FB26_Msk
#define CAN_F5R2_FB27_Pos                    (27U)
#define CAN_F5R2_FB27_Msk                    (0x1UL << CAN_F5R2_FB27_Pos)
#define CAN_F5R2_FB27                        CAN_F5R2_FB27_Msk
#define CAN_F5R2_FB28_Pos                    (28U)
#define CAN_F5R2_FB28_Msk                    (0x1UL << CAN_F5R2_FB28_Pos)
#define CAN_F5R2_FB28                        CAN_F5R2_FB28_Msk
#define CAN_F5R2_FB29_Pos                    (29U)
#define CAN_F5R2_FB29_Msk                    (0x1UL << CAN_F5R2_FB29_Pos)
#define CAN_F5R2_FB29                        CAN_F5R2_FB29_Msk
#define CAN_F5R2_FB30_Pos                    (30U)
#define CAN_F5R2_FB30_Msk                    (0x1UL << CAN_F5R2_FB30_Pos)
#define CAN_F5R2_FB30                        CAN_F5R2_FB30_Msk
#define CAN_F5R2_FB31_Pos                    (31U)
#define CAN_F5R2_FB31_Msk                    (0x1UL << CAN_F5R2_FB31_Pos)
#define CAN_F5R2_FB31                        CAN_F5R2_FB31_Msk

#define CAN_F6R2_FB0_Pos                     (0U)
#define CAN_F6R2_FB0_Msk                     (0x1UL << CAN_F6R2_FB0_Pos)
#define CAN_F6R2_FB0                         CAN_F6R2_FB0_Msk
#define CAN_F6R2_FB1_Pos                     (1U)
#define CAN_F6R2_FB1_Msk                     (0x1UL << CAN_F6R2_FB1_Pos)
#define CAN_F6R2_FB1                         CAN_F6R2_FB1_Msk
#define CAN_F6R2_FB2_Pos                     (2U)
#define CAN_F6R2_FB2_Msk                     (0x1UL << CAN_F6R2_FB2_Pos)
#define CAN_F6R2_FB2                         CAN_F6R2_FB2_Msk
#define CAN_F6R2_FB3_Pos                     (3U)
#define CAN_F6R2_FB3_Msk                     (0x1UL << CAN_F6R2_FB3_Pos)
#define CAN_F6R2_FB3                         CAN_F6R2_FB3_Msk
#define CAN_F6R2_FB4_Pos                     (4U)
#define CAN_F6R2_FB4_Msk                     (0x1UL << CAN_F6R2_FB4_Pos)
#define CAN_F6R2_FB4                         CAN_F6R2_FB4_Msk
#define CAN_F6R2_FB5_Pos                     (5U)
#define CAN_F6R2_FB5_Msk                     (0x1UL << CAN_F6R2_FB5_Pos)
#define CAN_F6R2_FB5                         CAN_F6R2_FB5_Msk
#define CAN_F6R2_FB6_Pos                     (6U)
#define CAN_F6R2_FB6_Msk                     (0x1UL << CAN_F6R2_FB6_Pos)
#define CAN_F6R2_FB6                         CAN_F6R2_FB6_Msk
#define CAN_F6R2_FB7_Pos                     (7U)
#define CAN_F6R2_FB7_Msk                     (0x1UL << CAN_F6R2_FB7_Pos)
#define CAN_F6R2_FB7                         CAN_F6R2_FB7_Msk
#define CAN_F6R2_FB8_Pos                     (8U)
#define CAN_F6R2_FB8_Msk                     (0x1UL << CAN_F6R2_FB8_Pos)
#define CAN_F6R2_FB8                         CAN_F6R2_FB8_Msk
#define CAN_F6R2_FB9_Pos                     (9U)
#define CAN_F6R2_FB9_Msk                     (0x1UL << CAN_F6R2_FB9_Pos)
#define CAN_F6R2_FB9                         CAN_F6R2_FB9_Msk
#define CAN_F6R2_FB10_Pos                    (10U)
#define CAN_F6R2_FB10_Msk                    (0x1UL << CAN_F6R2_FB10_Pos)
#define CAN_F6R2_FB10                        CAN_F6R2_FB10_Msk
#define CAN_F6R2_FB11_Pos                    (11U)
#define CAN_F6R2_FB11_Msk                    (0x1UL << CAN_F6R2_FB11_Pos)
#define CAN_F6R2_FB11                        CAN_F6R2_FB11_Msk
#define CAN_F6R2_FB12_Pos                    (12U)
#define CAN_F6R2_FB12_Msk                    (0x1UL << CAN_F6R2_FB12_Pos)
#define CAN_F6R2_FB12                        CAN_F6R2_FB12_Msk
#define CAN_F6R2_FB13_Pos                    (13U)
#define CAN_F6R2_FB13_Msk                    (0x1UL << CAN_F6R2_FB13_Pos)
#define CAN_F6R2_FB13                        CAN_F6R2_FB13_Msk
#define CAN_F6R2_FB14_Pos                    (14U)
#define CAN_F6R2_FB14_Msk                    (0x1UL << CAN_F6R2_FB14_Pos)
#define CAN_F6R2_FB14                        CAN_F6R2_FB14_Msk
#define CAN_F6R2_FB15_Pos                    (15U)
#define CAN_F6R2_FB15_Msk                    (0x1UL << CAN_F6R2_FB15_Pos)
#define CAN_F6R2_FB15                        CAN_F6R2_FB15_Msk
#define CAN_F6R2_FB16_Pos                    (16U)
#define CAN_F6R2_FB16_Msk                    (0x1UL << CAN_F6R2_FB16_Pos)
#define CAN_F6R2_FB16                        CAN_F6R2_FB16_Msk
#define CAN_F6R2_FB17_Pos                    (17U)
#define CAN_F6R2_FB17_Msk                    (0x1UL << CAN_F6R2_FB17_Pos)
#define CAN_F6R2_FB17                        CAN_F6R2_FB17_Msk
#define CAN_F6R2_FB18_Pos                    (18U)
#define CAN_F6R2_FB18_Msk                    (0x1UL << CAN_F6R2_FB18_Pos)
#define CAN_F6R2_FB18                        CAN_F6R2_FB18_Msk
#define CAN_F6R2_FB19_Pos                    (19U)
#define CAN_F6R2_FB19_Msk                    (0x1UL << CAN_F6R2_FB19_Pos)
#define CAN_F6R2_FB19                        CAN_F6R2_FB19_Msk
#define CAN_F6R2_FB20_Pos                    (20U)
#define CAN_F6R2_FB20_Msk                    (0x1UL << CAN_F6R2_FB20_Pos)
#define CAN_F6R2_FB20                        CAN_F6R2_FB20_Msk
#define CAN_F6R2_FB21_Pos                    (21U)
#define CAN_F6R2_FB21_Msk                    (0x1UL << CAN_F6R2_FB21_Pos)
#define CAN_F6R2_FB21                        CAN_F6R2_FB21_Msk
#define CAN_F6R2_FB22_Pos                    (22U)
#define CAN_F6R2_FB22_Msk                    (0x1UL << CAN_F6R2_FB22_Pos)
#define CAN_F6R2_FB22                        CAN_F6R2_FB22_Msk
#define CAN_F6R2_FB23_Pos                    (23U)
#define CAN_F6R2_FB23_Msk                    (0x1UL << CAN_F6R2_FB23_Pos)
#define CAN_F6R2_FB23                        CAN_F6R2_FB23_Msk
#define CAN_F6R2_FB24_Pos                    (24U)
#define CAN_F6R2_FB24_Msk                    (0x1UL << CAN_F6R2_FB24_Pos)
#define CAN_F6R2_FB24                        CAN_F6R2_FB24_Msk
#define CAN_F6R2_FB25_Pos                    (25U)
#define CAN_F6R2_FB25_Msk                    (0x1UL << CAN_F6R2_FB25_Pos)
#define CAN_F6R2_FB25                        CAN_F6R2_FB25_Msk
#define CAN_F6R2_FB26_Pos                    (26U)
#define CAN_F6R2_FB26_Msk                    (0x1UL << CAN_F6R2_FB26_Pos)
#define CAN_F6R2_FB26                        CAN_F6R2_FB26_Msk
#define CAN_F6R2_FB27_Pos                    (27U)
#define CAN_F6R2_FB27_Msk                    (0x1UL << CAN_F6R2_FB27_Pos)
#define CAN_F6R2_FB27                        CAN_F6R2_FB27_Msk
#define CAN_F6R2_FB28_Pos                    (28U)
#define CAN_F6R2_FB28_Msk                    (0x1UL << CAN_F6R2_FB28_Pos)
#define CAN_F6R2_FB28                        CAN_F6R2_FB28_Msk
#define CAN_F6R2_FB29_Pos                    (29U)
#define CAN_F6R2_FB29_Msk                    (0x1UL << CAN_F6R2_FB29_Pos)
#define CAN_F6R2_FB29                        CAN_F6R2_FB29_Msk
#define CAN_F6R2_FB30_Pos                    (30U)
#define CAN_F6R2_FB30_Msk                    (0x1UL << CAN_F6R2_FB30_Pos)
#define CAN_F6R2_FB30                        CAN_F6R2_FB30_Msk
#define CAN_F6R2_FB31_Pos                    (31U)
#define CAN_F6R2_FB31_Msk                    (0x1UL << CAN_F6R2_FB31_Pos)
#define CAN_F6R2_FB31                        CAN_F6R2_FB31_Msk

#define CAN_F7R2_FB0_Pos                     (0U)
#define CAN_F7R2_FB0_Msk                     (0x1UL << CAN_F7R2_FB0_Pos)
#define CAN_F7R2_FB0                         CAN_F7R2_FB0_Msk
#define CAN_F7R2_FB1_Pos                     (1U)
#define CAN_F7R2_FB1_Msk                     (0x1UL << CAN_F7R2_FB1_Pos)
#define CAN_F7R2_FB1                         CAN_F7R2_FB1_Msk
#define CAN_F7R2_FB2_Pos                     (2U)
#define CAN_F7R2_FB2_Msk                     (0x1UL << CAN_F7R2_FB2_Pos)
#define CAN_F7R2_FB2                         CAN_F7R2_FB2_Msk
#define CAN_F7R2_FB3_Pos                     (3U)
#define CAN_F7R2_FB3_Msk                     (0x1UL << CAN_F7R2_FB3_Pos)
#define CAN_F7R2_FB3                         CAN_F7R2_FB3_Msk
#define CAN_F7R2_FB4_Pos                     (4U)
#define CAN_F7R2_FB4_Msk                     (0x1UL << CAN_F7R2_FB4_Pos)
#define CAN_F7R2_FB4                         CAN_F7R2_FB4_Msk
#define CAN_F7R2_FB5_Pos                     (5U)
#define CAN_F7R2_FB5_Msk                     (0x1UL << CAN_F7R2_FB5_Pos)
#define CAN_F7R2_FB5                         CAN_F7R2_FB5_Msk
#define CAN_F7R2_FB6_Pos                     (6U)
#define CAN_F7R2_FB6_Msk                     (0x1UL << CAN_F7R2_FB6_Pos)
#define CAN_F7R2_FB6                         CAN_F7R2_FB6_Msk
#define CAN_F7R2_FB7_Pos                     (7U)
#define CAN_F7R2_FB7_Msk                     (0x1UL << CAN_F7R2_FB7_Pos)
#define CAN_F7R2_FB7                         CAN_F7R2_FB7_Msk
#define CAN_F7R2_FB8_Pos                     (8U)
#define CAN_F7R2_FB8_Msk                     (0x1UL << CAN_F7R2_FB8_Pos)
#define CAN_F7R2_FB8                         CAN_F7R2_FB8_Msk
#define CAN_F7R2_FB9_Pos                     (9U)
#define CAN_F7R2_FB9_Msk                     (0x1UL << CAN_F7R2_FB9_Pos)
#define CAN_F7R2_FB9                         CAN_F7R2_FB9_Msk
#define CAN_F7R2_FB10_Pos                    (10U)
#define CAN_F7R2_FB10_Msk                    (0x1UL << CAN_F7R2_FB10_Pos)
#define CAN_F7R2_FB10                        CAN_F7R2_FB10_Msk
#define CAN_F7R2_FB11_Pos                    (11U)
#define CAN_F7R2_FB11_Msk                    (0x1UL << CAN_F7R2_FB11_Pos)
#define CAN_F7R2_FB11                        CAN_F7R2_FB11_Msk
#define CAN_F7R2_FB12_Pos                    (12U)
#define CAN_F7R2_FB12_Msk                    (0x1UL << CAN_F7R2_FB12_Pos)
#define CAN_F7R2_FB12                        CAN_F7R2_FB12_Msk
#define CAN_F7R2_FB13_Pos                    (13U)
#define CAN_F7R2_FB13_Msk                    (0x1UL << CAN_F7R2_FB13_Pos)
#define CAN_F7R2_FB13                        CAN_F7R2_FB13_Msk
#define CAN_F7R2_FB14_Pos                    (14U)
#define CAN_F7R2_FB14_Msk                    (0x1UL << CAN_F7R2_FB14_Pos)
#define CAN_F7R2_FB14                        CAN_F7R2_FB14_Msk
#define CAN_F7R2_FB15_Pos                    (15U)
#define CAN_F7R2_FB15_Msk                    (0x1UL << CAN_F7R2_FB15_Pos)
#define CAN_F7R2_FB15                        CAN_F7R2_FB15_Msk
#define CAN_F7R2_FB16_Pos                    (16U)
#define CAN_F7R2_FB16_Msk                    (0x1UL << CAN_F7R2_FB16_Pos)
#define CAN_F7R2_FB16                        CAN_F7R2_FB16_Msk
#define CAN_F7R2_FB17_Pos                    (17U)
#define CAN_F7R2_FB17_Msk                    (0x1UL << CAN_F7R2_FB17_Pos)
#define CAN_F7R2_FB17                        CAN_F7R2_FB17_Msk
#define CAN_F7R2_FB18_Pos                    (18U)
#define CAN_F7R2_FB18_Msk                    (0x1UL << CAN_F7R2_FB18_Pos)
#define CAN_F7R2_FB18                        CAN_F7R2_FB18_Msk
#define CAN_F7R2_FB19_Pos                    (19U)
#define CAN_F7R2_FB19_Msk                    (0x1UL << CAN_F7R2_FB19_Pos)
#define CAN_F7R2_FB19                        CAN_F7R2_FB19_Msk
#define CAN_F7R2_FB20_Pos                    (20U)
#define CAN_F7R2_FB20_Msk                    (0x1UL << CAN_F7R2_FB20_Pos)
#define CAN_F7R2_FB20                        CAN_F7R2_FB20_Msk
#define CAN_F7R2_FB21_Pos                    (21U)
#define CAN_F7R2_FB21_Msk                    (0x1UL << CAN_F7R2_FB21_Pos)
#define CAN_F7R2_FB21                        CAN_F7R2_FB21_Msk
#define CAN_F7R2_FB22_Pos                    (22U)
#define CAN_F7R2_FB22_Msk                    (0x1UL << CAN_F7R2_FB22_Pos)
#define CAN_F7R2_FB22                        CAN_F7R2_FB22_Msk
#define CAN_F7R2_FB23_Pos                    (23U)
#define CAN_F7R2_FB23_Msk                    (0x1UL << CAN_F7R2_FB23_Pos)
#define CAN_F7R2_FB23                        CAN_F7R2_FB23_Msk
#define CAN_F7R2_FB24_Pos                    (24U)
#define CAN_F7R2_FB24_Msk                    (0x1UL << CAN_F7R2_FB24_Pos)
#define CAN_F7R2_FB24                        CAN_F7R2_FB24_Msk
#define CAN_F7R2_FB25_Pos                    (25U)
#define CAN_F7R2_FB25_Msk                    (0x1UL << CAN_F7R2_FB25_Pos)
#define CAN_F7R2_FB25                        CAN_F7R2_FB25_Msk
#define CAN_F7R2_FB26_Pos                    (26U)
#define CAN_F7R2_FB26_Msk                    (0x1UL << CAN_F7R2_FB26_Pos)
#define CAN_F7R2_FB26                        CAN_F7R2_FB26_Msk
#define CAN_F7R2_FB27_Pos                    (27U)
#define CAN_F7R2_FB27_Msk                    (0x1UL << CAN_F7R2_FB27_Pos)
#define CAN_F7R2_FB27                        CAN_F7R2_FB27_Msk
#define CAN_F7R2_FB28_Pos                    (28U)
#define CAN_F7R2_FB28_Msk                    (0x1UL << CAN_F7R2_FB28_Pos)
#define CAN_F7R2_FB28                        CAN_F7R2_FB28_Msk
#define CAN_F7R2_FB29_Pos                    (29U)
#define CAN_F7R2_FB29_Msk                    (0x1UL << CAN_F7R2_FB29_Pos)
#define CAN_F7R2_FB29                        CAN_F7R2_FB29_Msk
#define CAN_F7R2_FB30_Pos                    (30U)
#define CAN_F7R2_FB30_Msk                    (0x1UL << CAN_F7R2_FB30_Pos)
#define CAN_F7R2_FB30                        CAN_F7R2_FB30_Msk
#define CAN_F7R2_FB31_Pos                    (31U)
#define CAN_F7R2_FB31_Msk                    (0x1UL << CAN_F7R2_FB31_Pos)
#define CAN_F7R2_FB31                        CAN_F7R2_FB31_Msk

#define CAN_F8R2_FB0_Pos                     (0U)
#define CAN_F8R2_FB0_Msk                     (0x1UL << CAN_F8R2_FB0_Pos)
#define CAN_F8R2_FB0                         CAN_F8R2_FB0_Msk
#define CAN_F8R2_FB1_Pos                     (1U)
#define CAN_F8R2_FB1_Msk                     (0x1UL << CAN_F8R2_FB1_Pos)
#define CAN_F8R2_FB1                         CAN_F8R2_FB1_Msk
#define CAN_F8R2_FB2_Pos                     (2U)
#define CAN_F8R2_FB2_Msk                     (0x1UL << CAN_F8R2_FB2_Pos)
#define CAN_F8R2_FB2                         CAN_F8R2_FB2_Msk
#define CAN_F8R2_FB3_Pos                     (3U)
#define CAN_F8R2_FB3_Msk                     (0x1UL << CAN_F8R2_FB3_Pos)
#define CAN_F8R2_FB3                         CAN_F8R2_FB3_Msk
#define CAN_F8R2_FB4_Pos                     (4U)
#define CAN_F8R2_FB4_Msk                     (0x1UL << CAN_F8R2_FB4_Pos)
#define CAN_F8R2_FB4                         CAN_F8R2_FB4_Msk
#define CAN_F8R2_FB5_Pos                     (5U)
#define CAN_F8R2_FB5_Msk                     (0x1UL << CAN_F8R2_FB5_Pos)
#define CAN_F8R2_FB5                         CAN_F8R2_FB5_Msk
#define CAN_F8R2_FB6_Pos                     (6U)
#define CAN_F8R2_FB6_Msk                     (0x1UL << CAN_F8R2_FB6_Pos)
#define CAN_F8R2_FB6                         CAN_F8R2_FB6_Msk
#define CAN_F8R2_FB7_Pos                     (7U)
#define CAN_F8R2_FB7_Msk                     (0x1UL << CAN_F8R2_FB7_Pos)
#define CAN_F8R2_FB7                         CAN_F8R2_FB7_Msk
#define CAN_F8R2_FB8_Pos                     (8U)
#define CAN_F8R2_FB8_Msk                     (0x1UL << CAN_F8R2_FB8_Pos)
#define CAN_F8R2_FB8                         CAN_F8R2_FB8_Msk
#define CAN_F8R2_FB9_Pos                     (9U)
#define CAN_F8R2_FB9_Msk                     (0x1UL << CAN_F8R2_FB9_Pos)
#define CAN_F8R2_FB9                         CAN_F8R2_FB9_Msk
#define CAN_F8R2_FB10_Pos                    (10U)
#define CAN_F8R2_FB10_Msk                    (0x1UL << CAN_F8R2_FB10_Pos)
#define CAN_F8R2_FB10                        CAN_F8R2_FB10_Msk
#define CAN_F8R2_FB11_Pos                    (11U)
#define CAN_F8R2_FB11_Msk                    (0x1UL << CAN_F8R2_FB11_Pos)
#define CAN_F8R2_FB11                        CAN_F8R2_FB11_Msk
#define CAN_F8R2_FB12_Pos                    (12U)
#define CAN_F8R2_FB12_Msk                    (0x1UL << CAN_F8R2_FB12_Pos)
#define CAN_F8R2_FB12                        CAN_F8R2_FB12_Msk
#define CAN_F8R2_FB13_Pos                    (13U)
#define CAN_F8R2_FB13_Msk                    (0x1UL << CAN_F8R2_FB13_Pos)
#define CAN_F8R2_FB13                        CAN_F8R2_FB13_Msk
#define CAN_F8R2_FB14_Pos                    (14U)
#define CAN_F8R2_FB14_Msk                    (0x1UL << CAN_F8R2_FB14_Pos)
#define CAN_F8R2_FB14                        CAN_F8R2_FB14_Msk
#define CAN_F8R2_FB15_Pos                    (15U)
#define CAN_F8R2_FB15_Msk                    (0x1UL << CAN_F8R2_FB15_Pos)
#define CAN_F8R2_FB15                        CAN_F8R2_FB15_Msk
#define CAN_F8R2_FB16_Pos                    (16U)
#define CAN_F8R2_FB16_Msk                    (0x1UL << CAN_F8R2_FB16_Pos)
#define CAN_F8R2_FB16                        CAN_F8R2_FB16_Msk
#define CAN_F8R2_FB17_Pos                    (17U)
#define CAN_F8R2_FB17_Msk                    (0x1UL << CAN_F8R2_FB17_Pos)
#define CAN_F8R2_FB17                        CAN_F8R2_FB17_Msk
#define CAN_F8R2_FB18_Pos                    (18U)
#define CAN_F8R2_FB18_Msk                    (0x1UL << CAN_F8R2_FB18_Pos)
#define CAN_F8R2_FB18                        CAN_F8R2_FB18_Msk
#define CAN_F8R2_FB19_Pos                    (19U)
#define CAN_F8R2_FB19_Msk                    (0x1UL << CAN_F8R2_FB19_Pos)
#define CAN_F8R2_FB19                        CAN_F8R2_FB19_Msk
#define CAN_F8R2_FB20_Pos                    (20U)
#define CAN_F8R2_FB20_Msk                    (0x1UL << CAN_F8R2_FB20_Pos)
#define CAN_F8R2_FB20                        CAN_F8R2_FB20_Msk
#define CAN_F8R2_FB21_Pos                    (21U)
#define CAN_F8R2_FB21_Msk                    (0x1UL << CAN_F8R2_FB21_Pos)
#define CAN_F8R2_FB21                        CAN_F8R2_FB21_Msk
#define CAN_F8R2_FB22_Pos                    (22U)
#define CAN_F8R2_FB22_Msk                    (0x1UL << CAN_F8R2_FB22_Pos)
#define CAN_F8R2_FB22                        CAN_F8R2_FB22_Msk
#define CAN_F8R2_FB23_Pos                    (23U)
#define CAN_F8R2_FB23_Msk                    (0x1UL << CAN_F8R2_FB23_Pos)
#define CAN_F8R2_FB23                        CAN_F8R2_FB23_Msk
#define CAN_F8R2_FB24_Pos                    (24U)
#define CAN_F8R2_FB24_Msk                    (0x1UL << CAN_F8R2_FB24_Pos)
#define CAN_F8R2_FB24                        CAN_F8R2_FB24_Msk
#define CAN_F8R2_FB25_Pos                    (25U)
#define CAN_F8R2_FB25_Msk                    (0x1UL << CAN_F8R2_FB25_Pos)
#define CAN_F8R2_FB25                        CAN_F8R2_FB25_Msk
#define CAN_F8R2_FB26_Pos                    (26U)
#define CAN_F8R2_FB26_Msk                    (0x1UL << CAN_F8R2_FB26_Pos)
#define CAN_F8R2_FB26                        CAN_F8R2_FB26_Msk
#define CAN_F8R2_FB27_Pos                    (27U)
#define CAN_F8R2_FB27_Msk                    (0x1UL << CAN_F8R2_FB27_Pos)
#define CAN_F8R2_FB27                        CAN_F8R2_FB27_Msk
#define CAN_F8R2_FB28_Pos                    (28U)
#define CAN_F8R2_FB28_Msk                    (0x1UL << CAN_F8R2_FB28_Pos)
#define CAN_F8R2_FB28                        CAN_F8R2_FB28_Msk
#define CAN_F8R2_FB29_Pos                    (29U)
#define CAN_F8R2_FB29_Msk                    (0x1UL << CAN_F8R2_FB29_Pos)
#define CAN_F8R2_FB29                        CAN_F8R2_FB29_Msk
#define CAN_F8R2_FB30_Pos                    (30U)
#define CAN_F8R2_FB30_Msk                    (0x1UL << CAN_F8R2_FB30_Pos)
#define CAN_F8R2_FB30                        CAN_F8R2_FB30_Msk
#define CAN_F8R2_FB31_Pos                    (31U)
#define CAN_F8R2_FB31_Msk                    (0x1UL << CAN_F8R2_FB31_Pos)
#define CAN_F8R2_FB31                        CAN_F8R2_FB31_Msk

#define CAN_F9R2_FB0_Pos                     (0U)
#define CAN_F9R2_FB0_Msk                     (0x1UL << CAN_F9R2_FB0_Pos)
#define CAN_F9R2_FB0                         CAN_F9R2_FB0_Msk
#define CAN_F9R2_FB1_Pos                     (1U)
#define CAN_F9R2_FB1_Msk                     (0x1UL << CAN_F9R2_FB1_Pos)
#define CAN_F9R2_FB1                         CAN_F9R2_FB1_Msk
#define CAN_F9R2_FB2_Pos                     (2U)
#define CAN_F9R2_FB2_Msk                     (0x1UL << CAN_F9R2_FB2_Pos)
#define CAN_F9R2_FB2                         CAN_F9R2_FB2_Msk
#define CAN_F9R2_FB3_Pos                     (3U)
#define CAN_F9R2_FB3_Msk                     (0x1UL << CAN_F9R2_FB3_Pos)
#define CAN_F9R2_FB3                         CAN_F9R2_FB3_Msk
#define CAN_F9R2_FB4_Pos                     (4U)
#define CAN_F9R2_FB4_Msk                     (0x1UL << CAN_F9R2_FB4_Pos)
#define CAN_F9R2_FB4                         CAN_F9R2_FB4_Msk
#define CAN_F9R2_FB5_Pos                     (5U)
#define CAN_F9R2_FB5_Msk                     (0x1UL << CAN_F9R2_FB5_Pos)
#define CAN_F9R2_FB5                         CAN_F9R2_FB5_Msk
#define CAN_F9R2_FB6_Pos                     (6U)
#define CAN_F9R2_FB6_Msk                     (0x1UL << CAN_F9R2_FB6_Pos)
#define CAN_F9R2_FB6                         CAN_F9R2_FB6_Msk
#define CAN_F9R2_FB7_Pos                     (7U)
#define CAN_F9R2_FB7_Msk                     (0x1UL << CAN_F9R2_FB7_Pos)
#define CAN_F9R2_FB7                         CAN_F9R2_FB7_Msk
#define CAN_F9R2_FB8_Pos                     (8U)
#define CAN_F9R2_FB8_Msk                     (0x1UL << CAN_F9R2_FB8_Pos)
#define CAN_F9R2_FB8                         CAN_F9R2_FB8_Msk
#define CAN_F9R2_FB9_Pos                     (9U)
#define CAN_F9R2_FB9_Msk                     (0x1UL << CAN_F9R2_FB9_Pos)
#define CAN_F9R2_FB9                         CAN_F9R2_FB9_Msk
#define CAN_F9R2_FB10_Pos                    (10U)
#define CAN_F9R2_FB10_Msk                    (0x1UL << CAN_F9R2_FB10_Pos)
#define CAN_F9R2_FB10                        CAN_F9R2_FB10_Msk
#define CAN_F9R2_FB11_Pos                    (11U)
#define CAN_F9R2_FB11_Msk                    (0x1UL << CAN_F9R2_FB11_Pos)
#define CAN_F9R2_FB11                        CAN_F9R2_FB11_Msk
#define CAN_F9R2_FB12_Pos                    (12U)
#define CAN_F9R2_FB12_Msk                    (0x1UL << CAN_F9R2_FB12_Pos)
#define CAN_F9R2_FB12                        CAN_F9R2_FB12_Msk
#define CAN_F9R2_FB13_Pos                    (13U)
#define CAN_F9R2_FB13_Msk                    (0x1UL << CAN_F9R2_FB13_Pos)
#define CAN_F9R2_FB13                        CAN_F9R2_FB13_Msk
#define CAN_F9R2_FB14_Pos                    (14U)
#define CAN_F9R2_FB14_Msk                    (0x1UL << CAN_F9R2_FB14_Pos)
#define CAN_F9R2_FB14                        CAN_F9R2_FB14_Msk
#define CAN_F9R2_FB15_Pos                    (15U)
#define CAN_F9R2_FB15_Msk                    (0x1UL << CAN_F9R2_FB15_Pos)
#define CAN_F9R2_FB15                        CAN_F9R2_FB15_Msk
#define CAN_F9R2_FB16_Pos                    (16U)
#define CAN_F9R2_FB16_Msk                    (0x1UL << CAN_F9R2_FB16_Pos)
#define CAN_F9R2_FB16                        CAN_F9R2_FB16_Msk
#define CAN_F9R2_FB17_Pos                    (17U)
#define CAN_F9R2_FB17_Msk                    (0x1UL << CAN_F9R2_FB17_Pos)
#define CAN_F9R2_FB17                        CAN_F9R2_FB17_Msk
#define CAN_F9R2_FB18_Pos                    (18U)
#define CAN_F9R2_FB18_Msk                    (0x1UL << CAN_F9R2_FB18_Pos)
#define CAN_F9R2_FB18                        CAN_F9R2_FB18_Msk
#define CAN_F9R2_FB19_Pos                    (19U)
#define CAN_F9R2_FB19_Msk                    (0x1UL << CAN_F9R2_FB19_Pos)
#define CAN_F9R2_FB19                        CAN_F9R2_FB19_Msk
#define CAN_F9R2_FB20_Pos                    (20U)
#define CAN_F9R2_FB20_Msk                    (0x1UL << CAN_F9R2_FB20_Pos)
#define CAN_F9R2_FB20                        CAN_F9R2_FB20_Msk
#define CAN_F9R2_FB21_Pos                    (21U)
#define CAN_F9R2_FB21_Msk                    (0x1UL << CAN_F9R2_FB21_Pos)
#define CAN_F9R2_FB21                        CAN_F9R2_FB21_Msk
#define CAN_F9R2_FB22_Pos                    (22U)
#define CAN_F9R2_FB22_Msk                    (0x1UL << CAN_F9R2_FB22_Pos)
#define CAN_F9R2_FB22                        CAN_F9R2_FB22_Msk
#define CAN_F9R2_FB23_Pos                    (23U)
#define CAN_F9R2_FB23_Msk                    (0x1UL << CAN_F9R2_FB23_Pos)
#define CAN_F9R2_FB23                        CAN_F9R2_FB23_Msk
#define CAN_F9R2_FB24_Pos                    (24U)
#define CAN_F9R2_FB24_Msk                    (0x1UL << CAN_F9R2_FB24_Pos)
#define CAN_F9R2_FB24                        CAN_F9R2_FB24_Msk
#define CAN_F9R2_FB25_Pos                    (25U)
#define CAN_F9R2_FB25_Msk                    (0x1UL << CAN_F9R2_FB25_Pos)
#define CAN_F9R2_FB25                        CAN_F9R2_FB25_Msk
#define CAN_F9R2_FB26_Pos                    (26U)
#define CAN_F9R2_FB26_Msk                    (0x1UL << CAN_F9R2_FB26_Pos)
#define CAN_F9R2_FB26                        CAN_F9R2_FB26_Msk
#define CAN_F9R2_FB27_Pos                    (27U)
#define CAN_F9R2_FB27_Msk                    (0x1UL << CAN_F9R2_FB27_Pos)
#define CAN_F9R2_FB27                        CAN_F9R2_FB27_Msk
#define CAN_F9R2_FB28_Pos                    (28U)
#define CAN_F9R2_FB28_Msk                    (0x1UL << CAN_F9R2_FB28_Pos)
#define CAN_F9R2_FB28                        CAN_F9R2_FB28_Msk
#define CAN_F9R2_FB29_Pos                    (29U)
#define CAN_F9R2_FB29_Msk                    (0x1UL << CAN_F9R2_FB29_Pos)
#define CAN_F9R2_FB29                        CAN_F9R2_FB29_Msk
#define CAN_F9R2_FB30_Pos                    (30U)
#define CAN_F9R2_FB30_Msk                    (0x1UL << CAN_F9R2_FB30_Pos)
#define CAN_F9R2_FB30                        CAN_F9R2_FB30_Msk
#define CAN_F9R2_FB31_Pos                    (31U)
#define CAN_F9R2_FB31_Msk                    (0x1UL << CAN_F9R2_FB31_Pos)
#define CAN_F9R2_FB31                        CAN_F9R2_FB31_Msk

#define CAN_F10R2_FB0_Pos                    (0U)
#define CAN_F10R2_FB0_Msk                    (0x1UL << CAN_F10R2_FB0_Pos)
#define CAN_F10R2_FB0                        CAN_F10R2_FB0_Msk
#define CAN_F10R2_FB1_Pos                    (1U)
#define CAN_F10R2_FB1_Msk                    (0x1UL << CAN_F10R2_FB1_Pos)
#define CAN_F10R2_FB1                        CAN_F10R2_FB1_Msk
#define CAN_F10R2_FB2_Pos                    (2U)
#define CAN_F10R2_FB2_Msk                    (0x1UL << CAN_F10R2_FB2_Pos)
#define CAN_F10R2_FB2                        CAN_F10R2_FB2_Msk
#define CAN_F10R2_FB3_Pos                    (3U)
#define CAN_F10R2_FB3_Msk                    (0x1UL << CAN_F10R2_FB3_Pos)
#define CAN_F10R2_FB3                        CAN_F10R2_FB3_Msk
#define CAN_F10R2_FB4_Pos                    (4U)
#define CAN_F10R2_FB4_Msk                    (0x1UL << CAN_F10R2_FB4_Pos)
#define CAN_F10R2_FB4                        CAN_F10R2_FB4_Msk
#define CAN_F10R2_FB5_Pos                    (5U)
#define CAN_F10R2_FB5_Msk                    (0x1UL << CAN_F10R2_FB5_Pos)
#define CAN_F10R2_FB5                        CAN_F10R2_FB5_Msk
#define CAN_F10R2_FB6_Pos                    (6U)
#define CAN_F10R2_FB6_Msk                    (0x1UL << CAN_F10R2_FB6_Pos)
#define CAN_F10R2_FB6                        CAN_F10R2_FB6_Msk
#define CAN_F10R2_FB7_Pos                    (7U)
#define CAN_F10R2_FB7_Msk                    (0x1UL << CAN_F10R2_FB7_Pos)
#define CAN_F10R2_FB7                        CAN_F10R2_FB7_Msk
#define CAN_F10R2_FB8_Pos                    (8U)
#define CAN_F10R2_FB8_Msk                    (0x1UL << CAN_F10R2_FB8_Pos)
#define CAN_F10R2_FB8                        CAN_F10R2_FB8_Msk
#define CAN_F10R2_FB9_Pos                    (9U)
#define CAN_F10R2_FB9_Msk                    (0x1UL << CAN_F10R2_FB9_Pos)
#define CAN_F10R2_FB9                        CAN_F10R2_FB9_Msk
#define CAN_F10R2_FB10_Pos                   (10U)
#define CAN_F10R2_FB10_Msk                   (0x1UL << CAN_F10R2_FB10_Pos)
#define CAN_F10R2_FB10                       CAN_F10R2_FB10_Msk
#define CAN_F10R2_FB11_Pos                   (11U)
#define CAN_F10R2_FB11_Msk                   (0x1UL << CAN_F10R2_FB11_Pos)
#define CAN_F10R2_FB11                       CAN_F10R2_FB11_Msk
#define CAN_F10R2_FB12_Pos                   (12U)
#define CAN_F10R2_FB12_Msk                   (0x1UL << CAN_F10R2_FB12_Pos)
#define CAN_F10R2_FB12                       CAN_F10R2_FB12_Msk
#define CAN_F10R2_FB13_Pos                   (13U)
#define CAN_F10R2_FB13_Msk                   (0x1UL << CAN_F10R2_FB13_Pos)
#define CAN_F10R2_FB13                       CAN_F10R2_FB13_Msk
#define CAN_F10R2_FB14_Pos                   (14U)
#define CAN_F10R2_FB14_Msk                   (0x1UL << CAN_F10R2_FB14_Pos)
#define CAN_F10R2_FB14                       CAN_F10R2_FB14_Msk
#define CAN_F10R2_FB15_Pos                   (15U)
#define CAN_F10R2_FB15_Msk                   (0x1UL << CAN_F10R2_FB15_Pos)
#define CAN_F10R2_FB15                       CAN_F10R2_FB15_Msk
#define CAN_F10R2_FB16_Pos                   (16U)
#define CAN_F10R2_FB16_Msk                   (0x1UL << CAN_F10R2_FB16_Pos)
#define CAN_F10R2_FB16                       CAN_F10R2_FB16_Msk
#define CAN_F10R2_FB17_Pos                   (17U)
#define CAN_F10R2_FB17_Msk                   (0x1UL << CAN_F10R2_FB17_Pos)
#define CAN_F10R2_FB17                       CAN_F10R2_FB17_Msk
#define CAN_F10R2_FB18_Pos                   (18U)
#define CAN_F10R2_FB18_Msk                   (0x1UL << CAN_F10R2_FB18_Pos)
#define CAN_F10R2_FB18                       CAN_F10R2_FB18_Msk
#define CAN_F10R2_FB19_Pos                   (19U)
#define CAN_F10R2_FB19_Msk                   (0x1UL << CAN_F10R2_FB19_Pos)
#define CAN_F10R2_FB19                       CAN_F10R2_FB19_Msk
#define CAN_F10R2_FB20_Pos                   (20U)
#define CAN_F10R2_FB20_Msk                   (0x1UL << CAN_F10R2_FB20_Pos)
#define CAN_F10R2_FB20                       CAN_F10R2_FB20_Msk
#define CAN_F10R2_FB21_Pos                   (21U)
#define CAN_F10R2_FB21_Msk                   (0x1UL << CAN_F10R2_FB21_Pos)
#define CAN_F10R2_FB21                       CAN_F10R2_FB21_Msk
#define CAN_F10R2_FB22_Pos                   (22U)
#define CAN_F10R2_FB22_Msk                   (0x1UL << CAN_F10R2_FB22_Pos)
#define CAN_F10R2_FB22                       CAN_F10R2_FB22_Msk
#define CAN_F10R2_FB23_Pos                   (23U)
#define CAN_F10R2_FB23_Msk                   (0x1UL << CAN_F10R2_FB23_Pos)
#define CAN_F10R2_FB23                       CAN_F10R2_FB23_Msk
#define CAN_F10R2_FB24_Pos                   (24U)
#define CAN_F10R2_FB24_Msk                   (0x1UL << CAN_F10R2_FB24_Pos)
#define CAN_F10R2_FB24                       CAN_F10R2_FB24_Msk
#define CAN_F10R2_FB25_Pos                   (25U)
#define CAN_F10R2_FB25_Msk                   (0x1UL << CAN_F10R2_FB25_Pos)
#define CAN_F10R2_FB25                       CAN_F10R2_FB25_Msk
#define CAN_F10R2_FB26_Pos                   (26U)
#define CAN_F10R2_FB26_Msk                   (0x1UL << CAN_F10R2_FB26_Pos)
#define CAN_F10R2_FB26                       CAN_F10R2_FB26_Msk
#define CAN_F10R2_FB27_Pos                   (27U)
#define CAN_F10R2_FB27_Msk                   (0x1UL << CAN_F10R2_FB27_Pos)
#define CAN_F10R2_FB27                       CAN_F10R2_FB27_Msk
#define CAN_F10R2_FB28_Pos                   (28U)
#define CAN_F10R2_FB28_Msk                   (0x1UL << CAN_F10R2_FB28_Pos)
#define CAN_F10R2_FB28                       CAN_F10R2_FB28_Msk
#define CAN_F10R2_FB29_Pos                   (29U)
#define CAN_F10R2_FB29_Msk                   (0x1UL << CAN_F10R2_FB29_Pos)
#define CAN_F10R2_FB29                       CAN_F10R2_FB29_Msk
#define CAN_F10R2_FB30_Pos                   (30U)
#define CAN_F10R2_FB30_Msk                   (0x1UL << CAN_F10R2_FB30_Pos)
#define CAN_F10R2_FB30                       CAN_F10R2_FB30_Msk
#define CAN_F10R2_FB31_Pos                   (31U)
#define CAN_F10R2_FB31_Msk                   (0x1UL << CAN_F10R2_FB31_Pos)
#define CAN_F10R2_FB31                       CAN_F10R2_FB31_Msk

#define CAN_F11R2_FB0_Pos                    (0U)
#define CAN_F11R2_FB0_Msk                    (0x1UL << CAN_F11R2_FB0_Pos)
#define CAN_F11R2_FB0                        CAN_F11R2_FB0_Msk
#define CAN_F11R2_FB1_Pos                    (1U)
#define CAN_F11R2_FB1_Msk                    (0x1UL << CAN_F11R2_FB1_Pos)
#define CAN_F11R2_FB1                        CAN_F11R2_FB1_Msk
#define CAN_F11R2_FB2_Pos                    (2U)
#define CAN_F11R2_FB2_Msk                    (0x1UL << CAN_F11R2_FB2_Pos)
#define CAN_F11R2_FB2                        CAN_F11R2_FB2_Msk
#define CAN_F11R2_FB3_Pos                    (3U)
#define CAN_F11R2_FB3_Msk                    (0x1UL << CAN_F11R2_FB3_Pos)
#define CAN_F11R2_FB3                        CAN_F11R2_FB3_Msk
#define CAN_F11R2_FB4_Pos                    (4U)
#define CAN_F11R2_FB4_Msk                    (0x1UL << CAN_F11R2_FB4_Pos)
#define CAN_F11R2_FB4                        CAN_F11R2_FB4_Msk
#define CAN_F11R2_FB5_Pos                    (5U)
#define CAN_F11R2_FB5_Msk                    (0x1UL << CAN_F11R2_FB5_Pos)
#define CAN_F11R2_FB5                        CAN_F11R2_FB5_Msk
#define CAN_F11R2_FB6_Pos                    (6U)
#define CAN_F11R2_FB6_Msk                    (0x1UL << CAN_F11R2_FB6_Pos)
#define CAN_F11R2_FB6                        CAN_F11R2_FB6_Msk
#define CAN_F11R2_FB7_Pos                    (7U)
#define CAN_F11R2_FB7_Msk                    (0x1UL << CAN_F11R2_FB7_Pos)
#define CAN_F11R2_FB7                        CAN_F11R2_FB7_Msk
#define CAN_F11R2_FB8_Pos                    (8U)
#define CAN_F11R2_FB8_Msk                    (0x1UL << CAN_F11R2_FB8_Pos)
#define CAN_F11R2_FB8                        CAN_F11R2_FB8_Msk
#define CAN_F11R2_FB9_Pos                    (9U)
#define CAN_F11R2_FB9_Msk                    (0x1UL << CAN_F11R2_FB9_Pos)
#define CAN_F11R2_FB9                        CAN_F11R2_FB9_Msk
#define CAN_F11R2_FB10_Pos                   (10U)
#define CAN_F11R2_FB10_Msk                   (0x1UL << CAN_F11R2_FB10_Pos)
#define CAN_F11R2_FB10                       CAN_F11R2_FB10_Msk
#define CAN_F11R2_FB11_Pos                   (11U)
#define CAN_F11R2_FB11_Msk                   (0x1UL << CAN_F11R2_FB11_Pos)
#define CAN_F11R2_FB11                       CAN_F11R2_FB11_Msk
#define CAN_F11R2_FB12_Pos                   (12U)
#define CAN_F11R2_FB12_Msk                   (0x1UL << CAN_F11R2_FB12_Pos)
#define CAN_F11R2_FB12                       CAN_F11R2_FB12_Msk
#define CAN_F11R2_FB13_Pos                   (13U)
#define CAN_F11R2_FB13_Msk                   (0x1UL << CAN_F11R2_FB13_Pos)
#define CAN_F11R2_FB13                       CAN_F11R2_FB13_Msk
#define CAN_F11R2_FB14_Pos                   (14U)
#define CAN_F11R2_FB14_Msk                   (0x1UL << CAN_F11R2_FB14_Pos)
#define CAN_F11R2_FB14                       CAN_F11R2_FB14_Msk
#define CAN_F11R2_FB15_Pos                   (15U)
#define CAN_F11R2_FB15_Msk                   (0x1UL << CAN_F11R2_FB15_Pos)
#define CAN_F11R2_FB15                       CAN_F11R2_FB15_Msk
#define CAN_F11R2_FB16_Pos                   (16U)
#define CAN_F11R2_FB16_Msk                   (0x1UL << CAN_F11R2_FB16_Pos)
#define CAN_F11R2_FB16                       CAN_F11R2_FB16_Msk
#define CAN_F11R2_FB17_Pos                   (17U)
#define CAN_F11R2_FB17_Msk                   (0x1UL << CAN_F11R2_FB17_Pos)
#define CAN_F11R2_FB17                       CAN_F11R2_FB17_Msk
#define CAN_F11R2_FB18_Pos                   (18U)
#define CAN_F11R2_FB18_Msk                   (0x1UL << CAN_F11R2_FB18_Pos)
#define CAN_F11R2_FB18                       CAN_F11R2_FB18_Msk
#define CAN_F11R2_FB19_Pos                   (19U)
#define CAN_F11R2_FB19_Msk                   (0x1UL << CAN_F11R2_FB19_Pos)
#define CAN_F11R2_FB19                       CAN_F11R2_FB19_Msk
#define CAN_F11R2_FB20_Pos                   (20U)
#define CAN_F11R2_FB20_Msk                   (0x1UL << CAN_F11R2_FB20_Pos)
#define CAN_F11R2_FB20                       CAN_F11R2_FB20_Msk
#define CAN_F11R2_FB21_Pos                   (21U)
#define CAN_F11R2_FB21_Msk                   (0x1UL << CAN_F11R2_FB21_Pos)
#define CAN_F11R2_FB21                       CAN_F11R2_FB21_Msk
#define CAN_F11R2_FB22_Pos                   (22U)
#define CAN_F11R2_FB22_Msk                   (0x1UL << CAN_F11R2_FB22_Pos)
#define CAN_F11R2_FB22                       CAN_F11R2_FB22_Msk
#define CAN_F11R2_FB23_Pos                   (23U)
#define CAN_F11R2_FB23_Msk                   (0x1UL << CAN_F11R2_FB23_Pos)
#define CAN_F11R2_FB23                       CAN_F11R2_FB23_Msk
#define CAN_F11R2_FB24_Pos                   (24U)
#define CAN_F11R2_FB24_Msk                   (0x1UL << CAN_F11R2_FB24_Pos)
#define CAN_F11R2_FB24                       CAN_F11R2_FB24_Msk
#define CAN_F11R2_FB25_Pos                   (25U)
#define CAN_F11R2_FB25_Msk                   (0x1UL << CAN_F11R2_FB25_Pos)
#define CAN_F11R2_FB25                       CAN_F11R2_FB25_Msk
#define CAN_F11R2_FB26_Pos                   (26U)
#define CAN_F11R2_FB26_Msk                   (0x1UL << CAN_F11R2_FB26_Pos)
#define CAN_F11R2_FB26                       CAN_F11R2_FB26_Msk
#define CAN_F11R2_FB27_Pos                   (27U)
#define CAN_F11R2_FB27_Msk                   (0x1UL << CAN_F11R2_FB27_Pos)
#define CAN_F11R2_FB27                       CAN_F11R2_FB27_Msk
#define CAN_F11R2_FB28_Pos                   (28U)
#define CAN_F11R2_FB28_Msk                   (0x1UL << CAN_F11R2_FB28_Pos)
#define CAN_F11R2_FB28                       CAN_F11R2_FB28_Msk
#define CAN_F11R2_FB29_Pos                   (29U)
#define CAN_F11R2_FB29_Msk                   (0x1UL << CAN_F11R2_FB29_Pos)
#define CAN_F11R2_FB29                       CAN_F11R2_FB29_Msk
#define CAN_F11R2_FB30_Pos                   (30U)
#define CAN_F11R2_FB30_Msk                   (0x1UL << CAN_F11R2_FB30_Pos)
#define CAN_F11R2_FB30                       CAN_F11R2_FB30_Msk
#define CAN_F11R2_FB31_Pos                   (31U)
#define CAN_F11R2_FB31_Msk                   (0x1UL << CAN_F11R2_FB31_Pos)
#define CAN_F11R2_FB31                       CAN_F11R2_FB31_Msk

#define CAN_F12R2_FB0_Pos                    (0U)
#define CAN_F12R2_FB0_Msk                    (0x1UL << CAN_F12R2_FB0_Pos)
#define CAN_F12R2_FB0                        CAN_F12R2_FB0_Msk
#define CAN_F12R2_FB1_Pos                    (1U)
#define CAN_F12R2_FB1_Msk                    (0x1UL << CAN_F12R2_FB1_Pos)
#define CAN_F12R2_FB1                        CAN_F12R2_FB1_Msk
#define CAN_F12R2_FB2_Pos                    (2U)
#define CAN_F12R2_FB2_Msk                    (0x1UL << CAN_F12R2_FB2_Pos)
#define CAN_F12R2_FB2                        CAN_F12R2_FB2_Msk
#define CAN_F12R2_FB3_Pos                    (3U)
#define CAN_F12R2_FB3_Msk                    (0x1UL << CAN_F12R2_FB3_Pos)
#define CAN_F12R2_FB3                        CAN_F12R2_FB3_Msk
#define CAN_F12R2_FB4_Pos                    (4U)
#define CAN_F12R2_FB4_Msk                    (0x1UL << CAN_F12R2_FB4_Pos)
#define CAN_F12R2_FB4                        CAN_F12R2_FB4_Msk
#define CAN_F12R2_FB5_Pos                    (5U)
#define CAN_F12R2_FB5_Msk                    (0x1UL << CAN_F12R2_FB5_Pos)
#define CAN_F12R2_FB5                        CAN_F12R2_FB5_Msk
#define CAN_F12R2_FB6_Pos                    (6U)
#define CAN_F12R2_FB6_Msk                    (0x1UL << CAN_F12R2_FB6_Pos)
#define CAN_F12R2_FB6                        CAN_F12R2_FB6_Msk
#define CAN_F12R2_FB7_Pos                    (7U)
#define CAN_F12R2_FB7_Msk                    (0x1UL << CAN_F12R2_FB7_Pos)
#define CAN_F12R2_FB7                        CAN_F12R2_FB7_Msk
#define CAN_F12R2_FB8_Pos                    (8U)
#define CAN_F12R2_FB8_Msk                    (0x1UL << CAN_F12R2_FB8_Pos)
#define CAN_F12R2_FB8                        CAN_F12R2_FB8_Msk
#define CAN_F12R2_FB9_Pos                    (9U)
#define CAN_F12R2_FB9_Msk                    (0x1UL << CAN_F12R2_FB9_Pos)
#define CAN_F12R2_FB9                        CAN_F12R2_FB9_Msk
#define CAN_F12R2_FB10_Pos                   (10U)
#define CAN_F12R2_FB10_Msk                   (0x1UL << CAN_F12R2_FB10_Pos)
#define CAN_F12R2_FB10                       CAN_F12R2_FB10_Msk
#define CAN_F12R2_FB11_Pos                   (11U)
#define CAN_F12R2_FB11_Msk                   (0x1UL << CAN_F12R2_FB11_Pos)
#define CAN_F12R2_FB11                       CAN_F12R2_FB11_Msk
#define CAN_F12R2_FB12_Pos                   (12U)
#define CAN_F12R2_FB12_Msk                   (0x1UL << CAN_F12R2_FB12_Pos)
#define CAN_F12R2_FB12                       CAN_F12R2_FB12_Msk
#define CAN_F12R2_FB13_Pos                   (13U)
#define CAN_F12R2_FB13_Msk                   (0x1UL << CAN_F12R2_FB13_Pos)
#define CAN_F12R2_FB13                       CAN_F12R2_FB13_Msk
#define CAN_F12R2_FB14_Pos                   (14U)
#define CAN_F12R2_FB14_Msk                   (0x1UL << CAN_F12R2_FB14_Pos)
#define CAN_F12R2_FB14                       CAN_F12R2_FB14_Msk
#define CAN_F12R2_FB15_Pos                   (15U)
#define CAN_F12R2_FB15_Msk                   (0x1UL << CAN_F12R2_FB15_Pos)
#define CAN_F12R2_FB15                       CAN_F12R2_FB15_Msk
#define CAN_F12R2_FB16_Pos                   (16U)
#define CAN_F12R2_FB16_Msk                   (0x1UL << CAN_F12R2_FB16_Pos)
#define CAN_F12R2_FB16                       CAN_F12R2_FB16_Msk
#define CAN_F12R2_FB17_Pos                   (17U)
#define CAN_F12R2_FB17_Msk                   (0x1UL << CAN_F12R2_FB17_Pos)
#define CAN_F12R2_FB17                       CAN_F12R2_FB17_Msk
#define CAN_F12R2_FB18_Pos                   (18U)
#define CAN_F12R2_FB18_Msk                   (0x1UL << CAN_F12R2_FB18_Pos)
#define CAN_F12R2_FB18                       CAN_F12R2_FB18_Msk
#define CAN_F12R2_FB19_Pos                   (19U)
#define CAN_F12R2_FB19_Msk                   (0x1UL << CAN_F12R2_FB19_Pos)
#define CAN_F12R2_FB19                       CAN_F12R2_FB19_Msk
#define CAN_F12R2_FB20_Pos                   (20U)
#define CAN_F12R2_FB20_Msk                   (0x1UL << CAN_F12R2_FB20_Pos)
#define CAN_F12R2_FB20                       CAN_F12R2_FB20_Msk
#define CAN_F12R2_FB21_Pos                   (21U)
#define CAN_F12R2_FB21_Msk                   (0x1UL << CAN_F12R2_FB21_Pos)
#define CAN_F12R2_FB21                       CAN_F12R2_FB21_Msk
#define CAN_F12R2_FB22_Pos                   (22U)
#define CAN_F12R2_FB22_Msk                   (0x1UL << CAN_F12R2_FB22_Pos)
#define CAN_F12R2_FB22                       CAN_F12R2_FB22_Msk
#define CAN_F12R2_FB23_Pos                   (23U)
#define CAN_F12R2_FB23_Msk                   (0x1UL << CAN_F12R2_FB23_Pos)
#define CAN_F12R2_FB23                       CAN_F12R2_FB23_Msk
#define CAN_F12R2_FB24_Pos                   (24U)
#define CAN_F12R2_FB24_Msk                   (0x1UL << CAN_F12R2_FB24_Pos)
#define CAN_F12R2_FB24                       CAN_F12R2_FB24_Msk
#define CAN_F12R2_FB25_Pos                   (25U)
#define CAN_F12R2_FB25_Msk                   (0x1UL << CAN_F12R2_FB25_Pos)
#define CAN_F12R2_FB25                       CAN_F12R2_FB25_Msk
#define CAN_F12R2_FB26_Pos                   (26U)
#define CAN_F12R2_FB26_Msk                   (0x1UL << CAN_F12R2_FB26_Pos)
#define CAN_F12R2_FB26                       CAN_F12R2_FB26_Msk
#define CAN_F12R2_FB27_Pos                   (27U)
#define CAN_F12R2_FB27_Msk                   (0x1UL << CAN_F12R2_FB27_Pos)
#define CAN_F12R2_FB27                       CAN_F12R2_FB27_Msk
#define CAN_F12R2_FB28_Pos                   (28U)
#define CAN_F12R2_FB28_Msk                   (0x1UL << CAN_F12R2_FB28_Pos)
#define CAN_F12R2_FB28                       CAN_F12R2_FB28_Msk
#define CAN_F12R2_FB29_Pos                   (29U)
#define CAN_F12R2_FB29_Msk                   (0x1UL << CAN_F12R2_FB29_Pos)
#define CAN_F12R2_FB29                       CAN_F12R2_FB29_Msk
#define CAN_F12R2_FB30_Pos                   (30U)
#define CAN_F12R2_FB30_Msk                   (0x1UL << CAN_F12R2_FB30_Pos)
#define CAN_F12R2_FB30                       CAN_F12R2_FB30_Msk
#define CAN_F12R2_FB31_Pos                   (31U)
#define CAN_F12R2_FB31_Msk                   (0x1UL << CAN_F12R2_FB31_Pos)
#define CAN_F12R2_FB31                       CAN_F12R2_FB31_Msk

#define CAN_F13R2_FB0_Pos                    (0U)
#define CAN_F13R2_FB0_Msk                    (0x1UL << CAN_F13R2_FB0_Pos)
#define CAN_F13R2_FB0                        CAN_F13R2_FB0_Msk
#define CAN_F13R2_FB1_Pos                    (1U)
#define CAN_F13R2_FB1_Msk                    (0x1UL << CAN_F13R2_FB1_Pos)
#define CAN_F13R2_FB1                        CAN_F13R2_FB1_Msk
#define CAN_F13R2_FB2_Pos                    (2U)
#define CAN_F13R2_FB2_Msk                    (0x1UL << CAN_F13R2_FB2_Pos)
#define CAN_F13R2_FB2                        CAN_F13R2_FB2_Msk
#define CAN_F13R2_FB3_Pos                    (3U)
#define CAN_F13R2_FB3_Msk                    (0x1UL << CAN_F13R2_FB3_Pos)
#define CAN_F13R2_FB3                        CAN_F13R2_FB3_Msk
#define CAN_F13R2_FB4_Pos                    (4U)
#define CAN_F13R2_FB4_Msk                    (0x1UL << CAN_F13R2_FB4_Pos)
#define CAN_F13R2_FB4                        CAN_F13R2_FB4_Msk
#define CAN_F13R2_FB5_Pos                    (5U)
#define CAN_F13R2_FB5_Msk                    (0x1UL << CAN_F13R2_FB5_Pos)
#define CAN_F13R2_FB5                        CAN_F13R2_FB5_Msk
#define CAN_F13R2_FB6_Pos                    (6U)
#define CAN_F13R2_FB6_Msk                    (0x1UL << CAN_F13R2_FB6_Pos)
#define CAN_F13R2_FB6                        CAN_F13R2_FB6_Msk
#define CAN_F13R2_FB7_Pos                    (7U)
#define CAN_F13R2_FB7_Msk                    (0x1UL << CAN_F13R2_FB7_Pos)
#define CAN_F13R2_FB7                        CAN_F13R2_FB7_Msk
#define CAN_F13R2_FB8_Pos                    (8U)
#define CAN_F13R2_FB8_Msk                    (0x1UL << CAN_F13R2_FB8_Pos)
#define CAN_F13R2_FB8                        CAN_F13R2_FB8_Msk
#define CAN_F13R2_FB9_Pos                    (9U)
#define CAN_F13R2_FB9_Msk                    (0x1UL << CAN_F13R2_FB9_Pos)
#define CAN_F13R2_FB9                        CAN_F13R2_FB9_Msk
#define CAN_F13R2_FB10_Pos                   (10U)
#define CAN_F13R2_FB10_Msk                   (0x1UL << CAN_F13R2_FB10_Pos)
#define CAN_F13R2_FB10                       CAN_F13R2_FB10_Msk
#define CAN_F13R2_FB11_Pos                   (11U)
#define CAN_F13R2_FB11_Msk                   (0x1UL << CAN_F13R2_FB11_Pos)
#define CAN_F13R2_FB11                       CAN_F13R2_FB11_Msk
#define CAN_F13R2_FB12_Pos                   (12U)
#define CAN_F13R2_FB12_Msk                   (0x1UL << CAN_F13R2_FB12_Pos)
#define CAN_F13R2_FB12                       CAN_F13R2_FB12_Msk
#define CAN_F13R2_FB13_Pos                   (13U)
#define CAN_F13R2_FB13_Msk                   (0x1UL << CAN_F13R2_FB13_Pos)
#define CAN_F13R2_FB13                       CAN_F13R2_FB13_Msk
#define CAN_F13R2_FB14_Pos                   (14U)
#define CAN_F13R2_FB14_Msk                   (0x1UL << CAN_F13R2_FB14_Pos)
#define CAN_F13R2_FB14                       CAN_F13R2_FB14_Msk
#define CAN_F13R2_FB15_Pos                   (15U)
#define CAN_F13R2_FB15_Msk                   (0x1UL << CAN_F13R2_FB15_Pos)
#define CAN_F13R2_FB15                       CAN_F13R2_FB15_Msk
#define CAN_F13R2_FB16_Pos                   (16U)
#define CAN_F13R2_FB16_Msk                   (0x1UL << CAN_F13R2_FB16_Pos)
#define CAN_F13R2_FB16                       CAN_F13R2_FB16_Msk
#define CAN_F13R2_FB17_Pos                   (17U)
#define CAN_F13R2_FB17_Msk                   (0x1UL << CAN_F13R2_FB17_Pos)
#define CAN_F13R2_FB17                       CAN_F13R2_FB17_Msk
#define CAN_F13R2_FB18_Pos                   (18U)
#define CAN_F13R2_FB18_Msk                   (0x1UL << CAN_F13R2_FB18_Pos)
#define CAN_F13R2_FB18                       CAN_F13R2_FB18_Msk
#define CAN_F13R2_FB19_Pos                   (19U)
#define CAN_F13R2_FB19_Msk                   (0x1UL << CAN_F13R2_FB19_Pos)
#define CAN_F13R2_FB19                       CAN_F13R2_FB19_Msk
#define CAN_F13R2_FB20_Pos                   (20U)
#define CAN_F13R2_FB20_Msk                   (0x1UL << CAN_F13R2_FB20_Pos)
#define CAN_F13R2_FB20                       CAN_F13R2_FB20_Msk
#define CAN_F13R2_FB21_Pos                   (21U)
#define CAN_F13R2_FB21_Msk                   (0x1UL << CAN_F13R2_FB21_Pos)
#define CAN_F13R2_FB21                       CAN_F13R2_FB21_Msk
#define CAN_F13R2_FB22_Pos                   (22U)
#define CAN_F13R2_FB22_Msk                   (0x1UL << CAN_F13R2_FB22_Pos)
#define CAN_F13R2_FB22                       CAN_F13R2_FB22_Msk
#define CAN_F13R2_FB23_Pos                   (23U)
#define CAN_F13R2_FB23_Msk                   (0x1UL << CAN_F13R2_FB23_Pos)
#define CAN_F13R2_FB23                       CAN_F13R2_FB23_Msk
#define CAN_F13R2_FB24_Pos                   (24U)
#define CAN_F13R2_FB24_Msk                   (0x1UL << CAN_F13R2_FB24_Pos)
#define CAN_F13R2_FB24                       CAN_F13R2_FB24_Msk
#define CAN_F13R2_FB25_Pos                   (25U)
#define CAN_F13R2_FB25_Msk                   (0x1UL << CAN_F13R2_FB25_Pos)
#define CAN_F13R2_FB25                       CAN_F13R2_FB25_Msk
#define CAN_F13R2_FB26_Pos                   (26U)
#define CAN_F13R2_FB26_Msk                   (0x1UL << CAN_F13R2_FB26_Pos)
#define CAN_F13R2_FB26                       CAN_F13R2_FB26_Msk
#define CAN_F13R2_FB27_Pos                   (27U)
#define CAN_F13R2_FB27_Msk                   (0x1UL << CAN_F13R2_FB27_Pos)
#define CAN_F13R2_FB27                       CAN_F13R2_FB27_Msk
#define CAN_F13R2_FB28_Pos                   (28U)
#define CAN_F13R2_FB28_Msk                   (0x1UL << CAN_F13R2_FB28_Pos)
#define CAN_F13R2_FB28                       CAN_F13R2_FB28_Msk
#define CAN_F13R2_FB29_Pos                   (29U)
#define CAN_F13R2_FB29_Msk                   (0x1UL << CAN_F13R2_FB29_Pos)
#define CAN_F13R2_FB29                       CAN_F13R2_FB29_Msk
#define CAN_F13R2_FB30_Pos                   (30U)
#define CAN_F13R2_FB30_Msk                   (0x1UL << CAN_F13R2_FB30_Pos)
#define CAN_F13R2_FB30                       CAN_F13R2_FB30_Msk
#define CAN_F13R2_FB31_Pos                   (31U)
#define CAN_F13R2_FB31_Msk                   (0x1UL << CAN_F13R2_FB31_Pos)
#define CAN_F13R2_FB31                       CAN_F13R2_FB31_Msk

#define SPI_CR1_CPHA_Pos                    (0U)
#define SPI_CR1_CPHA_Msk                    (0x1UL << SPI_CR1_CPHA_Pos)
#define SPI_CR1_CPHA                        SPI_CR1_CPHA_Msk
#define SPI_CR1_CPOL_Pos                    (1U)
#define SPI_CR1_CPOL_Msk                    (0x1UL << SPI_CR1_CPOL_Pos)
#define SPI_CR1_CPOL                        SPI_CR1_CPOL_Msk
#define SPI_CR1_MSTR_Pos                    (2U)
#define SPI_CR1_MSTR_Msk                    (0x1UL << SPI_CR1_MSTR_Pos)
#define SPI_CR1_MSTR                        SPI_CR1_MSTR_Msk

#define SPI_CR1_BR_Pos                      (3U)
#define SPI_CR1_BR_Msk                      (0x7UL << SPI_CR1_BR_Pos)
#define SPI_CR1_BR                          SPI_CR1_BR_Msk
#define SPI_CR1_BR_0                        (0x1UL << SPI_CR1_BR_Pos)
#define SPI_CR1_BR_1                        (0x2UL << SPI_CR1_BR_Pos)
#define SPI_CR1_BR_2                        (0x4UL << SPI_CR1_BR_Pos)

#define SPI_CR1_SPE_Pos                     (6U)
#define SPI_CR1_SPE_Msk                     (0x1UL << SPI_CR1_SPE_Pos)
#define SPI_CR1_SPE                         SPI_CR1_SPE_Msk
#define SPI_CR1_LSBFIRST_Pos                (7U)
#define SPI_CR1_LSBFIRST_Msk                (0x1UL << SPI_CR1_LSBFIRST_Pos)
#define SPI_CR1_LSBFIRST                    SPI_CR1_LSBFIRST_Msk
#define SPI_CR1_SSI_Pos                     (8U)
#define SPI_CR1_SSI_Msk                     (0x1UL << SPI_CR1_SSI_Pos)
#define SPI_CR1_SSI                         SPI_CR1_SSI_Msk
#define SPI_CR1_SSM_Pos                     (9U)
#define SPI_CR1_SSM_Msk                     (0x1UL << SPI_CR1_SSM_Pos)
#define SPI_CR1_SSM                         SPI_CR1_SSM_Msk
#define SPI_CR1_RXONLY_Pos                  (10U)
#define SPI_CR1_RXONLY_Msk                  (0x1UL << SPI_CR1_RXONLY_Pos)
#define SPI_CR1_RXONLY                      SPI_CR1_RXONLY_Msk
#define SPI_CR1_DFF_Pos                     (11U)
#define SPI_CR1_DFF_Msk                     (0x1UL << SPI_CR1_DFF_Pos)
#define SPI_CR1_DFF                         SPI_CR1_DFF_Msk
#define SPI_CR1_CRCNEXT_Pos                 (12U)
#define SPI_CR1_CRCNEXT_Msk                 (0x1UL << SPI_CR1_CRCNEXT_Pos)
#define SPI_CR1_CRCNEXT                     SPI_CR1_CRCNEXT_Msk
#define SPI_CR1_CRCEN_Pos                   (13U)
#define SPI_CR1_CRCEN_Msk                   (0x1UL << SPI_CR1_CRCEN_Pos)
#define SPI_CR1_CRCEN                       SPI_CR1_CRCEN_Msk
#define SPI_CR1_BIDIOE_Pos                  (14U)
#define SPI_CR1_BIDIOE_Msk                  (0x1UL << SPI_CR1_BIDIOE_Pos)
#define SPI_CR1_BIDIOE                      SPI_CR1_BIDIOE_Msk
#define SPI_CR1_BIDIMODE_Pos                (15U)
#define SPI_CR1_BIDIMODE_Msk                (0x1UL << SPI_CR1_BIDIMODE_Pos)
#define SPI_CR1_BIDIMODE                    SPI_CR1_BIDIMODE_Msk

#define SPI_CR2_RXDMAEN_Pos                 (0U)
#define SPI_CR2_RXDMAEN_Msk                 (0x1UL << SPI_CR2_RXDMAEN_Pos)
#define SPI_CR2_RXDMAEN                     SPI_CR2_RXDMAEN_Msk
#define SPI_CR2_TXDMAEN_Pos                 (1U)
#define SPI_CR2_TXDMAEN_Msk                 (0x1UL << SPI_CR2_TXDMAEN_Pos)
#define SPI_CR2_TXDMAEN                     SPI_CR2_TXDMAEN_Msk
#define SPI_CR2_SSOE_Pos                    (2U)
#define SPI_CR2_SSOE_Msk                    (0x1UL << SPI_CR2_SSOE_Pos)
#define SPI_CR2_SSOE                        SPI_CR2_SSOE_Msk
#define SPI_CR2_ERRIE_Pos                   (5U)
#define SPI_CR2_ERRIE_Msk                   (0x1UL << SPI_CR2_ERRIE_Pos)
#define SPI_CR2_ERRIE                       SPI_CR2_ERRIE_Msk
#define SPI_CR2_RXNEIE_Pos                  (6U)
#define SPI_CR2_RXNEIE_Msk                  (0x1UL << SPI_CR2_RXNEIE_Pos)
#define SPI_CR2_RXNEIE                      SPI_CR2_RXNEIE_Msk
#define SPI_CR2_TXEIE_Pos                   (7U)
#define SPI_CR2_TXEIE_Msk                   (0x1UL << SPI_CR2_TXEIE_Pos)
#define SPI_CR2_TXEIE                       SPI_CR2_TXEIE_Msk

#define SPI_SR_RXNE_Pos                     (0U)
#define SPI_SR_RXNE_Msk                     (0x1UL << SPI_SR_RXNE_Pos)
#define SPI_SR_RXNE                         SPI_SR_RXNE_Msk
#define SPI_SR_TXE_Pos                      (1U)
#define SPI_SR_TXE_Msk                      (0x1UL << SPI_SR_TXE_Pos)
#define SPI_SR_TXE                          SPI_SR_TXE_Msk
#define SPI_SR_CHSIDE_Pos                   (2U)
#define SPI_SR_CHSIDE_Msk                   (0x1UL << SPI_SR_CHSIDE_Pos)
#define SPI_SR_CHSIDE                       SPI_SR_CHSIDE_Msk
#define SPI_SR_UDR_Pos                      (3U)
#define SPI_SR_UDR_Msk                      (0x1UL << SPI_SR_UDR_Pos)
#define SPI_SR_UDR                          SPI_SR_UDR_Msk
#define SPI_SR_CRCERR_Pos                   (4U)
#define SPI_SR_CRCERR_Msk                   (0x1UL << SPI_SR_CRCERR_Pos)
#define SPI_SR_CRCERR                       SPI_SR_CRCERR_Msk
#define SPI_SR_MODF_Pos                     (5U)
#define SPI_SR_MODF_Msk                     (0x1UL << SPI_SR_MODF_Pos)
#define SPI_SR_MODF                         SPI_SR_MODF_Msk
#define SPI_SR_OVR_Pos                      (6U)
#define SPI_SR_OVR_Msk                      (0x1UL << SPI_SR_OVR_Pos)
#define SPI_SR_OVR                          SPI_SR_OVR_Msk
#define SPI_SR_BSY_Pos                      (7U)
#define SPI_SR_BSY_Msk                      (0x1UL << SPI_SR_BSY_Pos)
#define SPI_SR_BSY                          SPI_SR_BSY_Msk

#define SPI_DR_DR_Pos                       (0U)
#define SPI_DR_DR_Msk                       (0xFFFFUL << SPI_DR_DR_Pos)
#define SPI_DR_DR                           SPI_DR_DR_Msk

#define SPI_CRCPR_CRCPOLY_Pos               (0U)
#define SPI_CRCPR_CRCPOLY_Msk               (0xFFFFUL << SPI_CRCPR_CRCPOLY_Pos)
#define SPI_CRCPR_CRCPOLY                   SPI_CRCPR_CRCPOLY_Msk

#define SPI_RXCRCR_RXCRC_Pos                (0U)
#define SPI_RXCRCR_RXCRC_Msk                (0xFFFFUL << SPI_RXCRCR_RXCRC_Pos)
#define SPI_RXCRCR_RXCRC                    SPI_RXCRCR_RXCRC_Msk

#define SPI_TXCRCR_TXCRC_Pos                (0U)
#define SPI_TXCRCR_TXCRC_Msk                (0xFFFFUL << SPI_TXCRCR_TXCRC_Pos)
#define SPI_TXCRCR_TXCRC                    SPI_TXCRCR_TXCRC_Msk

#define SPI_I2SCFGR_I2SMOD_Pos              (11U)
#define SPI_I2SCFGR_I2SMOD_Msk              (0x1UL << SPI_I2SCFGR_I2SMOD_Pos)
#define SPI_I2SCFGR_I2SMOD                  SPI_I2SCFGR_I2SMOD_Msk

#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)
#define I2C_CR1_PE                          I2C_CR1_PE_Msk
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)
#define I2C_CR1_START                       I2C_CR1_START_Msk
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)
#define I2C_CR1_POS                         I2C_CR1_POS_Msk
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk

#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk
#define I2C_CR2_FREQ_0                      (0x01UL << I2C_CR2_FREQ_Pos)
#define I2C_CR2_FREQ_1                      (0x02UL << I2C_CR2_FREQ_Pos)
#define I2C_CR2_FREQ_2                      (0x04UL << I2C_CR2_FREQ_Pos)
#define I2C_CR2_FREQ_3                      (0x08UL << I2C_CR2_FREQ_Pos)
#define I2C_CR2_FREQ_4                      (0x10UL << I2C_CR2_FREQ_Pos)
#define I2C_CR2_FREQ_5                      (0x20UL << I2C_CR2_FREQ_Pos)

#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk

#define I2C_OAR1_ADD1_7                     0x000000FEU
#define I2C_OAR1_ADD8_9                     0x00000300U

#define I2C_OAR1_ADD0_Pos                   (0U)
#define I2C_OAR1_ADD0_Msk                   (0x1UL << I2C_OAR1_ADD0_Pos)
#define I2C_OAR1_ADD0                       I2C_OAR1_ADD0_Msk
#define I2C_OAR1_ADD1_Pos                   (1U)
#define I2C_OAR1_ADD1_Msk                   (0x1UL << I2C_OAR1_ADD1_Pos)
#define I2C_OAR1_ADD1                       I2C_OAR1_ADD1_Msk
#define I2C_OAR1_ADD2_Pos                   (2U)
#define I2C_OAR1_ADD2_Msk                   (0x1UL << I2C_OAR1_ADD2_Pos)
#define I2C_OAR1_ADD2                       I2C_OAR1_ADD2_Msk
#define I2C_OAR1_ADD3_Pos                   (3U)
#define I2C_OAR1_ADD3_Msk                   (0x1UL << I2C_OAR1_ADD3_Pos)
#define I2C_OAR1_ADD3                       I2C_OAR1_ADD3_Msk
#define I2C_OAR1_ADD4_Pos                   (4U)
#define I2C_OAR1_ADD4_Msk                   (0x1UL << I2C_OAR1_ADD4_Pos)
#define I2C_OAR1_ADD4                       I2C_OAR1_ADD4_Msk
#define I2C_OAR1_ADD5_Pos                   (5U)
#define I2C_OAR1_ADD5_Msk                   (0x1UL << I2C_OAR1_ADD5_Pos)
#define I2C_OAR1_ADD5                       I2C_OAR1_ADD5_Msk
#define I2C_OAR1_ADD6_Pos                   (6U)
#define I2C_OAR1_ADD6_Msk                   (0x1UL << I2C_OAR1_ADD6_Pos)
#define I2C_OAR1_ADD6                       I2C_OAR1_ADD6_Msk
#define I2C_OAR1_ADD7_Pos                   (7U)
#define I2C_OAR1_ADD7_Msk                   (0x1UL << I2C_OAR1_ADD7_Pos)
#define I2C_OAR1_ADD7                       I2C_OAR1_ADD7_Msk
#define I2C_OAR1_ADD8_Pos                   (8U)
#define I2C_OAR1_ADD8_Msk                   (0x1UL << I2C_OAR1_ADD8_Pos)
#define I2C_OAR1_ADD8                       I2C_OAR1_ADD8_Msk
#define I2C_OAR1_ADD9_Pos                   (9U)
#define I2C_OAR1_ADD9_Msk                   (0x1UL << I2C_OAR1_ADD9_Pos)
#define I2C_OAR1_ADD9                       I2C_OAR1_ADD9_Msk

#define I2C_OAR1_ADDMODE_Pos                (15U)
#define I2C_OAR1_ADDMODE_Msk                (0x1UL << I2C_OAR1_ADDMODE_Pos)
#define I2C_OAR1_ADDMODE                    I2C_OAR1_ADDMODE_Msk

#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk
#define I2C_OAR2_ADD2_Pos                   (1U)
#define I2C_OAR2_ADD2_Msk                   (0x7FUL << I2C_OAR2_ADD2_Pos)
#define I2C_OAR2_ADD2                       I2C_OAR2_ADD2_Msk

#define I2C_DR_DR_Pos             (0U)
#define I2C_DR_DR_Msk             (0xFFUL << I2C_DR_DR_Pos)
#define I2C_DR_DR                 I2C_DR_DR_Msk

#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)
#define I2C_SR1_SB                          I2C_SR1_SB_Msk
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)
#define I2C_SR1_AF                          I2C_SR1_AF_Msk
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk

#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk

#define I2C_CCR_CCR_Pos                     (0U)
#define I2C_CCR_CCR_Msk                     (0xFFFUL << I2C_CCR_CCR_Pos)
#define I2C_CCR_CCR                         I2C_CCR_CCR_Msk
#define I2C_CCR_DUTY_Pos                    (14U)
#define I2C_CCR_DUTY_Msk                    (0x1UL << I2C_CCR_DUTY_Pos)
#define I2C_CCR_DUTY                        I2C_CCR_DUTY_Msk
#define I2C_CCR_FS_Pos                      (15U)
#define I2C_CCR_FS_Msk                      (0x1UL << I2C_CCR_FS_Pos)
#define I2C_CCR_FS                          I2C_CCR_FS_Msk

#define I2C_TRISE_TRISE_Pos                 (0U)
#define I2C_TRISE_TRISE_Msk                 (0x3FUL << I2C_TRISE_TRISE_Pos)
#define I2C_TRISE_TRISE                     I2C_TRISE_TRISE_Msk

#define USART_SR_PE_Pos                     (0U)
#define USART_SR_PE_Msk                     (0x1UL << USART_SR_PE_Pos)
#define USART_SR_PE                         USART_SR_PE_Msk
#define USART_SR_FE_Pos                     (1U)
#define USART_SR_FE_Msk                     (0x1UL << USART_SR_FE_Pos)
#define USART_SR_FE                         USART_SR_FE_Msk
#define USART_SR_NE_Pos                     (2U)
#define USART_SR_NE_Msk                     (0x1UL << USART_SR_NE_Pos)
#define USART_SR_NE                         USART_SR_NE_Msk
#define USART_SR_ORE_Pos                    (3U)
#define USART_SR_ORE_Msk                    (0x1UL << USART_SR_ORE_Pos)
#define USART_SR_ORE                        USART_SR_ORE_Msk
#define USART_SR_IDLE_Pos                   (4U)
#define USART_SR_IDLE_Msk                   (0x1UL << USART_SR_IDLE_Pos)
#define USART_SR_IDLE                       USART_SR_IDLE_Msk
#define USART_SR_RXNE_Pos                   (5U)
#define USART_SR_RXNE_Msk                   (0x1UL << USART_SR_RXNE_Pos)
#define USART_SR_RXNE                       USART_SR_RXNE_Msk
#define USART_SR_TC_Pos                     (6U)
#define USART_SR_TC_Msk                     (0x1UL << USART_SR_TC_Pos)
#define USART_SR_TC                         USART_SR_TC_Msk
#define USART_SR_TXE_Pos                    (7U)
#define USART_SR_TXE_Msk                    (0x1UL << USART_SR_TXE_Pos)
#define USART_SR_TXE                        USART_SR_TXE_Msk
#define USART_SR_LBD_Pos                    (8U)
#define USART_SR_LBD_Msk                    (0x1UL << USART_SR_LBD_Pos)
#define USART_SR_LBD                        USART_SR_LBD_Msk
#define USART_SR_CTS_Pos                    (9U)
#define USART_SR_CTS_Msk                    (0x1UL << USART_SR_CTS_Pos)
#define USART_SR_CTS                        USART_SR_CTS_Msk

#define USART_DR_DR_Pos                     (0U)
#define USART_DR_DR_Msk                     (0x1FFUL << USART_DR_DR_Pos)
#define USART_DR_DR                         USART_DR_DR_Msk

#define USART_BRR_DIV_Fraction_Pos          (0U)
#define USART_BRR_DIV_Fraction_Msk          (0xFUL << USART_BRR_DIV_Fraction_Pos)
#define USART_BRR_DIV_Fraction              USART_BRR_DIV_Fraction_Msk
#define USART_BRR_DIV_Mantissa_Pos          (4U)
#define USART_BRR_DIV_Mantissa_Msk          (0xFFFUL << USART_BRR_DIV_Mantissa_Pos)
#define USART_BRR_DIV_Mantissa              USART_BRR_DIV_Mantissa_Msk

#define USART_CR1_SBK_Pos                   (0U)
#define USART_CR1_SBK_Msk                   (0x1UL << USART_CR1_SBK_Pos)
#define USART_CR1_SBK                       USART_CR1_SBK_Msk
#define USART_CR1_RWU_Pos                   (1U)
#define USART_CR1_RWU_Msk                   (0x1UL << USART_CR1_RWU_Pos)
#define USART_CR1_RWU                       USART_CR1_RWU_Msk
#define USART_CR1_RE_Pos                    (2U)
#define USART_CR1_RE_Msk                    (0x1UL << USART_CR1_RE_Pos)
#define USART_CR1_RE                        USART_CR1_RE_Msk
#define USART_CR1_TE_Pos                    (3U)
#define USART_CR1_TE_Msk                    (0x1UL << USART_CR1_TE_Pos)
#define USART_CR1_TE                        USART_CR1_TE_Msk
#define USART_CR1_IDLEIE_Pos                (4U)
#define USART_CR1_IDLEIE_Msk                (0x1UL << USART_CR1_IDLEIE_Pos)
#define USART_CR1_IDLEIE                    USART_CR1_IDLEIE_Msk
#define USART_CR1_RXNEIE_Pos                (5U)
#define USART_CR1_RXNEIE_Msk                (0x1UL << USART_CR1_RXNEIE_Pos)
#define USART_CR1_RXNEIE                    USART_CR1_RXNEIE_Msk
#define USART_CR1_TCIE_Pos                  (6U)
#define USART_CR1_TCIE_Msk                  (0x1UL << USART_CR1_TCIE_Pos)
#define USART_CR1_TCIE                      USART_CR1_TCIE_Msk
#define USART_CR1_TXEIE_Pos                 (7U)
#define USART_CR1_TXEIE_Msk                 (0x1UL << USART_CR1_TXEIE_Pos)
#define USART_CR1_TXEIE                     USART_CR1_TXEIE_Msk
#define USART_CR1_PEIE_Pos                  (8U)
#define USART_CR1_PEIE_Msk                  (0x1UL << USART_CR1_PEIE_Pos)
#define USART_CR1_PEIE                      USART_CR1_PEIE_Msk
#define USART_CR1_PS_Pos                    (9U)
#define USART_CR1_PS_Msk                    (0x1UL << USART_CR1_PS_Pos)
#define USART_CR1_PS                        USART_CR1_PS_Msk
#define USART_CR1_PCE_Pos                   (10U)
#define USART_CR1_PCE_Msk                   (0x1UL << USART_CR1_PCE_Pos)
#define USART_CR1_PCE                       USART_CR1_PCE_Msk
#define USART_CR1_WAKE_Pos                  (11U)
#define USART_CR1_WAKE_Msk                  (0x1UL << USART_CR1_WAKE_Pos)
#define USART_CR1_WAKE                      USART_CR1_WAKE_Msk
#define USART_CR1_M_Pos                     (12U)
#define USART_CR1_M_Msk                     (0x1UL << USART_CR1_M_Pos)
#define USART_CR1_M                         USART_CR1_M_Msk
#define USART_CR1_UE_Pos                    (13U)
#define USART_CR1_UE_Msk                    (0x1UL << USART_CR1_UE_Pos)
#define USART_CR1_UE                        USART_CR1_UE_Msk

#define USART_CR2_ADD_Pos                   (0U)
#define USART_CR2_ADD_Msk                   (0xFUL << USART_CR2_ADD_Pos)
#define USART_CR2_ADD                       USART_CR2_ADD_Msk
#define USART_CR2_LBDL_Pos                  (5U)
#define USART_CR2_LBDL_Msk                  (0x1UL << USART_CR2_LBDL_Pos)
#define USART_CR2_LBDL                      USART_CR2_LBDL_Msk
#define USART_CR2_LBDIE_Pos                 (6U)
#define USART_CR2_LBDIE_Msk                 (0x1UL << USART_CR2_LBDIE_Pos)
#define USART_CR2_LBDIE                     USART_CR2_LBDIE_Msk
#define USART_CR2_LBCL_Pos                  (8U)
#define USART_CR2_LBCL_Msk                  (0x1UL << USART_CR2_LBCL_Pos)
#define USART_CR2_LBCL                      USART_CR2_LBCL_Msk
#define USART_CR2_CPHA_Pos                  (9U)
#define USART_CR2_CPHA_Msk                  (0x1UL << USART_CR2_CPHA_Pos)
#define USART_CR2_CPHA                      USART_CR2_CPHA_Msk
#define USART_CR2_CPOL_Pos                  (10U)
#define USART_CR2_CPOL_Msk                  (0x1UL << USART_CR2_CPOL_Pos)
#define USART_CR2_CPOL                      USART_CR2_CPOL_Msk
#define USART_CR2_CLKEN_Pos                 (11U)
#define USART_CR2_CLKEN_Msk                 (0x1UL << USART_CR2_CLKEN_Pos)
#define USART_CR2_CLKEN                     USART_CR2_CLKEN_Msk

#define USART_CR2_STOP_Pos                  (12U)
#define USART_CR2_STOP_Msk                  (0x3UL << USART_CR2_STOP_Pos)
#define USART_CR2_STOP                      USART_CR2_STOP_Msk
#define USART_CR2_STOP_0                    (0x1UL << USART_CR2_STOP_Pos)
#define USART_CR2_STOP_1                    (0x2UL << USART_CR2_STOP_Pos)

#define USART_CR2_LINEN_Pos                 (14U)
#define USART_CR2_LINEN_Msk                 (0x1UL << USART_CR2_LINEN_Pos)
#define USART_CR2_LINEN                     USART_CR2_LINEN_Msk

#define USART_CR3_EIE_Pos                   (0U)
#define USART_CR3_EIE_Msk                   (0x1UL << USART_CR3_EIE_Pos)
#define USART_CR3_EIE                       USART_CR3_EIE_Msk
#define USART_CR3_IREN_Pos                  (1U)
#define USART_CR3_IREN_Msk                  (0x1UL << USART_CR3_IREN_Pos)
#define USART_CR3_IREN                      USART_CR3_IREN_Msk
#define USART_CR3_IRLP_Pos                  (2U)
#define USART_CR3_IRLP_Msk                  (0x1UL << USART_CR3_IRLP_Pos)
#define USART_CR3_IRLP                      USART_CR3_IRLP_Msk
#define USART_CR3_HDSEL_Pos                 (3U)
#define USART_CR3_HDSEL_Msk                 (0x1UL << USART_CR3_HDSEL_Pos)
#define USART_CR3_HDSEL                     USART_CR3_HDSEL_Msk
#define USART_CR3_NACK_Pos                  (4U)
#define USART_CR3_NACK_Msk                  (0x1UL << USART_CR3_NACK_Pos)
#define USART_CR3_NACK                      USART_CR3_NACK_Msk
#define USART_CR3_SCEN_Pos                  (5U)
#define USART_CR3_SCEN_Msk                  (0x1UL << USART_CR3_SCEN_Pos)
#define USART_CR3_SCEN                      USART_CR3_SCEN_Msk
#define USART_CR3_DMAR_Pos                  (6U)
#define USART_CR3_DMAR_Msk                  (0x1UL << USART_CR3_DMAR_Pos)
#define USART_CR3_DMAR                      USART_CR3_DMAR_Msk
#define USART_CR3_DMAT_Pos                  (7U)
#define USART_CR3_DMAT_Msk                  (0x1UL << USART_CR3_DMAT_Pos)
#define USART_CR3_DMAT                      USART_CR3_DMAT_Msk
#define USART_CR3_RTSE_Pos                  (8U)
#define USART_CR3_RTSE_Msk                  (0x1UL << USART_CR3_RTSE_Pos)
#define USART_CR3_RTSE                      USART_CR3_RTSE_Msk
#define USART_CR3_CTSE_Pos                  (9U)
#define USART_CR3_CTSE_Msk                  (0x1UL << USART_CR3_CTSE_Pos)
#define USART_CR3_CTSE                      USART_CR3_CTSE_Msk
#define USART_CR3_CTSIE_Pos                 (10U)
#define USART_CR3_CTSIE_Msk                 (0x1UL << USART_CR3_CTSIE_Pos)
#define USART_CR3_CTSIE                     USART_CR3_CTSIE_Msk

#define USART_GTPR_PSC_Pos                  (0U)
#define USART_GTPR_PSC_Msk                  (0xFFUL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC                      USART_GTPR_PSC_Msk
#define USART_GTPR_PSC_0                    (0x01UL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC_1                    (0x02UL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC_2                    (0x04UL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC_3                    (0x08UL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC_4                    (0x10UL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC_5                    (0x20UL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC_6                    (0x40UL << USART_GTPR_PSC_Pos)
#define USART_GTPR_PSC_7                    (0x80UL << USART_GTPR_PSC_Pos)

#define USART_GTPR_GT_Pos                   (8U)
#define USART_GTPR_GT_Msk                   (0xFFUL << USART_GTPR_GT_Pos)
#define USART_GTPR_GT                       USART_GTPR_GT_Msk

#define DBGMCU_IDCODE_DEV_ID_Pos            (0U)
#define DBGMCU_IDCODE_DEV_ID_Msk            (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos)
#define DBGMCU_IDCODE_DEV_ID                DBGMCU_IDCODE_DEV_ID_Msk

#define DBGMCU_IDCODE_REV_ID_Pos            (16U)
#define DBGMCU_IDCODE_REV_ID_Msk            (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID                DBGMCU_IDCODE_REV_ID_Msk
#define DBGMCU_IDCODE_REV_ID_0              (0x0001UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_1              (0x0002UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_2              (0x0004UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_3              (0x0008UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_4              (0x0010UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_5              (0x0020UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_6              (0x0040UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_7              (0x0080UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_8              (0x0100UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_9              (0x0200UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_10             (0x0400UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_11             (0x0800UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_12             (0x1000UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_13             (0x2000UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_14             (0x4000UL << DBGMCU_IDCODE_REV_ID_Pos)
#define DBGMCU_IDCODE_REV_ID_15             (0x8000UL << DBGMCU_IDCODE_REV_ID_Pos)

#define DBGMCU_CR_DBG_SLEEP_Pos             (0U)
#define DBGMCU_CR_DBG_SLEEP_Msk             (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos)
#define DBGMCU_CR_DBG_SLEEP                 DBGMCU_CR_DBG_SLEEP_Msk
#define DBGMCU_CR_DBG_STOP_Pos              (1U)
#define DBGMCU_CR_DBG_STOP_Msk              (0x1UL << DBGMCU_CR_DBG_STOP_Pos)
#define DBGMCU_CR_DBG_STOP                  DBGMCU_CR_DBG_STOP_Msk
#define DBGMCU_CR_DBG_STANDBY_Pos           (2U)
#define DBGMCU_CR_DBG_STANDBY_Msk           (0x1UL << DBGMCU_CR_DBG_STANDBY_Pos)
#define DBGMCU_CR_DBG_STANDBY               DBGMCU_CR_DBG_STANDBY_Msk
#define DBGMCU_CR_TRACE_IOEN_Pos            (5U)
#define DBGMCU_CR_TRACE_IOEN_Msk            (0x1UL << DBGMCU_CR_TRACE_IOEN_Pos)
#define DBGMCU_CR_TRACE_IOEN                DBGMCU_CR_TRACE_IOEN_Msk

#define DBGMCU_CR_TRACE_MODE_Pos            (6U)
#define DBGMCU_CR_TRACE_MODE_Msk            (0x3UL << DBGMCU_CR_TRACE_MODE_Pos)
#define DBGMCU_CR_TRACE_MODE                DBGMCU_CR_TRACE_MODE_Msk
#define DBGMCU_CR_TRACE_MODE_0              (0x1UL << DBGMCU_CR_TRACE_MODE_Pos)
#define DBGMCU_CR_TRACE_MODE_1              (0x2UL << DBGMCU_CR_TRACE_MODE_Pos)

#define DBGMCU_CR_DBG_IWDG_STOP_Pos         (8U)
#define DBGMCU_CR_DBG_IWDG_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_IWDG_STOP_Pos)
#define DBGMCU_CR_DBG_IWDG_STOP             DBGMCU_CR_DBG_IWDG_STOP_Msk
#define DBGMCU_CR_DBG_WWDG_STOP_Pos         (9U)
#define DBGMCU_CR_DBG_WWDG_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_WWDG_STOP_Pos)
#define DBGMCU_CR_DBG_WWDG_STOP             DBGMCU_CR_DBG_WWDG_STOP_Msk
#define DBGMCU_CR_DBG_TIM1_STOP_Pos         (10U)
#define DBGMCU_CR_DBG_TIM1_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM1_STOP_Pos)
#define DBGMCU_CR_DBG_TIM1_STOP             DBGMCU_CR_DBG_TIM1_STOP_Msk
#define DBGMCU_CR_DBG_TIM2_STOP_Pos         (11U)
#define DBGMCU_CR_DBG_TIM2_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM2_STOP_Pos)
#define DBGMCU_CR_DBG_TIM2_STOP             DBGMCU_CR_DBG_TIM2_STOP_Msk
#define DBGMCU_CR_DBG_TIM3_STOP_Pos         (12U)
#define DBGMCU_CR_DBG_TIM3_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM3_STOP_Pos)
#define DBGMCU_CR_DBG_TIM3_STOP             DBGMCU_CR_DBG_TIM3_STOP_Msk
#define DBGMCU_CR_DBG_TIM4_STOP_Pos         (13U)
#define DBGMCU_CR_DBG_TIM4_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_TIM4_STOP_Pos)
#define DBGMCU_CR_DBG_TIM4_STOP             DBGMCU_CR_DBG_TIM4_STOP_Msk
#define DBGMCU_CR_DBG_CAN1_STOP_Pos         (14U)
#define DBGMCU_CR_DBG_CAN1_STOP_Msk         (0x1UL << DBGMCU_CR_DBG_CAN1_STOP_Pos)
#define DBGMCU_CR_DBG_CAN1_STOP             DBGMCU_CR_DBG_CAN1_STOP_Msk
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Pos (15U)
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Pos)
#define DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT    DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT_Msk
#define DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Pos (16U)
#define DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Pos)
#define DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT    DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT_Msk

#define FLASH_ACR_LATENCY_Pos               (0U)
#define FLASH_ACR_LATENCY_Msk               (0x7UL << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY                   FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0                 (0x1UL << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY_1                 (0x2UL << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY_2                 (0x4UL << FLASH_ACR_LATENCY_Pos)

#define FLASH_ACR_HLFCYA_Pos                (3U)
#define FLASH_ACR_HLFCYA_Msk                (0x1UL << FLASH_ACR_HLFCYA_Pos)
#define FLASH_ACR_HLFCYA                    FLASH_ACR_HLFCYA_Msk
#define FLASH_ACR_PRFTBE_Pos                (4U)
#define FLASH_ACR_PRFTBE_Msk                (0x1UL << FLASH_ACR_PRFTBE_Pos)
#define FLASH_ACR_PRFTBE                    FLASH_ACR_PRFTBE_Msk
#define FLASH_ACR_PRFTBS_Pos                (5U)
#define FLASH_ACR_PRFTBS_Msk                (0x1UL << FLASH_ACR_PRFTBS_Pos)
#define FLASH_ACR_PRFTBS                    FLASH_ACR_PRFTBS_Msk

#define FLASH_KEYR_FKEYR_Pos                (0U)
#define FLASH_KEYR_FKEYR_Msk                (0xFFFFFFFFUL << FLASH_KEYR_FKEYR_Pos)
#define FLASH_KEYR_FKEYR                    FLASH_KEYR_FKEYR_Msk

#define RDP_KEY_Pos                         (0U)
#define RDP_KEY_Msk                         (0xA5UL << RDP_KEY_Pos)
#define RDP_KEY                             RDP_KEY_Msk
#define FLASH_KEY1_Pos                      (0U)
#define FLASH_KEY1_Msk                      (0x45670123UL << FLASH_KEY1_Pos)
#define FLASH_KEY1                          FLASH_KEY1_Msk
#define FLASH_KEY2_Pos                      (0U)
#define FLASH_KEY2_Msk                      (0xCDEF89ABUL << FLASH_KEY2_Pos)
#define FLASH_KEY2                          FLASH_KEY2_Msk

#define FLASH_OPTKEYR_OPTKEYR_Pos           (0U)
#define FLASH_OPTKEYR_OPTKEYR_Msk           (0xFFFFFFFFUL << FLASH_OPTKEYR_OPTKEYR_Pos)
#define FLASH_OPTKEYR_OPTKEYR               FLASH_OPTKEYR_OPTKEYR_Msk

#define  FLASH_OPTKEY1                       FLASH_KEY1
#define  FLASH_OPTKEY2                       FLASH_KEY2

#define FLASH_SR_BSY_Pos                    (0U)
#define FLASH_SR_BSY_Msk                    (0x1UL << FLASH_SR_BSY_Pos)
#define FLASH_SR_BSY                        FLASH_SR_BSY_Msk
#define FLASH_SR_PGERR_Pos                  (2U)
#define FLASH_SR_PGERR_Msk                  (0x1UL << FLASH_SR_PGERR_Pos)
#define FLASH_SR_PGERR                      FLASH_SR_PGERR_Msk
#define FLASH_SR_WRPRTERR_Pos               (4U)
#define FLASH_SR_WRPRTERR_Msk               (0x1UL << FLASH_SR_WRPRTERR_Pos)
#define FLASH_SR_WRPRTERR                   FLASH_SR_WRPRTERR_Msk
#define FLASH_SR_EOP_Pos                    (5U)
#define FLASH_SR_EOP_Msk                    (0x1UL << FLASH_SR_EOP_Pos)
#define FLASH_SR_EOP                        FLASH_SR_EOP_Msk

#define FLASH_CR_PG_Pos                     (0U)
#define FLASH_CR_PG_Msk                     (0x1UL << FLASH_CR_PG_Pos)
#define FLASH_CR_PG                         FLASH_CR_PG_Msk
#define FLASH_CR_PER_Pos                    (1U)
#define FLASH_CR_PER_Msk                    (0x1UL << FLASH_CR_PER_Pos)
#define FLASH_CR_PER                        FLASH_CR_PER_Msk
#define FLASH_CR_MER_Pos                    (2U)
#define FLASH_CR_MER_Msk                    (0x1UL << FLASH_CR_MER_Pos)
#define FLASH_CR_MER                        FLASH_CR_MER_Msk
#define FLASH_CR_OPTPG_Pos                  (4U)
#define FLASH_CR_OPTPG_Msk                  (0x1UL << FLASH_CR_OPTPG_Pos)
#define FLASH_CR_OPTPG                      FLASH_CR_OPTPG_Msk
#define FLASH_CR_OPTER_Pos                  (5U)
#define FLASH_CR_OPTER_Msk                  (0x1UL << FLASH_CR_OPTER_Pos)
#define FLASH_CR_OPTER                      FLASH_CR_OPTER_Msk
#define FLASH_CR_STRT_Pos                   (6U)
#define FLASH_CR_STRT_Msk                   (0x1UL << FLASH_CR_STRT_Pos)
#define FLASH_CR_STRT                       FLASH_CR_STRT_Msk
#define FLASH_CR_LOCK_Pos                   (7U)
#define FLASH_CR_LOCK_Msk                   (0x1UL << FLASH_CR_LOCK_Pos)
#define FLASH_CR_LOCK                       FLASH_CR_LOCK_Msk
#define FLASH_CR_OPTWRE_Pos                 (9U)
#define FLASH_CR_OPTWRE_Msk                 (0x1UL << FLASH_CR_OPTWRE_Pos)
#define FLASH_CR_OPTWRE                     FLASH_CR_OPTWRE_Msk
#define FLASH_CR_ERRIE_Pos                  (10U)
#define FLASH_CR_ERRIE_Msk                  (0x1UL << FLASH_CR_ERRIE_Pos)
#define FLASH_CR_ERRIE                      FLASH_CR_ERRIE_Msk
#define FLASH_CR_EOPIE_Pos                  (12U)
#define FLASH_CR_EOPIE_Msk                  (0x1UL << FLASH_CR_EOPIE_Pos)
#define FLASH_CR_EOPIE                      FLASH_CR_EOPIE_Msk

#define FLASH_AR_FAR_Pos                    (0U)
#define FLASH_AR_FAR_Msk                    (0xFFFFFFFFUL << FLASH_AR_FAR_Pos)
#define FLASH_AR_FAR                        FLASH_AR_FAR_Msk

#define FLASH_OBR_OPTERR_Pos                (0U)
#define FLASH_OBR_OPTERR_Msk                (0x1UL << FLASH_OBR_OPTERR_Pos)
#define FLASH_OBR_OPTERR                    FLASH_OBR_OPTERR_Msk
#define FLASH_OBR_RDPRT_Pos                 (1U)
#define FLASH_OBR_RDPRT_Msk                 (0x1UL << FLASH_OBR_RDPRT_Pos)
#define FLASH_OBR_RDPRT                     FLASH_OBR_RDPRT_Msk

#define FLASH_OBR_IWDG_SW_Pos               (2U)
#define FLASH_OBR_IWDG_SW_Msk               (0x1UL << FLASH_OBR_IWDG_SW_Pos)
#define FLASH_OBR_IWDG_SW                   FLASH_OBR_IWDG_SW_Msk
#define FLASH_OBR_nRST_STOP_Pos             (3U)
#define FLASH_OBR_nRST_STOP_Msk             (0x1UL << FLASH_OBR_nRST_STOP_Pos)
#define FLASH_OBR_nRST_STOP                 FLASH_OBR_nRST_STOP_Msk
#define FLASH_OBR_nRST_STDBY_Pos            (4U)
#define FLASH_OBR_nRST_STDBY_Msk            (0x1UL << FLASH_OBR_nRST_STDBY_Pos)
#define FLASH_OBR_nRST_STDBY                FLASH_OBR_nRST_STDBY_Msk
#define FLASH_OBR_USER_Pos                  (2U)
#define FLASH_OBR_USER_Msk                  (0x7UL << FLASH_OBR_USER_Pos)
#define FLASH_OBR_USER                      FLASH_OBR_USER_Msk
#define FLASH_OBR_DATA0_Pos                 (10U)
#define FLASH_OBR_DATA0_Msk                 (0xFFUL << FLASH_OBR_DATA0_Pos)
#define FLASH_OBR_DATA0                     FLASH_OBR_DATA0_Msk
#define FLASH_OBR_DATA1_Pos                 (18U)
#define FLASH_OBR_DATA1_Msk                 (0xFFUL << FLASH_OBR_DATA1_Pos)
#define FLASH_OBR_DATA1                     FLASH_OBR_DATA1_Msk

#define FLASH_WRPR_WRP_Pos                  (0U)
#define FLASH_WRPR_WRP_Msk                  (0xFFFFFFFFUL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP                      FLASH_WRPR_WRP_Msk

#define FLASH_RDP_RDP_Pos                   (0U)
#define FLASH_RDP_RDP_Msk                   (0xFFUL << FLASH_RDP_RDP_Pos)
#define FLASH_RDP_RDP                       FLASH_RDP_RDP_Msk
#define FLASH_RDP_nRDP_Pos                  (8U)
#define FLASH_RDP_nRDP_Msk                  (0xFFUL << FLASH_RDP_nRDP_Pos)
#define FLASH_RDP_nRDP                      FLASH_RDP_nRDP_Msk

#define FLASH_USER_USER_Pos                 (16U)
#define FLASH_USER_USER_Msk                 (0xFFUL << FLASH_USER_USER_Pos)
#define FLASH_USER_USER                     FLASH_USER_USER_Msk
#define FLASH_USER_nUSER_Pos                (24U)
#define FLASH_USER_nUSER_Msk                (0xFFUL << FLASH_USER_nUSER_Pos)
#define FLASH_USER_nUSER                    FLASH_USER_nUSER_Msk

#define FLASH_DATA0_DATA0_Pos               (0U)
#define FLASH_DATA0_DATA0_Msk               (0xFFUL << FLASH_DATA0_DATA0_Pos)
#define FLASH_DATA0_DATA0                   FLASH_DATA0_DATA0_Msk
#define FLASH_DATA0_nDATA0_Pos              (8U)
#define FLASH_DATA0_nDATA0_Msk              (0xFFUL << FLASH_DATA0_nDATA0_Pos)
#define FLASH_DATA0_nDATA0                  FLASH_DATA0_nDATA0_Msk

#define FLASH_DATA1_DATA1_Pos               (16U)
#define FLASH_DATA1_DATA1_Msk               (0xFFUL << FLASH_DATA1_DATA1_Pos)
#define FLASH_DATA1_DATA1                   FLASH_DATA1_DATA1_Msk
#define FLASH_DATA1_nDATA1_Pos              (24U)
#define FLASH_DATA1_nDATA1_Msk              (0xFFUL << FLASH_DATA1_nDATA1_Pos)
#define FLASH_DATA1_nDATA1                  FLASH_DATA1_nDATA1_Msk

#define FLASH_WRP0_WRP0_Pos                 (0U)
#define FLASH_WRP0_WRP0_Msk                 (0xFFUL << FLASH_WRP0_WRP0_Pos)
#define FLASH_WRP0_WRP0                     FLASH_WRP0_WRP0_Msk
#define FLASH_WRP0_nWRP0_Pos                (8U)
#define FLASH_WRP0_nWRP0_Msk                (0xFFUL << FLASH_WRP0_nWRP0_Pos)
#define FLASH_WRP0_nWRP0                    FLASH_WRP0_nWRP0_Msk

#define FLASH_WRP1_WRP1_Pos                 (16U)
#define FLASH_WRP1_WRP1_Msk                 (0xFFUL << FLASH_WRP1_WRP1_Pos)
#define FLASH_WRP1_WRP1                     FLASH_WRP1_WRP1_Msk
#define FLASH_WRP1_nWRP1_Pos                (24U)
#define FLASH_WRP1_nWRP1_Msk                (0xFFUL << FLASH_WRP1_nWRP1_Pos)
#define FLASH_WRP1_nWRP1                    FLASH_WRP1_nWRP1_Msk

#define FLASH_WRP2_WRP2_Pos                 (0U)
#define FLASH_WRP2_WRP2_Msk                 (0xFFUL << FLASH_WRP2_WRP2_Pos)
#define FLASH_WRP2_WRP2                     FLASH_WRP2_WRP2_Msk
#define FLASH_WRP2_nWRP2_Pos                (8U)
#define FLASH_WRP2_nWRP2_Msk                (0xFFUL << FLASH_WRP2_nWRP2_Pos)
#define FLASH_WRP2_nWRP2                    FLASH_WRP2_nWRP2_Msk

#define FLASH_WRP3_WRP3_Pos                 (16U)
#define FLASH_WRP3_WRP3_Msk                 (0xFFUL << FLASH_WRP3_WRP3_Pos)
#define FLASH_WRP3_WRP3                     FLASH_WRP3_WRP3_Msk
#define FLASH_WRP3_nWRP3_Pos                (24U)
#define FLASH_WRP3_nWRP3_Msk                (0xFFUL << FLASH_WRP3_nWRP3_Pos)
#define FLASH_WRP3_nWRP3                    FLASH_WRP3_nWRP3_Msk

#define IS_ADC_ALL_INSTANCE(INSTANCE) (((INSTANCE) == ADC1) || \
                                       ((INSTANCE) == ADC2))

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC12_COMMON)

#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_DMA_CAPABILITY_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_CAN_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CAN1)

#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7))

#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD) || \
                                        ((INSTANCE) == GPIOE))

#define IS_GPIO_AF_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

#define IS_I2C_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                       ((INSTANCE) == I2C2))

#define IS_SMBUS_ALL_INSTANCE         IS_I2C_ALL_INSTANCE

#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2))

#define IS_TIM_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_ADVANCED_INSTANCE(INSTANCE) ((INSTANCE) == TIM1)

#define IS_TIM_CC1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_CC2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_CC3_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_CC4_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_DMABURST_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_BREAK_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)

#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM2) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM3) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM4) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4))))

#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
    (((INSTANCE) == TIM1) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))

#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)

#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_DMA_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4))

#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)

#define IS_TIM_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1)    || \
                                        ((INSTANCE) == TIM2)    || \
                                        ((INSTANCE) == TIM3)    || \
                                        ((INSTANCE) == TIM4))

#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)    || \
                                                         ((INSTANCE) == TIM2)    || \
                                                         ((INSTANCE) == TIM3)    || \
                                                         ((INSTANCE) == TIM4))

#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE)           0U

#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2) || \
                                     ((INSTANCE) == USART3))

#define IS_UART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3))

#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                               ((INSTANCE) == USART2) || \
                                               ((INSTANCE) == USART3))

#define IS_UART_LIN_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) || \
                                        ((INSTANCE) == USART3))

#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2) || \
                                           ((INSTANCE) == USART3))

#define IS_SMARTCARD_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2) || \
                                         ((INSTANCE) == USART3))

#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3))

#define IS_UART_MULTIPROCESSOR_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                   ((INSTANCE) == USART2) || \
                                                   ((INSTANCE) == USART3))

#define IS_UART_DMA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) || \
                                        ((INSTANCE) == USART3))

#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)

#define IS_PCD_ALL_INSTANCE(INSTANCE)   ((INSTANCE) == USB)

#define RCC_HSE_MIN         4000000U
#define RCC_HSE_MAX        16000000U

#define RCC_MAX_FREQUENCY  72000000U

#define ADC1_IRQn               ADC1_2_IRQn
#define TIM9_IRQn               TIM1_BRK_IRQn
#define TIM1_BRK_TIM9_IRQn      TIM1_BRK_IRQn
#define TIM1_BRK_TIM15_IRQn     TIM1_BRK_IRQn
#define TIM1_TRG_COM_TIM17_IRQn TIM1_TRG_COM_IRQn
#define TIM1_TRG_COM_TIM11_IRQn TIM1_TRG_COM_IRQn
#define TIM11_IRQn              TIM1_TRG_COM_IRQn
#define TIM10_IRQn              TIM1_UP_IRQn
#define TIM1_UP_TIM10_IRQn      TIM1_UP_IRQn
#define TIM1_UP_TIM16_IRQn      TIM1_UP_IRQn
#define OTG_FS_WKUP_IRQn        USBWakeUp_IRQn
#define CEC_IRQn                USBWakeUp_IRQn
#define USB_HP_IRQn             USB_HP_CAN1_TX_IRQn
#define CAN1_TX_IRQn            USB_HP_CAN1_TX_IRQn
#define CAN1_RX0_IRQn           USB_LP_CAN1_RX0_IRQn
#define USB_LP_IRQn             USB_LP_CAN1_RX0_IRQn

#define ADC1_IRQHandler               ADC1_2_IRQHandler
#define TIM9_IRQHandler               TIM1_BRK_IRQHandler
#define TIM1_BRK_TIM9_IRQHandler      TIM1_BRK_IRQHandler
#define TIM1_BRK_TIM15_IRQHandler     TIM1_BRK_IRQHandler
#define TIM1_TRG_COM_TIM17_IRQHandler TIM1_TRG_COM_IRQHandler
#define TIM1_TRG_COM_TIM11_IRQHandler TIM1_TRG_COM_IRQHandler
#define TIM11_IRQHandler              TIM1_TRG_COM_IRQHandler
#define TIM10_IRQHandler              TIM1_UP_IRQHandler
#define TIM1_UP_TIM10_IRQHandler      TIM1_UP_IRQHandler
#define TIM1_UP_TIM16_IRQHandler      TIM1_UP_IRQHandler
#define OTG_FS_WKUP_IRQHandler        USBWakeUp_IRQHandler
#define CEC_IRQHandler                USBWakeUp_IRQHandler
#define USB_HP_IRQHandler             USB_HP_CAN1_TX_IRQHandler
#define CAN1_TX_IRQHandler            USB_HP_CAN1_TX_IRQHandler
#define CAN1_RX0_IRQHandler           USB_LP_CAN1_RX0_IRQHandler
#define USB_LP_IRQHandler             USB_LP_CAN1_RX0_IRQHandler

#ifdef __cplusplus
  }
#endif

#endif

