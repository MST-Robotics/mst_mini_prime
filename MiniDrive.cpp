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
    wheels[3].cent_val = WHEEL_3_CENT_VAL*M_PI/180;
    
    //initalize other globals
    servo_range = DEG_RANGE;
    
    //pre calculate som parameters for rotation
    for(int i = 0; i < wheels.size(); i++)
    {
        float  rot_ang;
        
        //get the angle of the wheel when it is tangent to the center of the robot
        rot_ang = atan2(wheels[i].pos_y, wheels[i].pos_x) + (M_PI/2);
        
        //calcutlate the x and y percents to make faster
        wheels[i].x_rot_per = cos(rot_ang);
        wheels[i].y_rot_per = sin(rot_ang);
        
        //calculate radius from the center of the robot
        wheels[i].diameter = hypot(wheels[i].pos_x, wheels[i].pos_y) * 2;
        
    }
    
    //get max componet velocities
    max_vel_x = MAX_WHEEL_SPEED * sin(M_PI/2);
    max_vel_y = max_vel_x;
    
}


void MiniDrive::SetVel(float x_in, float y_in, float yaw_in)
{
    float fastest_wheel_speed = 0;
    float speed_scaler;
    //TODO most of these loops can be combined
    
    //calculate the x and y movement vectors in m/s
    for(int i = 0; i < wheels.size(); i++)
    {
        //calculate velocities as percentage of max speed
        wheels[i].move_x = x_in;
        wheels[i].move_y = y_in;
        wheels[i].move_speed = hypot(x_in, y_in);
    }
    
    //calculate the x and y rotation vectors in m/s
    for(int i = 0; i < wheels.size(); i++)
    {
        //calculate the speed the wheel has to move at for the desired rotation
        wheels[i].rot_speed = (wheels[i].diameter * M_PI) * (yaw_in/(2*M_PI));
        
        //calculate the x and y componet vectors of movement
        wheels[i].rot_x = wheels[i].rot_speed * wheels[i].x_rot_per;
        wheels[i].rot_y = wheels[i].rot_speed * wheels[i].y_rot_per;
    }
    
    //add componets to get the total componts
    for(int i = 0; i < wheels.size(); i++)
    {
        //calculate the sume of the vector componets
        wheels[i].sum_x = wheels[i].move_x + wheels[i].rot_x;
        wheels[i].sum_y = wheels[i].move_y + wheels[i].rot_y;
        
        //calculate the speeds 
        wheels[i].sum_speed = hypot(wheels[i].sum_x, wheels[i].sum_y);
        
        //get fastest wheel speed
        if (wheels[i].sum_speed > fastest_wheel_speed)
        {
            fastest_wheel_speed = wheels[i].sum_speed;
        }
    }
    
    //get scaler to bring wheels to limits
    if(fastest_wheel_speed > MAX_WHEEL_SPEED)
    {
        speed_scaler = MAX_WHEEL_SPEED/fastest_wheel_speed;
        
        //scale wheels to limits
        for(int i = 0; i < wheels.size(); i++)
        {
            //scale the values
            wheels[i].sum_x = wheels[i].sum_x * speed_scaler;
            wheels[i].sum_y = wheels[i].sum_y * speed_scaler;
        }
    }
    
    //find the velocity commands
    for(int i = 0; i < wheels.size(); i++)
    {
        //find the yaw angle for each wheel
        wheels[i].yaw_angle = atan2(wheels[i].sum_y, wheels[i].sum_x);
        
        //figure out what wire wraping state we are in 
        if(wheels[i].forward)
        {
            //wheel wrap state forward
            
        }
        else
        {
            //wheel wrap state reverce
            
        }
        
        //find the speed for each wheel 
        wheels[i].cmd_vel = CMD_MAX * (hypot(wheels[i].sum_x, wheels[i].sum_y) / MAX_WHEEL_SPEED);
    }
    
    //find rotation commands accounting for motor limitations
    for(int i = 0; i < wheels.size(); i++)
    {
        //TODO need to set two halves of rotation states up in initialize then
        //depending on the state move the motor to the corect position to match
        //the yaw that I need to calculate in one of the previous steps then check
        //to see if it would be faster to switch states and run the motor backward
        //bellow I also need to take these commands and pipe them into the serial driver
        //its 2:31 and thats alot of work so im going to bed sorry Daniel 
        
    }
    
}


