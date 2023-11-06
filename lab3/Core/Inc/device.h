/*
 * device.h
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_
int TRAFFIC = 0;
int SEG0 = 1;
int SEG1 = 2;

void turn_on_pin_traffic(int pin, int state);
void turn_on_pin_seg0(int pin, int state);
void turn_on_pin_seg1(int pin, int state);
void display7SEG(int seg, int num);
void display_value();
void turn_off_display_value();
void turnonTraffigLights(int state);
void blink_all_red();
void blink_all_ambient();
void blink_all_green();

#endif /* INC_DEVICE_H_ */
