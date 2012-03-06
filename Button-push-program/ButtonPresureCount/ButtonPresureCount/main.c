/*
================================================================================
Name        : ADC_to_LCD.c
Author      : 1.sem a class
Version     : 4v
Copyright   : Your copyright notice
Description : Sound measure in C, Ansi-style
================================================================================
*/
//-------------------------------------------------------------------------------
// C main line
//-------------------------------------------------------------------------------
#include <m8c.h>        		// Part specific constants and macros
#include "PSoCAPI.h"    		// PSoC API definitions for all User Modules
#include <math.h>				// Math to use logf
#include <stdlib.h>				// normal c liberi
//-------------------------------Definitions-------------------------------------
//Defines for the hole program
//-------------------------------------------------------------------------------
//LCD Row and position
	#define Y 1
	#define X 6
//Key defines to port 1 pin 4 5 6 7
	#define KEY0_EVENT_Enter	0x10
	#define KEY1_EVENT_Cancel	0x20
	#define KEY2_EVENT_Left		0x40
	#define KEY3_EVENT_Rigth	0x80
//-------------------------------Prototyping-------------------------------------
/*-------------------------------Prototyping-------------------------------------*/
	void Init(void);								//Opstart main parts of the Psoc and LCD
	int Key_Push_Count(void);                             // input and dataminer
	
	void Show_on_LCD(char* LCDstr, char row, char pos);// Define "RAM" based string to LCD
	void Clear_LCD(char LCDstr[], char row, char pos);// Clear the display for unwanted letters
		
//--------------------------------Variables--------------------------------------
/*--------------------------------Variables--------------------------------------*/
		int key1 = 0;
		int key2 = 0;
		int key3 = 0;
		int key4 = 0;
//----------------------------------Main-----------------------------------------
/*----------------------------------Main-----------------------------------------

Text explaining what main is doing

Main call:  Init, Measure & Show_on_LCD

Variables changed: Non

---------------------------------------------------------------------------------*/
	void main(void)
		{
			Init();
			
			while(1)
			{
				unsigned char LCDstr[32];					// LCD Array
				unsigned int mvalue;					// Local variable for the returned measured value
				mvalue = Key_Push_Count(); 	// res = bit on ADC and Ch on port
				/*
				// Programers tool!! to se the step from the ADC on the LCD
				itoa(LCDstr,mvalue,10);
				c = 0;
				d = 5;
				Clear_LCD(LCDstr, c, d);
				Show_on_LCD(LCDstr, c, d);
				*/
				//DBcal on LCD
				itoa(LCDstr,mvalue,10); // string pointer, value and base
				
				Clear_LCD(LCDstr, Y, X);
				Show_on_LCD(LCDstr, Y, X);
			}
		
		}
		
//----------------------------------Init-----------------------------------------
/*----------------------------------Init-----------------------------------------
Text explaining what main is doing

Init calls: Non

Init is called from: Main

Variables changed :non

---------------------------------------------------------------------------------*/
	void Init(void)
		{
			//M8C_EnableGInt;                    			// Enable global interrupts
			LCD_Start(); 								// Initialize LCD hardware
			LCD_Position(0,1);							// Position cursor @ row 0, col 4
			LCD_PrCString("Count Push");			// Print a constant "ROM" string			
		}
	
//----------------------------------Key_Push_Count--------------------------------------
/*----------------------------------Key_Push_Count--------------------------------------
Text explaining what main is doing

Key_Push_Count calls: resulution

Key_Push_Count is called from: Main

Variables changed : mvalue

---------------------------------------------------------------------------------*/
	int Key_Push_Count(void)
		{
		int Readkeys(int RawKeys);
			static int key1pressed = 0;
			static int key2pressed = 0;
			static int key3pressed = 0;
			static int key4pressed = 0;
			
			if (PRT1DR & KEY0_EVENT_Enter)
				{
				if (key1pressed == 0)
					{
					//indsæt knap programering
						key1pressed = 1;
						key1++;
					}
				}
			else
				{
					key1pressed = 0;
				}
			
			return key1;
		}
		
//-------------------------------Show on LCD-------------------------------------
/*--------------------------------Show on LCD------------------------------------
Text explaining what main is doing

Show on LCD calls: Non

Show on LCD is called from: Main

Variables changed: DBcalc, LCDstr,

---------------------------------------------------------------------------------*/
	void Show_on_LCD (char LCDstr[], char row, char pos)
		{
			LCD_Position(row, pos);						// Position cursor @  row 0-1, col 0-15
			LCD_PrString(LCDstr); 						// Print "RAM" based string.
		}
		
//------------------------------Clear_LCD----------------------------------------
/*--------------------------------clear_LCD--------------------------------------
Text explaining what main is doing

Show on LCD calls: Non

Show on LCD is called from: Main

Variables changed: DBcalc, LCDstr,

---------------------------------------------------------------------------------*/
	void Clear_LCD (char LCDstr[], char row, char pos)
		{
			LCD_Position( 0,0);						// Position cursor @ row 0-1, col 0-15
			LCD_PrCString("    Count Push    ");
			LCD_Position( 1,0 );
			LCD_PrCString("                "); 
		}	