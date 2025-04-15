#ifndef __BSP_TEMP_H
#define __BSP_TEMP_H

#include "stm32f10x.h"

#define Std_Temperature 37.0 // 阈值温度，超过报警

extern float Now_Temperature;
extern short Alm_Sys_Mode;
extern short Alm_LED_Mode, Alm_Beep_Mode;

short Temp_Is_high(void);
void Send_Temperature(float nowt);
float Get_Temperature(void);
void Alarm_LED(void);
void Alarm_Beep(void);

#endif
