#include "Track.h"

void TrackInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能PA端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4|GPIO_Pin_3|GPIO_Pin_2; //端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);      //根据设定参数初始化GPIOA

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_3|GPIO_Pin_1|GPIO_Pin_0|GPIO_Pin_4|GPIO_Pin_10|GPIO_Pin_11;//端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
    GPIO_Init(GPIOB, &GPIO_InitStructure);    //根据设定参数初始化GPIOB
}


//void Tracking_Forward()//前进循迹，到达米字不停止
//{
//    if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//中间黑线 前进
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
//    }
//    if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//中间白线 前进
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
//    }
//    else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//全白 慢前进
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
//    }
//    else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//全黑 慢前进
//    {
//        Trackflog=1;
//        Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
//    }
//    else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//左出现黑线 左转前进
//    {
//        Trackflog=2;
//        Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
//    }
//    else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//右出现黑线 右转前进
//    {
//        Trackflog=3;
//        Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
//    }
//}

//void Tracking_Back()//后退循迹，到达米字不停止
//{
//    if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//中间黑线 后退
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
//    }
//    if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//中间白线 后退
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
//    }
//    else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//全白 慢后退
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
//    }
//    else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//全黑 慢后退
//    {
//        Trackflog=-1;
//        Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
//    }
//    
//    else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//左出现黑线 左转后退
//    {
//        Trackflog=-2;
//        Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
//    }
//    else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//右出现黑线 右转后退
//    {
//        Trackflog=-3;
//        Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
//    }
//}

void Tracking_1(uint8_t trackflog)//前进后退循迹到达米字停止 1前进 0后退
{
    if(HuiDu_L_2==Hei && HuiDu_L_3==Hei && HuiDu_R_2==Hei && HuiDu_R_3==Hei)//停止
    {
        Trackflog=0;
        Target_Speed_L = 0;Target_Speed_R = 0;
        Miflog=1;
    }
    else//移动
    {
        Miflog=0;
        if(trackflog==1)//前进
        {
            if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//中间黑线 前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//中间白线 前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//全白 慢前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//全黑 慢前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//左出现黑线 左转前进
            {
                Trackflog=2;
                Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//右出现黑线 右转前进
            {
                Trackflog=3;
                Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
            }
        }
        else if(trackflog==0)//后退
        {
            if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//中间黑线 后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//中间白线 后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//全白 慢后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
            }
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//全黑 慢后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
            }
            
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//左出现黑线 左转后退
            {
                Trackflog=-2;
                Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//右出现黑线 右转后退
            {
                Trackflog=-3;
                Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
            }
        }
    }
}

void Tracking_2(uint8_t trackflog)//前进后退循迹全点位都不停止 1前进 0后退
{

    if(trackflog==1)//前进
    {
        if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//中间黑线 前进
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
        }
        if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//中间白线 前进
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
        }
        else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//全白 慢前进
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
        }
        else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//全黑 慢前进
        {
            Trackflog=1;
            Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
        }
        else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//左出现黑线 左转前进
        {
            Trackflog=2;
            Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
        }
        else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//右出现黑线 右转前进
        {
            Trackflog=3;
            Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
        }
    }
    else if(trackflog==0)//后退
    {
        if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//中间黑线 后退
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
        }
        if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//中间白线 后退
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
        }
        else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//全白 慢后退
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
        }
        else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//全黑 慢后退
        {
            Trackflog=-1;
            Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
        }
        
        else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//左出现黑线 左转后退
        {
            Trackflog=-2;
            Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
        }
        else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//右出现黑线 右转后退
        {
            Trackflog=-3;
            Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
        }
    }
}
            
