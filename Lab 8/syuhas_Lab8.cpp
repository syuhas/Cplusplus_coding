//Stephen Yuhas
//Lab 8 - Strings
//5-2-22

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MATH = 1, COUNT = 2, MANIP = 3, CLASS = 4, EXIT = 5;	//const ints for menu selection options
const int SIZE = 30;	//const size limits for most c-strings created in program
const int YN_SIZE = 4;	//const size limit for 'y' or 'n' c-strings
const char DECIMAL = '.';	//test char const for input validation of only one decimal in test function with char version of a decimal point
const double REV = 0.34;	//const for revenue for each load delivered
const int SENT = 60;	//const for size limit for sentence in counting function
const int MAX_DEC = 1;		//const for max amount of decimals in validation function
const int MAX_ADDR = 10;	//const for max amount of characters in for address copy/concatenation
const int ZERO = 0;			//const int for zero value for decimal validation and strcmp address comparison


void welcome();		//proto for welcome display function
void stringMath();	//proto for string math function
bool exitProgram();	//proto for validation bool function to exit the program
bool testInput(char[]);	//proto for function that tests for only numerical input above zero
void countElements(char[]);	//proto for function that tests and counts types of elements in c-string
void cStringManip();	//proto for c-string manipulation function
void scStringManip();	//proto for string class manipulation function

int main()
{
	int choice = 0;		//variable for switch menu choice
	bool exitFlag = false;	//bool flag variable to exit or remain in program
	char sentence[SENT] = "How R cStrings 4 U? They can B tricky 4 C++ students!";	//c-string variable being sent into element counting function



	welcome();

	do	//do/while loop for testing to exit the program
	{
		cout << "String Lab Menu: " << endl;		//menu display
		cout << "\t1 - Doing Math with Strings" << endl;
		cout << "\t2 - Counting Elements" << endl;
		cout << "\t3 - C - String Manipulation" << endl;
		cout << "\t4 - String Class Manipulation" << endl;
		cout << "\t5 - Exit Program" << endl << endl;
		cout << "Please enter menu choice: ";
		cin >> choice;
		cin.ignore(1, '\n');	//ignore white space after the cin

		switch (choice)	//beginning of switch statement
		{
			case MATH:	//case 1, string math
			{
				stringMath();
				break;
			}
			case COUNT:	//case 2, element counting
			{
				countElements(sentence);
				cout << endl;
				break;
			}
			case MANIP:	//case 3, c-string manipulation
			{
				cStringManip();
				break;
			}
			case CLASS:	//case 4, string class manipulation
			{
				scStringManip();
				cout << endl;
				break;
			}
			case EXIT:	//case 5, exit choice
			{
				cout << "Do you wish to exit the program?(Y or N) ";
				exitFlag = exitProgram();
				break;
			}
			default:	//default case, invalid input
			{
				cout << "ERROR: You must enter a valid menu item. Please try again." << endl << endl;
				break;
			}
		}

	} while (!exitFlag);	//end of do/while loop for testing exit of program

	system("pause");
	return 0;
}

void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 8 - Strings" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 C-String Manipulation Program" << endl << endl;
	return;
}


