#ifndef __DMA_M2UART1_H
#define __DMA_M2UART1_H

#include "stm32f10x.h"

#define SENDBUFF_SIZE 5000 // 一次发送数据量
extern uint8_t SendBuff[SENDBUFF_SIZE];

void DMA_M2UART1_Config(void);

#endif
