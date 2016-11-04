#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);


	// * POINTER AND REFERENCE */
	int number = 10;				// regular variable
	int * pointer = &number;		// pointer to a reference
	int pointerValue = *pointer;	// dereference the pointer to get the value

	cout << "number: " << number << endl;
	cout << "pointer: " << pointer << endl;
	cout << "pointerValue: " << pointerValue << endl;

	number = 50;				// update the number variable
	pointerValue = *pointer;	// update the pointerValue variable using the dereference operator

	cout << "--------------------" << endl;

	cout << "number: " << number << endl;
	cout << "pointer: " << pointer << endl;
	cout << "pointerValue: " << pointerValue << endl;


	// * VECTOR */
	vector<float> nums;			// create an empty vector of floats  
	nums.push_back(10.5);		// add a float with value 10.5 to the end of vector
	nums.push_back(20.2);		// add a float with value 20.2 to the end of vector

	cout << "--------------------" << endl;

	cout << nums[0] << endl;	// print out the value of element at position 0
	cout << nums[1] << endl;	// print out the value of element at position 1

	cout << "--------------------" << endl;

	for (int i = 0; i < nums.size(); i++) {  // loop through the vector and print
		cout << nums[i] << endl;
	}

	nums.clear();				// clear the vector


	// * MAP */
	map<string, int> age;		// create empty map with first element a string and second element an integer
	age["Bob"] = 40;			// assign "Bob" to 40
	age["Kate"] = 55;			// assign "Kate" to 55

	cout << "--------------------" << endl;

	cout << age["Bob"] << endl;		// print the value of "Bob"
	cout << age["Kate"] << endl;	// print the value of "Kate"


	cout << "--------------------" << endl;


	for (auto a : age) { 								// loop through age using the for each loop
		cout << a.first << " " << a.second << endl;		// print the first and second element of the list
	}


	map<string, ofImage> images;	// another example map


	ofRunApp(new ofApp());

}
