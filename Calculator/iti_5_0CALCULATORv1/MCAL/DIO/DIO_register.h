/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: MCAL                     ***********************/
/*****************    SWC: DIO_register.h             ***********************/
/*****************    VER: 2.00                       ***********************/
/****************************************************************************/
/****************************************************************************/
 
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/********************************** Register Definitions *********************************/


/************************** Group A **************************/
#define PORTA    *((volatile u8*)0x3b)
#define PINA     *((volatile u8*)0x39)
//I use DDR in PORT driver instead of here, as AUTOSAR
 
/************************** Group B **************************/ 
#define PORTB    *((volatile u8*)0x38)
#define PINB     *((volatile u8*)0x36)
//I use DDR in PORT driver instead of here, as AUTOSAR


/************************** Group C **************************/  
#define PORTC    *((volatile u8*)0x35)
#define PINC     *((volatile u8*)0x33)
//I use DDR in PORT driver instead of here, as AUTOSAR


/************************** Group D **************************/
#define PORTD    *((volatile u8*)0x32)
#define PIND     *((volatile u8*)0x30)
//I use DDR in PORT driver instead of here, as AUTOSAR



#endif /* DIO_REGISTER_H_ */
