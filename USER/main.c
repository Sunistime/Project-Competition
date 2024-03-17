#include "sys.h"

short gyrox,gyroy,gyroz;//陀螺仪原始数据
int Encoder_Left,Encoder_Right;//左右编码器的脉冲计数
int Motor_Left,Motor_Right; //计算出来的最终赋给电机的PWM
float Target_Speed_L,Target_Speed_R;//期望速度
float Angle_Left,Angle_Right;//角度值
short Trackflog;//循迹标志位
short Zhuan_End;//旋转结束标志位 1结束 0未结束
short Miflog,DanWu_flog;//固定点位标志位 0未到达 1到达
short Color_Flog,White_balance_Flog;//颜色识别标志位 白平衡标志位
short TCS3200_Pa_Pl_Flog;
int Color_Num;
int Color_RGB[3]={0,0,0};
int RGB[3]={0,0,0};
float R_Divisor,G_Divisor,B_Divisor;//颜色因子

int main(void)
{ 
    delay_init(); //=====延时函数初始化
    delay_ms(100);
    NVIC_Configuration();//=====中断优先级分组,其中包含了所有的中断优先级的配置,方便管理和一次性修改。
    Encoder_Init_TIM2();//=====初始化编码器
    Encoder_Init_TIM3();
    TrackInit();//循迹引脚初始化
    MPU_Init(); //=====初始化MPU6050
    mpu_dmp_init(); //=====初始化MPU6050的DMP模式
    TIM1_PWM_Init(7199,0);    //=====初始化PWM 10KHZ,用于驱动电机
    delay_ms(1000); //=====延时1s 解决小车上电轮子乱转的问题
    Motor_Init(); //=====初始化与电机连接的硬件IO接口 
    MPU6050_EXTI_Init(); //=====MPU6050 5ms定时中断初始化
    PID_Init();
    //TCS3200_Init();
    //OLED_Init();
    //uart2_Init(9600);
    
    while(1)
    {
        //SHOW();
        
    }
}


