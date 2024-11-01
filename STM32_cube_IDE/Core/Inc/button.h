/*
 * button.h
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define MAX_BUTTON 3

void init_state_button();

bool getButtonFlagAtIndex(int index);

void ResetButtonFlagAtIndex(int index);

void getKeyInput();

void UnitTestButton();

#endif /* INC_BUTTON_H_ */
