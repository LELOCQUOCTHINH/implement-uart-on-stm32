/*
 * led7_segment.h
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

//#include "main.h"

#define MAX_LED 4
//using if I want to change amount of 7Seg LEDs in the future

void Set7SegBufferAtIndex(int index, int value);

int GetValueBufferAtIndex(int index);

void update7SEG(int number);

void display7SEG ( int counter);

#endif /* INC_LED7_SEGMENT_H_ */
