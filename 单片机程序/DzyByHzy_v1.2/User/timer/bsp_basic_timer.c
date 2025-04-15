#include "bsp_basic_timer.h"

uint16_t tim6_cnt = 0;

//基本定时器初始化
void BASIC_TIM_Init(uint16_t arr,uint16_t psc)
{
	  //中断优先级配置
		NVIC_InitTypeDef NVIC_InitStructure; 
		/* 嵌套向量中断控制器组选择 */
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
		/* 配置中断源 */
		NVIC_InitStructure.NVIC_IRQChannel                   = TIM6_IRQn;
		/* 抢断优先级*/
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
		/* 子优先级 */
		NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
		/* 使能中断 */
		NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
		/* 初始化配置NVIC */
		NVIC_Init(&NVIC_InitStructure);
	
	
	  //配置定时器
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	
		// 开启定时器时钟,即内部时钟CK_INT=72M
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);	
		// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
    TIM_TimeBaseStructure.TIM_Period              = arr;	
	  // 时钟预分频数为
    TIM_TimeBaseStructure.TIM_Prescaler           = psc;
		// 时钟分频因子 ，基本定时器没有，不用管
    //TIM_TimeBaseStructure.TIM_ClockDivision     = TIM_CKD_DIV1;	
		// 计数器计数模式，基本定时器只能向上计数，没有计数模式的设置
    //TIM_TimeBaseStructure.TIM_CounterMode       = TIM_CounterMode_Up; 		
		// 重复计数器的值，基本定时器没有，不用管
		//TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	  // 初始化定时器
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);	
		// 清除计数器中断标志位
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);  
		// 开启计数器中断
    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);	
		// 使能计数器
    TIM_Cmd(TIM6, ENABLE);	
}
