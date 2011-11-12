#ifndef MINIDRIVE_H
#define MINIDRIVE_H
/*******************************************************************************
* @file MiniDrive.h
* @author James Anderson <jra798>
* @date 11/11/2011
* @version 1.0
* @brief h file for the mini_drive class to controll mini_primes motors
******************************************************************************/


#include "mini_drive_common.h"



class MiniDrive
{
    public:
        
        //initializer
        mini_drive();

        //set the robots x y and rotational velocities
        void SetVel(float x, float y, float yaw); 

        
    private:
        
        //struct to hold 
        struct Wheel
        {
            //parameters
            float pos_x;
            float pos_y;
            int cent_val;
            
            //calculated params
            float diameter;
            float x_rot_per;
            float y_rot_per;
            
            //x and y movement values
            float move_x;
            float move_y;
            float move_speed;
            
            //x and y rotation values
            float rot_x;
            float rot_y
            float rot_speed;
            
            //x and y sum values
            float sum_x;
            float sum_y
            float sum_speed;
            
            //commands
            int cmd_vel;
            int cmd_yaw
        };
        
        //stores data for all three wheels
        vector <Wheel> wheels;
        
        float servo_range ;
        
        
        //max velocites
        float max_vel_x 
        float max_vel_y
        
        
};

#endif
