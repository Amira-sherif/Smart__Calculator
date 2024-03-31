#include "DIO.h"
#include "LCD.h"



void send_char(char out)
{

    //  D0    =>  PA7
    if(Get_Bit(out,0)){  Set_Bit( GPIO_PORTA_DATA_R,7 );}
    else{  Clear_Bit( GPIO_PORTA_DATA_R,7 );}

    //  D1    =>  PA6
    if(Get_Bit(out,1)){  Set_Bit( GPIO_PORTA_DATA_R,6 );}
    else{  Clear_Bit( GPIO_PORTA_DATA_R,6 );}

    //  D2    =>  PA5
    if(Get_Bit(out,2)){  Set_Bit( GPIO_PORTA_DATA_R,5 );}
    else{  Clear_Bit( GPIO_PORTA_DATA_R,5 );}

    //  D3    =>  PB4
    if(Get_Bit(out,3)){  Set_Bit( GPIO_PORTB_DATA_R,4 );}
    else{  Clear_Bit( GPIO_PORTB_DATA_R,4 );}
    //  D4    =>  PE5
    if(Get_Bit(out,4)){  Set_Bit( GPIO_PORTE_DATA_R,5 );}
    else{  Clear_Bit( GPIO_PORTE_DATA_R,5 );}

    //  D5   =>  PE4
    if(Get_Bit(out,5)){  Set_Bit( GPIO_PORTE_DATA_R,4 );}
    else{  Clear_Bit( GPIO_PORTE_DATA_R,4 );}

    //  D6    =>  PB1
    if(Get_Bit(out,6)){  Set_Bit( GPIO_PORTB_DATA_R,1 );}
    else{  Clear_Bit( GPIO_PORTB_DATA_R,1 );}

    //  D7    =>  PB0
    if(Get_Bit(out,7)){  Set_Bit( GPIO_PORTB_DATA_R,0 );}
    else{  Clear_Bit( GPIO_PORTB_DATA_R,0 );}

}

void LCD_init(){
//    int i;
    DIO_Init(PORTB_ID);
    DIO_Init(PORTD_ID);
    DIO_Init(PORTE_ID);
    DIO_Init(PORTA_ID);

    DIO_configurePin(PORTB_ID,4, OUTPUT_PIN, DISABLE,ENABLE);
   //DIO_configurePin(PORTB_ID,0, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTB_ID,1, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTA_ID,5, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTA_ID,6, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTA_ID,7, OUTPUT_PIN, DISABLE,ENABLE);

    DIO_configurePin(PORTE_ID,3, OUTPUT_PIN, DISABLE,ENABLE); ///////
    DIO_configurePin(PORTE_ID,4, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTE_ID,5, OUTPUT_PIN, DISABLE,ENABLE);


    DIO_configurePin(PORTD_ID,0, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTD_ID,1, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTD_ID,2, OUTPUT_PIN, DISABLE,ENABLE);


    delay_Milli(50);

    LCD_wite_cmd_data(LCD_TWO_LINES_EIGHT_BITS_MODE,CMD);
    LCD_wite_cmd_data(0x06,CMD);
    LCD_wite_cmd_data( LCD_CURSOR_OFF,CMD);
    LCD_wite_cmd_data(LCD_CLEAR_COMMAND, CMD);

    LCD_wite_cmd_data(0x80, CMD);

}



void LCD_wite_cmd_data(char out,RS_state input_rs)
{

Clear_Bit( CONTROL_PORT ,RW_PIN );

delay_Milli(10);

if(input_rs ==CMD)
{
    Clear_Bit( CONTROL_PORT ,RS_PIN );
}
else
{
    Set_Bit(CONTROL_PORT ,RS_PIN );
}

send_char(out); //ok


delay_Milli(10);

Set_Bit(CONTROL_PORT ,EN_PIN );


delay_Milli(5);

Clear_Bit( CONTROL_PORT ,EN_PIN );

delay_Milli(10);

}

void LCD_writ_string(char* str){
    int i=0;
    while(str[i]!='\0'){
        LCD_wite_cmd_data(str[i],DATA);
        i++;
    }

}
