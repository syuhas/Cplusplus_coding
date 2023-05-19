//Stephen Yuhas
//Lab 0 - Variables and Math
//2-16-22

#include <iostream>
#include <iomanip>	//Library to format output

using namespace std;

int main()
{
	double a = 0, b = 0, c = 0;		//Declare and initialize 3 user input variables to 0
	double disc = 0;				//Declare and initialize discriminant to 0

	cout << "\t\tWelcome to the Quadratic Problem Solver" << endl << endl;	//Title of the program, indented for style

	//Input sequence for a, b, c with proper spacing
	cout << "Please enter in the value of a: ";
	cin >> a;
	cout << endl << "Please enter in the value of b: ";
	cin >> b;
	cout << endl << "Please enter in the value of c: ";
	cin >> c;
	cout << endl << endl;

	cout << fixed << showpoint << setprecision(2);													//Set formatting to display two decimal places, even if a whole integer

	cout << "The equation is " << a << "x^2 " << "+ " << b << "x " << "+ " << c << endl << endl;	//Display for Quadratic formula


	disc = (pow(b, 2)) - (4 * a * c);																//After user input of a/b/c, discriminant is calculated and saved to memory

	cout << "The discriminant is: " << disc << endl << endl;										//Display the saved discriminant that was calculated above
	
	if (disc >= 0)																					//Determine whether or not discriminant is greater than or equal to zero
	{
		double root1 = (-b + sqrt(disc)) / (2 * a);				//Initialize and save calculation only to one root variable as they will be the same value if the discriminant is 0

		if (disc == 0)																				//Determines if the discriminant equals zero
		{
			cout << "There is one root and the value is: " << root1 << endl << endl;				//Display the one root variable defined above
		}
		if (disc > 0)																				//Determine if the discriminant is a positive value
		{
			double root2 = (-b - sqrt(disc)) / (2 * a);			//Initialize and save additional calcualtion to a second root variable since there are two distinct roots
			cout << "There are two roots and the values are: " << root1 << " and " << root2 << endl << endl;	//Display both roots
		}
	}
	//If the above initial parent condition is not met, the discriminant is negative and program will display that there aren't any roots
	//Additionally, no root variables are initialized and saved to memory as they are not required and would produce an irrational result
	else
	{
		cout << "There are no roots for this equation!!" << endl << endl;
		
	}

	cout << "\t\tThank you for using the Quadratic Formula Solver.\n\n";					//Outro for the program, indented for style

	system("pause");
	return 0;

}

