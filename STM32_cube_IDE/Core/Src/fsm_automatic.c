/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */
#include "global.h"
void fsm_automatic()
{
		if(TimeForRed != TimeForAmber + TimeForGreen + 1)
		{
			TimeForAmber = 0;
			TimeForRed = 0;
			TimeForGreen = 0;
		}

		if(Onepass)
		UpdateTimeDecrease();

		traffic_light();
}
