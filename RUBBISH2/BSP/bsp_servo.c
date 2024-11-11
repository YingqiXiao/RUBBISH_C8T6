#include "bsp_servo.h"
#include "tim.h"

void Servo180_Angle(uint8_t PWM)
 {
   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,PWM);
 }

void Servo270_Angle(uint16_t PWM)
 {
   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,PWM);
 }

 