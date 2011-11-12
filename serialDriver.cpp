/******************************************************************************************
* The purpose of this class is to handle interactions with the serial ports. It has nothing
*	special in it. Is is simply a serail port driver. It allows other code to read and 
*	write to the serial port
*
*	Author: Daniel Peterson
*	Version 1.0 11/23/09
********************************************************************************************/
#include "serialDriver.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

using namespace std;

/********************************************************************************************
* Function Name: serialDriver
* Purpose: constructor for this class
* Arguments: none
* Returns: nothing
*********************************************************************************************/
serialDriver::serialDriver(void)
{
	m_open = false;
}

/********************************************************************************************
* Function Name: ~serialDriver
* Purpose: destructor for this class
* Arguments: none
* Returns: nothing
*********************************************************************************************/
serialDriver::~serialDriver(void)
{
	m_open = false; //pointless, but does get the point accross
	close(fd_serial); //close the file discriptor when we are destroyed
}

/********************************************************************************************
* Function Name: initialize
* Purpose: does the actual initialization of the port
* Arguments: port - the port to initialize
* Returns: 1 on success
*********************************************************************************************/
int serialDriver::initializeSerialPort(char port[])
{
	struct termios tty;
	struct termios oldtty;

try{	
	cout << "Creating Serial Port\n" << flush;
	const char* p = port;
	fd_serial = open(p, O_RDWR | O_NOCTTY | O_NONBLOCK); //try to open the serial port
	cout << "Got File Descriptor\n" << flush;
	if (fd_serial < 0) { //if opening the port was unsuccessful, print the error to the console line and exit
		printf("Error opening the port\n"); //say where the error occured
		perror(port); //print the error
		throw port;
	}

	tcgetattr(fd_serial, &oldtty); //save the previous port settings so the computer doesn't complain
	bzero(&tty, sizeof(tty)); //make sure the new structure is actually clear
	//lets set the new port settings
	/**
	* B19200 = Baud 19200
	* CS8 = 8N1
	* CLOCAL = no modem control. We control the port directly
	* CREAD = enable recieving characters
	**/
	tty.c_cflag = B19200 | CS8 | CLOCAL | CREAD;
	/**
	* ICRNL = map a carriage return to the new line character so when a return is sent, a new line is too
	**/
	tty.c_iflag = ICRNL;
	tty.c_oflag = 0; //set output to raw only
	tty.c_lflag = ICANON; //disable echo
	
	int err = tcflush(fd_serial, TCIFLUSH); //flush the old settings
	if (err < 0) cout << "Error flushing old settings" << flush;

	err = tcsetattr(fd_serial, TCSANOW, &tty); //apply the new settings to the port
	if (err < 0) cout << "Error applying new serial port settings" << flush;
	m_open = true;

	cout << "Serial Port Ready: " << fd_serial << "\n" << flush;
} //end try
catch(...) {
	cout << "There was an error initializing the port\n" << flush;
	return -1;
}// end catch
}//=====================================================
/********************************************************************************************
* Function Name: readSerial
* Purpose: reads a byte from the serail port
* Arguments: data - a pointer to a character array to write to in memory
* Returns: nothing
*********************************************************************************************/
int serialDriver::readSerial(char *data)
{
try
{
	int t = read(fd_serial, data, 1);
	if (t < 0) return -1;
	return 1;
}
catch(...){cout <<"Error reading port\n" << flush;}
}//======================================================
/********************************************************************************************
* Function Name: writeSerial
* Purpose: writes a byte 
* Arguments: data - the byte of data to write
* Returns: 1 on success
*********************************************************************************************/
int serialDriver::writeSerial(char *data, unsigned int size )
{
try
{	
	int err = write(fd_serial, data, size);
	if (err < 0) {cout << "Error writing to the port"; return -1;}
	return 1;
}
catch(...){cout << "Error writing: " << strerror(errno) << "\n" <<  flush; return -1;}
}//=======================================================
/********************************************************************************************
* Function Name: writeSerial
* Purpose: writes a byte 
* Arguments: data - the byte of data to write
* Returns: 1 on success
*********************************************************************************************/
int serialDriver::writeSerial(char *data[], unsigned int size )
{
try
{	
	for (int i = 0; i < size; i++) 
	{
		int err = write(fd_serial, data[i],1);
		if (err < 0) {cout << "Error writing to the port"; return -1;}
	}
	return 1;
}
catch(...){cout << "Error writing: " << strerror(errno) << "\n" <<  flush; return -1;}
}//=======================================================
