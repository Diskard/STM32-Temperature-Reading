#ifndef __BSP_ASSIST_H
#define __BSP_ASSIST_H

#include "stm32f10x.h"

extern short SWJ_LED_Switch, SWJ_LED_Mode, SWJ_Beep_Switch, SWJ_Beep_Mode;

void Delay(__IO u32 nCount);
void DelaySet(u16 cnt);
void PD6_GPIO_Config(void);
void decode(u16 len);
void All_Mode_Ctrl(void);
#endif
