/*
 * CLCD_program.c
 *
 *  Created on: Jan 16, 2022
 *      Author: 20111
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"CLCD_config.h"
#include"CLCD_interface.h"
#include "util/delay.h"



void CLCD_voidinit(void)
{
	/*wait for more than 30ms*/
	_delay_ms(40);
	/*function set command : DB3->2 lines, DB2->5*8 font size*/
	CLCD_voidSendCommand(0b00111000);
	/*we already made a delay in send command ,SO NO NEED(delay here 39us) */
	/*display on off control : DB2-> display enable,DB1-> disable cursor ,DB0-> no blink cursor*/
	CLCD_voidSendCommand(0b00001100);
	/*CLEAR DISPLAY : DB0*/
	CLCD_voidSendCommand(0b00000001);

}
void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*set RS pin to low for command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*set command to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*send enable pulse pin */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*set RS pin to high for data */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*set datato data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*send enable pulse pin */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0 ;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}


void CLCD_voidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos == 0)
	{
		/*location is at first line*/
		Local_u8Address = Copy_u8YPos;
	}
	else if (Copy_u8XPos == 1)
	{
		/*location is at second line*/
		Local_u8Address = Copy_u8YPos + 0x40;
	}
	/*set bit number 7 for set DDRAM address command and then send the command */
	CLCD_voidSendCommand(Local_u8Address+128);
}


void CLCD_voidWriteSpecialChar(u8* Copy_pu8Pattern ,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress = 0 ;
	u8 Local_u8loop ;

	/*calculate the CGRAM address whose each block is 8 bytes (block number * 8)*/
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8 ;

	/*send  CGRAM address command to LCD , with setting bit 6 , & clearing bit 6 ( it was already cleared)*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);

	/*write the pattern on CGRAM*/
	for (Local_u8loop = 0 ; Local_u8loop < 8; Local_u8loop++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8loop]);
	}

	/*go back to DDRAM to display the pattern by +128 as shown in memory or\
	by using (goto) function because its use +128 inside the function to access DDRAM memory*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*display the pattern written in CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);

}

void CLCD_voidWriteNumber(u32 Copy_u8Number)
{
	u8 Local_u8SplitNum;
	u8 Local_u8Counter=0;
	u8 Local_u8Array[10];
	if(Copy_u8Number == 0)
	{
		CLCD_voidSendData(Copy_u8Number+0x30);
	}
	else
	{
		while(Copy_u8Number >0)
		{
			Local_u8SplitNum = (Copy_u8Number % 10);
			Local_u8Array[Local_u8Counter]=Local_u8SplitNum;
			Copy_u8Number = Copy_u8Number/10;
			Local_u8Counter++;
		}
		for(Local_u8Counter=Local_u8Counter-1 ; Local_u8Counter>=0 ; Local_u8Counter--)
		{
			CLCD_voidSendData(Local_u8Array[Local_u8Counter]+0x30);
			if(Local_u8Counter == 0)
			{
				break;
			}
		}

	}
}
