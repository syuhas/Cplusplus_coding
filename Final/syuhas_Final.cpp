//Stephen Yuhas
//Final Exam
//5-18-22

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;


const int SIZE = 20;	//const for size of c-strings in program, set to 20 to allow for normal range of input
const int MIN = 2;		//const int for minimum family member profiles
const int MAX = 7;		//const int for maximum family member profiles
const int ZERO = 0;		//const int for 0 value in input validation


struct PhoneProfile		//structure declaration for family member phone profiles structure
{
	char name[SIZE] = "none";	//c-string for the name of each family member
	char model[SIZE] = "none";	//c-string for the model of the phone of each family member
	int memory = 0;				//int for the memory in each family member phone
	int apps = 0;				//int for the number of apps on each family member phone
	double avgMem = 0;			//int for the average amount of memory used on each family member phone
};


void getInfo(PhoneProfile*, int);		//proto for the function to input data for each phone profile
double getAvg(int, int);				//proto for the function to get the average memory useage
void dispInfo(const PhoneProfile*, int);	//proto for the function to display all phone profile info entered


int main()
{
	int members = 0;	//input int variable for number of family members

	do	//do/while loop to validate family member input between 2 and 7
	{
		cout << "How many family members do you have: ";
		cin >> members;
		if (members < 2 || members > 7)		//error message for invalid input
		{
			cout << "Error - Please enter in a number between 2 and 7." << endl << endl;
		}

	} while (members < 2 || members > 7);	//loop will persist until a valid number between 2 and 7 has been entered

	cin.ignore(1, '\n');	//cin.ignore for white space


	//dynamic array of 'PhoneProfile' creation
	PhoneProfile* profiles = nullptr;		//set pointer to point to null the array of structures
	profiles = new PhoneProfile[members];	//pointer set to the dynamically allocated array of structure 'PhoneProfile'
	
	cout << endl;

	getInfo(profiles, members);		//call function to get all family member phone profiles

	cout << endl;

	dispInfo(profiles, members);	//call function to display all family member profiles

	delete[] profiles;	//memory is deallocated	for the dynamic array
	profiles = nullptr;	//pointer reset to nullptr


	system("pause");
	return 0;
}

void getInfo(PhoneProfile* profiles, int members)	//definition for function to input all family member profile data(using array notation)
{

	for (int i = 0; i < members; i++)	//for loop will run through each element of array of structure
	{
		cout << "Enter name " << i + 1 << ": ";
		cin.getline(profiles[i].name, SIZE);	//cin.getline for c-string entry up to max size, using array notation
		
		cout << "Enter the model owned by " << profiles[i].name << ": ";
		cin.getline(profiles[i].model, SIZE);	//cin.getline for c-string entry up to max size, using array notation

		do	//do/while loop will validate entry for each memory value input is greater than 0
		{
			cout << "Enter the total memory of the phone in Gigabytes: ";
			cin >> profiles[i].memory;	//cin using array notation
			if (profiles[i].memory <= ZERO)		//error message for invalid input
			{
				cout << "Error - Please enter a positive number!" << endl << endl;
			}
		} while (profiles[i].memory <= ZERO);	//loop will persist until a valid number greater than 0 has been entered

		do	//do/while loop will validate entry for each app value input is greater than 0
		{
			cout << "Enter the total number of applications on the phone: ";
			cin >> profiles[i].apps;	//cin using array notation
			if (profiles[i].apps <= ZERO)	//error message for invalid input
			{
				cout << "Error - Please enter a positive number!" << endl << endl;
			}
		} while (profiles[i].apps <= ZERO);	//loop will persist until a valid number greater than 0 has been entered
		cin.ignore(1, '\n');	//cin.ignore for white space

		profiles[i].avgMem = getAvg(profiles[i].apps, profiles[i].memory);	//call separate function 'getAvg' to do the calculation for the average memory and return the value to the profile element
		
		cout << endl;
		
	}
	return;
}

double getAvg(int apps, int memory)		//defintion for function that calcuates and returns the average memory useage
{
	double average = 0;		//temporary double variable created to hold average calculation
	average = static_cast<double>(memory) / apps;	//static cast in value to double for calculation for average memory useage
	
	return average;		//average is returned to previous function and saved to array element
}

void dispInfo(const PhoneProfile* profiles, int members)	//definition of function to display all family member profiles and data(using pointer notation)
{
	for (int i = 0; i < members; i++)	//for loop will run through each element of array of structure to display
	{
		cout << fixed << showpoint << setprecision(2);	//formatting for forced 2 decimal places
		
		cout << "Name " << i + 1 << ": " << profiles->name << endl;		//name displayed using pointer operator notation	
		
		cout << "The model owned by " << profiles->name << ": " << profiles->model << endl;		//name and model displayed using pointer operator notation
		
		cout << "The total memory of the phone is: " << profiles->memory  << "GB" << endl;	//total memory displayed using pointer operator notation
		
		cout << "The total number of applications on the phone is: " << profiles->apps << endl;		//total applications displayed using pointer operator notation
		
		cout << "The average memory used per application is: " << profiles->avgMem << "GB" << endl << endl;		//average memory useage displayed using pointer operator notation

		profiles++;		//pointer is incremented in loop to go to next element
	}
	return;
}