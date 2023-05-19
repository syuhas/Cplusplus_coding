//Stephen Yuhas
//Exercise - Sort
//4-18-22

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 12;	//constant for size of array

void printTitle();	//proto for print title, copyright, and intro
void dispArr(const int[]);	//proto for the function to print the contents of the array
void sortArr(int[]);	//proto for function to sort the contents of the array
void swapArr(int&, int&);	//proto for function to swap elements of array
void goodbye();	//proto for goodbye function 

int main()
{
	int intArr[SIZE] = { 98, 78, 102, 67, 45, 83, 29, 184, 2, 68, -7, 115 };	//array initialized with values to be sorted
	
	
	printTitle();	//call function to print the title section
	
	dispArr(intArr);	//calls function to display contents of array

	cout << endl << endl;

	sortArr(intArr);	//call function to sort array in ascending order

	dispArr(intArr);	//display sorted array
	
	cout << endl << endl;

	goodbye();	//call function to print goodbye message

	system("pause");
	return 0;
}

void printTitle()	//title display function
{
	//Display title section and copyright
	cout << "CE - Sort" << endl;
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.";
	cout << endl << endl;

	//Welcome message using setw for proper formatting
	cout << "\tCSMY-141 Sorting Program" << endl << endl;
	return;
}

void dispArr(const int intArr[])	//function header to display array
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << intArr[i] << " ";	//display each element with a space between each 
	}
}

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

void goodbye()	//goodbye function
{
	cout << "Thank you for using the CMSY-141 Sorting Program!" << endl << endl;
}