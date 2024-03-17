#include "usart2.h"
/**************************************************************************
函数功能：串口2初始化
入口参数： bound:波特率
返回  值：无
**************************************************************************/
void uart2_Init(u32 bound)
{
    //GPIO端口设置
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能UGPIOB时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);//使能USART2时钟
    //USART2_TX  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PA2
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //USART2_RX	  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PA3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //USART 初始化设置
    USART_InitStructure.USART_BaudRate = bound;//串口波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//收发模式
    USART_Init(USART2, &USART_InitStructure);     //初始化串口2
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启串口接受中断
    USART_Cmd(USART2, ENABLE);                    //使能串口2 
}

/**************************************************************************
函数功能：串口2接收中断
入口参数：无
返回  值：无
**************************************************************************/
u8 Fore,Back,Left,Right;
void USART2_IRQHandler(void)
{
    int Uart_Receive;
    if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)//接收中断标志位拉高
    {
        Uart_Receive=USART_ReceiveData(USART2);//保存接收的数据
        BluetoothCMD(Uart_Receive);
    }
}

void BluetoothCMD(int Uart_Receive)
{
    switch(Uart_Receive)
    {
        case 1:Target_Speed_L=0;    Target_Speed_R=0;    break;//停止
        case 2:Target_Speed_L=200;  Target_Speed_R=200;  break;//后退
        case 3:Target_Speed_L=500;  Target_Speed_R=500;  break;//后退
        case 4:Target_Speed_L=550; Target_Speed_R=500; break;//后退
        case 5:Target_Speed_L=1500; Target_Speed_R=1500; break;//后退
        case 6:Target_Speed_L=-200; Target_Speed_R=-200; break;//前进
        case 7:Target_Speed_L=-500; Target_Speed_R=-500; break;//前进
        case 8:Target_Speed_L=-550;Target_Speed_R=-500;break;//前进
        case 9:Target_Speed_L=-1500;Target_Speed_R=-1500;break;//前进
        default:Target_Speed_L=0;   Target_Speed_R=0;    break;//停止
    }
}

void Uart2SendByte(char byte)   //串口发送一个字节
{
    USART_SendData(USART2, byte);        //通过库函数  发送数据
    while( USART_GetFlagStatus(USART2,USART_FLAG_TC)!= SET);  
    //等待发送完成。   检测 USART_FLAG_TC 是否置1；    //见库函数 P359 介绍
}

void Uart2SendBuf(char *buf, u16 len)
{
    u16 i;
    for(i=0; i<len; i++)Uart2SendByte(*buf++);
}
void Uart2SendStr(char *str)
{
    u16 i,len;
    len = strlen(str);
    for(i=0; i<len; i++)Uart2SendByte(*str++);
}

