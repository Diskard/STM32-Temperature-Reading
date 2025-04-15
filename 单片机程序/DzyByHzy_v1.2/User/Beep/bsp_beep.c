#include "headers.h"

short melody_s[8] = {247, 262, 294, 330, 349, 392, 440, 494};
short melody_h[8] = {1000, 1046, 1175, 1318, 1397, 1568, 1760, 1976};
short melody_m[8] = {500, 523, 587, 659, 698, 784, 880, 988};
short Beep_Mode = ON;

short MusicA[18] = {659, 659, 659, 523, 784, 659, 523, 784, 659, 988,
					988, 988, 1046, 784, 587, 523, 784, 587};

short *Music = melody_h;
					
void Beep_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�������ӷ�������GPIO������ʱ��*/
	BEEP_GPIO_APBxClock_FUN(BEEP_GPIO_CLK, ENABLE);
	/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStructure.GPIO_Pin = BEEP_PIN;
	/*��������ģʽΪͨ���������*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	/*������������Ϊ50MHz */   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	/*���ÿ⺯������ʼ��GPIO*/
	GPIO_Init(BEEP_PORT, & GPIO_InitStructure);

	/* Ĭ�Ϲرշ�����*/
	BEEP_OFF ();	
}

void Beep_Init(void)
{		
	Beep_GPIO_Config ();
	
	/* Ĭ�Ϲرշ�����*/
	BEEP_OFF ();
	
}

void Play_Tone(short frq)
{
	u16 t = 500000 / frq;
	BEEP_ON();
	delay_us(t*1/10);
	BEEP_OFF();
	delay_us(t*9/10);
}
void Music_Play(short MusicX[])
{
	u16 index = 1, j;
	for(index = 1; index <= 7; index++)
	{
		for(j = 1; j <= MusicX[index]; j++)
		{
			if(Beep_Mode == ON) Play_Tone(MusicX[index]);
		}
		
	}
}
void Beep_Ctrl(short Mode)
{
	Beep_Mode = Mode;
}
/*********************************************END OF FILE**********************/
