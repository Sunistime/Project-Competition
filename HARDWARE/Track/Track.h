#ifndef __TRACK_H
#define __TRACK_H

#include "sys.h"

#define Bai 0//��
#define Hei 1//��

#define HuiDu_A_L PAin(5)   //ǰ��
#define HuiDu_A_M PBin(3)   //ǰ��
#define HuiDu_A_R PBin(1)   //ǰ��

#define HuiDu_B_L PBin(0)   //����
#define HuiDu_B_M PAin(4)   //����
#define HuiDu_B_R PBin(4)   //����

#define HuiDu_L_1 PBin(8) //��ǰ
#define HuiDu_L_2 PBin(11)  //����
#define HuiDu_L_3 PAin(3)   //���

#define HuiDu_R_1 PBin(9) //��ǰ
#define HuiDu_R_2 PBin(10)  //����
#define HuiDu_R_3 PAin(2)   //�Һ�

#define ZhiZou_Man_A_L -300     //��ǰ��ֱ�����������ٶ�
#define ZhiZou_Man_A_R -300     //��ǰ��ֱ���ҵ�������ٶ�
#define ZhiZou_Man_B_L 300      //��ǰ��ֱ�����������ٶ�
#define ZhiZou_Man_B_R 300      //��ǰ��ֱ���ҵ�������ٶ�


/*-------------------------------------------------------*/
#define ZhiZou_A_L -500       //ǰ��ֱ�����������ٶ�
#define ZhiZou_A_R -500       //ǰ��ֱ���ҵ�������ٶ�

#define ZuoZhuan_A_L -500     //ǰ����ת���������ٶ�
#define ZuoZhuan_A_R -550     //ǰ����ת�ҵ�������ٶ�

#define YouZhuan_A_L -550     //ǰ����ת���������ٶ�
#define YouZhuan_A_R -500     //ǰ����ת�ҵ�������ٶ�
/*-------------------------------------------------------*/
#define ZhiZou_B_L 500       //����ֱ�����������ٶ�
#define ZhiZou_B_R 500       //����ֱ���ҵ�������ٶ�

#define ZuoZhuan_B_L 500     //������ת���������ٶ�
#define ZuoZhuan_B_R 550     //������ת�ҵ�������ٶ�

#define YouZhuan_B_L 550     //������ת���������ٶ�
#define YouZhuan_B_R 500     //������ת�ҵ�������ٶ�


void TrackInit(void);
//void Tracking_Forward(void);//ǰ��ѭ�����������ֲ�ֹͣ
//void Tracking_Back(void);//����ѭ�����������ֲ�ֹͣ
void Tracking_1(uint8_t trackflog);//ǰ������ѭ����������ֹͣ 1ǰ�� 0����
void Tracking_2(uint8_t trackflog);//ǰ������ѭ��ȫ��λ����ֹͣ 1ǰ�� 0����
void Tracking_3(uint8_t trackflog);//ǰ������ѭ�����������λֹͣ 1ǰ�� 0����
void Tracking_4(uint8_t trackflog);//�ڷ�����λ����������������λֹͣ 1ǰ�� 0����
#endif

