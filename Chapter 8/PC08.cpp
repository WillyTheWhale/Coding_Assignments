///***********************************************************************************

///Title: PC0809 Sorting Benchmarks

/// Description: Sorts a randomly generated array using bubble and selection sort.

/// Displays the number of times that a swap has occured.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: October 11, 2015

/// Status : Complete 

/// 

/// 

///***********************************************************************************
using namespace std;

#include <iostream>
#include <cstdlib>


int bsort(int array[], int arraySize);
int ssort(int array[], int arraySize);
void dispArray(int array[], int, int numswaps);

int main()
{
	// define two arrays
	int arr1[20];
	int arr2[20];

	// fill the two arrays with random values
	for (int i = 0; i < 20; i++)
	{
		arr1[i] = rand();
		arr2[i] = arr1[i];
	}
	cout << "Array 1 before..." << endl;
	dispArray(arr1, 20, 0);
	cout << endl;
	cout << "Array 2 before..." << endl;
	dispArray(arr2, 20, 0);
	cout << endl;
	cout << "Bubble sorting array 1...\n";
	int swapNum1 = bsort(arr1, 20);
	dispArray(arr1, 20, swapNum1);

	cout << "Selection sorting array 2...\n";
	int swapnum2 = ssort(arr2, 20);
	dispArray(arr2, 20, swapnum2);





}

int bsort(int array[], int arraySize)
{
	int swapCount = 0;
	bool swap = false;

	do
	{
		swap = false;
		for (int i = 0; i < (arraySize - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapCount++;
				swap = true;
			}

		}
	} while (swap);
	return swapCount;
};




int ssort(int array[], int arraySize)
{
	int swapValue;
	int newLow;
	int swapIndex;
	bool swaptest;
	int swapCount = 0;

	for (int i = 0; i < (arraySize - 1); i++)
	{
		swaptest = false; // reset swap flag
		swapValue = array[i];
		newLow = swapValue;
		for (int j = (i + 1); j < arraySize; j++) // Search for the lowest of the remaining elements.
		{
			if (newLow > array[j]) // if there is a element that is lower than the value to Swap, declare that element as the element to be swapped.
			{
				newLow = array[j];
				swapIndex = j;
				swaptest = true;
			}
		}
		if (swaptest == true) // Do we need to make a swap?
		{
			array[i] = newLow;
			array[swapIndex] = swapValue;
			swapCount++;
		}
	}
	return swapCount;
};








void dispArray(int array[], int arraySize, int numswaps)
{
	cout << "[";
	for (int i = 0; i < arraySize; i++)
	{
		cout << " " << array[i];
	}
	cout << " ]\n";
	if (numswaps != 0)
	cout << "There were " << numswaps << " swaps\n\n";
};