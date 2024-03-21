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

void TCS3200_Planning()//路径规划
{
    static int TCS3200_Num;
    
    if(TCS3200_Num==1)//第一次
    {
        switch(TCS3200_Pa_Pl_Flog)
        {
            case 1:Planning[0]=1;TCS3200_Num=2;break;
            case 2:Planning[0]=2;TCS3200_Num=2;break;
            case 3:Planning[0]=3;TCS3200_Num=2;break;
            case 4:Planning[0]=4;TCS3200_Num=2;break;
            case 5:Planning[0]=5;TCS3200_Num=2;break;
            case 0:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=1;break;
            default:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=1;
        }
    }
    else if(TCS3200_Num==2)//第二次
    {
        switch(TCS3200_Pa_Pl_Flog)
        {
            case 1:Planning[1]=1;TCS3200_Num=3;break;
            case 2:Planning[1]=2;TCS3200_Num=3;break;
            case 3:Planning[1]=3;TCS3200_Num=3;break;
            case 4:Planning[1]=4;TCS3200_Num=3;break;
            case 5:Planning[1]=5;TCS3200_Num=3;break;
            case 0:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=2;break;
            default:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=2;
        }
    }
    else if(TCS3200_Num==3)//第三次
    {
        switch(TCS3200_Pa_Pl_Flog)
        {
            case 1:Planning[2]=1;TCS3200_Num=4;break;
            case 2:Planning[2]=2;TCS3200_Num=4;break;
            case 3:Planning[2]=3;TCS3200_Num=4;break;
            case 4:Planning[2]=4;TCS3200_Num=4;break;
            case 5:Planning[2]=5;TCS3200_Num=4;break;
            case 0:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=3;break;
            default:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=3;
        }
    }
    else if(TCS3200_Num==4)//第四次
    {
        switch(TCS3200_Pa_Pl_Flog)
        {
            case 1:Planning[3]=1;TCS3200_Num=5;break;
            case 2:Planning[3]=2;TCS3200_Num=5;break;
            case 3:Planning[3]=3;TCS3200_Num=5;break;
            case 4:Planning[3]=4;TCS3200_Num=5;break;
            case 5:Planning[3]=5;TCS3200_Num=5;break;
            case 0:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=4;break;
            default:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=4;
        }
    }
    else if(TCS3200_Num==5)//第五次
    {
        switch(TCS3200_Pa_Pl_Flog)
        {
            case 1:Planning[4]=1;TCS3200_Num=5;break;
            case 2:Planning[4]=2;TCS3200_Num=5;break;
            case 3:Planning[4]=3;TCS3200_Num=5;break;
            case 4:Planning[4]=4;TCS3200_Num=5;break;
            case 5:Planning[4]=5;TCS3200_Num=5;break;
            case 0:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=5;break;
            default:TCS3200_Pa_Pl_Flog=0;TCS3200_Num=5;
        }
    }
}



/*0无 1白 2黑 3红 4绿 5蓝*/
void TCS3200_Determine()//判断颜色
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
    if(White_balance_Flog==1)//白平衡结束
    {
        if(TCs3200_ON_Flog==1)//开启颜色识别
        {
            TCS3200_Color_Recognition();//颜色识别
        }
    }
    else
    {
        TCS3200_White_balance();//白平衡
    }
}


void TCS3200_Color_Re(void)//颜色识别底层
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
