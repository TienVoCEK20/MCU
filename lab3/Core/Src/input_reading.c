/*
 * input_reading.c
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */
#include "main.h"
#include "input_reading.h"
//we aim to work with more than one buttons
#define N0_OF_BUTTONS 				       3
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   100
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after
//debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState0 = BUTTON_RELEASED;
enum ButtonState buttonState1 = BUTTON_RELEASED;
enum ButtonState buttonState2 = BUTTON_RELEASED;
void fsm_for_input_processing_0(void){
	switch(buttonState0){
	case BUTTON_RELEASED:
		if(is_button_pressed(0)){
			buttonState0 = BUTTON_PRESSED;
			changing_mode_flag = 1;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			buttonState0 = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(0)){
				buttonState0 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(0)){
			buttonState0 = BUTTON_RELEASED;
		}
		//todo
		break;
	}
}

void fsm_for_input_processing_1(void){
	switch(buttonState1){
	case BUTTON_RELEASED:
		if(is_button_pressed(1)){
			buttonState1 = BUTTON_PRESSED;
			increment_value_flag = 1;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(1)){
			buttonState1 = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(1)){
				buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(1)){
			buttonState1 = BUTTON_RELEASED;
		}
		break;
	}
}

void fsm_for_input_processing_2(void){
	switch(buttonState2){
	case BUTTON_RELEASED:
		if(is_button_pressed(2)){
			buttonState2 = BUTTON_PRESSED;
			value_chosen_flag = 1;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(2)){
			buttonState2 = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(2)){
				buttonState2 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(2)){
			buttonState2 = BUTTON_RELEASED;
		}
		//todo
		break;
	}
}


void button_reading(void){
	for(char i = 0; i < N0_OF_BUTTONS; i ++){
		if (i == 0)
		{
			debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		}
		if (i == 1)
		{
			debounceButtonBuffer2[i] =debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
		}
		if (i == 2)
		{
			debounceButtonBuffer2[i] =debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
		}
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[i]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[i] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
	}
}

unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}
