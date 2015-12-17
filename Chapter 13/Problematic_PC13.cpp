///***********************************************************************************

/// Title: Number Array Class PROBLEM CHILD.

/// Description: PROBLEM: take const away from void dispArray(). The second time the 

/// function is called, right after the first, the values in the array has somehow

/// altered. I assumed that the function is changing the contents in my array. The 

/// memory addresses being called are not changing. The contents do not change during

/// function runtime. My function does not have any code that alter the contents stored

/// in those memory addresses.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : Complete 

/// 

/// 

///***********************************************************************************
#include <iostream>
#include <cstdlib>
using namespace std;

class MyClass
{
private:
	double	*doublePtr;
	int 	arrSize;
	void 	onInit( int ); // Mutator on initialization
	bool	validation( int ) const;

public:
	MyClass( int ); // Constructor, Accepts int
	~MyClass();		// Destructor
	int 	storeNum( double , int ); // Mutator, Stores a number into an element. Requested to return -1, for invalid index, or 0
	int 	retrieveValue( double & , int ) const; // Accessor, uses a reference parameter. Requested to return -1, for invalid index, or 0
	double 	returnHigh() const; // Accessor, returns the highest number.
	double 	returnLow()	 const; // Accessor, returns the lowest number.
	double 	returnAvg()  const; // Accessor, returns the average.

	int 	returnSize() const; // Accessor, returns the size of the array.
	double* returnPtr()  const; // Accessor, returns the address held by the class.

};

MyClass::MyClass( int size )
{
	onInit( size );
}

MyClass::~MyClass()
{
	delete doublePtr;
}

bool MyClass::validation(int position) const // ROLE: To check whether or not the index passed is out of bounds
{
	if ( ( position < 0 ) || ( position >= arrSize ) ) // Check to see if the index is out of bounds
	{
		return false;
	}
	else
	{
		return true; // return true if index is not out of bounds
	}

}
void MyClass::onInit( int size ) // ROLE: to initialize object attributes
{

	doublePtr 	= new double [ size ]; // Assigns the address of a dynamically allocated array to ptr

	arrSize		= size; // Assigns the size to the object's arrSize attribute
	for ( int i = 0; i < arrSize; i++ )
	{
		cout << "i = " << i << endl;
		*( doublePtr + i ) = 0;
		cout << "Address: " << ( doublePtr + i ) << endl;
		cout << "Value: " << *( doublePtr + i ) << endl;
	}
	cout << doublePtr << endl;
	cout << *doublePtr;
}

int MyClass::storeNum( double number, int position )
{
	if ( validation( position ) ) // If we're passed a valid index, continue store operation.
	{
		cout << "Before storing: " << endl;
		for ( int i = 0; i < arrSize; i++ )
		{
			cout << "Address of element " 	<< 	i 	<< " : " 	<<  ( doublePtr + i ) << endl;
			cout << "Value of element " 	<< 	i 	<< " : " 	<< *( doublePtr + i ) << endl;
		}

		*( doublePtr + position ) = number;

		cout << "\nAfter storing: " << endl;
		for ( int i = 0; i < arrSize; i++ )
		{
			cout << "Address of element " 	<< 	i 	<< " : " 	<<  ( doublePtr + i ) << endl;
			cout << "Value of element " 	<< 	i 	<< " : " 	<< *( doublePtr + i ) << endl;
		}
		return 0; // Also, return 0.
	}
	else // If not, return -1.
	{
		return -1;
	}
}

int MyClass::retrieveValue( double &storeHere, int position ) const
{
	if ( validation( position ) ) // Check to see if index passed is valid
	{
		storeHere = *( doublePtr + position );
		return 0;
	}
	else
	{
		return -1 ;
	}
}

double MyClass::returnHigh() const
{
	double high = *( doublePtr ); // set the highest to the first element.
	for ( int i = 1; i < arrSize; i++ )
	{
		if ( *( doublePtr + i ) > high )
		{
			high = *( doublePtr + i );
		}
	}
	return high;
}

double MyClass::returnLow() const
{
	double low = *( doublePtr );
	for (int i = 1; i < arrSize; i++ )
	{
		if ( *( doublePtr + i ) < low )
		{
			low = *( doublePtr + i );
		}
	}
	return low;
}

double MyClass::returnAvg() const
{
	double sum = 0;
	for ( int i = 0; i < arrSize; i++ )
	{
		sum = sum + *( doublePtr + i );
	}
	return ( sum / arrSize );
}

int MyClass::returnSize() const
{
	return arrSize;
}

double* MyClass::returnPtr() const
{
	return doublePtr;
}

void dispOptions()
{
	cout << "1. Store a number in the array" 						<< endl;
	cout << "2. Retrieve a number from any element of the array" 	<< endl;
	cout << "3. Return the highest number from the array" 			<< endl;
	cout << "4. Return the lowest number from the array"			<< endl;
	cout << "5. Return the average of all numbers stored"			<< endl;
	cout << "6. Sequentially overwrite and store array"				<< endl;
	cout << "7. Quit"												<< endl;

}

