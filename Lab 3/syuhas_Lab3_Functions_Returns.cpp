//Stephen Yuhas
//Exercise - Decisions and Loops
//3-9-22

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printTitle();	//prototype for title display function
int menuSelect();	//prototype for menu selection function
int itemEntry(string);	//prototype for item amount input function
int paperType();	//prototype for paper unit selection function
bool testExit();	//prototype for exit confirmation function
void checkOut(double, double, double, double, bool);	//prototype for checkout function
int penCheck(int);	//prototype for pen tracker function


const string INKSTR_MENU = "Printer Ink";	//string for ink in menu
const string STAPSTR_MENU = "Staplers";	//string for staplers in menu
const string PAPSTR_MENU = "Printer Paper";	//string for paper in menu
const string PENSTR_MENU = "Pens";	//string for pens in menu
const string CHECKSTR_MENU = "Checkout";	//string for checkout option in menu
const string INKSTR = "printer ink cartriges";	//string for ink display in item entry function
const string STAPSTR = "staplers";	//string for stapler display in item entry function
const string REAMSTR = "reams of printer paper";	//string for reams in item entry function
const string CASESTR = "cases of printer paper";	//string for cases in item entry function
const string PENSTR = "pens";


const string YES1 = "Y";	//uppercase string value to exit program
const string YES2 = "y";	//lowercase string value to exit program
const string NO1 = "N";		//uppercase string value to remain in program
const string NO2 = "n";		//lowercase string value to remain in program


const int INK1 = 1;	//menu selection value for ink
const int STAP2 = 2;	//menu selection value for staplers
const int PAP3 = 3;	//menu selection value for paper
const int PEN4 = 4;	//menu selection value for pens
const int CHECK5 = 5;	//menu selection value for checkout


const int MIN_TEST = 0;	//test constant to check the minimum on various items/prices
const int DISC_CHECK = 4;	//constant used to test if a discount is applied to paper
const int PEN_DISC1 = 5;	//used to test for no price break and first price break on pens
const int PEN_DISC2 = 10;	//used to test for second price break on pens


const int UNITREAM = 1;	//test constant for ream unit
const int UNITCASE = 2;	//test constant for case unit


const double INKCOST = 40.25;	//cost of ink
const double STAPCOSTFULL = 8.00;	//value for "NONE" discount code
const double STAPDISC = 5.75;	//value for "disc stap" discount code
const double PAPREAM = 6.00;	//cost of a ream of paper
const double PAPCASE = 34.50;	//cost of a case of paper
const double PENCOST1 = 1.99;	//regular cost of a pen
const double PENCOST2 = 1.69;	//first pen discounted cost (6-10)
const double PENCOST3 = 1.29;	//second pen discounted cost(11+)
const double TAXRATE = 0.06;	//tax rate used to calculate sales tax


const string CODEDISC = "disc stap";	//string to test for discounted stapler cost
const string CODENONE = "NONE";	//string to test for no discount on s





