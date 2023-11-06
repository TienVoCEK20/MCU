/*
 * system.h
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */
#ifndef INC_SYSTEM_H_
#define INC_SYSTEM_H_
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

void choosing_red_value();
void choosing_yellow_value();
void choosing_green_value();
void save_red_value();
void save_yellow_value();
void save_green_value();
void display_mode(int mode);
void clear_all_flag();
void system_running();

#endif /* INC_TRAFFIC_LIGTH_H_ */
