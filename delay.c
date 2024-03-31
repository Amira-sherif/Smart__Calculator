#include "delay.h"

void delay_Milli(uint16 delay){
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = delay * freq_factor_milli -1;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x1;
    while(Get_Bit(NVIC_ST_CTRL_R,count_flag) == 0) {}
    NVIC_ST_CURRENT_R = 0;
}


void delay_Micro(uint32 delay){
    NVIC_ST_RELOAD_R = delay * freq_factor_micro -1;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x1;
    while(Get_Bit(NVIC_ST_CTRL_R,count_flag) == 0) {}
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0;
}


void systickInit(void)
{
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 16000000 -1;     //reload with ticks --> w second
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R |= (1<<1) | (1<<2);       //enable systick timer and enable its interrupt
}
