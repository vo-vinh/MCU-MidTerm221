/*
 * button_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NUMS_OF_BUTTON	3

//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   300


void buttonInput(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_hold(unsigned char index);

#endif /* INC_BUTTON_H_ */
