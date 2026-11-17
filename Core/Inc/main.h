/* USER CODE BEGIN Header */

/* USER CODE END Header */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* USER CODE BEGIN EM */

/* USER CODE END EM */

void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#define LED0_Pin GPIO_PIN_0
#define LED0_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOA
#define KEY_DIR_Pin GPIO_PIN_11
#define KEY_DIR_GPIO_Port GPIOA
#define KEY_DIR_EXTI_IRQn EXTI15_10_IRQn
#define KEY_PAUSE_Pin GPIO_PIN_12
#define KEY_PAUSE_GPIO_Port GPIOA
#define KEY_PAUSE_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif
