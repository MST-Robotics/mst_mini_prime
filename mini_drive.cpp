/*******************************************************************************
* @file mini_drive.cpp
* @author James Anderson <jra798>
* @date 11/11/2011
* @version 1.0
* @brief mini_drive class to controll mini_primes motors
******************************************************************************/


#include "mini_drive_common.h"

MiniDrive::MiniDrive()
{
    //initialize vector
    for (int i; i < 3; i++)
    {
        Wheel temp;
        wheels.push_back(temp);
    }
    
    wheels[1].pos_x = WHEEL_1_POS_X;
    wheels[1].pos_y = WHEEL_1_POS_Y;
    wheels[1].cent_val = WHEEL_1_CENT_VAL*PI/180;
    
    wheels[2].pos_x = WHEEL_2_POS_X;
    wheels[2].pos_y = WHEEL_2_POS_Y;
    wheels[2].cent_val = WHEEL_2_CENT_VAL*PI/180;
    
    wheels[3].pos_x = WHEEL_3_POS_X;
    wheels[3].pos_y = WHEEL_3_POS_Y;
    wheels[3].cent_val = WHEEL_3_CENT_VAL*PI/180;
    
    //initalize other globals
    servo_range = DEG_RANGE;
}

void MiniDrive::SetVel(float x, float y, float yaw)
{
    for(int i; i < wheels.size(); i++)
    {
        wheels[i].vel_x = 
    }
}
