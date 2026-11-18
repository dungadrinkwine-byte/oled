#ifndef __STM32F1xx_HAL_FLASH_EX_H
#define __STM32F1xx_HAL_FLASH_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f1xx_hal_def.h"

#define FLASH_SIZE_DATA_REGISTER     0x1FFFF7E0U
#define OBR_REG_INDEX                1U
#define SR_FLAG_MASK                 ((uint32_t)(FLASH_SR_BSY | FLASH_SR_PGERR | FLASH_SR_WRPRTERR | FLASH_SR_EOP))

#define IS_FLASH_TYPEERASE(VALUE)   (((VALUE) == FLASH_TYPEERASE_PAGES) || ((VALUE) == FLASH_TYPEERASE_MASSERASE))

#define IS_OPTIONBYTE(VALUE)        (((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER | OPTIONBYTE_DATA)))

#define IS_WRPSTATE(VALUE)          (((VALUE) == OB_WRPSTATE_DISABLE) || ((VALUE) == OB_WRPSTATE_ENABLE))

#define IS_OB_RDP_LEVEL(LEVEL)      (((LEVEL) == OB_RDP_LEVEL_0) || ((LEVEL) == OB_RDP_LEVEL_1))

#define IS_OB_DATA_ADDRESS(ADDRESS) (((ADDRESS) == OB_DATA_ADDRESS_DATA0) || ((ADDRESS) == OB_DATA_ADDRESS_DATA1))

#define IS_OB_IWDG_SOURCE(SOURCE)   (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))

#define IS_OB_STOP_SOURCE(SOURCE)   (((SOURCE) == OB_STOP_NO_RST) || ((SOURCE) == OB_STOP_RST))

#define IS_OB_STDBY_SOURCE(SOURCE)  (((SOURCE) == OB_STDBY_NO_RST) || ((SOURCE) == OB_STDBY_RST))

#if defined(FLASH_BANK2_END)
#define IS_OB_BOOT1(BOOT1)         (((BOOT1) == OB_BOOT1_RESET) || ((BOOT1) == OB_BOOT1_SET))
#endif

#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08003FFFU))
#endif

#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08003FFFU))))
#endif

#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0807FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0805FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU)))
#endif

#if defined(FLASH_BANK2_END)
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080FFFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080BFFFFU))
#endif

#if (defined(STM32F105xC) || defined(STM32F107xC))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) ==  0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU)))
#endif

#define IS_OB_WRP(PAGE) (((PAGE) != 0x0000000U))

#if defined(FLASH_BANK2_END)
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1)  || \
                             ((BANK) == FLASH_BANK_2)  || \
                             ((BANK) == FLASH_BANK_BOTH))
#else
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1))
#endif

#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS)  (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                            ((ADDRESS) <= FLASH_BANK1_END) :  ((ADDRESS) <= 0x08003FFFU)))

#endif

#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? \
                                           ((ADDRESS) <= 0x0800FFFF) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                           ((ADDRESS) <= 0x08007FFF) :  ((ADDRESS) <= 0x08003FFFU)))))

#endif

#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? \
                                           ((ADDRESS) <= 0x0805FFFFU) :  ((ADDRESS) <= 0x0803FFFFU))))

#endif

#if defined(FLASH_BANK2_END)
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? \
                                           ((ADDRESS) <= FLASH_BANK2_END) :  ((ADDRESS) <= 0x080BFFFFU)))

#endif

#if (defined(STM32F105xC) || defined(STM32F107xC))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= 0x0801FFFFU) :  ((ADDRESS) <= 0x0800FFFFU))))

#endif

typedef struct
{
  uint32_t TypeErase;

  uint32_t Banks;

  uint32_t PageAddress;

  uint32_t NbPages;

} FLASH_EraseInitTypeDef;

