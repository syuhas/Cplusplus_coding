//Stephen Yuhas
//Exercise - Pass By Reference
//3-20-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MENU_INT = 1;	//menu value for integer math
const int MENU_DBL = 2;	//menu value for double math
const int MENU_EX = 3;	//menu value for exit

const string INT_MATH = "1 - Integer Math";	//string value to display the integer math menu option
const string DBL_MATH = "2 - Double Math";	//string value to display the double math menu option
const string EXIT_MENU = "3 - Exit Program";	//string value to display the exit program menu option

const string YES1 = "Y";	//uppercase string value to exit program
const string YES2 = "y";	//lowercase string value to exit program
const string NO1 = "N";		//uppercase string value to remain in program
const string NO2 = "n";		//lowercase string value to remain in program

void printTitle();	//prototype function to print title, copyright and introduction
int mainMenu(int);	//prototype function to display menu and return the choice

int add(int, int);	//prototype	function for adding integers
int subtract(int, int);	//prototype function for subtracting integers
int multiply(int, int);	//prototype function for muiltiplying integers
int divide(int, int);	//prototype function for dividing integers
int mod(int, int);	//prototype function for modulus integers

void add(double, double, double&);	//prototype	function for adding doubles
void subtract(double, double, double&);	//prototype	function for subtracting doubles
void multiply(double, double, double&);	//prototype	function for multiplying doubles
void divide(double, double, double&);	//prototype	function for dividing doubles

void displayInt(int, int, int, int, int);	//prototype	function for displaying the integer math
void displayDbl(double, double, double, double);	//prototype	function for displaying the double math

bool testExit();	//prototype function for exit confirmation
void goodbye();		//prototype	function for the goodbye message




int main()
{
	int intNum1 = 0;	//first test integer variable
	int intNum2 = 0;	//second test integer variable
	double dblNum1 = 0;	//first test double variable
	double dblNum2 = 0;	//second test double variable

	int addInt = 0;		//variable for resulting integer addition
	int subInt = 0;		//variable for resulting integer subtraction
	int multInt = 0;	//variable for resulting integer multiplication
	int divInt = 0;		//variable for resulting integer division
	int modInt = 0;		//variable for resulting integer modulus

	double addDbl = 0;	//variable for resulting double addition
	double subDbl = 0;	//variable for resulting double subtraction
	double multDbl = 0;	//variable for resulting double multiplication
	double divDbl = 0;	//variable for resulting double division

	int selectMath = 0;	//variable for the menu selection

	bool exitTest = false;	//text boolean variable for exiting the program

	printTitle();	//function call to print the title, copyright and introduction

	while (exitTest == false)	//beginning of loop to validate menu input; persists menu until exit program(option 3) is input and the exit function returns a "true" value
	{

		selectMath = mainMenu(selectMath);	//sets the menu selection equal to the result from the menu function call
		switch (selectMath)	//beginning of switch statement for 3 menu options
		{
			case MENU_INT:	//case 1, integer math
			{
				cout << endl << endl;
				cout << "Please enter the first integer value: ";	//integer variables are input
				cin >> intNum1;
				cout << endl << endl;
				cout << "Please enter the second integer value: ";
				cin >> intNum2;
				cout << endl << endl;
				
				addInt = add(intNum1, intNum2);			//calls addition function for integers and sets variable as return value
				subInt = subtract(intNum1, intNum2);	//calls subtraction function for integers and sets variable as return value
				multInt = multiply(intNum1, intNum2);	//calls multiplication function for integers and sets variable as return value
				divInt = divide(intNum1, intNum2);		//calls division function for integers and sets variable as return value
				modInt = mod(intNum1, intNum2);			//calls modulus function for integers and sets variable as return value
				
				displayInt(addInt, subInt, multInt, divInt, modInt);	//calls display function to display all integer results
				cout << endl << endl;
				break;
			}

			case MENU_DBL:
			{
				cout << endl << endl;
				cout << "Please select the first double value: ";	//double variables are input
				cin >> dblNum1;
				cout << endl << endl;
				cout << "Please enter the second double value: ";
				cin >> dblNum2;
				cout << endl << endl;
				
				add(dblNum1, dblNum2, addDbl);					//calls addition function for doubles and sets passby reference as the result
				subtract(dblNum1, dblNum2, subDbl);				//calls subtraction function for doubles and sets passby reference as the result
				multiply(dblNum1, dblNum2, multDbl);			//calls multiplication function for doubles and sets passby reference as the result
				divide(dblNum1, dblNum2, divDbl);				//calls division function for doubles and sets passby reference as the result
				
				displayDbl(addDbl, subDbl, multDbl, divDbl);	//calls display function to display all double results
				cout << endl << endl;
				break;
			}

			case MENU_EX:
			{
				exitTest = testExit();	//calls the fuction to confirm program exit, sets boolean variable as the return value
				break;
			}

		}
	}
	goodbye();
	system("pause");
	return 0;
}




