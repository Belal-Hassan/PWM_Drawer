/*
 * Graduation_Project.c
 *
 * Created: 2/5/2024 7:46:01 AM
 * Author : Belal
 */ 
//This is the main source file of the project.
/*____________________Header File____________________*/
#include <Main.h>

int main(void)
{
	/*______________Initializations______________*/
	LCD_Initialize(); //Initializes LCD screen.
	LCD_Display_String("Initializing..."); //Displays the string "Initializing..." on the LCD screen.
	LCD_Store_Special(Overscore, 0); //Stores the Overscore Character for drawing the PWM wave.
	Timer1_ICP_Initialize(); //Initializes Timer 1 in input capture mode.
	/*_________________Super Loop_________________*/
    while (1)
    {
		Timer1_ICP_Start(PRE_1); //Starts the timer with a division factor of 1, and captures 3 edges for calculating frequency and duty cycle.
		Timer1_ICP_Stop(); // Stops the timer to begin the calculations.
		Frequency = Timer1_ICP_Get_Frequency(); //Frequency is calculated and assigned to the variable "Frequency."
		DutyCycle = Timer1_ICP_Get_DutyCycle(); //Duty cycle is calculated and assigned to the variable "DutyCycle."
		LCD_ClearScreen(); //Clears the Screen from "Initializing..." to display the data.
		LCD_Display_Frequency(Frequency); //Displays the input Frequency (x) in the form "Freq = xHz","Freq = xkHz," or "Freq =xMHz."
		LCD_Display_DutyCycle(DutyCycle); //Displays the input duty cycle (y) in the form "DCycle = y%."
		_delay_ms(1000); //Delay for viewing the displayed data.
		LCD_ClearScreen(); //Clears the screen from the data to draw the PWM wave.
		LCD_Send_Command(LCD_Command_DisplayOnCursorOff); //Turns off the blinking cursor to make the drawn wave clear.
		LCD_Draw_Pulse(DutyCycle); //Displays the duty cycles using underscores (_) for low and overscores (?) for high.
		_delay_ms(1000); //Delay for viewing the displayed data.
		LCD_Send_Command(LCD_Command_DisplayOnCursorOn); //Turns on the blinking cursor again.
    }
	return 0;
}