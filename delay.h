/*
 * delay.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Lenovo
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "hw_gpio.h"
#include "std_types.h"
#include "bitwise_operations.h"

#define count_flag      16
#define freq_factor_micro   4
#define freq_factor_milli   4000

void delay_Milli(uint16 delay);
void delay_Micro(uint32 delay);
void systickInit(void);


#endif /* DELAY_H_ */
