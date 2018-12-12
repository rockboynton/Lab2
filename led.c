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
static uint8_t currentSpeed;

// Base frequency of 1Hz
const uint8_t BASE_FREQUENCY = 1000;  

// Multiplier to change speed 
const uint8_t MULTIPLIER = 50;



void led_init(){ 
	// Enable the GPIOB in RCC_AHB1ENR
	*(RCC_AHB1ENR) |= (1 << GPIOBEN);
	// Turn on to set LED0 - LED9 to output mode ("01")
	// Pins 5-10, 12-15
	*(GPIOB_MODER) &= ~0xFF3FFC00;
	*(GPIOB_MODER) |= 0x55155400;
}

void led_allOn(){
	//Insert code here (Hint use ODR)
	//protect other pins 
	// BSRR sets set bits in lower half-word
	*(GPIOB_BSRR) |= 0xF7E0;
}

void led_allOff(){
	// BSRR resets set bits in upper half-word
	*(GPIOB_BSRR) |= (0xF7E0 << 16);
}

void led_on(uint8_t ledIndex){
	ledIndex = adjustIndex(ledIndex); // TODO try making this one line when its working
	*(GPIOB_BSRR) |= (1 << ledIndex);
}

void led_off(uint8_t ledIndex){
	//Insert code here (Hint use BSRR may be helpful)
	ledIndex = adjustIndex(ledIndex); // TODO try making this one line when its working
	*(GPIOB_BSRR) |= ((1 << ledIndex) << 16);
}

void led_scan(){
	// Scan the light across
	for (uint8_t i = 0; i < 10; i++) {
		led_on(i);
		delay_1ms(BASE_FREQUENCY - currentSpeed * MULTIPLIER); 
		led_off(i);
	} 
	// Scan the light back
	for (uint8_t i = 9; i >= 0; i--) {
		led_on(i);
		delay_1ms(BASE_FREQUENCY - currentSpeed * MULTIPLIER); 
		led_off(i);
	} 
}

void led_flash(){
	//Insert code here
	led_allOn();
	delay_1ms(BASE_FREQUENCY - currentSpeed * 10);
	led_allOff();
}

void led_setSpeed(uint8_t speed){
	if (0 < speed || speed < 9) {
		currentSpeed = speed;
	} else {
		printf("Error: Index Out of Range\n");
	}
}

void led_incSpeed(){
	if (currentSpeed < 9) {
		currentSpeed++;
	}
}

void led_decSpeed(){
	if (currentSpeed > 0) {
		currentSpeed--;
	}
}

uint8_t getCurrentSpeed() {
	return currentSpeed;
}

uint32_t adjustIndex(uint32_t ledIndex) {
	if (ledIndex <= 5) {
		ledIndex += 5;
	} else if (ledIndex <= 9) {
		ledIndex += 6;
	} 
	return ledIndex;
}


