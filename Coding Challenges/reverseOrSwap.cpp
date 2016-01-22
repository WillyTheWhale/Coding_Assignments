#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct RSS
{
    int length = 0;
    int startIndex;
    int lastIndex;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int SIZE;
    cin >> SIZE;
    
    int array [ SIZE + 1 ] ;
    
    for ( int i = 1; i <= SIZE ; i++ )
    {
        cin >> array[i];
    }
    RSS RSSarray [ SIZE / 2 ];
    int j = 0;
    
    
    int numRSS = 0;
    bool thisIsRSS = false;

    
    for ( int i = 1; i < SIZE ; i++)
    {
        if ( thisIsRSS == false ) // This is when we are not in a RSS
        {
           
            if ( array[i] > array[ i + 1 ] ) // is this the start of a RSS then?
            {                                // (which is when the current element
                numRSS++;                    // is greater than the next).
                if ( numRSS > 2 ) // if we have 3 RSS, we cant do anything period.
                {
                    cout << "no";
                    return 0;
                }
                
                thisIsRSS = true; // next loop, we will test for the end of RSS
                if ( j > ( SIZE / 2 ) )
                    cout << "PROBLEM" << endl;
                RSSarray[j].startIndex = i;
            }
            
        }
        
        else // Then we are in a RSS
        {
            if ( array[i] < array[i+1] ) // is this the last element of an RSS?
            {
                RSSarray[j].lastIndex = i;
                RSSarray[j].length = 1 + RSSarray[j].lastIndex - RSSarray[j].startIndex;
                
                thisIsRSS = false; // then the next element is not part of this RSS
            }
        }
        
    }
    
    // below is when there are only 2 RSS or less.
    if ( SIZE == 2 )
    {
        if ( array[1] > array[2] )
        {
            cout << "yes" << endl;
            cout << "swap 1 2";
            return 0;
        }
        else
        {
            cout << "no";
            return 0;
        }
    }
    
    
    if ( numRSS <= 2 ) // we NEED to make a  reverse or swap. 
    {
        bool fail = false;
        for ( int i = 0; i < 2; i++ )
        {
            if ( RSSarray[i].length > 2 ) // check if there is any of size 3 or higher
            {
                if ( numRSS != 1 )
                {   
                    fail = true; // then we seriously cant do it, unless there is just one RSS
                    cout << "no";
                    cout << " fail";
                    return 0;
                }
            }
        }
        
        if ( numRSS == 2 ) // there are two RSS THEN WE NEED TO MAKE A SWAP
        {
        
            if ( RSSarray[0].startIndex == 1 ) // check if the array starts with a RSS
            {
                int interestValue = array[1]; // we need to compare the first ele
                int left = array[ RSSarray[1].startIndex ]; // with this
                int right = array[ RSSarray[1].lastIndex + 1 ];
                
                if ( ( interestValue > left ) && ( interestValue < right ) )
                {
                    cout << "yes" << endl;
                    cout << "swap 1 " << array[ RSSarray[1].lastIndex ];
                    return 0;
                }
                
                else
                {
                    cout << "no";
                    return 0;
                }
            }
            
            else // the array doesnt start with one.
            {
                int swapVal1 = array[ RSSarray[0].startIndex ];
                int swapVal2 = array[ RSSarray[1].lastIndex ];
                int leftOfVal1 = array[ RSSarray[0].startIndex - 1 ];
                int rightOfVal1 = array[ RSSarray[0].lastIndex ];
                int leftOfVal2 = array[ RSSarray[1].startIndex ];
                int rightOfVal2 = array[ RSSarray[1].lastIndex + 1 ];
                
                if ( ( swapVal1 > leftOfVal2 ) && ( swapVal1 < rightOfVal2 ) && ( leftOfVal1 < swapVal2 ) && ( swapVal2 < rightOfVal1 ) )
                {
                    cout << "yes" << endl;
                    cout << "swap " << RSSarray[0].startIndex << " " <<  RSSarray[1].lastIndex ;

                }
                
                else
                {
                    cout << "no";
                }
            }
            
        }
        
        else if ( numRSS == 0 ) // there are no RSS
        {
            cout << "Yes";
        }
        
        else // just one RSS
        {
            
            if ( RSSarray[0].length > 3 ) // NO SWAPS ALLOWED, WE NEED TO MAKE A REVERSAL.
            {    
                if ( RSSarray[0].startIndex == 1 ) // if the array starts with this one RSS with length 4 and above
                {                                  // WE NEED TO MAKE A REVERSAL!!!!
                
                    if ( array[1] < array[ RSSarray[0].lastIndex + 1 ] ) // THIS REVERSE IS POSSIBLE
                    {
                        cout << "yes" << endl;
                        cout << "reverse " << RSSarray[0].lastIndex << " 1";
                        return 0;
                    }
                
                    else // THAT REVERSAL WAS NOT POSSIBLE
                    {
                        cout << "no";
                        return 0;
                    }
                    
                }
                
                else if ( RSSarray[0].lastIndex == SIZE ) // ARRAY ENDS WITH RSS, AND WE NEED TO MAKE A REVERSAL
                {
                    
                    if ( array[SIZE] > array[ RSSarray[0].startIndex - 1 ] ) // IS IT POSSIBLE?
                    {
                        cout << "yes" << endl;
                        cout << "reverse " << SIZE << " " << RSSarray[0].startIndex;
                        return 0;
                    }
                    else // NO IT IS NOT.
                    {   
                        cout << "no" << endl;
                        return 0;
                    }
                }
                
                else // IT DOES NOT START NOR END WITH THAT SINGLE RSS, AND WE NEED TO MAKE THAT REVERSAL.
                {
                    int valLeftOfStart = array[ RSSarray[0].startIndex - 1 ];
                    int valRightOfLast = array[ RSSarray[0].lastIndex + 1 ];
                    int startVal = array[ RSSarray[0].startIndex ];
                    int lastVal = array[ RSSarray[0].lastIndex ];
                   
                    if ( ( lastVal > valLeftOfStart ) && ( startVal < valRightOfLast ) ) // SO CAN WE MAKE THAT REVERSAL?!?!?!?
                    {
                        cout << "yes" << endl;
                        cout << "reverse " << RSSarray[0].startIndex << " " << RSSarray[0].lastIndex;
                        return 0;
                    }
                   
                    else // NO WE CANT!
                    {
                        cout << "no";
                        return 0;
                    }
                   
                }
            }
            
            else // WE CAN MAKE EITHER A SWAP OR A REVERSE, THEY ARE ESSENTIALLY THE SAME. THE SINGLE RSS IS SIZE 3 OR 2
            {
                if ( RSSarray[0].startIndex == 1 ) // if the array starts with this one RSS with length 3 or 2
                {                                  // WE NEED TO MAKE THAT SWAP!!!!
                
                    if ( array[1] < array[ RSSarray[0].lastIndex + 1 ] ) // THIS SWAP IS POSSIBLE 
                    {
                        cout << "yes" << endl;
                        cout << "swap 1 " << RSSarray[0].lastIndex;
                        return 0;
                    }
                    else // THIS SWAP IS NOT EVEN POSSIBLE, THEREFORE A REVERSE IS NOT POSSIBLE
                    {
                        cout << "no" << endl;
                        return 0;
                    }
                }
                
                else if ( RSSarray[0].lastIndex == SIZE ) // DOES THIS ARRAY END IN A RSS
                {
                    if ( array[SIZE] > array[ RSSarray[0].startIndex - 1 ] ) // CAN WE MAKE THIS SWAP
                    {
                        cout << "yes" << endl;
                        cout << "swap " << RSSarray[0].startIndex << " " << RSSarray[0].lastIndex;
                        return 0;
                    }
                    
                    else // NO WE CANNOT
                    {
                        cout << "no";
                        return 0;
                    }
                    
                }
                    
                else // THIS RSS, WHICH IS SIZE 2 OR 3,  IS NOT AT THE START , NOR THE END OF THE ARRAY.
                {
                    int valLeftOfStart = array[ RSSarray[0].startIndex - 1 ];
                    int valRightOfLast = array[ RSSarray[0].lastIndex + 1 ];
                    int startVal = array[ RSSarray[0].startIndex ];
                    int lastVal = array[ RSSarray[0].lastIndex ];
                    
                    if ( ( lastVal > valLeftOfStart ) && ( startVal < valRightOfLast ) ) // IF WE CAN MAKE A SWAP, WHICH IS SAME AS
                    {                                                                    // A REVERSE
                        cout << "yes" << endl;
                        cout << "swap " << RSSarray[0].startIndex << " " << RSSarray[0].lastIndex;
                        return 0;
                    }
                    else
                    {
                        cout << "no";
                        return 0;
                    }
                }
            }
        }
        
    }
    
    else
    {
        cout << "no";
    }
        

    
    return 0;
}