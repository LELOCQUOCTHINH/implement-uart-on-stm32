/*
 * fsm_setting.c
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */
#include "global.h"

#define MAX_MODE 4

int current_mode = 0;

void setCurrentMode(int CurrentMode)
{
	current_mode = CurrentMode;
}

int getCurrentMode()
{
	return current_mode;
}

void fsm_setting()
{
	if(getButtonFlagAtIndex(0))
	{
		Onepass = 1;
		current_mode ++;
		current_mode = current_mode % 4;
		ResetButtonFlagAtIndex(0);
	}

	if(current_mode == 0)
		fsm_automatic();

	else
	{
		fsm_manual();
	}
}
