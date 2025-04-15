#include "headers.h"

u16 WinkLED_Mode = OFF;
u16 LED_Mode = 1;

void Led_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStruct.GPIO_Pin     = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GreenSet(0);
	BlueSet(0);
	RedSet(0);
}

void TIM6_WinkLED_Init()
{
	Led_Init();
	
	BASIC_TIM_Init(1000 - 1, 36 - 1);
}

void WinkLED_Ctrl(u16 Mode){
	
	if(WinkLED_Mode == Mode) return;
		
	if(Mode == OFF)
	{
		BlueSet(0);
		RedSet(0);
		WinkLED_Mode = OFF;
	}
	
	if(Mode == ON)
	{	
		BlueSet(1);
		RedSet(0);
		WinkLED_Mode = ON;
	}
}


void Mode_Send()
{
	usb_printf("PRT");
	usb_printf("Wink:%d, Breath:%d, LED:%d, ", WinkLED_Mode, BreathLED_Mode, LED_Mode);
	usb_printf("Beep:%d\n", Beep_Mode);
}

