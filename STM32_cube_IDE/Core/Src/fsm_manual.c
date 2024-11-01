/*
 * fsm_manual.c
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */
#include "global.h"

bool FlagToggle = 0;

int tempMode2 = 0;

int tempMode3 = 0;

int tempMode4 = 0;

void updateTempsForFSMManual()
{
	tempMode2 = TimeForRed;

	tempMode3 = TimeForAmber;

	tempMode4 = TimeForGreen;
}

void mode2() //set duration for RED LEDs
{
	update7SegBufferForOdd(02); //display mode number

	if(IsOneSecondPassed())
	{
		FlagToggle = !FlagToggle;
		clearOneSecondFlag();
	}

	if(FlagToggle)
	{
		turnOnLedRedForOdd();
		turnOnLedRedForEven();
	}

	else
	{
		clearAllLed();
	}

	if(getButtonFlagAtIndex(1)) //button 2 is pressed
	{
		tempMode2++;
		tempMode2 = tempMode2 % 100; //Max 99

		update7SegBufferForEven(tempMode2); //display duration set

		ResetButtonFlagAtIndex(1);
	}

	if(getButtonFlagAtIndex(2)) //button 3 is pressed
	{
		TimeForRed = tempMode2;

		ResetButtonFlagAtIndex(2);
	}
}

void mode3() //set Duration for Amber Leds
{
	update7SegBufferForOdd(03); //display mode number

	if(IsOneSecondPassed())
	{
		FlagToggle = !FlagToggle;
		clearOneSecondFlag();
	}

	if(FlagToggle)
	{
		turnOnLedAmberForOdd();
		turnOnLedAmberForEven();
	}

	else
	{
		clearAllLed();
	}

	if(getButtonFlagAtIndex(1)) //button 2 is pressed And don't exceed time Red leds
	{
		tempMode3++;
		tempMode3 = tempMode3 % 100; //Max 99
		update7SegBufferForEven(tempMode3); //display duration set
		ResetButtonFlagAtIndex(1);
	}

	if(getButtonFlagAtIndex(2)) //button 3 is pressed
	{
		if(tempMode3 < TimeForRed)
			TimeForAmber = tempMode3;

//		TimeForGreen = TimeForRed - TimeForAmber - 1; //reassign Time for Green Leds

		ResetButtonFlagAtIndex(2);
	}
}

void mode4()
{
	update7SegBufferForOdd(04); //display mode number

	if(IsOneSecondPassed())
	{
		FlagToggle = !FlagToggle;
		clearOneSecondFlag();
	}

	if(FlagToggle)
	{
		turnOnLedGreenForOdd();
		turnOnLedGreenForEven();
	}

	else
	{
		clearAllLed();
	}

	if(getButtonFlagAtIndex(1)) //button 2 is pressed And don't exceed time Red leds
	{
		tempMode4++;
		tempMode4 = tempMode4 % 100; //Max 99
		update7SegBufferForEven(tempMode4); //display duration set

		ResetButtonFlagAtIndex(1);
	}

	if(getButtonFlagAtIndex(2)) //button 3 is pressed
	{
		if(tempMode4 <= TimeForRed - TimeForAmber)
			TimeForGreen = tempMode4 - 1;

//		TimeForAmber = TimeForRed - TimeForGreen - 1; //reassign Time for Amber Leds

		ResetButtonFlagAtIndex(2);
	}
}

void fsm_manual()
{
	if(Onepass)
	{
		updateTempsForFSMManual();
		Onepass = 0;
	}

	switch (getCurrentMode())
	{
		case 1:
			update7SegBufferForEven(tempMode2);
			mode2();
			break;
		case 2:
			update7SegBufferForEven(tempMode3);
			mode3();
			break;
		case 3:
			update7SegBufferForEven(tempMode4);
			mode4();
			break;
		default:
			break;
	}

}
