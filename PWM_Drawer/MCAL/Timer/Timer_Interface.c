/*
* Timer_Interface.c
*
* Created: 11/17/2023 9:45:01 AM
*  Author: Belal
*/
//This source file includes all functions definitions of Timer 1 driver.

/*________________Header File________________*/
#include <Timer_Private.h>

/*______________Variables Decelerations & Initializations______________*/
u16 Capture1 = 0, Capture2 = 0, Capture3 = 0;
f32 Period = 0.0, High_Time = 0.0, Factor = 0.0;

/*________________Functions Definitions________________*/
void Timer1_ICP_Initialize(void) //Initializes Timer 1 in input capture mode.
{
	/*____Setup Normal Operation Mode____*/
	Clear_Bit(TCCR1A, COM1A1);
	Clear_Bit(TCCR1A, COM1A0);
	Clear_Bit(TCCR1A, COM1B1);
	Clear_Bit(TCCR1A, COM1B0);
	/*____Turn-off Waveform Generation Mode____*/
	Clear_Bit(TCCR1A, WGM11);
	Clear_Bit(TCCR1A, WGM10);
	Clear_Bit(TCCR1B, WGM13);
	Clear_Bit(TCCR1B, WGM12);
	Clear_Bit(TCCR1B, ICNC1); //Turns off noise canceling.
	/*____Configure Pin ICP1 as input____*/
	Clear_Bit(DDRA, ICP1);
	Set_Bit(PORTA, ICP1);
}
void Timer1_ICP_Start(tprescale Prescale) //Starts the timer with a chosen prescaler, and captures 3 edges for calculations.
{
	/*____Choosing Timer 1 Prescaler____*/
	switch(Prescale)
	{
		case PRE_NO: //Sets no clock source.
		Clear_Bit(TCCR1B, CS10);
		Clear_Bit(TCCR1B, CS11);
		Clear_Bit(TCCR1B, CS12);
		Factor = 0.0;
		break;
		case PRE_1: //Sets no prescaler (1).
		Set_Bit(TCCR1B, CS10);
		Clear_Bit(TCCR1B, CS11);
		Clear_Bit(TCCR1B, CS12);
		Factor = 1.0;
		break;
		case PRE_8: //Sets prescaler 8.
		Clear_Bit(TCCR1B, CS10);
		Set_Bit(TCCR1B, CS11);
		Clear_Bit(TCCR1B, CS12);
		Factor = 8.0;
		break;
		case PRE_64: //Sets prescaler 64.
		Set_Bit(TCCR1B, CS10);
		Set_Bit(TCCR1B, CS11);
		Clear_Bit(TCCR1B, CS12);
		Factor = 64.0;
		break;
		case PRE_256: //Sets prescaler 256.
		Clear_Bit(TCCR1B, CS10);
		Clear_Bit(TCCR1B, CS11);
		Set_Bit(TCCR1B, CS12);
		Factor = 256.0;
		break;
		case PRE_1024: //Sets prescaler 1024.
		Set_Bit(TCCR1B, CS10);
		Clear_Bit(TCCR1B, CS11);
		Set_Bit(TCCR1B, CS12);
		Factor = 1024.0;
		break;
		default:
		break;
	}
	TCNT1 = 0; //Clears the "TCNT1" counter register.
	/*_____________Capture 1_____________*/
	Set_Bit(TIFR1, ICF1); //Clears the input capture flag (ICF1) to start a new input capture operation.
	Clear_Bit(TCCR1B, ICES1); //Selects the edge to be "falling".
	while(!(Get_Bit(TIFR1, ICF1))) 
		asm("NOP"); //Waits until the "falling" edge gets captured.
	Capture1 = ICR1; //Stores the value of "ICR1" Register in "Capture1" variable.
	Set_Bit(TIFR1, ICF1); //Clears the input capture flag (ICF1) to start a new input capture operation.
	/*_____________Capture 2_____________*/
	Set_Bit(TCCR1B, ICES1); //Selects the edge to be "rising".
	while(!(Get_Bit(TIFR1, ICF1)))
		asm("NOP"); //Waits until the "rising" edge gets captured.
	Capture2 = ICR1; //Stores the value of "ICR1" Register in "Capture2" variable.
	Set_Bit(TIFR1, ICF1); //Clears the input capture flag (ICF1) to start a new input capture operation.
	/*_____________Capture 3_____________*/
	Clear_Bit(TCCR1B, ICES1); //Selects the edge to be "falling".
	while(!(Get_Bit(TIFR1, ICF1)))
		asm("NOP"); //Waits until the "falling" edge gets captured.
	Capture3 = ICR1; //Stores the value of "ICR1" Register in "Capture3" variable.
	Set_Bit(TIFR1, ICF1); //Clears the input capture flag (ICF1) to end captures.
}
u32 Timer1_ICP_Get_Frequency(void) //Returns the frequency of the input wave.
{
	if(Capture1 < Capture2 && Capture2 < Capture3) //Checks if the captures are valid (i.e. an overflow didn't occur).
	{
		Period = (f32)(Capture3 - Capture1); //Calculates the Period of the wave by measuring the time between the 2 consecutive falling edges.
		return (u32)(System_Frequency / (Period * Factor)); //Returns the frequency of the wave by measuring it relative to the system frequency.
	}
	return 0;
}
u8 Timer1_ICP_Get_DutyCycle(void) //Returns the duty cycle of the input wave.
{
	if(Capture1 < Capture2 && Capture2 < Capture3) //Checks if the captures are valid (i.e. an overflow didn't occur).
	{
		Period = (f32)(Capture3 - Capture1); //Calculates the Period of the wave by measuring the time between the 2 consecutive falling edges.
		High_Time = (f32)(Capture3 - Capture2); //Calculates the High wave time by measuring the time between 2 consecutive falling and rising edges.
		return (u8)((High_Time / Period) * 100); //Calculates the ratio between the High time of the wave and the total period, returning the wave.
	}
	return 0;
}
void Timer1_ICP_Stop(void) //Stops the timer.
{
	/*___Selects No Clock Source___*/
	Clear_Bit(TCCR1B, CS10);
	Clear_Bit(TCCR1B, CS11);
	Clear_Bit(TCCR1B, CS12);
}