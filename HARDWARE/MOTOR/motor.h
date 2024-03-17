#ifndef __MOTOR_H
#define __MOTOR_H

#include <sys.h>

#define PWMA   TIM1->CCR1  //PA8右电机

#define AIN2   PBout(15)
#define AIN1   PBout(14)
#define BIN1   PBout(13)
#define BIN2   PBout(12)

#define PWMB   TIM1->CCR4  //PA11左电机

#define YuanDiZuoZhuan_L 600    //原地左转左电机期望速度
#define YuanDiZuoZhuan_R -600   //原地左转右电机期望速度

#define YuanDiYouZhuan_L -600   //原地右转左电机期望速度
#define YuanDiYouZhuan_R 600    //原地右转右电机期望速度

#define YuanDiAngle_Left_45 28          //45度原地左转
#define YuanDiAngle_Right_45 30         //45度原地右转

#define YuanDiAngle_Left_90 57          //90度原地左转
#define YuanDiAngle_Right_90 58         //90度原地右转

#define YuanDiAngle_Left_135 88          //135度原地左转
#define YuanDiAngle_Right_135 87         //135度原地右转

#define YuanDiAngle_Left_180 115          //180度原地左转
#define YuanDiAngle_Right_180 116         //180度原地右转




void Motor_Init(void);
void Set_Pwm(int moto1,int moto2);
void Yuandi_Zhuan(short angle);//正左转 负右转
int myabs(int a);


#endif
