/*
 * macro.h
 *
 * Created: 9/14/2023 3:15:49 PM
 *  Author: Belal Hassan
 */ 
//This header file includes all bit manipulation macros used throughout this project.

#ifndef	BITMATH_H_
#define BITMATH_H_

#define Set_Bit(reg, bit) reg |= (1 << bit) //Sets the "bit" of register "reg."
#define Clear_Bit(reg, bit) reg &= ~(1 << bit) //Clears the "bit" of register "reg."
#define Get_Bit(reg, bit) reg & (1 << bit) //Reads the "bit" of register "reg."
#define Toggle_Bit(reg, bit) reg ^= (1 << bit) //Toggles the "bit" of register "reg."

#endif /* BITMATH_H_ */