/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */

#include "global.h"

#define TimeForLongPress 500

bool KeyReg0Buffer[MAX_BUTTON] ;
bool KeyReg1Buffer[MAX_BUTTON] ;
bool KeyReg2Buffer[MAX_BUTTON] ;
bool KeyReg3Buffer[MAX_BUTTON] ;

bool ButtonFlagBuffer[MAX_BUTTON];

int TimeOutForKeyPressBuffer[MAX_BUTTON];

void init_state_button()
{
	for (int i = 0 ; i < MAX_BUTTON ; i++)
	{
		KeyReg0Buffer [i] = NORMAL_STATE;
		KeyReg1Buffer [i] = NORMAL_STATE;
		KeyReg2Buffer [i] = NORMAL_STATE;
		KeyReg3Buffer [i] = NORMAL_STATE;

		ButtonFlagBuffer [i] = 0;

		TimeOutForKeyPressBuffer[i] = TimeForLongPress/TICK;
	}
}

bool getButtonFlagAtIndex(int index)
{
	if(index >= MAX_BUTTON)
		return 0;

	return ButtonFlagBuffer[index];
}

void ResetButtonFlagAtIndex(int index)
{
	if(index >= MAX_BUTTON)
		return;

	ButtonFlagBuffer[index] = 0;
}

void getKeyInput()
{
	for(int i = 0 ; i < MAX_BUTTON ; i++)
	{
		KeyReg2Buffer [i] = KeyReg1Buffer [i];
		KeyReg1Buffer [i] = KeyReg0Buffer [i];
	}

	KeyReg0Buffer[0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	KeyReg0Buffer[1] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	KeyReg0Buffer[2] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	for(int i = 0 ; i < MAX_BUTTON ; i++)
	{
		bool temp = KeyReg3Buffer[i];

		if(KeyReg1Buffer[i] == KeyReg0Buffer[i] && KeyReg1Buffer [i] == KeyReg2Buffer[i]) //same each other
			temp = KeyReg2Buffer[i];

		if(KeyReg3Buffer [i] != temp)
			KeyReg3Buffer[i] = temp;

		//if it is pressed and long pressed we will minus time out and update it as Long Pressed
		//if we use else command we will have a problem when NOT PRESSED state we also minus time out
		//and if it is pressed at time out <  origin Time For Long Press we will determine it as long pressed
		else if(KeyReg3Buffer[i] == (bool)PRESSED_STATE)
			TimeOutForKeyPressBuffer[i] -= 1;

		//if it is pressed but TimeOutForKeyPressBuffer larger on or equal to origin Time For Long Press we will define it as pressed one time
		if(KeyReg3Buffer[i] == (bool)PRESSED_STATE && TimeOutForKeyPressBuffer[i] >= TimeForLongPress/TICK)
		{
			ButtonFlagBuffer[i] = 1;
		}

		//if it is pressed and TimeOutForKeyPressBuffer equal to zero we will define it as long pressed
		else if(KeyReg3Buffer[i] == (bool)PRESSED_STATE && TimeOutForKeyPressBuffer[i] <= 0)
		{
			ButtonFlagBuffer[i] = 1;
			TimeOutForKeyPressBuffer[i] = TimeForLongPress/TICK;
		}

//		  if ((KeyReg1Buffer[i] == KeyReg0Buffer[i]) && (KeyReg1Buffer[i] == KeyReg2Buffer[i])){
//		    if (KeyReg2Buffer[i] != KeyReg3Buffer[i])
//		    {
//		      KeyReg3Buffer[i] = KeyReg2Buffer[i];
//
//		      if (KeyReg3 == (bool)PRESSED_STATE){
//		        TimeOutForKeyPress = 500;
//		        //subKeyProcess();
//		        ButtonFlagBuffer[i] = 1;
//		      }
//		    }
//
//		    else
//		    {
//		    	TimeOutForKeyPressBuffer[i] --;
//		        if (TimeOutForKeyPressBuffer[i] == 0){
//		        	TimeOutForKeyPress = 500;
//		        	if (KeyReg3 == PRESSED_STATE){
//		        		//subKeyProcess();
//		        		button1_flag = 1;
//		        	}
//		        }
//		    }
//		  }
	}
}

int index_Led7Seg_test_button = 0;
int temp = 0;
void UnitTestButton()
{
	if(getButtonFlagAtIndex(0)) //button 1
	{
		ResetButtonFlagAtIndex(0);

		index_Led7Seg_test_button++;
		if(index_Led7Seg_test_button >= MAX_LED)
			index_Led7Seg_test_button = 0;

		temp = GetValueBufferAtIndex(index_Led7Seg_test_button);

		update7SEG(index_Led7Seg_test_button);

	}

	else if(getButtonFlagAtIndex(1)) //button 2
	{
		ResetButtonFlagAtIndex(1);

		temp++;

		if(temp >= 10)
			temp = 0;

		display7SEG(temp);
	}

	else if(getButtonFlagAtIndex(2)) //button 3
	{
		ResetButtonFlagAtIndex(2);
		Set7SegBufferAtIndex(index_Led7Seg_test_button, temp);
		update7SEG(index_Led7Seg_test_button);
	}

}
