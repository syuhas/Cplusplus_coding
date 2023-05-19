//Stephen Yuhas
//Lab 4 - Functions - Pass By Reference
//3-22-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double PI = 3.14;		//const for value of PI
const double PRICE_W = 20.75;	//const for price of wood per foot
const double PRICE_T = 27.85;	//const for price of trex per foot
const double TAX = 0.06;		//const for tax rate
const double LABOR = 0.37;		//const for percentage of labor

const int REC = 1;	//menu value for rectangular deck
const int CIRC = 2;	//menu value for circular deck
const int TRAP = 3;	//menu value for trapezoidal deck
const int WOOD = 1;	//menu value for wood material
const int TREX = 2;	//menu value for trex material

const string YES1 = "Y";	//uppercase string value to exit program
const string YES2 = "y";	//lowercase string value to exit program
const string NO1 = "N";		//uppercase string value to remain in program
const string NO2 = "n";		//lowercase string value to remain in program

const string L_STR = "length";	//display string for length in "smart" function
const string W_STR = "width";	//display string for width in "smart" function
const string D_STR = "diameter";	//display string for diameter in "smart" function
const string SL_STR = "short length";	//display string for short length in "smart" function
const string LL_STR = "long length";	//display string for long length in "smart" function
const string H_STR = "height";	//display string for height in "smart" function

const string REC_STR = "1. Rectangle";	//display string for rectangle in menu
const string CIRC_STR = "2. Circle";	//display string for circle in menu
const string TRAP_STR = "3. Trapezoidal";	//display string for trapezoid in menu

const string WOOD_STR = "Wood	$20.75 per square foot";	//display string for wood in material menu
const string TREX_STR = "Trex	$27.85 per square foot";	//display string for trex in material menu
const string W_STR_DISP = "Wood";	//display string for wood in estimate display function
const string T_STR_DISP = "Trex";	//display string for trex in estimate display function


const double MIN_TEST = 0;		//const for testing minimum value input
const double MAX_TEST = 308;	//const for testing max possible area



void welcome();									//proto welcome function
void getInfo(string&, string&, string&);		//proto function for gathering customer info
int selectPackageShape();						//proto function for selecting shape of deck
void getDimensions(double&, double&);			//proto function for getting dimensions of rectangular deck
double calcSquareFeet(double, double);			//proto function for calculating sq feet of rectangular deck
void getDimensions(double&);					//proto function for getting diameter of circular deck
double calcSquareFeet(double);					//proto function for calculating sq feet of circular deck
void getDimensions(double&, double&, double&);	//proto function for getting dimensions of trapezoidal deck
double calcSquareFeet(double, double, double);	//proto function for calulating sq feet of trapezoidal deck
int selectMaterial();							//proto function to select desired material
double calcTotalPrice(int, double);				//proto function to calculate the total price of deck
void displayEstimate(string, string, string, double, int, double);	//proto function to display estimate summary
void goodBye();									//proto function that displays goodbye message
double minTest(double, string);					//(EXTRA CREDIT) proto "smart" function that tests input and displays which input is invalid


