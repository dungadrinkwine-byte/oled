#ifndef STM32F1xx_HAL_GPIO_H
#define STM32F1xx_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal_def.h"

typedef struct
{
  uint32_t Pin;

  uint32_t Mode;

  uint32_t Pull;

  uint32_t Speed;

} GPIO_InitTypeDef;

typedef enum
{
  GPIO_PIN_RESET = 0u,
  GPIO_PIN_SET
} GPIO_PinState;

#define GPIO_PIN_0                 ((uint16_t)0x0001)
#define GPIO_PIN_1                 ((uint16_t)0x0002)
#define GPIO_PIN_2                 ((uint16_t)0x0004)
#define GPIO_PIN_3                 ((uint16_t)0x0008)
#define GPIO_PIN_4                 ((uint16_t)0x0010)
#define GPIO_PIN_5                 ((uint16_t)0x0020)
#define GPIO_PIN_6                 ((uint16_t)0x0040)
#define GPIO_PIN_7                 ((uint16_t)0x0080)
#define GPIO_PIN_8                 ((uint16_t)0x0100)
#define GPIO_PIN_9                 ((uint16_t)0x0200)
#define GPIO_PIN_10                ((uint16_t)0x0400)
#define GPIO_PIN_11                ((uint16_t)0x0800)
#define GPIO_PIN_12                ((uint16_t)0x1000)
#define GPIO_PIN_13                ((uint16_t)0x2000)
#define GPIO_PIN_14                ((uint16_t)0x4000)
#define GPIO_PIN_15                ((uint16_t)0x8000)
#define GPIO_PIN_All               ((uint16_t)0xFFFF)

#define GPIO_PIN_MASK              0x0000FFFFu

#define  GPIO_MODE_INPUT                        0x00000000u
#define  GPIO_MODE_OUTPUT_PP                    0x00000001u
#define  GPIO_MODE_OUTPUT_OD                    0x00000011u
#define  GPIO_MODE_AF_PP                        0x00000002u
#define  GPIO_MODE_AF_OD                        0x00000012u
#define  GPIO_MODE_AF_INPUT                     GPIO_MODE_INPUT

#define  GPIO_MODE_ANALOG                       0x00000003u

#define  GPIO_MODE_IT_RISING                    0x10110000u
#define  GPIO_MODE_IT_FALLING                   0x10210000u
#define  GPIO_MODE_IT_RISING_FALLING            0x10310000u

#define  GPIO_MODE_EVT_RISING                   0x10120000u
#define  GPIO_MODE_EVT_FALLING                  0x10220000u
#define  GPIO_MODE_EVT_RISING_FALLING           0x10320000u

#define  GPIO_SPEED_FREQ_LOW              (GPIO_CRL_MODE0_1)
#define  GPIO_SPEED_FREQ_MEDIUM           (GPIO_CRL_MODE0_0)
#define  GPIO_SPEED_FREQ_HIGH             (GPIO_CRL_MODE0)

#define  GPIO_NOPULL        0x00000000u
#define  GPIO_PULLUP        0x00000001u
#define  GPIO_PULLDOWN      0x00000002u

#define __HAL_GPIO_EXTI_GET_FLAG(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_CLEAR_FLAG(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_GET_IT(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_CLEAR_IT(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_GENERATE_SWIT(__EXTI_LINE__) (EXTI->SWIER |= (__EXTI_LINE__))

#include "stm32f1xx_hal_gpio_ex.h"

void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#define IS_GPIO_PIN_ACTION(ACTION) (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))
#define IS_GPIO_PIN(PIN)           (((((uint32_t)PIN) & GPIO_PIN_MASK ) != 0x00u) && ((((uint32_t)PIN) & ~GPIO_PIN_MASK) == 0x00u))
#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_MODE_INPUT)              ||\
                            ((MODE) == GPIO_MODE_OUTPUT_PP)          ||\
                            ((MODE) == GPIO_MODE_OUTPUT_OD)          ||\
                            ((MODE) == GPIO_MODE_AF_PP)              ||\
                            ((MODE) == GPIO_MODE_AF_OD)              ||\
                            ((MODE) == GPIO_MODE_IT_RISING)          ||\
                            ((MODE) == GPIO_MODE_IT_FALLING)         ||\
                            ((MODE) == GPIO_MODE_IT_RISING_FALLING)  ||\
                            ((MODE) == GPIO_MODE_EVT_RISING)         ||\
                            ((MODE) == GPIO_MODE_EVT_FALLING)        ||\
                            ((MODE) == GPIO_MODE_EVT_RISING_FALLING) ||\
                            ((MODE) == GPIO_MODE_ANALOG))
#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_SPEED_FREQ_LOW) || \
                              ((SPEED) == GPIO_SPEED_FREQ_MEDIUM) || ((SPEED) == GPIO_SPEED_FREQ_HIGH))
#define IS_GPIO_PULL(PULL) (((PULL) == GPIO_NOPULL) || ((PULL) == GPIO_PULLUP) || \
                            ((PULL) == GPIO_PULLDOWN))

#ifdef __cplusplus
}
#endif

#endif

