/*
 * driver_interrupt.h
 *
 * Created: 02.04.2016 14:16:22
 *  Author: Valeriu
 */ 
//used TIMER0_COMPx_vect

#ifndef DRIVER_INTERRUPT_H_
#define DRIVER_INTERRUPT_H_


#include "Global.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void init_Timer0_int(void);


#endif /* DRIVER_INTERRUPT_H_ */