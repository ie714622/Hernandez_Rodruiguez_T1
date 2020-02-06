/**
 * @file	OneLed.c
 * @brief	Application entry pint.
 *
 * Edwin Hernandez
 * Urik Rodriguez
 */

// standart input output
#include <stdio.h>
// standard integer definition provided by the compiler
#include <stdint.h>
#include "MK64F12.h"

#define DEBUG_ON

int main (void) {
	//Activating the GPIOB clock gating
	SIM->SCGC5 = 0x2400;
	// Pin control configuration of GPIOB pin22 as GPIO
	PORTB->PCR[22] = 0x00000100;
	PORTB->PCR[21] = 0x00000100;
	PORTE->PCR[26] = 0x00000100;
	// assigns a safe value to the output pin
	GPIOB->PDOR = 0x00600000;
	//GPIOB->PDOR = 0x00400000;
	//GPIOB->PDOR = 0x00200000;
	GPIOE->PDOR = 0x04000000;
	// configures GPIOB pin 22 as output
	GPIOB->PDDR = 0x00600000;
	//GPIOB->PDDR = 0x00400000;
	//GPIOB->PDDR = 0x00200000;
	GPIOE->PDDR = 0x04000000;

	while (1) {
		// clears the output port, therefore the led is on
		// red on, green off, blue off
		GPIOE->PDOR = 0x04000000;
		GPIOB->PDOR = 0x00200000;
#ifdef DEBUG_ON
		// printf is only used for debug purposes
		printf("RED LED ON\n");
#endif

		// red off green off blue on
		GPIOE->PDOR = 0x04000000;
		GPIOB->PDOR = 0x00400000;
#ifdef DEBUG_ON
		// printf is only used for debug purposes
		printf("BLUE LED ON\n");
#endif

		// red off, green on, blue off
		GPIOB->PDOR = 0x00600000;
		GPIOE->PDOR = 0;
#ifdef DEBUG_ON
		// printf is only used for debug purposes
		printf("GREEN LED ON\n");
#endif

		// red on green on blue on
		GPIOB->PDOR = 0;
#ifdef DEBUG_ON
		// printf is only used for debug purposes
		printf("WHITE LED ON\n");
#endif

	}

}
