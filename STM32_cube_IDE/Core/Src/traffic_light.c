/*
 * traffic_light.c
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */
#include "global.h"

int TimeForRed = 0;

int TimeForAmber = 0;

int TimeForGreen = 0;

bool OddOrEven = 0;
//we have 2 pair cross road is 2-4 and 1-3 which are even and odd respectively
//so we will use 1 of OddOrEven variable for indicating LedRed state to odd otherwise 0 for indicating LedRed to even
int TimeRedDecrease = 0;
int TimeAmberDecrease = 0;
int TimeGreenDecrease = 0;

bool Onepass = 0; //one pass indicate that node 0 have been pressed (switch mode on)

void update7SegBufferForOdd(int interval) //odd is index 1 & 3
{//we will minus for 1 to get index of array
	Set7SegBufferAtIndex(1-1, interval/10); //max 99
	Set7SegBufferAtIndex(3-1, interval%10);
}

void update7SegBufferForEven(int interval) //even is index 2 & 4
{//we will minus for 1 to get index of array
	Set7SegBufferAtIndex(2-1, interval/10); //max 99
	Set7SegBufferAtIndex(4-1, interval%10);
}

void UpdateTimeDecrease()
{
	TimeRedDecrease = TimeForRed;
	TimeAmberDecrease = TimeForAmber;
	TimeGreenDecrease = TimeForGreen;
}

void DecreaseTimeForOne()
{
	TimeRedDecrease --;
	if(TimeGreenDecrease < 0)
		TimeAmberDecrease --;
	else
		TimeGreenDecrease --;
}

void turnOnLedRedForEven()
{
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0); //0 is on
	HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, 0);
}

void turnOnLedRedForOdd()
{
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0); //0 is on
	HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, 0);

}

void turnOnLedAmberForEven()
{
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0); //0 is on
	HAL_GPIO_WritePin(LED_YELLOW_4_GPIO_Port, LED_YELLOW_4_Pin, 0);
}

void turnOnLedAmberForOdd()
{
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0); //0 is on
	HAL_GPIO_WritePin(LED_YELLOW_3_GPIO_Port, LED_YELLOW_3_Pin, 0);
}

void turnOnLedGreenForEven()
{
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0); //0 is on
	HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, 0);
}

void turnOnLedGreenForOdd()
{
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0); //0 is on
	HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, 0);
}

void clearAllLed()
{
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1); //0 is on
	HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, 1);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1); //0 is on
	HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, 1);

	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1); //0 is on
	HAL_GPIO_WritePin(LED_YELLOW_4_GPIO_Port, LED_YELLOW_4_Pin, 1);

	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1); //0 is on
	HAL_GPIO_WritePin(LED_YELLOW_3_GPIO_Port, LED_YELLOW_3_Pin, 1);

	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1); //0 is on
	HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, 1);

	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1); //0 is on
	HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, 1);
}

void traffic_light()
{
	switch (OddOrEven)
	{
		case 1: //LedRed for odd
				update7SegBufferForOdd(TimeRedDecrease);

				if(Onepass)
				{
					clearAllLed();
					turnOnLedRedForOdd();
					turnOnLedGreenForEven();
					Onepass = 0;
				}

				if(TimeGreenDecrease < 0) //switch to Led yellow
				{
					update7SegBufferForEven(TimeAmberDecrease);
					clearAllLed();
					turnOnLedAmberForEven();
					turnOnLedRedForOdd();
				}

				else
					update7SegBufferForEven(TimeGreenDecrease);

				if(OneSecondPass) //one second flag on
				{
					DecreaseTimeForOne();
					clearOneSecondFlag(); //clear one second flag
				}

				if(TimeRedDecrease < 0)
				{
					UpdateTimeDecrease();

					clearAllLed();
					turnOnLedRedForEven();
					turnOnLedGreenForOdd();

					OddOrEven = 0; //switch to LedRed state for even
				}

		break;

		default: //Led Red for even
				update7SegBufferForEven(TimeRedDecrease);

				if(Onepass)
				{
					clearAllLed();
					turnOnLedRedForEven();
					turnOnLedGreenForOdd();
					Onepass = 0;
				}

				if(TimeGreenDecrease < 0) //switch to Led yellow
				{
					update7SegBufferForOdd(TimeAmberDecrease);
					clearAllLed();
					turnOnLedAmberForOdd();
					turnOnLedRedForEven();
				}

				else
					update7SegBufferForOdd(TimeGreenDecrease);

				if(OneSecondPass) //one second flag on
				{
					DecreaseTimeForOne();
					clearOneSecondFlag(); //clear one second flag
				}

				if(TimeRedDecrease < 0)
				{
					UpdateTimeDecrease();

					clearAllLed();
					turnOnLedRedForOdd();
					turnOnLedGreenForEven();

					OddOrEven = 1; //switch to LedRed state for odd
				}
		break;
	}
}

