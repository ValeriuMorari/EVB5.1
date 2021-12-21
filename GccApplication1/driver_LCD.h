/*
 * driver_LCD.h
 *
 * Created: 04.04.2016 18:25:45
 *  Author: Valeriu
 */ 


#ifndef DRIVER_LCD_H_
#define DRIVER_LCD_H_

#define LED_PORT PORTA 
#define SET_ENABLE PORTB|=0x01
#define SET_DATA PORTB|=0x02
#define CLEAR_ENABLE PORTB&=0xFE
#define CLEAR_DATA PORTB&=0xFD

#include "Global.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void display_welcome(void);
void init_LCD(void);
void put_char(char character, int type);
void clear_screen(void);
void next_line(void);
void display_duty_cycle1(void);
void display_duty_cycle2(void);
void display_author(void);
void Cursor_init_position(void);
void put_string(char a[40]);

#endif /* DRIVER_LCD_H_ */