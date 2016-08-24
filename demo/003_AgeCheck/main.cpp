#include <iostream>
#include <windows.h> 	// use this library for windows
//#include <unistd.h> 	// use this library for mac and linux 

using namespace std;

 // declare an integer variable name age
int age = 0;

int main() {

	// declare a boolean variable
	bool running = true;	

	// create a loop
	while (running) {
		std::cout << "Enter your age: ";
		std::cin >> age;

		if (age < 14) {
			std::cout << "\nSorry, you are not old enough.\n" << std::endl;
		}
		else {
			std::cout << "\nEnjoy the exhibit!\n" << std::endl;
			running = false; // this will cause the program to exit
		}
		
		// sleep or pause the program for 1000 milliseconds or 1 second
		Sleep(1000); 			// use this one for windows
		//usleep(1000*1000);  	// use this one for mac and linux (in microseconds) 
	}

	return 0;
}