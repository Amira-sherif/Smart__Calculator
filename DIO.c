#include "DIO.h"



void DIO_Init(uint8 port_num){

    Set_Bit(SYSCTL_RCGCGPIO_R,port_num);
    while(Get_Bit(SYSCTL_RCGCGPIO_R,port_num)  ==0  ){}

    switch(port_num)
    {
//    case PORTB_ID:
//            GPIO_PORTC_LOCK_R =0x4C4F434B;
//            //GPIO_PORTC_CR_R  =0x1F;
//            break;

    case PORTC_ID:
        GPIO_PORTC_LOCK_R =0x4C4F434B;
        //GPIO_PORTC_CR_R  =0x1F;
        break;
    case PORTD_ID:
        GPIO_PORTD_LOCK_R =0x4C4F434B;
        //GPIO_PORTD_CR_R  =0x1F;
        break;
    case PORTF_ID:
        GPIO_PORTF_LOCK_R =0x4C4F434B;
        //GPIO_PORTF_CR_R  =0x1F;
        break;

    default: break;
    }

}

void DIO_Write_Pin(uint8 port_num, uint8 pin_num, uint8 value)
 {
    switch (port_num)
    {
    case PORTA_ID :
        if(value == LOGIC_HIGH){
            Set_Bit(GPIO_PORTA_DATA_R,pin_num);
        }
        else if(value == LOGIC_LOW){
            Clear_Bit(GPIO_PORTA_DATA_R,pin_num);
        }
        break;
    case PORTB_ID :
         if(value == LOGIC_HIGH){
              Set_Bit(GPIO_PORTB_DATA_R,pin_num);
         }
         else if(value == LOGIC_LOW){
              Clear_Bit(GPIO_PORTB_DATA_R,pin_num);
         }
         break;
    case PORTC_ID :
         if(value == LOGIC_HIGH){
              Set_Bit(GPIO_PORTC_DATA_R,pin_num);
         }
         else if(value == LOGIC_LOW){
              Clear_Bit(GPIO_PORTC_DATA_R,pin_num);
         }
         break;
    case PORTD_ID :
         if(value == LOGIC_HIGH){
              Set_Bit(GPIO_PORTD_DATA_R,pin_num);
         }
         else if(value == LOGIC_LOW){
              Clear_Bit(GPIO_PORTD_DATA_R,pin_num);
         }
         break;
    case PORTE_ID :
         if(value == LOGIC_HIGH){
              Set_Bit(GPIO_PORTE_DATA_R,pin_num);
         }
         else if(value == LOGIC_LOW){
              Clear_Bit(GPIO_PORTE_DATA_R,pin_num);
         }
         break;
    case PORTF_ID :
         if(value == LOGIC_HIGH){
              Set_Bit(GPIO_PORTF_DATA_R,pin_num);
         }
         else if(value == LOGIC_LOW){
              Clear_Bit(GPIO_PORTF_DATA_R,pin_num);
         }
         break;
    }
 }

//void DIO_setPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
//{
//    switch (port_num)
//        {
//            case PORTA_ID :
//                if(direction == INPUT_PIN){
//                    Clear_Bit(GPIO_PORTA_DIR_R, pin_num);
//                }
//                else if(direction == OUTPUT_PIN){
//                    Set_Bit(GPIO_PORTA_DIR_R, pin_num);
//                }
//                break;
//            case PORTB_ID :
//                if(direction == INPUT_PIN){
//                   Clear_Bit(GPIO_PORTB_DIR_R, pin_num);
//                }
//                else if(direction == OUTPUT_PIN){
//                   Set_Bit(GPIO_PORTB_DIR_R, pin_num);
//                }
//                break;
//            case PORTC_ID :
//                if(direction == INPUT_PIN){
//                   Clear_Bit(GPIO_PORTC_DIR_R, pin_num);
//                }
//                else if(direction == OUTPUT_PIN){
//                   Set_Bit(GPIO_PORTC_DIR_R, pin_num);
//                }
//                break;
//            case PORTD_ID :
//                if(direction == INPUT_PIN){
//                   Clear_Bit(GPIO_PORTD_DIR_R, pin_num);
//                }
//                else if(direction == OUTPUT_PIN){
//                   Set_Bit(GPIO_PORTD_DIR_R, pin_num);
//                }
//                break;
//            case PORTE_ID :
//                if(direction == INPUT_PIN){
//                   Clear_Bit(GPIO_PORTE_DIR_R, pin_num);
//                }
//                else if(direction == OUTPUT_PIN){
//                   Set_Bit(GPIO_PORTE_DIR_R, pin_num);
//                }
//                break;
//            case PORTF_ID :
//                if(direction == INPUT_PIN){
//                   Clear_Bit(GPIO_PORTF_DIR_R, pin_num);
//                }
//                else if(direction == OUTPUT_PIN){
//                   Set_Bit(GPIO_PORTF_DIR_R, pin_num);
//                }
//                break;
//        }
//}

