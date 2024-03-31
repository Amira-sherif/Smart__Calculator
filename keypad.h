

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#include "bitwise_operations.h"
#include "delay.h"
#include "std_types.h"

#define ROW1_PORT_DATA_REG      GPIO_PORTB_DATA_R
#define ROW2_PORT_DATA_REG      GPIO_PORTC_DATA_R
#define ROW3_PORT_DATA_REG      GPIO_PORTC_DATA_R
#define ROW4_PORT_DATA_REG      GPIO_PORTC_DATA_R
#define COL1_PORT_DATA_REG      GPIO_PORTC_DATA_R
#define COL2_PORT_DATA_REG      GPIO_PORTD_DATA_R
#define COL3_PORT_DATA_REG      GPIO_PORTD_DATA_R
#define COL4_PORT_DATA_REG      GPIO_PORTB_DATA_R////

#define ROW1_PIN      3
#define ROW2_PIN      4
#define ROW3_PIN      5
#define ROW4_PIN      6

#define COL1_PIN      7
#define COL2_PIN      6
#define COL3_PIN      0
#define COL4_PIN      2

void keypadInit(void);
uint8 getNum(uint8*);

typedef enum{
    KPD_KEY_PRESSED = 0 ,
    KPD_KEY_NOT_PRESSED,
    KPD_KEYS_TOTAL
}en_kpd_key_state_t;


#endif /* KEYPAD_H_ */
