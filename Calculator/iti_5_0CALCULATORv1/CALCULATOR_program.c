/*
 * CALCULATOR_program.c
 *
 *  Created on: Jan 20, 2022
 *      Author: 20111
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include"CALCULATOR_interface.h"

#include "HAL/CLCD/CLCD_interface.h"


#include "util/delay.h"

typedef struct {
	s32 current_num;
	s32 result;
	u8 current_operation;
	u8 old_operation;
}cal;
cal ptr;
u8 Local_u8first_num = 0;
u8 Local_u8first_op = 0;
u8 Local_u8Negative = 0;
u8 Local_u8Clear = 0;
u8 Local_u8Error = 0;
void CALCULATOR_screen_v2(u8 Copy_u8NumOperation)
{

	if((Local_u8Clear == 1 &&  Copy_u8NumOperation != 0xff) ||Copy_u8NumOperation =='#' )
	{
		Label:
		if(Local_u8Error ==1 )
		{
			CLCD_voidSendCommand(1);
			CLCD_voidSendString("ERROR, not");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("Division by 0 ...");
			_delay_ms(800);
			Local_u8Clear = 1;
		}
		Local_u8Error = 0;
		Local_u8Clear = 0;
		ptr.current_num = 0;
		ptr.current_operation = 0;
		ptr.old_operation = 0;
		ptr.result = 0;
		Local_u8Negative = 0;
		Local_u8first_num = 0;
		Local_u8first_op = 0;

		CLCD_voidSendCommand(1);

	}

	else if((Copy_u8NumOperation >= 0 && Copy_u8NumOperation <= 9) && Local_u8first_num == 0)
	{

		CLCD_voidWriteNumber(Copy_u8NumOperation);
		ptr.current_num = (ptr.current_num * 10) + Copy_u8NumOperation;
		ptr.result = ptr.current_num;
	}
	else if((Copy_u8NumOperation >= 0 && Copy_u8NumOperation <= 9) && Local_u8first_num == 1)
	{
		CLCD_voidWriteNumber(Copy_u8NumOperation);
		ptr.current_num = (ptr.current_num * 10) + Copy_u8NumOperation;

	}
	else if((Local_u8first_op = 0) &&(Copy_u8NumOperation == '+' ||Copy_u8NumOperation == '-' ||Copy_u8NumOperation == '*' ||Copy_u8NumOperation == '/'))
	{
		Local_u8first_num = 1 ;
		Local_u8first_op = 1 ;
		CLCD_voidSendData(Copy_u8NumOperation);
		ptr.old_operation = Copy_u8NumOperation;
		ptr.result = ptr.current_num;
		ptr.current_num = 0;
	}
	else if((Local_u8first_op = 1) &&(Copy_u8NumOperation == '+' ||Copy_u8NumOperation == '-' ||Copy_u8NumOperation == '*' ||Copy_u8NumOperation == '/'))
	{
		Local_u8first_num = 1 ;
		Local_u8first_op = 1 ;
		CLCD_voidSendData(Copy_u8NumOperation);
		switch(ptr.old_operation)
		{
		case '+':
			ptr.result += ptr.current_num;
			break;
		case '-':
			ptr.result -= ptr.current_num;
			break;
		case '*':
			ptr.result *= ptr.current_num;
			break;
		case '/':
			if(ptr.current_num == 0)
			{
				Local_u8Error=1;
				Local_u8Clear=1;
				break;
			}
			ptr.result /= ptr.current_num;
			break;
		}
		ptr.old_operation = Copy_u8NumOperation;
		ptr.current_num = 0;

	}
	else if(Copy_u8NumOperation == '=' )
	{

		switch(ptr.old_operation)
		{
		case '+':
			ptr.result += ptr.current_num;
			break;
		case '-':
			if(ptr.current_num > ptr.result)
			{
				u8 temp;
				Local_u8Negative =1;
				temp = ptr.current_num - ptr.result;
				ptr.result = temp;
				break;
			}

			ptr.result -= ptr.current_num;
			break;
		case '*':
			ptr.result *= ptr.current_num;
			break;
		case '/':
			if(ptr.current_num == 0)
			{
				Local_u8Error=1;
				Local_u8Clear=1;
				goto Label;
			}
			ptr.result /= ptr.current_num;
			break;
		}
		ptr.current_num = 0;
		CLCD_voidSendData(Copy_u8NumOperation);
		if(Local_u8Negative == 1)
			CLCD_voidSendData('-');
		CLCD_voidWriteNumber(ptr.result);
		Local_u8Clear = 1;
	}





}




