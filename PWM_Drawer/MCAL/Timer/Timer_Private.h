/*
 * Timer_Private.h
 *
 * Created: 11/17/2023 9:44:44 AM
 *  Author: Belal
 */ 
//This header file declares the used functions throughout timer 1 driver.

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
/*________________Header File________________*/
#include <Timer_Configuration.h>

/*______________Functions Declerations______________*/
void Timer1_ICP_Initialize(void); //Initializes Timer 1 in input capture mode.
void Timer1_ICP_Start(tprescale Prescale); //Starts the timer with a chosen prescaler, and captures 3 edges for calculations.
u32 Timer1_ICP_Get_Frequency(void); //Returns the frequency of the captured wave.
u8 Timer1_ICP_Get_DutyCycle(void); //Returns the duty cycle of the captured wave.
void Timer1_ICP_Stop(void); //Stops the timer.

#endif /* TIMER_PRIVATE_H_ */