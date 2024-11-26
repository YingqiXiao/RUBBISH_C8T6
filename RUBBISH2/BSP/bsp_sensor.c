#include "bsp_sensor.h"
#include "usart.h"
#include "bsp_uart.h"

void Sensor_Scan()
{
	uint8_t Sensor1 = 0;
	uint8_t Sensor2 = 0;
	uint8_t Sensor3 = 0;
	uint8_t Sensor4 = 0;
	
	Sensor1 = HAL_GPIO_ReadPin(SENSOR1_GPIO_Port, SENSOR1_Pin);
	Sensor2 = HAL_GPIO_ReadPin(SENSOR2_GPIO_Port, SENSOR2_Pin);
	Sensor3 = HAL_GPIO_ReadPin(SENSOR3_GPIO_Port, SENSOR3_Pin);
	Sensor4 = HAL_GPIO_ReadPin(SENSOR4_GPIO_Port, SENSOR4_Pin);
	
	if(Sensor1 == 1 || Sensor2 == 1 || Sensor3 == 1 || Sensor4 == 1)
	{
		tx_buffer[0] = 0x08;
		tx_buffer[1] = 0x07;
		tx_buffer[2] = 0x09;
		DMA_Usart_Send(tx_buffer, tx_len);		
	}
//	else
//	{
//		tx_buffer[0] = 0x00;
//		tx_buffer[1] = 0x00;
//		tx_buffer[2] = 0x00;
//		DMA_Usart_Send(tx_buffer, tx_len);	
//	}
}




