#include <iostream>

using namespace std;

/* 
   This program demonstrates some basic operators:
   << insertion
   >> extraction 
   + add
   - subtract
   * multiply
   / divide
   % modulus
*/
int main()
{
	int firstNumber;
	int secondNumber;
	int result;

	while (true) {
		// add
		cout << "Add two numbers." << endl;
		cout << "Enter the first number: ";
		cin >> firstNumber;
		cout << "Enter the second number: ";
		cin >> secondNumber;
		result = firstNumber + secondNumber;
		cout << "The result is: " << result << "\n\n";

		// subtract
		cout << "Subtract two numbers." << endl;
		cout << "Enter the first number: ";
		cin >> firstNumber;
		cout << "Enter the second number: ";
		cin >> secondNumber;
		result = firstNumber - secondNumber;
		cout << "The result is: " << result << "\n\n";

		// multiply
		cout << "Multiply two numbers." << endl;
		cout << "Enter the first number: ";
		cin >> firstNumber;
		cout << "Enter the second number: ";
		cin >> secondNumber;
		result = firstNumber * secondNumber;
		cout << "The result is: " << result << "\n\n";

		// divide
		cout << "Divide two numbers." << endl;
		cout << "Enter the first number: ";
		cin >> firstNumber;
		cout << "Enter the second number: ";
		cin >> secondNumber;
		result = firstNumber / secondNumber;
		cout << "The result is: " << result << "\n\n";

		// modulus
		cout << "Find the remainder of two numbers." << endl;
		cout << "Enter the first number: ";
		cin >> firstNumber;
		cout << "Enter the second number: ";
		cin >> secondNumber;
		result = firstNumber % secondNumber;
		cout << "The result is: " << result << "\n\n";
	}
}
