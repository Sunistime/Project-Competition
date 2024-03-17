#ifndef __CONTROL_H
#define __CONTROL_H

#include "sys.h"
#include "zhiru.h"

enum PID_MODE
{
    PID_POSITION = 0,
    PID_DELTA
};

typedef struct
{
    uint8_t mode;
    //PID 三参数
    fp32 Kp;
    fp32 Ki;
    fp32 Kd;

    fp32 max_out;  //最大输出
    fp32 max_iout; //最大积分输出

    fp32 set;//期望输出
    fp32 fdb;//实际输出

    fp32 out;
    fp32 Pout;
    fp32 Iout;
    fp32 Dout;
    fp32 Dbuf[3];  //微分项 0最新 1上一次 2上上次
    fp32 error[3]; //误差项 0最新 1上一次 2上上次

} PidTypeDef1;

typedef struct
{
    uint8_t mode;
    //PID 三参数
    fp32 Kp;
    fp32 Ki;
    fp32 Kd;

    fp32 max_out;  //最大输出
    fp32 max_iout; //最大积分输出

    fp32 set;//期望输出
    fp32 fdb;//实际输出

    fp32 out;
    fp32 Pout;
    fp32 Iout;
    fp32 Dout;
    fp32 Dbuf[3];  //微分项 0最新 1上一次 2上上次
    fp32 error[3]; //误差项 0最新 1上一次 2上上次

} PidTypeDef2;


void EXTI9_5_IRQHandler(void);
void EXTI0_IRQHandler(void);
void Path_Planning(void);//路径规划
void PID_Init(void);
extern void PID_Motor_Left_Init(PidTypeDef1 *pid, uint8_t mode, const fp32 PID[3], fp32 max_out, fp32 max_iout);
extern void PID_Motor_Right_Init(PidTypeDef2 *pid, uint8_t mode, const fp32 PID[3], fp32 max_out, fp32 max_iout);
extern fp32 PID_Calc_Motor_Left(PidTypeDef1 *pid, fp32 ref, fp32 set);
extern fp32 PID_Calc_Motor_Right(PidTypeDef2 *pid, fp32 ref, fp32 set);
extern void PID_clear(PidTypeDef1 *pid);
#endif
