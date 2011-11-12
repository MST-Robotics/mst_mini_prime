/***********************************************************************
* Contains the class deffinition for the miniservo class. This class 
*	contains all the code required to drive miniprime
*
*
***********************************************************************/
#ifndef MINISERVO_H_
#define MINISERHO_H_

#include "serialDriver.h"
#include <iostream>

class miniservo 
{
	//holds the information for a wheel pod
	struct pod
	{
		//these two hold the motor numbers
		char rot;
		char drive;
		//these two hold the angle and speed of the pod
		char velocity;
		char angle;
	};
	
	public:
	//variables first
		struct pod[3]; //miniprime only has three pods
		
		//now functions
		miniservo () {sio.initializeSerialPort("/dev/ttyUSB2");}
		
		miniservo (char *serial) {sio.initializeSerialPort(serial);}
		
/***********************************************************************
* Function Name: setPod
* Purpose: sets the parameters of a pod and pushes them out the serial port
* Arguments: po - the pod to set the speed of; top - set the steering 
* 	motor or the driving motor; speed - the value to push out to the motor
* Returns: nothing
***********************************************************************/
	int setPod(int po, bool top, char speed); 
	
	private:
	
		serialDriver sio; //port to use for serial IO
/***********************************************************************
* Function Name: setParam (command 0)
* Purpose: sets the parameters of a servo 
* Arguments: servo - the number of the servo to set; command - the hex 
* 		value of the command to send. See the Pololou manual for more
* 		information on the Pololou protocol
*
* Returns: nothing
***********************************************************************/
		void setParam(char servo, char command); 
		
/***********************************************************************
* Function Name: setSpeed (command 1)
* Purpose: sets the speed at which a servo changes position
* Arguments: servo - the number of the servo to set; speed - this basically
* 		determines how long a servo pulse lasts and how many pulses will
* 		be used to change a position.
* Returns: nothing
***********************************************************************/
		void setSpeed(char servo, char speed); 

/***********************************************************************
* Function Name: setPosition (command 2 or 3)
* Purpose: commands the servo to move to a certian position. The caller
* 		sets the step resolution
* Arguments: servo - the number of the servo to set; pos - the position
* 	to set the motor to. If there are two bytes in there, then use
* 	command 4, else use command 3. The difference is resolution
* Returns: nothing
***********************************************************************/
		void setPosition(char servo, char pos[]); 	
		
/***********************************************************************
* Function Name: setAbsPosition (command 4)
* Purpose: sets the Absolution position of the servo (no offsets)
* Arguments: servo - the number of the servo to set; pos - the position
* 	to command the servo to move to. This ignores any offsets such as 
* 	the neutral position.
* Returns: nothing
***********************************************************************/
		void setAbsPosition(char servo, char pos[]); 		
		
/***********************************************************************
* Function Name: setNeutral (command 5)
* Purpose: sets the position where the servo controller considers the
* 		servo to be at neutral 
* Arguments: servo - the number of the servo to set; pos - the position
* 	to set as the servo neutral point. 
* Returns: nothing
***********************************************************************/
		void setNeutral(char servo, char pos[]);
};

#endif
