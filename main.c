/*
 * main.c
 *
 *  Starter Code
 */
#include <stdio.h>
#include <stdlib.h>
#include "uart_driver.h"
#include "led.h"

#define F_CPU 16000000UL


// main
int main(){

	char c;

	init_usart2(19200,F_CPU);

	//Insert control and interface code here

	led_init();
	
	// Read c into variable 
	// Note that getchar() will grab the first c
	
	while (1) {
		c = getchar();
		switch (c) {
			case 'h': 
				printf("help interface here\n"); // ! FIXME
				break;
			case 'f': 
				led_flash(); 
				break;
			case 's': 
				led_scan(); 
				break;
			case 'p': 
				printf("Current Speed: %d\n", getCurrentSpeed()); 
				break;
			case '+': 
				led_incSpeed(); 
				break;
			case '-': 
				led_decSpeed(); 
				break;
			case 'x': 
				led_allOff(); 
				break;
			default:
				printf("Invalid Command.");
				break;
		}
	}
	
	//The return will still be in the stream
	//You may have to load the return into a dummy variable to discard it
	//Another option would be to look at scanf

	// never return
	
	return 0;
}



