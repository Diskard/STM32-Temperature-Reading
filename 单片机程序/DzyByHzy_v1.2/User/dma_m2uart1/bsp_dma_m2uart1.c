#include "bsp_dma_m2uart1.h"

uint8_t SendBuff[SENDBUFF_SIZE];

void DMA_M2UART1_INVIC_Configuration()
{
    NVIC_InitTypeDef NVIC_InitStructure;    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);             //Ƕ�������жϿ�������ѡ��
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;    //����DMAΪ�ж�Դ
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   //�����������ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //�����ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //ʹ��
    NVIC_Init(&NVIC_InitStructure);                             //��ʼ������
}

void DMA_M2UART1_Config()
{
    DMA_InitTypeDef DMA_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);     //����DMAʱ��
    DMA_M2UART1_INVIC_Configuration();                     //����NVIC

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(USART1_BASE + 0x04);  //����DMAԴ��ַ���������ݼĴ�����ַ
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)SendBuff;                  //Ŀ���ַ(���������ָ��)
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                          //�����ڴ浽����
    DMA_InitStructure.DMA_BufferSize = SENDBUFF_SIZE;                         //�����С
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//�����ַ����
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//�ڴ��ַ����
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//�������ݵ�λ
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; //�ڴ����ݵ�λ
    DMA_InitStructure.DMA_Mode =  DMA_Mode_Normal; //DMAģʽ һ�λ���ѭ��ģʽ
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;//���ȼ���
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //��ֹM to M
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);//����DMAͨ��
    DMA_Cmd(DMA1_Channel4,ENABLE);//ʹ��DMA
    DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE);//ʹ��DMA��������ж�
}