void dispArray( MyClass const )
{
	inClass double* localPtr = inClass.returnPtr();

	cout << "\ndoublePtr = " << inClass.returnPtr() << endl;
	cout << "localPtr = " << localPtr;

	cout << "\n\n\nYour Array is:\n";
	cout << "[ ";
	for ( int i = 0; i < inClass.returnSize(); i++ )
	{
		cout << *( localPtr + i ) << " ";
	}
	cout << "]\n ";

	for ( int i = 0; i < inClass.returnSize(); i++ )
	{
		cout << " " << i;
	}
	cout << endl;

	for ( int i = 0; i < inClass.returnSize(); i++ )
	{
		cout << "Address of element " 	<< 	i 	<< " : " 	<<  ( localPtr + i ) << endl;
		cout << "Value of element " 	<< 	i 	<< " : " 	<< *( localPtr + i ) << endl;
	}

	cout << "Again" << endl;
	for ( int i = 0; i < inClass.returnSize(); i++ )
	{
		cout << "Address of element " 	<< 	i 	<< " : " 	<<  ( localPtr + i ) << endl;
		cout << "Value of element " 	<< 	i 	<< " : " 	<< *( localPtr + i ) << endl;
	}
}

void sequentialStore( MyClass inClass )
{
	double input;
	cout << "Please input " << inClass.returnSize() << " numbers: " << endl;
	for ( int i = 0; i < inClass.returnSize() ; i++ )
	{		
		cout << ( i + 1 ) << ": ";
		cin >> input;
		inClass.storeNum( input , i );
	}
	cout << "Done.\n\n";
}

int main()
{
	int SIZE;
	int element;
	double number;
	double retrieved;

	cout << "Please enter the desired size of the array of floating point numbers: ";
	cin  >> SIZE;
	while ( SIZE < 1 )
	{
		cout << "Please enter a valid size: " << endl;
		cin >> SIZE;
	}

	MyClass lol( SIZE );
	cout << "\n---------Object has been instantiated---------\n";
	cout << "Dynamically allocated memory to an array of size " << SIZE << "...\n";
	cout << "Testing...\nFilling array with zeros...\n";
	dispArray( lol );
	dispArray( lol );


	cout << "\n\n--------------------------------------------------------------------------------";
	cout << "\nTesting storing function...\n";
	cout << "You may store any number into any element of the array.\n";
	cout << "Please enter a number to store: ";
	cin  >> number;
	cout << "\nPlease enter an element number: ";
	cin  >> element;
	cout << endl;

	while ( lol.storeNum( number , element ) == -1 )
	{
		cout << "Error! Please enter a valid position: ";
		cin  >> element;
		cout << endl;
	}

	cout << "Number successfully stored!\n";
	cout << "--------------------------------------------------------------------------------";
	dispArray( lol );

	cout << "\n\n--------------------------------------------------------------------------------";
	cout << "\nTesting retrieval function...\n";
	cout << "You may retrieve a number stored in any element of the array.\n";
	cout << "Try retrieving the number you just stored.\n";
	cout << "Please enter the element that you wish to retrieve: ";
	cin  >> element;
	cout << endl;

	while ( lol.retrieveValue( retrieved , element ) == -1 )
	{
		cout << "Error! Please enter a valid position: ";
		cin >> element;
		cout << endl;
	}

	cout << "Your number is: " << retrieved << endl;
	cout << "--------------------------------------------------------------------------------";
	dispArray( lol );

	cout << "\n\n--------------------------------------------------------------------------------";
	cout << "\nTesting Highest Number function...\n";
	cout << "The highest number is: " << lol.returnHigh() << endl;
	cout << "--------------------------------------------------------------------------------";
	dispArray( lol );

	cout << "\n\n--------------------------------------------------------------------------------";
	cout << "\nTesting Lowest Number function...\n";
	cout << "The lowest number is: " << lol.returnLow() << endl;
	cout << "--------------------------------------------------------------------------------";
	dispArray( lol );

	cout << "\n\n--------------------------------------------------------------------------------";
	cout << "\nTesting Averaging function...\n";
	cout << "The average is: " << lol.returnAvg() << endl;
	cout << "--------------------------------------------------------------------------------";
	dispArray( lol );

	cout << "\n\n===== Testing Complete =====\n\n";
	cout << "Feel free to play around with the class' functions!" << endl;

	int input;
	do
	{
		dispArray( lol );
		cout << "\n----- MENU -----\n";
		dispOptions();
		cout << "Select an option: ";
		cin >> input;
		cout << endl;
		while ( ( input < 1 ) || ( input > 7 ) )
		{
			cout << "Error! Please enter a valid option: ";
			cin >> input;
			cout << endl;
		}

		if ( input == 1 )
		{
			cout << "You may store any number into any element of the array.\n";
			cout << "Please enter a number to store: ";
			cin  >> number;
			cout << "\nPlease enter an element number: ";
			cin  >> element;
			cout << endl;

			while ( lol.storeNum( number , element ) == -1 )
			{
				cout << "Error! Please enter a valid position: ";
				cin  >> element;
				cout << endl;
			}
		}

		if ( input == 2 )
		{
			cout << "You may retrieve a number stored in any element of the array.\n";
			cout << "Try retrieving the number you just stored.\n";
			cout << "Please enter the element that you wish to retrieve: ";
			cin  >> element;

			while ( lol.retrieveValue( retrieved , element ) == -1 )
			{
				cout << "Error! Please enter a valid position: ";
				cin >> element;
				cout << endl;
			}

			cout << "Your number is: " << retrieved << endl;
		}

		if ( input == 3 )
		{
			cout << "The highest number is: " << lol.returnHigh() << endl;
		}

		if ( input == 4 )
		{
			cout << "The lowest number is: " << lol.returnLow() << endl;
		}

		if ( input == 5 )
		{
			cout << "The average is: " << lol.returnAvg() << endl;
		}

		if ( input == 6 )
		{
			sequentialStore( lol );
		}

	} while ( input != 7 );

	cout << "Bye Felicia. Bye. BYE. BAI." << endl;

	return 0;
}
