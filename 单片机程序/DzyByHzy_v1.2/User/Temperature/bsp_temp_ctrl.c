#include "headers.h"

float Now_Temperature = 1.0;

short Alm_Sys_Mode = ON;

float Get_Temperature()//将均值电压转化为温度
{
	u32 adcx;
 	float temperature;
	adcx=Get_Adc_Average(ADC_Channel_16,20);	//读取通道16,20次取平均
	temperature=(float)adcx*(3.3/4096);		//电压值 
	temperature=(1.43-temperature)/0.0043+25;	//转换为温度值 	 
	return temperature;
}

void Send_Temperature(float nowt)//获取并发送温度数据
{
	usb_printf("TEM%.2f %d %d", nowt, WinkLED_Mode, BreathLED_Mode);
	//DelaySet(10);
}

short Temp_Is_high()
{
    return (Now_Temperature >= Std_Temperature) ? 1 : 0;
}


void Alarm_LED(void)
{
	if(Temp_Is_high())
	{
		BreathLED_Ctrl(OFF);
		WinkLED_Ctrl(ON);
	}
	else
	{
		BreathLED_Ctrl(ON);
		WinkLED_Ctrl(OFF);
	}
}

void Alarm_Beep(void)
{
	if(Temp_Is_high())
	{
		Beep_Ctrl(ON);
	}
	else
	{
		Beep_Ctrl(OFF);
	}

}
