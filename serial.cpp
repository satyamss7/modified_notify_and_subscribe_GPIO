//https://github.com/gbmhunter/CppLinuxSerial
//$g++ serial.cpp -lCppLinuxSerial -o serial.o
//$./serial.o
//For compiling with threads
//g++ serial.cpp -lCppLinuxSerial -o serial.o -pthread
#include <CppLinuxSerial/SerialPort.hpp>
#include <iostream>
#include <string>
#include <iterator>
#include <cstring>
#include <thread>
#include <unistd.h>
#include "serialprt.hpp"
using namespace mn::CppLinuxSerial;
using std::cout;
char tmpbuf[512];
using namespace std;
int serial_1(char *readbuff);
SerialPort serialPort("/dev/ttyUSB0", BaudRate::B_115200, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
#if 0
int serial_1(char *readbuff)
{
	// Create serial port object and open serial port at 57600 buad, 8 data bits, no parity bit, and one stop bit (8n1)
	//char tempBuff[64] = {'\0'};
	SerialPort serialPort("/dev/ttyUSB0", BaudRate::B_115200, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
	// Use SerialPort serialPort("/dev/ttyACM0", 13000); instead if you want to provide a custom baud rate
	serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();

	{
	// Write some ASCII data
	//serialPort.Write("santhosh\n");

	// Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
	std::string readData;
	//char *creadData = readData.c_str();
	serialPort.Read(readData);
	//cout << readData;
	memset(readbuff,'\0',readData.length());
	memcpy(readbuff,readData.c_str(),readData.length());
	//std::cout<<"received data:"<<readData.c_str()<<std::endl;
	//cout<<"Length :"<<readData.length();
	//cout<<readbuff;
	return readData.length();
	}
   

	// Close the serial port
	serialPort.Close();
	return 0;
}
#endif
int serial_rd()
{
	// Create serial port object and open serial port at 57600 buad, 8 data bits, no parity bit, and one stop bit (8n1)
	SerialPort serialPort("/dev/ttyUSB0", BaudRate::B_115200, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
	// Use SerialPort serialPort("/dev/ttyACM0", 13000); instead if you want to provide a custom baud rate
	serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();

	while(1){
	// Write some ASCII data
	//serialPort.Write("santhosh\n");

	// Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
	std::string readData;
	serialPort.Read(readData);
	cout << readData;
	}
   

	// Close the serial port
	serialPort.Close();
}
int serial_init()
{
	serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();
	return 0;
}
int data_flag=0;
//int serial_1(char readbuff[])
int serial_1(char *readbuff)
{
		// Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
		std::string readData;
		//data_flag=0;
		serialPort.Read(readData);
		memcpy(readbuff,readData.c_str(),readData.length());
		std::cout<<"received data:"<<readData<<std::endl;
		data_flag=readData.length();
		std::cout<<"Length: "<<data_flag<<std::endl;
		// Close the serial port
		//serialPort.Close();
		return readData.length();
}


#if 0 // Make it 1 to test locally. Go to start of the this file for compilation procedure 
int main()
{
	serial_init();
	std::cout<<"init complete"<<std::endl;
	thread th1(serial_1, tmpbuf);
	//thread th1(foo,3);
		while(1)
	{
		
		//if(serial_1(tmpbuf)>0)
		if(data_flag>0)
		{
		std::cout<<"Mainloop:"<<tmpbuf<<std::endl;
		memset(tmpbuf,'\0',sizeof(tmpbuf));
		data_flag=0;
		}
		else
		{
		//std::cout<<"No data"<<std::endl;
		}
		 
		 
		sleep(0.1);
	}
	th1.join();
	return 0;
	
}
#endif 
