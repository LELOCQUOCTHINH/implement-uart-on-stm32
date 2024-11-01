/*
 * UUT_7SEG.c
 *
 *  Created on: Oct 29, 2024
 *      Author: 84898
 */
#include "UUT_7SEG.h"

int main_index = 0;
int counter_UUT7SEG = 25;

void UUT_7SEG()
{
	int temp = (GetValueBufferAtIndex(main_index) + 1);
	Set7SegBufferAtIndex(main_index,  temp > 9 ? 0 : temp);

	update7SEG(main_index);

	main_index++;

	if(main_index >= MAX_LED)
	{
		main_index = 0;
	}

	counter_UUT7SEG--;

	if(counter_UUT7SEG <= 0)
		counter_UUT7SEG = 25;

}
