#include "headers.h"


int main(void)
{  
	/*
	1.采集芯片温度
	
	2.usb虚拟串口将数据发送
	
	3.设定锚定温度T0
	
		①温度超过T0：LED快速闪烁（救护车那样？）， 蜂鸣器播放音乐报警 上位机报警
	
		②温度小于T0：LED呼吸灯闪烁
	
		③按下按键：同②
	
	4.上位机
	*/  

	//--------------------LED、蜂鸣器初始化--------------//
	delay_init();
	Key_Init();
	Adc_Init();
	TIM6_WinkLED_Init();//闪烁灯初始化
	TIM3_Breathing_Init();//呼吸灯初始化
	Beep_Init();//蜂鸣器初始化
	WinkLED_Ctrl(ON);//关闭闪烁灯
	BreathLED_Ctrl(OFF);//关闭呼吸灯

	//-------------------USB初始化----------------------//
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	PD6_GPIO_Config();//拉低PD6使能usb
	delay_ms(1800);
	USB_Port_Set(0); 	//USB先断开
	delay_ms(700);
	USB_Port_Set(1);	//USB再次连接
 	Set_USBClock();   
 	USB_Interrupts_Config();    
 	USB_Init();


	while (1){
		Music_Play(Music);
   }
}
