#ifndef __DuJi_H
#define __DuJi_H

#include "sys.h"

void DuoJi_Init(void);
void DuoJi_PWM_Init(void);

void DuoJi_Control(short DUOJI_Flog,short duoji_Flog);//舵机控制
void duoji_Control(short duoji_Flog);//五爪小舵机控制
void WuZhua_DUOJI(uint16_t Compare);//五爪大舵机控制
void WuZhua_Duoji_1(uint16_t Compare);//五爪小舵机1控制
void WuZhua_Duoji_2(uint16_t Compare);//五爪小舵机2控制
void WuZhua_Duoji_3(uint16_t Compare);//五爪小舵机3控制
void WuZhua_Duoji_4(uint16_t Compare);//五爪小舵机4控制
void WuZhua_Duoji_5(uint16_t Compare);//五爪小舵机5控制
void TaoTong_DUOJI(uint16_t Compare);//套筒大舵机控制
void TaoTong_Duoji(uint16_t Compare);//套筒小舵机控制


#endif

