/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SDA_2_Pin GPIO_PIN_0
#define SDA_2_GPIO_Port GPIOF
#define SCL_2_Pin GPIO_PIN_1
#define SCL_2_GPIO_Port GPIOF
#define NSS_5_Pin GPIO_PIN_6
#define NSS_5_GPIO_Port GPIOF
#define CLK_5_Pin GPIO_PIN_7
#define CLK_5_GPIO_Port GPIOF
#define MISO_5_Pin GPIO_PIN_8
#define MISO_5_GPIO_Port GPIOF
#define MOSI_5_Pin GPIO_PIN_9
#define MOSI_5_GPIO_Port GPIOF
#define NSS_2_Pin GPIO_PIN_12
#define NSS_2_GPIO_Port GPIOB
#define CLK_2_Pin GPIO_PIN_13
#define CLK_2_GPIO_Port GPIOB
#define MISO_2_Pin GPIO_PIN_14
#define MISO_2_GPIO_Port GPIOB
#define MOSI_2_Pin GPIO_PIN_15
#define MOSI_2_GPIO_Port GPIOB
#define SCL_4_Pin GPIO_PIN_12
#define SCL_4_GPIO_Port GPIOD
#define SCL_4D13_Pin GPIO_PIN_13
#define SCL_4D13_GPIO_Port GPIOD
#define M7_Green_LED_Pin GPIO_PIN_5
#define M7_Green_LED_GPIO_Port GPIOD
#define M7_Red_LED_Pin GPIO_PIN_6
#define M7_Red_LED_GPIO_Port GPIOD
#define M7_Blue_LED_Pin GPIO_PIN_7
#define M7_Blue_LED_GPIO_Port GPIOD
#define SDA_1_Pin GPIO_PIN_8
#define SDA_1_GPIO_Port GPIOB
#define SCL_1_Pin GPIO_PIN_9
#define SCL_1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
