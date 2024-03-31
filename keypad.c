#include "keypad.h"

uint8 arr_col[4][2] = {{PORTC_ID, COL1_PIN},
                       {PORTD_ID, COL2_PIN},
                       {PORTE_ID, COL3_PIN},    ///
                       {PORTB_ID, COL4_PIN}};

uint8 arr_rows[4][2] = {
                       {PORTB_ID,ROW1_PIN},
                       {PORTC_ID, ROW2_PIN},
                       {PORTC_ID, ROW3_PIN},
                       {PORTC_ID, ROW4_PIN} };

uint8 keypad_arr[4][4] = {
                          {'1','2','3','+'},
                          {'4','5','6','-'},
                          {'7','8','9','*'},
                          {'R','0','=','/'},
};


void keypadInit(void){
    DIO_Init(PORTB_ID);
    DIO_Init(PORTD_ID);
    DIO_Init(PORTC_ID);
    DIO_Init(PORTE_ID);
    //ROWS pins configuration(output)


    DIO_configurePin(PORTB_ID,ROW1_PIN, OUTPUT_PIN, DISABLE,ENABLE);  //pb3
    DIO_configurePin(PORTC_ID,ROW2_PIN, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTC_ID,ROW3_PIN, OUTPUT_PIN, DISABLE,ENABLE);
    DIO_configurePin(PORTC_ID,ROW4_PIN, OUTPUT_PIN, DISABLE,ENABLE);

    DIO_Write_Pin(PORTB_ID,ROW1_PIN, LOGIC_HIGH);
    DIO_Write_Pin(PORTC_ID,ROW2_PIN, LOGIC_HIGH);
    DIO_Write_Pin(PORTC_ID,ROW3_PIN, LOGIC_HIGH);
    DIO_Write_Pin(PORTC_ID,ROW4_PIN, LOGIC_HIGH);


    //COLS pins configuration(input)
    DIO_configurePin(PORTC_ID,COL1_PIN, INPUT_PIN, ENABLE,ENABLE);
    DIO_configurePin(PORTD_ID,COL2_PIN, INPUT_PIN, ENABLE,ENABLE);
    DIO_configurePin(PORTE_ID,COL3_PIN, INPUT_PIN, ENABLE,ENABLE);
    DIO_configurePin(PORTB_ID,COL4_PIN, INPUT_PIN, ENABLE,ENABLE);

}

uint8 getNum(uint8 * key)
{
    uint8 r,c;
    en_kpd_key_state_t keyPressed = KPD_KEY_NOT_PRESSED;

    for(r= 0; r <4; r++)
    {
//        DIO_configurePin(arr_rows[r][0],arr_rows[r][1], OUTPUT_PIN, DISABLE,ENABLE);
        DIO_Write_Pin(arr_rows[r][0],arr_rows[r][1], LOGIC_LOW);
//        delay_Milli(1000);

        for(c=0; c<4; c++)
        {
            if(DIO_readPin(arr_col[c][0], arr_col[c][1]) == 0 )
            {
                while(DIO_readPin(arr_col[c][0], arr_col[c][1]) == 0);
                DIO_Write_Pin(arr_rows[r][0],arr_rows[r][1], LOGIC_HIGH);
                *key = keypad_arr[r][c];
                keyPressed = KPD_KEY_PRESSED;
                break;
            }
        }
        DIO_Write_Pin(arr_rows[r][0],arr_rows[r][1], LOGIC_HIGH);
    }
    return keyPressed;
}


