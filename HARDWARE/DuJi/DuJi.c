#include "DuJi.h"

void DuoJi_Init()//�����ʼ�� PWM��ʼ�� �͸��������λ
{
    DuoJi_PWM_Init();
    
    WuZhua_DUOJI(0);    //��צ��������
    WuZhua_Duoji_1(0);  //��צС���1̧��
    WuZhua_Duoji_2(0);  //��צС���2̧��
    WuZhua_Duoji_3(0);  //��צС���3̧��
    WuZhua_Duoji_4(0);  //��צС���4̧��
    WuZhua_Duoji_5(0);  //��צС���5̧��
    TaoTong_DUOJI(0);   //��Ͳ��������
    TaoTong_Duoji(0);   //��ͲС�������
    
}

//�������
//DUOJI_Flog = 2 ��צ������ת144��    duoji_Flog = 1 ��צС���1����
//DUOJI_Flog = 1 ��צ������ת72��     duoji_Flog = 2 ��צС���2����
//DUOJI_Flog = 0 ��צ��������         duoji_Flog = 3 ��צС���3����
//DUOJI_Flog =-1 ��צ������ת72��     duoji_Flog = 4 ��צС���4����
//DUOJI_Flog =-2 ��צ������ת144��    duoji_Flog = 5 ��צС���5����
void DuoJi_Control(short DUOJI_Flog,short duoji_Flog)
{
    if(DUOJI_ON_Flog==1)//����ܿ��ؿ���
    {
        if(DUOJI_Flog==0)//��������
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==1)//������ת72��
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==2)//������ת144��
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==-1)//������ת72�� 
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==-2)//������ת144��
        {
            duoji_Control(duoji_Flog);
        }
    }
}

void duoji_Control(short duoji_Flog)//��צС�������
{
    if(duoji_Flog==1)//��צС���1����
    {
        WuZhua_Duoji_1(150);
        delay_ms(500);//��ʱһ��500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==2)//��צС���2����
    {
        WuZhua_Duoji_2(150);
        delay_ms(500);//��ʱһ��500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==3)//��צС���3����
    {
        WuZhua_Duoji_3(150);
        delay_ms(500);//��ʱһ��500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==4)//��צС���4����
    {
        WuZhua_Duoji_4(150);
        delay_ms(500);//��ʱһ��500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==5)//��צС���5����
    {
        WuZhua_Duoji_5(150);
        delay_ms(500);//��ʱһ��500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
}











void DuoJi_PWM_Init()
{
    //���pwm��ʼ��,���Ų���ûд
}

void WuZhua_DUOJI(uint16_t Compare)//��צ��������
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_1(uint16_t Compare)//��צС���1����
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_2(uint16_t Compare)//��צС���2����
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_3(uint16_t Compare)//��צС���3����
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_4(uint16_t Compare)//��צС���4����
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_5(uint16_t Compare)//��צС���5����
{
    //(Compare / 180 * 2000 + 500)
}

void TaoTong_DUOJI(uint16_t Compare)//��Ͳ��������
{
    //(Compare / 180 * 2000 + 500)
}

void TaoTong_Duoji(uint16_t Compare)//��ͲС�������
{
    //(Compare / 180 * 2000 + 500)
}









