																																										//Sort and Swap functions

void sortArr(int intArr[])	//function header to sort array in ascending order
{
	int minInd = 0;	//minimum index location value variable
	int minVal = 0;	//minimum actual value variable

	for (int start = 0; start < (SIZE - 1); start++)	//starts for loop at the first element up to next to last element
	{
		minInd = start;	//mimimum index value set to starting array subscript
		minVal = intArr[start];	//minimum value set to starting element
		for (int index = start + 1; index < SIZE; index++)	//for loop starts at next element and compares each to find the smallest
		{
			if (intArr[index] < minVal)	//check if smaller than start element
			{
				minVal = intArr[index];	//if smaller, value is stored
				minInd = index;	//and location is stored
			}
		}
		swapArr(intArr[minInd], intArr[start]);	//call function to swap elements

	}
}

void swapArr(int& a, int& b)	//function to swap elements using pass by reference
{
	int numTemp = a;	//temporary value set to first value
	a = b;				//first value is set to second value
	b = numTemp;		//second value is set to first value via temporary value
}






																																										//ignore cin

cin.ignore(1, '\n');







																																										//switch template, 'variable' entered by user

switch (variable)	
{
	case CONST:
	{
		statement;
		break;
	}

	default:	
	{
		statement;
		break;
	}
}








																																											//exit program function

bool exitProgram()	//boolean function definition to validate whether or not user would like to exit the program
{
	bool exitFlag = true;	//bool flag to return to main
	bool valid = false;	//bool flag to validate input
	char choice[YN_SIZE] = " ";	//c-string used as the input for the exit option
	char y[YN_SIZE] = "Y", n[YN_SIZE] = "N";	//yes and no test c-strings used for testing termination of the program

	do	//do/while loop validates the user input
	{
		cin.getline(choice, YN_SIZE);		//cin.getline used to enter the c-string choice	

		int i = strlen(choice) - 1;	//variable for the c-string array element to be compared

		if (toupper(choice[i]) == y[i])	//whether the user enters 'y' or 'Y', the 'toupper' converts to the uppercase version and compares it with the test string
		{
			exitFlag = true;	//function will return 'false'
			valid = true;		//valid flag set to 'true' to exit the validation loop
		}
		else if (toupper(choice[i]) == n[i])	//whether the user enters 'n' or 'N', the 'toupper' converts to the uppercase version and compares it with the test string
		{
			exitFlag = false;	//function will return 'true'
			valid = true;		//valid flag set to 'true' to exit the validation loop
		}
		else	//user does not enter a valid input
		{
			cout << "Please enter either Y or N: ";
			valid = false;	//valid flag set to 'false' to remain in validation loop
		}
	} while (!valid);	//loop will persist until valid input/valid flag set to true

	cout << endl << endl;

	return exitFlag;	//return the result of the exit prompt, true or false, to exit or remain in program
}


//use this in main for exit function

do
{
	exitFlag = exitProgram();
} while (!exitFlag);





																																											//structs
//struct with array of structs template
struct Struct1
{
	var1;
	var2;
};

struct StructNest
{
	Struct1 arrOfStruct1[CONST];
};

//array of structnest's created

StructNest arr[CONST];



//struct notation



//dynamically allocated array of struct, user enters 'variable'
Struct1* structArr = nullptr;		//set pointer to point to null the array of structures
structArr = new Struct1[variable];	//pointer set to the dynamically allocated array of structures

//pointer operator notation
structArr->var1
structArr->var2

//nested struct notation
structArr[i].arrOfStruct1[j].pName

void function(Struct team[])
{

}




																																											//welcome template


void welcome()	//definition of function to display title, copyright, welcome message and owner info
{
	//Display title section and copyright
	cout << "Lab 9 - Structures" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message and owner info display using setw for proper formatting
	cout << "\tWelcome to CMSY-141 Soccer Statistics Calculator" << endl << endl;
	return;
}




																																									//vector, array, pointer definitions

//vector
vector<string> inventory;	//vector for inventory items

inventory.push_back(item);	//pushback to 'item' to the end of the vector

inventory.pop_back();	//removes last element of the vector

//array
//3x7 array definition

int arr[3][7] = { { 0, 0, 0, 0, 0, 0, 0},		//definition for array to hold item data
					{ 0, 0, 0, 0, 0, 0, 0},
					{ 0, 0, 0, 0, 0, 0, 0} };

//array for loop for multi dimension array

for (int i = 0; i < "CONST for array dimension 1"; i++)
{
	for (int j = 0; j < "CONST for array dimension 2"; j++)
	{
		"expression" arr[i][j];
	}
}


//pointer, user inputs 'variable'
int* pointer = nullptr;		//create pointer and initialize to null
pointer = new int[variable];		//dynamic array is allocated to hold user defined number of days

//deallocate pointer
delete[] pointer;	//memory is deallocated
pointer = nullptr;	//pointer reset to nullptr


//pointer use in function, !!DO NOT USE IN MAIN!!

int function(int* pointer, int variable)	//function definition for the dry loads calculation
{

	for (int i = 0; i < variable; i++)
	{
		if ((*pointer % 3) > CONST)		//if the modulus returns a result, the above division had a remainder and so we need to round up
		{

		}
		pointer++;
	}

	return dry;	//return the dryer loads to main
}
