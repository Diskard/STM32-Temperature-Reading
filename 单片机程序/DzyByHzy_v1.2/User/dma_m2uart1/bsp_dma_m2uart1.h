#ifndef __DMA_M2UART1_H
#define __DMA_M2UART1_H

#include "stm32f10x.h"

#define SENDBUFF_SIZE 5000 // һ�η���������
extern uint8_t SendBuff[SENDBUFF_SIZE];

void DMA_M2UART1_Config(void);

#endif
