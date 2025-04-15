/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.6.0
  * @date    20-September-2021
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2011 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "headers.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval
*/
/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/
extern uint16_t indexWave[];

/* 呼吸灯中断服务函数 */
void BRE_TIMx_IRQHandler(void)
{	
	static uint16_t pwm_index = 0;			//用于PWM查表
	static uint16_t period_cnt = 0;		//用于计算周期数
	
  if (TIM_GetITStatus(BRE_TIMx, TIM_IT_Update) != RESET)	//TIM_IT_Update
  {
	  period_cnt++;
		
	  if(BreathLED_Mode == ON) BRE_TIMx->BRE_CCRx = indexWave[pwm_index];	//根据PWM表修改定时器的比较寄存器值
	  else  BRE_TIMx->BRE_CCRx = 0;

	  //每个PWM表中的每个元素使用period_class次
	  if(period_cnt > period_class)				 				
	  {				
			pwm_index++;												//标志PWM表指向下一个元素

			//若PWM表已到达结尾，重新指向表头
			if( pwm_index >=  POINT_NUM)			
			{
			  pwm_index=0;								
			}
		  
			period_cnt=0;											//重置周期计数标志
	  }	
	  else
	  {
	  }	
	TIM_ClearITPendingBit (BRE_TIMx, TIM_IT_Update);	//必须要清除中断标志位
    }
}

void  TIM6_IRQHandler (void)
{
	u16 len;
	if ( TIM_GetITStatus( TIM6, TIM_IT_Update) != RESET ) 
	{	
		tim6_cnt++;
		if(USB_USART_RX_STA&0x8000)
		{	   
			len=USB_USART_RX_STA&0x3FFF;//得到此次接收到的数据长度
			decode(len);
			USB_USART_RX_STA=0;
		}
		All_Mode_Ctrl();//总控，分析处理上位机信号和stm信号
		//LED闪烁
		if(WinkLED_Mode == ON)
		{
			if(tim6_cnt % Wink_Period == 0)
			{
				T_BLUE;  //翻转LED蓝灯
				T_RED;
			} 	
		}

		if(tim6_cnt % Temp_Period == 0)
		{
			Now_Temperature = Get_Temperature();
			Send_Temperature(Now_Temperature);
			//Mode_Send();
		}
		if(tim6_cnt % 500 == 0)
		{
			tim6_cnt = 0;
		}
		TIM_ClearITPendingBit(TIM6 , TIM_FLAG_Update); 
	}		 	
}

void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		Alm_Sys_Mode = 0;
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line13) != RESET)
	{
		Alm_Sys_Mode = 1;
		SWJ_LED_Switch = 1;
		SWJ_LED_Mode = 0;
		SWJ_Beep_Switch = 1;
		SWJ_Beep_Mode = 0;
	}
	EXTI_ClearITPendingBit(EXTI_Line13);
}