void stringMath()	//defintition for the c-string math function
{
	char mDriven[SIZE] = "none";	//c-string for miles driven
	char mPG[SIZE] = "none";		//c-string for miles per gallon
	char gCost[SIZE] = "none";		//c-string for gas cost
	char numPk[SIZE] = "none";		//c-string for number of packages delivered per day
	double mD = 0, mP = 0, gC = 0;	//miles driven, miles per gallon and cost variables to hold c-string numerical conversions
	int nP = 0;						//packages variable to hold c-string conversion
	bool exitFlag = true, valid = false;	//bool values: 'exitFlag' for exit program test; 'valid' is sent to test function to validate c-string input

	double fuelUsed = 0;	//variable for fuel used calculation
	double costOfFuel = 0;	//variable for fuel cost calculation
	double averageDel = 0;	//variable for average deliveries calculation
	double averageDriven = 0;	//variable for average miles driven calculation
	double revenue = 0;			//variable for revenue calculation

	do		//do/while statement for exit program test
	{
		do		//do/while statement for c-string validation
		{
			cout << "Please enter in the number of miles driven in a week: ";
			cin.getline(mDriven, SIZE);
			valid = testInput(mDriven);		//number is sent to validation function and returns bool value (EXTRA CREDIT)
			if (!valid)
			{
				cout << "Error.  You must enter only numerical values without spaces. Please try again." << endl << endl;
			}

		} while (!valid);

		cout << endl;

		do		//do/while statement for c-string validation
		{
			cout << "Please enter the miles per gallon your vehicle gets: ";
			cin.getline(mPG, SIZE);
			valid = testInput(mPG);		//number is sent to validation function and returns bool value (EXTRA CREDIT)
			if (!valid)
			{
				cout << "Error.  You must enter only numerical values without spaces. Please try again." << endl << endl;
			}
			
		} while (!valid);
		
		cout << endl;

		do		//do/while statement for c-string validation
		{
			cout << "Please enter the cost of a gallon of diesel: ";
			cin.getline(gCost, SIZE);
			valid = testInput(gCost);		//number is sent to validation function and returns bool value (EXTRA CREDIT)
			if (!valid)
			{
				cout << "Error.  You must enter only numerical values without spaces. Please try again." << endl << endl;
			}

		} while (!valid);

		cout << endl;
		
		do		//do/while statement for c-string validation
		{
			cout << "Please enter the number of packages delivered per week: ";
			cin.getline(numPk, SIZE);
			valid = testInput(numPk);		//number is sent to validation function and returns bool value (EXTRA CREDIT)
			if (!valid)
			{
				cout << "Error.  You must enter only numerical values without spaces. Please try again." << endl << endl;
			}

		} while (!valid);
		
		cout << endl << endl;

		mD = stod(mDriven);		//miles driven c-string converted to a double
		mP = stod(mPG);			//miles per gallon c-string converted to a double
		gC = stod(gCost);		//gas cost c-string converted to a double
		nP = stoi(numPk);		//num of packages c-string converted to an int

		cout << fixed << showpoint << setprecision(2);		//formatting for output

		fuelUsed = mD / mP;		//gallons of fuel used is miles driven divided by miles per gallon
		costOfFuel = fuelUsed * gC;	//cost of fuel is the fuel used times the gas cost
		averageDel = static_cast<double>(nP) / 7;	//average miles driven is the number of packages divided by 7 days
		averageDriven = mD / 7;		//average miles per day is total miles driven divided by 7 days
		revenue = nP * REV;			//revenue is the number of packages times the revenue(constant) per package

		//display for all calculations
		cout << "The number of miles driven in a week was: " << mD << endl;
		cout << "The amount of fuel used in a week was: " << fuelUsed << endl;
		cout << "The cost of fuel for the week was: $" << costOfFuel << endl;
		cout << "The average packages delivered per day was: " << averageDel << endl;
		cout << "The average miles driven per day was: " << averageDriven << endl;
		cout << "The average amount of fuel used per day was: " << fuelUsed / 7 << endl;	//average fuel used is total fuel used divided by 7 days
		cout << "The average cost per day was: $" << costOfFuel / 7 << endl;		//average cost per day is total cost of fuel divided by 7 days
		cout << "The total revenue for the week was: $" << revenue << endl;
		cout << "The company made $" << revenue - costOfFuel << " in deliveries this week." << endl;	//total profit is the revenue minus the total cost of fuel
		cout << "Do you wish to enter another value? (Y or N) ";
		exitFlag = exitProgram();	//function call to perform exit function test

	} while (exitFlag);
	cout << endl;
	return;

}

bool testInput(char str[SIZE])		//defintion for test function to validate inputs in stringMath function (EXTRA CREDIT)
{
	bool valid = false;		//bool value to return as true or false for validation
	int dCounter = 0;		//decimal counter checks for more than one decimal in input
	
	for (int i = 0; i < strlen(str); i++)	//for loop starts running through each c-string char up to the total size of the c-string
	{
		
		if (isalpha(str[i]) || isspace(str[i]))		//if element is a SPACE or an ALPHA character....
		{				
			return valid = false;					//....function returns false
		}
		else if ((ispunct(str[i])) && (str[i] != DECIMAL))	//if element is a PUNCT that is NOT a decimal point.....(using char decimal point constant)
		{
			return valid = false;							//function returns false
		}
		if (str[i] == DECIMAL)							//if element is a decimal point......
		{				
			dCounter++;									//decimal point counter increments by 1
		}		
	}
	
	if (dCounter <= MAX_DEC && stod(str) > ZERO)		//once all elements have been validated as either a numerical or decimal value....
	{													//....if the decimal counter is at 0 or 1 AND the numerical conversion value is greater than zero
		return valid = true;							//function will return a true value(input is valid)
	}
	else
	{
		return valid = false;							//else the input is a negative value or contains more than one decimal and function returns false
	}
}


