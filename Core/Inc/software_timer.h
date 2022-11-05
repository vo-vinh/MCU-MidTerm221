/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#include "button.h"

extern int timer1_flag;
extern int timer2_flag;

void setTimer0(int duration);
void setTimer1(int duration);

void timerRun(void);

int TimerFlag0(void);
int TimerFlag1(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
