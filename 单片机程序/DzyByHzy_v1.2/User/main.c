#include "headers.h"


int main(void)
{  
	/*
	1.�ɼ�оƬ�¶�
	
	2.usb���⴮�ڽ����ݷ���
	
	3.�趨ê���¶�T0
	
		���¶ȳ���T0��LED������˸���Ȼ������������� �������������ֱ��� ��λ������
	
		���¶�С��T0��LED��������˸
	
		�۰��°�����ͬ��
	
	4.��λ��
	*/  

	//--------------------LED����������ʼ��--------------//
	delay_init();
	Key_Init();
	Adc_Init();
	TIM6_WinkLED_Init();//��˸�Ƴ�ʼ��
	TIM3_Breathing_Init();//�����Ƴ�ʼ��
	Beep_Init();//��������ʼ��
	WinkLED_Ctrl(ON);//�ر���˸��
	BreathLED_Ctrl(OFF);//�رպ�����

	//-------------------USB��ʼ��----------------------//
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	PD6_GPIO_Config();//����PD6ʹ��usb
	delay_ms(1800);
	USB_Port_Set(0); 	//USB�ȶϿ�
	delay_ms(700);
	USB_Port_Set(1);	//USB�ٴ�����
 	Set_USBClock();   
 	USB_Interrupts_Config();    
 	USB_Init();


	while (1){
		Music_Play(Music);
   }
}