int main()
{
	bool areaMax = false;	//bool variable for testing maximum area 
	bool exitTest = false;	//bool variable for testing whether or not user wants to exit program 
	string custName;		//string for customer name
	string custNum;			//string for customer phone number
	string custEmail;		//string for customer email
	int shape = 0;			//integer variable for deck shape selection

	double recL = 0;	//input variable for length
	double recW = 0;		//input variable for width
	double totArea = 0;		//variable for total area of deck
	double diameter = 0;	//input variable for diameter
	double trapSL = 0;		//input variable for  short length
	double trapLL = 0;		//input variable for long length
	double trapH = 0;		//input variable for height

	int material = 0;	//integer variable for material selection 
	double subTotal = 0;	//variable for total cost calculation

	string exitCheck;	//string for 'y' or 'n' exit choice


	welcome();	//calls welcome function
	getInfo(custName, custNum, custEmail);	//calls function to get customer info

	while (exitTest == false)	//beginning of loop that persists until user enters the correct string value to exit the program; 
	{							//when this happens, bool value is set to true and loop ends, ending the program

		cout << endl << endl << setw(27) << "Estimate" << endl << endl;
		shape = selectPackageShape();	//calls shape selection function; deck shape variable set as the return value of the function 

		cout << fixed << showpoint << setprecision(2);	//formatting for 2 decimal places

		switch (shape)	//beginning of switch statement for deck shape choice
		{
			case REC:	//case, rectangle
			{
				do	//loop for max area validation
				{
					cout << endl;
					getDimensions(recL, recW);	//calls function to get dimensions of deck, rectangle
					totArea = calcSquareFeet(recL, recW);	//call function to calculate square feet
					if (totArea > MAX_TEST)
					{
						cout << "ERROR - The maximum area is " << MAX_TEST << " feet. Please reenter dimensions!" << endl << endl;
					}				
				} while (totArea > MAX_TEST);
				break;
			}
			case CIRC:
			{
				do	//loop for max area validation
				{
					cout << endl;
					getDimensions(diameter);	//calls function to get dimensions of deck, circle
					totArea = calcSquareFeet(diameter);	//call function to calculate square feet
					if (totArea > MAX_TEST)
					{
						cout << "ERROR - The maximum area is " << MAX_TEST << " feet. Please reenter dimensions!" << endl << endl;
					}
				} while (totArea > MAX_TEST);
				break;
			}
			case TRAP:
			{
				do	//loop for max area validation
				{
					cout << endl;
					getDimensions(trapSL, trapLL, trapH);	//calls function to get dimensions of deck, trapezoid
					totArea = calcSquareFeet(trapSL, trapLL, trapH);	//call function to calculate square feet
					if (totArea > MAX_TEST)
					{
						cout << "ERROR - The maximum area is " << MAX_TEST << " feet. Please reenter dimensions!" << endl << endl;
					}
				} while (totArea > MAX_TEST);
				break;
			}
		}

		material = selectMaterial();	//call function to select the material for the deck

		subTotal = calcTotalPrice(material, totArea);	//total cost set as function call to calculate total price function

		displayEstimate(custName, custNum, custEmail, totArea, material, subTotal);	//call function to display estimate, sends in customer info, area, deck material and total cost
		
		do		//loop 
		{
			cout << endl << "Would you like another estimate? [Y or N] ";
			cin >> exitCheck;
			if (exitCheck == YES1 || exitCheck == YES2)	//if Y or y, returns a bool value of true and exits the program
			{
				exitTest = false;
			}
			if (exitCheck == NO1 || exitCheck == NO2)	//if N or n, returns a bool value of false and the program persists
			{
				exitTest = true;
			}
			if (exitCheck != YES1 && exitCheck != YES2 && exitCheck != NO1 && exitCheck != NO2)		//tests to display error message for an invalid input
			{
				cout << "Error - Only y or n is valid, please reenter!!" << endl << endl;
			}
		} while (exitCheck != YES1 && exitCheck != YES2 && exitCheck != NO1 && exitCheck != NO2);
	}
	goodBye();	//calls goodbye function to display goodbye mesasage
}








void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 4 - Functions - Pass By Reference" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << setw(50) << "Welcome to CSMY-141 Deck Builders" << endl;
	cout << setw(43) << "Stephen Yuhas, Owner" << endl << endl << endl;
	return;
}

void getInfo(string& name, string& number, string& email)	//function that recieves user input for name, number and email and passby reference variables
{
	cout << "Please enter your full name: ";
	getline(cin, name);
	cout << "Please enter your telephone number (ex: (555) 555-5555): ";
	getline(cin, number);
	cout << "Please enter your email address (ex: name@domain.net): ";
	getline(cin, email);
	return;
}

int selectPackageShape()	//function that selects deck shape, returns selection to main
{
	int choice = 0;
	cout << "To describe the shape of the deck, please select 1, 2 or 3:" << endl;
	cout << setw(16) << REC_STR << endl;
	cout << setw(13) << CIRC_STR << endl;
	cout << setw(18) << TRAP_STR << endl << endl;
	do	//loop to validate correct input
	{		
		cout << "Please enter your selection here: ";
		cin >> choice;
		if (choice != REC && choice != CIRC && choice != TRAP)
		{
			cout << "Error - this is not a valid selection. Please try again" << endl << endl;
		}
	} while (choice != REC && choice != CIRC && choice != TRAP);
	return choice;
}

void getDimensions(double& length, double& width)	//function for rectangle dimensions using passby reference variables, variables sent to "smart" function for input and validations
{
	length = minTest(length, L_STR);	//calls mintest "smart" function to validate input and display which value is incorrect
	width = minTest(length, W_STR);		//calls "smart" function for next value
	return;
}

double calcSquareFeet(double length, double width)	//function that calculates area for rectangle and returns value to main
{
	double result = length * width;
	return result;
}

void getDimensions(double& dValue)	//function to get diameter of circle using passby reference varible, variable sent to "smart" function for input and validation
{
	dValue = minTest(dValue, D_STR);	//calls "smart" function to validate input and display which value is incorrect
	return;
}

