/*
 * traffic_light.c
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */
#include "traffic_light.h"
#include "main.h"

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