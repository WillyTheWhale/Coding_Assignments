///***********************************************************************************

/// Title: PC 1214

/// Description: Inventory Program

/// 

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: November 15, 2015

/// Status : Complete 

/// 

///***********************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

const int C_STRING_SIZE = 50;

struct InventoryItem
{
	char itemDescription[C_STRING_SIZE];
	int QtyOnHand;
	double WholesaleCost;
	double RetailCost;
	char DateAdded[C_STRING_SIZE];
};

void addRecord(fstream&);
void dispRecord(fstream&);
void changeRecord(fstream&);

int main()
{
	// Create a file
	fstream file;
	file.open("output.txt", ios::out);

	// Check if that file had been created.
	if (file.fail())
	{
		cout << "We failed to create a new file\n";
		return 0;
	}
	else
	{
		cout << "Successfully created a file...\n";
	}

	file.close();

	// Open that file for reading and writing in binary
	file.open("output.txt", ios::in | ios::out | ios::binary);

	if (file.fail())
	{
		cout << "We failed to open the file for reading and writing in binary\n";
		return 0;
	}
	else
	{
		cout << "Sucessfully opened that file for reading and writing in binary...\n";
	}


	int choice;

	do
	{
		cout << "\n\n\n\n\nMENU--------------------";
		cout << "\n1. Add Record\n";
		cout << "2. Display A Record\n";
		cout << "3. Change A Record\n";
		cout << "4. Quit\n";
		cout << "------------------------\n\n\n";
		cout << "Please select an option: ";

		cin >> choice;
		cin.ignore();
		if (choice == 1) // If we want to add a record, follow these instructions.
		{
			addRecord(file);
		}

		else if (choice == 2) // If we want to display a record, follow these instuctions.
		{
			dispRecord(file);
		}

		else if (choice == 3)
		{
			changeRecord(file);
		}


	} while (choice != 4);

	cout << "You chose to quit!\nBye Felicia~!\n";
	file.close();

	return 0;
}


void addRecord(fstream &file)
{
	InventoryItem item;

	// Populate the item to be stored in a record

	cout << "\nItem Description: ";
	cin.getline(item.itemDescription, ( C_STRING_SIZE - 1 ) );

	cout << "Quantity On Hand: ";
	cin >> item.QtyOnHand;

	cout << "Wholesale Cost: ";
	cin >> item.WholesaleCost;

	cout << "Retail Cost: ";
	cin >> item.RetailCost;
	cin.ignore();

	cout << "Date Added: ";
	cin.getline(item.DateAdded, ( C_STRING_SIZE - 1 ) );

	// item now populated with data

	file.seekp(0L, ios::end); // Set the p pointer to the end,

	file.write(reinterpret_cast< char * >(&item), sizeof(item));

};

void dispRecord(fstream &file)
{
	int entry;
	cout << "Enter the record number that you would like to view: ";

	cin >> entry;
	InventoryItem temp;

	// Find the starting address of a specified record
	file.seekg( static_cast<long>( entry * sizeof( temp ) ) , ios::beg );

	// Store the data into a temp variable
	file.read( reinterpret_cast< char * >(&temp) , sizeof(temp));

	// Display the data stored in temp
	cout << "\nItem Description: "	<< temp.itemDescription << endl;
	cout << "Quantity On Hand: " 	<< temp.QtyOnHand 		<< endl;
	cout << "Wholesale Cost: " 		<< temp.WholesaleCost 	<< endl;
	cout << "Retail Cost: " 		<< temp.RetailCost 		<< endl;
	cout << "Date Added: " 			<< temp.DateAdded 		<< endl;

};

void changeRecord(fstream &file)
{
	int entry;

	InventoryItem temp; // temp variable to hold new data

	cout << "Which entry do you want to change?";
	cin >> entry;
	cin.ignore();

	cout << "Please enter the new info:\n";

	cout << "\nItem Description: ";
	cin.getline(temp.itemDescription, ( C_STRING_SIZE - 1 ) );

	cout << "Quantity On Hand: ";
	cin >> temp.QtyOnHand;

	cout << "Wholesale Cost: ";
	cin >> temp.WholesaleCost;

	cout << "Retail Cost: ";
	cin >> temp.RetailCost;
	cin.ignore();

	cout << "Date Added: ";
	cin.getline(temp.DateAdded, ( C_STRING_SIZE - 1) );


	file.seekp( static_cast< long >( entry * sizeof( temp ) ) , ios::beg );
	file.write( reinterpret_cast< char * >( &temp ) , sizeof( temp ) );
};