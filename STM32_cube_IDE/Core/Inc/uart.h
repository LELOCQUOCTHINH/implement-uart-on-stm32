/*
 * uart.h
 *
 *  Created on: Dec 12, 2024
 *      Author: 84898
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include "main.h"
#include <stdio.h>
#include <string.h>
#define MAX_BUFFER_SIZE 30
extern uint8_t buffer_flag;
extern uint8_t buffer [MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
void HAL_UART_RxCpltCallback ( UART_HandleTypeDef * huart );
void command_parser_fsm();
void uart_communiation_fsm ();
void init_uart();
void decrease_time_out();
void blink_led();
#endif /* INC_UART_H_ */
