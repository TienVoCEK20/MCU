/*
 * timer_system.c
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */
#include "timer_system.h"
#include "main.h"

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
	timer1s_counter = duration / TIMER_CYCLE;
	timer1s_flag = 0;
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

	if(timer1s_counter > 0) {
		timer1s_counter --;
	}
	if(timer1s_counter == 0)
	{
		timer1s_flag = 1;
	}
}