/****************************************************************************/
/****************************************************************************/
/*****************    Author: Mohamed Alaa Eldehimy   ***********************/
/*****************    Layer: HAL                      ***********************/
/*****************    SWC: KBD_program.c              ***********************/
/*****************    VER: 1.00                       ***********************/
/****************************************************************************/
/****************************************************************************/

#include"../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include"KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8ColumnIndex,Local_u8RowIndex,Local_u8PinState;
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;

	static u8 Localu8KPDArr[KPD_COLUMN_NUM][KPD_ROW_NUM] = KPD_ARR_VAL;

	static u8 Local_u8KPDColumnArr[KPD_COLUMN_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	static u8 Local_u8KPDROWArr[KPD_ROW_NUM]       = {KPD_ROW0_PIN,    KPD_ROW1_PIN,    KPD_ROW2_PIN,    KPD_ROW3_PIN};

	for(Local_u8ColumnIndex = 0 ; Local_u8ColumnIndex < KPD_COLUMN_NUM ;Local_u8ColumnIndex++)
	{
		/*activate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);
		for(Local_u8RowIndex = 0; Local_u8RowIndex < KPD_ROW_NUM; Local_u8RowIndex++ )
		{
			/*read the current ROW*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDROWArr[Local_u8RowIndex],&Local_u8PinState);
			/*check if switch is pressed*/
			if(DIO_u8PIN_LOW ==Local_u8PinState)
			{
				Local_u8PressedKey = Localu8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];

				/*polling (busy waiting until the key is released)*/
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDROWArr[Local_u8RowIndex],&Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		/*deactivate the current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}

