//Stephen Yuhas
//Exercise - Structures
//5-9-22

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

const double TAX = 0.06;	//constant for tax rate
const double BEVPRICE = 0.73;	//constant for beverage wholesale price
const int SIZE = 20;			//constant for size of c-string
const int MINV = 24;			//constant for minimum inventory
const int ZERO = 0;				//constant for a zero value in validation

struct beverage				//structure declaration for beverages
{
	char name[SIZE] = "none";	//c-string for ther name
	int num = 0;				//int for number of inventory
	double val = 0;				//double for value of inventory
	bool reorder = false;		//bool for reorder status
};

void welcome();		//proto for welcome display function
void dispBev(beverage*, int);	//proto for the display function of the beverages
double reOrder(int);			//(EXTRA CREDIT) proto for function that calculates ands returns the cost of ordering additional inventory with tax
void goodBye();			//proto for goodbye message function

int main()
{
	int bevAmt = 0;		//beverage amount input variable

	welcome();	//call welcome display function

	do  //do/while validation loop
	{
		cout << "Please enter the number of beverages: ";
		cin >> bevAmt;
		if (bevAmt <= ZERO)	//if beverages entered is less than or equal to zero, validation loop persists
		{
			"ERROR - Number of beverages must be greater than zero. Please reenter.";
		}
	} while (bevAmt <= ZERO);

	cin.ignore(1, '\n');	//ignore white space after cin
	
	cout << endl;

	beverage* bevArr = nullptr;		//set pointer to point to null the array of structures
	bevArr = new beverage[bevAmt];	//pointer set to the dynamically allocated array of structures

	for (int i = 0; i < bevAmt; i++)	//for loop for input of all structure array data
	{
		cout << "Please enter the beverage name: ";
		cin.getline(bevArr[i].name, SIZE);	//name of each beverage is input by user up to SIZE size

		do			//do/while loop used for inventory amount validation
		{
			cout << "Please enter the number of bottles in inventory for " << bevArr[i].name << ": ";	//print message to input number of beverage inventory
			cin >> bevArr[i].num;		//enter number of inventory
			if (bevArr[i].num <= ZERO)	//input is validated
			{
				cout << "Invalid Value. Please enter valid value." << endl << endl;
			}
		} while (bevArr[i].num <= ZERO);
		
		cin.ignore(10, '\n');	//ignore white space after cin
		
		cout << endl;

		bevArr[i].val = bevArr[i].num * BEVPRICE;	//calculation for value of each beverage inventory

		if (bevArr[i].num < MINV)	//determine whether or not a reorder is necessary
		{
			bevArr[i].reorder = true;	//set to true if reorder is required
		}
		else { bevArr[i].reorder = false; }	//set to false if no reorder is required
	}
	
	dispBev(bevArr, bevAmt);	//call function to display all beverage data
	
	delete[] bevArr;	//deallocate array
	bevArr = nullptr;	//set pointer to null

	goodBye();	//call function to print goodbye message

	system("pause");
	return 0;
}

void welcome()	//definition of function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "CE - Structures" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Beverage Inventory Calculator" << endl << endl;
	return;
}

void dispBev(beverage* bevArr, int num)		//definition of function to display beverages data
{
	int belowCase = 0;		//variable for amount of inventory below full case amount
	double reOrderCost = 0;	//variable to hold reorder cost calculated in function

	cout << fixed << showpoint << setprecision(2);	//formatting for currency

	cout << "Beverage Inventory Calculator" << endl;
	cout << "\tInventory Report" << endl << endl;

	for (int i = 0; i < num; i++)	// for loop to run through array structures
	{
		cout << "\tBeverage Name: " << bevArr->name << endl;	//display each name using struct pointer opreator notation 
		cout << "\tNumber in Inventory: " << bevArr->num << endl;	//display each inventory amount using struct pointer operator notation
		cout << "\tValue of Inventory: $" << bevArr->val << endl;	//display value of each item inventory using struct pointer operator notation
		if (bevArr->reorder)	//if bool value of inventory amount was set to true in main, reorder is required
		{
			belowCase = MINV - bevArr->num;		//amount below a full case is calculated
			cout << "\tWarning: Inventory is below one case." << endl;
			cout << "\tYou must order " << belowCase << " more " << bevArr->name << endl;
			reOrderCost = reOrder(belowCase);			//(EXTRA CREDIT) actual calculation for cost of additional orders done with a function call to a reorder function 
			cout << "\tThe cost with tax will be: $" << reOrderCost << endl << endl;
		}
		else if (!bevArr->reorder && bevArr->num == MINV)		//if the amount in inventory is equal to a case, a message is displayed and no further action is required
		{
			cout << "\tInventory equals exactly one case. No need to order additional " << bevArr->name << endl << endl;
		}
		else if (!bevArr->reorder)								//if the amount in inventory is more than a case, a message is displayed and no further action is required
		{
			
			cout << "\tInventory is greater than a case. No need to order additional " << bevArr->name << endl << endl;
		}
		bevArr++;	//pointer to array is incremented to the next element
	}
	return;
}

double reOrder(int amt)		//(EXTRA CREDIT) definition for reorder cost function
{
	double cost = 0;
	cost = ((BEVPRICE * TAX) + BEVPRICE)* amt;		//calculation for the cost of additional orders to make up a full case including tax
	return cost;	//return the cost to the display function
}

void goodBye()	//definition for goodbye message function
{
	cout << endl << endl;
	cout << "Thank you for using the Food Kiosk Profit Calculator. Goodbye!" << endl << endl;
}