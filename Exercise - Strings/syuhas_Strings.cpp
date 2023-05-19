//Stephen Yuhas
//Lab 6 - Vectors and Range Based Loops
//4-18-22

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

const int SUB_SIZE = 25;	//const integer for the maximum size of each sub c-string array
const int FULL_SIZE = 50;	//const integer for the maximum size of the fully concatenated c-string array
const int YN_SIZE = 5;		//const integer for the test c-string to exit program with Y or N




void welcome();		//proto for welcome function
void stringCounter(char[]);	//proto for function to count the number of types of characters in full array
bool exit();	//proto for function to check whether or not user wants to exit the program

int main()
{
	char dString[SUB_SIZE], nString[SUB_SIZE], sString[SUB_SIZE], tString[SUB_SIZE];	//sub c-string arrays for dept, number, section and title of course
	char fString[FULL_SIZE];	//full c-string array for the complete concatenated course description
	char cSTest[SUB_SIZE] = "CMSY";	//test c-string to validate if the course is a comp sci course
	bool exitFlag = false;	//bool varible to test whether or not to exit program

	welcome();	//function call to print welcome function with title and copyright
	
	do	//start of do/while statement to test if the user wants to exit the program
	{

		cout << "Please enter in the department name: ";
		cin.getline(dString, SUB_SIZE);						//user enters the name of the dept using cin.getline
		cout << "Please enter in the class number: ";
		cin.getline(nString, SUB_SIZE);						//user enters the course number using cin.getline
		cout << "Please enter in the section number: ";
		cin.getline(sString, SUB_SIZE);						//user enters the course section using cin.getline
		cout << "Please enter in the class title: ";
		cin.getline(tString, SUB_SIZE);						//user enters the course title using cin.getline

		strcpy_s(fString, dString);		//copies the substring for the dept name into what will become the full course description c-string
		strcat_s(fString, "-");			//concatenates a '-' with the full string
		strcat_s(fString, nString);		//concatenates the course number substring with the full string 
		strcat_s(fString, " (");		//concatenates a ' (' with the full string
		strcat_s(fString, sString);		//concatenates the section number substring with the full string
		strcat_s(fString, ") ");		//concatenates a ') ' with the full string
		strcat_s(fString, tString);		//concatenates the title substring with the full string

		cout << endl << "The course entered is: " << fString << endl;	//prints the full course description string

		cout << "The size of the string is: " << strlen(fString) << endl;	//strlen used to print the length of the full course description string

		if (strcmp(dString, cSTest) == 0)	//if strcmp if equal to zero then the two strings are equal and will print the confirmation message
		{
			cout << "This is a Computer Science Class." << endl << endl;
		}
		else
		{
			cout << "This is not a Computer Science Class." << endl << endl;
		}

		stringCounter(fString);		//call the function to count types of characters and print the results
		
		cout << endl << endl;

		exitFlag = exit();		//bool variable set to the result of the function call to check if the user wants to exit the program

	} while (exitFlag);		//if function returns true, program will persist

	system("pause");
	return 0;
}

void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "CE - Strings" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 C-String Practice Program" << endl << endl;
	return;
}

void stringCounter(char str[])		//function definition to count the different characters in the full string
{
	int alpha = 0, digit = 0, space = 0, punct = 0;		//varibles to hold counts for alpha, digit, space and punct characters

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
		if (isspace(str[i]))	//isspace tests each element for spaces
		{
			space++;	//variable for spaces is incremented if found
		}
		if (ispunct(str[i]))	//ispunct tests each element for punct characters
		{
			punct++;	//variable for puncts is incremented if found
		}
	}
	cout << "Number of alphas = " << alpha << endl;		//	print number of alphas found
	cout << "Number of digits = " << digit << endl;		//	print number of digits found
	cout << "Number of spaces = " << space << endl;		//	print number of spaces found
	cout << "Number of puncts = " << punct << endl;		//	print number of puncts found
	
	return;
}

bool exit()	//boolean function definition to validate whether or not user would like to exit the program
{
	bool exitFlag = true;	//bool flag to return to main
	bool valid = false;	//bool flag to validate input
	char choice[YN_SIZE];	//c-string used as the input for the exit option
	char y[YN_SIZE] = "Y", n[YN_SIZE] = "N";	//yes and no test c-strings used for testing termination of the program

	do	//do/while loop validates the user input
	{
		cout << "Do you wish to exit the program (y/n)? ";
		cin.getline(choice, YN_SIZE);		//cin.getline used to enter the c-string choice	

		int i = strlen(choice) - 1;	//variable for the c-string array element to be compared

		if (toupper(choice[i]) == y[i])	//whether the user enters 'y' or 'Y', the 'toupper' converts to the uppercase version and compares it with the test string
		{
			exitFlag = false;	//function will return 'false' to main() to exit program
			valid = true;		//valid flag set to 'true' to exit the validation loop
		}
		else if (toupper(choice[i]) == n[i])	//whether the user enters 'n' or 'N', the 'toupper' converts to the uppercase version and compares it with the test string
		{
			exitFlag = true;	//function will return 'true' to main() to remain in program
			valid = true;		//valid flag set to 'true' to exit the validation loop
		}
		else	//user does not enter a valid input
		{
			cout << "Error - Please enter either y or n." << endl << endl;
			valid = false;	//valid flag set to 'false' to remain in validation loop
		}
	} while (!valid);	//loop will persist until valid input/valid flag set to true

	cout << endl << endl;

	return exitFlag;	//return the result of the exit prompt, true or false, to exit or remain in program
}