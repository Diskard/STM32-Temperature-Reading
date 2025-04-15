#include "bsp_dma_m2uart1.h"

uint8_t SendBuff[SENDBUFF_SIZE];

void DMA_M2UART1_INVIC_Configuration()
{
    NVIC_InitTypeDef NVIC_InitStructure;    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);             //嵌套向量中断控制器组选择
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;    //配置DMA为中断源
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   //配置抢断优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //子优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //使能
    NVIC_Init(&NVIC_InitStructure);                             //初始化配置
}

void DMA_M2UART1_Config()
{
    DMA_InitTypeDef DMA_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);     //开启DMA时钟
    DMA_M2UART1_INVIC_Configuration();                     //配置NVIC

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(USART1_BASE + 0x04);  //设置DMA源地址：串口数据寄存器地址
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)SendBuff;                  //目标地址(传输变量的指针)
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                          //方向：内存到外设
    DMA_InitStructure.DMA_BufferSize = SENDBUFF_SIZE;                         //传输大小
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设地址不增
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//内存地址自增
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//外设数据单位
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; //内存数据单位
    DMA_InitStructure.DMA_Mode =  DMA_Mode_Normal; //DMA模式 一次或者循环模式
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;//优先级中
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //禁止M to M
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);//配置DMA通道
    DMA_Cmd(DMA1_Channel4,ENABLE);//使能DMA
    DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE);//使能DMA发送完成中断
}
