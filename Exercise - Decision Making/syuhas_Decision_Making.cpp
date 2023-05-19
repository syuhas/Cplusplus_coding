//Stephen Yuhas
//Exercise - Decision Making
//2-27-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const string food1 = "sandwich";	//constants for the two menu items
	const string food2 = "french fries";	//
	//variables for the regular and discounted costs of both items initialized and declared as double
	double cost1 = 3.50;	//regular cost of sandwich
	double cost1Disc = 2.75;	//discounted cost of sandwich
	double cost2 = 2.50;	//regular cost of french fries
	double cost2Disc = 1.75;	//discounted cost of french fries
	int itemAmt = 0;	//variable for amount of items desired declared as int and initialized 
	string foodIn;	//input for food choice, declared as string

	//Display title section and copyright
	cout << "CE - Decision Making" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//getline input for longer string
	cout << "Please enter the item to purchase (sandwich or french fries): ";
	getline(cin, foodIn);
	

	cout << fixed << showpoint << setprecision(2);	//formatting for currency output




	if (foodIn != food1 && foodIn != food2)	//error message for food input not equal to either constant options
	{
		cout << "Error - this is not a valid option. Please try again." << endl << endl;	//output error message
	}



	if (foodIn == food1)	//start of input for sandwich option
	{
		cout << "Please enter the number of sandwiches you wish to buy: ";	//input number of items
		cin >> itemAmt;
		cout << endl;
		if (itemAmt <= 0)	//number of sandiwches is less or equal to zero, outputs and sets prices to zero
		{
			cout << "This is an invalid number of items. Please try again." << endl << endl;	//output error message
			cost1 = 0.00, cost1Disc = 0.00;	//set costs to zero
			cout << "The cost of a single sandwich is: $" << cost1 << endl;
			cout << "The cost of " << itemAmt << " sandwich(es) is $" << cost1 << endl << endl;	//display zero-ed out values
		}
		if (itemAmt == 1)	//output for one sandwich
		{
			cout << "The cost of a single sandwich is: $" << cost1 << endl << endl;
		}
		if (itemAmt > 1 && itemAmt < 4)	//output for 1 to 3 sandwiches
		{
			cout << "The cost of a single sandwich is: $" << cost1 << endl;
			cout << "The cost of " << itemAmt << " sandwiches is " << cost1 * itemAmt << endl << endl;	//calculation for regular price
		}
		if (itemAmt >= 4)	//output with discount for 4 or more sandwiches
		{
			cout << "The cost of a single sandwich is: $" << cost1Disc << endl;
			cout << "The cost of " << itemAmt << " sandwiches is " << cost1Disc * itemAmt << endl << endl;	//calculation for discount
		}


	}
	



	if (foodIn == food2)	//start of input for french fries option
	{
		cout << "Please enter the number of french fries you wish to buy: ";	//input number of items
		cin >> itemAmt;
		cout << endl;
		if (itemAmt <= 0)	//number of french fries is less or equal to zero, outputs and sets prices to zero
		{
			cout << "This is an invalid number of items. Please try again." << endl << endl;
			cost2 = 0.00, cost2Disc = 0.00;
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
			cout << "The cost of " << itemAmt << " orders of french fries is " << cost2 * itemAmt << endl << endl;	//calculation for regular price
		}
		if (itemAmt >= 4)	//output for 4 or more orders of french fries
		{
			cout << "The cost of a single order of french fries is: $" << cost2Disc << endl;
			cout << "The cost of " << itemAmt << " orders of french fries is " << cost2Disc * itemAmt << endl << endl;	//calculation for discount
		}
	}


	cout << "Thanks for your business at Steve's House O' Sandwiches and Fries. Where Every Day is Fryday." << endl << endl;	//goodbye message

	system("pause");
	return 0;

	

}