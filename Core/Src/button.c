/*
 * button_reading.c
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */

#include "button.h"


#define PRESSED_STATE                GPIO_PIN_RESET
#define NORMAL_STATE                 GPIO_PIN_SET

uint16_t Button_PIN[3] = {RESET_Pin, INC_Pin, DEC_Pin};

static GPIO_PinState buttonBuffer[NUMS_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};


static GPIO_PinState KeyReg1[NUMS_OF_BUTTON];
static GPIO_PinState KeyReg2[NUMS_OF_BUTTON];


static uint8_t button_hold_flag[NUMS_OF_BUTTON];

static uint16_t button_hold_counter[NUMS_OF_BUTTON];

void buttonInput(void)
{
	for(uint8_t i = 0; i < NUMS_OF_BUTTON; i ++)
	{
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = HAL_GPIO_ReadPin(GPIOA, Button_PIN[i]);

		if(KeyReg1[i] == KeyReg2[i])
		{
			buttonBuffer[i] = KeyReg1[i];
			if(buttonBuffer[i] == PRESSED_STATE)
			{

				if(button_hold_counter[i] < DURATION_FOR_AUTO_INCREASING)
				{
					button_hold_counter[i]++;
				}
				else
				{

					button_hold_flag[i] = 1;
				}
			}
			else
			{
				button_hold_counter[i] = 0;
				button_hold_flag[i] = 0;
			}
		}
	}
}


unsigned char is_button_pressed(uint8_t index)
{
	if(index >= NUMS_OF_BUTTON) return 0;

	if(buttonBuffer[index] == PRESSED_STATE)
	{
		return (button_hold_counter[index] == 1);
	}
	return 0;
}

unsigned char is_button_hold(unsigned char index)
{
	if(index >= NUMS_OF_BUTTON) return 0xff;
	return (button_hold_flag[index] == 1);
}
