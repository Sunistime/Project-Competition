#ifndef __USRAT2_H
#define __USRAT2_H

#include "sys.h"

void uart2_Init(u32 bound);
void USART2_IRQHandler(void);
void Uart2SendByte(char byte);//���ڷ���һ���ֽ�
void Uart2SendBuf(char *buf, u16 len);
void Uart2SendStr(char *str);
void BluetoothCMD(int Uart_Receive);
#endif

