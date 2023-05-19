//Stephen Yuhas
//Exercise - Return
//3-13-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printHeader();	//prototype	of function that prints copyright and title
void printMenu();	//prototype of function that prints the menu
double convertCalc(int, double);	//prototype of function that does all conversions
void printGoodbye();	//prototype of function that prints exit message 
bool testGoodbye(bool);	//prototype of function that tests for correct user input to exit program

const double MIN_DEG = -459.67;	//test value for temp calculation below acceptable value
const double ZERO_TEST = 0;	//test value for below zero for weight and length 

const int MTR1 = 1;	//menu input value for meters
const int FHT2 = 2;	//menu input value for temp
const int PND3 = 3;	//menu input value for weight
const int EXT4 = 4;	//menu input value for exit sequence

const string YES1 = "Y";	//uppercase string constant value to exit program
const string YES2 = "y";	//lowercase string constant value to exit program
const string NO1 = "N";		//uppercase string value to remain in program
const string NO2 = "n";		//lowercase string value to remain in program




int main()
{
	printHeader();	//prints title and copyright


	cout << fixed << setprecision(2);	//setprecision and fixed notation to 2 decimal places


	int menuIn = 0;	//input menu value
	double valIn = 0;	//input length, weight, temp value
	bool exitTest = false;	//bool test for exiting program, set to false

	while (exitTest == false)	//starts the loop, loops on bool exittest=false
	{
		printMenu();	//menu is printed
		cout << "Please enter the menu option: ";
		cin >> menuIn;	//input for menu choice

		switch (menuIn)	//switch for menu inputs
		{
			case MTR1:	//case 1 meters
			{
				do
				{
					cout << "Please enter the length in feet: ";
					cin >> valIn;	//input for conversion
					if (valIn <= ZERO_TEST)	//input tested to be above zero, loops if equal or below
					{
						cout << "Error - The length cannot be less than zero. Please reenter." << endl << endl;
					}
				} while (valIn <= ZERO_TEST);


				cout << valIn << " feet is equal to " << convertCalc(menuIn, valIn) << " meters." << endl << endl;	//conversion function is called and returns the converted value for meters
				break;
			}

			case FHT2:	//case 2 temperature
			{
				do
				{
					cout << "Please enter the temperature in Fahrenheit: ";
					cin >> valIn;	//input for conversion
					if (valIn < MIN_DEG)	//input tested to be above zero, loops if or below -459.67
					{
						cout << "Error - The temp cannot be below absolute zero (-459.67). Please reenter." << endl << endl;
					}
				} while (valIn < MIN_DEG);

				cout << valIn << " degrees Fahrenheit is equal to " << convertCalc(menuIn, valIn) << " degrees Celcius." << endl << endl;	//conversion function is called and returns value for degrees celcius
				break;
			}

			case PND3:	//case 3 pounds
			{
				do
				{
					cout << "Please enter the weight in pounds: ";
					cin >> valIn;	//input for conversion
					if (valIn <= ZERO_TEST)	//input tested to be above zero, loops if equal or below
					{
						cout << "Error - The weight cannot be less than zero. Please reenter." << endl << endl;
					}
				} while (valIn <= ZERO_TEST);

				cout << valIn << " pounds is equal to a mass of " << convertCalc(menuIn, valIn) << " kilograms." << endl << endl;	//conversion function called and returns value for weight in kilos
				break;
			}

			case EXT4:	//case 4 exit test
			{
				exitTest = testGoodbye(exitTest);	//sets the bool value equal to the function test to exit. if returns true, program will exit; false, program will persist
				cout << endl << endl;
				break;
			}

			default:	//default case for invalid menu entry
			{
				cout << "Error - Invalid option, please reenter!! " << endl << endl;	
				break;
			}
		}
	}
	printGoodbye();	//goodbye message is displayed after loop when the bool value is equal to true

	system("pause");
	return 0;
}




void printHeader()	//display function for the copyright
{
	cout << "CE - Return" << endl;
	cout << "Copyright 2021 - Howard Community College All rights reserved; Unauthorized duplication prohibited." << endl << endl;
	cout << "\t Welcome to the Conversion Calculator Program" << endl << endl;
	return;
}

void printMenu()	//display function for the title
{
	cout << "Menu of options:" << endl;
	cout << setw(31) << "1. - Convert Feet to Meters" << endl;
	cout << setw(38) << "2. - Convert Fahrenheit to Celcius" << endl;
	cout << setw(36) << "3. - Convert Pounds to Kilograms" << endl;
	cout << setw(13) << "4. - Exit" << endl;
	return;
}

double convertCalc(int menuVal, double result)	//conversion function, tests which conversion it must do then returns that conversion as a result
{
	if (menuVal == 1)
	{
		result = result / 3.281;	//conversion for meters
		return result;
	}
	if (menuVal == 2)
	{
		result = (result - 32) * (9 / 5);	//conversion for degrees celcius
		return result;
	}
	if (menuVal == 3)
	{
		result = result / 2.205;	//conversion for kilograms
		return result;
	}
}

bool testGoodbye(bool test)	//function for testing whether the user wants to exit or not
{
	string exitCh;	//string created to input and test against yes or no string constants
	do	//start of the loop to test for correct input (Y,y,N,n)
	{
		cout << "Do you want to exit the program? (y/n): ";
		cin >> exitCh;	//input choice to exit the program

		if (exitCh == YES1 || exitCh == YES2)	//if Y or y, returns a bool value of true and exits the program (EXTRA CREDIT)
		{
			test = true;
			return test;
			break;
		}
		if (exitCh == NO1 || exitCh == NO2)	//if N or n, returns a bool value of false and the program persists (EXTRA CREDIT)
		{
			test = false;
			return test;
			break;
		}
		if (exitCh != YES1 && exitCh != YES2 && exitCh != NO1 && exitCh != NO2)		//tests to display error message for an invalid input
		{
			cout << "Error - Only y or n is valid, please reenter!!" << endl << endl;
		}
	}while (exitCh != YES1 && exitCh != YES2 && exitCh != NO1 && exitCh != NO2);	//loop persists if the user does not enter any valid option

	

}

void printGoodbye()	//function to print goodbye message which prints at end of program when bool value is true
{
	cout << "Thank you for using our application today. Stay Healthy!!" << endl << endl;
	return;
}


