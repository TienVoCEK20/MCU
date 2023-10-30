/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "input_reading.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
enum TrafficLightState {
    RED1_GREEN2,
	RED1_YELLOW2,
	GREEN1_RED2,
	YELLOW1_RED2,
  };
enum TrafficLightState current_traffic_state = RED1_GREEN2;
enum TrafficLightState next_traffic_state = RED1_GREEN2;

  // Initialize the current state of the traffic light
int red_light = 5;
int green_light = 3;
int yellow_light = 2;

int counter = 3 + 1;
int light1 = 5 + 1;
int light2 = 2;

int temp_change = 0;
int current_mod = 0;

uint8_t choosing_value_mode_flag = 0;
uint8_t changing_mode_flag = 0;
uint8_t value_chosen_flag = 0;
uint8_t increment_value_flag = 0;
uint8_t increment_value_every_500ms_flag = 0;

enum SYSTEM_RUNNING {
	  NORMAL,
	  RED_MODIFIED,
	  AMBIENT_MODIFED,
	  GREEN_MODIFED,
};
enum SYSTEM_RUNNING currentState = NORMAL;
enum SYSTEM_RUNNING nextState = NORMAL;

int TIMER_CYCLE = 10;

int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

void setTimerIncrement(int duration)
{
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}
void setTimerBlinking(int duration)
{
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}
void setTimer1s(int duration)
{
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}

void timer_run () {
	if(timer0_counter > 0) {
		timer0_counter --;
	}
	if(timer0_counter == 0) {
		timer0_flag = 1;
	}

	if(timer1_counter > 0) {
		timer1_counter --;
	}
	if(timer1_counter == 0)
	{
		timer1_flag = 1;
	}

	if(timer2_counter > 0) {
		timer2_counter --;
	}
	if(timer2_counter == 0)
	{
		timer2_flag = 1;
	}
}

void turn_on_pin_traffic(int pin, int state)
{
	switch(pin){
	case 1:
		HAL_GPIO_WritePin(traffic0_GPIO_Port, traffic0_Pin, state);
		break;
	case 2:
		HAL_GPIO_WritePin(traffic1_GPIO_Port, traffic1_Pin, state);
		break;
	case 3:
		HAL_GPIO_WritePin(traffic2_GPIO_Port, traffic2_Pin, state);
		break;
	case 4:
		HAL_GPIO_WritePin(traffic3_GPIO_Port, traffic3_Pin, state);
		break;
	case 5:
		HAL_GPIO_WritePin(traffic4_GPIO_Port, traffic4_Pin, state);
		break;
	case 6:
		HAL_GPIO_WritePin(traffic5_GPIO_Port, traffic5_Pin, state);
		break;
	case 7:
		HAL_GPIO_WritePin(traffic6_GPIO_Port, traffic6_Pin, state);
		break;
	}

}

void turn_on_pin_seg0(int pin, int state)
{
	switch(pin){
	case 1:
		HAL_GPIO_WritePin(dis0_0_GPIO_Port, dis0_0_Pin, state);
		break;
	case 2:
		HAL_GPIO_WritePin(dis0_1_GPIO_Port, dis0_1_Pin, state);
		break;
	case 3:
		HAL_GPIO_WritePin(dis0_2_GPIO_Port, dis0_2_Pin, state);
		break;
	case 4:
		HAL_GPIO_WritePin(dis0_3_GPIO_Port, dis0_3_Pin, state);
		break;
	case 5:
		HAL_GPIO_WritePin(dis0_4_GPIO_Port, dis0_4_Pin, state);
		break;
	case 6:
		HAL_GPIO_WritePin(dis0_5_GPIO_Port, dis0_5_Pin, state);
		break;
	case 7:
		HAL_GPIO_WritePin(dis0_6_GPIO_Port, dis0_6_Pin, state);
		break;
	}
}

