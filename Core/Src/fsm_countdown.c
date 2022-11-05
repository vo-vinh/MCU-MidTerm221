/*
 * fsm_midterm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#include "global.h"
#include "fsm_countdown.h"

enum STATE {STATE0, STATE1, STATE2};

enum STATE State = STATE0;

//timeout for button is 10s, while time invoking fsm is 10ms
// so we create a counter

uint16_t Time_counter	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;

void STATE0_manual()
{
	if(is_button_pressed(RESET_BUTTON))
	{
		Time_counter = TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		display = 0;
	}
	else if(is_button_pressed(INC_BUTTON))
	{
		Time_counter = TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		if (display == 9)
		{
			display = 0;
		}
		else
		{
			display ++;
		}
	}
	else if(is_button_pressed(DEC_BUTTON))
	{
		Time_counter = TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		if (display == 0)
		{
			display = 9;
		}
		else
		{
			display--;
		}
	}
}
void fsm_simple_buttons_run(){
	switch(State){
	case STATE0:
		STATE0_manual();
		if(is_button_hold(INC_BUTTON) || is_button_hold(DEC_BUTTON)){
			State = STATE1;
		}
		if(Time_counter == 0){
			saveBuffer = display;
			State = STATE2;
		}
		Time_counter--;
		break;
	case STATE1:
		if(is_button_hold(INC_BUTTON)) {
			Inc_flag = 1;
		}
		else if(is_button_hold(DEC_BUTTON)){
			Dec_flag = 1;
		}
		else
		{
			Inc_flag = 0;
			Dec_flag = 0;
			State = STATE0;
		}
		break;
	case STATE2:
		Dec_flag1 = 1;
		if(is_button_pressed(INC_BUTTON) || is_button_pressed(DEC_BUTTON)){
			Dec_flag1 = 0;
			display = saveBuffer;
			State = STATE0;
		}
		break;
	default:
		break;
	}
}
