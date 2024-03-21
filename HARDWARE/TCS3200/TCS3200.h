#ifndef __TCS3200_H
#define __TCS3200_H

#include "sys.h"

/*-------------------------------------------------------
|   S0   |   S1   |           |   S2   |   S3   |       
---------------------------------------------------------
|   L    |   L    |   �ϵ�    |   L    |   L    |  ��ɫ  
---------------------------------------------------------
|   L    |   H    |   2%      |   L    |   H    |  ��ɫ  
---------------------------------------------------------
|   H    |   L    |   20%     |   H    |   L    |  ͸��  
---------------------------------------------------------
|   H    |   H    |   100%    |   H    |   H    |  ��ɫ  
---------------------------------------------------------*/

#define S0(a) if (a) \
     GPIO_SetBits(GPIOB,GPIO_Pin_3);\
     else  \
     GPIO_ResetBits(GPIOB,GPIO_Pin_3)
     
#define S1(b) if (b) \
     GPIO_SetBits(GPIOB,GPIO_Pin_4);\
     else  \
     GPIO_ResetBits(GPIOB,GPIO_Pin_4)
     
#define S2(c) if (c) \
     GPIO_SetBits(GPIOA,GPIO_Pin_4);\
     else  \
     GPIO_ResetBits(GPIOA,GPIO_Pin_4)
     
#define S3(d) if (d) \
     GPIO_SetBits(GPIOA,GPIO_Pin_5);\
     else  \
     GPIO_ResetBits(GPIOA,GPIO_Pin_5)
     
#define OE(e) if (e) \
     GPIO_SetBits(GPIOB,GPIO_Pin_1);\
     else  \
     GPIO_ResetBits(GPIOB,GPIO_Pin_1)
     
//#define S0  PBin(3)
//#define S1  PBin(4)
//#define S2  PAin(4)
//#define S3  PAin(5)
//#define OE  PBin(1)//�͵�ƽ��Ч

//#define DuanDian    S0 = 0;S1 = 0;//�ϵ�
//#define Mode_2      S0 = 0;S1 = 1;//2%
//#define Mode_20     S0 = 1;S1 = 0;//20%
//#define Mode_100    S0 = 1;S1 = 1;//100%

//#define Red         S2 = 0;S3 = 0;//��
//#define Blue        S2 = 0;S3 = 1;//��
//#define NoColor     S2 = 1;S3 = 0;//͸��
//#define Green       S2 = 1;S3 = 1;//��


void TCS3200_Init(void);
void TCS3200_Determine(void);//�ж���ɫ
void TCS3200_Planning(void);//·���滮
void TCS3200_Color_Recognition(void);//��ɫʶ��
void TCS3200_Color_Re(void);//��ɫʶ��ײ�
void TCS3200_White_balance(void);//1��� 0�쳣
void TCS3200_Mode(u8 TCS3200_Mode);
void TCS3200_Mode_Color(u8 TCS3200_Color_Mode);

#endif

