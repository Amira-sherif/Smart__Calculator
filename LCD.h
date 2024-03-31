#ifndef LCD_H_
#define LCD_H_

/*******************************************************************************
 *                                includes                                     *
 *******************************************************************************/
#include "DIO.h"
#include "bitwise_operations.h"
#include "delay.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define CONTROL_PORT               GPIO_PORTD_DATA_R
#define  RS_PIN                   0
#define  EN_PIN                   2
#define  RW_PIN                   1

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38         //Function set command/
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80        //set cursor location to zero/


/*******************************************************************************
 *                              Type Definitions                               *
 *******************************************************************************/
typedef enum{CMD,DATA}RS_state;
typedef enum{WRITE,READ}RW_state;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void LCD_wite_cmd_data(char out,RS_state input_rs);
void LCD_init();
void LCD_writ_string(char* str);
void delay(long d);

#endif /* LCD_H_ */
