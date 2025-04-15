#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"


#define ON 1
#define OFF 0

#define GREEN GPIO_Pin_0 
#define BLUE GPIO_Pin_1
#define RED GPIO_Pin_5

#define RedSet(n) (n ? GPIO_ResetBits(GPIOB, GPIO_Pin_5) : GPIO_SetBits(GPIOB, GPIO_Pin_5))

#define GreenSet(n) (n ? GPIO_ResetBits(GPIOB, GPIO_Pin_0) : GPIO_SetBits(GPIOB, GPIO_Pin_0))

#define BlueSet(n) (n ? GPIO_ResetBits(GPIOB, GPIO_Pin_1) : GPIO_SetBits(GPIOB, GPIO_Pin_1))

#define T_GREEN {GPIOB->ODR ^= GPIO_Pin_0;}
#define T_BLUE {GPIOB->ODR ^= GPIO_Pin_1;}
#define T_RED {GPIOB->ODR ^= GPIO_Pin_5;}



//LED操作定义
#define LED_R(n)      (n?GPIO_ResetBits(GPIOB, GPIO_Pin_5):GPIO_SetBits(GPIOB, GPIO_Pin_5))
#define LED_R_Toggle  {GPIOB->ODR ^= GPIO_Pin_5;}  // ^按位异或,与1异或改变,与0异或不变

#define LED_G(n)      (n?GPIO_ResetBits(GPIOB, GPIO_Pin_0):GPIO_SetBits(GPIOB, GPIO_Pin_0))
#define LED_G_Toggle  {GPIOB->ODR ^= GPIO_Pin_0;}  // ^按位异或,与1异或改变,与0异或不变

#define LED_B(n)      (n?GPIO_ResetBits(GPIOB, GPIO_Pin_1):GPIO_SetBits(GPIOB, GPIO_Pin_1))
#define LED_B_Toggle  {GPIOB->ODR ^= GPIO_Pin_1;}  // ^按位异或,与1异或改变,与0异或不变

extern u16 WinkLED_Mode;
extern u16 LED_Mode;
void Led_Init(void);
void WinkLED_Ctrl(u16 Mode);
void TIM6_WinkLED_Init(void);
void LED_Ctrl(short Mode);
void Mode_Send(void);

#endif
