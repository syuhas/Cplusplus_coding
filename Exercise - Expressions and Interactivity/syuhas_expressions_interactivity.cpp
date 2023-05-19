//Stephen Yuhas
//Exercise - Expressions and Interactivity
//2-20-22

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int sw1 = 0, sw2 = 0, sw3 = 0;	//Declare and initialize variables for each season win as integers
	double avgW = 0;	//Declare and initialize variable for the average wins as a double

	//Display title section and copyright
	cout << "CE - Expressions and Interactivity" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	cout << "Input Data:" << endl;	//Header to signify start of input

	cout << setw(39) << "Enter number of wins in season 1: ";	//Set width to display indented 5 spaces in
	cin >> sw1;	//Input for first win value
	while (sw1 < 0)	//While loop will reject input until the value is >=0
	{
		cout << endl << "Error - You cannot enter in a value less than 0. Please reenter here: ";	//Prompt for re-input if the above condition is met
		cin >> sw1;
		cout << endl;
	}
	cout << setw(39) << "Enter number of wins in season 2: ";	//Set width to display indented 5 spaces in
	cin >> sw2;	//Input for second win value
	while (sw2 < 0)	//While loop will reject input until the value is >=0
	{
		cout << endl << "Error - You cannot enter in a value less than 0. Please reenter here: ";	//Prompt for re-input if the above condition is met
		cin >> sw2;
		cout << endl;
	}
	cout << setw(39) << "Enter number of wins in season 3: ";	//Set width to display indented 5 spaces in
	cin >> sw3;	//Input for third win value
	while (sw3 < 0)	//While loop will reject input until the value is >=0
	{
		cout << endl << "Error - You cannot enter in a value less than 0. Please reenter here: ";	//Prompt for re-input if the above condition is met
		cin >> sw3;
		cout << endl;
	}
	cout << endl << endl;

	avgW = (static_cast<double>(sw1 + sw2 + sw3)) / 3;	//Calculation for the average wins, static casting the "win" integers to a double type

	cout << fixed << showpoint << setprecision(2);	//Formats to show 2 decimal places, even if value is an integer
	cout << "The average number of wins per year is: ";
	cout << avgW << endl << endl;	//Displays the average wins

	system("pause");
	return 0;
}