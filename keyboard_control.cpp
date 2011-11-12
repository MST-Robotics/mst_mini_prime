/*******************************************************************************
* @file keyboard_control.cpp
* @author James Anderson <jra798> addapted from Aluminator keydrive by Goldman
* @date 11/11/2011
* @version 1.0
* @brief keyboard controll for mini prime
******************************************************************************/
/*This file is the keyboard remote controlls for MiniPrime
  This will allow you to move the robot using 

  W - Forward
  A - Left
  S - Backward
  D - Right
  > - Turn Right
  < - Turn Left
  SPACE - All stop

  These commands will run until the next command is entered

*/

#include <ncurses.h>
#include "MiniDrive.h"
#include <signal.h>
#include <time.h>
#include <unistd.h>
#define SOME_TIME_FACTOR .02
//These are the defines for setting speeds
#define X_SPEED 0.1
#define Y_SPEED 0.1
#define ROTATE 0.25
#define TIMEOUT 0.1

using namespace std;

int keys;
int keybuffer;
double xVel =0;
double yVel =0;
double rotVel =0;
bool quitProgram = false;
clock_t xTimeout;
clock_t yTimeout;
clock_t rotTimeout;


void ExitProgram(int dummy)
{
	dummy=0;
	quitProgram = true;
}

int rgetch()
{
	int temp1=ERR;
	int temp2=ERR;
	do
	{
		temp1=temp2;
		temp2=getch();
	}while(temp2!=ERR);
	return temp1;
}

int main()
{       
	signal( SIGINT, ExitProgram );
        initscr();                      /* Start curses mode              */
	printw("yo");
	noecho();
        printw("Remote Control Robot!\n");
        refresh();//update screen
	cbreak();
	nodelay(stdscr, TRUE);
	MiniDrive control;
	while(!quitProgram)
	{
		usleep(200000);
		keys=rgetch();
		clear();
		
		//xVel = 0;
		//yVel = 0;
		//rotVel = 0;
		
		//code for x direction
		if(keys=='w' || keys=='W')
		{
			printw("Moving Forward\n");
			xVel = X_SPEED;
			xTimeout = clock() + TIMEOUT * CLOCKS_PER_SEC;
		}
		else if(keys=='s' || keys=='S')
		{
			printw("Moving Backward\n");
			xVel= -X_SPEED;
			xTimeout = clock() + TIMEOUT * CLOCKS_PER_SEC;
		}
		else
		{
			if(xTimeout < clock())
			{
				xVel = 0;
			}
		}
		
		//code for y direction
		if(keys=='a' || keys=='A')
		{
			printw("Moving Left\n");
			yVel = Y_SPEED;
			yTimeout = clock() + TIMEOUT * CLOCKS_PER_SEC;
		}
		else if(keys=='f' || keys=='F')
		{
			printw("Moving Right\n");
			yVel= -Y_SPEED;
			yTimeout = clock() + TIMEOUT * CLOCKS_PER_SEC;
		}
		else
		{
			if(yTimeout < clock())
			{
				yVel = 0;
			}
		}
		
		//code for y direction
		if(keys==',' || keys=='<')
		{
			printw("Moving Left\n");
			rotVel = ROTATE;
			rotTimeout = clock() + TIMEOUT * CLOCKS_PER_SEC;
		}
		else if(keys=='.' || keys=='>')
		{
			printw("Moving Right\n");
			rotVel= -ROTATE;
			rotTimeout = clock() + TIMEOUT * CLOCKS_PER_SEC;
		}
		else
		{
			if(rotTimeout < clock())
			{
				rotVel = 0;
			}
		}
		
		if(keys!=ERR)
		{
			printw("stopping\n");
			xVel=0;
			yVel=0;
			rotVel=0;
		}
		
		printw("Keyboard Commands\n");
		printw("w = forward\n");
		printw("s = backward\n");
		printw("a = left\n");
		printw("d = right\n");
		printw("< = rotate left\n");
		printw("> = rotate right\n");
		printw("SPACE = stop\n");
		printw("ctrl + c = exit\n");
		
		printw("speed:\tFoward: %f\tLeft: %f\tRotate:%f",xVel,yVel,rotVel);
		control.SetVel(xVel, yVel, rotVel);
	}

        endwin();
        return 0;
}
