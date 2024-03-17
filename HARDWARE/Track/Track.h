#ifndef __TRACK_H
#define __TRACK_H

#include "sys.h"

#define Bai 0//白
#define Hei 1//黑

#define HuiDu_A_L PAin(5)   //前左
#define HuiDu_A_M PBin(3)   //前中
#define HuiDu_A_R PBin(1)   //前右

#define HuiDu_B_L PBin(0)   //后左
#define HuiDu_B_M PAin(4)   //后中
#define HuiDu_B_R PBin(4)   //后右

#define HuiDu_L_1 PBin(8) //左前
#define HuiDu_L_2 PBin(11)  //左中
#define HuiDu_L_3 PAin(3)   //左后

#define HuiDu_R_1 PBin(9) //右前
#define HuiDu_R_2 PBin(10)  //右中
#define HuiDu_R_3 PAin(2)   //右后

#define ZhiZou_Man_A_L -300     //慢前排直走左电机期望速度
#define ZhiZou_Man_A_R -300     //慢前排直走右电机期望速度
#define ZhiZou_Man_B_L 300      //慢前排直走左电机期望速度
#define ZhiZou_Man_B_R 300      //慢前排直走右电机期望速度


/*-------------------------------------------------------*/
#define ZhiZou_A_L -500       //前排直走左电机期望速度
#define ZhiZou_A_R -500       //前排直走右电机期望速度

#define ZuoZhuan_A_L -500     //前排左转左电机期望速度
#define ZuoZhuan_A_R -550     //前排左转右电机期望速度

#define YouZhuan_A_L -550     //前排右转左电机期望速度
#define YouZhuan_A_R -500     //前排右转右电机期望速度
/*-------------------------------------------------------*/
#define ZhiZou_B_L 500       //后排直走左电机期望速度
#define ZhiZou_B_R 500       //后排直走右电机期望速度

#define ZuoZhuan_B_L 500     //后排左转左电机期望速度
#define ZuoZhuan_B_R 550     //后排左转右电机期望速度

#define YouZhuan_B_L 550     //后排右转左电机期望速度
#define YouZhuan_B_R 500     //后排右转右电机期望速度


void TrackInit(void);
//void Tracking_Forward(void);//前进循迹，到达米字不停止
//void Tracking_Back(void);//后退循迹，到达米字不停止
void Tracking_1(uint8_t trackflog);//前进后退循迹到达米字停止 1前进 0后退
void Tracking_2(uint8_t trackflog);//前进后退循迹全点位都不停止 1前进 0后退
void Tracking_3(uint8_t trackflog);//前进后退循迹到达放物块点位停止 1前进 0后退
void Tracking_4(uint8_t trackflog);//在放物块点位启动，在欲放物块点位停止 1前进 0后退
#endif

