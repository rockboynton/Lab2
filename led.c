/*
 * led.c
 *
 *  Created on: Dec 1, 2018
 *      Author: livingston
 */

#include "led.h"
#include "delay.h"
#include <inttypes.h>
#include <stdio.h>

#include "stm32f446xx.h"

#define LED_COUNT 10
#define LED0 (volatile uint32_t*) 


//One solution for the current speed to have a local static variable in this file;


void led_init(){ // ? TODO Shouldn't this be led_init?
	// Enable the GPIOB in RCC_AHB1ENR
	*(RCC_AHB1ENR) |= (1<<GPIOBEN);
	// Turn on to set LED0 - LED9 to output mode ("01")
	uint32_t leds[LED_COUNT] = {LED0_GPIO, LED1_GPIO, LED2_GPIO, LED3_GPIO, LED4_GPIO,
		LED5_GPIO, LED6_GPIO, LED7_GPIO, LED8_GPIO, LED9_GPIO};
	int mode = 1;
	for (int i = 0; i < LED_COUNT; i++) {
		// Test
	}

}

void led_allOn(){
	//Insert code here (Hint use ODR)
	//protect other pins
}

void led_allOff(){
	//Insert code here (Hint use ODR)
	//protect other pins

}

void led_on(uint8_t ledIndex){
	//Insert code here (Hint use BSRR may be helpful)

}

void led_off(uint8_t ledIndex){
	//Insert code here (Hint use BSRR may be helpful)
}

void led_scan(){
	//Insert code here
}

void led_flash(){
	//Insert code here
}

void led_setSpeed(uint8_t speed){
	//Insert code here
}

void led_incSpeed(){
	//Insert code here
}

void led_decSpeed(){
	//Insert code here
}

uint8_t getCurrentSpeed()
{
	//Insert code here
	return 0;
}


