/*
 * Button.c
 *
 * Created: 06.04.2016 0:04:15
 *  Author: Valeriu
 */ 

#include <avr/io.h>

int isKthBitSet(int n, int k)
{
	k = k + 1;
	if (n & (1 << (k - 1)))
	return 1;
	else
	return 0;
}

int ReadPin(char Port, int Pin)
{
	switch (Port)
	{
		case 'A':
			DDRA = DDRA & (0<<Pin); // setez PORT & PIN ca input
			PORTA = PORTA | (1<<Pin);  // activez rez. de Pull Up
			return isKthBitSet(PINA, Pin);
		case 'C':
			DDRC = DDRC & (0<<Pin); // setez PORT & PIN ca input
			PORTC = PORTC | (1<<Pin);  // activez rez. de Pull Up
			return isKthBitSet(PINC, Pin);
	}
}






