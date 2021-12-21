/*
 * GccApplication1.c
 *
 * Created: 12/21/2021 1:22:06 PM
 *  Author: uidq8132
 */ 


#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif
#include <util/delay.h>
#include "io_handler.h"
#include "Button.h"
#include "lcd.h"



int main(void)
{	
	char *text = "Control Alarma";
	char *text1 = "Motor Pornit";
	InitLcd('B', 'A', 1, 0);
	SendText(text);
	
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