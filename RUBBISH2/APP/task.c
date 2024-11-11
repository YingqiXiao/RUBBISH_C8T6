#include "task.h"
#include "tim.h"
#include "usart.h"
#include "bsp_uart.h"
#include "bsp_motor.h"
#include "bsp_servo.h"

uint32_t time = 0;
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
	Servo180_Angle(100);
	Pull_Motor();
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
			Servo180_Angle(150);
			flag_1 = 2;
		}

		/*�ɻ�����������ѹ���������������Ƹ�*/
		if(time == 4000 && flag_category == 1)
		{
			Push_Motor();
			
		}

		/*�ɻ�����������ѹ�������Ĳ��ջ��Ƹ�*/
		if(time == 9000 && flag_category == 1)
		{
			Pull_Motor();
			
		}

		/*�ɻ�����������ѹ�������岽����������*/
		if(time == 14000 && flag_category == 1)
		{
			Servo180_Angle(150);
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
			Stepper1(1);
			Stepper2(1);
			
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
			if(time == 8000)
			{
			tx_buffer[0] = 0x08;
			tx_buffer[1] = 0x02;
			tx_buffer[2] = 0x09;
			DMA_Usart_Send(tx_buffer, tx_len);
			rubbish_init();				
			}
		}
		
		if(flag_1 == 3)
		{
			time++;
			if(time == 18000)
			{
			tx_buffer[0] = 0x08;
			tx_buffer[1] = 0x02;
			tx_buffer[2] = 0x09;
			DMA_Usart_Send(tx_buffer, tx_len);
			rubbish_init();

			}
		}		
		
	}
}


