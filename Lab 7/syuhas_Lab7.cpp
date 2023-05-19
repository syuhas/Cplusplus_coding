//Stephen Yuhas
//Lab 7 - Pointers
//4-24-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MIN = 0;	//const for minimum for validation
const int MAX = 35;	//const for max loads validation
const double WASH = 3.27;	//const revenue for the wash loads
const double DRY = 2.96;	//const revenue for the dry loads
const double EXP = 95.00;	//const for expenses

void welcome();					//proto welcome function
double average(int*, int);		//proto average function 
int howManyDryerLoads(int*, int);	//proto for counting dryer loads function
double calcRevenue(int*, int);	////proto for calculating revenue function
bool profit(int);		//proto for the function to see if profit was made
void hiWash(int*, int);	//(EXTRA CREDIT)proto for function to see what day had the highest loads




int main()
{
	int days = 0;	//variable for days input
	double avg = 0;	//variable for average calculation
	int dry = 0;	//variable for the dry loads calculation
	double revenue = 0;	//variable for revenue calculation
	bool profCh = false;	//bool variable to validate profit for each day
	int profCount = 0;	//variable for amount of days profit was made

	welcome();

	cout << "Please enter the number of days: ";
	do	//do/while for negative/zero validation of days
	{		
		cin >> days;
		if (days <= MIN)
		{
			cout << "The number of loads must be greater than zero. Please reenter: ";
		}
	} while (days <= MIN);
	

	int* loads = nullptr;		//create pointer and initialize to null
	loads = new int[days];		//dynamic array is allocated to hold user defined number of days

	for (int i = 0; i < days; i++)
	{
		cout << "Enter the number of loads washed for day " << i + 1 << ": ";
		do //do while for load number validation
		{	
			cin >> *(loads + i);
			if (*(loads + i) < MIN)
			{
				cout << "Negatives are not allowed. Please Reenter: ";	//min validation
			}
			if (*(loads + i) > MAX)
			{
				cout << "The maximum loads per day is 35. Please reenter: ";	//max validation
			}
		} while (*(loads + i) < MIN || *(loads + i) > MAX);
	}
	
	avg = average(loads, days);	//average loads is set to call the function to do the calculation

	cout << endl;

	cout << "The total number of loads washed is " << static_cast<double>(days) * avg << endl << endl;	//static cast the total equal to the days * the average to get the total back
	cout << fixed << setprecision(1) << "The average number of loads washed per day is " << avg << endl << endl;	//formatting to one decimal place

	dry = howManyDryerLoads(loads, days);	//dryer loads set to call the function to do the calculation

	cout << "The total number of loads dried is " << dry << endl << endl;

	cout << "The average number of loads dried per day is " << static_cast<double>(dry)/days << endl << endl;	//static cast the average as the dryer loads / days

	revenue = calcRevenue(loads, days);	//revenue set to call the function to do the revenue calculation

	cout << fixed << setprecision(2) << "The total revenue generated is $" << revenue << endl << endl;	//formatting with 2 decimal places for currency

	for (int i = 0; i < days; i++)
	{
		profCh = profit(*(loads+i));	//for each element of the dynamic array, it is sent to the function to see if profit was made
		if (profCh)
		{
			profCount++;	//if the function returns that a profit was made for the day, the profit counter increments
		}
	}

	cout << "There were " << profCount << " days in which the laundromat made a profit!" << endl;

	hiWash(loads, days);	//(EXTRA CREDIT) calls function to calculate and display the day with the highest number of loads

	delete[] loads;	//memory is deallocated

	loads = nullptr;	//pointer reset to nullptr

	system("pause");
	return 0;
	
}





void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 7 - Pointers" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Laundromat Profit Calculator" << endl << endl;

	return;
}

double average(int* loads, int days)	//function definition for the average calculation
{
	double avg = 0;	//variable for average
	double sum = 0;	//variable for sum

	for (int i = 0; i < days; i++)
	{
		sum += *loads;	//pointer notation to run through the array
		loads++;
	}
	avg = sum / days;
	return avg;	//average is returned after calculation
}

int howManyDryerLoads(int* loads, int days)	//function definition for the dry loads calculation
{
	int dry = 0;

	for (int i = 0; i < days; i++)
	{
		dry = dry + (*loads / 3);	//dry loads set to integer division to return result
		if ((*loads % 3) > MIN)		//if the modulus returns a result, the above division had a remainder and so we need to round up
		{
			dry++;	//round up by adding one to the amount of dryer loads
		}
		loads++;
	}
	
	return dry;	//return the dryer loads to main
}

double calcRevenue(int *loads, int days)	//function definition to calculate the revenue
{
	double washRev = 0;	//variable for wash revenue
	double dryRev = 0;	//variable for dryer revenue
	double totRev = 0;	//total revenue

	for (int i = 0; i < days; i++)
	{
		washRev += *loads * WASH;	//wash revenue = loads * revenue for each wash load
		
		dryRev += (*loads / 3) * DRY;	//dry revenue is the revenue for dry every 3 loads
		if ((*loads % 3) > MIN)	//if the last load is partial we round up; modulus will tell if there is a remainder
		{
			dryRev += DRY;	//increment one load worth of revenue if rounding up is required
		}
		loads++;
	}
	totRev = washRev + dryRev;
	return totRev;	//return calculation to main
}

bool profit(int loads)	//function definition to check for a profit for each day element sent in
{
	double wR = 0;	//wash revenue for each day
	double dR = 0;	//dry revenue for each day
	double tot = 0;	//total revenue for each day
	bool profit = false;	//bool to validate if a profit was made for the day

	wR = loads * WASH;	//wash revenue calculation
	dR = (loads / 3) * DRY;	//dry revenue calculation
	if ((loads % 3) > MIN)	//modulus calculation to round up if required
	{
		dR = dR + DRY;
	}

	tot = (dR + wR) - EXP;	//the total revenue minus the expenses

	if (tot > MIN)	//if the revenue exceeds the expenses.......
	{
		return profit = true;	//.....function returns a true value
	}
	else	//else, the day did not result in a profit.....
	{
		return profit = false;	//.....and the function returns a false value
	}
}

void hiWash(int *loads, int days)	//(EXTRA CREDIT) function defintion to find day with the highest washer loads
{
	int dL = 0;	//variable for loads for each day
	int hiDay = 0;	//variable for the day with the highest loads
	int hiLoad = 0;	//variable that contains the actual amount of loads for the highest day

	hiLoad = *loads;	//high loads set to element zero

	for (int i = 1; i < days; i++)	//run through the array starting at element one (the next value)
	{
		dL = *(loads + i);	//value to check saved to the variable
		if (dL > hiLoad)	//compared to the current highest value(starts at the first element)
		{
			hiLoad = dL;	//if it is higher than the current high, the new high is saved to the variable
			hiDay = i;		//the day it occured is saved
		}
	}
	cout << "The day with the highest washer loads was day " << hiDay + 1 << " with " << hiLoad << " loads." << endl << endl;	//print the results
	return;
}
