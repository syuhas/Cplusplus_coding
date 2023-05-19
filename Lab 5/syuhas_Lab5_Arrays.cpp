//Stephen Yuhas
//Lab 5 - Arrays
//4-5-22

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int ITEMS = 3;	//constant for number of items in array
const int DAYS = 7;		//constant for number of days in array
const int INIT = 0;		//initializing value constant for best and worst seller 'for' loops
const int A = 0;		//constant value for item 1 for best seller calculation
const int B = 1;		//constant value for item 2 for best seller calculation
const int C = 2;		//constant value for item 3 for best seller calculation


void welcome();	//proto for welcome function
void dataIn(string[], int[][DAYS]);		//proto for data input function
void printData(const string[], const int[][DAYS]);	//proto for item table function
void avgData(const string[], const int[][DAYS]);	//proto for function to average items
void dailyLow(const string[], const int[][DAYS]);	//proto for function to calculate daily low seller
void dailyHi(const string[], const int[][DAYS]);	//proto for function to calculate daily low seller
void bestSeller(const string[], const int[][DAYS]);	//proto for function to calculate best seller





int main()
{
	string inventory[ITEMS] = { "none", "none", "none" };	//definition for array to hold item names
	int sales[ITEMS][DAYS] = { { 0, 0, 0, 0, 0, 0, 0},		//definition for array to hold item data
		                       { 0, 0, 0, 0, 0, 0, 0}, 
		                       { 0, 0, 0, 0, 0, 0, 0} };

	welcome();	//call function to print welcome message and copyright
	
	dataIn(inventory, sales);	//call function to input data from text file
	
	cout << endl << endl;
	
	printData(inventory, sales);	//call function to print item table
	
	cout << endl << endl;

	avgData(inventory, sales);		//call function to average items

	cout << endl << endl;

	dailyLow(inventory, sales);		//call function to calculate daily low
	
	cout << endl << endl;

	dailyHi(inventory, sales);		//call function to calculate daily high

	cout << endl << endl;

	bestSeller(inventory, sales);		//call function to calculate best seller for most days

	cout << endl << endl << endl;

	system("pause");
	return 0;
}

void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 5 - Arrays" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Food Kiosk Inventory Program" << endl << endl;

	return;
}

void dataIn(string inventory[], int sales[][DAYS])	//function pulls data from a text file and user inputs item names(EXTRA CREDIT)
{
	for (int i = 0; i < ITEMS; i++)
	{
		cout << "Enter the name of the inventory item #" << i + 1 << ": ";
		getline(cin, inventory[i]);
	}

	ifstream iFile;		//set as file input variable
	iFile.open("c:\\test\\data.txt");	//location set to open text file and set as varible
	if (!iFile)		//error message for inability to find/open file
	{
		cout << "Error - Could not locate data file." << endl;
	}
	else
	{
		for (int i = 0; i < ITEMS; i++)		//run through each element of 2-dimensional array with nested for loops
		{
			for (int j = 0; j < DAYS; j++)
			{
				iFile >> sales[i][j];	//set each array position to subsequent file data as loop progresses
			}
		}
	}
	return;
}

void printData(const string inventory[], const int sales[][DAYS])	//function prints the item table
{
	cout << left << setw(20) << "Item";
	for (int i = 0; i < DAYS; i++)	//for loop for 'day' display row with formatting
	{
		cout << right << setw(10) << "Day " << i + 1;
	}
	cout << endl;
	cout << left << setw(20) << "----";
	for (int i = 0; i < DAYS; i++)	//for loop for formatting line gap
	{
		cout << right << setw(11) << "-----";
	}
	for (int i = 0; i < ITEMS; i++)	//for loop to display each item name
	{
		cout << endl;
		cout << left << setw(20) << inventory[i];

		for (int j = 0; j < DAYS; j++)	//nested for loop to display each item sales 
		{
			cout << right << setw(10) << sales[i][j] << " ";
		}
	}
	return;
}

