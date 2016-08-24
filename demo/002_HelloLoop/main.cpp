#include <iostream>
#include <windows.h> 	// use this library for windows
//#include <unistd.h> 	// use this library for mac and linux 

using namespace std;

int main() {

	// declare a boolean variable
	bool running = true;	

	// create a while loop
	while (running) {
		cout << "hello ";

		// sleep or pause the program for 1000 milliseconds or 1 second
		Sleep(1000); 			// use this one for windows
		//usleep(1000*1000);  	// use this one for mac and linux (in microseconds)
	}

	return 0;
}