///***********************************************************************************

/// Title: Matrix Rotation

/// Description: 

/// 

/// Author: Willy Ma

/// HackerRank

/// Date: January 17, 2016

/// Status : Complete

/// 

/// 

///***********************************************************************************

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class RingLayer
{
private:
	int *arrayPtr;

	static int rotations;
	int front;
	int ringSize;

	int qty;




public:
	RingLayer()
	{

	}
	~RingLayer();
	void createArray( int );
	void rotate();
	static void setRotations( int );
	void retrieveOne( int & );
	void addElement( int );

};

int RingLayer::rotations;

void RingLayer::createArray( int SIZE )
{
	arrayPtr = new int [ SIZE ];
	ringSize = SIZE;
	front = 0;
	qty = 0;


}
RingLayer::~RingLayer()
{
	delete [] arrayPtr;
}
void RingLayer::rotate()
{
	front = front + ( rotations % ringSize );
}

void RingLayer::setRotations( int r )
{
	rotations = r;
}

void RingLayer::retrieveOne( int &output)
{
	output = *( arrayPtr + front );
	front++;
	front = front % ringSize;
}



void RingLayer::addElement( int element )
{
	*( arrayPtr + qty ) = element;
	qty++;
}

int main()	
{
	int rows;
	int columns;
	int rotations;
	cin >> rows >> columns >> rotations;

	RingLayer::setRotations( rotations );


	int matrix [rows][columns];

	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			int input;
			cin >> input;
			matrix[i][j] = input;
		}
	}

	int numRings = min( rows , columns ) / 2;
	
	int outerSize = 2 * ( rows + columns - 2 );

	int SIZES [ numRings ];

	for ( int i = 0; i < numRings; i++ )
	{
		SIZES[i] = outerSize - ( 8 * i );
	}

	RingLayer rings[ numRings ];

	for ( int i = 0; i < numRings; i++ )
	{
		rings[i].createArray( SIZES[i] );
	}

	for ( int count = 0, iStopper = 1, jStopper = 0, i = 0, j = 0,
		rightBorder = ( columns - 1 ), BottomBorder = ( rows - 1 ), 
		leftBorder = 0, ringNumber = 0, direction = 0;
		count < ( columns * rows ); count++ )
		// direction: 0 for right , 1 for down, 2 for left, 3 for up
	{
		rings[ringNumber].addElement( matrix[i][j] );

		if ( ( direction == 3) && ( ( i == iStopper ) && ( j == jStopper ) ) )
		{
			iStopper++;
			jStopper++;
			j++;
			direction = 0;
			ringNumber++;
		}

		else if ( ( direction == 0 ) && ( j == rightBorder ) )
		{
			direction = 1;
			rightBorder--;
			i++;
		}

		else if ( ( direction == 1 ) && ( i == BottomBorder ) )
		{
			direction = 2;
			BottomBorder--;
			j--;
		}

		else if ( ( direction == 2 ) && ( j == leftBorder ) )
		{
			direction = 3;
			leftBorder++;
			i--;
		}

		else if ( direction == 0 )
		{
			j++;
		}

		else if ( direction == 1 )
		{
			i++;
		}

		else if ( direction == 2 )
		{
			j--;
		}

		else if ( direction == 3 )
		{
			i--;
		}

	}

	int ringNumber = 0;

	for ( int i = 0; i < numRings; i++ )
	{
		rings[i].rotate();
	}

	int temp;

	for ( int count = 0, iStopper = 1, jStopper = 0, i = 0, j = 0,
		rightBorder = ( columns - 1 ), BottomBorder = ( rows - 1 ), 
		leftBorder = 0, ringNumber = 0, direction = 0;
		count < ( columns * rows ); count++ )
		// direction: 0 for right , 1 for down, 2 for left, 3 for up
	{
		rings[ringNumber].retrieveOne( temp );

		matrix[i][j] = temp;

		if ( ( direction == 3) && ( ( i == iStopper ) && ( j == jStopper ) ) )
		{
			iStopper++;
			jStopper++;
			j++;
			direction = 0;
			ringNumber++;
		}

		else if ( ( direction == 0 ) && ( j == rightBorder ) )
		{
			direction = 1;
			rightBorder--;
			i++;
		}

		else if ( ( direction == 1 ) && ( i == BottomBorder ) )
		{
			direction = 2;
			BottomBorder--;
			j--;
		}

		else if ( ( direction == 2 ) && ( j == leftBorder ) )
		{
			direction = 3;
			leftBorder++;
			i--;
		}

		else if ( direction == 0 )
		{
			j++;
		}

		else if ( direction == 1 )
		{
			i++;
		}

		else if ( direction == 2 )
		{
			j--;
		}

		else if ( direction == 3 )
		{
			i--;
		}

	}


	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
		
	}







    return 0;
}
