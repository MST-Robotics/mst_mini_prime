#ifndef serialDriver_h
#define serialDriver_h

using namespace std;

class serialDriver
{
	public:
		serialDriver();
		~serialDriver();
		int initializeSerialPort(char port[]); //initialize the serial port
		int writeSerial(char *data, unsigned int size); //write data to the port
		int writeSerial(char *data[], unsigned int size); //write data to the port
		int readSerial(char *data); //read data from the port
		bool isOpen() {return m_open;} //tell the caller if the port is Open at the moment

	private:
//variables
		int fd_serial; //a system assigned int that identifies the port
		bool m_open;
};//end class

#endif
