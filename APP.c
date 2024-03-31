#include "APP.h"

/***************************************************************************************************
 *                                Global variables                                                 *
 ***************************************************************************************************/
uint8 input_from_keypad[input_from_keypad_SIZE];
sint16 conc_nums_ops[conc_nums_ops_SIZE];
uint8 input_from_keypad_SIZE_used = 0;
uint8 error_flag = 0;
uint8 counter=0;

/***************************************************************************************************
* Function Name: displayFromKeypad
* Parameters (in): uint8 num
* Return value: None
* Description:display the number taken from the keypad on LCD
*
****************************************************************************************************/
void displayFromKeypad(uint8 num)
{
    switch(num)
           {
           case '0':
           case '1':
           case '2':
           case '3':
           case '4':
           case '5':
           case '6':
           case '7':
           case '8':
           case '9':
           case '*':
           case '+':
           case '-':
           case '/':
           case '=':
               LCD_wite_cmd_data(num, DATA);
               break;
           case 'R':     /*an option for resetting the calculator*/
               input_from_keypad_SIZE_used = 0;
               LCD_wite_cmd_data(LCD_CLEAR_COMMAND,CMD);
               error_flag = 0;
               break;

          }
    delay_Milli(500);
}


/***************************************************************************************************
* Function Name: fillArrayFromKeypad
* Parameters (in): uint8 num
* Return value: None
* Description:take each digit from keypad and and add it into a specific array for the inputs
*
****************************************************************************************************/

void fillArrayFromKeypad(uint8 num)
{

    if((input_from_keypad_SIZE_used < input_from_keypad_SIZE))
    {
        input_from_keypad[input_from_keypad_SIZE_used] = num;
        input_from_keypad_SIZE_used++;
    }
    //input_from_keypad_SIZE_used will be the used size of the array
    return;
}

/***************************************************************************************************
* Function Name: charToInt
* Parameters (in): uint8 ch
* Return value: None
* Description:converts the given char into an integer value
*
****************************************************************************************************/


uint8 charToInt(uint8 ch)
{
    if( (ch>= '0')&& (ch<='9') )
    {
        ch -= '0';
    }

    return ch;
}

/***************************************************************************************************
* Function Name: intToChar
* Parameters (in): uint8 int_num
* Return value: None
* Description:converts the given an integer value into a character
*
****************************************************************************************************/
uint8 intToChar(uint8 int_num)
{

    return (int_num += '0');
}


/***************************************************************************************************
* Function Name: displayAnswer
* Parameters (in): None
* Return value: None
* Description:to display the answer of the entered equation including checking on the negative
*  values of it
*
****************************************************************************************************/
void displayAnswer(void)
{
    int num = conc_nums_ops[0];
    sint8 i;
    uint8 j;

    /* print negative sign */
    if (num < 0)
    {
        LCD_wite_cmd_data('-', DATA);
        num = -num; // Make the number positive for printing
    }

    int numLength = 1;
    int tempNum = num;

    while (tempNum /= 10) {
        numLength++;
    }

    for (i = numLength -1; i >= 0; i--) {
        int powerOf10 = 1;
        for (j = 0; j < i; j++) {
            powerOf10 *= 10;
        }
        int digit = (num / powerOf10) % 10;

        LCD_wite_cmd_data(intToChar(digit), DATA);
    }
}



/***************************************************************************************************
* Function Name: conc
* Parameters (in): None
* Return value: None
* Description:manipulate the array of inputs which contains individual digits to concatenate the digits
*  of each number
*
****************************************************************************************************/
void conc(void)
{
    uint8 i=0,nums_flag=0,neg_flag =0;
    sint16 key_num=0,j=0;

    for(i=0;i<input_from_keypad_SIZE_used;i++)
    {
        if(input_from_keypad[i]=='+'||input_from_keypad[i]=='-'||input_from_keypad[i]=='*'||input_from_keypad[i]=='/')
        {
            if(nums_flag)
            {
                if(neg_flag)
                {
                    conc_nums_ops[j]=key_num*(-1);
                    key_num=0;
                    neg_flag=0;
                    j++;
                    counter++;
                }
                else
                {
                    conc_nums_ops[j]=key_num;
                    key_num=0;
                    j++;
                    counter++;
                }

            }
            if(input_from_keypad[i]=='-')
            {
                if(!nums_flag)
                {
                    neg_flag=1;
                }
                else
                {
                    conc_nums_ops[j]=input_from_keypad[i];
                    nums_flag=0;
                    j++;
                    counter++;
                }
            }
            else
            {
                conc_nums_ops[j]=input_from_keypad[i];
                nums_flag=0;
                j++;
                counter++;
            }
        }
        else if(input_from_keypad[i]=='=')
        {
            if(neg_flag)
            {
                conc_nums_ops[j]=key_num*(-1);
                key_num=0;
                neg_flag=0;
                j++;
                counter++;
            }
            else
            {
                conc_nums_ops[j]=key_num;
                key_num=0;
                j++;
                counter++;
            }
        }
        else
        {
            key_num=(key_num*10)+input_from_keypad[i];
            nums_flag=1;
        }
    }
}


/***************************************************************************************************
* Function Name: operationHandling
* Parameters (in): sint16 num1 - sint16 op - sint16 num2
* Return value: sint16 value  -  the result of a simple operation
* Description:takes a two operands and an operator and return the result
*
****************************************************************************************************/

sint16 operationHandling(sint16 num1,sint16 op,sint16 num2)
{
    sint16 result;
      switch(op)
      {
      case '*':
          result=(num1*num2);
          break;
      case '/':
          if(num2 == 0)
          {
              input_from_keypad_SIZE_used = 0;
              LCD_wite_cmd_data(LCD_CLEAR_COMMAND,CMD);
              LCD_writ_string("ERROR");
              delay_Milli(100);
              error_flag = 1;
          }
          else
          {
              result=(num1/num2);
              error_flag = 0;
          }
          break;
      case '+':
          result=(num1+num2);
          break;
      case '-':
          result=(num1-num2);
          break;
      }
      return result;
}

/***************************************************************************************************
* Function Name: precedenceHandling
* Parameters (in): None
* Return value: None
* Description:checks and handles the precedence of the operations in the given equation
*
****************************************************************************************************/
void precedenceHandling(void)
{
    uint8 i,j;
    for(i=0;i<counter;)
    {
        if(conc_nums_ops[i]=='*'||conc_nums_ops[i]=='/')
        {
            conc_nums_ops[i-1]=operationHandling(conc_nums_ops[i-1],conc_nums_ops[i],conc_nums_ops[i+1]);
            j=i;
            while(j<counter)
            {
                conc_nums_ops[j]=conc_nums_ops[j+2];
                j++;
            }
        }
        else
        {
            i++;
        }
    }
    for(i=0;i<counter;)
    {
        if(conc_nums_ops[i]=='+'||conc_nums_ops[i]=='-')
        {
            conc_nums_ops[i-1]=operationHandling(conc_nums_ops[i-1],conc_nums_ops[i],conc_nums_ops[i+1]);
            j=i;
            while(j<counter)
            {
                conc_nums_ops[j]=conc_nums_ops[j+2];
                j++;
            }
        }
        else
        {
            i++;
        }
    }
}



