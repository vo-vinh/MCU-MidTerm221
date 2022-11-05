/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */

#include "software_timer.h"


static int		TIME_CYCLE	= 10;

int timer0_flag = 0;
int timer1_flag = 0;

int timer0_counter = 0;
int timer1_counter = 0;


void InitSoftwareTimer(void);

void setTimer0(int duration){
	timer0_counter = duration / TIME_CYCLE;
	timer0_flag = 0;
}
void setTimer1(int duration){
	timer1_counter  = duration / TIME_CYCLE;
	timer1_flag	 = 0;
}

void timerRun(void){
	if(timer0_counter  > 0){
		timer0_counter --;
		if(timer0_counter  == 0){
			timer0_flag = 1;
		}
	}
	if(timer1_counter  > 0){
		timer1_counter --;
		if(timer1_counter  == 0){
			timer1_flag = 1;
		}
	}
}

int TimerFlag0(void){
	return timer0_flag;
}
int TimerFlag1(void){
	return timer1_flag;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2) {
		timerRun();
		buttonInput();
	}
}
