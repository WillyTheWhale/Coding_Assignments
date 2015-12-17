
// Number Array Class written by Odile Sutsakhan   REFERENCE PARAMETER????

#include <iostream>
#include <string>
using namespace std;

class NumberArray {
private: 
double *ptr;     //declaring a pointer variable that will be used to point to the array
double highest;
double lowest;
double sum;
double average;


public: 

NumberArray (int); //constructor that accept an int as an argument 
~NumberArray(); //destructor
void setNumber(int);
double getNumber(int);
double getHighest ();
double getLowest();
double getAverage();

};


//defining the constructor:

NumberArray :: NumberArray (int E){
 
 	if (E=0){
 		return -1; //stops following the rest of the code of the function
 	}

	if (E!=0) {
	ptr= new double NumberArray[E];
	}



}

// defining the destructor:

NumberArray :: ~NumberArray {

	delete [] ptr;
}

// setting number

Number Array :: void setNumber( double numb, int A) {     //getting data from user (numb & element #)

	if (A>E)
	{
		cout<<"Invalid. You did not create a big enough array to hold that many elements"<<endl;
		return 1;
	}

	*(ptr A)= numb;

}

//returns a number of chosen element
NumberArray :: double getNumber(int B){ 
    //takes value and returns value 
	return *(ptr B);

}

//returns the highest value of the array
NumberArray :: double getHighest() {

	highest= *(ptr);

	for (int x=1; x<E; x  ){
		if *(ptr  x) > highest {
			highest= *(ptr x);
		}
	}
return highest;
}

// returns the lowest value of the array
NumberArray:: double getLowest(){

	lowest= *(ptr);
	for (int x=1; x<E; x  ){
		if *(ptr x)< highest {
			lowest= *(ptr x);
		}
	}

return lowest;

}


//calculating Average and displaying it
NumberArray:: double Average() {

	sum=0;

	for(int x=0; x<E; x  )
	{
		sum= *(ptr x)  sum;

	}

  average= sum/E;

  return average;
}



//action time!
int main {

	NumberArray array;

	cout<<"The size of your array is : "<<endl;
	cin>>sizeofArray;
	NumberArray(sizeofArray);

	cout<<"Array was created of size " << sizeofArray<<endl;

	for (int x=0; x<sizeofArray; x  )
	{
	cout<<"What value number would you like to add to the array?"<<endl;
	cin>>numb;
	cout<<"To which element number: "<<endl;
	cin>> A;
	setNumber(numb, A);

}


	cout<<"What element of the array would you like to read? " <<endl;
	cin>>B;
	getNumber(B);

	double High= getHighest();
	cout<<"Your highest value is "<<high<<endl;

	double Low=getLowest();
	cout<<"Your lowest value is "<<Low<<endl;

	double average= getAverage();
	cout<<"Your average is "<<average<<endl;




return 0;
}