uint8 DIO_readPin(uint8 port_num, uint8 pin_num)
{
    uint8 pin_value;
    switch (port_num)
            {
                case PORTA_ID : pin_value = Get_Bit(GPIO_PORTA_DATA_R, pin_num);
                    break;
                case PORTB_ID : pin_value = Get_Bit(GPIO_PORTB_DATA_R, pin_num);
                    break;
                case PORTC_ID : pin_value = Get_Bit(GPIO_PORTC_DATA_R, pin_num);
                    break;
                case PORTD_ID : pin_value = Get_Bit(GPIO_PORTD_DATA_R, pin_num);
                    break;
                case PORTE_ID : pin_value = Get_Bit(GPIO_PORTE_DATA_R, pin_num);
                    break;
                case PORTF_ID : pin_value = Get_Bit(GPIO_PORTF_DATA_R, pin_num);
                    break;
            }
    return pin_value;
}

void DIO_configurePin(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction ,ENABLE_DISABLE pur_val, ENABLE_DISABLE den_val )
{
    switch (port_num)
               {
                   case PORTA_ID : Set_Bit(GPIO_PORTA_CR_R,pin_num);
                                   if(direction == INPUT_PIN) Clear_Bit(GPIO_PORTA_DIR_R, pin_num);
                                   else if(direction == OUTPUT_PIN) Set_Bit(GPIO_PORTA_DIR_R, pin_num);

                                   if(pur_val == ENABLE) Set_Bit(GPIO_PORTA_PUR_R,pin_num);
                                   else Clear_Bit(GPIO_PORTA_PUR_R,pin_num);

                                   if(den_val == ENABLE) Set_Bit(GPIO_PORTA_DEN_R,pin_num);
                                   else Clear_Bit(GPIO_PORTA_DEN_R,pin_num);
                       break;
                   case PORTB_ID : //Set_Bit(GPIO_PORTB_CR_R,pin_num);
                                   if(direction == INPUT_PIN) Clear_Bit(GPIO_PORTB_DIR_R, pin_num);
                                   else if(direction == OUTPUT_PIN) Set_Bit(GPIO_PORTB_DIR_R, pin_num);

                                   if(pur_val == ENABLE) Set_Bit(GPIO_PORTB_PUR_R,pin_num);
                                   else Clear_Bit(GPIO_PORTB_PUR_R,pin_num);

                                   if(den_val == ENABLE) Set_Bit(GPIO_PORTB_DEN_R,pin_num);
                                   else Clear_Bit(GPIO_PORTB_DEN_R,pin_num);
                       break;
                   case PORTC_ID : Set_Bit(GPIO_PORTC_CR_R,pin_num);
                                   if(direction == INPUT_PIN) Clear_Bit(GPIO_PORTC_DIR_R, pin_num);
                                   else if(direction == OUTPUT_PIN) Set_Bit(GPIO_PORTC_DIR_R, pin_num);

                                   if(pur_val == ENABLE) Set_Bit(GPIO_PORTC_PUR_R,pin_num);
                                   else Clear_Bit(GPIO_PORTC_PUR_R,pin_num);

                                   if(den_val == ENABLE) Set_Bit(GPIO_PORTC_DEN_R,pin_num);
                                   else Clear_Bit(GPIO_PORTC_DEN_R,pin_num);
                       break;
                   case PORTD_ID : Set_Bit(GPIO_PORTD_CR_R,pin_num);
                                   if(direction == INPUT_PIN) Clear_Bit(GPIO_PORTD_DIR_R, pin_num);
                                   else if(direction == OUTPUT_PIN) Set_Bit(GPIO_PORTD_DIR_R, pin_num);

                                   if(pur_val == ENABLE) Set_Bit(GPIO_PORTD_PUR_R,pin_num);
                                   else Clear_Bit(GPIO_PORTD_PUR_R,pin_num);

                                   if(den_val == ENABLE) Set_Bit(GPIO_PORTD_DEN_R,pin_num);
                                   else Clear_Bit(GPIO_PORTD_DEN_R,pin_num);
                       break;
                   case PORTE_ID : Set_Bit(GPIO_PORTE_CR_R,pin_num);
                                   if(direction == INPUT_PIN) Clear_Bit(GPIO_PORTE_DIR_R, pin_num);
                                   else if(direction == OUTPUT_PIN) Set_Bit(GPIO_PORTE_DIR_R, pin_num);

                                   if(pur_val == ENABLE) Set_Bit(GPIO_PORTE_PUR_R,pin_num);
                                   else Clear_Bit(GPIO_PORTE_PUR_R,pin_num);

                                   if(den_val == ENABLE) Set_Bit(GPIO_PORTE_DEN_R,pin_num);
                                   else Clear_Bit(GPIO_PORTE_DEN_R,pin_num);
                       break;
                   case PORTF_ID : Set_Bit(GPIO_PORTF_CR_R,pin_num);

                                   if(direction == INPUT_PIN) Clear_Bit(GPIO_PORTF_DIR_R, pin_num);
                                   else if(direction == OUTPUT_PIN) Set_Bit(GPIO_PORTF_DIR_R, pin_num);

                                   if(pur_val == ENABLE) Set_Bit(GPIO_PORTF_PUR_R,pin_num);
                                   else Clear_Bit(GPIO_PORTF_PUR_R,pin_num);

                                   if(den_val == ENABLE) Set_Bit(GPIO_PORTF_DEN_R,pin_num);
                                   else Clear_Bit(GPIO_PORTF_DEN_R,pin_num);
                       break;
               }
}
