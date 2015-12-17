///***********************************************************************************

/// Title: PC1204

/// Description: Tail Program

/// 

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : Complete 

/// 

///***********************************************************************************
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	string fileName;

	cout << "Please enter the file name: ";

	cin >> fileName;

	string buffer[10];

	int index = 0;

	bool overFlow = false;

	fstream file;
	file.open(fileName.c_str(), ios::in);

	while ( getline(file , buffer[index] ) ) // circular buffer method
	{
		index++;
		if ( index > 9 )
		{
			index = 0;
			overFlow = true;
		}

	}

	if ( overFlow == true )
	{
		for ( int i = 0; i < 10; i++)
		{

			cout << buffer[index] << endl;
			index++;

			if ( index > 9 )
			{
				index = 0;
			}

		}
	}
	else // if there is less than 10 lines
	{
		cout << "There is less than or at most 10 lines.\n";
		for (int i = 0; i < index; i++)
		{
			cout << buffer[i] << endl;
		}
	}

	return 0;
}