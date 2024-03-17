#include "control.h"
/**************************************************************************
��������:   ���еĿ��ƴ��붼��������
            5ms��ʱ�ж���MPU6050��INT���Ŵ���
            �ϸ�֤���������ݴ����ʱ��ͬ��	
            ��MPU6050�Ĳ���Ƶ�������У����ó�100HZ�����ɱ�֤6050��������10ms����һ�Ρ�
            ���߿���imv_mpu.h�ļ���26�еĺ궨������޸�(#define DEFAULT_MPU_HZ  (100))
**************************************************************************/

const float PID[3]={2.5,0.5,0.0125};  //����PID��������ֵ
PidTypeDef1 PID1_Structure;
PidTypeDef2 PID2_Structure;

void EXTI9_5_IRQHandler(void)
{
    if(PBin(5)==0)
    {
        EXTI->PR=1<<5;  //���LINE5�ϵ��жϱ�־λ
        Encoder_Left=-Read_Encoder(2); //��ȡ��������ֵ����֤�������һ��
        Encoder_Right=Read_Encoder(3); //��ȡ��������ֵ
//        if(White_balance_Flog==1){TCS3200_Color_Recognition();}//��ɫʶ��
//        else{TCS3200_White_balance();}//��ƽ��
        
        Path_Planning();
        
        //Tracking_3(1);
        //Tracking1(1);
        //Tracking_Forward();
        //Tracking_Back();
        //Yuandi_Left();
        
        Motor_Left=PID_Calc_Motor_Left(&PID1_Structure,Encoder_Left,Target_Speed_L); //===�������ֵ������PWM
        Motor_Right=PID_Calc_Motor_Right(&PID2_Structure,Encoder_Right,Target_Speed_R); //===�������ֵ������PWM             
        Set_Pwm(Motor_Left,Motor_Right);       //===��ֵ��PWM�Ĵ���
    }
}

//void EXTI0_IRQHandler(void)
//{
//    if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
//    {
//        EXTI_ClearITPendingBit(EXTI_Line0);//���LINE0�ϵ��жϱ�־λ
//        Color_Num++;
//    }
//}

void Path_Planning()
{
//    TCS3200_Path_Planning();
//    switch(TCS3200_Pa_Pl_Flog)
//    {
//        case 0:Tracking(1);     break;//��
//        case 1:Tracking(2);   break;//��
//        case 2:     break;//��
//        case 3:     break;//��
//        case 4:     break;//��
//        case 5:     break;//��
//        default://��
//    }
    static int Num;
    if(Num==0)
    {
        if(Miflog==0)//δ������
        {
            Tracking_1(1);
        }
        else if(Miflog==1)//������
        {
            if(DanWu_flog==0)//δ���������ص�
            {
                Tracking_3(1);
            }
            else if(DanWu_flog==1)//ץ���
            {
                Num=1;Miflog=0;DanWu_flog=0;Zhuan_End=0;
            }
        }
    }
    else if(Num==1)
    {
        if(Miflog==0)//δ������
        {
            Tracking_1(0);
        }
        else if(Miflog==1)//������
        {
            if(Zhuan_End==0)
            {
                Yuandi_Zhuan(90);
            }
            else if(Zhuan_End==1)//��ת����
            {
                if(DanWu_flog==0)//δ���������ص�
                {
                    Tracking_3(1);
                }
                else if(DanWu_flog==1)//ץ���
                {
                    Num=2;Miflog=0;DanWu_flog=0;Zhuan_End=0;
                }
            }
        }
    }
    else if(Num==2)
    {
        if(DanWu_flog==0)//δ���������ص�
        {
            Tracking_4(1);
        }
        if(DanWu_flog<0)
        {
            Tracking_4(1);
        }
        else if(DanWu_flog==0)//�߳�������ص� ȥ�����
        {
            Tracking_3(1);
        }
        else if(DanWu_flog==1)//�����
        {
            Target_Speed_L = 0;Target_Speed_R = 0;
            Num=3;Miflog=0;DanWu_flog=0;Zhuan_End=0;
        }
    }
}


void PID_Init(void)
{
    PID_Motor_Left_Init(&PID1_Structure,PID_POSITION,PID,7000,5000);
    PID_Motor_Right_Init(&PID2_Structure,PID_POSITION,PID,7000,5000);
}

#define LimitMax(input, max)   \
    {                          \
        if (input > max)       \
        {                      \
            input = max;       \
        }                      \
        else if (input < -max) \
        {                      \
            input = -max;      \
        }                      \
    }

