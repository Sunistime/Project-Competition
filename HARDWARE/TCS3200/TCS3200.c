#include "TCS3200.h"

void TCS3200_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��PA�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5; //�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);      //�����趨������ʼ��GPIOA

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_4;     //�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);    //�����趨������ʼ��GPIOB
    TCS3200_Mode(20);//20%
    TCS3200_Mode_Color(0);//͸��(�޹�����)
    OE(0);//�͵�ƽ��Ч
    TCS3200_EXTI_Init();
}

/*0�� 1�� 2�� 3�� 4�� 5��*/
void TCS3200_Path_Planning()//·���滮 �õ�������·��ֵ
{
    if(Color_RGB[0]>=235&&Color_RGB[0]<=255&&Color_RGB[1]>=235&&Color_RGB[1]<=255&&Color_RGB[2]>=235&&Color_RGB[2]<=255)//��
    {
        TCS3200_Pa_Pl_Flog=1;
    }
    else if(Color_RGB[0]>=10&&Color_RGB[0]<=50&&Color_RGB[1]>=10&&Color_RGB[1]<=50&&Color_RGB[2]>=10&&Color_RGB[2]<=50)//��
    {
        TCS3200_Pa_Pl_Flog=2;
    }
    else if(Color_RGB[0]>=155&&Color_RGB[0]<=195&&Color_RGB[1]>=26&&Color_RGB[1]<=66&&Color_RGB[2]>=37&&Color_RGB[2]<=77)//��
    {
        TCS3200_Pa_Pl_Flog=3;
    }
    else if(Color_RGB[0]>=25&&Color_RGB[0]<=65&&Color_RGB[1]>=70&&Color_RGB[1]<=110&&Color_RGB[2]>=53&&Color_RGB[2]<=93)//��
    {
        TCS3200_Pa_Pl_Flog=4;
    }
    else if(Color_RGB[0]>=26&&Color_RGB[0]<=66&&Color_RGB[1]>=39&&Color_RGB[1]<=79&&Color_RGB[2]>=73&&Color_RGB[2]<=113)//��
    {
        TCS3200_Pa_Pl_Flog=5;
    }
    else
    {
        TCS3200_Pa_Pl_Flog=0;
    }
}

void TCS3200_Color_Recognition(void)//��ɫʶ��
{
    switch(Color_Flog)
    {
        case 0: TCS3200_Mode_Color(1);Color_Flog=1;break;//�����,��һ���ж�ȡ����ֵ
        case 1: Color_RGB[0]=(Color_Num*255/RGB[0]);Color_Flog=2;TCS3200_Mode_Color(2); break;//ȡ��ɫ����ֵ,���̵�
        case 2: Color_RGB[1]=(Color_Num*255/RGB[1]);Color_Flog=3;TCS3200_Mode_Color(3); break;//ȡ��ɫ����ֵ,������
        case 3: Color_RGB[2]=(Color_Num*255/RGB[2]);Color_Flog=0;TCS3200_Mode_Color(0); break;//ȡ��ɫ����ֵ,�ص�
        default:TCS3200_Mode_Color(0);Color_Flog=0;
    }
    Color_Num=0;
}

void TCS3200_White_balance(void)//1��� 0�쳣
{
    
    switch(Color_Flog)
    {
        case 0: TCS3200_Mode_Color(1);Color_Flog=1;break;//�����,��һ���ж�ȡ����ֵ
        case 1: RGB[0]=Color_Num; Color_Flog=2; TCS3200_Mode_Color(2);  break;//ȡ��ɫ����ֵ,���̵�
        case 2: RGB[1]=Color_Num; Color_Flog=3; TCS3200_Mode_Color(3);  break;//ȡ��ɫ����ֵ,������
        case 3: RGB[2]=Color_Num; Color_Flog=4; TCS3200_Mode_Color(0);  break;//ȡ��ɫ����ֵ,�ص�
        case 4: TCS3200_Mode_Color(0);White_balance_Flog=1;Color_Flog=0;break;//��ɰ�ƽ��,��־λ��1
        default:TCS3200_Mode_Color(0);Color_Flog=0;White_balance_Flog=0;
    }
    Color_Num=0;
}

void TCS3200_Mode(u8 TCS3200_Mode)
{
    switch(TCS3200_Mode)
    {
        case 0:     S0(0);S1(0);      break;//�ϵ�
        case 2:     S0(0);S1(1);      break;//2%
        case 20:    S0(1);S1(0);      break;//20%
        case 100:   S0(1);S1(1);      break;//100%
        default:    S0(0);S1(0);
    }

}

void TCS3200_Mode_Color(u8 TCS3200_Color_Mode)
{

    switch(TCS3200_Color_Mode)
    {
        case 0:     S2(1); S3(0);      break;//͸��
        case 1:     S2(0); S3(0);      break;//��
        case 2:     S2(1); S3(1);      break;//��
        case 3:     S2(0); S3(1);      break;//��
        default:    S2(1); S3(0);
    }
}
