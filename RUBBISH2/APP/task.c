#include "task.h"
#include "tim.h"
#include "usart.h"
#include "bsp_uart.h"
#include "bsp_motor.h"
#include "bsp_servo.h"
#include "bsp_key.h"

uint32_t time = 0;
uint16_t timeg = 0;
/*�׶���������ɱ�־*/
uint8_t flag_1 = 0;
uint8_t flag_category = 0;
uint32_t Pulse_Cnt = 0;

void rubbish_init()
{
	time = 0;
	/*�׶���������ɱ�־*/
	flag_1 = 0;
	flag_category = 0;
	/*���ʹ�����*/
	Stepper1(1);
	Stepper2(1);
	Servo270_Angle(50);
	Servo180_Angle(135);
	Pull_Motor();
	Uart_Flag.flag = 0;
	tx_buffer[0] = 0x08;
	tx_buffer[1] = 0x06;
	tx_buffer[2] = 0x09;
	DMA_Usart_Send(tx_buffer, tx_len);	
}

void rubbish_reset()
{
	time = 0;
	/*�׶���������ɱ�־*/
	flag_1 = 0;
	flag_category = 0;
	/*���ʹ�����*/
	Stepper1(1);
	Stepper2(1);
	Servo270_Angle(50);
	Servo180_Angle(135);
	Pull_Motor();
	Uart_Flag.flag = 0;
}

void rubbish_reset2()
{
	Servo180_Angle(135);
	Uart_Flag.flag = 0;
	
}

void rubbish_solve()
{

	if(time == 50)
	{
		/*���ʹ�ֹͣ*/
		Stepper1(0);
		Stepper2(0);
	}
	if(time == 2000)
	{
	/*�ж��������࣬������Ͱ��ת����ȷλ��*/
		switch(Uart_Flag.flag)
		{
			case 1:
				Servo270_Angle(50);
			break;
			case 2://�ɻ�������
				Servo270_Angle(117);
				flag_category = 1;
			break;
			case 3:
				Servo270_Angle(184);
			break;
			case 4:
				Servo270_Angle(250);
			break;				
		}
	tx_buffer[0] = 0x08;
	tx_buffer[1] = 0x01;
	tx_buffer[2] = 0x09;
	DMA_Usart_Send(tx_buffer, tx_len);
		
	}
	

		/*������������ֱ������*/		
		if(time == 4000 && flag_category != 1)
		{
			Servo180_Angle(60);
			flag_1 = 2;
		}

		/*�ɻ�����������ѹ���������������Ƹ�*/
		if(time == 4000 && flag_category == 1)
		{
			Push_Motor();
			
		}

		/*�ɻ�����������ѹ�������Ĳ��ջ��Ƹ�*/
		if(time == 8000 && flag_category == 1)
		{
			Pull_Motor();
			
		}

		/*�ɻ�����������ѹ�������岽����������*/
		if(time == 12000 && flag_category == 1)
		{
			Servo180_Angle(60);
			flag_1 = 3;
		}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	
    if (htim == (&htim2))
    {
		/*δ��⵽����*/
		if(Uart_Flag.flag == 0 && flag_1 == 0)
		{
			timeg++;
			Stepper1(1);
			if(timeg == 500)
			{
				Stepper2(1);
			}
			
			if(timeg == 2800)
			{
				Stepper2(0);
				timeg = 0;
			}
			
			
		}
		/*��⵽����*/
		if(Uart_Flag.flag != 0 && flag_1 == 0)
		{			
			flag_1 = 1;

		}
		/*����������һ*/
		if(flag_1 == 1)
		{
			time++;
			/*��ʱ*/
			rubbish_solve();		
		}
		
		if(flag_1 == 2)
		{
			time++;
			if(time == 7000)
			{
			rubbish_reset2();
				
			}
			
			if(time == 8000)
			{
			tx_buffer[0] = 0x08;
			tx_buffer[1] = 0x03;
			tx_buffer[2] = 0x09;
			DMA_Usart_Send(tx_buffer, tx_len);	
				
			}			
			
			if(time == 11000 && Uart_Flag.flag != 0)
			{
				Servo180_Angle(60);
				time = 4000;
				
			}
			
			if(time == 11000 && Uart_Flag.flag == 0)
			{
			tx_buffer[0] = 0x08;
			tx_buffer[1] = 0x02;
			tx_buffer[2] = 0x09;
			DMA_Usart_Send(tx_buffer, tx_len);
			rubbish_reset();	
				
			}			
						
		}
		
		if(flag_1 == 3)
		{
			time++;
			if(time == 15000)
			{
			rubbish_reset2();
				
			}
			
			if(time == 16000)
			{
			tx_buffer[0] = 0x08;
			tx_buffer[1] = 0x03;
			tx_buffer[2] = 0x09;
			DMA_Usart_Send(tx_buffer, tx_len);	
				
			}			

			if(time == 19000 && Uart_Flag.flag != 0)
			{
				Servo180_Angle(60);
				time = 12000;
				
			}
			
			if(time == 19000 && Uart_Flag.flag == 0)
			{
			tx_buffer[0] = 0x08;
			tx_buffer[1] = 0x02;
			tx_buffer[2] = 0x09;
			DMA_Usart_Send(tx_buffer, tx_len);
			rubbish_reset();
			
			}
			
			
		}		
//		Servo_Stop();
	}
}


