#ifndef __BSP_BASIC_TIMER_H
#define __BSP_BASIC_TIMER_H

#include "stm32f10x.h"

#define Wink_Period 500
#define Temp_Period 500


extern uint16_t tim6_cnt;

void BASIC_TIM_Init(uint16_t arr,uint16_t psc);//基本定时器初始化

#endif
