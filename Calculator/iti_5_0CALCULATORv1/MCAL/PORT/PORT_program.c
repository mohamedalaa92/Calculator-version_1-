/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: MCAL                     ***********************/
/*****************    SWC: PORT_program.c             ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"PORT_register.h"
#include"PORT_config.h"  //must before private.h, because the private use that 
#include"PORT_private.h" 
#include"PORT_interface.h"


void PORT_voidInit (void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	

/************************************ INTI VALUE***********************************************/
	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;
}
