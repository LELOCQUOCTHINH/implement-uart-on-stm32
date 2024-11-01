/*
 * global.c
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */
#include "global.h"

#define TIME_BLINK 1000

int counter_blinkLed = TIME_BLINK/TICK;


void blink_led()
{
	counter_blinkLed--;

	if(counter_blinkLed <= 0)
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		clearOneSecondFlag();
		counter_blinkLed = TIME_BLINK/TICK;
	}
}

