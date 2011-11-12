/***********************************************************************
* This file contains the code used to drive the pololu motor controller
*	on mini-prime. It can control up to 8 servos, but we only use 6.
*
*
*
***********************************************************************/
#include "miniservo.h"

using namespace std;

int miniservo::setPod(int po, bool top, char speed)
{
	if (po < 0 || po > 3) return -1; //let the caller know that the pod is out of range
	//now we can start setting parameters
	if (top) pod[po -1].angle = speed;
	else pod[po - 1].velocity = speed;
	
	//now that the new parameters are stored, its time to update the servos
	// the first byte contains the most significat bit. The next byte contains
	//the lower 7 bits. This is because the Pololu protocal dicatates that
	//the first bit of a character must be 0
	char temp[2];
	
	
}

void miniservo::setParam(char servo, char command)
{
	char *temp[5];
	*temp[0] = 0x80; //command start byte (see docs)
	*temp[1] = 0x01; //device id. We only have one, so the ID is 1
	*temp[2] = 0x00; //this is command 0 we are sending
	*temp[3] = servo; //the servo to set the parameters of
	*temp[4] = command; //the command to send the servo
	
	if (sio.isOpen()) sio.writeSerial(temp, 5);
	else cout << "Serial port closed. Can't write!" << endl;
}

void miniservo::setSpeed(char servo, char speed)
{
	char *temp[5];
	*temp[0] = 0x80; //command start byte (see docs)
	*temp[1] = 0x01; //device id. We only have one, so the ID is 1
	*temp[2] = 0x01; //this is command 1 we are sending
	*temp[3] = servo; //the servo to set the parameters of
	*temp[4] = speed; //the speed to rotate at 
	
	if (sio.isOpen()) sio.writeSerial(temp, 5);
	else cout << "Serial port closed. Can't write!" << endl;
}

void miniservo::setPosition(char servo, char pos[])
{
	char *temp[6];
	*temp[0] = 0x80; //command start byte (see docs)
	*temp[1] = 0x01; //device id. We only have one, so the ID is 1
	if ((sizeof(pos)/sizeof(char)) > 1 ) *temp[2] = 0x03;
	else *temp[2] = 0x02; //this is command 1 we are sending
	*temp[3] = servo; //the servo to set the parameters of
	*temp[4] = pos[0]; //the position to rotate to. Can be small or big value
	if ((sizeof(pos)/sizeof(char)) > 1 ) *temp[5] = pos[1];
	
	if (sio.isOpen() && (sizeof(pos)/sizeof(char)) > 1) sio.writeSerial(temp, 6);
	else if (sio.isOpen()) sio.writeSerial(temp, 5);
	else cout << "Serial port closed. Can't write!" << endl;
}

void miniservo::setAbsPosition(char servo, char pos[])
{
	char *temp[6];
	*temp[0] = 0x80; //command start byte (see docs)
	*temp[1] = 0x04; //device id. We only have one, so the ID is 1
	*temp[2] = 0x01; //this is command 1 we are sending
	*temp[3] = servo; //the servo to set the parameters of
	*temp[4] = pos[0]; //the position to rotate to (500 to 5500)
	*temp[5] = pos[1];
	
	if (sio.isOpen()) sio.writeSerial(temp, 6);
	else cout << "Serial port closed. Can't write!" << endl;
}

void miniservo::setNeutral(char servo, char pos[])
{
	char *temp[6];
	*temp[0] = 0x80; //command start byte (see docs)
	*temp[1] = 0x04; //device id. We only have one, so the ID is 1
	*temp[2] = 0x05; //this is command 1 we are sending
	*temp[3] = servo; //the servo to set the parameters of
	*temp[4] = pos[0]; //the position to set as neutral
	*temp[5] = pos[1];
	
	if (sio.isOpen()) sio.writeSerial(temp, 6);
	else cout << "Serial port closed. Can't write!" << endl;
}
