
#ifndef APP_H_
#define APP_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include "LCD.h"
#include "keypad.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define input_from_keypad_SIZE      16
#define conc_nums_ops_SIZE          16

/*******************************************************************************
 *                              extern variables                               *
 *******************************************************************************/
extern uint8 error_flag ;
extern sint16 conc_nums_ops[conc_nums_ops_SIZE];

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void displayFromKeypad(uint8 num);
void fillArrayFromKeypad(uint8 num);
uint8 charToInt(uint8 ch);
uint8 intToChar(uint8 int_num);
void displayAnswer(void);
void conc(void);
sint16 operationHandling(sint16 num1,sint16 op,sint16 num2);
void precedenceHandling(void);

#endif /* APP_H_ */
