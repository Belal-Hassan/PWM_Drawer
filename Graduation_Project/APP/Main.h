/*
 * Main.h
 *
 * Created: 2/5/2024 8:16:59 AM
 *  Author: Belal
 */ 
//This header file includes all required header files and initializations for the main source file.

#ifndef MAIN_H_
#define MAIN_H_
/*____________________Header Files____________________*/
#include <Peripheral_Libraries.h>
#include <LCD_Private.h>
/*_______________Variables Initialization_______________*/
u32 Frequency = 0; //"Frequency" variable Initialization.
u8 DutyCycle = 0, Overscore[8] = {0b11111,
								  0b00000,
								  0b00000,
								  0b00000,
								  0b00000,
								  0b00000,
								  0b00000,
								  0b00000}; //"Duty Cycle" and "Overscore" variables initialization.

#endif /* MAIN_H_ */