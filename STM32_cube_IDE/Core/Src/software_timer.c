/*
 * software_timer.c
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */
#include "global.h"

#define TimeScanLed7Seg 250 //0.25s = 250ms

int counterOneSecond = 1000/TICK;

int indexScanLed7Seg = 0;

bool OneSecondPass = 0;


void timerRun()
{
	counterOneSecond--;
	if(counterOneSecond <= 0)
	{
		OneSecondPass = 1;
		counterOneSecond = 1000/TICK;
	}
}

bool IsOneSecondPassed()
{
	return OneSecondPass;
}

void clearOneSecondFlag()
{
	OneSecondPass = 0;
}

void ScanLed7Seg()
{
	if(counterOneSecond%(TimeScanLed7Seg/TICK) == 0)
		update7SEG(indexScanLed7Seg++);

	if(indexScanLed7Seg >= MAX_LED)
		indexScanLed7Seg = 0;
}

void timer_isr()
{
	blink_led();
	ScanLed7Seg();
	timerRun();
	getKeyInput();
//	fsm_setting();
//	UnitTestButton();
}

