/*
* LCD1602_4Bit_Private.h
*
* Created: 9/28/2023 5:07:46 PM
*  Author: Belal hassan
*/


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_
/*________________Header File________________*/
#include <LCD_Configuration.h>

/*______________Variables Decelerations______________*/
u16 Character_Counter;
bool CursorDirection;

/*______________Functions Decelerations______________*/
void LCD_Enable(void); //Sends the High-to-Low enable pulse.
void LCD_Send_Command(u8 Command); //Sends a command to the LCD.
void LCD_HomeScreen(void); //Returns to the home screen of the LCD.
void LCD_ClearScreen(void); //Clears the LCD and returns to the home screen.
void LCD_Initialize(void); //Initializes the LCD.
void LCD_LineCheck(void); //Checks the position of the line based on the "Character_Counter" variable.
void LCD_Display_Character(u8 Character); //Displays a character on the LCD.
void LCD_Display_String(u8 String[]); //Displays a string on the LCD.
void LCD_Reverse_String(u8 String[], u8 Length); //Reverses a string.
u8 LCD_IntToString(u32 Number, u8 String[], u8 Length); //Changes an integer to string.
void LCD_Display_Number(u32 Number); //Displays a number on the LCD.
void LCD_FloatToString(f32 Number, u8 String[], u8 AfterPoint); //Changes float numbers to strings.
void LCD_Display_FloatNumber(f32 Number, u8 AfterPoint); //Displays float numbers.
void LCD_Display_Location(u8 xAxis, u8 yAxis); //Sets the Display location (cursor).
void LCD_Send_Special(u8 Character); //Sends a row of the special character.
void LCD_Store_Special(u8 Character[], u8 Address); //Stores the whole special character in the CGRAM.
void LCD_Display_Frequency(u32 Freq); //Displays the Frequency of the input wave on the LCD.
void LCD_Display_DutyCycle(u8 Duty); //Displays the Frequency of the input wave on the LCD.
void LCD_Draw_Pulse(u8 Duty); //Draws a pulse of the input wave, using the duty cycle.

#endif /* LCD_PRIVATE_H_ */