int main()
{
	
	//inputs for menu choice and all subsequent item amounts
	int menuIn = 0, inkAmt = 0, stapAmt = 0, papAmt = 0, penAmt = 0;

	int papUnit = 0;

	string codeIn;	//string for input of discount code

	//counters for all inventory items, will accumulate totals of items over all menu cycles
	int inkCt = 0, penCt = 0;

	double stapCost = 0;	//variable for cost of a stapler, will be set based on coupon code
	double penCost = 0;		//variable for cost of a pen, will be set based on amount of pens purchased
	double papCost = 0;		//variable for cost of paper, will be set based on unit size
	

	//variable subtotals for inventory items purchased
	double subInk = 0, subStap = 0, subPap = 0, subPen = 0;

	bool exitTest = false;	//bool used to exit program when true
	bool discCheck = false;	//bool used to check if discount will be applied

	printTitle();	//calls function to print title, copyright and welcome message	

	cout << fixed << showpoint << setprecision(2);	//formatting for currency output

	while (exitTest == false)	//beginning of loop to validate menu input; persists menu until checkout(option 5) is input and the exit function returns a "true" value
	{

		menuIn = menuSelect();	//menu selection set equal to function call to display menu and return menu input
		cout << endl;

		switch (menuIn)	//beggining fo switch for the menu
		{
			case INK1:	//case 1, ink
			{
				inkAmt = itemEntry(INKSTR);	//ink amount set to call function to return value, sends string argument to display prompt
				inkCt = inkCt + inkAmt;	//accumulates total ink count

				subInk = (inkCt * INKCOST);	//subtotal for ink
				cout << endl << "\tThe subtotal for the printer ink is $" << subInk << endl << endl;
				if (inkCt >= DISC_CHECK)
				{
					discCheck = true;	//bool value will be set to true when ink hits 4 and will be sent to checkout function as an argument to apply discount
				}
				break;
			}

			case STAP2:	//case 2, staplers
			{
				stapAmt = itemEntry(STAPSTR);	//stapler amount set to call function to return value, sends string argument to display prompt
				
				do	//start of loop to valididate correct coupon code entry
				{
					cout << "\tPlease type in a coupon code or NONE: ";	//input for coupon code
					getline(cin, codeIn);

					if (codeIn != CODEDISC && codeIn != CODENONE)
					{
						cout << "Error - invalid coupon code entered. Please enter a coupon code or NONE" << endl << endl;	//error message for incorrect coupon code
					}
					if (codeIn == CODEDISC)	//discount code is true, discount applied
					{
						stapCost = STAPDISC;	//stapler cost is set as discounted cost
					}

					if (codeIn == CODENONE)	//no discount applied
					{
						stapCost = STAPCOSTFULL;	//stapler cost is set as full cost
					}
				} while (codeIn != CODEDISC && codeIn != CODENONE);	//validation for correct coupon code
					

				subStap = subStap + (stapAmt * stapCost);	//subtotal for staplers
				cout << endl << "\tThe subtotal for staplers is $" << subStap << endl << endl;
				break;
			}

			case PAP3:	//case 3, paper
			{
				papUnit = paperType();	//unit choice for paper is set to call function to return choice for paper type

				if (papUnit == UNITREAM)	//if reams selected for unit size
				{
					papCost = PAPREAM;	//paper cost set to ream cost
					papAmt = itemEntry(REAMSTR);	//paper ream amount set to call function to return value, sends string argument to display prompt
					subPap = subPap + (papCost * papAmt);
				}

				if (papUnit == UNITCASE)	//if case selected for unit size
				{
					papCost = PAPCASE;	//paper cost set to case cost
					papAmt = itemEntry(CASESTR);	//paper case amount set to call function to return value, sends string argument to display prompt
					subPap = subPap + (papCost * papAmt);
				}

				cout << endl << "\tThe subtotal for paper is $" << subPap << endl << endl;	//ream + case amount displayed here
				break;
			}

			case PEN4:	//case 4, pens
			{
				penAmt = itemEntry(PENSTR);	//pen amount set to call function to return value, sends string argument to display prompt
				
				penCt = penCheck(penAmt);	//sends pen count to a function that tracks total pens (EXTRA CREDIT)

				if (penCt <= PEN_DISC1)	//sets pens to regular price if 5 or less pens ordered
				{
					penCost = PENCOST1;	//set to regular cost
				}

				if (penCt > PEN_DISC1 && penCt <= PEN_DISC2)	//sets pens to first discounted price if 5-10 pens ordered
				{
					penCost = PENCOST2;	//set to first discounted cost
				}

				if (penCt > PEN_DISC2)	//sets pens to second discounted price if more than 10 pens ordered
				{
					penCost = PENCOST3;	//set to final discounted cost
				}

				subPen = (penCt * penCost);	//subtotal for pens
				cout << endl << "\tThe subtotal for the pens is $" << subPen << endl << endl;
				break;
			}

			case CHECK5:	//case 5, exit to checkout
			{
				exitTest = testExit();	//sets bool to the result of the function which will stay in loop if returns false and will exit if returns true 
				break;
			}
			
			default:	//default case for incorrect menu selection
			{
				cout << "Sorry, we do not sell that item." << endl;
				cout << "Please make another selection." << endl << endl;
			}
		}

	}
	checkOut(subInk, subStap, subPap, subPen, discCheck);	//after menu loop, checkout function is called to display totals(if any), display discount(if any) and apply tax, then program will end
	cout << endl << endl;									//all subtotals and the bool discount check are sent to function for calculation and discount display
	system("pause");
	return 0;
}



void printTitle()	//void function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 2 - Decision Making and Loops" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << setw(50) << "Welcome to CSMY-141 Office Supplies" << endl;
	cout << setw(40) << "Stephen Yuhas, Owner" << endl << endl;
	return;
}

int menuSelect()	//function to display menu and return menu seletion parameter
{
	int menuChoice;	//created as variable to send back to main to use in switch statement
	cout << "Our Inventory:" << endl;	//beginnning of menu display
	cout << setw(5) << INK1 << ". " << INKSTR_MENU << endl;
	cout << setw(5) << STAP2 << ". " << STAPSTR_MENU << endl;
	cout << setw(5) << PAP3 << ". " << PAPSTR_MENU << endl;
	cout << setw(5) << PEN4 << ". " << PENSTR_MENU << endl;
	cout << setw(5) << CHECK5 << ". " << CHECKSTR_MENU << endl;
	cout << "Please make a selection: ";
	cin >> menuChoice;
	return menuChoice;	//selection is returned to main function
}

