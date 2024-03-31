/*
 * bitwise_operations.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Lenovo
 */

#ifndef BITWISE_OPERATIONS_H_
#define BITWISE_OPERATIONS_H_

#define Set_Bit(Register,Bit) ((Register) = (Register) | (1<<(Bit)))
#define Clear_Bit(Register,Bit) ((Register) = (Register) & (~(1<<(Bit))) )
#define Get_Bit(Register,Bit) ( ((Register)>>(Bit)) & 1 )
#define Toggle_Bit(Register,Bit) ((Register) = (Register) ^ (1<<(Bit)))


#endif /* BITWISE_OPERATIONS_H_ */
