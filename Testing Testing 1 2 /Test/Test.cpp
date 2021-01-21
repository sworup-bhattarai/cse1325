#include <iostream>
using namespace std;



//Inputs and checks if the value entered is an int or not and returns it to be calculated 
int checkType(string currency) {
	int quantity;
	
	
	while (true) {
		cout << "Please enter the number of "<< currency << " you have: " ;

		if(cin >> quantity) 
		{
			if (quantity < 0 )
			{
				cout << "Enter a number grater than 0" << endl;
			}
			else
			{
			return quantity;
			}
		}
		else if (cin.eof() || cin.bad()) // fatal states, e.g., control-d
		{
			cerr << "BAD DON'T DO THAT!!!!" << "\nInput terminated. Aborted." << endl;
			exit(-1);
		}
		else if (cin.fail())  //catches chars 
		{
			cin.clear(); // clear the fail state
			cin.ignore(99999,'\n'); // clear the buffer
			cout << "Enter number not letters" << endl;

		}
		else 
		{
			return quantity;
		}


	}	

	
	
}


int main(){
		
	
	double total = 0;
	int dollars = 0;
	int fives = 0;
	int tens = 0;
	int twenties = 0;
	int hundreds = 0;
	int quarters = 0;
	int dimes = 0;
	int nickles = 0;
	int pennies = 0;
	
	//gets input for the ammount of bills/coins and checks to see if input type is correct 
	hundreds = checkType("$100 bills");
	total = hundreds * 100;
	
	twenties = checkType("$20 bills");
	total += twenties * 20;
	
	tens = checkType("$10 bills ");
	total += tens * 10;
	
	fives = checkType("$5 bills");
	total += fives * 5;
	
	dollars = checkType("$1 bills");
	total += dollars * 1;
	
	quarters = checkType("quarters");
	total += quarters * .25;
	
	dimes = checkType("dimes");
	total += dimes * .10;
	
	nickles = checkType("nickles");
	total += nickles * .05;
	
	pennies = checkType("pennies");
	total += pennies * .01;
	cout << "You have a total of $" << total << endl;
	//cout << pennies << nickles << dimes << quarters  << hundreds  << twenties <<tens << fives << dollars << endl;
	
	
}