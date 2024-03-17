#include "motor.h"

void Motor_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	//端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50MHZ
    GPIO_Init(GPIOB, &GPIO_InitStructure);//根据设定参数初始化GPIOB 
    AIN1=0,AIN2=0;
    BIN1=0,BIN1=0;
}

/**************************************************************************
函数功能：赋值给PWM寄存器
入口参数：左轮PWM、右轮PWM
返回  值：无
**************************************************************************/
void Set_Pwm(int moto1,int moto2)
{
    if(moto1<0) {AIN2=0,AIN1=1;PWMA=myabs(moto1);}//右
    else        {AIN2=1,AIN1=0;PWMA=myabs(moto1);}
    
    if(moto2<0) {BIN1=0,BIN2=1;PWMB=myabs(moto2);}//左
    else        {BIN1=1,BIN2=0;PWMB=myabs(moto2);}
}

void Yuandi_Zhuan(short angle)//正左转 负右转
{
    static int Begin_Flog;
    
    if(Begin_Flog==0)
    {
        switch(angle)
        {
            case 45:    Angle_Left=YuanDiAngle_Left_45;     Begin_Flog=1; break;
            case 90:    Angle_Left=YuanDiAngle_Left_90;     Begin_Flog=1; break;
            case 135:   Angle_Left=YuanDiAngle_Left_135;    Begin_Flog=1; break;
            case 180:   Angle_Left=YuanDiAngle_Left_180;    Begin_Flog=1; break;
            //case 225:   Angle_Left=;    Begin_Flog=1; break;
            //case 270:   Angle_Left=;    Begin_Flog=1; break;
            case -45:   Angle_Right=YuanDiAngle_Right_45;   Begin_Flog=2; break;
            case -90:   Angle_Right=YuanDiAngle_Right_90;   Begin_Flog=2; break;
            case -135:  Angle_Right=YuanDiAngle_Right_135;  Begin_Flog=2; break;
            case -180:  Angle_Right=YuanDiAngle_Right_180;  Begin_Flog=2; break;
            //case -225:  Angle_Right=;   Begin_Flog=2; break;
            //case -270:  Angle_Right=;   Begin_Flog=2; break;
            default:    Angle_Left=0;Angle_Right=0;Begin_Flog=0;
        }
    }
    if(Begin_Flog==1)
    {
        if(Angle_Left>0)//左转
        {
            Angle_Left--;
            Target_Speed_L=YuanDiZuoZhuan_L;
            Target_Speed_R=YuanDiZuoZhuan_R;
            Zhuan_End=0;
        }
        else if(Angle_Left==0)//停止
        {
            Target_Speed_L=0;
            Target_Speed_R=0;
            Begin_Flog=0;
            Zhuan_End=1;
        } 
    }
    if(Begin_Flog==2)
    {
        if(Angle_Right>0)//右转
        {
            Angle_Right--;
            Target_Speed_L=YuanDiYouZhuan_L;
            Target_Speed_R=YuanDiYouZhuan_R;
        }
        else if(Angle_Right==0)//停止
        {
            Target_Speed_L=0;
            Target_Speed_R=0;
            Begin_Flog=0;
        }
    }
    
}

/**************************************************************************
函数功能：绝对值函数
入口参数：int
返回  值：unsigned int
目    的：经过直立环和速度环以及转向环计算出来的PWM有可能为负值
        而只能赋给定时器PWM寄存器只能是正值。故需要对PWM进行绝对值处理
**************************************************************************/
int myabs(int a)
{
    int temp;
    if(a<0)  temp=-a;
    else temp=a;
    return temp;
}



