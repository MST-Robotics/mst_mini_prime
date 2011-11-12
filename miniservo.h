/***********************************************************************
* Contains the class deffinition for the miniservo class. This class 
*	contains all the code required to drive miniprime
*
*
***********************************************************************/

class miniservo 
{
	struct pod
	{
		char rot = 0;
		char drive = 0;
	}
	
	public:
	//variables first
		char sio[] = ""; //holds the string for the serial controller we are using
		
		struct pod p1, p2, p3; //miniprime only has three pods
		
		//now functions
		miniservo () {sio  = "/dev/ttyUSB2"}
		
		miniservo (const char serial)
		{
			sio = serial;
			
		}
		
		//set the speed/position of a pod
		setPod(int po, bool top, char speed); 
	
	private:
		setSpeed(char servo, 
	
}
