/*
 * globalVar.h
 *
 *  Created on: 5 thg 11, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBALVAR_H_
#define INC_GLOBALVAR_H_

#include "main.h"

#define RESET_BUTTON  	0
#define INC_BUTTON		1
#define DEC_BUTTON		2

#define TIMEOUT_FOR_BUTTON		10000
#define TIME_INVOKE_FSM			10

extern int saveBuffer;
extern int display;

extern int Inc_flag;
extern int Dec_flag;

extern int Dec_flag1;

#endif /* INC_GLOBALVAR_H_ */
