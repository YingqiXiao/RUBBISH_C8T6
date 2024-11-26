#include "bsp_servo.h"
#include "tim.h"

void Servo180_Angle(uint8_t PWM)
 {
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2); 
   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,PWM);
 }

void Servo270_Angle(uint8_t PWM)
 {
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,PWM);
 }

 void Servo_Stop()
 {
	HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_2);
   
 }
 