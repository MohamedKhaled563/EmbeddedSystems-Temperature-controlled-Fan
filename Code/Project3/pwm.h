/***********************************************************************
 *
 *  Module: PWM
 *
 *  File Name: pwm.h
 *
 *  Description: Header file for PWM module.
 *
 *  Author: Mohamed Khaled
 *
***********************************************************************/
#ifndef PWM_H_
#define PWM_H_


/***********************************************************************
*                       Include common modules                         *
***********************************************************************/
#include "std_types.h"

/***********************************************************************
*                      Public Functions Prototypes                     *
***********************************************************************/
/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
