#ifndef MINI_DRIVE_COMMON_H
#define MINI_DRIVE_COMMON_H
/*******************************************************************************
* @file mini_drive_common.h
* @author James Anderson <jra798>
* @date 11/11/2011
* @version 1.0
* @brief define settings for mini prime drive
******************************************************************************/


//general includes bellow

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#include <vector>

//general defines
#define PI 3.14159265


//wheels are numbered starting from the front and rotating counter clockwise

#define WHEEL_1_POS_X           0   //x loction from center of rotation in meters
#define WHEEL_1_POS_Y           1   //y loction from center of rotation in meters
#define WHEEL_1_CENT_VAL        127   //pwm position of wheel at 0 yaw

#define WHEEL_2_POS_X           -0.5   //x loction from center of rotation in meters
#define WHEEL_2_POS_Y           -0.5   //y loction from center of rotation in meters
#define WHEEL_2_CENT_VAL        127   //pwm position of wheel at 0 yaw

#define WHEEL_3_POS_X           0.5   //x loction from center of rotation in meters
#define WHEEL_3_POS_Y           -0.5   //y loction from center of rotation in meters
#define WHEEL_3_CENT_VAL        127   //pwm position of wheel at 0 yaw

#define DEG_RANGE         180   //range of the rotation sevos in degrees



#endif
