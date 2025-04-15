#include "headers.h"

__IO uint16_t ADC_ConvertedValue;

void Adc_Init()
{
	ADC1_GPIO_Config();
	ADC1_Mode_Config();
}

static void ADC1_GPIO_Config(void)//GPIO��ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// �� ADC IO �˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	// ���� ADC IO ����ģʽ
	// ����Ϊģ������
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	// ��ʼ�� ADC IO
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

static void ADC1_Mode_Config(void)//adc1����ģʽ����
{
	ADC_InitTypeDef ADC_InitStructure;
	
	// �� ADC ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);//72M / 8 = 9M
	
	// ADC ģʽ����
	// ֻʹ��һ�� ADC�����ڶ���ģʽ
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	
	// ��ֹɨ��ģʽ����ͨ����Ҫ����ͨ������Ҫ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE ;
	
	// ����ת��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;

	// �����ⲿ����ת���������������
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	// ת������Ҷ���
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;

	// ת��ͨ�� 1 ��
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	
	// ��ʼ�� ADC
	ADC_Init(ADC1, &ADC_InitStructure);

	//ʹ���¶ȴ�����
	ADC_TempSensorVrefintCmd(ENABLE);
        

	// ���� ADC ͨ��ת��˳��Ϊ 1����һ��ת��������ʱ��Ϊ 55.5 ��ʱ������
	ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_55Cycles5);
	
	// ADC ת�����������жϣ����жϷ�������ж�ȡת��ֵ
	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);
	
	// ���� ADC ������ʼת��
	ADC_Cmd(ADC1, ENABLE);
	
	// ��ʼ�� ADC У׼�Ĵ���
	ADC_ResetCalibration(ADC1);
	// �ȴ�У׼�Ĵ�����ʼ�����
	while (ADC_GetResetCalibrationStatus(ADC1));
	
	// ADC ��ʼУ׼
	ADC_StartCalibration(ADC1);
	// �ȴ�У׼���
	while (ADC_GetCalibrationStatus(ADC1));
	
	// ����û�в����ⲿ����������ʹ��������� ADC ת��
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

u16 Get_ADC(u8 ch)//��ȡһ�ε�ѹ
{
 
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��3,��һ��ת��,����ʱ��Ϊ239.5����	  			    
 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������
	return ADC_GetConversionValue(ADC1);	//�������һ��ADC1�������ת�����

}

u16 Get_Adc_Average(u8 ch,u8 times)//��ȡ��ε�ѹȡ��ֵ
{
	u16 temp_value=0;
	u8 t;
	for(t=1;t<=times;t++)
	{
		temp_value+=Get_ADC(ADC_Channel_16);
		//delay_ms(5);
	}
	return temp_value/times;
} 



