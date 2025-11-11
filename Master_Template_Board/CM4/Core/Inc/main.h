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
void MX_I2C1_Init(void);
void MX_I2C2_Init(void);
void MX_I2C4_Init(void);
void MX_SPI2_Init(void);
void MX_SPI5_Init(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DO_Pin GPIO_PIN_3
#define DO_GPIO_Port GPIOE
#define D1_Pin GPIO_PIN_4
#define D1_GPIO_Port GPIOE
#define D2_Pin GPIO_PIN_5
#define D2_GPIO_Port GPIOE
#define D3_Pin GPIO_PIN_6
#define D3_GPIO_Port GPIOE
#define SDA_2_Pin GPIO_PIN_0
#define SDA_2_GPIO_Port GPIOF
#define SCL_2_Pin GPIO_PIN_1
#define SCL_2_GPIO_Port GPIOF
#define D4_Pin GPIO_PIN_2
#define D4_GPIO_Port GPIOF
#define D5_Pin GPIO_PIN_3
#define D5_GPIO_Port GPIOF
#define D6_Pin GPIO_PIN_4
#define D6_GPIO_Port GPIOF
#define D7_Pin GPIO_PIN_5
#define D7_GPIO_Port GPIOF
#define NSS_5_Pin GPIO_PIN_6
#define NSS_5_GPIO_Port GPIOF
#define CLK_5_Pin GPIO_PIN_7
#define CLK_5_GPIO_Port GPIOF
#define MISO_5_Pin GPIO_PIN_8
#define MISO_5_GPIO_Port GPIOF
#define MOSI_5_Pin GPIO_PIN_9
#define MOSI_5_GPIO_Port GPIOF
#define D8_Pin GPIO_PIN_10
#define D8_GPIO_Port GPIOF
#define D9_Pin GPIO_PIN_4
#define D9_GPIO_Port GPIOA
#define D10_Pin GPIO_PIN_6
#define D10_GPIO_Port GPIOA
#define D11_Pin GPIO_PIN_7
#define D11_GPIO_Port GPIOA
#define D12_Pin GPIO_PIN_4
#define D12_GPIO_Port GPIOC
#define D13_Pin GPIO_PIN_5
#define D13_GPIO_Port GPIOC
#define D14_Pin GPIO_PIN_0
#define D14_GPIO_Port GPIOB
#define D15_Pin GPIO_PIN_1
#define D15_GPIO_Port GPIOB
#define D16_Pin GPIO_PIN_2
#define D16_GPIO_Port GPIOB
#define D17_Pin GPIO_PIN_11
#define D17_GPIO_Port GPIOF
#define A0_Pin GPIO_PIN_12
#define A0_GPIO_Port GPIOF
#define A1_Pin GPIO_PIN_13
#define A1_GPIO_Port GPIOF
#define A2_Pin GPIO_PIN_14
#define A2_GPIO_Port GPIOF
#define A3_Pin GPIO_PIN_15
#define A3_GPIO_Port GPIOF
#define A4_Pin GPIO_PIN_0
#define A4_GPIO_Port GPIOG
#define A5_Pin GPIO_PIN_1
#define A5_GPIO_Port GPIOG
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
#define M4_Green_LED_Pin GPIO_PIN_1
#define M4_Green_LED_GPIO_Port GPIOD
#define M4_Red_LED_Pin GPIO_PIN_3
#define M4_Red_LED_GPIO_Port GPIOD
#define M4_Blue_LED_Pin GPIO_PIN_4
#define M4_Blue_LED_GPIO_Port GPIOD
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
