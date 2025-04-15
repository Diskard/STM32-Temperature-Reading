#include "bsp_basic_timer.h"

uint16_t tim6_cnt = 0;

//������ʱ����ʼ��
void BASIC_TIM_Init(uint16_t arr,uint16_t psc)
{
	  //�ж����ȼ�����
		NVIC_InitTypeDef NVIC_InitStructure; 
		/* Ƕ�������жϿ�������ѡ�� */
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
		/* �����ж�Դ */
		NVIC_InitStructure.NVIC_IRQChannel                   = TIM6_IRQn;
		/* �������ȼ�*/
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
		/* �����ȼ� */
		NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
		/* ʹ���ж� */
		NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
		/* ��ʼ������NVIC */
		NVIC_Init(&NVIC_InitStructure);
	
	
	  //���ö�ʱ��
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	
		// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);	
		// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
    TIM_TimeBaseStructure.TIM_Period              = arr;	
	  // ʱ��Ԥ��Ƶ��Ϊ
    TIM_TimeBaseStructure.TIM_Prescaler           = psc;
		// ʱ�ӷ�Ƶ���� ��������ʱ��û�У����ù�
    //TIM_TimeBaseStructure.TIM_ClockDivision     = TIM_CKD_DIV1;	
		// ����������ģʽ��������ʱ��ֻ�����ϼ�����û�м���ģʽ������
    //TIM_TimeBaseStructure.TIM_CounterMode       = TIM_CounterMode_Up; 		
		// �ظ���������ֵ��������ʱ��û�У����ù�
		//TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	  // ��ʼ����ʱ��
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);	
		// ����������жϱ�־λ
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);  
		// �����������ж�
    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);	
		// ʹ�ܼ�����
    TIM_Cmd(TIM6, ENABLE);	
}
