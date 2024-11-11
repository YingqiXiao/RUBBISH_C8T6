#include "bsp_motor.h"
#include "tim.h"

uint8_t pwm = 100;
uint32_t Pulse_exp_Cnt=0;

void Push_Motor()
{
	HAL_GPIO_WritePin(PUSH1_GPIO_Port, PUSH1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PUSH2_GPIO_Port, PUSH2_Pin, GPIO_PIN_RESET);
}

void Pull_Motor()
{
	HAL_GPIO_WritePin(PUSH1_GPIO_Port, PUSH1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PUSH2_GPIO_Port, PUSH2_Pin, GPIO_PIN_SET);
}

 void Stepper1(uint8_t start_flag)
 {
	if(start_flag == 1)
	{
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
		HAL_GPIO_WritePin(ENA1_GPIO_Port, ENA1_Pin, GPIO_PIN_RESET);//ENA
		HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);//DIR
		
	}
	if(start_flag != 1)
	{
		HAL_GPIO_WritePin(ENA1_GPIO_Port, ENA1_Pin, GPIO_PIN_SET);//ENA
		HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_2);
	}	
 }
 
  void Stepper2(uint8_t start_flag)
 {
	if(start_flag == 1)
	{
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
		HAL_GPIO_WritePin(ENA2_GPIO_Port, ENA2_Pin, GPIO_PIN_RESET);//ENA
		HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET);//DIR
	}
	if(start_flag != 1)
	{
		HAL_GPIO_WritePin(ENA2_GPIO_Port, ENA2_Pin, GPIO_PIN_SET);//ENA
		HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_2);
	}	
 }

//void Stepper_Spines(uint32_t pwm_num)
//{
//		//使能
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);		
//		/*开启定时器更新中断*/
//		HAL_TIM_Base_Start_IT(&htim4);
//		/*开始输出PWM*/
//		HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
//		Pulse_exp_Cnt=pwm_num;
//}
