/*
 * driver_LCD.c
 *
 * Created: 04.04.2016 18:27:41
 *  Author: Valeriu
 */ 
#include <avr/io.h>
#include "driver_LCD.h"
#include "util\delay.h"

void Cursor_init_position(void)
{
	put_char(0x80,0);// initializeaza cursorul pe prima pozitie 
}

void display_welcome(void)
{

put_char(0x85,0);
put_char('W',1);

_delay_ms(200);
put_char(0x86,0);
put_char('E',1);

_delay_ms(200);
put_char(0x87,0);
put_char('L',1);

_delay_ms(200);
put_char(0x88,0);
put_char('C',1);

_delay_ms(200);
put_char(0x89,0);
put_char('O',1);

_delay_ms(200);
put_char(0x8A,0);
put_char('M',1);

_delay_ms(200);
put_char(0x8B,0);
put_char('E',1);
_delay_ms(1000);
	

}
void put_char(char character, int type)
{
	//LED_PORT este PORTB
	LED_PORT=character;
	SET_ENABLE;
	if(type==1)
	{
		SET_DATA;
	}
	_delay_ms(5);
	CLEAR_ENABLE;
	CLEAR_DATA;
}


void init_LCD(void)
{
	put_char(0x3F,0); //initialize LCD to work in 8 bit mode
	_delay_ms(10);
	put_char(0x01,0); //clear screen
	_delay_ms(2);
	put_char(0x02,0); 
	_delay_ms(2);
	put_char(0x0E,0);
	_delay_ms(2);
}

void clear_screen(void)
{
	put_char(0x01,0); //clear screen and set cursor on the first position left corner
	_delay_ms(2);
}



void next_line(void)
{
	put_char(0x80+0x40,0);	
}


void display_duty_cycle1(void)
{
	int i;
	char a[42] ="DIR=0 PWM1->";
	//duty cycle == (1..1001); NR1 = first number of duty cycle; NR2 = second number
	
	PORTC |= 0x70; 
	PORTC &= 0x7F; //LED1 --> ON
	
	Cursor_init_position();
	for (i=0;i<42;i++)
	{
		if(a[i] == '\0')
		{
			put_char((((1000-OCR1A)/100)%10) + '0',1); //operatie de extragere a cifrei din numarul ce reprezinta duty cycle 1
			put_char((((1000-OCR1A)/10)%10) + '0',1);
			while (i<42)
			{
				put_char(' ',1);
				i++;
			}
			break;
		}
		
		put_char(a[i],1);
		
		if (i==15)
		{
			next_line();
		}
		
		
	}
	
}

void display_duty_cycle2(void)
{
	int i;
	char a[42] ="DIR=1 PWM2->";
	//duty cycle == (1..1001); NR1 = first number of duty cycle; NR2 = second number
	
	PORTC |= 0x80; //LED1 --> OFF
	PORTC &= 0xBF; //LED2 --> ON
	
	Cursor_init_position();
	for (i=0;i<42;i++)
	{
		if(a[i] == '\0')
		{
			put_char((((1000-OCR1B)/100)%10 ) + '0',1);
			put_char((((1000-OCR1B)/10)%10) + '0',1);
			while (i<42)
			{
				put_char(' ',1);
				i++;
			}
			break;
		}
		
		put_char(a[i],1);
		
		if (i==15)
		{
			next_line();
		}
		
		
	}
	
}


void display_author(void)

{
	int i;
	char a[40] =" Valeriu Morari";

	Cursor_init_position();
	
	for (i=0;i<40;i++)
	{
		if(a[i] == '\0')
		{
			while (i<42)
			{
				put_char(' ',1);
				i++;
			}
			break;
		}
		
		
		put_char(a[i],1);
		
		if (i==15)
		{
			next_line();
		}
		
	}
		
	
	
}

void put_string(char a[40])
{
	int i;
	
	Cursor_init_position();

	for(i=0;i<40;i++)
	{
		if (a[i] == '\0')
		{
			while (i<42)
			{
				put_char(' ',1);
				i++;
			}
			break;
			
		}
		
		
		put_char(a[i],1);
		
		if (i==15)
		{
			next_line();
		}	
	}
}








