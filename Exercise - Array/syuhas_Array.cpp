//Stephen Yuhas
//Exercise - Array
//4-2-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int DAYS = 7;			//test constant for days of the week
const double ZERO_TEST = 0;	//test constant for zero
const int ZERO = 0;			//start constant for 'for' loops
const double TAX = 0.06;	//tax rate

void welcome();					//proto welcome function
bool testRev(double);			//proto for revenue test function	
void titleReport(double[]);		//proto for title display function
double sumRev(double[]);		//proto for function to sum up revenues
double avgRev(double[]);		//proto for function to average revenues


int main()
{
	double revPerDay[DAYS];	//array is defined to hold constant of 7
	double revSum = 0;	//variable for sum of revenues
	double revAvg = 0;	//average revenue variable
	bool validRev = true;	//bool variable to validate the revenue input
	double taxSum = 0;	//variable for sum of tax revenue
	double taxAvg = 0;	//variable for average tax revenue
	double profSum = 0;	//variable for profit sum
	double profAvg = 0;	//variable for profit average

	welcome();		//calls welcome function to display title and copyright

	cout << fixed << showpoint << setprecision(2);	//formatting to display 2 decimal places

	cout << "Please enter the gross revenue for " << endl;
	for (int i = ZERO; i < DAYS; i++)	//beginning of for statement to run through each element of array and assign an input value
	{
		validRev = true;	//bool variable set to true to validate input is > 0
		do
		{
			cout << "\tDay " << i + 1 << ": $";
			cin >> revPerDay[i];	//input for array variable i each time the loop runs
			validRev = testRev(revPerDay[i]);	//calls function to test input. function returns a true if <= 0 and false if > 0
		} while (validRev);	//loop persists if a true value is returned from the test function
	}
	cout << endl << endl;

	titleReport(revPerDay);	//function to call revenue report

	revSum = sumRev(revPerDay);	//calls function to sum up revenues and returns the revenue sum as a variable

	revAvg = avgRev(revPerDay);	//calls function to average revenues and returns the revenue average as a variable

	cout << endl << endl;

	cout << "Total Revenue for the Week: $" << revSum << endl;
	cout << "Average Revenue per day: $" << revAvg << endl << endl;
	
	taxSum = revSum * TAX;	//tax sum set as the tax rate * the total revenue
	taxAvg = taxSum / DAYS;	//tax average set as the tax sum divided by number of revenues
	profSum = revSum - taxSum;	//profit sum set as the revenue minus the tax sum
	profAvg = profSum / DAYS;	//profit average set as the profit sum divided by the number of revenue entries

	cout << "Total Tax for the week: $" << taxSum << endl;
	cout << "Average Tax for the week: $" << taxAvg << endl << endl;
	cout << "Total Profit for the week: $" << profSum << endl;
	cout << "Average Profit for the week: $" << profAvg << endl << endl;

	cout << "Thank you for using the Food Kiosk Profit Calculator. Goodbye!" << endl << endl;

	system("pause");
	return 0;
}





void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "CE - Array" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Food Kiosk Profit Calculator" << endl << endl;
	
	return;
}

bool testRev(double test)	//function definition for the test function to validate the revenue input (EXTRA CREDIT PORTION)
{
	bool result = true;
	if (test <= ZERO_TEST)	//if the revenue entered is 0 or less, returns a 'true' value to the variable, restarting the validation loop in main
	{
		cout << "Invalid Value. Please enter a valid revenue greater than zero." << endl;
	}
	else
	{
		result = false;		//once validated as greater than zero, a 'false' value is returned to main and exits the validation loop
	}
	return result;	//return the resulting value of the bool variable
}

void titleReport(double revData[])		//function definition to print the revenue report, array argument sent in from main
{
	cout << "Food Kiosk Profit Calculator" << endl;
	cout << "\tSales Report:" << endl << endl;
	for (int i = ZERO; i < DAYS; i++)	//'for' loop runs through each element of the array parameter and prints the value
	{
		cout << "\tDay " << i + 1 << ": $" << revData[i] << endl;
	}
}

double sumRev(double revData[])	//function definition to sum revenues using array argument from main
{
	double sum = 0;
	for (int i = ZERO; i < DAYS; i++)	//runs through each element of the array parameter and adds them up
	{
		sum += revData[i];	//each element of the array is added to the sum variable
	}
	return sum;
}

double avgRev(double revData[])
{
	double avg = 0;
	double sum = 0;
	for (int i = 0; i < DAYS; i++)	//runs through each element of the array parameter and adds them up, sum is then averaged
	{
		sum += revData[i];	//each element is added to sum variable to be averaged
	}
	avg = sum / DAYS;	//average revenue is the sum divided by number of elements
	return avg;	//average is returned to main
}