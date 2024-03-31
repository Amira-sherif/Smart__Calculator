/*
 * DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Lenovo
 */

#ifndef DIO_H_
#define DIO_H_

#include "bitwise_operations.h"
#include "hw_gpio.h"
#include "std_types.h"

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3
#define PORTE_ID               4
#define PORTF_ID               5


typedef enum
{
    INPUT_PIN, OUTPUT_PIN
}GPIO_PinDirectionType;

typedef enum
{
    DISABLE, ENABLE
}ENABLE_DISABLE;

#define LOGIC_HIGH              1
#define LOGIC_LOW               0



void DIO_Init(uint8 port_num);

void DIO_configurePin(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction ,ENABLE_DISABLE pur_val, ENABLE_DISABLE den_val );

void DIO_Write_Pin(uint8 port_num, uint8 pin_num, uint8 value);

//void DIO_setPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

uint8 DIO_readPin(uint8 port_num, uint8 pin_num);


#endif /* DIO_H_ */
