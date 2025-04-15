#ifndef __BEEP_H_
#define	__BEEP_H_

#include "stm32f10x.h"

/******************** BEEP 引脚配置参数定义 **************************/
#define    BEEP_GPIO_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define    BEEP_GPIO_CLK               RCC_APB2Periph_GPIOA
#define    BEEP_PORT                   GPIOA
#define    BEEP_PIN                    GPIO_Pin_8



/******************** BEEP 函数宏定义 *******************************/
#define    BEEP_ON()	      GPIO_SetBits(BEEP_PORT,BEEP_PIN)
#define    BEEP_OFF()       GPIO_ResetBits(BEEP_PORT,BEEP_PIN)

extern short Beep_Mode;

/************************七个音调************************************/
extern short melody_s[8];
extern short melody_m[8];
extern short melody_h[8];

extern short Beep_Mode;
extern short MusicA[18];
extern short *Music;

/************************** BEEP 函数声明****************************/
void Beep_Init(void);
void Music_On(void);
void Music_Off(void);
void Beep_Ctrl(short Mode);
void Music_Play(short MusicX[]);

#endif /* __BEEP_H_ */