void turn_on_pin_seg1(int pin, int state)
{
	switch(pin){
	case 1:
		HAL_GPIO_WritePin(dis1_0_GPIO_Port, dis1_0_Pin, state);
		break;
	case 2:
		HAL_GPIO_WritePin(dis1_1_GPIO_Port, dis1_1_Pin, state);
		break;
	case 3:
		HAL_GPIO_WritePin(dis1_2_GPIO_Port, dis1_2_Pin, state);
		break;
	case 4:
		HAL_GPIO_WritePin(dis1_3_GPIO_Port, dis1_3_Pin, state);
		break;
	case 5:
		HAL_GPIO_WritePin(dis1_4_GPIO_Port, dis1_4_Pin, state);
		break;
	case 6:
		HAL_GPIO_WritePin(dis1_5_GPIO_Port, dis1_5_Pin, state);
		break;
	case 7:
		HAL_GPIO_WritePin(dis1_6_GPIO_Port, dis1_6_Pin, state);
		break;
	}
}

int TRAFFIC = 0;
int SEG0 = 1;
int SEG1 = 2;

void display7SEG(int seg, int num)
{
	if (seg == TRAFFIC)
	{
		if (num == 0)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_RESET);
			turn_on_pin_traffic(5, GPIO_PIN_RESET);
			turn_on_pin_traffic(6, GPIO_PIN_RESET);
			turn_on_pin_traffic(7, GPIO_PIN_SET);
		}
		else if (num == 1)
		{
			turn_on_pin_traffic(1, GPIO_PIN_SET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_SET);
			turn_on_pin_traffic(5, GPIO_PIN_SET);
			turn_on_pin_traffic(6, GPIO_PIN_SET);
			turn_on_pin_traffic(7, GPIO_PIN_SET);
		}
		else if (num == 2)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_SET);
			turn_on_pin_traffic(4, GPIO_PIN_RESET);
			turn_on_pin_traffic(5, GPIO_PIN_RESET);
			turn_on_pin_traffic(6, GPIO_PIN_SET);
			turn_on_pin_traffic(7, GPIO_PIN_RESET);
		}
		else if (num == 3)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_RESET);
			turn_on_pin_traffic(5, GPIO_PIN_SET);
			turn_on_pin_traffic(6, GPIO_PIN_SET);
			turn_on_pin_traffic(7, GPIO_PIN_RESET);
		}
		else if (num == 4)
		{
			turn_on_pin_traffic(1, GPIO_PIN_SET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_SET);
			turn_on_pin_traffic(5, GPIO_PIN_SET);
			turn_on_pin_traffic(6, GPIO_PIN_RESET);
			turn_on_pin_traffic(7, GPIO_PIN_RESET);
		}
		else if (num == 5)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_SET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_RESET);
			turn_on_pin_traffic(5, GPIO_PIN_SET);
			turn_on_pin_traffic(6, GPIO_PIN_RESET);
			turn_on_pin_traffic(7, GPIO_PIN_RESET);
		}
		else if (num == 6)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_SET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_RESET);
			turn_on_pin_traffic(5, GPIO_PIN_RESET);
			turn_on_pin_traffic(6, GPIO_PIN_RESET);
			turn_on_pin_traffic(7, GPIO_PIN_RESET);
		}
		else if (num == 7)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_SET);
			turn_on_pin_traffic(5, GPIO_PIN_SET);
			turn_on_pin_traffic(6, GPIO_PIN_SET);
			turn_on_pin_traffic(7, GPIO_PIN_SET);
		}
		else if (num == 8)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_RESET);
			turn_on_pin_traffic(5, GPIO_PIN_RESET);
			turn_on_pin_traffic(6, GPIO_PIN_RESET);
			turn_on_pin_traffic(7, GPIO_PIN_RESET);
		}
		else if (num == 9)
		{
			turn_on_pin_traffic(1, GPIO_PIN_RESET);
			turn_on_pin_traffic(2, GPIO_PIN_RESET);
			turn_on_pin_traffic(3, GPIO_PIN_RESET);
			turn_on_pin_traffic(4, GPIO_PIN_RESET);
			turn_on_pin_traffic(5, GPIO_PIN_SET);
			turn_on_pin_traffic(6, GPIO_PIN_RESET);
			turn_on_pin_traffic(7, GPIO_PIN_RESET);
		}
	}
	if (seg == SEG0)
	{
		if (num == 0)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_RESET);
			turn_on_pin_seg0(5, GPIO_PIN_RESET);
			turn_on_pin_seg0(6, GPIO_PIN_RESET);
			turn_on_pin_seg0(7, GPIO_PIN_SET);
		}
		else if (num == 1)
		{
			turn_on_pin_seg0(1, GPIO_PIN_SET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_SET);
			turn_on_pin_seg0(5, GPIO_PIN_SET);
			turn_on_pin_seg0(6, GPIO_PIN_SET);
			turn_on_pin_seg0(7, GPIO_PIN_SET);
		}
		else if (num == 2)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_SET);
			turn_on_pin_seg0(4, GPIO_PIN_RESET);
			turn_on_pin_seg0(5, GPIO_PIN_RESET);
			turn_on_pin_seg0(6, GPIO_PIN_SET);
			turn_on_pin_seg0(7, GPIO_PIN_RESET);
		}
		else if (num == 3)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_RESET);
			turn_on_pin_seg0(5, GPIO_PIN_SET);
			turn_on_pin_seg0(6, GPIO_PIN_SET);
			turn_on_pin_seg0(7, GPIO_PIN_RESET);
		}
		else if (num == 4)
		{
			turn_on_pin_seg0(1, GPIO_PIN_SET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_SET);
			turn_on_pin_seg0(5, GPIO_PIN_SET);
			turn_on_pin_seg0(6, GPIO_PIN_RESET);
			turn_on_pin_seg0(7, GPIO_PIN_RESET);
		}
		else if (num == 5)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_SET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_RESET);
			turn_on_pin_seg0(5, GPIO_PIN_SET);
			turn_on_pin_seg0(6, GPIO_PIN_RESET);
			turn_on_pin_seg0(7, GPIO_PIN_RESET);
		}
		else if (num == 6)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_SET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_RESET);
			turn_on_pin_seg0(5, GPIO_PIN_RESET);
			turn_on_pin_seg0(6, GPIO_PIN_RESET);
			turn_on_pin_seg0(7, GPIO_PIN_RESET);
		}
		else if (num == 7)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_SET);
			turn_on_pin_seg0(5, GPIO_PIN_SET);
			turn_on_pin_seg0(6, GPIO_PIN_SET);
			turn_on_pin_seg0(7, GPIO_PIN_SET);
		}
		else if (num == 8)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_RESET);
			turn_on_pin_seg0(5, GPIO_PIN_RESET);
			turn_on_pin_seg0(6, GPIO_PIN_RESET);
			turn_on_pin_seg0(7, GPIO_PIN_RESET);
		}
		else if (num == 9)
		{
			turn_on_pin_seg0(1, GPIO_PIN_RESET);
			turn_on_pin_seg0(2, GPIO_PIN_RESET);
			turn_on_pin_seg0(3, GPIO_PIN_RESET);
			turn_on_pin_seg0(4, GPIO_PIN_RESET);
			turn_on_pin_seg0(5, GPIO_PIN_SET);
			turn_on_pin_seg0(6, GPIO_PIN_RESET);
			turn_on_pin_seg0(7, GPIO_PIN_RESET);
		}
	}
	if (seg == SEG1)
	{
		if (num == 0)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_RESET);
			turn_on_pin_seg1(5, GPIO_PIN_RESET);
			turn_on_pin_seg1(6, GPIO_PIN_RESET);
			turn_on_pin_seg1(7, GPIO_PIN_SET);
		}
		else if (num == 1)
		{
			turn_on_pin_seg1(1, GPIO_PIN_SET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_SET);
			turn_on_pin_seg1(5, GPIO_PIN_SET);
			turn_on_pin_seg1(6, GPIO_PIN_SET);
			turn_on_pin_seg1(7, GPIO_PIN_SET);
		}
		else if (num == 2)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_SET);
			turn_on_pin_seg1(4, GPIO_PIN_RESET);
			turn_on_pin_seg1(5, GPIO_PIN_RESET);
			turn_on_pin_seg1(6, GPIO_PIN_SET);
			turn_on_pin_seg1(7, GPIO_PIN_RESET);
		}
		else if (num == 3)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_RESET);
			turn_on_pin_seg1(5, GPIO_PIN_SET);
			turn_on_pin_seg1(6, GPIO_PIN_SET);
			turn_on_pin_seg1(7, GPIO_PIN_RESET);
		}
		else if (num == 4)
		{
			turn_on_pin_seg1(1, GPIO_PIN_SET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_SET);
			turn_on_pin_seg1(5, GPIO_PIN_SET);
			turn_on_pin_seg1(6, GPIO_PIN_RESET);
			turn_on_pin_seg1(7, GPIO_PIN_RESET);
		}
		else if (num == 5)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_SET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_RESET);
			turn_on_pin_seg1(5, GPIO_PIN_SET);
			turn_on_pin_seg1(6, GPIO_PIN_RESET);
			turn_on_pin_seg1(7, GPIO_PIN_RESET);
		}
		else if (num == 6)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_SET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_RESET);
			turn_on_pin_seg1(5, GPIO_PIN_RESET);
			turn_on_pin_seg1(6, GPIO_PIN_RESET);
			turn_on_pin_seg1(7, GPIO_PIN_RESET);
		}
		else if (num == 7)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_SET);
			turn_on_pin_seg1(5, GPIO_PIN_SET);
			turn_on_pin_seg1(6, GPIO_PIN_SET);
			turn_on_pin_seg1(7, GPIO_PIN_SET);
		}
		else if (num == 8)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_RESET);
			turn_on_pin_seg1(5, GPIO_PIN_RESET);
			turn_on_pin_seg1(6, GPIO_PIN_RESET);
			turn_on_pin_seg1(7, GPIO_PIN_RESET);
		}
		else if (num == 9)
		{
			turn_on_pin_seg1(1, GPIO_PIN_RESET);
			turn_on_pin_seg1(2, GPIO_PIN_RESET);
			turn_on_pin_seg1(3, GPIO_PIN_RESET);
			turn_on_pin_seg1(4, GPIO_PIN_RESET);
			turn_on_pin_seg1(5, GPIO_PIN_SET);
			turn_on_pin_seg1(6, GPIO_PIN_RESET);
			turn_on_pin_seg1(7, GPIO_PIN_RESET);
		}
	}

}

