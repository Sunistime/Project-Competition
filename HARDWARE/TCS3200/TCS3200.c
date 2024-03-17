#include "TCS3200.h"

void TCS3200_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能PA端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5; //端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);      //根据设定参数初始化GPIOA

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_4;     //端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);    //根据设定参数初始化GPIOB
    TCS3200_Mode(20);//20%
    TCS3200_Mode_Color(0);//透明(无过滤器)
    OE(0);//低电平有效
    TCS3200_EXTI_Init();
}

/*0无 1白 2黑 3红 4绿 5蓝*/
void TCS3200_Path_Planning()//路径规划 得到各个分路的值
{
    if(Color_RGB[0]>=235&&Color_RGB[0]<=255&&Color_RGB[1]>=235&&Color_RGB[1]<=255&&Color_RGB[2]>=235&&Color_RGB[2]<=255)//白
    {
        TCS3200_Pa_Pl_Flog=1;
    }
    else if(Color_RGB[0]>=10&&Color_RGB[0]<=50&&Color_RGB[1]>=10&&Color_RGB[1]<=50&&Color_RGB[2]>=10&&Color_RGB[2]<=50)//黑
    {
        TCS3200_Pa_Pl_Flog=2;
    }
    else if(Color_RGB[0]>=155&&Color_RGB[0]<=195&&Color_RGB[1]>=26&&Color_RGB[1]<=66&&Color_RGB[2]>=37&&Color_RGB[2]<=77)//红
    {
        TCS3200_Pa_Pl_Flog=3;
    }
    else if(Color_RGB[0]>=25&&Color_RGB[0]<=65&&Color_RGB[1]>=70&&Color_RGB[1]<=110&&Color_RGB[2]>=53&&Color_RGB[2]<=93)//绿
    {
        TCS3200_Pa_Pl_Flog=4;
    }
    else if(Color_RGB[0]>=26&&Color_RGB[0]<=66&&Color_RGB[1]>=39&&Color_RGB[1]<=79&&Color_RGB[2]>=73&&Color_RGB[2]<=113)//蓝
    {
        TCS3200_Pa_Pl_Flog=5;
    }
    else
    {
        TCS3200_Pa_Pl_Flog=0;
    }
}

void TCS3200_Color_Recognition(void)//颜色识别
{
    switch(Color_Flog)
    {
        case 0: TCS3200_Mode_Color(1);Color_Flog=1;break;//开红灯,下一次中断取计数值
        case 1: Color_RGB[0]=(Color_Num*255/RGB[0]);Color_Flog=2;TCS3200_Mode_Color(2); break;//取红色计数值,开绿灯
        case 2: Color_RGB[1]=(Color_Num*255/RGB[1]);Color_Flog=3;TCS3200_Mode_Color(3); break;//取绿色计数值,开蓝灯
        case 3: Color_RGB[2]=(Color_Num*255/RGB[2]);Color_Flog=0;TCS3200_Mode_Color(0); break;//取蓝色计数值,关灯
        default:TCS3200_Mode_Color(0);Color_Flog=0;
    }
    Color_Num=0;
}

void TCS3200_White_balance(void)//1完成 0异常
{
    
    switch(Color_Flog)
    {
        case 0: TCS3200_Mode_Color(1);Color_Flog=1;break;//开红灯,下一次中断取计数值
        case 1: RGB[0]=Color_Num; Color_Flog=2; TCS3200_Mode_Color(2);  break;//取红色计数值,开绿灯
        case 2: RGB[1]=Color_Num; Color_Flog=3; TCS3200_Mode_Color(3);  break;//取绿色计数值,开蓝灯
        case 3: RGB[2]=Color_Num; Color_Flog=4; TCS3200_Mode_Color(0);  break;//取蓝色计数值,关灯
        case 4: TCS3200_Mode_Color(0);White_balance_Flog=1;Color_Flog=0;break;//完成白平衡,标志位置1
        default:TCS3200_Mode_Color(0);Color_Flog=0;White_balance_Flog=0;
    }
    Color_Num=0;
}

void TCS3200_Mode(u8 TCS3200_Mode)
{
    switch(TCS3200_Mode)
    {
        case 0:     S0(0);S1(0);      break;//断电
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
        case 0:     S2(1); S3(0);      break;//透明
        case 1:     S2(0); S3(0);      break;//红
        case 2:     S2(1); S3(1);      break;//绿
        case 3:     S2(0); S3(1);      break;//蓝
        default:    S2(1); S3(0);
    }
}
