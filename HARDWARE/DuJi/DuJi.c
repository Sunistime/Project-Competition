#include "DuJi.h"

void DuoJi_Init()//舵机初始化 PWM初始化 和各个舵机归位
{
    DuoJi_PWM_Init();
    
    WuZhua_DUOJI(0);    //五爪大舵机控制
    WuZhua_Duoji_1(0);  //五爪小舵机1抬起
    WuZhua_Duoji_2(0);  //五爪小舵机2抬起
    WuZhua_Duoji_3(0);  //五爪小舵机3抬起
    WuZhua_Duoji_4(0);  //五爪小舵机4抬起
    WuZhua_Duoji_5(0);  //五爪小舵机5抬起
    TaoTong_DUOJI(0);   //套筒大舵机控制
    TaoTong_Duoji(0);   //套筒小舵机控制
    
}

//舵机控制
//DUOJI_Flog = 2 五爪大舵机左转144度    duoji_Flog = 1 五爪小舵机1落下
//DUOJI_Flog = 1 五爪大舵机左转72度     duoji_Flog = 2 五爪小舵机2落下
//DUOJI_Flog = 0 五爪大舵机不动         duoji_Flog = 3 五爪小舵机3落下
//DUOJI_Flog =-1 五爪大舵机右转72度     duoji_Flog = 4 五爪小舵机4落下
//DUOJI_Flog =-2 五爪大舵机右转144度    duoji_Flog = 5 五爪小舵机5落下
void DuoJi_Control(short DUOJI_Flog,short duoji_Flog)
{
    if(DUOJI_ON_Flog==1)//舵机总开关开启
    {
        if(DUOJI_Flog==0)//大舵机不动
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==1)//大舵机左转72度
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==2)//大舵机左转144度
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==-1)//大舵机右转72度 
        {
            duoji_Control(duoji_Flog);
        }
        else if(DUOJI_Flog==-2)//大舵机右转144度
        {
            duoji_Control(duoji_Flog);
        }
    }
}

void duoji_Control(short duoji_Flog)//五爪小舵机控制
{
    if(duoji_Flog==1)//五爪小舵机1落下
    {
        WuZhua_Duoji_1(150);
        delay_ms(500);//延时一般500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==2)//五爪小舵机2落下
    {
        WuZhua_Duoji_2(150);
        delay_ms(500);//延时一般500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==3)//五爪小舵机3落下
    {
        WuZhua_Duoji_3(150);
        delay_ms(500);//延时一般500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==4)//五爪小舵机4落下
    {
        WuZhua_Duoji_4(150);
        delay_ms(500);//延时一般500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
    else if(duoji_Flog==5)//五爪小舵机5落下
    {
        WuZhua_Duoji_5(150);
        delay_ms(500);//延时一般500ms
        DUOJI_ON_Flog=0;DUOJI_OFF_Flog=1;
    }
}











void DuoJi_PWM_Init()
{
    //舵机pwm初始化,引脚不够没写
}

void WuZhua_DUOJI(uint16_t Compare)//五爪大舵机控制
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_1(uint16_t Compare)//五爪小舵机1控制
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_2(uint16_t Compare)//五爪小舵机2控制
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_3(uint16_t Compare)//五爪小舵机3控制
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_4(uint16_t Compare)//五爪小舵机4控制
{
    //(Compare / 180 * 2000 + 500)
}

void WuZhua_Duoji_5(uint16_t Compare)//五爪小舵机5控制
{
    //(Compare / 180 * 2000 + 500)
}

void TaoTong_DUOJI(uint16_t Compare)//套筒大舵机控制
{
    //(Compare / 180 * 2000 + 500)
}

void TaoTong_Duoji(uint16_t Compare)//套筒小舵机控制
{
    //(Compare / 180 * 2000 + 500)
}









