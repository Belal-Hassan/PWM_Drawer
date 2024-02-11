/*
 * LCD1602_4Bit_Interface.c
 *
 * Created: 9/28/2023 5:08:17 PM
 *  Author: Belal hassan
 */ 
#include <LCD_Private.h>

void LCD_Enable(void) //Sends the High-to-Low enable pulse.
{
	DIO_SetPinValue(LCD_Enable_PORT, LCD_EN_PIN, LCD_High);
	_delay_ms(1);
	DIO_SetPinValue(LCD_Enable_PORT, LCD_EN_PIN, LCD_Low);
}
void LCD_Send_Command(u8 Command) //Sends a command to the LCD.
{
	/*_______________Sends Command_______________*/
	DIO_SetPinValue(LCD_Control_PORT, LCD_RS_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Control_PORT, LCD_RW_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Enable_PORT, LCD_EN_PIN, LCD_Low);
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Command & 0xF0) >> LCD_Right_Shift);
	LCD_Enable();
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Command & 0x0F) << LCD_Left_Shift);
	LCD_Enable();
	_delay_us(100);
	
	/*_______________Decides if the Character Count should increase or decrease_______________*/
	if(Command == LCD_Command_IncrementCursor || Command == LCD_Command_DisplayLeft)
		CursorDirection = false;
	if(Command == LCD_Command_DecrementCursor || Command == LCD_Command_DisplayRight)
		CursorDirection = true;
}
void LCD_HomeScreen(void) //Returns to the home screen of the LCD.
{
	LCD_Send_Command(0x02);
	_delay_us(1900);
	Character_Counter = 0;
}
void LCD_ClearScreen(void) //Clears the LCD and returns to the home screen.
{
	LCD_Send_Command(0x01);
	LCD_HomeScreen();
	_delay_us(1900);
}
void LCD_Initialize(void) //Initializes the LCD.
{
	static bool Initialized = false;
	if(!Initialized) //An if condition for initializing the LCD once.
	{
		DIO_SetPinDirection(LCD_Control_PORT, LCD_RS_PIN, LCD_Output);
		DIO_SetPinDirection(LCD_Control_PORT, LCD_RW_PIN, LCD_Output);
		DIO_SetPinDirection(LCD_Enable_PORT, LCD_EN_PIN, LCD_Output);
		DIO_SetPinDirection(LCD_Data_PORT, LCD_PIN_D4, LCD_Output);
		DIO_SetPinDirection(LCD_Data_PORT, LCD_PIN_D5, LCD_Output);
		DIO_SetPinDirection(LCD_Data_PORT, LCD_PIN_D6, LCD_Output);
		DIO_SetPinDirection(LCD_Data_PORT, LCD_PIN_D7, LCD_Output);
		_delay_ms(15);
		LCD_Send_Command(LCD_Command_8BitInitialize);
		LCD_Send_Command(LCD_Command_4BitInitialize);
		LCD_Send_Command(LCD_Command_4Bit2Line);
		LCD_Send_Command(LCD_Command_DisplayOnCursorOn);
		LCD_Send_Command(LCD_Command_IncrementCursor);
		LCD_ClearScreen();
		Initialized = true;
	}
}
void LCD_LineCheck(void) //Checks the position of the line based on the "Character_Counter" variable.
{
	if(Character_Counter % 32 == 0)
	{
		LCD_ClearScreen();
		LCD_Send_Command(LCD_Command_1stLine);
	}
	else if(Character_Counter % 16 == 0)
		LCD_Send_Command(LCD_Command_2ndLine);
}
void LCD_Display_Character(u8 Character) //Displays a character on the LCD.
{
	/*_______________Sends Character_______________*/
	LCD_Initialize();
	LCD_LineCheck();
	DIO_SetPinValue(LCD_Control_PORT, LCD_RS_PIN, LCD_High);
	DIO_SetPinValue(LCD_Control_PORT, LCD_RW_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Enable_PORT, LCD_EN_PIN, LCD_Low);
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Character & 0xF0) >> LCD_Right_Shift);
	LCD_Enable();
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Character & 0x0F) << LCD_Left_Shift);
	LCD_Enable();
	_delay_us(100);
	
	/*_______________Checks if the Character Count should increase or decrease_______________*/
	if(CursorDirection)
		Character_Counter--;
	else
		Character_Counter++;
}
void LCD_Display_String(u8 String[]) //Displays a string on the LCD.
{
	u8 Counter = 0;
	while(String[Counter] != '\0') //Simply by repeating the display character function.
		LCD_Display_Character(String[Counter++]);
}
void LCD_Reverse_String(u8 String[], u8 Length) //Reverses a string.
{
	u8 Counter = 0, temp;
	Length--;
	while(Counter < Length)
	{
		temp = String[Counter];
		String[Counter++] = String[Length];
		String[Length--] = temp;
	}
}
u8 LCD_IntToString(u32 Number, u8 String[], u8 Length) //Changes an integer to string.
{
	u8 Counter = 0;
	while (Number)
	{
		String[Counter++] = (Number % 10) + '0';
		Number /= 10;
	}
	while (Counter < Length)
		String[Counter++] = '0';
	LCD_Reverse_String(String, Counter);
	String[Counter] = '\0';
	return Counter;
}
void LCD_Display_Number(u32 Number) //Displays a number on the LCD.
{
	if(Number == 0)
	{
		LCD_Display_Character('0');
		return;
	}
	u8 String[33];
	LCD_IntToString(Number, String, 0); //First, it transforms it into a string.
	LCD_Display_String(String); //Then, displays the string.
}
void LCD_FloatToString(f32 Number, u8 String[], u8 AfterPoint) //Changes float numbers to strings.
{
	u32 int_part = (u32)Number;
	f32 float_part = Number - (f32)int_part;
	u8 Counter = LCD_IntToString(int_part, String, 0);
	String[Counter] = '.';
	float_part *= pow(10, AfterPoint);
	LCD_IntToString((u64)float_part, String + Counter + 1, AfterPoint);
}
void LCD_Display_FloatNumber(f32 Number, u8 AfterPoint) //Displays float numbers.
{
	u8 String[33];
	LCD_FloatToString(Number, String, AfterPoint); //First, the number is converted into a string.
	LCD_Display_String(String); //Then, the string is displayed on the LCD.
}
void LCD_Display_Location(u8 xAxis, u8 yAxis) //Sets the Display location (cursor).
{
	LCD_Initialize();
	u8 RowAddress[2] = {0x80, 0xC0};
	LCD_Send_Command(RowAddress[yAxis] + xAxis);
	Character_Counter = (yAxis * 16) + (xAxis); //After sending the command, the "Character_Counter" is set to match the location.
}
void LCD_Send_Special(u8 Character) //Sends a row of the special character.
{
	LCD_Initialize();
	DIO_SetPinValue(LCD_Control_PORT, LCD_RS_PIN, LCD_High);
	DIO_SetPinValue(LCD_Control_PORT, LCD_RW_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Enable_PORT, LCD_EN_PIN, LCD_Low);
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Character & 0xF0) >> LCD_Right_Shift);
	LCD_Enable();
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Character & 0x0F) << LCD_Left_Shift);
	LCD_Enable();
	_delay_us(100);
}
void LCD_Store_Special(u8 Character[], u8 Address)  //Stores the whole special character in the CGRAM.
{
	LCD_Send_Command(LCD_Command_CGRAM + (Address * 8));
	for(int i = 0; i < 8; i++)
		LCD_Send_Special(Character[i]);
	LCD_Display_Location(Character_Counter % 16, Character_Counter / 16);
}
void LCD_Display_Frequency(u32 Freq) //Displays the Frequency of the input wave on the LCD.
{
	LCD_Display_String("Freq = ");
	if(Freq >= 1000000) //If the frequency is more than 1000000, it's displayed in "MHz."
	{
		LCD_Display_FloatNumber((f32)Freq / 1000000.0, 1);
		LCD_Display_String("MHz");
	}
	else if(Freq >= 1000) //If the frequency is more than 1000, it's displayed in "kHz."
	{
		LCD_Display_FloatNumber((f32)Freq / 1000.0, 1);
		LCD_Display_String("KHz");
	}
	else //Else, the frequency is displayed in "Hz."
	{
		LCD_Display_Number(Freq);
		LCD_Display_String("Hz");
	}
}
void LCD_Display_DutyCycle(u8 Duty) //Displays the Frequency of the input wave on the LCD.
{
	LCD_Display_Location(0, 1);
	LCD_Display_String("DCycle = ");
	LCD_Display_Number(Duty);
	LCD_Display_Character('%');
}
void LCD_Draw_Pulse(u8 Duty) //Draws a pulse of the input wave, using the duty cycle.
{	
	/*____________Rounding the high pulses number_____________*/
	u16 High_Pixels;
	u8 Pixel_Duty = round((f32)(Duty) * (16.0/100.0)), Counter; 
	if (Duty >= 50)
		High_Pixels = Pixel_Duty + (Pixel_Duty % 2);
	else
		High_Pixels = Pixel_Duty - (Pixel_Duty % 2);
	
	/*____________Displaying a Low-High-Low Pulse____________*/
	LCD_Display_Location(0, 1);
	for(Counter = 0; Counter < (16 - High_Pixels) / 2; Counter++)
		LCD_Display_Character('_');
	LCD_Display_Location(Counter, 0);
	u8 Place_Holder = Counter;
	for (Counter; Counter < High_Pixels + Place_Holder; Counter++)
		LCD_Display_Character(Overscore0);
	LCD_Display_Location(Counter, 1);
	for(Counter; Counter < 16; Counter++)
		LCD_Display_Character('_');
}