void avgData(const string inventory[], const int sales[][DAYS])	//function averages sales data
{
	cout << left << setw(20) << "Item" << right << setw(20) << "Average Sold" << endl;
	cout << left << setw(20) << "____" << right << setw(20) << "____________" << endl << endl;
	cout << fixed << showpoint << setprecision(1);
	
	for (int i = 0; i < ITEMS; i++)	//for loop for items
	{
		double sum = 0;	//sum variable for average calculation
		double avg = 0;	//average varibale for average calculation
		cout << left << setw(20) << inventory[i];
		
		for (int j = 0; j < DAYS; j++)	//nested for loop for items
		{
			sum += sales[i][j];	//sum is added up as loop runs through each element
		}

		avg = sum / DAYS;	//average is calculated
		cout << right << setw(17) << avg << endl;	//average is displayed

	
	}
	return;
}

void dailyLow(const string inventory[], const int sales[][DAYS])	//function calculates daily low seller
{
	int lowVal = sales[INIT][INIT];	//low value variable initialized to first element position in sales array
	string lowStr = inventory[INIT];	//string variable will hold the text value of the lowest seller

	int lowDay = INIT;	//variable will hold value of the day that the lowest sales occured

	for (int i = 0; i < ITEMS; i++)
	{										//nested for loops to run through each element of 2-dimension array
		for (int j = 0; j < DAYS; j++)
		{
			if (sales[i][j] < lowVal)	
			{							//checks each element for lowest value saves if lower than the previous....
				lowVal = sales[i][j];
				lowStr = inventory[i];	//....then also saves the name of the item.....
				lowDay = j;				//....and lastly the day on which the sales occured for the lowest sales item.
			}
		}
	}

	cout << endl << "Item " << lowStr << " sold the lowest amount, " << lowVal << ", on day " << lowDay +1 << ".";	//data is printed with name of item in output(EXTRA CREDIT)
	return;
}

void dailyHi(const string inventory[], const int sales[][DAYS])	//function calculates daily best seller
{
	int hiVal = sales[INIT][INIT];	//high value variable initialized to first element position in sales array
	string hiStr = inventory[INIT];	//string variable will hold the text value of the highest seller
	
	int hiDay = INIT;				//variable will hold value of the day that the highest sales occured

	for (int i = 0; i < ITEMS; i++)
	{									//nested for loops to run through each element of 2-dimension array
		for (int j = 0; j < DAYS; j++)
		{
			if (sales[i][j] > hiVal)
			{							//checks each element for highest value saves if higher than the previous....
				hiVal = sales[i][j];
				hiStr = inventory[i];	//....then also saves the name of the item.....
				hiDay = j;				//....and lastly the day on which the sales occured for the lowest sales item.
			}
		}
	}

	cout << endl << "Item " << hiStr << " sold the highest amount, " << hiVal << ", on day " << hiDay + 1 << ".";	//data is printed with name of item in output(EXTRA CREDIT)
	return;
}

void bestSeller(const string inventory[], const int sales[][DAYS])		//function calculates the best seller over the most days(EXTRA CREDIT)
{
	int winner[ITEMS] = { 0, 0, 0, };	//parallel array created to tally winners for each day

	for (int i = 0; i < DAYS; i++)	//for loop to run through each secondary element (days) of the sales array
	{
		if (sales[A][i] > sales[B][i] && sales[A][i] > sales[C][i])		//if statements check each item for days 1-7, tallies the winner for each day in parallel array
		{
			winner[A] = winner[A] + 1;
		}
		if (sales[B][i] > sales[A][i] && sales[B][i] > sales[C][i])
		{
			winner[B] = winner[B] + 1;
		}
		if (sales[C][i] > sales[A][i] && sales[C][i] > sales[B][i])
		{
			winner[C] = winner[C] + 1;
		}
	}

	if (winner[A] > winner[B] && winner[A] > winner[C])		//if statements check for the overall winner with the most sales on the most days, displays the winner
	{
		cout << endl << "Item " << inventory[A] << " had the most days with the highest sales, " << winner[A] << " days!";
	}
	if (winner[B] > winner[A] && winner[B] > winner[C])
	{
		cout << endl << "Item " << inventory[B] << " had the most days with the highest sales, " << winner[B] << " days!";
	}
	if (winner[C] > winner[A] && winner[C] > winner[B])
	{
		cout << endl << "Item " << inventory[C] << " had the most days with the highest sales, " << winner[C] << " days!";
	}
	return;
}
