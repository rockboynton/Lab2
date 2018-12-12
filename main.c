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
#define ARSIZE 10


// main
int main(){

	init_usart2(19200,F_CPU);

	//Insert control and interface code here
	led_init();
	while 

	//Note that getchar() will grab the first character
	//The return will still be in the stream
	//You may have to load the return into a dummy variable to discard it
	//Another option would be to look at scanf

	// never return
	for(;;){}
	
	return 0;
}



