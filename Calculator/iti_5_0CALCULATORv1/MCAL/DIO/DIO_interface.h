/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: MCAL                     ***********************/
/*****************    SWC: DIO_interface.h            ***********************/
/*****************    VER: 2.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/************************** F_CPU Configurations *******************/
/* user can choose:               ONE_MHZ
								  TWO_MHZ
								  THREE_MHZ
								  FOUR_MHZ
								  FIVE_MHZ
								  SIX_MHZ
								  SEVEN_MHZ
								  EIGHT_MHZ
 */                  
#define  F_CPU_VALUE              EIGHT_MHZ

/************************** Pin Numbers **************************/
#define DIO_u8PIN0                0
#define DIO_u8PIN1                1
#define DIO_u8PIN2                2
#define DIO_u8PIN3                3
#define DIO_u8PIN4                4
#define DIO_u8PIN5                5
#define DIO_u8PIN6                6
#define DIO_u8PIN7                7


        /*I use it in PORT driver instead of here, as AUTOSAR */
///************************** Pin Direction ************************/
//#define DIO_u8PIN_INPUT           0
//#define DIO_u8PIN_OUTPUT          1
//
///************************** Port Direction ************************/
//#define DIO_PORT_INPUT            0
//#define DIO_PORT_OUTPUT           0xff



/************************** Pin Value ****************************/
#define DIO_u8PIN_LOW             0
#define DIO_u8PIN_HIGH            1

/************************** Port Value ****************************/
#define DIO_PORT_LOW              0
#define DIO_PORT_HIGH             0xff

/************************** Group Name ***************************/
#define DIO_u8PORTA               0
#define DIO_u8PORTB               1
#define DIO_u8PORTC               2
#define DIO_u8PORTD               3

#define NULL                      0

/************************** Pull Up State ************************/
#define  DIO_u8DISABLE_PULLUP     0
#define  DIO_u8INSABLE_PULLUP     1

/************************** Function Prototype ********************************************/

/************************** SET_BIT & SET_PORT DIRECTION **********************************/
        /*we use it in PORT driver instead of here, as AUTOSAR */

///********** this function shall set the direction for the desired pin *********************/
//u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);
///********** this function shall set the direction for the desired port ********************/
//u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);



/************************** SET_BIT & SET_PORT VALUE **************************************/

/********** this function shall set the value for the desired pin *************************/
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
/********** this function shall set the value for the desired port ************************/
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);



/************************** GET_BIT & GET_PORT VALUE **************************************/

/********** this function shall get the value for the desired pin *************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value);



/************************** TOGGLE_BIT & TOGGLE_PORT VALUE **************************************/

/********** this function shall toggle the value for the desired pin **********************/
u8 DIO_u8TogglePinValue(u8 Copy_u8Port , u8 Copy_u8Pin);
/********** this function shall toggle the value for the desired port *********************/
u8 DIO_u8TogglePortValue(u8 Copy_u8Port );

/********** this function shall control the pull up for the desired pin *******************/
u8 DIO_u8InitPinPullUp(u8 Copy_u8Port , u8 Copy_u8Pin);


#endif /* DIO_INTERFACE_H_ */
