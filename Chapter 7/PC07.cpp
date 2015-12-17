///***********************************************************************************

///Title: Number Analysis Program

/// Description: The program asks the user for a file name. The file contains a series of numbers written on separate

/// lines. The program reads the contents of the file into an array, and displays the following:

/// Lowest number, Highest number, the total numbers, and the average of the numbers.

/// Note: The denotation of the positions of highs and lows will only return the first low's position,

/// or the first high's position if there are two elements that share the same value within the array.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : Complete 

///***********************************************************************************

using namespace std;

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

void getFileName(string&);
bool openFile(string);
double getHigh(double[], int);
double getLow(double[], int);
double getAvg(double[], int);



int main()
{
	double data[10] = { 0 };
	int dataNum = 0;
	double highest;
	double lowest;
	double avg;

	string fileName;
	getFileName(fileName);
	fstream inputFile;
	inputFile.open(fileName.c_str(), ios::in); //define the file object for reading

	if (inputFile)
		cout << "File successfully opened!\n";

	else
	{
		cout << "File failed to open.\n";
		return(88);
	}

	for (int i = 0; i<10; i++)
	{
		double temp = 0;
		if (inputFile >> temp)
		{
			data[i] = temp;
			dataNum++;
		}
		else
			break;
	}
	highest = getHigh(data, dataNum);
	lowest = getLow(data, dataNum);
	avg = getAvg(data, dataNum);
	cout << "The highest is: " << highest << endl;
	cout << "The lowest is: " << lowest << endl;
	cout << "The avg is: " << avg << endl;


	return 0;

}

void getFileName(string &fileName)
{
	cout << "Please input the name of the file: ";
	cin >> fileName;
	return;
}

double getHigh(double data[], int totalNum)
{
	double high = data[0];
	int highPos = 0;
	for (int i = 1; i < totalNum; i++)
	{
		if (high < data[i])
		{
			high = data[i];
			highPos = i;
		}
	}
	cout << "The highest number is in position " << (highPos + 1) << endl;
	return high;
}

double getLow(double data[], int totalNum)
{
	double low = data[0];
	int lowPos = 0;
	for (int i = 1; i < totalNum; i++)
	{
		if (low > data[i])
		{
			low = data[i];
				lowPos = i;
		}
	}
	cout << "The lowest number is in position " << (lowPos + 1) << endl;
	return low;
}

double getAvg(double data[], int totalNum)
{
	int sum = 0;
	double avg;

	for (int i = 0; i < totalNum; i++)
	{
		sum = sum + data[i];
	}
	cout << "The sum is: " << sum << endl;

	avg = ((1.00*sum) / totalNum);
	return avg;
}
