/*
 * uart.c
 *
 *  Created on: Dec 12, 2024
 *      Author: 84898
 */

#include "uart.h"

#define TICK 10
#define start_flag 0
#define R_flag 1
#define S_flag 2
#define T_flag 3
#define end_flag 4

#define O_flag 1
#define K_flag 2

uint8_t buffer [MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t parser_index = 0;
//void HAL_UART_RxCpltCallback ( UART_HandleTypeDef * huart ) {
//	if( huart -> Instance == USART2 )
//	{
//		HAL_UART_Receive_IT(&huart2, &temp, 1);
////		HAL_UART_Transmit (& huart2 , &temp , 1, 50);
//		buffer[index_buffer++] = temp ;
//		if( index_buffer == 30)
//			index_buffer = 0;
//		buffer_flag = 1;
//	}
//}

uint32_t ADC_value = 0;
char str[13];
int flag_input[4];
int flag_ack[3];
int flag_communication = 0;
int start_time_out = 0;
int time_out = 3000/TICK;
int transmit_again = 0;
void command_parser_fsm()
{
	if(buffer[parser_index] == 33) //! char
	{
		flag_input[start_flag] = 1;
		flag_input[R_flag] = 0;
		flag_input[S_flag] = 0;
		flag_input[T_flag] = 0;
	}
	else if(flag_input[start_flag] == 1 && buffer[parser_index] == 82) //R char
	{
		flag_input[R_flag] = 1;
		flag_input[start_flag] = 0;
	}
	else if(flag_input[R_flag] == 1 && buffer[parser_index] == 83) //S char
	{
		flag_input[S_flag] = 1;
		flag_input[R_flag] = 0;
	}
	else if(flag_input[S_flag] == 1 && buffer[parser_index] == 84) //T char
	{
		flag_input[T_flag] = 1;
		flag_input[S_flag] = 0;
	}
	else if(flag_input[T_flag] == 1 && buffer[parser_index] == 35) //# char
	{
		flag_communication ++; //start communicating
		flag_input[T_flag] = 0;
	}
	else
	{
		flag_input[start_flag] = 0;
		flag_input[R_flag] = 0;
		flag_input[S_flag] = 0;
		flag_input[T_flag] = 0;
	}



	if(buffer[parser_index] == 33 && start_time_out == 1) //! char
	{
		flag_ack[start_flag] = 1;
		flag_ack[O_flag] = 0;
		flag_ack[K_flag] = 0;
	}
	else if(flag_ack[start_flag] == 1 && buffer[parser_index] == 79) //O char
	{
		flag_ack[O_flag] = 1;
		flag_ack[start_flag] = 0;
	}
	else if(flag_ack[O_flag] == 1 && buffer[parser_index] == 75) //K char
	{
		flag_ack[K_flag] = 1;
		flag_ack[O_flag] = 0;
	}
	else if(flag_ack[K_flag] == 1 && buffer[parser_index] == 35) //# char
	{
		time_out = 3000/TICK;
		start_time_out = 0; //end communicating
		flag_ack[K_flag] = 0;
	}
	else
	{
		flag_ack[start_flag] = 0;
		flag_ack[O_flag] = 0;
		flag_ack[K_flag] = 0;
	}

	if(++parser_index >= 30)
		parser_index = 0;
}

char default_str[] = "ADC=";  // String to transmit
void uart_communiation_fsm ()
{
	if(flag_communication > 0 && start_time_out == 0)
	{
		flag_communication --;
		HAL_UART_Transmit(&huart2, (uint8_t *)default_str, strlen(default_str), 1000);
		ADC_value = HAL_ADC_GetValue(&hadc1) ;
		HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "%ld ", ADC_value), 1000); // Transmit the string
		start_time_out = 1;
	}

	if(transmit_again == 1)
	{
		transmit_again = 0;
		HAL_UART_Transmit(&huart2, (uint8_t *)default_str, strlen(default_str), 1000);
//		ADC_value = HAL_ADC_GetValue(&hadc1) ;
		HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "%ld ", ADC_value), 1000); // Transmit the string
	}
}

void init_uart()
{
	for(int i = 0 ; i < 4 ; i++)
		flag_input [i] = 0;
	for(int i = 0 ; i < 3 ; i++)
		flag_ack [i] = 0;
	buffer_flag = 0;
	index_buffer = 0;
	flag_communication = 0;
	start_time_out = 0;
	time_out = 3000/TICK;
	transmit_again = 0;
	parser_index = 0;
}

void decrease_time_out()
{
	if(start_time_out == 1)
		time_out --;
	if(time_out < 0)
	{
		time_out = 3000/TICK;
		transmit_again = 1;
	}
}

#define TIME_BLINK 1000

int counter_blinkLed = TIME_BLINK/TICK;


void blink_led()
{
	counter_blinkLed--;

	if(counter_blinkLed <= 0)
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//		clearOneSecondFlag();
		counter_blinkLed = TIME_BLINK/TICK;
	}
}
