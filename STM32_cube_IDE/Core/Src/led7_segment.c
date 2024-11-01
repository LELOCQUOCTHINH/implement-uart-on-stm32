#include "global.h"

int led_buffer[MAX_LED] = {0, 0, 0, 0};

void Set7SegBufferAtIndex(int index, int value)
{
	if(index >= MAX_LED)
	{
		return;
	}

	led_buffer [index] = value;
}

int GetValueBufferAtIndex(int index)
{
	if(index >= MAX_LED)
		return -1;

	return led_buffer[index];
}


void update7SEG ( int index )
{
	if(index >= MAX_LED)
	{
		index = 0;
	}

	 switch ( index )
	 {
		 case 0:
		 // Display the first 7 SEG with led_buffer [0]
				HAL_GPIO_WritePin(ANOT_COMMON_1_GPIO_Port, ANOT_COMMON_1_Pin, 0);
				HAL_GPIO_WritePin(ANOT_COMMON_2_GPIO_Port, ANOT_COMMON_2_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_3_GPIO_Port, ANOT_COMMON_3_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_4_GPIO_Port, ANOT_COMMON_4_Pin, 1);
				display7SEG(led_buffer [0]);
			 break ;
		 case 1:
		 // Display the second 7 SEG with led_buffer [1]
				HAL_GPIO_WritePin(ANOT_COMMON_1_GPIO_Port, ANOT_COMMON_1_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_2_GPIO_Port, ANOT_COMMON_2_Pin, 0);
				HAL_GPIO_WritePin(ANOT_COMMON_3_GPIO_Port, ANOT_COMMON_3_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_4_GPIO_Port, ANOT_COMMON_4_Pin, 1);
				display7SEG(led_buffer [1]);
			 break ;
		 case 2:
		 // Display the third 7 SEG with led_buffer [2]
				HAL_GPIO_WritePin(ANOT_COMMON_1_GPIO_Port, ANOT_COMMON_1_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_2_GPIO_Port, ANOT_COMMON_2_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_3_GPIO_Port, ANOT_COMMON_3_Pin, 0);
				HAL_GPIO_WritePin(ANOT_COMMON_4_GPIO_Port, ANOT_COMMON_4_Pin, 1);
				display7SEG(led_buffer [2]);
			 break ;
		 case 3:
		 // Display the forth 7 SEG with led_buffer [3]
				HAL_GPIO_WritePin(ANOT_COMMON_1_GPIO_Port, ANOT_COMMON_1_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_2_GPIO_Port, ANOT_COMMON_2_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_3_GPIO_Port, ANOT_COMMON_3_Pin, 1);
				HAL_GPIO_WritePin(ANOT_COMMON_4_GPIO_Port, ANOT_COMMON_4_Pin, 0);
				display7SEG(led_buffer [3]);
			 break ;
		 default :
			 break ;
	 }
}


void display7SEG ( int counter)
{
	switch(counter)
	{
		case 0:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_SET);
			break;
		case 1:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_SET);
			break;
		case 2:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
			break;
		case 3:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
			break;
		case 4:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
			break;
		case 5:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
			break;
		case 6:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
			break;
		case 7:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_SET);
			break;
		case 8:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
			break;
		default:
		HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
			break;
	}
}
