/*
 * software_timer.h
 *
 *  Created on: Oct 28, 2024
 *      Author: 84898
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern bool OneSecondPass;

bool IsOneSecondPassed();
void clearOneSecondFlag();
void timerRun();
void setTime();
void ScanLed7Seg();
void timer_isr();

#endif /* INC_SOFTWARE_TIMER_H_ */
