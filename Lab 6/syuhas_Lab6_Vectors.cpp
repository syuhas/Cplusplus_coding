//Stephen Yuhas
//Lab 6 - Vectors and Range Based Loops
//4-18-22

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


const double RPS = 1.37;	//constant for revenue per sandwich
const double TAX_RATE = 0.06;	//constant for tax rate
const string Y1 = "Y", Y2 = "y", N1 = "N", N2 = "n";	//costant values for validation for termination of program
const int NEW_VAL = 1, AVG = 2, RTP = 3, EXIT = 4;		//constant values for menu swith statement
const double MIN = 0;	//constant value for minimum input validation




void welcome();		//proto for welcome function
int menu();		//proto for menu function to display the title and copyright
bool exit();	//proto for the function to validate to exit the program
int addSales();	//proto for function to add sales data to the vector
double avgSales(vector<int>);	//proto for function to get average number of sandwiches sold over all days
void calcRTP(vector<int>, double&, double&, double&);	//proto for function to calculate all required sales revenue data
void printRTP(vector<int>, double, double, double);		//proto for function to output the sales revenue data
void goodbye();
double calcSum(vector<int>);	//(EXTRA CREDIT): Common function called by average, revenue and output functions to use a range loop to calculate the sum used in all 3 functions






int main()
{
	int choice = 0;	//variable for the input choice in the switch statement
	bool exitFlag = true;	//variable boolean to validate to exit the program

	vector<int> transactions;	//vector that holds all revenue data
	int newSale = 0;	//variable to add each new revenue input

	double avg = 0;		//variable to calculate and store the average

	double revenue = 0, tax = 0, profit = 0;	//variables to calculate/store the revenue, tax and profit


	welcome();	//call function to print welcome title and copyright header
	
	do	//start of do/while loop to validate whether or not user wants to exit the program
	{
		choice = menu();	//call function to enter and validate user input 

		switch (choice)	//switch statement using the choice variable
		{
			case NEW_VAL:	//case 1: add new revenue data
			{
				newSale = addSales();	//call function to add a new sales revenue
				transactions.push_back(newSale);	//adds new sales data on to the end of the vector using pushback
				cout << endl;
				break;
			}

			case AVG:	//case 2: calculate average
			{
				avg = avgSales(transactions);	//call function to calculate the average sales				
				cout << "The average number of sandwiches sold per order is: " << avg << endl << endl;
				break;
			}

			case RTP:	//case 3: calculate revenue, tax and profit and print the results
			{
				calcRTP(transactions, revenue, tax, profit);	//call function to calculate the revenue, tax and profit, using reference parameters
				printRTP(transactions, revenue, tax, profit);	//call function to then print the sales data
				break;
			}

			case EXIT:	//case 4: prompt user to exit the program or return to menu
			{
				exitFlag = exit();	//call function to validate exiting the program, will return true or false after input has been validated
				break;
			}

			default:	//default case for invalid input
			{
				cout << "Error - Please enter a valid menu item." << endl << endl;	//error case, no valid input was entered, loop persists
				break;
			}

		}
	} while (exitFlag);	//end of do/while statment, only exits the loop if the call to the validation function returns a false value after the user enters 'y' or 'Y' 

	goodbye();	//call function to print goodbye message

	system("pause");
	return 0;
}

void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 6 - Vector" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Sandwich Revenue Calculation Program" << endl << endl;
	return;
}

int menu()	//function definition to print the menu and return the input
{
	int choice = 0;	//temporary variable for input choice
	cout << "Input Menu" << endl;
	cout << "1. Enter a new value sold" << endl << "2. Calculate the average sold: " << endl;
	cout << "3. Calculate the revenue, tax and profit " << endl << "4. End Program" << endl;
	cout << "Enter the menu option here: ";
	cin >> choice;
	cin.ignore(1, '\n');	//fixes cin skip for subsequent getline
	cout << endl;
	return choice;
}

int addSales()	//function definition to add sales revenue data to vector
{
	int num = 0;	//temporary variable for new sales revenue amount
	do	//do/while loop validates input for positive value
	{
		cout << "Input the number of sandwiches sold: ";
		cin >> num;
		if (num < MIN)	//input validation for values zero or less
		{
			cout << "Error - Number of sandwiches must be greater than zero. Please reenter!" << endl << endl;
		}
	} while (num < MIN);
	return num;
}

double avgSales(vector<int> transactions)	//function definition to get average sales
{
	int vecSize = transactions.size();	//size of vector set to varible to use for average calculation 
	double sum = calcSum(transactions);	//(EXTRA CREDIT) call function to calculate sum 
	double avg = 0;	//temporary variable for average
	cout << fixed << showpoint << setprecision(1);	//formatting to one decimal point
	avg = sum / vecSize;	//average set to sum divided by the size of the vector
	return avg;
}

void calcRTP(vector<int> transactions, double& revenue, double& tax, double& profit)	//function definition to calculate the sales data using reference parameters
{
	double sum = calcSum(transactions);	//(EXTRA CREDIT) call function to calculate sum
	revenue = sum * RPS;	//revenue equal to sum divided by the revenue per sandwich
	tax = revenue * TAX_RATE;	//tax equal to the revenue multiplied by the tax rate
	profit = revenue - tax;	//profit is equal to the revenue minus the tax
	return;
}

void printRTP(vector<int> transactions, double r, double t, double p)	//function definition to print the sales data
{
	int vecSize = transactions.size();	//size of vector set to varible to use for display 'for' loop 
	int i = 0;	//counter for displaying each day
	int sum = calcSum(transactions);	//(EXTRA CREDIT) call function to calculate sum
	
	for (auto sale : transactions)	//range based for loop to display each sales day
	{
		cout << "\tSale # " << i + 1 << ": " << sale << endl;
		i++;
	}
	
	
	cout << "The total number of transactions is: " << vecSize << endl;
	cout << "The total number of sandwiches sold is: " << sum << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "The total revenue is: $" << r << endl;
	cout << "The total tax is: $" << t << endl;
	cout << "The total profit is: $" << p << endl << endl;
}

bool exit()	//boolean function definition to validate whether or not user would like to exit the program
{
	bool exitFlag = true;	//bool flag to return to main
	bool valid = false;	//bool flag to validate input
	string choice;	//variable for user input

	do	//do/while loop validates the user input
	{
		cout << "Do you wish to exit the program (y/n)? ";
		getline(cin, choice);
		if (choice == Y1 || choice == Y2)	//user enters 'y' or 'Y'
		{
			exitFlag = false;	//function will return 'false' to main() to exit program
			valid = true;		//valid flag set to 'true' to exit the validation loop
		}
		else if (choice == N1 || choice == N2)	//user enters 'n' or 'N'
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

double calcSum(vector<int> transactions)	//(EXTRA CREDIT) common function used by 3 above functions to get the sum of the data
{
	double sum = 0;	//variable for sum
	for (auto sale : transactions)	//range based for loop to run through each element
	{
		sum += sale;	//sum is added up
	}
	return sum;	//sum is returned to each function 
}

void goodbye()	//function definition to print goodbye message
{
	cout << endl << endl << "Thank you for using the Sandwich Revenue Calculation Program!! Goodbye!!" << endl << endl;
}