int itemEntry(string itemName)	//function for all item amount entries, string argument sent in from main to display item being prompted for
{
	int menuVal = 0;	//variable created to return to main as the desired number of items
	do	//beginning of loop to validate item amount is greater than zero
	{
		cout << "\tHow many " << itemName << " would you like to buy? ";	//string argument displayed in prompt
		cin >> menuVal;
		cin.ignore(1, '/n');	//needed to add this to have the possible getline statement work correctly
		if (menuVal <= MIN_TEST)	//back to beginning of loop of less than zero
		{
			cout << "Error - Invalid number of " << itemName << " entered. Please enter a number greater than zero!" << endl << endl;
		}
	} while (menuVal <= MIN_TEST);
	return menuVal;	//item amount returned to main
	
}

int paperType()	//function to return a value for paper unit
{
	int choice = 0;	//variable created to return value to main
	do	//beginning of loop to validate entry
	{
		cout << "How would you like to buy your printer paper? " << endl;	//entry for ream or case choice
		cout << setw(11) << "1. Ream" << endl;
		cout << setw(11) << "2. Case" << endl << endl;
		cout << "Please enter your choice: ";
		cin >> choice;	//variable for unit choice
		if (choice != UNITREAM && choice != UNITCASE)	//validates unit type entry
		{
			cout << "Error - this is not a valid choice for paper type!" << endl << endl;
		}
	} while (choice != UNITREAM && choice != UNITCASE);	//error loop for an incorrect unit choice
	return choice;	//returns value for unit selection
}

bool testExit()	//function for testing whether the user wants to exit or not
{
	string exitCh;	//string created to input and test against yes or no string constants
	bool test = false;
	do	//start of the loop to test for correct input (Y,y,N,n)
	{
		cout << "Do you wish to checkout and get your total cost? (y/n): ";
		cin >> exitCh;	//input choice to exit the program

		if (exitCh == YES1 || exitCh == YES2)	//if Y or y, returns a bool value of true and exits the program
		{
			test = true;
		}
		if (exitCh == NO1 || exitCh == NO2)	//if N or n, returns a bool value of false and the program persists
		{
			test = false;
		}
		if (exitCh != YES1 && exitCh != YES2 && exitCh != NO1 && exitCh != NO2)		//tests to display error message for an invalid input
		{
			cout << "Error - Only y or n is valid, please reenter!!" << endl << endl;
		}
	} while (exitCh != YES1 && exitCh != YES2 && exitCh != NO1 && exitCh != NO2);	//loop persists if the user does not enter any valid option
	cout << endl;
	return test;
}

int penCheck(int penVal)	//function to track total pens purchased throughout all menu cycles
{
	static int penTot = 0;	//static int created and initialized to track the pen total and return value to the total in main
	
	penTot = penVal + penTot;	//current pen purchase is added to total pen purchase
	
	return penTot;	//value is returned and added to total in main
}

//function to calculate subtotal, tax, total and display any discount; will display only goodbye message if no items purchased
void checkOut(double inkSub, double stapSub, double papSub, double penSub, bool checkDisc)	//4 subtotals and bool value for discount sent as arguments
{
	double discTot = 0;	//total discount applied to order
	double tax = 0;	//total tax on items purchased
	double grandTotal = 0;	//subtotal before sales tax is added
	double totalDue = 0;	//total to include sales tax and subtotal

	if (checkDisc == true && papSub > MIN_TEST)	//checks for discount with value from main; if true, discount applied. Only displays if paper is purchased. 
	{
		papSub = papSub / 2;
		discTot = (papSub * 2) - papSub;	//paper discount calculation
		cout << "Your total discount is $" << discTot;
		cout << endl << endl;
	}

	grandTotal = (inkSub + stapSub + papSub + penSub);	//subtotal before tax

	if (grandTotal > MIN_TEST)	//will only display if items are purchased and there is a total
	{
		tax = (TAXRATE * grandTotal);	//sales tax on subtotal
		totalDue = (grandTotal + tax);	//total due, including sales tax
		cout << "Your grand total is: $" << grandTotal << endl;	//display for subtotal
		cout << "Your sales tax is $" << tax << endl;	//display for sales tax
		cout << "Your total due is $" << totalDue << endl << endl;	//display for total due
	}
	cout << "Thank you for ordering from CSMY-141 Office Supplies. Please come again!" << endl << endl;	//goodbye message
	return;
}
