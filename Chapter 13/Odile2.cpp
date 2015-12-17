
// Number Array Class written by Odile Sutsakhan   

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
int setNumber(double, int, int);
double getNumber(int);
double getHighest (int);
double getLowest(int);
double getAverage(int);
int Validate1(int,int);
int Validate2(int,int);

};


//defining the constructor:

NumberArray :: NumberArray (int sizeofArray){
 
 	if(sizeofArray>1) {
 		ptr=new double [sizeofArray];
 		for (int x=0; x<sizeofArray; x++)
 			{ 
 				*(ptr+x)=0;
 			}
 
 
}

// defining the destructor:

NumberArray :: ~NumberArray(); 
{

	delete [] ptr;
}

// setting number

int NumberArray :: setNumber( double numb, int A, int sizeofArray) {     //getting data from user (numb & element #)

	if (A>sizeofArray)
	{
		return -1;
	}

	*(ptr+A)= numb;
	double Variable1= *(ptr+A);
	return 0;

}

//returns a number of chosen element
double NumberArray :: getNumber(int B){ 


    //takes value and returns value 
	double Variable2=*(ptr+B);
	return Variable2;
}

//returns the highest value of the array
double NumberArray :: getHighest(int sizeofArray) {

	highest= *(ptr);

	for (int x=1; x<sizeofArray; x++){
		if (*(ptr +x) > highest) {
			highest= *(ptr+x);
		}
	}
return highest;
}

// returns the lowest value of the array
double NumberArray:: getLowest( int sizeofArray ){

	lowest= *(ptr);
	for (int x=1; x<sizeofArray; x++){
		if (*(ptr+x)< highest) {
			lowest= *(ptr+x);
		}
	}

return lowest;

}


//calculating Average and displaying it
double NumberArray:: getAverage(int sizeofArray) {

	sum=0;

	for(int x=0; x<sizeofArray; x++)
	{
		sum= *(ptr+x)+ sum;

	}

  average= sum/sizeofArray;

  return average;
}

int NumberArray:: Validate1(int A, int sizeofArray){
	if (A<sizeofArray)
	{
		return 0;
	}
	else { 
		return -1;
	}
}

int NumberArray:: Validate2(int B, int sizeofArray){
	if (B<sizeofArray)
	{
		return 0;
	}
	else {
		return -1;
	}
}


//action time!
int main() {

	int A;
	int B;
	double numb;

	int sizeofArray;	

	cout<<"The size of your array is : "<<endl;
	cin>> sizeofArray;

	NumberArray array[sizeofArray];


	cout<<"Array was created of size " << sizeofArray<<endl;

	for (int x=0; x<sizeofArray; x++)
	{
		cout<<"What value number would you like to add to the array?"<<endl;
		cin>>numb;
	
		cout<<"To which element number: "<<endl;
		cin>> A;
			if (array.Validate1(A)==0){
				array.setNumber(numb, A);
				
			}
			else if(array.Validate1(A)==-1){
				
			cout<<"Invalid. You did not create a big enough array to hold that many elements"<<endl;
				
		}
}


	cout<<"What element of the array would you like to read? " <<endl;
	cin>>B;
	if (array.Validate2(B)==true){
		double Read=array.getNumber(B);
		cout<<"The number is "<<Read<<endl;
		return 0;
	}
	
	else {
		cout<<"Element number was not valid"<<endl;
		return -1;
	}

	double High= array.getHighest(sizeofArray);
	cout<<"Your highest value is "<<High<<endl;

	double Low=array. getLowest(sizeofArray);
	cout<<"Your lowest value is "<<Low<<endl;

	double average= array. getAverage(sizeofArray);
	cout<<"Your average is "<<average<<endl;




	return 0;
}