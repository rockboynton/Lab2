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

//One solution for the current speed to have a local static variable in this file;


void led_init(){ 
	// Enable the GPIOB in RCC_AHB1ENR
	*(RCC_AHB1ENR) |= (1 << GPIOBEN);
	// Turn on to set LED0 - LED9 to output mode ("01")
	// Pins 5-10, 12-15
	uint32_t ledAndMask = 0x00C003FF;
	uint32_t ledOrMask = 0x55155400;
	*(GPIOB_MODER) &= ledAndMask;
	*(GPIOB_MODER) |= ledOrMask;
}

void led_allOn(){
	//Insert code here (Hint use ODR)
	//protect other pins 
	// BSRR sets set bits in upper half-word
	*(GPIOB_BSRR) |= 0xF7E00000;
}

void led_allOff(){
	//Insert code here (Hint use ODR)
	//protect other pins
	// BSRR resets set bits in lower half-word
	*(GPIOB_BSRR) |= 0x0000F7E0;
}

void led_on(uint8_t ledIndex){
	//Insert code here (Hint use BSRR may be helpful)
	// if
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