void display_value()
{
	int digit_tens;
	int digit_ones;
	if(temp_change <= 9 && temp_change >= 0)
	{
		display7SEG(SEG0, 0);
		display7SEG(SEG1, temp_change);
	}
	else if(temp_change >= 10 && temp_change <= 99)
	{
		digit_tens = temp_change/10;
		digit_ones = temp_change%10;
		display7SEG(SEG0, digit_tens);
		display7SEG(SEG1, digit_ones);
	}
}
void turn_off_display_value()
{

	display7SEG(SEG0, 0);
	display7SEG(SEG1, 0);

}

void choosing_red_value()
{
	if(increment_value_flag | increment_value_every_500ms_flag)
	{
		temp_change++;
		increment_value_flag = 0;
		increment_value_every_500ms_flag = 0;
	}
	display_value();
}

void choosing_yellow_value()
{
	if(increment_value_flag | increment_value_every_500ms_flag)
	{
		temp_change++;
		increment_value_flag = 0;
		increment_value_every_500ms_flag = 0;
	}
	display_value();
}

void choosing_green_value()
{
	if(increment_value_flag | increment_value_every_500ms_flag)
	{
		temp_change++;
		increment_value_flag = 0;
		increment_value_every_500ms_flag = 0;
	}
	display_value();
}

