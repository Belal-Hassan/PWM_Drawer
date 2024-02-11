/*
 * DIO_CONFIGURATION.h
 *
 * Created: 9/14/2023 4:03:11 PM
 *  Author: Belal Hassan
 */ 
//This header file includes the all digital input\output (DIO) configurations.

#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_
/*________________Header Files________________*/
#include <Peripheral_Libraries.h>
#include <DIO_Addresses.h>

/*________________PORT States Definitions________________*/
#define DIO_PORT_Input 0x00
#define DIO_PORT_Output 0xff

/*________________PORT Status Definitions________________*/
#define DIO_PORT_Low 0x00
#define DIO_PORT_High 0xff

/*________________PORTs Redefinition________________*/
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB
}port;

/*________________PINs Redefinition________________*/
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7 
}pin;

/*________________States Redefinition________________*/
typedef enum
{
	DIO_Input = 0,
	DIO_Output
}state;

/*________________Status Redefinition________________*/
typedef enum
{
	DIO_Low = 0,	
	DIO_High
}status;

#endif /* DIO_CONFIGURATION_H_ */