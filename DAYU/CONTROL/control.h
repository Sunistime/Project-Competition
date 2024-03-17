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
    //PID ������
    fp32 Kp;
    fp32 Ki;
    fp32 Kd;

    fp32 max_out;  //������
    fp32 max_iout; //���������

    fp32 set;//�������
    fp32 fdb;//ʵ�����

    fp32 out;
    fp32 Pout;
    fp32 Iout;
    fp32 Dout;
    fp32 Dbuf[3];  //΢���� 0���� 1��һ�� 2���ϴ�
    fp32 error[3]; //����� 0���� 1��һ�� 2���ϴ�

} PidTypeDef1;

typedef struct
{
    uint8_t mode;
    //PID ������
    fp32 Kp;
    fp32 Ki;
    fp32 Kd;

    fp32 max_out;  //������
    fp32 max_iout; //���������

    fp32 set;//�������
    fp32 fdb;//ʵ�����

    fp32 out;
    fp32 Pout;
    fp32 Iout;
    fp32 Dout;
    fp32 Dbuf[3];  //΢���� 0���� 1��һ�� 2���ϴ�
    fp32 error[3]; //����� 0���� 1��һ�� 2���ϴ�

} PidTypeDef2;


void EXTI9_5_IRQHandler(void);
void EXTI0_IRQHandler(void);
void Path_Planning(void);//·���滮
void PID_Init(void);
extern void PID_Motor_Left_Init(PidTypeDef1 *pid, uint8_t mode, const fp32 PID[3], fp32 max_out, fp32 max_iout);
extern void PID_Motor_Right_Init(PidTypeDef2 *pid, uint8_t mode, const fp32 PID[3], fp32 max_out, fp32 max_iout);
extern fp32 PID_Calc_Motor_Left(PidTypeDef1 *pid, fp32 ref, fp32 set);
extern fp32 PID_Calc_Motor_Right(PidTypeDef2 *pid, fp32 ref, fp32 set);
extern void PID_clear(PidTypeDef1 *pid);
#endif