void save_red_value()
{
	red_light = temp_change;
	turn_off_display_value();
}

void save_yellow_value()
{
	yellow_light = temp_change;
	turn_off_display_value();
}

void save_green_value()
{
	green_light = temp_change;
	counter = green_light + 1;
	light1 = red_light + 1;
	light2 = red_light - green_light;
	current_traffic_state = RED1_GREEN2;
	next_traffic_state = RED1_GREEN2;
}

void blink_all_red()
{
	if(timer1_flag)
	{
		HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
		setTimerBlinking(250);
	}
	HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);
}

void blink_all_ambient()
{
	if(timer1_flag)
	{
		HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
		setTimerBlinking(250);
	}
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);
}

void blink_all_green()
{
	if(timer1_flag)
	{
		HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
		setTimerBlinking(250);
	}
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);
}
void display_mode(int mode)
{
	display7SEG(TRAFFIC, mode);
}

void clear_all_flag()
{
	choosing_value_mode_flag = 0;
	changing_mode_flag = 0;
	value_chosen_flag = 0;
	increment_value_flag = 0;
	increment_value_every_500ms_flag = 0;
}
void turnonTraffigLights(int state)
{
	  switch (state) {
	    case RED1_GREEN2:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);//Turn on LED RED1
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);//Turn off LED YELLOW1
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);//Turn off LED GREEN1

			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);//Turn off LED RED2
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);//Turn off LED YELLOW2
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);//Turn on LED GREEN2
	    	break;
	    case RED1_YELLOW2:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);//Turn on LED RED1
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);//Turn off LED YELLOW1
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);//Turn off LED GREEN1

			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);//Turn off LED RED2
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);//Turn on LED YELLOW2
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);//Turn off LED GREEN2
	    	break;
	    case GREEN1_RED2:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);//Turn off LED RED
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);//Turn off LED YELLOW
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);//Turn on LED GREEN

			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);//Turn on LED RED2
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);//Turn off LED YELLOW2
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);//Turn off LED GREEN2
	    	break;
	    case YELLOW1_RED2:
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);//Turn off LED RED
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);//Turn on LED YELLOW
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);//Turn off LED GREEN

			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);//Turn off LED RED1
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);//Turn on LED YELLOW1
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);//Turn off LED GREEN1
	    	break;
	  }
}

