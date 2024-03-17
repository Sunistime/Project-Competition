#ifndef __MOTOR_H
#define __MOTOR_H

#include <sys.h>

#define PWMA   TIM1->CCR1  //PA8�ҵ��

#define AIN2   PBout(15)
#define AIN1   PBout(14)
#define BIN1   PBout(13)
#define BIN2   PBout(12)

#define PWMB   TIM1->CCR4  //PA11����

#define YuanDiZuoZhuan_L 600    //ԭ����ת���������ٶ�
#define YuanDiZuoZhuan_R -600   //ԭ����ת�ҵ�������ٶ�

#define YuanDiYouZhuan_L -600   //ԭ����ת���������ٶ�
#define YuanDiYouZhuan_R 600    //ԭ����ת�ҵ�������ٶ�

#define YuanDiAngle_Left_45 28          //45��ԭ����ת
#define YuanDiAngle_Right_45 30         //45��ԭ����ת

#define YuanDiAngle_Left_90 57          //90��ԭ����ת
#define YuanDiAngle_Right_90 58         //90��ԭ����ת

#define YuanDiAngle_Left_135 88          //135��ԭ����ת
#define YuanDiAngle_Right_135 87         //135��ԭ����ת

#define YuanDiAngle_Left_180 115          //180��ԭ����ת
#define YuanDiAngle_Right_180 116         //180��ԭ����ת




void Motor_Init(void);
void Set_Pwm(int moto1,int moto2);
void Yuandi_Zhuan(short angle);//����ת ����ת
int myabs(int a);


#endif
