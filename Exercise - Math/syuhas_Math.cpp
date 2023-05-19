// Stephen Yuhas
// 2-14-2022
// Project - Math

#include <iostream>
#include <iomanip>	//Input output manipulation library

using namespace std;

int main()
{
	int int1 = 0, int2 = 0;	//Declares integer, double variables, set to zero as best practice
	double dbl1 = 0, dbl2 = 0;

	//Copyright statement and program title
	cout << "CE - Math" << endl;
	cout << "Copyright 2021 - Howard Community College All rights reserved; Unauthorized duplication prohibited." << endl << endl;
	
	//Prompts to enter first and second integer values
	cout << "Enter the first integer value: ";
	cin >> int1;
	cout << "Enter the second integer value: ";
	cin >> int2;
	//Prompts to enter the first and second double values
	cout << "Enter the first double value: ";
	cin >> dbl1;
	cout << "Enter the first double value: ";
	cin >> dbl2;
	cout << endl << endl;	//New line using manipulator

	//Calculations for integer variables
	cout << "Integer Math:" << endl;
	cout << "Adding " << int1 << " and " << int2 << " = " << int1 + int2 << endl;
	cout << "Subtracting " << int1 << " and " << int2 << " = " << int1 - int2 << endl;
	cout << "Multiplying " << int1 << " and " << int2 << " = " << int1 * int2 << endl;
	cout << "Dividing " << int1 << " and " << int2 << " = " << int1 / int2 << endl;
	cout << "Moding " << int1 << " and " << int2 << " = " << int1 % int2 << endl << endl;	//Extra end of line manipulator for next section

	//Calculations for double variables
	cout << "Double Math:" << endl;	//
	cout << setprecision(2) << fixed;	//Sets the output to a fixed notation of (2) decimal places	**EXTRA CREDIT**
	cout << "Adding " << dbl1 << " and " << dbl2 << " = " << dbl1 + dbl2 << endl;
	cout << "Subtracting " << dbl1 << " and " << dbl2 << " = " << dbl1 - dbl2 << endl;
	cout << "Multiplying " << dbl1 << " and " << dbl2 << " = " << dbl1 * dbl2 << endl;
	cout << "Dividing " << dbl1 << " and " << dbl2 << " = " << dbl1 / dbl2 << endl;
	

	system("pause");
	return 0;
}