///***********************************************************************************

/// Title: Population Bar Chart

/// Description: Creates a bar chart showing the population of Prairieville

/// at 20 year intervals during the past 100 years.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : -

/// 

/// 

///***********************************************************************************
using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main()
{

	bool openInputFile(fstream &file, string fileName);


	fstream inputFile;
	bool status;
	int years[] = { 1900, 1920, 1940, 1960, 1980, 2000 };
	int population[6];

	status = openInputFile(inputFile, "People.txt");
	if (status == false)
		return 0;

	for (int i = 0; i < 6; i++)
	{
		inputFile >> population[i];
		population[i] = ( population[i] / 1000);
	}


	for (int i = 0; i < 6; i++)
	{
		cout << years[i] << ":\t";
		for (; population[i] != 0; (population[i]-= 1))
		{
			cout << "*";
		}

		cout << endl;

	}
	cin.get();
	return 0;



}

bool openInputFile(fstream &file, string fileName)
{
	bool status;
	file.open(fileName.c_str(), ios::in);
	if (file.fail())
	{
		status = false;
		cout << "File failed to open\n";
	}
	else
	{
		status = true;
		cout << "File successfully opened\n";
	}
	return status;
}