void countElements(char str[SENT])		//definition for element counting function
{
	int alpha = 0, digit = 0, upper = 0, lower = 0, space = 0, punct = 0;		//varibles to hold counts for alpha, digit, space and punct characters

	for (int i = 0; i < strlen(str); i++)	//runs through all elements of c-string using the strlen as the upper bound
	{
		if (isalpha(str[i]))	//isalpha tests each element for alpha characters
		{
			alpha++;	//variable for alphas is incremented if found
		}
		if (isdigit(str[i]))	//isdigits tests each element for digit characters
		{
			digit++;	//variable for digits is incremented if found
		}
		if (isupper(str[i]))	//isupper tests each element for upper characters
		{
			upper++;	//variable for uppers is incremented if found
		}
		if (islower(str[i]))//islower tests each element for lower characters
		{
			lower++;	//variable for lowers is incremented if found
		}
		if (isspace(str[i]))	//isspace tests each element for spaces
		{
			space++;	//variable for spaces is incremented if found
		}
		if (ispunct(str[i]))	//ispunct tests each element for punct characters
		{
			punct++;	//variable for puncts is incremented if found
		}
	}

	cout << "The test string is: " << str << endl << endl;
	cout << "Number of alphas = " << alpha << endl;		//	print number of alphas found
	cout << "Number of digits = " << digit << endl;		//	print number of digits found
	cout << "Number of uppers = " << upper << endl;		//	print number of uppers found
	cout << "Number of lowers = " << lower << endl;		//	print number of uppers found
	cout << "Number of spaces = " << space << endl;		//	print number of spaces found
	cout << "Number of puncts = " << punct << endl << endl;		//	print number of puncts found
}

void cStringManip()		//definition for c-string manipulation function
{
	char testString[SIZE] = "none";						//c-string for test string
	char first[SIZE] = "none", last[SIZE] = "none";		//c-string for first name	//c-string for last name	
	char completeName[SIZE] = "none";					//c-string fort the complete name
	char character[SIZE] = "none";						//c-string for replacement character
	char city[SIZE] = "none";							//c-string for city
	char state[SIZE] = "none", zip[SIZE] = "none";		//c-string for state	//c-string for zip
	char completeAddress[SIZE] = "none";				//c-string for the complete address

	int posToRep = 0;		//int variable to hold the position of the character to replace
	int pos = 0;			//int variable of the position of the replacement character




	cout << "Enter in a string for test string: ";
	cin.getline(testString, SIZE);

	cout << "The length of " << testString << " is: " << strlen(testString) << endl << endl;		//strlen displays the length of the test string

	cout << "Enter in a first name: ";
	cin.getline(first, SIZE);
	cout << "Enter in a last name: ";
	cin.getline(last, SIZE);

	strcpy_s(completeName, first);		//strcpy copies the first name to the comlplete name c-string

	cout << "After strcpy, string completeName is " << completeName << " and the length is: " << strlen(completeName) << endl << endl;	//display complete name and length using strlen
	
	strcat_s(completeName, " ");	//strcat one space to the end of complete name
	strcat_s(completeName, last);	//strcat the last name to the end of the complete name

	cout << "After strcat, string completeName is " << completeName << " and the length is: " << strlen(completeName) << endl << endl;	//display final complete name and length using strlen
	
	cout << "Enter in a single character: ";
	cin.getline(character, SIZE);	//enter new character to swap into c-string
	cout << "Enter in the character number in the string holding the full name to replace: ";
	cin >> posToRep;		//enter the position of the c-string to replace with the new character
	cin.ignore(1, '\n');	//ignore white space after cin
	
	completeName[posToRep - 1] = character[pos];	//swaps the selected character in position 'posToRep' with the new character

	cout << "After replacement, string completeName is " << completeName << endl << endl;

	cout << "Enter in a city: ";		//enter city, state and zip
	cin.getline(city, SIZE);
	cout << "Enter in a state: ";
	cin.getline(state, SIZE);
	cout << "Enter in a zip: ";
	cin.getline(zip, SIZE);

	strncpy_s(completeAddress, city, MAX_ADDR);		//city name is copied to completeaddress up to 10(MAX_ADDR) char elements using strncpy

	cout << "When doing a strncpy of city into completeAddress, max 10, you get: " << completeAddress << endl << endl;

	if (strcmp(completeAddress, city) != ZERO)		//strcmp compares the completeaddress and the city name...if 0 is not returned, they are not the equal
	{
		cout << "When first copied, city and completeAddress do not equal each other." << endl << endl;
	}
	else	//else, 0 is returned and the completeaddress and city names are the same
	{
		cout << "When first copied, city and completeAddress are equal." << endl << endl;
	}

	strcat_s(completeAddress, ", ");	//strcat one ', ' to the end of completeaddress
	strncat_s(completeAddress, state, MAX_ADDR);	//strcat the state name to the end of completeaddress (up to MAX_ADDR)
	strcat_s(completeAddress, " ");					//strcat a space to the end of completeaddress
	strncat_s(completeAddress, zip, MAX_ADDR);		//strcat the zip to the end of completeaddress (up to MAX_ADDR)

	cout << "The complete address is: " << completeAddress << endl;
	cout << "The length of the address is: " << strlen(completeAddress) << " characters." << endl << endl;	//display completed address and the length using strlen
	
	char *stateLoc = nullptr;	//pointer created to use with strstr to point to the found substring
	stateLoc = strstr(completeAddress, state);	//search completeaddress for the substring that matches the city c-string and saves position to pointer



	cout << "When looking for the string \"Maryland\" in name using strstr you get: " << stateLoc << endl << endl;	//displays the complete address starting from where the matching city substring was found

}

