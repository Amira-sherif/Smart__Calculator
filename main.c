#include "APP.h"
int main()
{
    LCD_init();
    keypadInit();
     uint8 num, doneFlag=0;
         while (1)
         {
             uint8 keyPad_status = getNum(&num);
             if((keyPad_status == KPD_KEY_PRESSED) && ( doneFlag != 1))
             {
                 if(num == '=')
                 {
                     doneFlag = 1;
                     displayFromKeypad(num);
                     fillArrayFromKeypad(charToInt(num));
                     conc();
                     precedenceHandling();
                     if(!error_flag)
                     {
                         displayAnswer();
                     }
                 }

                 if(doneFlag == 0)
                 {
                     displayFromKeypad(num);
                     fillArrayFromKeypad(charToInt(num));
                 }
             }
             else if((num == 'R'))
             {
                 doneFlag = 0;
                 displayFromKeypad(num);
             }


         }
}


