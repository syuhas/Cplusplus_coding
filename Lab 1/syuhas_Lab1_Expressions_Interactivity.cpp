//Stephen Yuhas
//Lab - Expressions and Interactivity
//2-24-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const double dispFee = 12.75;	//disposal fee declared as a constant value, initialized to 12.75
	string make;	//make/model declared as a string value
	//all other variables declared below as doubles and initialized 
	double base = 0, wrnty = 0;
	double totalCost = 0, totalDue = 0;
	double downPay = 0;
	double finance = 0, monthly = 0;
	double tax = 0;

	//Title/copyright header
	cout << "Lab 1 - Expressions and Interactivity" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Input section for the make/model, base price and warranty
	cout << "Please enter the make and model of the cell phone: ";
	getline(cin, make);
	cout << endl << endl;
	cout << "Enter the base price of the cell phone: ";
	cin >> base;
	
	while (base <= 0)	//while statement prevents a 0 or negative value
	{
		cout << "Error - the base price of the cell phone cannot be less than or equal to $0.00. Please reenter here: ";
		cin >> base;	//reenter prompt if the value is <=0
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "Enter the cost of cellphone warranty: ";
	cin >> wrnty;

	while (wrnty <= 0)	//while statement prevents a 0 or negative value
	{
		cout << "Error - the base price of the cell phone cannot be less than or equal to $0.00. Please reenter here: ";
		cin >> wrnty;	//reenter prompt if the value is <=0
		cout << endl << endl;
	}
	cout << endl << endl;

	//all relevant calculations prepared for output
	tax = 0.06 * (wrnty + base);
	totalCost = wrnty + base + dispFee + tax;
	downPay = 0.14 * (base + wrnty);
	totalDue = downPay + dispFee + tax;
	finance = totalCost - totalDue;
	monthly = finance / 24;


	cout << fixed << showpoint << setprecision(2);	//set to show decimals in currency format, including whole integers

	//output with proper spacing for all varibles
	cout << "OUTPUT REPORT :" << endl;
	cout << "Make and Model: " << make << endl;
	cout << "Base Price: ";
	cout << setw(15) << "$" << setw(8) << base << endl;	//two setw commands used to space properly between the "$" and the actual amount
	
	cout << "Warranty Cost: ";
	cout << setw(12) << "$" << setw(8) << wrnty << endl;
	
	cout << "Disposal Fee: ";
	cout << setw(13) << "$" << setw(8) << dispFee << endl;
	
	cout << "Sales Tax: ";
	cout << setw(16) << "$" << setw(8) << tax << endl;
	
	cout << "Total Cost: ";
	cout << setw(15) << "$" << setw(8) << totalCost << endl;
	
	cout << "Downpayment: ";
	cout << setw(14) << "$" << setw(8) << downPay << endl;
	
	cout << "Total Due at Purchase: ";
	cout << setw(4) << "$" << setw(8) << totalDue << endl;
	
	cout << "Finance Amount: ";
	cout << setw(11) << "$" << setw(8) << finance << endl;
	
	cout << "Monthly Payment: ";
	cout << setw(10) << "$" << setw(8) << monthly << endl;

	cout << endl;
	
	system("pause");
	return 0;
	


}