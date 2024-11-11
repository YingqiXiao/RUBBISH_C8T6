#ifndef _BSP_MOTOR_H
#define _BSP_MOTOR_H

#include "main.h"

extern uint32_t Pulse_exp_Cnt;

void Push_Motor(void);
void Pull_Motor(void);
void Stepper1(uint8_t start_flag);
void Stepper2(uint8_t start_flag);

#endif
