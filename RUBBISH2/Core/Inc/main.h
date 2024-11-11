/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define PUSH2_Pin GPIO_PIN_0
#define PUSH2_GPIO_Port GPIOA
#define PUSH1_Pin GPIO_PIN_1
#define PUSH1_GPIO_Port GPIOA
#define TX_Pin GPIO_PIN_2
#define TX_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_3
#define RX_GPIO_Port GPIOA
#define SERVO1_Pin GPIO_PIN_6
#define SERVO1_GPIO_Port GPIOA
#define SERVO2_Pin GPIO_PIN_7
#define SERVO2_GPIO_Port GPIOA
#define BUTTON_Pin GPIO_PIN_12
#define BUTTON_GPIO_Port GPIOB
#define ENA1_Pin GPIO_PIN_15
#define ENA1_GPIO_Port GPIOB
#define PUL1_Pin GPIO_PIN_8
#define PUL1_GPIO_Port GPIOA
#define DIR1_Pin GPIO_PIN_9
#define DIR1_GPIO_Port GPIOA
#define ENA2_Pin GPIO_PIN_10
#define ENA2_GPIO_Port GPIOA
#define PUL2_Pin GPIO_PIN_11
#define PUL2_GPIO_Port GPIOA
#define DIR2_Pin GPIO_PIN_12
#define DIR2_GPIO_Port GPIOA
#define SENSOR1_Pin GPIO_PIN_5
#define SENSOR1_GPIO_Port GPIOB
#define SENSOR2_Pin GPIO_PIN_6
#define SENSOR2_GPIO_Port GPIOB
#define SENSOR3_Pin GPIO_PIN_7
#define SENSOR3_GPIO_Port GPIOB
#define SENSOR4_Pin GPIO_PIN_8
#define SENSOR4_GPIO_Port GPIOB
#define SENSOR5_Pin GPIO_PIN_9
#define SENSOR5_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
