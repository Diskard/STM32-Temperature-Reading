#include "headers.h"

//�����һЩ��֪��������ĺ���
short SWJ_LED_Switch = 1, SWJ_LED_Mode = 0, SWJ_Beep_Switch = 1, SWJ_Beep_Mode = 0;

void Delay(__IO u32 nCount)
{
	for(; nCount != 0; nCount--);
}
void DelaySet(u16 cnt)
{
	for(;cnt>=1; cnt--)
	{
		Delay(0xFFFFF);
	}
}
void PD6_GPIO_Config(void)
{	
	//����һ��GPIO_InitTypeDef ���͵Ľṹ��
	GPIO_InitTypeDef  GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);//����GPIOC������ʱ��
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;//ѡ��Ҫ�õ�GPIO����	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOD, &GPIO_InitStruct); //���ÿ⺯������ʼ��GPIO   
	  	
	GPIO_ResetBits(GPIOD, GPIO_Pin_6);
}

void decode(u16 len)
{
	/*
	LED:
		LED0: LED�ر�
		LED1: LED��
		LED2: LED����
		LED3: LED��˸
	BEP:
		BEP0: BEP�ر�
		BEP1��BEP��
		BEP2; ����A
		BEP3: ����B
	*/
	if(len == 4)
	{
		if(USB_USART_RX_BUF[0] == 'L' && USB_USART_RX_BUF[1] == 'E' && USB_USART_RX_BUF[2] == 'D')
		{
			if(USB_USART_RX_BUF[3] == '0') 
			{
				//LED_Ctrl(OFF);
				SWJ_LED_Switch = 0;
			}
			
			if(USB_USART_RX_BUF[3] == '1') 
			{
				//LED_Ctrl(ON);
				SWJ_LED_Switch = 1;
				SWJ_LED_Mode = 0;
			}
			if(USB_USART_RX_BUF[3] == '2') 
			{
				// BreathLED_Ctrl(ON);
				// WinkLED_Ctrl(OFF);
				SWJ_LED_Mode = 1;
			}
			if(USB_USART_RX_BUF[3] == '3') 
			{
				// BreathLED_Ctrl(OFF);
				// WinkLED_Ctrl(ON);
				SWJ_LED_Mode = 2;
			}	
		}
		if(USB_USART_RX_BUF[0] == 'B' && USB_USART_RX_BUF[1] == 'E' && USB_USART_RX_BUF[2] == 'P')
		{
			if(USB_USART_RX_BUF[3] == '0') 
			{
				//Beep_Ctrl(OFF);
				SWJ_Beep_Switch = 0;
			}
			if(USB_USART_RX_BUF[3] == '1') 
			{
				//Beep_Ctrl(ON);
				SWJ_Beep_Switch = 1;
				SWJ_Beep_Mode = 0;
			}
			if(USB_USART_RX_BUF[3] == '2') 
			{
				//����A
				SWJ_Beep_Mode = 1;
			}
			if(USB_USART_RX_BUF[3] == '3') 
			{
				//����B
				SWJ_Beep_Mode = 2;
			}
		}
		if(USB_USART_RX_BUF[0] == 'A' && USB_USART_RX_BUF[1] == 'L' && USB_USART_RX_BUF[2] == 'M')
		{
			if(USB_USART_RX_BUF[3] == '0') Alm_Sys_Mode = OFF;
			if(USB_USART_RX_BUF[3] == '1') 
			{
				Alm_Sys_Mode = ON;
				//SWJ_LED_Switch = 1;
				SWJ_LED_Mode = 0;
				//SWJ_Beep_Switch = 1;
				SWJ_Beep_Mode = 0;
				
			}
		}
	}
}

void All_Mode_Ctrl(void)
{
	if(SWJ_LED_Switch == 0)
	{
		BreathLED_Ctrl(OFF);
		WinkLED_Ctrl(OFF);
	}
	else
	{
		if(SWJ_LED_Mode == 0)
		{
			if(Alm_Sys_Mode == ON)
			{
				Alarm_LED();
			}
			else
			{
				BreathLED_Ctrl(OFF);
				WinkLED_Ctrl(OFF);
			}
		}
		if(SWJ_LED_Mode == 1)
		{
			BreathLED_Ctrl(ON);
			WinkLED_Ctrl(OFF);
		}
		if(SWJ_LED_Mode == 2)
		{
			BreathLED_Ctrl(OFF);
			WinkLED_Ctrl(ON);
		}
	}

	if(SWJ_Beep_Switch == 0)
	{
		Beep_Ctrl(OFF);
	}
	else
	{
		if(SWJ_Beep_Mode == 0)
		{
			if(Alm_Sys_Mode == ON)
			{
				Alarm_Beep();
				Music = melody_h;
			}
			else
			{
				Beep_Ctrl(OFF);
			}
		}
		if(SWJ_Beep_Mode == 1)
		{
			Beep_Ctrl(ON);
			Music = melody_h;
		}
		if(SWJ_Beep_Mode == 2)
		{
			Beep_Ctrl(ON);
			Music = MusicA;
			
		}
	}
}
