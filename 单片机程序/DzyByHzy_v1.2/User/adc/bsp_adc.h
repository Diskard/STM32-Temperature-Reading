#ifndef __BSP_ADC_H
#define __BSP_ADC_H

#include "stm32f10x.h"

extern __IO uint16_t ADC_ConvertedValue;

static void ADC1_GPIO_Config(void);
static void ADC1_Mode_Config(void);
//static void ADC_NVIC_Config(void);

u16 Get_ADC(u8 ch);
u16 Get_Adc_Average(u8 ch,u8 times);
float Get_Temperature(void);
void Adc_Init(void);
void Send_Temperature(float nowt);

#endif

