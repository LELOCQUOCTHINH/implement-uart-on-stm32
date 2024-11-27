/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include <stdlib.h>
#include <stdint.h>

#define TICK 10

#define true 1
#define false 0
typedef uint8_t bool;

void blink_led();

#include "software_timer.h"
#include "led7_segment.h"
//#include "UUT_7SEG.h"
#include "button.h"
#include "traffic_light.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_setting.h"
#include "Scheduler.h"

#endif /* INC_GLOBAL_H_ */
