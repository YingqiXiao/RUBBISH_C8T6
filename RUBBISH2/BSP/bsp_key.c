#include "bsp_key.h"
#include "usart.h"
#include "bsp_uart.h"

uint16_t Key = 0;

void Key_Scan()
{
	Key = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);
	if(Key == 0)
	{
		tx_buffer[0] = 0x08;
		tx_buffer[1] = 0x08;
		tx_buffer[2] = 0x09;
		DMA_Usart_Send(tx_buffer, tx_len);
		HAL_GPIO_TogglePin(BUTTON_GPIO_Port, BUTTON_Pin);
	}
	
}
