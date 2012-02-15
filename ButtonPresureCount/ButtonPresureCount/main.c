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

//-------------------------------Prototyping-------------------------------------
/*-------------------------------Prototyping-------------------------------------*/
	void Init(void);								//Opstart main parts of the Psoc and LCD
	int Key_count(void);                             // input and dataminer
	
	void Show_on_LCD(char* str, char row, char pos);// Define "RAM" based string to LCD
	void Clear_LCD(char Lstr[], char row, char pos);// Clear the display for unwanted letters
		
//--------------------------------Variables--------------------------------------
/*--------------------------------Variables--------------------------------------*/
		
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
				unsigned char Lstr[32];					// LCD Array
				unsigned int mvalue;					// Local variable for the returned measured value
				mvalue = Key_count(); 	// res = bit on ADC and Ch on port
				/*
				// Programers tool!! to se the step from the ADC on the LCD
				itoa(Lstr,mvalue,10);
				c = 0;
				d = 5;
				Clear_LCD(Lstr, c, d);
				Show_on_LCD(Lstr, c, d);
				*/
				//DBcal on LCD
				itoa(Lstr,mvalue,10); // string pointer, value and base
				
				Clear_LCD(Lstr, Y, X);
				Show_on_LCD(Lstr, Y, X);
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
			LCD_PrCString("Count");			// Print a constant "ROM" string			
		}
		
//---------------------------------Measure---------------------------------------
/*----------------------------------Measure--------------------------------------
Text explaining what main is doing

Measure calls: resulution

Measure is called from: Main

Variables changed : mvalue

---------------------------------------------------------------------------------*/
	int Key_count(void)
		{
			
			int mData;
			static int count = 0;
			
			if ((PRT1DR & 0x10) == 0x10)
			{
				
			}
			mData = count;
			
			return mData;
		}
		
//-------------------------------Show on LCD-------------------------------------
/*--------------------------------Show on LCD------------------------------------
Text explaining what main is doing

Show on LCD calls: Non

Show on LCD is called from: Main

Variables changed: DBcalc, str,

---------------------------------------------------------------------------------*/
	void Show_on_LCD (char Lstr[], char row, char pos)
		{
			LCD_Position(row, pos);						// Position cursor @ row 1, col 2
			LCD_PrString(Lstr); 						// Print "RAM" based string.
		}
		
//------------------------------Clear_LCD----------------------------------------
/*--------------------------------clear_LCD--------------------------------------
Text explaining what main is doing

Show on LCD calls: Non

Show on LCD is called from: Main

Variables changed: DBcalc, str,

---------------------------------------------------------------------------------*/
	void Clear_LCD (char Lstr[], char row, char pos)
		{
			LCD_Position( 0,4 );						// Position cursor @ row 1, col 2
			LCD_PrCString("Count");
			LCD_Position( 0,0 );
			LCD_PrCString("Test INT"); 
		}	