void Tracking_3(uint8_t trackflog)//前进后退循迹到达放物块点位停止 1前进 0后退
{
    if(trackflog==1)//前进
    {
        if(HuiDu_L_1==Hei && HuiDu_R_1==Hei && HuiDu_L_3==Bai && HuiDu_R_3==Bai && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//停止
        {
            Trackflog=0;
            Target_Speed_L = 0;Target_Speed_R = 0;
            DanWu_flog=1;
        }
        else
        {
            DanWu_flog=0;
            if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//中间黑线 前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//中间白线 前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//全白 慢前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//全黑 慢前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//左出现黑线 左转前进
            {
                Trackflog=2;
                Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//右出现黑线 右转前进
            {
                Trackflog=3;
                Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
            }
        }
    }
    else if(trackflog==0)//后退
    {
        if(HuiDu_L_3==Hei && HuiDu_R_3==Hei && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//停止
        {
            Trackflog=0;
            Target_Speed_L = 0;Target_Speed_R = 0;
            DanWu_flog=1;
        }
        else
        {
            if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//中间黑线 后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//中间白线 后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//全白 慢后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
            }
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//全黑 慢后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
            }
            
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//左出现黑线 左转后退
            {
                Trackflog=-2;
                Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//右出现黑线 右转后退
            {
                Trackflog=-3;
                Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
            }
        }
    }
}

void Tracking_4(uint8_t trackflog)//在放物块点位启动，在欲放物块点位停止 1前进 0后退
{
    if(trackflog==1)//前进
    {
        if(HuiDu_L_1==Hei && HuiDu_R_1==Hei && HuiDu_L_3==Bai && HuiDu_R_3==Bai && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//前进
        {
            Trackflog=0;
            Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            DanWu_flog--;
            
        }
        else
        {
            DanWu_flog=0;
            if(HuiDu_A_L==Bai && HuiDu_A_M==Hei && HuiDu_A_R==Bai)//中间黑线 前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//中间白线 前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_A_L;Target_Speed_R = ZhiZou_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//全白 慢前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Hei && HuiDu_A_R==Hei)//全黑 慢前进
            {
                Trackflog=1;
                Target_Speed_L = ZhiZou_Man_A_L;Target_Speed_R = ZhiZou_Man_A_R;
            }
            else if(HuiDu_A_L==Hei && HuiDu_A_M==Bai && HuiDu_A_R==Bai)//左出现黑线 左转前进
            {
                Trackflog=2;
                Target_Speed_L = ZuoZhuan_A_L;Target_Speed_R = ZuoZhuan_A_R;
            }
            else if(HuiDu_A_L==Bai && HuiDu_A_M==Bai && HuiDu_A_R==Hei)//右出现黑线 右转前进
            {
                Trackflog=3;
                Target_Speed_L = YouZhuan_A_L;Target_Speed_R = YouZhuan_A_R;
            }
        }
    }
    else if(trackflog==0)//后退
    {
        if(HuiDu_L_3==Hei && HuiDu_R_3==Hei && HuiDu_L_2==Bai && HuiDu_R_2==Bai)//停止
        {
            Trackflog=0;
            Target_Speed_L = 0;Target_Speed_R = 0;
            DanWu_flog=1;
        }
        else
        {
            if(HuiDu_B_L==Bai && HuiDu_B_M==Hei && HuiDu_B_R==Bai)//中间黑线 后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//中间白线 后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_B_L;Target_Speed_R = ZhiZou_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//全白 慢后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L; Target_Speed_R = ZhiZou_Man_B_R;
            }
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Hei && HuiDu_B_R==Hei)//全黑 慢后退
            {
                Trackflog=-1;
                Target_Speed_L = ZhiZou_Man_B_L;Target_Speed_R = ZhiZou_Man_B_R;
            }
            
            else if(HuiDu_B_L==Hei && HuiDu_B_M==Bai && HuiDu_B_R==Bai)//左出现黑线 左转后退
            {
                Trackflog=-2;
                Target_Speed_L = ZuoZhuan_B_L;Target_Speed_R = ZuoZhuan_B_R;
            }
            else if(HuiDu_B_L==Bai && HuiDu_B_M==Bai && HuiDu_B_R==Hei)//右出现黑线 右转后退
            {
                Trackflog=-3;
                Target_Speed_L = YouZhuan_B_L;Target_Speed_R = YouZhuan_B_R;
            }
        }
    }
}
