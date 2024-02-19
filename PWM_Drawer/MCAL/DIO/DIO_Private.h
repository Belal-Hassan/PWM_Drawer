/*
 * DIO.h
 *
 * Created: 9/15/2023 2:53:42 AM
 *  Author: Belal Hassan
 */ 
//This header file declares the used functions throughout digital input\output (DIO) driver.

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
/*________________Header File________________*/
#include <DIO_Configuration.h>

/*____________________PINs Functions Declerations_____________________*/
void DIO_SetPinDirection(port Port, pin Pin, state State); //Sets the PIN direction.
void DIO_SetPinValue(port Port, pin Pin, status Status); //Sets the PIN value.
void DIO_TogglePinValue(port Port, pin Pin); //Toggles the PIN value.
u8 DIO_GetPinValue(port port, pin Pin); //Reads the PIN value.
void DIO_SetPinPullUp(port Port, pin Pin); //Sets the PIN as pullup.

/*____________________PORTs Functions Declerations_____________________*/
void DIO_SetPortValue(port Port, status Status); //Sets the PORT value.
void DIO_WritePortValue(port Port, pin StartPin, pin EndPin, u8 Data); //Writes data on specific bits of the PORT without changing the rest.
void DIO_TogglePortValue(port Port); //Toggles the PORT value.
u8 DIO_GetPortValue(port Port); //Reads the PORT value.
void DIO_SetPortPullUp(port Port); //Sets the PORT as pullup.

#endif /* DIO_PRIVATE_H_ */