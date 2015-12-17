///***********************************************************************************

///Title: Winning Division

/// Description: Determines which division of a company has the greatest sales 

/// for a quarter.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: September 27, 2015

/// Status : Complete 

/// 

/// 

///***********************************************************************************
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

// Define structures, because why not.
struct division
{
	string divName; // Name of division
	int dollar; // Dollar Amount for Gross Sale
	int cents;  // Cent Amount for Gross Sales
};

// Define array of structures
division company[4] = {
	{ "Northeast", 0, 0 },
	{ "Southeast", 0, 0 },
	{ "Northwest", 0, 0 },
	{ "Southwest", 0, 0 }
};


// Define each divisions' name.
//company[1].divName = "Northeast";
//company[2].divName = "Southeast";
//company[3].divName = "Northwest";
//company]4].divname = "Southwest";

// Prototype the functions;
void getSales(string, int&, int&);
bool findHighest(division[]);

int main()
{
	for (int i = 0; i < 4; i++)
	{
		getSales(company[i].divName, company[i].dollar, company[i].cents); // Populate the dollar and cent members of the elements in the array
	}
	for (int i = 0; i < 4; i++)
	{
		cout << company[i].divName << endl << company[i].dollar << endl << company[i].cents << endl;
	}
	findHighest(company);
	return 0;

}

// Define the function;
void getSales(string name, int &dollar, int &cents) // This function asks the user for the division's quarterly sales figure
{
	double amount;
	double temp;
	double tempdollar;

	cout << "Please enter the " << name << " division's quarterly sales figure.\n";
	cin >> amount;

	while (amount < 0)
	{
		cout << "Please enter a number that is greater than 0.";
		cin >> amount;
	}
	cout << "You put in " << amount << endl;
	temp = amount;
	tempdollar = trunc(temp);
	dollar = tempdollar;
	cents = ((amount - tempdollar)*100);
}


bool findHighest(division company[])
{
	for (int i = 0; i < 4; i++) // Take each division amount, compare it against every other division.
	{

		if (i == 0)		// Division 0 against all others:
		{
			int pass = 0;
			for (int j = 0; j < 3; j++)
			{
				if ((company[i].dollar > company[j + 1].dollar) || ( (company[i].dollar == company[j+1].dollar) && (company[i].cents > company[j + 1].cents) ) )
				{
					pass++;
					cout << "Pass for division 0" << endl;
				}
				if (pass == 3)
				{
					cout << "The " << company[i].divName << " division had the greatest sales with $" << company[i].dollar << "." << company[i].cents << endl;
				}
			}
		}
		if (i == 1)		// Division 1 against all others:
		{
			int pass = 0;
			if ((company[i].dollar > company[i - 1].dollar) || ( (company[i].dollar == company[i-1].dollar) && (company[i].cents > company[i - 1].cents)) ) // div 1 against div 0
			{
				pass++;
				cout << "Pass for division 1" << endl;
			}

			for (int j = 1; j < 3; j++) // div 1 against div 2, and 3
			{
				if ((company[i].dollar > company[j + 1].dollar) || ( (company[i].dollar == company[j+1].dollar) && (company[i].cents > company[j + 1].cents)) )
				{
					pass++;
					cout << "Pass for division 1" << endl;
				}
			}
			if (pass == 3)
			{
				cout << "The " << company[i].divName << " division had the greatest sales with $" << company[i].dollar << "." << company[i].cents << endl;
			}
		}
		if (i == 2)		// Division 2 against all others:
		{
			int pass = 0;
			for (int k = 0; k < 2; k++) // div 2 against div 0, and div 1
			{
				if ((company[i].dollar > company[k].dollar) || ( (company[i].dollar == company[k].dollar ) && (company[i].cents > company[k].cents) ) )
				{
					pass++;
					cout << "Pass for division 2" << endl;
				}
			}
			if ((company[i].dollar > company[i + 1].dollar) || ( (company[i].dollar == company[i + 1].dollar) && (company[i].cents > company[i + 1].cents)) ) // div 2 against div 3
			{
				pass++;
				cout << "Pass for division 2" << endl;
			}
			if (pass == 3)
			{
				cout << "The " << company[i].divName << " division had the greatest sales with $" << company[i].dollar << "." << company[i].cents << endl;
			}
		}
		if (i == 3) // Division 3 against all others:
		{
			int pass = 0;
			for (int j = 0; j < 3; j++)
			{
				if ((company[i].dollar > company[j].dollar) || ( (company[i].dollar == company[j].dollar) && (company[i].cents > company[j].cents) ) ) // div 3 against div 0, div 1, and div 2
				{
					pass++;
					cout << "Pass for division 3" << endl;
				}
			}
			if (pass == 3)
			{
				cout << "The " << company[i].divName << " division had the greatest sales with $" << company[i].dollar << "." << company[i].cents << endl;
			}
		}
	}
	return true;
}