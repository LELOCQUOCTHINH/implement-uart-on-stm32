/*
 * traffic_light.h
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"

extern int TimeForRed;

extern int TimeForAmber;

extern int TimeForGreen;

extern bool Onepass;

void InitTrafficLight();

void update7SegBufferForOdd(int interval);

void update7SegBufferForEven(int interval);

void UpdateTimeDecrease();

void traffic_light();

void turnOnLedRedForEven();
void turnOnLedRedForOdd();

void turnOnLedAmberForEven();
void turnOnLedAmberForOdd();

void turnOnLedGreenForEven();
void turnOnLedGreenForOdd();

void clearAllLed();

#endif /* INC_TRAFFIC_LIGHT_H_ */
