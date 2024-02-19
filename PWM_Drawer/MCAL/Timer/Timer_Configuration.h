/*
 * Timer_Configuration.h
 *
 * Created: 11/17/2023 9:44:30 AM
 *  Author: Belal
 */ 
//This header file includes the all timer 1 configurations.

#ifndef TIMER_CONFIGURATION_H_
#define TIMER_CONFIGURATION_H_
/*________________Header File________________*/
#include <Timer_Addresses.h>

#define System_Frequency	20000000.0 //Defines the system frequency for calculating frequency and duty cycle.
/*_______________Prescalaer Enum_______________*/
typedef enum
{
	PRE_NO = 0,
	PRE_1,
	PRE_8,
	PRE_64,
	PRE_256,
	PRE_1024
}tprescale;

#endif /* TIMER_CONFIGURATION_H_ */