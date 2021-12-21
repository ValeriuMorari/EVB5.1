/*
 * lcd.h
 *
 * Created: 12/21/2021 6:26:58 PM
 *  Author: uidq8132
 */ 


#ifndef LCD_H_
#define LCD_H_


void InitLcd(char _ControlPort, char _DataPort, int _RSPin, int _EnablePin);
void ClearScreen(void);
void SendData(char Data);
void SendCommand(char Data);
void CursorAtInitPosition(void);
void NextLine(void);
void SendText(char *Text);
#endif /* LCD_H_ */