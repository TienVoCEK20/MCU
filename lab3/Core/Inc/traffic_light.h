/*
 * traffic_light.h
 *
 *  Created on: Oct 26, 2023
 *      Author: 84968
 */
#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_
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

int counter = 3;
int light1 = 5;
int light2 = 2;

void displayTrafficLight1(int light1);
void traffic_light_running();

#endif /* INC_TRAFFIC_LIGHT_H_ */
