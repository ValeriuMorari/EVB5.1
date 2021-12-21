/*
 * driver_PWM.c
 *
 * Created: 02.04.2016 16:06:41
 *  Author: Valeriu
 */ 

//used TIMER1_COMPx_vect
#include <avr/io.h>
#include "driver_PWM.h"


void init_PWM(int out_compare_1, int out_compare_2)
{
	
	TCCR1A = 0xFE;  //Inverting mode; Update OCRx at bottom and set OCxx when TCNC1==OCR1x
	TCCR1B = 0x19;		
	TCNT1 = 0;
	ICR1 = 1000; //ICR1 = TOP COUNT
	OCR1A = 1001; // Pin is PD5; To rise duty cycle you need to rise OCR1A from 0 to 1001 (TOP=ICR1)
	OCR1B = 1001;	//Pin is PD4
	
 }

