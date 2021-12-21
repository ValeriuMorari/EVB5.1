/*
 * driver_PWM.h
 *
 * Created: 02.04.2016 16:02:44
 *  Author: Valeriu
 */ 


//used TIMER1_COMPx_vect

#ifndef DRIVER_PWM_H_
#define DRIVER_PWM_H_

#include "Global.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void init_PWM(int out_compare_1, int out_compare_2);

#define Set_duty_cycle1(x) OCR1A=1000-x*10;
#define Set_duty_cycle2(x) OCR1B=1000-x*10;


#endif /* DRIVER_PWM_H_ */