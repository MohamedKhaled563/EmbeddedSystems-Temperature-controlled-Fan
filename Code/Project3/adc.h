/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                            User Defined Types                               *
 *******************************************************************************/
/* Reference voltage for adc, if external reference voltage is used, the value of */
typedef enum
{
	AREF, AVCC, INTERNAL_2_56 = 3
} ADC_ReferenceVolatge;
/* Prescaler for the ADC module */
typedef enum {
	F_CUP_2 = 1, F_CUP_4, F_CUP_8, F_CUP_16, F_CUP_32, F_CUP_64, F_CPU_128
} ADC_Prescaler;
/* Dynamic configurations for adc */
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} 	ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
