//Stephen Yuhas
//Exercise - Decisions and Loops
//3-9-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//all string constants for inventory menu display
const string INKSTR = "Printer Ink";
const string STAPSTR = "Staplers";
const string PAPSTR = "Printer Paper";
const string PENSTR = "Pens";
const string CHECKSTR = "Checkout";

//constant integers for inventory menu choices
const int INK1 = 1;
const int STAP2 = 2;
const int PAP3 = 3;
const int PEN4 = 4;
const int CHECK5 = 5;

//paper inventory split into two unit sizes, ream and case
const int UNITREAM = 1;
const int UNITCASE = 2;

//all constant values that will not change throughtout the program, used to change other variable values
const double INKCOST = 40.25;
const double STAPCOSTFULL = 8.00;	//value for "NONE" discount code
const double STAPDISC = 5.75;	//value for "disc stap" discount code
const double PAPREAMDISC = 3.00;
const double PAPCASEDISC = 17.25;
const double PENCOST1 = 1.99;
const double PENCOST2 = 1.69;	//first pen discount (6-10)
const double PENCOST3 = 1.29;	//second pen discount (11+)
const double TAXRATE = 0.06;	//tax rate used to calculate sales tax

//string constants for discount code values
const string CODEDISC = "disc stap";
const string CODENONE = "NONE";





