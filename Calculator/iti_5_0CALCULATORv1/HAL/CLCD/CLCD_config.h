/*
 * CLCD_config.h
 *
 *  Created on: Jan 16, 2022
 *      Author: 20111
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*
CHOOSE :  CLCD_DATA & CONTROL _PORT:
					  DIO_u8PORTA
                      DIO_u8PORTB
                      DIO_u8PORTC
                      DIO_u8PORTD               */

#define CLCD_DATA_PORT DIO_u8PORTA

#define CLCD_CTRL_PORT DIO_u8PORTB

/*
CHOOSE :  CLCD_CONTROL_PINS:
					   DIO_u8PIN0
                       DIO_u8PIN1
                       DIO_u8PIN2
                       DIO_u8PIN3
                       DIO_u8PIN4
                       DIO_u8PIN5
                       DIO_u8PIN6
                       DIO_u8PIN7          */

#define CLCD_RS_PIN    DIO_u8PIN0
#define CLCD_RW_PIN    DIO_u8PIN1
#define CLCD_E_PIN     DIO_u8PIN2

#endif /* CLCD_CONFIG_H_ */