void scStringManip()		//definition for string class manipulation function
{
	string p1 = "none", p2 = "none";	//string variables for product 1 and 2 model numbers
	string make = "none", model = "none";	//string variables for make and model
	string dealer = "none", city = "none";	//string variable for dealer and city
	string dealCity = "none";				//string variable for dealer and city combined

	cout << "Please enter part number 1: ";		//enter product 1 and 2
	getline(cin, p1);
	cout << "Please enter part number 2: ";
	getline(cin, p2);
	cout << endl;

	cout << "Enter in the bike make: ";		//enter the make and model
	getline(cin, make);
	cout << "Enter in the bike model: ";
	getline(cin, model);
	cout << endl;

	cout << "Enter in the bike dealer: ";	//enter the dealer and city
	getline(cin, dealer);
	cout << "Enter in the city: ";
	getline(cin, city);

	cout << endl;

	if (p1 == p2)	//if p1 is equal to p2, the model numbers are the same
	{
		cout << "The model numbers are the same." << endl << endl;
	}
	else if (p1 < p2)	//if p1 is less than p2, the alphabetical order is p1, p2
	{
		cout << "The part numbers are: " << p1 << " and " << p2 << endl << endl;
	}
	else if (p2 < p1)	//if p2 is less than p1, the alphabetical order is p2, p1
	{
		cout << "The part numbers are: " << p2 << " and " << p1 << endl << endl;
	}

	make += " ";	//appends a space on to the end of 'make' string 
	make += model;	//appends the 'model' string on to the end of 'make'

	cout << "The bike make and model is: " << make << endl << endl;		//display the appended 'make' variable

	dealCity = dealer + " " + city;			//string variable 'dealCity' is defined as 'dealer' + a space + 'city' and now contains all 3

	cout << "The bike dealer is: " << dealCity << endl << endl;		//display the full dealer and city name string
}

bool exitProgram()	//boolean function definition to validate whether or not user would like to exit the program
{
	bool exitFlag = true;	//bool flag to return to main
	bool valid = false;	//bool flag to validate input
	char choice[YN_SIZE] = " ";	//c-string used as the input for the exit option
	char y[YN_SIZE] = "Y", n[YN_SIZE] = "N";	//yes and no test c-strings used for testing termination of the program

	do	//do/while loop validates the user input
	{
		cin.getline(choice, YN_SIZE);		//cin.getline used to enter the c-string choice	

		int i = strlen(choice) - 1;	//variable for the c-string array element to be compared

		if (toupper(choice[i]) == y[i])	//whether the user enters 'y' or 'Y', the 'toupper' converts to the uppercase version and compares it with the test string
		{
			exitFlag = true;	//function will return 'false'
			valid = true;		//valid flag set to 'true' to exit the validation loop
		}
		else if (toupper(choice[i]) == n[i])	//whether the user enters 'n' or 'N', the 'toupper' converts to the uppercase version and compares it with the test string
		{
			exitFlag = false;	//function will return 'true'
			valid = true;		//valid flag set to 'true' to exit the validation loop
		}
		else	//user does not enter a valid input
		{
			cout << "Please enter either Y or N: ";
			valid = false;	//valid flag set to 'false' to remain in validation loop
		}
	} while (!valid);	//loop will persist until valid input/valid flag set to true

	cout << endl << endl;

	return exitFlag;	//return the result of the exit prompt, true or false, to exit or remain in program
}

