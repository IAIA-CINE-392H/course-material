#include <iostream>

using namespace std;

// This function adds two integer numbers
// Inputs: numbers to add
// Output: addition result
int addTwoNumbers(int a, int b)
{
	return a + b;
}

int main()
{
	int firstNumber;
	int secondNumber;
	int result;

	while (true) {
		cout << "Add two numbers" << endl;
		cout << "Enter the first number: ";
		cin >> firstNumber;
		cout << "Enter the second number: ";
		cin >> secondNumber;
		result = addTwoNumbers(firstNumber, secondNumber);
		cout << "Result: " << result << endl;
	}
}
