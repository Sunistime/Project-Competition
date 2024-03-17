#include "Track.h"

void TrackInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��PA�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4|GPIO_Pin_3|GPIO_Pin_2; //�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOA, &GPIO_InitStructure);      //�����趨������ʼ��GPIOA

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_3|GPIO_Pin_1|GPIO_Pin_0|GPIO_Pin_4|GPIO_Pin_10|GPIO_Pin_11;//�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOB, &GPIO_InitStructure);    //�����趨������ʼ��GPIOB
}


//void Tracking_Forward()//ǰ��ѭ�����������ֲ�ֹͣ
//{
//    if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//�м���� ǰ��
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
//    }
//    if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�м���� ǰ��
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
//    }
//    else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//ȫ�� ��ǰ��
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
//    }
//    else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//ȫ�� ��ǰ��
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
//    }
//    else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//����ֺ��� ��תǰ��
//    {
//        Trackflog=2;
//        Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
//    }
//    else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�ҳ��ֺ��� ��תǰ��
//    {
//        Trackflog=3;
//        Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
//    }
//}

//void Tracking_Back()//����ѭ�����������ֲ�ֹͣ
//{
//    if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//�м���� ����
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
//    }
//    if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�м���� ����
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
//    }
//    else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//ȫ�� ������
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
//    }
//    else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//ȫ�� ������
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
//    }
//    
//    else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//����ֺ��� ��ת����
//    {
//        Trackflog=-2;
//        Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
//    }
//    else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�ҳ��ֺ��� ��ת����
//    {
//        Trackflog=-3;
//        Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
//    }
//}

void Tracking_1(uint8_t trackflog)//ǰ������ѭ����������ֹͣ 1ǰ�� 0����
{
    if(HuiDu_L_2==Hei && HuiDu_L_3==Hei && HuiDu_R_2==Hei && HuiDu_R_3==Hei)//ֹͣ
    {
        Trackflog=0;
        Target_Speed_L = 0;Target_Speed_R = 0;
        Miflog=1;
    }
    else//�ƶ�
    {
        Miflog=0;
        if(trackflog==1)//ǰ��
        {
            if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//�м���� ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�м���� ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//ȫ�� ��ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//ȫ�� ��ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//����ֺ��� ��תǰ��
            {
                Trackflog=2;
                Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�ҳ��ֺ��� ��תǰ��
            {
                Trackflog=3;
                Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
            }
        }
        else if(trackflog==0)//����
        {
            if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//�м���� ����
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�м���� ����
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//ȫ�� ������
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
            }
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//ȫ�� ������
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
            }
            
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//����ֺ��� ��ת����
            {
                Trackflog=-2;
                Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�ҳ��ֺ��� ��ת����
            {
                Trackflog=-3;
                Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
            }
        }
    }
}

void Tracking_2(uint8_t trackflog)//ǰ������ѭ��ȫ��λ����ֹͣ 1ǰ�� 0����
{

    if(trackflog==1)//ǰ��
    {
        if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//�м���� ǰ��
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
        }
        if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�м���� ǰ��
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
        }
        else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//ȫ�� ��ǰ��
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
        }
        else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//ȫ�� ��ǰ��
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
        }
        else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//����ֺ��� ��תǰ��
        {
            Trackflog=2;
            Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
        }
        else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�ҳ��ֺ��� ��תǰ��
        {
            Trackflog=3;
            Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
        }
    }
    else if(trackflog==0)//����
    {
        if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//�м���� ����
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
        }
        if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�м���� ����
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
        }
        else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//ȫ�� ������
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
        }
        else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//ȫ�� ������
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
        }
        
        else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//����ֺ��� ��ת����
        {
            Trackflog=-2;
            Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
        }
        else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�ҳ��ֺ��� ��ת����
        {
            Trackflog=-3;
            Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
        }
    }
}
            
void Tracking_3(uint8_t trackflog)//ǰ������ѭ�����������λֹͣ 1ǰ�� 0����
{
    if(trackflog==1)//ǰ��
    {
        if(HuiDu_L_1==Hei && HuiDu_R_1==Hei && HuiDu_L_3==Bai && HuiDu_R_3==Bai && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//ֹͣ
        {
            Trackflog=0;
            Target_Speed_L = 0;Target_Speed_R = 0;
            DanWu_flog=1;
        }
        else
        {
            DanWu_flog=0;
            if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//�м���� ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�м���� ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//ȫ�� ��ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//ȫ�� ��ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//����ֺ��� ��תǰ��
            {
                Trackflog=2;
                Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�ҳ��ֺ��� ��תǰ��
            {
                Trackflog=3;
                Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
            }
        }
    }
    else if(trackflog==0)//����
    {
        if(HuiDu_L_3==Hei && HuiDu_R_3==Hei && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//ֹͣ
        {
            Trackflog=0;
            Target_Speed_L = 0;Target_Speed_R = 0;
            DanWu_flog=1;
        }
        else
        {
            if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//�м���� ����
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�м���� ����
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//ȫ�� ������
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
            }
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//ȫ�� ������
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
            }
            
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//����ֺ��� ��ת����
            {
                Trackflog=-2;
                Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�ҳ��ֺ��� ��ת����
            {
                Trackflog=-3;
                Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
            }
        }
    }
}

void Tracking_4(uint8_t trackflog)//�ڷ�����λ����������������λֹͣ 1ǰ�� 0����
{
    if(trackflog==1)//ǰ��
    {
        if(HuiDu_L_1==Hei && HuiDu_R_1==Hei && HuiDu_L_3==Bai && HuiDu_R_3==Bai && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//ǰ��
        {
            Trackflog=0;
            Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            DanWu_flog--;
            
        }
        else
        {
            DanWu_flog=0;
            if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//�м���� ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�м���� ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//ȫ�� ��ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//ȫ�� ��ǰ��
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//����ֺ��� ��תǰ��
            {
                Trackflog=2;
                Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//�ҳ��ֺ��� ��תǰ��
            {
                Trackflog=3;
                Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
            }
        }
    }
    else if(trackflog==0)//����
    {
        if(HuiDu_L_3==Hei && HuiDu_R_3==Hei && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//ֹͣ
        {
            Trackflog=0;
            Target_Speed_L = 0;Target_Speed_R = 0;
            DanWu_flog=1;
        }
        else
        {
            if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//�м���� ����
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�м���� ����
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//ȫ�� ������
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
            }
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//ȫ�� ������
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
            }
            
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//����ֺ��� ��ת����
            {
                Trackflog=-2;
                Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//�ҳ��ֺ��� ��ת����
            {
                Trackflog=-3;
                Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
            }
        }
    }
}
