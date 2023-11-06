/*
 * input_reading.h
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */
#ifndef INC_TIMER_SYSTEM_H_
#define INC_TIMER_SYSTEM_H_

int TIMER_CYCLE = 10;

int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer1s_counter = 0;
int timer1s_flag = 0;

void setTimerIncrement(int duration);
void setTimerBlinking(int duration);
void setTimer1s(int duration);
void timer_run();

#endif /* INC_TIMER_SYSTEM_H_ */
