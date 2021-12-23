/*
 * GccApplication1.c
 *
 * Created: 12/21/2021 1:22:06 PM
 *  Author: uidq8132
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif
#include <util/delay.h>
#include "io_handler.h"
#include "Button.h"
#include "lcd.h"

/*Interrupt Service Routine for INT1*/
ISR(INT1_vect)
{
	static int stare_alarma = 1;
	char *text = "unknown";
	if (stare_alarma == 1)
	{
		SetPin('C', 7);
		stare_alarma = 0;
		text = "Alarma ON";
	}
	else
	{
		text = "Alarma OFF";
		ResetPin('C', 7);
		stare_alarma = 1;
	}
	ClearScreen();
	CursorAtInitPosition();
	SendText(text);
	_delay_ms(500);  	/* Software debouncing control delay */
}

/*Interrupt Service Routine for INT0*/
ISR(INT0_vect)
{
	static int stare_motor = 1;
	char *text = "unknown";
	
	if (stare_motor == 0)
	{
		text = "MOTOR OFF";
		stare_motor = 1;
	}else
	{
		text = "MOTOR ON !";
		stare_motor = 0;
	}
	
	ClearScreen();
	CursorAtInitPosition();
	SendText(text);
	_delay_ms(500);  	/* Software debouncing control delay */
	
}


int main(void)
{	
	char *text = "Control Alarma";
	char *text1 = "Motor Pornit";
	InitLcd('B', 'A', 1, 0);
	SendText(text);
	DDRD=0;			/* PORTD as input */
	PORTD=0xFF;		/* Make pull up high */
	GICR = 1<<INT0 | 1<<INT1;		/* Enable INT0 / INT1 */
	MCUCR = 1<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
	MCUCR = 1<<ISC11 | 1<<ISC10;  /* Trigger INT1 on rising edge */
	
	sei(); /* Enable Global Interrupt */
	
	while(1) //infinite loop
	{
		if (ReadPin('C', 0) == 0)
		{
			ClearScreen();
			CursorAtInitPosition();
			SendText(text1);
		}
				
		
	}
	return 0;
}