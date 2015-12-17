///***********************************************************************************

/// Title: PC09 - Element Shifter

/// Description: Write a function that accepts an int array and size as arguments. The

/// function creates a new array that is one element larger than the argument. The

/// first element is 0. All elements are shifted. Write another function that

/// accepts an int array and length as arguments. The function displays contents.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : Complete 


///***********************************************************************************
using namespace std;

#include <iostream>

int* arrShift(int *, int);
void arrDisp(int *, int);

int main()
{
	const int defaultSize = 5;
	int OGarray[defaultSize] = {5, 3, 4, 1, 2};

	int *arrPtr = nullptr;
	arrPtr = arrShift(OGarray, defaultSize);
	int newSize = (defaultSize + 1);
	cout << "Old array: ";
	arrDisp(OGarray, defaultSize);
	cout << "\nNew Array: ";
	arrDisp(arrPtr, newSize);
	int x;
	cin >> x;
	delete[] arrPtr;
	return 0;
};

int* arrShift(int *array, int length)
{
	// Dynamically allocate memory for a new array of (length + 1)
	int *newArr = new int[length + 1];
	*newArr = 0; // sets first element to 0
	for (int i = 1; i < (length + 1); i++)
	{
		*(newArr + i) = *(array + (i-1)); // Populate the rest of the new array with the elements of the old.
	}

	return newArr;
};

void arrDisp(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << *(array + i) << " ";

	}
};