typedef struct
{
  uint32_t OptionType;

  uint32_t WRPState;

  uint32_t WRPPage;

  uint32_t Banks;

  uint8_t RDPLevel;

#if defined(FLASH_BANK2_END)
  uint8_t USERConfig;

#else
  uint8_t USERConfig;

#endif

  uint32_t DATAAddress;

  uint8_t DATAData;

} FLASH_OBProgramInitTypeDef;

#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define FLASH_PAGE_SIZE          0x400U
#endif

#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG) || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC))
#define FLASH_PAGE_SIZE          0x800U
#endif

#define FLASH_TYPEERASE_PAGES     0x00U
#define FLASH_TYPEERASE_MASSERASE 0x02U

#if defined(FLASH_BANK2_END)
#define FLASH_BANK_1     1U
#define FLASH_BANK_2     2U
#define FLASH_BANK_BOTH  ((uint32_t)FLASH_BANK_1 | FLASH_BANK_2)

#else
#define FLASH_BANK_1     1U
#endif

#define OPTIONBYTE_WRP            0x01U
#define OPTIONBYTE_RDP            0x02U
#define OPTIONBYTE_USER           0x04U
#define OPTIONBYTE_DATA           0x08U

#define OB_WRPSTATE_DISABLE       0x00U
#define OB_WRPSTATE_ENABLE        0x01U

#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) \
  || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) \
  || defined(STM32F103xB)
#define OB_WRP_PAGES0TO3               0x00000001U
#define OB_WRP_PAGES4TO7               0x00000002U
#define OB_WRP_PAGES8TO11              0x00000004U
#define OB_WRP_PAGES12TO15             0x00000008U
#define OB_WRP_PAGES16TO19             0x00000010U
#define OB_WRP_PAGES20TO23             0x00000020U
#define OB_WRP_PAGES24TO27             0x00000040U
#define OB_WRP_PAGES28TO31             0x00000080U
#endif

#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
#define OB_WRP_PAGES32TO35             0x00000100U
#define OB_WRP_PAGES36TO39             0x00000200U
#define OB_WRP_PAGES40TO43             0x00000400U
#define OB_WRP_PAGES44TO47             0x00000800U
#define OB_WRP_PAGES48TO51             0x00001000U
#define OB_WRP_PAGES52TO55             0x00002000U
#define OB_WRP_PAGES56TO59             0x00004000U
#define OB_WRP_PAGES60TO63             0x00008000U
#define OB_WRP_PAGES64TO67             0x00010000U
#define OB_WRP_PAGES68TO71             0x00020000U
#define OB_WRP_PAGES72TO75             0x00040000U
#define OB_WRP_PAGES76TO79             0x00080000U
#define OB_WRP_PAGES80TO83             0x00100000U
#define OB_WRP_PAGES84TO87             0x00200000U
#define OB_WRP_PAGES88TO91             0x00400000U
#define OB_WRP_PAGES92TO95             0x00800000U
#define OB_WRP_PAGES96TO99             0x01000000U
#define OB_WRP_PAGES100TO103           0x02000000U
#define OB_WRP_PAGES104TO107           0x04000000U
#define OB_WRP_PAGES108TO111           0x08000000U
#define OB_WRP_PAGES112TO115           0x10000000U
#define OB_WRP_PAGES116TO119           0x20000000U
#define OB_WRP_PAGES120TO123           0x40000000U
#define OB_WRP_PAGES124TO127           0x80000000U
#endif

#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE) \
  || defined(STM32F101xG) || defined(STM32F103xG) \
  || defined(STM32F105xC) || defined(STM32F107xC)
