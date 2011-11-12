/*******************************************************************************
* @file MiniDrive.cpp
* @author James Anderson <jra798>
* @date 11/11/2011
* @version 1.0
* @brief mini_drive class to controll mini_primes motors
******************************************************************************/


#include "MiniDrive.h"

MiniDrive::MiniDrive()
{
    //initialize vector
    for (int i = 0; i < 3; i++)
    {
        Wheel temp;
        wheels.push_back(temp);
    }
    
    wheels[1].pos_x = WHEEL_1_POS_X;
    wheels[1].pos_y = WHEEL_1_POS_Y;
    wheels[1].cent_val = WHEEL_1_CENT_VAL*M_PI/180;
    
    wheels[2].pos_x = WHEEL_2_POS_X;
    wheels[2].pos_y = WHEEL_2_POS_Y;
    wheels[2].cent_val = WHEEL_2_CENT_VAL*M_PI/180;
    
    wheels[3].pos_x = WHEEL_3_POS_X;
    wheels[3].pos_y = WHEEL_3_POS_Y;
    wheels[3].cent_val = WHEEL_3_CENT_VAL*PI/180;
    
    //initalize other globals
    servo_range = DEG_RANGE;
    
    //pre calculate som parameters for rotation
    for(int i = 0; i < wheels.size(); i++)
    {
        float  rot_ang;
        
        //get the angle of the wheel when it is tangent to the center of the robot
        rot_ang = atan2(wheels[i].pos_x, wheels[i].pos_y) + (M_PI/2);
        
        //calcutlate the x and y percents to make faster
        wheels[i].x_rot_per = cos(rot_ang);
        wheels[i].y_rot_per = sin(rot_ang);
        
        //calculate radius from the center of the robot
        wheels[i].diameter = hypot(wheels[i].pos_x, wheels[i].pos_y) * 2;
        
    }
    
    //get max componet velocities
    max_vel_x = MAX_SPEED * sin(PI/2);
    max_vel_y = max_vel_x;
    
}


void MiniDrive::SetVel(float x, float y, float yaw)
{
    //calculate the x and y movement vectors
    /////////////////////////////////////////
    float speed_percent, per_vel_x, per_vel_y;
    
    
    //calculate the percentage scalar of velocity we can obtain
    speed_percent = MAX_SPEED / hypot( x, y);
    
    //calculate percent of total motor speed 
    per_vel_x = max_vel_x * speed_percent;
    per_vel_y = max_vel_y * speed_percent;
    
    
    for(int i = 0; i < wheels.size(); i++)
    {
        //enter velocities as percentage of max speed
        
    }
    
    //calculate the x and y rotation vectors
    /////////////////////////////////////////
    
    for(int i = 0; i < wheels.size(); i++)
    {
        //calculate the speed the wheel has to move at for the desired rotation
        wheels[i].rot_speed = (wheels[i].diameter * M_PI) * (yaw/(2*M_PI));
        
        //calculate the x and y componet vectors of movement
        wheels[i].rot_x = wheels[i].rot_speed * wheels[i].x_rot_per;
        wheels[i].rot_y = wheels[i].rot_speed * wheels[i].y_rot_per;
    }
    
    //scale values to hardware limits
    /////////////////////////////////
    
    //controll hardware
    ///////////////////
}


