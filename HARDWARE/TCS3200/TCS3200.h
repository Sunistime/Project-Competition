#ifndef __TCS3200_H
#define __TCS3200_H

#include "sys.h"

/*-------------------------------------------------------
|   S0   |   S1   |           |   S2   |   S3   |       
---------------------------------------------------------
|   L    |   L    |   断电    |   L    |   L    |  红色  
---------------------------------------------------------
|   L    |   H    |   2%      |   L    |   H    |  蓝色  
---------------------------------------------------------
|   H    |   L    |   20%     |   H    |   L    |  透明  
---------------------------------------------------------
|   H    |   H    |   100%    |   H    |   H    |  绿色  
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
//#define OE  PBin(1)//低电平有效

//#define DuanDian    S0 = 0;S1 = 0;//断电
//#define Mode_2      S0 = 0;S1 = 1;//2%
//#define Mode_20     S0 = 1;S1 = 0;//20%
//#define Mode_100    S0 = 1;S1 = 1;//100%

//#define Red         S2 = 0;S3 = 0;//红
//#define Blue        S2 = 0;S3 = 1;//蓝
//#define NoColor     S2 = 1;S3 = 0;//透明
//#define Green       S2 = 1;S3 = 1;//绿


void TCS3200_Init(void);
void TCS3200_Determine(void);//判断颜色
void TCS3200_Planning(void);//路径规划
void TCS3200_Color_Recognition(void);//颜色识别
void TCS3200_Color_Re(void);//颜色识别底层
void TCS3200_White_balance(void);//1完成 0异常
void TCS3200_Mode(u8 TCS3200_Mode);
void TCS3200_Mode_Color(u8 TCS3200_Color_Mode);

#endif

