#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "stm32f10x.h"
#include <stdio.h>

void USART1_INVIC_configuration(void);

void USART1_Init(void);

void Usart_SendByte(USART_TypeDef* pUSARTx, uint8_t data);

void Usart_SendHalfWord(USART_TypeDef* pUSARTx, uint16_t data);

void Usart_SendArray(USART_TypeDef* pUSARTx, uint8_t *array,uint8_t num);

void Usart_SendStr( USART_TypeDef * pUSARTx, char *str);

int fputc(int ch, FILE *f);

#endif
