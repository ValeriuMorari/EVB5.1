/*
 * CFile1.c
 *
 * Created: 12/21/2021 2:35:25 PM
 *  Author: uidq8132
 */ 

#include <avr/io.h>

void ResetPin(char Port, int Pin)
{
	switch (Port)
	{
		case 'A':
			DDRA = DDRA | (1<<Pin);
			PORTA = PORTA & (0<<Pin);
			break;
		case 'B':
			DDRB = DDRB | (1<<Pin);
			PORTB = PORTB & (0<<Pin);
			break;
		case 'C':
			DDRC = DDRC | (1<<Pin);
			PORTC = PORTC & (0<<Pin);
			break;
		case 'D':
			DDRD = DDRD | (1<<Pin);
			PORTD = PORTD & (0<<Pin);
			break;

	}
}


void SetPin(char Port, int Pin)
{
	switch (Port)
	{
		case 'A':
			DDRA = DDRA | (1<<Pin);
			PORTA = PORTA | (1<<Pin);
			break;
		case 'B':
			DDRB = DDRB | (1<<Pin);
			PORTB = PORTB | (1<<Pin);
			break;
		case 'C':
			DDRC = DDRC | (1<<Pin);
			PORTC = PORTC | (1<<Pin);
			break;
		case 'D':
			DDRD = DDRD | (1<<Pin);
			PORTD = PORTD | (1<<Pin);
			break;
	}
}
