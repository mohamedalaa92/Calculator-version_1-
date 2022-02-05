/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: MCAL                     ***********************/
/*****************    SWC: DIO_program.c              ***********************/
/*****************    VER: 2.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"

/************************** SET_BIT & SET_PORT DIRECTION **********************************/
               /*I use it in PORT driver instead of here as AUTOSAR */

///********** this function shall set the direction for the desired pin *********************/
//u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction)
//{
//	/*make error state be 1 if the user entered the wrong input to the function*/
//	u8 Local_u8ErrorState = 0;
//	/*check if the input is in between bits (0-7) or send error */
//	if (Copy_u8Pin <= DIO_u8PIN7)
//	{
//		/*check if the direction is output or input or, else send error */
//		if ( Copy_u8Direction == DIO_u8PIN_INPUT)
//		{
//			switch ( Copy_u8Port )
//			{
//			/*check if the correct port or, else send error */
//			case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin); break;
//			case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin); break;
//			case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin); break;
//			case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin); break;
//			default : Local_u8ErrorState = 1 ;
//			}
//
//		}
//		else if ( Copy_u8Direction == DIO_u8PIN_OUTPUT)
//		{
//			switch ( Copy_u8Port )
//			{
//			/*check if the correct port or, else send error */
//			case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin); break;
//			case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin); break;
//			case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin); break;
//			case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin); break;
//			default : Local_u8ErrorState = 1 ;
//
//			}
//
//		}
//		else
//		{
//			/*if wrong direction*/
//			Local_u8ErrorState = 1 ;
//		}
//
//	}
//	else
//	{
//		/*if wrong pin number*/
//		Local_u8ErrorState = 1 ;
//	}
//
//	return Local_u8ErrorState ;
//}
///********** this function shall set the direction for the desired port ********************/
//u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
//{
//	u8 Local_u8ErrorState = 0;
//
//	switch (Copy_u8Port)
//	{
//	/*check if the correct port or, else send error */
//	case DIO_u8PORTA : DDRA = Copy_u8Direction; break;
//	case DIO_u8PORTB : DDRB = Copy_u8Direction; break;
//	case DIO_u8PORTC : DDRC = Copy_u8Direction; break;
//	case DIO_u8PORTD : DDRD = Copy_u8Direction; break;
//	default : Local_u8ErrorState = 1 ;
//	}
//
//	return Local_u8ErrorState ;
//}



/************************** SET_BIT & SET_PORT VALUE **************************************/

/********** this function shall set the value for the desired pin *************************/
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0;
	/*check if the correct port or, else send error */
	if (Copy_u8Pin <= DIO_u8PIN7)
	{
		/*check if the value is high or low or, else send error */
		if ( Copy_u8Value == DIO_u8PIN_LOW)
		{
			switch ( Copy_u8Port )
			{
			/*check if the correct port or, else send error */
			case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin); break;
			default : Local_u8ErrorState = 1 ;
			}

		}
		else if ( Copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch ( Copy_u8Port )
			{
			case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin); break;
			default : Local_u8ErrorState = 1 ;

			}

		}
		else
		{
			/*if wrong value (not high or low)*/
			Local_u8ErrorState = 1 ;
		}

	}
	else
	{
		/*if wrong pin number*/
		Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}
/********** this function shall set the value for the desired port *************************/
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0;

	switch (Copy_u8Port)
	{
	/*check if the correct port or, else send error */
	case DIO_u8PORTA : PORTA = Copy_u8Value; break;
	case DIO_u8PORTB : PORTB = Copy_u8Value; break;
	case DIO_u8PORTC : PORTC = Copy_u8Value; break;
	case DIO_u8PORTD : PORTD = Copy_u8Value; break;
	default : Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}



/************************** GET_BIT & GET_PORT VALUE **************************************/

/********** this function shall get the value for the desired pin *************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState = 0;
	if ((Copy_pu8Value != NULL) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch (Copy_u8Port)
		{
		/*check if the correct port or, else send error */
		case DIO_u8PORTA : *Copy_pu8Value = GET_BIT(PINA , Copy_u8Pin); break;
		case DIO_u8PORTB : *Copy_pu8Value = GET_BIT(PINB , Copy_u8Pin); break;
		case DIO_u8PORTC : *Copy_pu8Value = GET_BIT(PINC , Copy_u8Pin); break;
		case DIO_u8PORTD : *Copy_pu8Value = GET_BIT(PIND , Copy_u8Pin); break;
		default : Local_u8ErrorState = 1  ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}


/************************** TOGGLE_BIT & TOGGLE_PORT VALUE **************************************/

/********** this function shall toggle the value for the desired pin **********************/
u8 DIO_u8TogglePinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState = 0;
	/*check if the correct port or, else send error */
	if (Copy_u8Pin <= DIO_u8PIN7)
	{
		switch ( Copy_u8Port )
		{
		/*check if the correct port or, else send error */
		case DIO_u8PORTA : TOG_BIT(PORTA,Copy_u8Pin); break;
		case DIO_u8PORTB : TOG_BIT(PORTB,Copy_u8Pin); break;
		case DIO_u8PORTC : TOG_BIT(PORTC,Copy_u8Pin); break;
		case DIO_u8PORTD : TOG_BIT(PORTD,Copy_u8Pin); break;
		default : Local_u8ErrorState = 1 ;
		}

	}
	else
	{
		/*if wrong pin number*/
		Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}

/********** this function shall toggle the value for the desired port **********************/
u8 DIO_u8TogglePortValue(u8 Copy_u8Port)
{
	u8 Local_u8ErrorState = 0;

	switch (Copy_u8Port)
	{
	/*check if the correct port or, else send error */
	case DIO_u8PORTA : PORTA = ~PORTA;  break;
	case DIO_u8PORTB : PORTB = ~PORTB;  break;
	case DIO_u8PORTC : PORTC = ~PORTC;  break;
	case DIO_u8PORTD : PORTD = ~PORTD;  break;
	default : Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}


/********** this function shall control the pull up for the desired pin *******************/
u8 DIO_u8InitPinPullUp(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState = 0;

	if (Copy_u8Pin <= DIO_u8PIN7)
	{
		switch (Copy_u8Port)
		{
		/*check if the correct port or, else send error */
		case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin); break;
		case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin); break;
		case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin); break;
		case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin); break;
		default : Local_u8ErrorState = 1  ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}