#define OB_WRP_PAGES0TO1               0x00000001U
#define OB_WRP_PAGES2TO3               0x00000002U
#define OB_WRP_PAGES4TO5               0x00000004U
#define OB_WRP_PAGES6TO7               0x00000008U
#define OB_WRP_PAGES8TO9               0x00000010U
#define OB_WRP_PAGES10TO11             0x00000020U
#define OB_WRP_PAGES12TO13             0x00000040U
#define OB_WRP_PAGES14TO15             0x00000080U
#define OB_WRP_PAGES16TO17             0x00000100U
#define OB_WRP_PAGES18TO19             0x00000200U
#define OB_WRP_PAGES20TO21             0x00000400U
#define OB_WRP_PAGES22TO23             0x00000800U
#define OB_WRP_PAGES24TO25             0x00001000U
#define OB_WRP_PAGES26TO27             0x00002000U
#define OB_WRP_PAGES28TO29             0x00004000U
#define OB_WRP_PAGES30TO31             0x00008000U
#define OB_WRP_PAGES32TO33             0x00010000U
#define OB_WRP_PAGES34TO35             0x00020000U
#define OB_WRP_PAGES36TO37             0x00040000U
#define OB_WRP_PAGES38TO39             0x00080000U
#define OB_WRP_PAGES40TO41             0x00100000U
#define OB_WRP_PAGES42TO43             0x00200000U
#define OB_WRP_PAGES44TO45             0x00400000U
#define OB_WRP_PAGES46TO47             0x00800000U
#define OB_WRP_PAGES48TO49             0x01000000U
#define OB_WRP_PAGES50TO51             0x02000000U
#define OB_WRP_PAGES52TO53             0x04000000U
#define OB_WRP_PAGES54TO55             0x08000000U
#define OB_WRP_PAGES56TO57             0x10000000U
#define OB_WRP_PAGES58TO59             0x20000000U
#define OB_WRP_PAGES60TO61             0x40000000U
#define OB_WRP_PAGES62TO127            0x80000000U
#define OB_WRP_PAGES62TO255            0x80000000U
#define OB_WRP_PAGES62TO511            0x80000000U
#endif

#define OB_WRP_ALLPAGES                0xFFFFFFFFU

#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6)
#define OB_WRP_PAGES0TO31MASK          0x000000FFU
#endif

#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
#define OB_WRP_PAGES0TO31MASK          0x000000FFU
#define OB_WRP_PAGES32TO63MASK         0x0000FF00U
#define OB_WRP_PAGES64TO95MASK         0x00FF0000U
#define OB_WRP_PAGES96TO127MASK        0xFF000000U
#endif

#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE)
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
#define OB_WRP_PAGES48TO255MASK        0xFF000000U
#endif

#if  defined(STM32F101xG) || defined(STM32F103xG)
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
#define OB_WRP_PAGES48TO511MASK        0xFF000000U
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
#define OB_WRP_PAGES48TO127MASK        0xFF000000U
#endif

#define OB_RDP_LEVEL_0            ((uint8_t)0xA5)
#define OB_RDP_LEVEL_1            ((uint8_t)0x00)

#define OB_IWDG_SW                ((uint16_t)0x0001)
#define OB_IWDG_HW                ((uint16_t)0x0000)

#define OB_STOP_NO_RST            ((uint16_t)0x0002)
#define OB_STOP_RST               ((uint16_t)0x0000)

#define OB_STDBY_NO_RST           ((uint16_t)0x0004)
#define OB_STDBY_RST              ((uint16_t)0x0000)

#if defined(FLASH_BANK2_END)

#define OB_BOOT1_RESET            ((uint16_t)0x0000)
#define OB_BOOT1_SET              ((uint16_t)0x0008)

#endif

#define OB_DATA_ADDRESS_DATA0     0x1FFFF804U
#define OB_DATA_ADDRESS_DATA1     0x1FFFF806U

#if defined(FLASH_BANK2_END)
 #define FLASH_FLAG_BSY             FLASH_FLAG_BSY_BANK1
 #define FLASH_FLAG_PGERR           FLASH_FLAG_PGERR_BANK1
 #define FLASH_FLAG_WRPERR          FLASH_FLAG_WRPERR_BANK1
 #define FLASH_FLAG_EOP             FLASH_FLAG_EOP_BANK1

 #define FLASH_FLAG_BSY_BANK1       FLASH_SR_BSY
 #define FLASH_FLAG_PGERR_BANK1     FLASH_SR_PGERR
 #define FLASH_FLAG_WRPERR_BANK1    FLASH_SR_WRPRTERR
 #define FLASH_FLAG_EOP_BANK1       FLASH_SR_EOP

 #define FLASH_FLAG_BSY_BANK2       (FLASH_SR2_BSY << 16U)
 #define FLASH_FLAG_PGERR_BANK2     (FLASH_SR2_PGERR << 16U)
 #define FLASH_FLAG_WRPERR_BANK2    (FLASH_SR2_WRPRTERR << 16U)
 #define FLASH_FLAG_EOP_BANK2       (FLASH_SR2_EOP << 16U)