void PID_Motor_Left_Init(PidTypeDef1 *pid, uint8_t mode, const fp32 PID[3], fp32 max_out, fp32 max_iout)
{
    if (pid == NULL || PID == NULL)
    {
        return;
    }
    pid->mode = mode;
    pid->Kp = PID[0];
    pid->Ki = PID[1];
    pid->Kd = PID[2];
    pid->max_out = max_out;
    pid->max_iout = max_iout;
    pid->Dbuf[0] = pid->Dbuf[1] = pid->Dbuf[2] = 0.0f;
    pid->error[0] = pid->error[1] = pid->error[2] = pid->Pout = pid->Iout = pid->Dout = pid->out = 0.0f;
}
void PID_Motor_Right_Init(PidTypeDef2 *pid, uint8_t mode, const fp32 PID[3], fp32 max_out, fp32 max_iout)
{
    if (pid == NULL || PID == NULL)
    {
        return;
    }
    pid->mode = mode;
    pid->Kp = PID[0];
    pid->Ki = PID[1];
    pid->Kd = PID[2];
    pid->max_out = max_out;
    pid->max_iout = max_iout;
    pid->Dbuf[0] = pid->Dbuf[1] = pid->Dbuf[2] = 0.0f;
    pid->error[0] = pid->error[1] = pid->error[2] = pid->Pout = pid->Iout = pid->Dout = pid->out = 0.0f;
}

fp32 PID_Calc_Motor_Left(PidTypeDef1 *pid, fp32 ref, fp32 set)       //PID���㺯��
{
    if (pid == NULL)
    {
        return 0.0f;
    }

    pid->error[2] = pid->error[1];   //���ϴθ����ϴ�
    pid->error[1] = pid->error[0];   //����θ��ϴ�
    pid->set = set;//�������
    pid->fdb = ref;//ʵ�����
    pid->error[0] = set - ref;//��ʱ���ֵ��������Σ�
    if (pid->mode == PID_POSITION)
    {
        pid->Pout = pid->Kp * pid->error[0];
        pid->Iout += pid->Ki * pid->error[0];//I�����
        //΢����䶯
        pid->Dbuf[2] = pid->Dbuf[1];
        pid->Dbuf[1] = pid->Dbuf[0];
        pid->Dbuf[0] = (pid->error[0] - pid->error[1]);
        pid->Dout = pid->Kd * pid->Dbuf[0];   //D�������
        
        LimitMax(pid->Iout, pid->max_iout);             //��I���л����޷�
        pid->out = pid->Pout + pid->Iout + pid->Dout;   //pid�����������
        LimitMax(pid->out, pid->max_out);               //����������л����޷�
    }
    return pid->out;
}

fp32 PID_Calc_Motor_Right(PidTypeDef2 *pid, fp32 ref, fp32 set)//PID���㺯��
{
    if (pid == NULL)
    {
        return 0.0f;
    }

    pid->error[2] = pid->error[1];   //���ϴθ����ϴ�
    pid->error[1] = pid->error[0];   //����θ��ϴ�
    pid->set = set;//�������
    pid->fdb = ref;//ʵ�����
    pid->error[0] = set - ref;//��ʱ���ֵ��������Σ�
    if (pid->mode == PID_POSITION)
    {
        pid->Pout = pid->Kp * pid->error[0];
        pid->Iout += pid->Ki * pid->error[0];//I�����
        //΢����䶯
        pid->Dbuf[2] = pid->Dbuf[1];
        pid->Dbuf[1] = pid->Dbuf[0];
        pid->Dbuf[0] = (pid->error[0] - pid->error[1]);
        pid->Dout = pid->Kd * pid->Dbuf[0];//D�������
        
        LimitMax(pid->Iout, pid->max_iout);             //��I���л����޷�
        pid->out = pid->Pout + pid->Iout + pid->Dout;   //pid�����������
        LimitMax(pid->out, pid->max_out);               //����������л����޷�
    }
    return pid->out;
}

void PID_clear(PidTypeDef1 *pid)  //���pid��������״̬������1����2�Ľṹ�壬������״̬��
{
    if (pid == NULL)
    {
        return;
    }

    pid->error[0] = pid->error[1] = pid->error[2] = 0.0f;
    pid->Dbuf[0] = pid->Dbuf[1] = pid->Dbuf[2] = 0.0f;
    pid->out = pid->Pout = pid->Iout = pid->Dout = 0.0f;
    pid->fdb = pid->set = 0.0f;
}



