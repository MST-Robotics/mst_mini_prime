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
        //mini_drive ();
        MiniDrive();

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
            float cent_ang;
            
            //range of rotation servo
            float servo_range;
            
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
            float rot_y;
            float rot_speed;
            
            //x and y sum values
            float sum_x;
            float sum_y;
            float sum_speed;
            
            //yaw angle
            float yaw_angle;
            
            //wire wraping states
            bool forward;
            float prev_yaw_rel;
            float prev_yaw_abs;
            float max_fwd_yaw;
            float min_fwd_yaw;
            float max_rev_yaw;
            float min_rev_yaw
            
            
            //commands
            int cmd_vel;
            int cmd_yaw;
        };
        
        //stores data for all three wheels
        std::vector<Wheel> wheels;
        
        
        

};

#endif
