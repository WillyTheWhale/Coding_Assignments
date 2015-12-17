///***********************************************************************************

/// Title: Drink Machine Simulator

/// Description: This program simulates a soft drink machine. It uses a structure that

/// stores data such as drink name, drink cost, and the number of drinks in the machine.

/// The program creates an array of 5 structures. Each time the program runs, it will:

/// display a list of drinks, allow the user to pick one or quit. The user can then 

/// enter the amount of money to be inserted into the drink machine. The program will 

/// display the amount of change, and then subtract one from the number of that drink

/// left. Loop repeats, then when the user quits, the machine displays its earnings.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : Complete 

/// 

/// 

///***********************************************************************************
using namespace std;

#include <iostream>
#include <string>

// Define an object named SodaData that holds info about different soda.
struct SodaData
{
	string name;
	double cost;
	int qty;
};

void displayOptions(SodaData[]); // This function displays YOUR OPTIONS!!!!
void takeYoCash(double &); // This function stores how much $$ the user entered


int main()
{
	// Define an array of 5 different sodas, that "belong" to a specific machine"

	SodaData machine01[5] = {
		{ "Cola", 0.75, 20 },
		{ "Root Beer", 0.75, 20 },
		{ "Lemon-Lime", 0.75, 20 },
		{ "Grape Soda", 0.80, 20 },
		{ "Cream Soda", 0.80, 20 }
	};

	int input;
	double earnings = 0;
	do
	{
		displayOptions(machine01);
		// Choose an option!
		cout << "Please choose an option: ";
		cin >> input;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number:";
			cin >> input;
		}
		// Validate that option!
		while ((input < 0) || (input > 5))
		{
			cout << "Please pick an option 1 - 5\n";
			cin >> input;
		}
		// Okay! Now you have a valid option.

		// Did you want to quit?
		if (input == 5)
		{
			cout << "This machine has made $" << earnings << " off of you :) ";
			cout << "Bye!\n";
			int dummy;
			cin >> dummy;
			exit(EXIT_SUCCESS);
		}
		// of course not. What did you pick again?
		cout << "You chose: " << machine01[input].name << endl;

		// You've picked a soda, and now you need to enter $$!
		double cashInput;
		takeYoCash(cashInput);




		// Now that you've entered an amount that we've validated, what next? We show you your Change!!!
		// Based on your option, we will dictate your change.
		if (input == 0) // Did you choose Cola?
		{
			// Do we even have any more cola left??
			if (machine01[input].qty > 0) // yES WE DO, THEN PROCEED.
			{

				if (cashInput < machine01[input].cost) // Really? You didn't even enter enough cash dude.
				{
					cout << "Your change is: " << cashInput << endl;
					cout << "You didn't have enough money. Loser.\n\n";
				}
				else // YOU'RE A PROUD OWNER OF A NEW CAN OF SODA!!! CONGRATULATIONS!! CAVITIES FOR THE WIN!!
				{
					cout << "Your change is: " << (cashInput - machine01[input].cost) << endl; // Change determined.
					machine01[input].qty--; // We have one less of that soda, since you bought one. jerk.
					earnings += machine01[input].cost;
					cout << "Enjoy your " << machine01[input].name << endl;
				}
			}

			else // NO, WE'RE OUT OF COLA!!!
				cout << "We're out of " << machine01[input].name << ", sorry.\n";
		}
		if (input == 1) // Did you choose Root Beer?
		{
			// Do we even have any more Root Beer left??
			if (machine01[input].qty > 0) // yES WE DO, THEN PROCEED.
			{

				if (cashInput < machine01[input].cost) // Really? You didn't even enter enough cash dude.
				{
					cout << "Your change is: " << cashInput << endl;
					cout << "You didn't have enough money. Loser.\n\n";
				}
				else // YOU'RE A PROUD OWNER OF A NEW CAN OF SODA!!! CONGRATULATIONS!! CAVITIES FOR THE WIN!!
				{
					cout << "Your change is: " << (cashInput - machine01[input].cost) << endl; // Change determined.
					machine01[input].qty--; // We have one less of that soda, since you bought one. jerk.
					earnings += machine01[input].cost;
					cout << "Enjoy your " << machine01[input].name << endl;
				}
			}

			else // NO, WE'RE OUT OF Root Beer!!!
				cout << "We're out of " << machine01[input].name << ", sorry.\n";
		}
		if (input == 2) // Did you choose Lemon Lime?
		{
			// Do we even have any more Lemon Lime left??
			if (machine01[input].qty > 0) // yES WE DO, THEN PROCEED.
			{

				if (cashInput < machine01[input].cost) // Really? You didn't even enter enough cash dude.
				{
					cout << "Your change is: " << cashInput << endl;
					cout << "You didn't have enough money. Loser.\n\n";
				}
				else // YOU'RE A PROUD OWNER OF A NEW CAN OF SODA!!! CONGRATULATIONS!! CAVITIES FOR THE WIN!!
				{
					cout << "Your change is: " << (cashInput - machine01[input].cost) << endl; // Change determined.
					machine01[input].qty--; // We have one less of that soda, since you bought one. jerk.
					earnings += machine01[input].cost;
					cout << "Enjoy your " << machine01[input].name << endl;
				}
			}

			else // NO, WE'RE OUT OF Lemon Lime!!!
				cout << "We're out of " << machine01[input].name << ", sorry.\n";
		}
		if (input == 3) // Did you choose Grape Soda?
		{
			// Do we even have any more Grape Soda left??
			if (machine01[input].qty > 0) // yES WE DO, THEN PROCEED.
			{

				if (cashInput < machine01[input].cost) // Really? You didn't even enter enough cash dude.
				{
					cout << "Your change is: " << cashInput << endl;
					cout << "You didn't have enough money. Loser.\n\n";
				}
				else // YOU'RE A PROUD OWNER OF A NEW CAN OF SODA!!! CONGRATULATIONS!! CAVITIES FOR THE WIN!!
				{
					cout << "Your change is: " << (cashInput - machine01[input].cost) << endl; // Change determined.
					machine01[input].qty--; // We have one less of that soda, since you bought one. jerk.
					earnings += machine01[input].cost;
					cout << "Enjoy your " << machine01[input].name << endl;
				}
			}

			else // NO, WE'RE OUT OF Grape Soda!!!
				cout << "We're out of " << machine01[input].name << ", sorry.\n";
		}
		if (input == 4) // Did you choose Cream Soda?
		{
			// Do we even have any more Cream Soda left??
			if (machine01[input].qty > 0) // yES WE DO, THEN PROCEED.
			{

				if (cashInput < machine01[input].cost) // Really? You didn't even enter enough cash dude.
				{
					cout << "Your change is: " << cashInput << endl;
					cout << "You didn't have enough money. Loser.\n\n";
				}
				else // YOU'RE A PROUD OWNER OF A NEW CAN OF SODA!!! CONGRATULATIONS!! CAVITIES FOR THE WIN!!
				{
					cout << "Your change is: " << (cashInput - machine01[input].cost) << endl; // Change determined.
					machine01[input].qty--; // We have one less of that soda, since you bought one. jerk.
					earnings += machine01[input].cost;
					cout << "Enjoy your " << machine01[input].name << endl;
				}
			}

			else // NO, WE'RE OUT OF Cream Soda!!!
				cout << "We're out of " << machine01[input].name << ", sorry.\n";
		}
	} while (input != 5);

	return 0;
};

void displayOptions(SodaData machine[])
{
	cout << "--------------------------------------\n";
	cout << "0. " << machine[0].name << "\t\t( " << machine[0].qty << " left in stock)" << endl;
	for (int i = 1; i < 5; i++)
	{
		cout << i << "." << " " << machine[i].name << "\t( " << machine[i].qty << " left in stock)" << endl;
	}
	cout << "5. Quit" << endl;
};

void takeYoCash(double &cash)
{
	cout << "Please enter some money.\n";
	cin >> cash;
	while ((cash < 0.00) || (cash > 1.00))
	{
		cout << "This machine only takes an cash between 0.00 - 1.00 dollars.\n";
		cin >> cash;
	}
	cout << "You've entered: " << cash << endl;
};