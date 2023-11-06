/*
 * device.c
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */

#include "main.h"
#include "device.h"

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