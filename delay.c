/*
 * delay.c
 *
 * Starter Code
 */

#include <inttypes.h>
#include "delay.h"  //include declaration header file

void delay_1ms(uint32_t n){
	for (int i = 0; i < n; i++) {
		// Load number of cycles for 1 ms
		// 16 MHz clock
		*(STK_LOAD) = 16000;
 		// set 1 to enable and clock source
		*(STK_CTRL) = (1 << EN) | (1 << CLKSOURCE); 

		// Wait for countflag to be set
		 uint32_t countFlag = 0;
		 while (countFlag == 0) {
		 	countFlag = *(STK_CTRL) & (1 << COUNTFLAG); 
		 }
	}
}
