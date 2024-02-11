/*
 * LCD1602_Configuration.h
 *
 * Created: 9/28/2023 5:07:19 PM
 *  Author: Belal hassan
 */ 


#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

#include <Peripheral_Libraries.h>

// Global Variable
extern u16 Character_Counter;
// Renaming PORTs
#define LCD_Control_PORT					DIO_PORTA
#define LCD_Enable_PORT						DIO_PORTB
#define LCD_Data_PORT						DIO_PORTA
#define LCD_PORT							PORTA
// Renaming PINs
#define LCD_RS_PIN							DIO_PIN1
#define LCD_RW_PIN							DIO_PIN2
#define LCD_EN_PIN							DIO_PIN2
#define LCD_PIN_D4							DIO_PIN3
#define LCD_PIN_D5							DIO_PIN4
#define LCD_PIN_D6							DIO_PIN5
#define LCD_PIN_D7							DIO_PIN6
// Renaming States
#define LCD_Output							DIO_Output
// Renaming Status
#define LCD_High							DIO_High
#define LCD_Low								DIO_Low
// Renaming Commands
#define LCD_Command_ClearScreen				0x01
#define LCD_Command_ReturnHome				0x02
#define LCD_Command_DecrementCursor			0x04
#define LCD_Command_DisplayRight			0x1C
#define LCD_Command_IncrementCursor			0x06
#define LCD_Command_DisplayLeft				0x18
#define LCD_Command_DisplayOffCursorOff		0x08
#define LCD_Command_DisplayOffCursorOn		0x0A
#define LCD_Command_DisplayOnCursorOff		0x0C
#define LCD_Command_DisplayOnCursorBlink	0x0E
#define LCD_Command_DisplayOnCursorOn		0x0F
#define LCD_Command_ShiftLeft				0x10
#define LCD_Command_ShiftRight				0x14
#define LCD_Command_2ndLine					0xC0
#define LCD_Command_4Bit2Line				0x28
#define LCD_Command_8BitInitialize			0x33
#define LCD_Command_4BitInitialize			0x32
#define LCD_Command_CGRAM					0x40
#define LCD_Command_1stLine					0x80
//Bit Shifting
#define LCD_Right_Shift						(DIO_PIN7 - LCD_PIN_D7)
#define LCD_Left_Shift						(LCD_PIN_D4 - DIO_PIN0)
//Special Characters
#define Overscore0 0x00

#endif /* LCD_CONFIGURATION_H_ */