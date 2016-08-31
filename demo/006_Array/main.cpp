#include <iostream>
#include <string>

using namespace std;

int main() {

	// an array is a ordered list
	// turn any variable into an array variable
	// simply use the square brackets []
	
	// declare a float array with a length of three
	float numbers[3];

	// assign values to items in the array
	numbers[0] = 44.33f;	// assign the first index the value of 44.3 (need to use 'f' for float values)
	numbers[1] = 33.1f;		// assign the second index
	numbers[2] = 44.4f;		// assign the third index
	
	// retrieve the value of the items in the array
	numbers[0]; 			// get the value of the first item
	numbers[1]; 			// get the value of the second item 
	numbers[2]; 			// get the value of the third item 

	cout << "first number in the list:" << endl;
	cout << numbers[0] << endl;

	cout << "\nentire list:" << endl;

	// loop through the entire array using a "for loop"

	/* create a for loop:
	   1) type "for"
	   2) type the parenthesis
	   3) inside the parenthesis: 
	 		a) create a counter variable, usually an integer
	 		b) define how high to count
			c) how much to increment the counter each loop, usually use "++"" which increments by one
	   4) use the curly brackets to execute some code within the loop */

	for (int i = 0; i < 3; i++) {
		cout << numbers[i] << endl; // use the variable "i" as the index to retrieve
	}


	// two-dimensional array = two indexes represent one value
	// think of a spreadsheet or grid of pixels (rows and columns)

	// declare a string array with a length of six
	string animals[3][2]; // the total length of the array is 3 * 2 = 6 

	// assign values to items in the array
	animals[0][0] = "cat";
	animals[0][1] = "dog";
	animals[1][0] = "rabbit";
	animals[1][1] = "horse";
	animals[2][0] = "donkey";
	animals[2][1] = "bird";

	// retrieve the value of an item in the array
	animals[0][0]; 			// get the value of the first item

	cout << "\nfirst animal in the list:" << endl;
	cout << animals[0][0] << endl;

	cout << "\nentire list:" << endl;

	// loop through the entire array using nested "for loops"

	// the first loop, three represents the length of the first array dimension
	for (int x = 0; x < 3; x++) {
		// the second loop, two represents the length of the second array dimension
		for (int y = 0; y < 2; y++) {
			cout << animals[x][y] << endl;
		}
	}

	// an easy way to keep the programm running, waiting for keyboard input
	cin.get();  
}