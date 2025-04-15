# STM32-Temperature-Reading
基于stm32的简易温度读取(野火STM32F103指南者)

通过STM32芯片ADC1通道16内置的温度传感器进行CPU温度采集，并通过虚拟串口将温度数据发到上位机

上位机使用C#+winforms实现，可以显示温度折线图，32部分使用标准库

超过设定阈值时上位机和板子都会报警

具体操作看BiliBili视频：https://www.bilibili.com/video/BV1wNhMehEbK/
