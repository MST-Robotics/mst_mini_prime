#ifndef MINI_DRIVE_H
#define MINI_DRIVE_H
/*******************************************************************************
* @file mini_drive.h
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
            

            //commands
            int cmd_x;
            int cmd_y;
            int cmd_yaw
        };
        
        //stores data for all three wheels
        vector <Wheel> wheels;
        
        float servo_range ;
        
        //velocities
        int vel_x;
        int vel_y;
        int vel_yaw;
        
};

#endif
