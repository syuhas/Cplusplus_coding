//Stephen Yuhas
//02-09-2022
//Exercise - Output

#include <iostream>
#include <string>	//Required to use the string class

using namespace std;

int main()
{
	int num1 = 12;											//Integer declared and defined in same line
	double num2 = 3.14159;									//Double declared and defined in same line
	char char1 = 'B';										//Character declared and defined in same line
	string str1 = "This is the display for CE-Output";		//String declared and defined in same line
	bool boolValue1 = false;								//Bool declared and defined in same line

	cout << "This is my first program\n\n";		//Two escape sequences to add a space between outputs
	cout << "This prints two lines\n" << "using an escape sequence\n";	//Escape sequence at end of each statement separates lines
	cout << "\tThis string tests the tab sequence\n";	//Tab escape sequence at beginning indents the output
	cout << "This string prints a " << "\\" << " and a " << "\"" << " character\n";	//Two escape sequences for  special character and one for new line
	cout << "This string uses the end of line manipulator" << endl << endl;	//Two end of line manipulators to separate subsequent line
	//Each of the following lines displays the variables declared and defined above
	cout << "The integer variable is: " << num1 << endl;
	cout << "The double variable is: " << num2 << endl;
	cout << "The character variable is: " << char1 << endl;
	cout << "The string variable is: " << str1 << endl;
	cout << "The boolean variable is: " << boolValue1 << endl << endl;

	cout << "Extra Credit:\n";	//Displays and starts a new line signifying the start of the extra credit portion
	int int1;	//This declares the first integer that will be inputted by the user
	int int2;	//This declares the second integer that will be inputted by the user
	cout << "Enter in the first integer value: ";	//Displays the instructions for the first user prompt
	cin >> int1;	//Prompts the user for the first input
	cout << "Enter in the second integer value: ";	//Displays the instructions for the second user prompt
	cin >> int2;	//Prompts the user for the second input
	cout << "The addition of " << int1 << " and " << int2 << " = " << int1 + int2 << endl << endl;	//Displays the sum of the two user inputs
	system("pause");
	return 0;

}