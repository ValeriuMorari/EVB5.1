#include "io_handler.h"
#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <util/delay.h>
#define SET_ENABLE SetPin(ControlPort, EnablePin)
#define SET_DATA SetPin(ControlPort, RSPin)
#define CLEAR_ENABLE ResetPin(ControlPort, EnablePin)
#define SET_COMMAND ResetPin(ControlPort, RSPin)


char DataPort = 'A';
char ControlPort = 'B';
int RSPin = 1;
int EnablePin = 0;


void SetControlPort(char Port)
{
	ControlPort = Port;
}

void SetDataPort(char Port)
{
	int i = 0;
	DataPort = Port;
	for (i = 0; i <= 7; i++)
	{
		ResetPin(DataPort, i);
	}
}


void SetRSPin(int Pin)
{
	RSPin = Pin;
	ResetPin(ControlPort, RSPin);
}

void SetEnablePin(int Pin)
{
	EnablePin = Pin;
	ResetPin(ControlPort, EnablePin);
}

void SendCommand(char Data)
{
	switch(DataPort)
	{
		case 'A':
			PORTA = Data;
			break;
		case 'B':
			PORTB = Data;
			break;
		case 'C':
			PORTC = Data;
			break;
		case 'D':
			PORTD = Data;
			break;
	}
	
	SET_ENABLE;
	SET_COMMAND;
	_delay_ms(2);
	CLEAR_ENABLE;
	_delay_ms(10);
}

void SendData(char Data)
{
	switch(DataPort)
	{
		case 'A':
			PORTA = Data;
			break; 
		case 'B':
			PORTB = Data;
			break;
		case 'C':
			PORTC = Data;
			break;
		case 'D':
			PORTD = Data;
			break;
	}
	
	
	SET_ENABLE;
	SET_DATA;
	_delay_ms(2);
	CLEAR_ENABLE;
	_delay_ms(10);
	//_delay_ms(10);
	
}

void ClearScreen(void)
{ 
	SendCommand(0x01); 
}

void CursorAtInitPosition(void)
{
	SendCommand(0x80);
}

void NextLine(void)
{
	SendCommand(0x80+0x40);
}

void InitLcd(char _ControlPort, char _DataPort, int _RSPin, int _EnablePin)
{
	SetControlPort(_ControlPort);
	SetDataPort(_DataPort);
	SetRSPin(_RSPin);
	SetEnablePin(_EnablePin);
	SendCommand(0x3F); // set 8 bit mode 
	SendCommand(0x02);
    SendCommand(0x0E);
	ClearScreen();
	_delay_ms(500);
	// CursorAtInitPosition();
}

void SendText(char *Text)
{
	int i = 0;
	while(Text[i] != '\0')
	{
		SendData(Text[i]);
		if (i == 15)
		{
			NextLine();
		}
		i++;
	}
};
