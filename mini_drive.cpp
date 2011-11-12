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
    float speed_percent, max_vel_x, max_vel_y, per_vel_x, per_vel_y;
    
    
    //get max componet velocities
    max_vel_x = MAX_SPEED * sin(PI/2);
    max_vel_y = max_vel_x;
    
    //calculate the percentage scalar of velocity we can obtain
    speed_percent = MAX_SPEED / sqrt( x^2 + y^2)
    
    //calculate percent of total motor speed 
    per_vel_x = max_vel_x * speed_percent
    per_vel_y = max_vel_y * speed_percent
    
    
    
    for(int i; i < wheels.size(); i++)
    {
        //enter velocities as percentage of max speed
        wheels[i].vel_x = x / 
    }
}
