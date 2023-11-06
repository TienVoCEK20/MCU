/*
 * system.c
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */
#include "system.h"
#include "device.h"
#include "main.h"

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
	counter = green_light;
	light1 = red_light;
	light2 = red_light - green_light;
	current_traffic_state = RED1_GREEN2;
	next_traffic_state = RED1_GREEN2;
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