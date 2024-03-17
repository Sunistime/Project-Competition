#include "SHOW.h"
//OLEDœ‘ æ’˚∫œ

void SHOW()
{
    OLED_ShowSignedNum(1,1,Encoder_Left,5);OLED_ShowSignedNum(1,7,Encoder_Right,5);
    OLED_ShowSignedNum(2,1,Motor_Left,5);OLED_ShowSignedNum(2,7,Motor_Right,5);
    OLED_ShowSignedNum(3,1,Target_Speed_L,5);OLED_ShowSignedNum(3,7,Target_Speed_R,5);
    OLED_ShowSignedNum(4,1,Angle_Left,3);OLED_ShowSignedNum(4,5,Angle_Right,3);
    OLED_ShowSignedNum(4,10,Trackflog,1);
}