void displayTrafficLight1(int light1)
{
	display7SEG(TRAFFIC, light1);
}

void traffic_light_running()
{
	  displayTrafficLight1(light1);
	  switch (current_traffic_state) {
	    case RED1_GREEN2:
	    	turnonTraffigLights(RED1_GREEN2);
	      	if(timer2_flag)
	      	{
	    	    	counter--;
	    	    	light1--;
	    	    	light2--;
	    	    	setTimer1s(1000);
	      	}
	    	if(counter <= 0)
	    	{
	    		next_traffic_state = RED1_YELLOW2;
	    		light2 = yellow_light;
	    		counter = yellow_light;
	    	}
	    	break;
	    case RED1_YELLOW2:
	    	turnonTraffigLights(RED1_YELLOW2);
	    	if(timer2_flag)
	    	{
		    	counter--;
		    	light1--;
		    	light2--;
		    	setTimer1s(1000);
	    	}
	    	if(counter <= 0)
	    	{
	    		next_traffic_state = GREEN1_RED2;
		    	counter = green_light;
		    	light1 = green_light;
		    	light2 = red_light;
	    	}
	    	break;
	    case GREEN1_RED2:
	    	turnonTraffigLights(GREEN1_RED2);
	    	if(timer2_flag)
	    	{
		    	counter--;
		    	light1--;
		    	light2--;
		    	setTimer1s(1000);
	    	}
	    	if(counter <= 0)
	    	{
	    		next_traffic_state = YELLOW1_RED2;
		    	counter = yellow_light;
		    	light1 = yellow_light;
		    	light2 = red_light;
	    	}
	    	break;
	    case YELLOW1_RED2:
	    	turnonTraffigLights(YELLOW1_RED2);
	    	if(timer2_flag)
	    	{
		    	counter--;
		    	light1--;
		    	light2--;
		    	setTimer1s(1000);
	    	}
	    	if(counter <= 0)
	    	{
	    		next_traffic_state = RED1_GREEN2;
		    	counter = green_light;
		    	light1 = red_light;
		    	light2 = green_light;
	    	}
	    	break;
	  }
	  current_traffic_state = next_traffic_state;
}
void system_running()
{
			  switch (currentState) {
			  	    case NORMAL:
			  	    	traffic_light_running();
			  	    	turn_off_display_value();
			  	    	if(changing_mode_flag)
			  	    	{
			  	    		clear_all_flag();
				  	    	temp_change = red_light;
				  	    	setTimerBlinking(250);
			  	    		nextState  = RED_MODIFIED;
			  	    	}
			  	    	break;
			  	    case RED_MODIFIED:
			  	    	display_mode(1);
			  	    	blink_all_red();
			  	    	choosing_red_value();
			  	    	if(changing_mode_flag)
			  	    	{
			  	    		clear_all_flag();
				  	    	temp_change = yellow_light;
			  	    		nextState  = AMBIENT_MODIFED;
			  	    	}
			  	    	if(value_chosen_flag)
			  	    	{
			  	    		value_chosen_flag = 0;
			  	    		save_red_value();
			  	    	}
			  	    	break;
			  	    case AMBIENT_MODIFED:
			  	    	display_mode(2);
			  	    	blink_all_ambient();
			  	    	choosing_yellow_value();
			  	    	if(changing_mode_flag)
			  	    	{
			  	    		clear_all_flag();
				  	    	temp_change = green_light;
			  	    		nextState  = GREEN_MODIFED;
			  	    	}
			  	    	if(value_chosen_flag)
			  	    	{
			  	    		value_chosen_flag = 0;
			  	    		save_yellow_value();
			  	    	}
			  	    	break;
			  	    case GREEN_MODIFED:
			  	    	display_mode(3);
			  	    	blink_all_green();
			  	    	choosing_green_value();
			  	    	if(changing_mode_flag)
			  	    	{
			  	    		clear_all_flag();
				  	    	temp_change = 0;
			  	    		nextState  = NORMAL;
			  	    	}
			  	    	if(value_chosen_flag)
			  	    	{
			  	    		value_chosen_flag = 0;
			  	    		save_green_value();
			  	    	}
			  	    	break;
		  }
		currentState = nextState;
		  fsm_for_input_processing_0();
		  fsm_for_input_processing_1();
		  fsm_for_input_processing_2();
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  system_running();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, dis0_0_Pin|dis0_1_Pin|dis0_2_Pin|dis0_3_Pin
                          |dis0_4_Pin|dis0_5_Pin|dis0_6_Pin|dis1_0_Pin
                          |dis1_1_Pin|dis1_2_Pin|dis1_3_Pin|dis1_4_Pin
                          |dis1_5_Pin|dis1_6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, traffic1_Pin|traffic2_Pin|traffic3_Pin|traffic4_Pin
                          |traffic5_Pin|traffic6_Pin|red1_Pin|yellow1_Pin
                          |green1_Pin|red2_Pin|yellow2_Pin|green2_Pin
                          |traffic0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : dis0_0_Pin dis0_1_Pin dis0_2_Pin dis0_3_Pin
                           dis0_4_Pin dis0_5_Pin dis0_6_Pin dis1_0_Pin
                           dis1_1_Pin dis1_2_Pin dis1_3_Pin dis1_4_Pin
                           dis1_5_Pin dis1_6_Pin */
  GPIO_InitStruct.Pin = dis0_0_Pin|dis0_1_Pin|dis0_2_Pin|dis0_3_Pin
                          |dis0_4_Pin|dis0_5_Pin|dis0_6_Pin|dis1_0_Pin
                          |dis1_1_Pin|dis1_2_Pin|dis1_3_Pin|dis1_4_Pin
                          |dis1_5_Pin|dis1_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON_1_Pin BUTTON_2_Pin BUTTON_3_Pin */
  GPIO_InitStruct.Pin = BUTTON_1_Pin|BUTTON_2_Pin|BUTTON_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : traffic1_Pin traffic2_Pin traffic3_Pin traffic4_Pin
                           traffic5_Pin traffic6_Pin red1_Pin yellow1_Pin
                           green1_Pin red2_Pin yellow2_Pin green2_Pin
                           traffic0_Pin */
  GPIO_InitStruct.Pin = traffic1_Pin|traffic2_Pin|traffic3_Pin|traffic4_Pin
                          |traffic5_Pin|traffic6_Pin|red1_Pin|yellow1_Pin
                          |green1_Pin|red2_Pin|yellow2_Pin|green2_Pin
                          |traffic0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		timer_run();
		button_reading();
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
