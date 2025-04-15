#include "headers.h"

__IO uint16_t ADC_ConvertedValue;

void Adc_Init()
{
	ADC1_GPIO_Config();
	ADC1_Mode_Config();
}

static void ADC1_GPIO_Config(void)//GPIO初始化
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 打开 ADC IO 端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	// 配置 ADC IO 引脚模式
	// 必须为模拟输入
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	// 初始化 ADC IO
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

static void ADC1_Mode_Config(void)//adc1工作模式配置
{
	ADC_InitTypeDef ADC_InitStructure;
	
	// 打开 ADC 时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);//72M / 8 = 9M
	
	// ADC 模式配置
	// 只使用一个 ADC，属于独立模式
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	
	// 禁止扫描模式，多通道才要，单通道不需要
	ADC_InitStructure.ADC_ScanConvMode = DISABLE ;
	
	// 连续转换模式
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;

	// 不用外部触发转换，软件开启即可
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	// 转换结果右对齐
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;

	// 转换通道 1 个
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	
	// 初始化 ADC
	ADC_Init(ADC1, &ADC_InitStructure);

	//使能温度传感器
	ADC_TempSensorVrefintCmd(ENABLE);
        

	// 配置 ADC 通道转换顺序为 1，第一个转换，采样时间为 55.5 个时钟周期
	ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_55Cycles5);
	
	// ADC 转换结束产生中断，在中断服务程序中读取转换值
	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);
	
	// 开启 ADC ，并开始转换
	ADC_Cmd(ADC1, ENABLE);
	
	// 初始化 ADC 校准寄存器
	ADC_ResetCalibration(ADC1);
	// 等待校准寄存器初始化完成
	while (ADC_GetResetCalibrationStatus(ADC1));
	
	// ADC 开始校准
	ADC_StartCalibration(ADC1);
	// 等待校准完成
	while (ADC_GetCalibrationStatus(ADC1));
	
	// 由于没有采用外部触发，所以使用软件触发 ADC 转换
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

u16 Get_ADC(u8 ch)//获取一次电压
{
 
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道3,第一个转换,采样时间为239.5周期	  			    
 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束
	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果

}

u16 Get_Adc_Average(u8 ch,u8 times)//获取多次电压取均值
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