#else

 #define FLASH_FLAG_BSY             FLASH_SR_BSY
 #define FLASH_FLAG_PGERR           FLASH_SR_PGERR
 #define FLASH_FLAG_WRPERR          FLASH_SR_WRPRTERR
 #define FLASH_FLAG_EOP             FLASH_SR_EOP

#endif
 #define FLASH_FLAG_OPTVERR         ((OBR_REG_INDEX << 8U | FLASH_OBR_OPTERR))

#if defined(FLASH_BANK2_END)
 #define FLASH_IT_EOP               FLASH_IT_EOP_BANK1
 #define FLASH_IT_ERR               FLASH_IT_ERR_BANK1

 #define FLASH_IT_EOP_BANK1         FLASH_CR_EOPIE
 #define FLASH_IT_ERR_BANK1         FLASH_CR_ERRIE

 #define FLASH_IT_EOP_BANK2         (FLASH_CR2_EOPIE << 16U)
 #define FLASH_IT_ERR_BANK2         (FLASH_CR2_ERRIE << 16U)

#else

 #define FLASH_IT_EOP               FLASH_CR_EOPIE
 #define FLASH_IT_ERR               FLASH_CR_ERRIE

#endif

#if defined(FLASH_BANK2_END)

#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  do { \
                            \
                          SET_BIT(FLASH->CR, ((__INTERRUPT__) & 0x0000FFFFU)); \
                            \
                          SET_BIT(FLASH->CR2, ((__INTERRUPT__) >> 16U)); \
                    } while(0U)

#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)  do { \
                            \
                          CLEAR_BIT(FLASH->CR, ((__INTERRUPT__) & 0x0000FFFFU)); \
                            \
                          CLEAR_BIT(FLASH->CR2, ((__INTERRUPT__) >> 16U)); \
                    } while(0U)

#define __HAL_FLASH_GET_FLAG(__FLAG__) (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                        ((((__FLAG__) & SR_FLAG_MASK) != RESET)? \
                                            (FLASH->SR & ((__FLAG__) & SR_FLAG_MASK)) : \
                                            (FLASH->SR2 & ((__FLAG__) >> 16U))))

#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)  do { \
                            \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                            \
                          if (((__FLAG__) & SR_FLAG_MASK) != RESET) \
                          { \
                            FLASH->SR  = ((__FLAG__) & SR_FLAG_MASK); \
                          } \
                            \
                          if (((__FLAG__) >> 16U) != RESET) \
                          { \
                            FLASH->SR2 = ((__FLAG__) >> 16U); \
                          } \
                          } \
                    } while(0U)
#else

#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  (FLASH->CR |= (__INTERRUPT__))

#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)   (FLASH->CR &= ~(__INTERRUPT__))

#define __HAL_FLASH_GET_FLAG(__FLAG__)  (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                            (FLASH->SR & (__FLAG__)))

#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)   do { \
                            \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                              \
                            FLASH->SR  = (__FLAG__); \
                          } \
                    } while(0U)

#endif

HAL_StatusTypeDef  HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);
HAL_StatusTypeDef  HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);

HAL_StatusTypeDef  HAL_FLASHEx_OBErase(void);
HAL_StatusTypeDef  HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void               HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
uint32_t           HAL_FLASHEx_OBGetUserData(uint32_t DATAAdress);

#ifdef __cplusplus
}
#endif

#endif

