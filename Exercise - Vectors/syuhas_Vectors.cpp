//Stephen Yuhas
//Exercise - Vectors and the Range Based Loop
//4-5-22

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const int MIN_TEST = 0;	//constant for value for minimum validation
const int POP = 2;	//pop back constant
const int TEST_CT = 0;	//minimum constant to start testing for duplicates

void welcome();		//proto for welcome function
void dispInv(vector<string>);	//proto for display inventory function
bool testItem(vector<string>, string);	//proto for test function that validates for duplicate inputs
void goodbye();	//proto for goodbye message function




int main()
{
	vector<string> inventory;	//vector for inventory items
	int invCt = 0;	//inventory variable for amount of items to input
	string item = " ";	//string varible for item input
	string newBev = " ";	//string varible for adding new item
	welcome();	//call welcome function to print welcome message
	bool testBev = false;	//bool test variable to test for duplicate inputs

	do	//do/while loop for negative input validation
	{
		cout << "Enter the number of beverages you have in inventory: ";	
		cin >> invCt;	//input the number of items to add to inventory vector
		cin.ignore(1, '/n');	//needed to ignore previous cin statement
		if (invCt < 0)	//validation for negative input value
		{
			cout << "Error - please enter a number greater than 0." << endl << endl;
		}
	} while (invCt < 0);

	cout << endl;
	
	for (int i = 0; i < invCt; i++)	//for loop runs through each element and fills it with the string value
	{
		cout << "Please enter the name of beverage " << i + 1 << ": ";
		do
		{			
			getline(cin, item);	//input the inventory item for each element
			if (i > TEST_CT)	//calls bool duplicate tester function when there is one element in the vector
			{
				testBev = testItem(inventory, item);	//call function to test for duplicate input and returns bool flag for the loop (EXTRA CREDIT)
			}
			if (testBev)	//if bool flag returns true, error will display and prompt for reinput
			{
				cout << "Error - This beverage already exists. Please enter a different beverage: ";
			}
		} while (testBev);

		inventory.push_back(item);	//pushback to add each new element to the vector
	}

	cout << endl << endl;
	dispInv(inventory);	//calls function to display the vector

	cout << endl << "Please enter in the new beverage name: ";
	do //do/while loop to validate new item input for duplicates
	{
		getline(cin, newBev);
		testBev = testItem(inventory, newBev);	//calls bool function and returns bool flag for validation
		if (testBev)
		{
			cout << "Error - This beverage already exists. Please enter a new beverage: ";
		}
	} while (testBev);

	inventory.push_back(newBev);	//adds new inventory item

	cout << endl;

	dispInv(inventory);	//display inventory vector after new added item

	for(int i = 0; i < POP; i++)	//for loop to remove last two elements
	{
		inventory.pop_back();	//removes last element of the vector, runs twice
	}	

	dispInv(inventory);	//display inventory after pop back

	inventory.clear();	//clear inventory

	dispInv(inventory);	//display empty inventory

	goodbye();	//call function to display goodbye message


	system("pause");
	return 0;
}





void welcome()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "CE - Vector" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Food Kiosk Beverage Inventory List" << endl << endl;
	return;
}

void dispInv(vector<string> inv)	//function header for function to display vector and vector size
{
	int vecSize = inv.size();	//uses int variable to display size of vector
	cout << "Beverage List :" << endl;
	for (string name : inv)	//range based for loop to display vector
	{
		cout << "\t" << name << endl;
	}
	cout << "The total number of beverages is: " << vecSize << endl << endl;
	return;
}

bool testItem(vector<string> inv, string newBev)	//(EXTRA CREDIT) function header for duplicate checking, sends in vector and variable to check, returns bool flag as true (duplicate) or false (unique)
{
	bool testBev = false;	//test is reset to false
	int size = inv.size();	//size of the loop is set by checking the size of the vector
	for (int i = 0; i < size; i++)	//runs through all of the current elements in the vector and checks each for duplicate
	{
		if (newBev == inv[i])	//if duplicate, function returns true and loop in main persists
		{
			testBev = true;
		}
	}
	return testBev;	//bool flag is returned to main with either a true or false value
}

void goodbye()	//function header for print goodbye message function
{
	cout << "Thank you for using the Beverage Inventory Control Program. Goodbye!";
	cout << endl << endl;
}