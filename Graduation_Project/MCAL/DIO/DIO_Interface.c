/*
* DIO.c
*
* Created: 9/15/2023 2:58:34 AM
*  Author: Belal Hassan
*/
//This source file includes all functions definitions of digital input\output (DIO) driver.

/*________________Header File________________*/
#include <DIO_Private.h>

/*____________________PINs Functions Definitinos_____________________*/
void DIO_SetPinDirection(port Port, pin Pin, state State) //Sets the PIN direction.
{
	switch(Port)
	{
		case DIO_PORTA:
		if(State == DIO_Input)
			Clear_Bit(DDRA, Pin); 
		else
			Set_Bit(DDRA, Pin);
		break;
		case DIO_PORTB:
		if(State == DIO_Input)
			Clear_Bit(DDRB, Pin);
		else
			Set_Bit(DDRB, Pin);
		break;
		defult:
		break;
	}
}
void DIO_SetPinValue(port Port, pin Pin, status Status) //Sets the PIN value.
{
	switch(Port)
	{
		case DIO_PORTA:
		if(Status == DIO_Low) 
			Clear_Bit(PORTA, Pin);
		else
			Set_Bit(PORTA, Pin);
		break;
		case DIO_PORTB:
		if(Status == DIO_Low)
			Clear_Bit(PORTB, Pin);
		else
			Set_Bit(PORTB, Pin);
		break;
		defult:
		break;
	}
}
void DIO_TogglePinValue(port Port, pin Pin) //Toggles the PIN value.
{
	switch(Port)
	{
		case DIO_PORTA:
		Toggle_Bit(PORTA, Pin);
		break;
		case DIO_PORTB:
		Toggle_Bit(PORTB, Pin);
		break;
		defult:
		break;
	}
}
u8 DIO_GetPinValue(port Port, pin Pin) //Reads the PIN value.
{
	switch(Port)
	{
		case DIO_PORTA:
		return Get_Bit(PINA, Pin);
		case DIO_PORTB:
		return Get_Bit(PINB, Pin);
		defult:
		break;
	}
	return 0;
}
void DIO_SetPinPullUp(port Port, pin Pin) //Sets the PIN as pull-up.
{ 
	switch(Port)
	{
		case DIO_PORTA:
		Set_Bit(PORTA, Pin);
		break;
		case DIO_PORTB:
		Set_Bit(PORTB, Pin);
		break;
		default:
		break;
	}
}

/*____________________PINs Functions Definitinos_____________________*/
void DIO_SetPortValue(port Port, status Status) //Sets the PORT direction.
{
	switch(Port)
	{
		case DIO_PORTA:
		if(Status == DIO_Low)
			PORTA = DIO_PORT_Low;
		else
			PORTA = DIO_PORT_High;
		break;
		case DIO_PORTB:
		if(Status == DIO_Low)
			PORTB = DIO_PORT_Low;
		else
			PORTB = DIO_PORT_High;
		break;
		defult:
		break;
	}
}
void DIO_WritePortValue(port Port, pin StartPin, pin EndPin, u8 Data) //Writes data on specific bits of the PORT without changing the rest.
{
	u8 Mask = ((1 << (EndPin - StartPin + 1)) - 1) << StartPin, PlaceHolder; 
	switch(Port)
	{
		case DIO_PORTA:
		PlaceHolder = PORTA; 
		PlaceHolder &= ~Mask; 
		PlaceHolder |= Data & Mask;
		PORTA = PlaceHolder;
		break;
		case DIO_PORTB:
		PlaceHolder = PORTB;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		PORTB = PlaceHolder;
		break;
		default:
		break;
	}
}
void DIO_TogglePortValue(port Port) //Toggles the PORT value.
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA ^= DIO_PORT_High;
		break;
		case DIO_PORTB:
		PORTB ^= DIO_PORT_High;
		break;
		defult:
		break;
	}
}
u8 DIO_GetPortValue(port Port) //Reads the PORT value.
{
	switch(Port)
	{
		case DIO_PORTA:
		return PINA;
		case DIO_PORTB:
		return PINB;
		defult:
		break;
	}
	return 0;
}
void DIO_SetPortPullUp(port Port) //Sets the PORT as pull-up.
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA = DIO_PORT_High;
		break;
		case DIO_PORTB:
		PORTB = DIO_PORT_High;
		break;
		default:
		break;
	}
}