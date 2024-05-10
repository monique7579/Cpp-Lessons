#include <iostream>
using namespace std;

int main()
{
	int userInput;

	// First Variation - Magic Number 5
	cout << "Enter a number: "; // Ask user to enter a number
	cin >> userInput;
	int Product1 = (((userInput * 2) + 10) / 2) - userInput;
	cout << "Result: " << Product1 << endl; //used to check if the result is the same as the magic number
	cout << "The Magic Number is 5" << endl; //output the magic number

	// Second Variation - Magic Number 3
	cout << "Enter a number: ";
	cin >> userInput;
	int Product2 = ((((userInput + 5) * 2) - 4) / 2) - userInput;
	cout << "Result: " << Product2 << endl;
	cout << "The Magic Number is 3" << endl;


	// Third Variation - Magic Number 7
	cout << "Enter a number: "; // Similar structure as above
	cin >> userInput;
	int Product3 = (((((userInput * 2) + 9) - 3) / 2) - userInput) + 4; // included the +4 to always make the result 7	
	cout << "Result: " << Product3 << endl;
	cout << "The Magic Number is 7" << endl;

	return 0;
}


