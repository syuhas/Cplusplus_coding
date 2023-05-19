//Stephen Yuhas
//Exercise - Loops
//3-6-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Selections 1-4 all set as constant integers, set before main function
const int sand1 = 1;
const int fry2 = 2;
const int plat3 = 3;
const int bev4 = 4;
const int quit5 = 5;
//Const strings added to avoid hard coded numbers in menu (Extra credit requirement)
const string sandStr = "Sandwich";
const string fryStr = "French Fries";
const string platStr = "Platter";
const string bevStr = "Beverage";
const string quitStr = "Checkout";


const double cost1Disc = 2.75;	//discounted cost of sandwich
const double cost2Disc = 1.75;	//discounted cost of french fries
const double cost3Disc = 4.25;	//discounted cost of a platter
const double cost4Disc = 1.00;	//discounted cost of a beverage

int main()
{
	int choiceIn = 0;	//input int variable
	//variables for amount of each specific item
	int sandAmt = 0;
	int fryAmt = 0;
	int platAmt = 0;
	int bevAmt = 0;

	int sandCt = sandAmt;
	int fryCt = fryAmt;
	int platCt = platAmt;
	int bevCt = bevAmt;

	//these are set as non-constant doubles to allow them to change with the program
	double cost1 = 3.50;	//regular cost of sandwich
	double cost2 = 2.50;	//regular cost of french fries
	double cost3 = 5.00;	//regular cost of a platter
	double cost4 = 1.50;	//regular cost of a beverage
	double grandTotal = 0.00;	//grand total for the entire order

	


	//Display title section and copyright
	cout << "CE - Loops" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Menu display using setw for proper formatting
	cout << "Welcome to Steve's House O' Sandwiches and Fries. Here is our menu." << endl;
	cout << setw(5) << sand1 << ". " << sandStr << endl;
	cout << setw(5) << fry2 << ". " << fryStr << endl;
	cout << setw(5) << plat3 << ". " << platStr << endl;
	cout << setw(5) << bev4 << ". " << bevStr << endl;
	cout << setw(5) << quit5 << ". " << quitStr << endl;

	cout << fixed << showpoint << setprecision(2);	//formatting for currency output


	while (choiceIn != quit5)
	{
		cout << "Please enter the item to purchase from the menu above: ";
		cin >> choiceIn;	//Input for menu selection
		switch (choiceIn)	//Beginning of the switch statment to evalute menu item input
		{
		case sand1:	//Case 1, sandwich
		{
			cout << "Please enter the number of sandwiches you wish to buy: ";	//input number of items
			cin >> sandAmt;	//Input for number of items ordered

			if (sandAmt <= 0)	//error case for invalid number of items, tests each time
			{
				cout << "Error - The number of sandwiches must be greater than 0. Please reenter." << endl << endl;
			}
			else //this only accumulates the count if it passes the above test for a positive value
			{
				sandCt = sandCt + sandAmt;	//accumulates the total count of sandwiches
			}
			cout << endl;

			if (sandCt >= 4)	//if the amount reaches 4 or greater the price permanently changes to the discounted price
			{
				cost1 = cost1Disc;
			}

			if (sandAmt > 0)	//will only display if the amount entered is a positive value
			{
				cout << "The cost of a single sandwich is: $" << cost1 << endl;
				cout << "The cost of " << sandAmt << " sandwich(es) is $" << cost1 * sandAmt << endl << endl;	//output for one menu cycle for sandwiches
			}
			break;
		}

		case fry2:	//Case 2, french fries
		{
			cout << "Please enter the number of orders of french fries you wish to buy: ";	//input number of items
			cin >> fryAmt;	//Input for number of items ordered

			if (fryAmt <= 0)	//error case for invalid number of items, tests each time
			{
				cout << "Error - The number of orders of french fries must be greater than 0. Please reenter." << endl << endl;
			}
			else //this only accumulates the count if it passes the above test for a positive value
			{
				fryCt = fryCt + fryAmt;	//accumulates the total count of fries
			}
			cout << endl;

			if (fryCt >= 4)	//if the amount reaches 4 or greater the price permanently changes to the discounted price
			{
				cost2 = cost2Disc;
			}
			
			if (fryAmt > 0)	//will only display if the amount entered is a positive value
			{
				cout << "The cost of a single order of french fries is: $" << cost2 << endl;
				cout << "The cost of " << fryAmt << " order(s) of french fries is $" << cost2 * fryAmt << endl << endl;	//output for one menu cycle for fries
			}
			break;
		}

		case plat3:	//Case 3, platter
		{
			cout << "Please enter the number of platters you wish to buy: ";	//input number of items
			cin >> platAmt;	//Input for number of items ordered

			if (platAmt <= 0)	//error case for invalid number of items, tests each time
			{
				cout << "Error - The number of platters must be greater than 0. Please reenter." << endl << endl;
			}
			else //this only accumulates the count if it passes the above test for a positive value
			{
				platCt = platCt + platAmt;	//accumulates the total count of fries
			}
			cout << endl;

			if (platCt >= 4)	//if the amount reaches 4 or greater the price permanently changes to the discounted price
			{
				cost3 = cost3Disc;
			}
			
			if (platAmt > 0)	//will only display if the amount entered is a positive value
			{
				cout << "The cost of a single platter is: $" << cost3 << endl;
				cout << "The cost of " << platAmt << " platter(s) is $" << cost3 * platAmt << endl << endl;	//output for one menu cycle for platters
				cost4 = cost4Disc;	//all beverages set to discounted price now that a platter has been ordered
			}
			break;
		}

		case bev4:	//Case 4, beverage
		{
			cout << "Please enter the number of beverages you wish to buy: ";	//input number of items
			cin >> bevAmt;	//Input for number of items ordered

			if (bevAmt <= 0)	//error case for invalid number of items, tests each time
			{
				cout << "Error - The number of beverages must be greater than 0. Please reenter." << endl << endl;
			}
			else //this only accumulates the count if it passes the above test for a positive value
			{
				bevCt = bevCt + bevAmt;	//accumulates the total count of beverages
			}
			cout << endl;
			
			if (bevAmt > 0)	//will only display if the amount entered is a positive value
			{
				cout << "The cost of a single beverage is: $" << cost4 << endl;
				cout << "The cost of " << bevAmt << " beverage(s) is $" << cost4 * bevAmt << endl << endl;	//output for one menu cycle for beverages 
			}
			break;
		}

		case quit5: cout << endl << endl;	//Case 5, quit, used to break out of program to the goodbye message
			break;

		default: cout << "Error - this is not a valid option. Please try again." << endl << endl;	//Default to display error message
		}
	}


	//Grand Total Calculations (for Extra Credit) assesses all indivdual counts that were accumulated above and displays them here as a total cost

	grandTotal = ((cost1 * sandCt) + (cost2 * fryCt) + (cost3 * platCt) + (cost4 * bevCt));
	cout << "Grand Total: $" << grandTotal << endl << endl;
	cout << "Thanks for your business at Steve's House O' Sandwiches and Fries. Where Every Day is Fryday." << endl << endl;	//goodbye message

	system("pause");
	return 0;
}

	