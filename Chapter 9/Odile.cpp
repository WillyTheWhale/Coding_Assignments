#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void Menu();
double gettingInput(struct DrinkMachine Drinks[]);

struct DrinkMachine 
{
string DrinkName;
double DrinkCost;
int DrinkCount;

};

int main()
{

bool start= true;
const int NUM_DRINKS=5;
DrinkMachine Drinks[NUM_DRINKS]= 
{
{"Cola",0.75,20},
{"Root-Beer",0.75,20},
{"Lemon-Lime", 0.75, 20},
{"Grape Soda", 0.80,20},
{"Cream Soda", 0.80,20},

};

while (start==true)
{
Menu(); 
gettingInput( struct DrinkMachine Drinks[]);

}


}

 

//displaying the menu
void Menu ()
{


cout<<"The Menu"<<endl;
cout<<"Drink Name"<<setw(5)<<"Cost"<<setw(5)<<"# in Machine"<<endl;
cout<<"Cola"<<setw(5)<<"$0.75"<<setw(5)<<"20"<<endl;
cout<<"Root-Beer"<<setw(5)<<"$0.75"<<setw(5)<<"20"<<endl;
cout<<"Lemon-Lime"<<setw(5)<<"$0.75"<<setw(5)<<"20"<<endl;
cout<<"Grape Soda "<<setw(5)<<"$0.80"<<setw(5)<<"20"<<endl;
cout<<"Cream Soda (F)"<<setw(5)<<"$0.80"<<setw(5)<<"20"<<endl;
}

// Analyzing customers' desires
double gettingInput(struct DrinkMachine Drinks[]) {
double payment1;
char drink1;
double total=0;


cout<<"Type in the first letter of the drink you want or Q for Quit. For Cream Soda, click on F."<<endl;
cin>>drink1;
cout<<"How much are you putting in?"<<endl;
cin>>payment1;

while (drink1!='Q') {
// if payment is less than drink cost, return back to menu.
if (payment1< Drinks.DrinkCost){
cout<<payment1<<" is not enough"<<endl;
Menu();
}
//Returns change
if (drink1=='C' || drink1=='c') {
double change1;
change1= payment1-0.75;
Drinks.DrinkCount[0]--; //subtracts 1 from total quantity of drink
total= total +0.75;
cout<<"Your returned change is: "<<change1<<endl;
}

if (drink1=='R' || drink1== 'r') {
double change2;
change2= payment1-0.75;
total=total+0.75;
Drinks.DrinkCount[1]--; //subtracts 1 from total quantity of drink
cout<<"Your returned change is: "<<change2<<endl;
}

if (drink1== 'L' || drink1== 'l' ) {
double change3;
change3= payment1-0.75;
total = total+ 0.75;
Drinks.DrinkCount[2]--; //subtracts 1 from total quantity of drink
cout<<"Your returned change is: "<<change3<<endl;
}

if (drink1== 'G' || drink1== 'g' ) {
double change4;
change4= payment1-0.80;
total = total+0.80;
Drinks.DrinkCount[3]--; //subtracts 1 from total quantity of drink
cout<<"Your returned change is: "<<change4<<endl;
}

if (drink1== 'F' || drink1== 'f' ){
double change5;
change5= payment1-0.80;
total = total + 0.80;
Drinks.DrinkCount[4]--; //subtracts 1 from total quantity of drink
cout<<"Your returned change is: "<<change5<<endl;
}

//if user selects a drink that has sold out, a message should be displayed
if (Drinks.DrinkCount ==0){
cout<<"You have selected a sold-out drink, please try again"<<endl;
Menu();
}

}
//displays total earnings

if (drink1== 'Q') {
cout<<"The total amount of $ the machine is :"<< total<<endl;
cout<<"goodbye"<<endl;
}

 

return 0.00;

}