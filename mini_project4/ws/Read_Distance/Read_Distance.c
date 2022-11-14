/*
 ================================================================================================
 Name        : Read_Distance.c
 Author      : Mohamed Aboelezz
 Description : Read the Distance from the sensor with the ultrasonic driver
 	 	 	   ,and display in LCD the distance
 Date        : 12/10/2022
 ================================================================================================
 */

#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>

int main(void)
{
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* distance which is red*/
	uint16 distance;

	LCD_init(); 			/* initialize LCD driver */
	Ultrasonic_init();		/* initialize ULTRASONIC driver */

	/* Display this string "Distance=    cm" only once on LCD at the First row col 0 */
	LCD_displayString("Distance=    cm");

	while(1)
	{
		/* get the distance */
		distance = Ultrasonic_readDistance();

		/* Display the distance value every time at same position */
		LCD_moveCursor(0,10);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}

