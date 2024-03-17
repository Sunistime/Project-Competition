#include "sys.h"

short gyrox,gyroy,gyroz;//������ԭʼ����
int Encoder_Left,Encoder_Right;//���ұ��������������
int Motor_Left,Motor_Right; //������������ո��������PWM
float Target_Speed_L,Target_Speed_R;//�����ٶ�
float Angle_Left,Angle_Right;//�Ƕ�ֵ
short Trackflog;//ѭ����־λ
short Zhuan_End;//��ת������־λ 1���� 0δ����
short Miflog,DanWu_flog;//�̶���λ��־λ 0δ���� 1����
short Color_Flog,White_balance_Flog;//��ɫʶ���־λ ��ƽ���־λ
short TCS3200_Pa_Pl_Flog;
int Color_Num;
int Color_RGB[3]={0,0,0};
int RGB[3]={0,0,0};
float R_Divisor,G_Divisor,B_Divisor;//��ɫ����

int main(void)
{ 
    delay_init(); //=====��ʱ������ʼ��
    delay_ms(100);
    NVIC_Configuration();//=====�ж����ȼ�����,���а��������е��ж����ȼ�������,��������һ�����޸ġ�
    Encoder_Init_TIM2();//=====��ʼ��������
    Encoder_Init_TIM3();
    TrackInit();//ѭ�����ų�ʼ��
    MPU_Init(); //=====��ʼ��MPU6050
    mpu_dmp_init(); //=====��ʼ��MPU6050��DMPģʽ
    TIM1_PWM_Init(7199,0);    //=====��ʼ��PWM 10KHZ,�����������
    delay_ms(1000); //=====��ʱ1s ���С���ϵ�������ת������
    Motor_Init(); //=====��ʼ���������ӵ�Ӳ��IO�ӿ� 
    MPU6050_EXTI_Init(); //=====MPU6050 5ms��ʱ�жϳ�ʼ��
    PID_Init();
    //TCS3200_Init();
    //OLED_Init();
    //uart2_Init(9600);
    
    while(1)
    {
        //SHOW();
        
    }
}