double calcSquareFeet(double dValue)	//function that calculates area of circle and returns value to main
{
	double radius = dValue / 2;
	double result = 0;
	result = PI * radius * radius;
	return result;
}

void getDimensions(double& shortL, double& longL, double& height)	//function for trapezoid dimensions using passby reference variables, variables sent to "smart" function for input and validations
{
	shortL = minTest(shortL, SL_STR);	//calls "smart" function to validate input and display which value is incorrect
	longL = minTest(longL, LL_STR);		//calls "smart" function for next value
	height = minTest(height, H_STR);	//calls "smart" function for final value
	return;
}

double calcSquareFeet(double shortL, double longL, double height)	//function to calculate area for a trapezoid and returns value to main
{
	double result = 0;
	result = ((shortL + longL) / 2) * height;
	return result;
}

int selectMaterial()	//function for selecting deck material, selection returned to main
{
	int choice = 0;
		
	do
	{
		cout << endl << "There are two types of deck material that are available." << endl;
		cout << "All prices are based on deck square footage and include construction costs," << endl << endl;
		cout << setw(8) << "1. " << WOOD_STR << endl;
		cout << setw(8) << "2. " << TREX_STR << endl << endl;
		cout << "Please enter your selection here: ";
		cin >> choice;
		if (choice != WOOD && choice != TREX)
		{
			cout << "Error - This is not a valid selection. Please try again." << endl << endl;
		}
	} while (choice != WOOD && choice != TREX);
	return choice;
}

double calcTotalPrice(int choice, double area)	//function for calculating total price, returns the total to main
{
	double total = 0;
	//if statement for total price using wood as material
	if (choice == WOOD)
	{
		total = area * PRICE_W;
	}
	//if statement for total price using trex as material
	if (choice == TREX)
	{
		total = area * PRICE_T;
	}
	return total;
}

void displayEstimate(string name, string num, string email, double area, int choice, double total)	//function that displays estimate summary with values gathered throughout the program
{
	string material;	//used for display purposes in the summary
	double taxable = 0;	//total taxable amount
	double grandTotal = 0;	//total after taxes
	double costPF = 0;	//used to display cost per foot
	taxable = total - (total * LABOR);		//total taxable amount calculation, total minus the labor portion
	grandTotal = (taxable + (taxable * TAX)) + (total - taxable);	//total after taxes equal to the taxable amount with taxes included, plus the labor without taxes included

	cout << fixed << showpoint << setprecision(2);	//formatting for 2 decimal places

	if (choice == WOOD)	//if material if wood, string and price variables are set to display correctly
	{
		material = W_STR_DISP;
		costPF = PRICE_W;
	}
	if (choice == TREX)	//if material is trex, string and price variables are set to display correctly
	{
		material = T_STR_DISP;
		costPF = PRICE_T;
	}

	//display summary for estimate with correct spacing
	cout << endl << endl << setw(28) << "Estimate:" << endl << endl;
	cout << "Customer Name: " << setw(18) << " " << name << endl;
	cout << "Telephone Number: " << setw(15) << " " << num << endl;
	cout << "Email Address: " << setw(18) << " " << email << endl << endl;
	cout << "Area of the deck: " << area << " square feet" << endl << endl;
	cout << "Material type selected: " << material << endl;
	cout << "Price per square foot: $" << costPF << endl << endl;
	cout << "Total Cost: " << setw(10) << "$" << total << endl;
	cout << "Taxes: " << setw(15) << "$" << taxable * TAX << endl;
	cout << "Final Cost: " << setw(10) << "$" << grandTotal << endl << endl;
	cout << "Date: March 25, 2022" << endl;
	cout << "This estimate is valid for 30 days from the above date." << endl;
}

void goodBye()	//simple goodbye function for program ending
{
	cout << endl;
	cout << "Thanks for visiting CSMY-141 Deck Builders." << endl;
	cout << "We'll have you decked out in no time!" << endl << endl;
}


double minTest(double value, string name)	//extra credit "smart" function; receives the value from another function to validate input and also recieves string value to correctly display which value is invalid
{
	double result = 0;	//result of the input and validation
	do	//loop for validation
	{
		cout << "Please enter the " << name << " of the deck(in feet) : ";
		cin >> value;
		if (value <= MIN_TEST)	//if statement for validation
		{
			cout << "Error: Invalid Entry. The " << name << " must be greater than zero." << endl << endl;
		}
	} while (value <= 0);
	cout << endl;
	result = value;	//value is validated and returned to function where it was called
	return result;
}

