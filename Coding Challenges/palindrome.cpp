///***********************************************************************************

/// Title: Palindrome Index

/// Description: 

/// 

/// Author: Willy Ma

/// HackerRank

/// Date: January 17, 2016

/// Status : Incomplete

/// 

/// 

///***********************************************************************************
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome( const char * );
int oddErrorSearch( const char * ); // these returns -1 if it is left side
int evenErrorSearch( const char * ); // anomaly, 1 if right side anomaly.
bool evenMidTest( const char * ); // true if the anomaly is in the middle two
void leftErrorIndex( const char * ); // searches for anomaly on left side
void rightErrorIndex( const char * ); // searches for anomaly on right side
void sizeThree( const char * );	// solves problem if size 3 string.

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numTests;
    cin >> numTests;
    cin.ignore();

    string palindromes[ numTests ]; // create an array of strings

    for ( int i = 0; i < numTests; i++ )
    {
    	getline( cin , palindromes[ i ] ); // fill the array of strings
    }

    for ( int i = 0; i < numTests; i++ )
    {

    	int N = palindromes[ i ].length();

    	if ( N == 1 )
    	{
    		cout << -1 << endl;
   			continue;
   		}

    	else if ( N == 2 )
   		{
   			cout << 0 << endl;
   			continue;
   		}

   		else if ( N == 3 )
   		{
   			sizeThree( palindromes[ i ].c_str() );
   			continue;
   		}

    	else if ( isPalindrome( palindromes[ i ].c_str() ) == true )
    	{
    		cout << -1 << endl;
    		continue;
    	}

    	else
    	{
    		
    		if ( ( N % 2 ) == 0 ) // if even
    		{
    			if ( evenMidTest( palindromes[ i ].c_str() ) == true )
    			{	// check if we need to remove just one of the mid two
    				cout << ( N / 2 ) << endl;
    				continue;
    			}

    			else
    			{
    				if ( evenErrorSearch( palindromes[ i ].c_str() ) == -1 )
    				{	// if the error is on the left side
    					leftErrorIndex( palindromes[ i ].c_str() );
    					continue;
    				}

    				else if ( evenErrorSearch( palindromes[ i ].c_str() ) == 1 )
    				{ // if the error is in the right side
    					rightErrorIndex( palindromes[ i ].c_str() );
    					continue;
    				}
    			}

    		}

    		else // if odd
    		{
    			if ( oddErrorSearch( palindromes[ i ].c_str() ) == -1 )
    				{	// if the error is on the left side
    					leftErrorIndex( palindromes[ i ].c_str() );
    					continue;
    				}

    			else if ( oddErrorSearch( palindromes[ i ].c_str() ) == 1 )
    				{ // if the error is in the right side
    					rightErrorIndex( palindromes[ i ].c_str() );
    					continue;
    				}
    		}

    	} // end else


    } // end forLoop

    // Update: Figured it out on paper.
    //
    // odd:
    // a d c c c c d a *x*
    // examine middle, left, right. if they're all the same,
    // move left towards the left, move right towards right.
    // Do this until either one is different.

    // even:
    // a a *x* a now size 4

    // a a a *x* a a now size 6

    // SIZE 8	 ****
    // *x* a  b  c  d  c  b  a 

    //  a *x* b  c  d  c  b  a 

    //  a  b *x* c  d  c  b  a 
    
    //  a  b  c *x* d  c  b  a  // if x were d, it would be palindrome.

    //  a  b  c  d *x* c  b  a  // if x were d, it would be palindrome

   	//  a  b  c  d  c *x* b  a 

    //  a  b  c  d  c  b *x* a

    //  a  b  c  d  c  b  a *x*

    //	a  b  c  d1
    

    //	x  a  b  c

    //	a  x  b  c

    //  a  b  x  c

    //  a  b  c  x

    // because we first check for it being a palindrome, we omit the cases for
    // x being a in the middle two.

    //			 ****
	//  a  b  c  c  c  b  a *x*

	//  a  d  c  c  c  d  a *x*

	//  c  c  c  c  c  c  c *x*

	//  a  b  c  d *x* c  b  a
	//  a  b  c  c *x* c  b  a // if d was c, you could remove d, x, 

	// x is anything but what d is. 

    //	1. Check if it is a palindrome
	//	2. Check the middle two. 
	//		If they're the same, check the sides of them,
	// 			until one of them are not the same as the middle.
	//		If they're not the same, then check the sides of them. one of them
	//			will be the same as one of the middles. If it is the left side,






    return 0;
}