int main()
{
	//inputs for menu choice and all subsequent item amounts
	int menuIn = 0, inkAmt = 0, stapAmt = 0, papReamAmt = 0, papCaseAmt = 0, penAmt = 0;
	int papUnit = 0;	//input choice for paper unit, ream or case
	string codeIn;	//string for input of discount code
	
	//counters for all inventory items, will accumulate totals of items over all menu cycles
	int inkCt = 0, stapCt = 0, papReamCt = 0, papCaseCt = 0, penCt = 0;

	//variable costs that are set as non-constants so they are able to change throughout the program
	double stapCost = 0;
	double penCost = 0;
	double papReam = 6.00;
	double papCase = 34.50;

	//variable subtotals for inventory items purchased
	double subInk = 0, subStap = 0, subReam = 0, subCase = 0, subPap = 0, subPen = 0;
	
	double tax = 0;	//total tax on items purchased
	double grandTotal = 0;	//subtotal before sales tax is added
	double totalDue = 0;	//total to include sales tax and subtotal

	double totalDisc = 0;
	


	//Display title section and copyright
	cout << "Lab 2 - Decision Making and Loops" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Menu display using setw for proper formatting
	cout << setw(50) << "Welcome to CSMY-141 Office Supplies" << endl;
	cout << setw(40) << "Stephen Yuhas, Owner" << endl << endl;
	
	cout << fixed << showpoint << setprecision(2);	//formatting for currency output

	while (menuIn != 5)	//beginning of loop; persists menu until checkout(option 5) is input
	{
		
		cout << "Our Inventory:" << endl;	//beginnning of menu display
		cout << setw(5) << INK1 << ". " << INKSTR << endl;	
		cout << setw(5) << STAP2 << ". " << STAPSTR << endl;
		cout << setw(5) << PAP3 << ". " << PAPSTR << endl;
		cout << setw(5) << PEN4 << ". " << PENSTR << endl;
		cout << setw(5) << CHECK5 << ". " << CHECKSTR << endl;
		cout << "Please make a selection: ";
		cin >> menuIn;
		cout << endl;
		switch (menuIn)
		{
			case INK1:	//case 1, ink
			{
				cout << "\tHow many printer ink catriges would you like to buy? ";	//input for amount of ink cartriges
				cin >> inkAmt;
				
				while (inkAmt <= 0)	//error loop for ink <= 0
				{
					cout << "Error - invalid number of printer catriges entered. Please enter a number greater than zero!" << endl << endl;
					cout << "\tHow many printer ink catriges would you like to buy? ";
					cin >> inkAmt;
				}
				inkCt = inkCt + inkAmt;	//accumulates total ink count

				if (inkCt >= 4)
				{
					//sets the ream and case to discounted prices then replaces existing subtotal with the discounted subtotal
					papReam = PAPREAMDISC;
					papCase = PAPCASEDISC;
					subReam = (papReamCt * papReam);
					subCase = (papCaseCt * papCase);
					subPap = (subReam + subCase);

				}

				subInk = (inkCt * INKCOST);	//subtotal for ink
				cout << endl << "\tThe subtotal for the printer ink is $" << subInk << endl << endl;
				break;
			}

			case STAP2:	//case 2, staplers
			{
				cout << "\tHow many staplers would you like to buy? ";
				cin >> stapAmt;
				cin.ignore(1, '/n');	//needed to add this to have the subsequent getline statement work correctly

				while (stapAmt <= 0)	//error loop for staplers <= 0
				{
					cout << "Error - invalid number of staplers entered. Please enter a number greater than zero!" << endl << endl;
					cout << "\tHow many staplers would you like to buy? ";
					cin >> stapAmt;
					cin.ignore(1, '/n');	//added to have the subsequent getline statement work correctly
				}
				if (stapAmt > 0)
				{
					stapCt = stapCt + stapAmt; //adds to the total stapler count
				}
				
				cout << "\tPlease type in a coupon code or NONE: ";	//input for coupon code
				getline(cin, codeIn);
				if (codeIn == CODEDISC)	//discount code is true, discount applied
				{
					stapCost = STAPDISC;
				}
				
				if (codeIn == CODENONE)	//no discount applied
				{
					stapCost = STAPCOSTFULL;
				}
				
				while (codeIn != CODEDISC && codeIn != CODENONE)	//loop for incorrect coupon code input, reinput for discounts in loop
				{
					cout << "Error - invalid coupon code entered. Please enter a coupon code or NONE" << endl << endl;
					cout << "\tPlease enter a coupon code or NONE: ";
					getline(cin, codeIn);
					if (codeIn == CODEDISC)
					{
						cout << "\tValid code entered";
						stapCost = STAPDISC;
					}
					if (codeIn == CODENONE)
					{
						stapCost = STAPCOSTFULL;
					}
				}

				subStap = (stapCt * stapCost);	//subtotal for staplers
				cout << endl << "\tThe subtotal for staplers is $" << subStap << endl << endl;
				break;
			}

			case PAP3:	//case 3, paper
			{
				cout << "How would you like to buy your printer paper? " << endl;	//entry for ream or case choice
				cout << setw(11) << "1. Ream" << endl;
				cout << setw(11) << "2. Case" << endl << endl;
				cout << "Please enter your choice: ";
				cin >> papUnit;	//variable for unit choice

				while (papUnit != UNITREAM && papUnit != UNITCASE)	//error loop for an incorrect menu choice, reinput in loop
				{
					cout << "Error - this is not a valid choice for paper type!" << endl << endl;
					cout << "How would you like to buy your printer paper? " << endl;
					cout << setw(11) << "1. Ream" << endl;
					cout << setw(11) << "2. Case" << endl;
					cout << "Please enter your choice: ";
					cin >> papUnit;
				}

				if (papUnit == UNITREAM)	//if reams selected for unit size
				{
					cout << "\tHow many reams of paper would you like to buy? ";
					cin >> papReamAmt;
					while (papReamAmt <= 0)	//error loop for incorrect amount of reams
					{
						cout << "Error - invalid number of reams entered. Please enter a number greater than zero!" << endl << endl;
						cout << "\tHow many reams of paper would you like to buy? ";
						cin >> papReamAmt;
					}
					papReamCt = papReamCt + papReamAmt;	//accumulates total ream count
					subReam = (papReamCt * papReam);	//adds reams to subtotal for all reams purchased
					subPap = (subReam + subCase);
				}

				if (papUnit == UNITCASE)	//if case selected for unit size
				{
					cout << "\tHow many cases of paper would you like to buy? ";
					cin >> papCaseAmt;
					while (papCaseAmt <= 0)	//error loop for incorrect amount of cases
					{
						cout << "Error - invalid number of cases entered. Please enter a number greater than zero!" << endl << endl;
						cout << "\tHow many cases of paper would you like to buy? ";
						cin >> papCaseAmt;
					}
					papCaseCt = papCaseCt + papCaseAmt;	//accumulates total case count
					subCase = (papCaseCt * papCase);	//adds cases to subtotal for all cases purchased
					subPap = (subReam + subCase);
				}
				if (inkCt >= 4)
				{
					//sets the ream and case to discounted prices then replaces existing subtotal with the discounted subtotal
					papReam = PAPREAMDISC;
					papCase = PAPCASEDISC;
					subReam = (papReamCt * papReam);
					subCase = (papCaseCt * papCase);
					subPap = (subReam + subCase);

				}

					cout << endl << "\tThe subtotal for paper is $" << subPap << endl << endl;	//ream + case amount displayed here
					break;
			}

			case PEN4:	//case 4, pens
			{
				cout << "\tHow many pens would you like to buy? ";	
				cin >> penAmt;


				while (penAmt <= 0)	//error loop for pens <= 0
				{
					cout << "Error - invalid number of pens entered. Please enter a number greater than zero!" << endl << endl;
					cout << "\tHow many pens would you like to buy? ";
					cin >> penAmt;
				}

				//tracks total pens and adds discount to the TOTAL pens ordered throughout all menu cycles as they are tallied up until checkout; (EXTRA CREDIT)
				penCt = penCt + penAmt;
				//then, discounts are applied to all pens ordered as the total tally of pens ordered increases
				
				if (penCt <= 5)	//defines base pen price as the cost for all pens ordered if pens<=5
				{
					penCost = PENCOST1;
				}

				if (penCt > 5)	//defines the 6-10 pen discount as the cost for all pens ordered if 6 to 10 pens are ordered
				{
					penCost = PENCOST2;
				}

				if (penCt > 10)	//defines the 11+ pen discount to the cost for all pens ordered if 11 or more pens are ordered
				{
					penCost = PENCOST3;
				}

				subPen = (penCt * penCost);	//subtotal for pens
				cout << endl << "\tThe subtotal for the pens is $" << subPen << endl << endl;
				break;
			}
			
			case CHECK5: cout << endl << endl;	//case 5, exit to checkout
				break;

			default:	//default case for incorrect menu selection
				{
					cout << "Sorry, we do not sell that item." << endl;
					cout << "Please make another selection." << endl << endl;
				}			
		}


	}

	//all 3 possible discounts evaluated, calculated, and added to the total discount variable; tracks and sums discounted amount of entire order
	if (inkCt >= 4)
	{
		totalDisc = totalDisc + ((subPap * 2) - (subPap));	//total paper discount added into total discount
	}

	if (penCt > 5)
	{
		totalDisc = totalDisc + ((penCt * PENCOST1) - (penCt * penCost));	//total pen discount added into total discount
	}

	if (codeIn == CODEDISC)
	{
		totalDisc = totalDisc + ((stapCt * STAPCOSTFULL) - (stapCt * stapCost));	//total stapler discount added into total discount
	}

						//evaluates if any discounts have been applied by checking the total discount that was being added up throughout all
	if (totalDisc > 0)	//menu cycles in the program; if this value is greater than 0, discounts have been applied and will not display otherwise
	{					
		cout << "Your total discount is: $" << totalDisc << endl << endl;	//displays the total discount for the entire order
	}

	
	grandTotal = (subInk + subStap + subPap + subPen);	//subtotal before tax
	tax = (TAXRATE * grandTotal);	//sales tax on subtotal
	totalDue = (grandTotal + tax);	//total due, including sales tax
	cout << "Your grand total is: $" << grandTotal << endl;	//display for subtotal
	cout << "Your sales tax is $" <<  tax << endl;	//display for sales tax
	cout << "Your total due is $" << totalDue << endl << endl;	//display for total due
	
	cout << "Thank you for ordering from CSMY-141 Office Supplies. Please come again!" << endl << endl;
	system("pause");
	return 0;
}