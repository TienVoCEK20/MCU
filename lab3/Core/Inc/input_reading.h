/*
 * input_reading.h
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
void fsm_for_input_processing0(void);
void fsm_for_input_processing1(void);
void fsm_for_input_processing2(void);
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
