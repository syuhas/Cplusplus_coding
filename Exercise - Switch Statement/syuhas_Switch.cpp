//Stephen Yuhas
//Exercise - Switch Statement
//2-27-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Selections 1-4 all set as constant integers, set before main function
const int sand1 = 1;
const int fry2 = 2;
const int plat3 = 3;
const int quit4 = 4;
//Const strings added to avoid hard coded numbers in menu (Extra credit requirement)
const string sandStr = "Sandwich";
const string fryStr = "French Fries";
const string platStr = "Platter";
const string quitStr = "Checkout";

int main()
{
	int choiceIn = 0;	//input int variable
	int itemAmt = 0;	//variable for amount of items desired declared as int and initialized 

	double cost1 = 3.50;	//regular cost of sandwich
	double cost1Disc = 2.75;	//discounted cost of sandwich
	double cost2 = 2.50;	//regular cost of french fries
	double cost2Disc = 1.75;	//discounted cost of french fries
	double cost3 = 5.00;	//regular cost of a platter
	double cost3Disc = 4.25;	//discounted cost of a platter

	
	//Display title section and copyright
	cout << "CE - Switch Statement" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Menu display using setw for proper formatting
	cout << "Welcome to Steve's House O' Sandwiches and Fries. Here is our menu." << endl;
	cout << setw(5) << sand1 << ". " << sandStr << endl;
	cout << setw(5) << fry2 << ". " << fryStr << endl;
	cout << setw(5) << plat3 << ". " << platStr << endl;
	cout << setw(5) << quit4 << ". " << quitStr << endl;
	cout << "Please enter the item to purchase from the menu above: ";

	cout << fixed << showpoint << setprecision(2);	//formatting for currency output

	cin >> choiceIn;	//Input for menu selection

	switch (choiceIn)	//Beginning of the switch statment to evalute menu item input
	{
		case sand1:	//Case 1, sandwich
		{
			cout << "Please enter the number of sandwiches you wish to buy: ";	//input number of items
			cin >> itemAmt;	//Input for number of items ordered
			cout << endl;
			if (itemAmt <= 0)	//number of sandiwches is less or equal to zero, outputs and sets prices to zero
			{
				cout << "This is an invalid number of items. Please try again." << endl << endl;	//output error message
				cost1 = 0.00, cost1Disc = 0.00;	//set costs to zero
				cout << "The cost of a single sandwich is: $" << cost1 << endl;
				cout << "The cost of " << itemAmt << " sandwiches is $" << cost1 << endl << endl;	//calculation for regular price
			}
			if (itemAmt == 1)	//output for one sandwich
			{
				cout << "The cost of a single sandwich is: $" << cost1 << endl << endl;
			}
			if (itemAmt > 1 && itemAmt < 4)	//output for 1 to 3 sandwiches
			{
				cout << "The cost of a single sandwich is: $" << cost1 << endl;
				cout << "The cost of " << itemAmt << " sandwiches is $" << cost1 * itemAmt << endl << endl;	//calculation for regular price
			}
			if (itemAmt >= 4)	//output with discount for 4 or more sandwiches
			{
				cout << "The cost of a single sandwich is: $" << cost1Disc << endl;
				cout << "The cost of " << itemAmt << " sandwiches is $" << cost1Disc * itemAmt << endl << endl;	//calculation for discount
			}
			break;
		}

		case fry2:	//Case 2, french fries
		{
			cout << "Please enter the number of french fries you wish to buy: ";
			cin >> itemAmt;	//Input for number of items ordered
			cout << endl;
			if (itemAmt <= 0)	//number of french fries is less or equal to zero, outputs and sets prices to zero
			{
				cout << "This is an invalid number of items. Please try again." << endl << endl;
				cost2 = 0.00, cost2Disc = 0.00;	//set costs to zero
				cout << "The cost of a single order of french fries is: $" << cost2 << endl;
				cout << "The cost of " << itemAmt << " orders of french fries is $" << cost2 << endl << endl;	//display zero-ed out values
			}
			if (itemAmt == 1)	//output for 1 order of french fries
			{
				cout << "The cost of a single order of fries is: $" << cost2 << endl << endl;
			}
			if (itemAmt > 1 && itemAmt < 4)	//output for 1 to 3 orders of french fries
			{
				cout << "The cost of a single order of french fries is: $" << cost2 << endl;
				cout << "The cost of " << itemAmt << " orders of french fries is $" << cost2 * itemAmt << endl << endl;	//calculation for regular price
			}
			if (itemAmt >= 4)	//output for 4 or more orders of french fries
			{
				cout << "The cost of a single order of french fries is: $" << cost2Disc << endl;
				cout << "The cost of " << itemAmt << " orders of french fries is $" << cost2Disc * itemAmt << endl << endl;	//calculation for discount
			}
			break;
		}

		case plat3:	//Case 3, platter
		{
			cout << "Please enter the number of platters you wish to buy: ";
			cin >> itemAmt;	//Input for number of items ordered
			cout << endl;
			if (itemAmt <= 0)	//number of platters is less or equal to zero, outputs and sets prices to zero
			{
				cout << "This is an invalid number of items. Please try again." << endl << endl;
				cost3 = 0.00, cost3Disc = 0.00;	//set costs to zero
				cout << "The cost of a single platter is: $" << cost3 << endl;
				cout << "The cost of " << itemAmt << " platters is $" << cost3 << endl << endl;	//display zero-ed out values
			}
			if (itemAmt == 1)	//output for 1 order of french fries
			{
				cout << "The cost of a single platter is: $" << cost3 << endl << endl;
			}
			if (itemAmt > 1 && itemAmt < 4)	//output for 1 to 3 orders of french fries
			{
				cout << "The cost of a single platter is: $" << cost3 << endl;
				cout << "The cost of " << itemAmt << " platters is $" << cost3 * itemAmt << endl << endl;	//calculation for regular price
			}
			if (itemAmt >= 4)	//output for 4 or more orders of french fries
			{
				cout << "The cost of a single platter is: $" << cost3Disc << endl;
				cout << "The cost of " << itemAmt << " platters is $" << cost3Disc * itemAmt << endl << endl;	//calculation for discount
			}
			break;
		}

		case quit4: cout << endl << endl;	//Case 4, quit, used to break out of program to the goodbye message
			break;

		default: cout << "Error - this is not a valid option. Please try again." << endl << endl;	//Default to display error message
	}
	

	cout << "Thanks for your business at Steve's House O' Sandwiches and Fries. Where Every Day is Fryday." << endl << endl;	//goodbye message

	system("pause");
	return 0;
}