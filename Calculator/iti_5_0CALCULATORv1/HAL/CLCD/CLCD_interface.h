/*
 * CLCD_interface.h
 *
 *  Created on: Jan 16, 2022
 *      Author: 20111
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidinit(void);

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos);

void CLCD_voidWriteSpecialChar(u8* Copy_pu8Pattern ,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidWriteNumber(u32 Copy_u8Number);


#endif /* CLCD_INTERFACE_H_ */
