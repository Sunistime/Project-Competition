#ifndef __EXTI_H
#define __EXIT_H

#include "sys.h"

#define INT PBin(5)   //PB5连接到MPU6050的中断引脚

void MPU6050_EXTI_Init(void);//MPU6050外部中断初始化
void TCS3200_EXTI_Init(void);//TCS3200外部中断初始化

#endif

























