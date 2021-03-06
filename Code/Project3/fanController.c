/*
 *
 * Module: Application
 *
 * File Name: fanController.c
 *
 * Description: Source file for application module
 *
 * Author: Mohamed Khaled
 *
 */
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

int main ( void )
{
	/* LCD initialization */
	LCD_init();
	LCD_moveCursor(0, 3);
	LCD_displayString("Fan is ");
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp = ");
	uint8 g_temp = LM35_getTemperature();
	LCD_moveCursor(1, 9);
	LCD_intgerToString(g_temp);
	LCD_displayString(" C");

	/* DC motor initialization */
	DcMotor_Init();
	DcMotor_State g_dcMotorState = CW;
	uint8 g_dcMotorSpeed = 0;
	DcMotor_Rotate(g_dcMotorState, g_dcMotorSpeed);

	while(1)
	{
		/* Displaying temperature on LCD */
		g_temp = LM35_getTemperature();
		LCD_moveCursor(1, 9);
		LCD_displayCharacter(' ');
		LCD_intgerToString(g_temp);
		LCD_displayString(" C ");

		/* Displaying fan status and operate motor according to temperature */
		if(g_temp < 30)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString(" OFF ");
			g_dcMotorState = STOP;
			g_dcMotorSpeed = 0;
			DcMotor_Rotate(g_dcMotorState, g_dcMotorSpeed);
		}
		else if(g_temp >= 120)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString(" ON ");
			g_dcMotorState = CW;
			g_dcMotorSpeed = 100;
			DcMotor_Rotate(g_dcMotorState, g_dcMotorSpeed);
		}
		else if(g_temp >= 90)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString(" ON ");
			g_dcMotorState = CW;
			g_dcMotorSpeed = 75;
			DcMotor_Rotate(g_dcMotorState, g_dcMotorSpeed);
		}
		else if(g_temp >= 60)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString(" ON ");
			g_dcMotorState = CW;
			g_dcMotorSpeed = 50;
			DcMotor_Rotate(g_dcMotorState, g_dcMotorSpeed);
		}
		else if(g_temp >= 30)
		{
			LCD_moveCursor(0, 10);
			LCD_displayString(" ON ");
			g_dcMotorState = CW;
			g_dcMotorSpeed = 25;
			DcMotor_Rotate(g_dcMotorState, g_dcMotorSpeed);
		}

	}



	return 0;
}
