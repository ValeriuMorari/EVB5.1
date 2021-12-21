/*
 * driver_interrupt.c
 *
 * Created: 02.04.2016 14:17:25
 *  Author: Valeriu
 */ 



#include <avr/io.h>
#include "driver_interrupt.h"

//1 ms intrerupere
//used TIMER0_COMP_vect

void init_Timer0_int(void)
{	
	TCCR0 = 0x8B; // prescaler = 64 
	TCNT0 = 0;
	OCR0 = 125;
	TIMSK = TIMSK | 0X02;
	TIFR = 0X02;
	MCUCR |= ((1 << ISC01) | (1 << ISC00)); /*select the rising edge*/
	GICR |= (1 << INT0); /*external interrupt request 0 enable*/
}



