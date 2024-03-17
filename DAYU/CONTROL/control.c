#include "control.h"
/**************************************************************************
函数功能:   所有的控制代码都在这里面
            5ms定时中断由MPU6050的INT引脚触发
            严格保证采样和数据处理的时间同步	
            在MPU6050的采样频率设置中，设置成100HZ，即可保证6050的数据是10ms更新一次。
            读者可在imv_mpu.h文件第26行的宏定义进行修改(#define DEFAULT_MPU_HZ  (100))
**************************************************************************/

const float PID[3]={2.5,0.5,0.0125};  //赋予PID三参数数值
PidTypeDef1 PID1_Structure;
PidTypeDef2 PID2_Structure;

void EXTI9_5_IRQHandler(void)
{
    if(PBin(5)==0)
    {
        EXTI->PR=1<<5;  //清除LINE5上的中断标志位
        Encoder_Left=-Read_Encoder(2); //读取编码器的值，保证输出极性一致
        Encoder_Right=Read_Encoder(3); //读取编码器的值
//        if(White_balance_Flog==1){TCS3200_Color_Recognition();}//颜色识别
//        else{TCS3200_White_balance();}//白平衡
        
        Path_Planning();
        
        //Tracking_3(1);
        //Tracking1(1);
        //Tracking_Forward();
        //Tracking_Back();
        //Yuandi_Left();
        
        Motor_Left=PID_Calc_Motor_Left(&PID1_Structure,Encoder_Left,Target_Speed_L); //===计算左轮电机最终PWM
        Motor_Right=PID_Calc_Motor_Right(&PID2_Structure,Encoder_Right,Target_Speed_R); //===计算右轮电机最终PWM             
        Set_Pwm(Motor_Left,Motor_Right);       //===赋值给PWM寄存器
    }
}

//void EXTI0_IRQHandler(void)
//{
//    if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
//    {
//        EXTI_ClearITPendingBit(EXTI_Line0);//清除LINE0上的中断标志位
//        Color_Num++;
//    }
//}

void Path_Planning()
{
//    TCS3200_Path_Planning();
//    switch(TCS3200_Pa_Pl_Flog)
//    {
//        case 0:Tracking(1);     break;//无
//        case 1:Tracking(2);   break;//白
//        case 2:     break;//黑
//        case 3:     break;//红
//        case 4:     break;//绿
//        case 5:     break;//蓝
//        default://无
//    }
    static int Num;
    if(Num==0)
    {
        if(Miflog==0)//未到米字
        {
            Tracking_1(1);
        }
        else if(Miflog==1)//到米字
        {
            if(DanWu_flog==0)//未到单个物块地点
            {
                Tracking_3(1);
            }
            else if(DanWu_flog==1)//抓物块
            {
                Num=1;Miflog=0;DanWu_flog=0;Zhuan_End=0;
            }
        }
    }
    else if(Num==1)
    {
        if(Miflog==0)//未到米字
        {
            Tracking_1(0);
        }
        else if(Miflog==1)//到米字
        {
            if(Zhuan_End==0)
            {
                Yuandi_Zhuan(90);
            }
            else if(Zhuan_End==1)//旋转结束
            {
                if(DanWu_flog==0)//未到单个物块地点
                {
                    Tracking_3(1);
                }
                else if(DanWu_flog==1)//抓物块
                {
                    Num=2;Miflog=0;DanWu_flog=0;Zhuan_End=0;
                }
            }
        }
    }
    else if(Num==2)
    {
        if(DanWu_flog==0)//未到单个物块地点
        {
            Tracking_4(1);
        }
        if(DanWu_flog<0)
        {
            Tracking_4(1);
        }
        else if(DanWu_flog==0)//走出存放物块地点 去放物块
        {
            Tracking_3(1);
        }
        else if(DanWu_flog==1)//放物块
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

fp32 PID_Calc_Motor_Left(PidTypeDef1 *pid, fp32 ref, fp32 set)       //PID计算函数
{
    if (pid == NULL)
    {
        return 0.0f;
    }

    pid->error[2] = pid->error[1];   //把上次给上上次
    pid->error[1] = pid->error[0];   //把这次给上次
    pid->set = set;//期望输出
    pid->fdb = ref;//实际输出
    pid->error[0] = set - ref;//此时误差值（更新这次）
    if (pid->mode == PID_POSITION)
    {
        pid->Pout = pid->Kp * pid->error[0];
        pid->Iout += pid->Ki * pid->error[0];//I项积累
        //微分项变动
        pid->Dbuf[2] = pid->Dbuf[1];
        pid->Dbuf[1] = pid->Dbuf[0];
        pid->Dbuf[0] = (pid->error[0] - pid->error[1]);
        pid->Dout = pid->Kd * pid->Dbuf[0];   //D项总输出
        
        LimitMax(pid->Iout, pid->max_iout);             //对I进行积分限幅
        pid->out = pid->Pout + pid->Iout + pid->Dout;   //pid控制器的输出
        LimitMax(pid->out, pid->max_out);               //对总输出进行积分限幅
    }
    return pid->out;
}

fp32 PID_Calc_Motor_Right(PidTypeDef2 *pid, fp32 ref, fp32 set)//PID计算函数
{
    if (pid == NULL)
    {
        return 0.0f;
    }

    pid->error[2] = pid->error[1];   //把上次给上上次
    pid->error[1] = pid->error[0];   //把这次给上次
    pid->set = set;//期望输出
    pid->fdb = ref;//实际输出
    pid->error[0] = set - ref;//此时误差值（更新这次）
    if (pid->mode == PID_POSITION)
    {
        pid->Pout = pid->Kp * pid->error[0];
        pid->Iout += pid->Ki * pid->error[0];//I项积累
        //微分项变动
        pid->Dbuf[2] = pid->Dbuf[1];
        pid->Dbuf[1] = pid->Dbuf[0];
        pid->Dbuf[0] = (pid->error[0] - pid->error[1]);
        pid->Dout = pid->Kd * pid->Dbuf[0];//D项总输出
        
        LimitMax(pid->Iout, pid->max_iout);             //对I进行积分限幅
        pid->out = pid->Pout + pid->Iout + pid->Dout;   //pid控制器的输出
        LimitMax(pid->out, pid->max_out);               //对总输出进行积分限幅
    }
    return pid->out;
}

void PID_clear(PidTypeDef1 *pid)  //清除pid控制器的状态（放入1或者2的结构体，便可清除状态）
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



