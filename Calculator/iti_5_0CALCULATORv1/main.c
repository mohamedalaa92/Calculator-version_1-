/*
 * main.c
 *
 *  Created on: Jan 17, 2022
 *      Author: 20111
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"

#include "MCAL/PORT/PORT_interface.h"

#include "HAL/CLCD/CLCD_interface.h"

#include "HAL/KPD/KPD_interface.h"
#include "HAL/KPD/KPD_config.h"

#include "CALCULATOR_interface.h"
#include "util/delay.h"

void main (void)
{
	u8 Local_u8ValueCal;
	u8 i;
	PORT_voidInit();
	CLCD_voidinit();
	for(i=0; i<=16; i++)
	{ 	CLCD_voidGoToXY(0,i);
		CLCD_voidSendString("##Version 1##");
		CLCD_voidGoToXY(1,i);
		CLCD_voidSendString("##Calculator##");
		_delay_ms(100);
		CLCD_voidSendCommand(1);
	}
	CLCD_voidSendCommand(1);
	while(1)
	{

		Local_u8ValueCal = KPD_u8GetPressedKey();
		CALCULATOR_screen_v2(Local_u8ValueCal);


	}

}
