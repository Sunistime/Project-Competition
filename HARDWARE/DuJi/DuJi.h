#ifndef __DuJi_H
#define __DuJi_H

#include "sys.h"

void DuoJi_Init(void);
void DuoJi_PWM_Init(void);

void DuoJi_Control(short DUOJI_Flog,short duoji_Flog);//�������
void duoji_Control(short duoji_Flog);//��צС�������
void WuZhua_DUOJI(uint16_t Compare);//��צ��������
void WuZhua_Duoji_1(uint16_t Compare);//��צС���1����
void WuZhua_Duoji_2(uint16_t Compare);//��צС���2����
void WuZhua_Duoji_3(uint16_t Compare);//��צС���3����
void WuZhua_Duoji_4(uint16_t Compare);//��צС���4����
void WuZhua_Duoji_5(uint16_t Compare);//��צС���5����
void TaoTong_DUOJI(uint16_t Compare);//��Ͳ��������
void TaoTong_Duoji(uint16_t Compare);//��ͲС�������


#endif