bool isPalindrome( const char *strPtr ) // strings of length 4 and above are passed.
{
	int N = strlen( strPtr );

	for ( int i = 0; i < ( N / 2 ); i++ ) // check outer pairs, going in
	{
		if ( *( strPtr + i ) != *( strPtr + ( N - 1 - i) ) )
		{
			return false;
		}
	}

	return true;

}

int oddErrorSearch( const char *strPtr )
{
	int N = strlen( strPtr );
	char midChar = *( strPtr + ( N / 2 ) );
	char leftMidChar = *( strPtr + ( N / 2 ) - 1 );
	char rightMidChar = *( strPtr + ( N / 2 ) + 1 );
	if ( ( leftMidChar == midChar ) && ( rightMidChar == midChar ) )
	{
		for ( int i = 1; i < ( N / 2 ); i++ )
		{
			leftMidChar = *( strPtr + ( N / 2 ) - 1 - i ); // shift left
			rightMidChar = *( strPtr + ( N / 2 ) + 1 + i ); // shift right

			if ( ( leftMidChar == midChar ) && ( rightMidChar == midChar ) )
			{
				continue; // if both are still same as mid, nothing interesting
			}

			else if ( leftMidChar != midChar ) // then the anomaly is on left
			{
				return -1;
			}

			else if ( rightMidChar != midChar ) // anomaly on right side
			{
				return 1;
			}
		}
	}

	else if ( leftMidChar != midChar )
	{
		return -1; // then the anomaly is on left side
	}

	else if ( rightMidChar != midChar )
	{
		return 1; // anomaly is on right side
	}
}

bool evenMidTest( const char *strPtr )
{
	int N = strlen( strPtr );
	for ( int i = 0; i < ( ( N / 2 ) - 1); i++ )
	{
		if ( *( strPtr + i ) != *( strPtr + ( N - 1 - i) ) )
			{
				return false;
			}
	}

	return true; // if each outer pair except for mid two are same, then you
				 // can remove either one of the middle two.
}





int evenErrorSearch( const char *strPtr )
{
	int N = strlen( strPtr );
	if ( *( strPtr + ( N / 2 ) - 1) == *( strPtr + ( N / 2 ) + 1 ) )
	{
		return -1; // the anomaly is to the left.
	}

	else if ( *( strPtr + ( N / 2 ) - 2 ) == *( strPtr + ( N / 2 ) ) )
	{
		return 1; // anomaly on right.
	}
}

void leftErrorIndex( const char *strPtr )
{
	int N = strlen( strPtr );
	for ( int i = 0; i < ( N / 2 ); i++ )
	{
		if ( *( strPtr + i ) != *( strPtr + ( N - 1 ) - i ) )
		{
			cout << i << endl;
			return;
		}
	}
}

void rightErrorIndex( const char *strPtr )
{
	int N = strlen( strPtr );
	for ( int i = 0; i < ( N / 2 ); i++ )
	{
		if ( *( strPtr + i ) != *( strPtr + ( N - 1 ) - i ) )
		{
			cout << ( N - 1 - i ) << endl;
			return;
		}
	}
}

void sizeThree ( const char *strPtr )
{
	char left = *strPtr;
	char mid = *( strPtr + 1 );
	char right = *( strPtr + 2 );

	if ( ( left == mid ) && ( left == right ) )
	{
		cout << -1 << endl;
	}

	else if ( left == mid )
	{
		cout << 2 << endl;
	}

	else
	{
		cout << 0 << endl;
	}

}