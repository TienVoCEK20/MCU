/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
extern uint8_t choosing_value_mode_flag;
extern uint8_t changing_mode_flag;
extern uint8_t value_chosen_flag;
extern uint8_t increment_value_flag;
extern uint8_t increment_value_every_500ms_flag;

extern void setTimerIncrement(int duration);
extern int timer0_counter;
extern void setTimer1s(int duration);
extern int timer2_flag;
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
#define dis0_0_Pin GPIO_PIN_1
#define dis0_0_GPIO_Port GPIOA
#define dis0_1_Pin GPIO_PIN_2
#define dis0_1_GPIO_Port GPIOA
#define dis0_2_Pin GPIO_PIN_3
#define dis0_2_GPIO_Port GPIOA
#define dis0_3_Pin GPIO_PIN_4
#define dis0_3_GPIO_Port GPIOA
#define dis0_4_Pin GPIO_PIN_5
#define dis0_4_GPIO_Port GPIOA
#define dis0_5_Pin GPIO_PIN_6
#define dis0_5_GPIO_Port GPIOA
#define dis0_6_Pin GPIO_PIN_7
#define dis0_6_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_0
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_1
#define BUTTON_2_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_2
#define BUTTON_3_GPIO_Port GPIOB
#define traffic1_Pin GPIO_PIN_10
#define traffic1_GPIO_Port GPIOB
#define traffic2_Pin GPIO_PIN_11
#define traffic2_GPIO_Port GPIOB
#define traffic3_Pin GPIO_PIN_12
#define traffic3_GPIO_Port GPIOB
#define traffic4_Pin GPIO_PIN_13
#define traffic4_GPIO_Port GPIOB
#define traffic5_Pin GPIO_PIN_14
#define traffic5_GPIO_Port GPIOB
#define traffic6_Pin GPIO_PIN_15
#define traffic6_GPIO_Port GPIOB
#define dis1_0_Pin GPIO_PIN_8
#define dis1_0_GPIO_Port GPIOA
#define dis1_1_Pin GPIO_PIN_9
#define dis1_1_GPIO_Port GPIOA
#define dis1_2_Pin GPIO_PIN_10
#define dis1_2_GPIO_Port GPIOA
#define dis1_3_Pin GPIO_PIN_11
#define dis1_3_GPIO_Port GPIOA
#define dis1_4_Pin GPIO_PIN_12
#define dis1_4_GPIO_Port GPIOA
#define dis1_5_Pin GPIO_PIN_13
#define dis1_5_GPIO_Port GPIOA
#define dis1_6_Pin GPIO_PIN_14
#define dis1_6_GPIO_Port GPIOA
#define red1_Pin GPIO_PIN_3
#define red1_GPIO_Port GPIOB
#define yellow1_Pin GPIO_PIN_4
#define yellow1_GPIO_Port GPIOB
#define green1_Pin GPIO_PIN_5
#define green1_GPIO_Port GPIOB
#define red2_Pin GPIO_PIN_6
#define red2_GPIO_Port GPIOB
#define yellow2_Pin GPIO_PIN_7
#define yellow2_GPIO_Port GPIOB
#define green2_Pin GPIO_PIN_8
#define green2_GPIO_Port GPIOB
#define traffic0_Pin GPIO_PIN_9
#define traffic0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