void printTitle()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "CE - Pass By Reference" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to the CSMY-141 Calculator Program" << endl << endl;
	return;
}


int mainMenu(int select)	//main menu function, menu is displayed and prompt for menu choice with validation
{
	do	//do/while loop for menu validation
	{
		cout << "MAIN MENU" << endl;
		cout << setw(24) << INT_MATH << endl;
		cout << setw(23) << DBL_MATH << endl;
		cout << setw(24) << EXIT_MENU << endl;
		cout << "Please enter your menu choice: ";
		cin >> select;
		if (select != MENU_INT && select != MENU_DBL && select != MENU_EX)	//if statement for menu validation error
		{
			cout << endl << "ERROR - Please enter a valid menu option" << endl << endl;
		}
	} while (select != MENU_INT && select != MENU_DBL && select != MENU_EX);	//end of do/while loop for menu validation
	return select;	//menu selection has been validated and is returned to main
}


int add(int num1, int num2)			//function for integer addition, returns integer result
{
	int result = 0;
	result = num1 + num2;
	return result;
}

int subtract(int num1, int num2)	//function for integer subtraction, returns integer result
{
	int result = 0;
	result = num1 - num2;
	return result;
}

int multiply(int num1, int num2)	//function for integer multiplication, returns integer result
{
	int result = 0;
	result = num1 * num2;
	return result;
}

int divide(int num1, int num2)		//function for integer division, returns integer result
{
	int result = 0;
	result = num1 / num2;
	return result;
}

int mod(int num1, int num2)			//function for integer modulus, returns integer result
{
	int result = 0;
	result = num1 % num2;
	return result;
}


void add(double num1, double num2, double &result)			//function for double addition, passby reference set as result
{
	result = num1 + num2;
	return;
}

void subtract(double num1, double num2, double& result)		//function for double subtraction, passby reference set as result
{
	result = num1 - num2;
	return;
}

void multiply(double num1, double num2, double& result)		//function for double multiplication, passby reference set as result
{
	result = num1 * num2;
	return;
}

void divide(double num1, double num2, double& result)		//function for double addition, passby reference set as result
{
	result = num1 / num2;
	return;

}

void displayInt(int resAdd, int resSub, int resMult, int resDiv, int resMod)	//display function for all integer results,  5 integer results sent to function and displayed
{
	cout << "RESULTS" << endl;
	cout << "\tAddition" << setw(10) <<" = " << resAdd << endl;				//addition result
	cout << "\tSubtraction" << setw(7) << " = " << resSub << endl;			//subtraction result
	cout << "\tMultiplication" << setw(4) << " = " << resMult << endl;		//multiplication result
	cout << "\tDivision" << setw(10) << " = " << resDiv << endl;			//division result
	cout << "\tModulus" << setw(11) << " = " << resMod << endl;				//modulus result
	return;
}

void displayDbl(double resAdd, double resSub, double resMult, double resDiv)	//display function for all double values, 4 double results sent to function and displayed
{
	cout << fixed << showpoint << setprecision(2);	//formatting for 2 decimal places
	cout << "RESULTS" << endl;
	cout << "\tAddition" << setw(10) << " = " << resAdd << endl;			//addition result
	cout << "\tSubtraction" << setw(7) << " = " << resSub << endl;			//subtraction result
	cout << "\tMultiplication" << setw(4) << " = " << resMult << endl;		//multiplication result
	cout << "\tDivision" << setw(10) << " = " << resDiv << endl;			//division result
	return;
}

bool testExit()	//function for testing whether the user wants to exit or not
{
	string exitCh;	//string created to input and test against yes or no string constants
	bool test = false;
	do	//start of the loop to test for correct input (Y,y,N,n)
	{
		cout << endl << "Do you wish to exit the program? (y/n): ";
		cin >> exitCh;	//input choice to exit the program

		if (exitCh == YES1 || exitCh == YES2)	//if Y or y, returns a bool value of true and exits the program
		{
			test = true;
		}
		if (exitCh == NO1 || exitCh == NO2)	//if N or n, returns a bool value of false and the program persists
		{
			test = false;
		}
		if (exitCh != YES1 && exitCh != YES2 && exitCh != NO1 && exitCh != NO2)		//tests to display error message for an invalid input
		{
			cout << endl << endl;
			cout << "Error - Please enter either y or n." << endl << endl;
		}
	} while (exitCh != YES1 && exitCh != YES2 && exitCh != NO1 && exitCh != NO2);	//loop persists if the user does not enter any valid option
	cout << endl;
	return test;
}

void goodbye()	//goodbye message function
{
	cout << endl << "Thank you for using the CSMY-141 Calculator Program" << endl << endl;
}
