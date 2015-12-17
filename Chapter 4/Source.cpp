///***********************************************************************************

///Title: Geometry Calculator

/// Description: 

/// 

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : Complete 

/// 

/// 

///***********************************************************************************
using namespace std;

#include <iostream>

int main()
{
	cout << "Geometry Calculator\n";
	cout << "1. Calculate the Area of a Circle\n";
	cout << "2. Calculate the Area of a Rectangle\n";
	cout << "3. Calculate the area of a Triangle\n";
	cout << "4. Quit\n";
	cout << "Please enter a choice 1-4:";
	
	int input;
	cin >> input;
	while ((input < 1) || (input > 4))
	{
		cout << "Invalid Selection. Please enter a number 1 through 4.\n";
		cin >> input;
	}

	if (input == 1)
	{
		const double PI = 3.14159;
		double radius;

		cout << "Please enter the radius:\n";
		cin >> radius;
		while (radius < 0)
		{
			cout << "Error. Please enter a positive radius.\n";
			cin >> radius;
		}
		cout << "The radius is " << (radius*radius*PI) << endl;
	}

	else if (input == 2)
	{
		double length;
		double width;

		cout << "Please enter the length:\n";
		cin >> length;
		while (length < 0)
		{
			cout << "Error. Please enter a positive length.\n";
			cin >> length;
		}

		cout << "Please enter the width:";
		cin >> width;
		while (width < 0)
		{
			cout << "Error. please enter a positive width: \n";
			cin >> width;
		}
		cout << "The area is: " << (width*length) << endl;

	}
	
	else if (input == 3)
	{
		double base;
		double height;

		cout << "Please enter the base:\n";
		cin >> base;
		
		while (base < 0)
		{
			cout << "Error. Please enter a positive base:\n";
			cin >> base;
		}

		cout << "Please enter the height:\n";
		cin >> height;

		while (height < 0)
		{
			cout << "Error. Please enter a positive height:\n";
			cin >> height;
		}
		
		cout << "The area is " << (base*height) << endl;
	}
	cout << "Goodbye!" << endl;

	cin.get();
	cin.get();
	return 0;
}