#include <iostream>
using namespace std;



//Inputs and checks if the value entered is an int or not and returns it to be calculated 
int checkType(string currency) {
	double quantity;
	int qcheck;
	
	while (true) {
		cout << "Please enter the number of "<< currency << " you have: " ;
		
		//checks to see if what was entered is a number or not
		if(cin >> quantity) 
		{
			qcheck = quantity;
			//checks to makesure the number is not negative 
			if (quantity < 0 )
			{
				cout << "Enter a number grater than 0\n" << endl;
			}
			else if (qcheck != quantity)
			{
				cout << "Enter Please enter whole numbers\n" << endl;
			}
			else
			{
			return (int) quantity;
			}
		}
		
		//no idea what this even is 
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
		
	
	/*double total = 0;
	int dollars = 0;
	int fives = 0;
	int tens = 0;
	int twenties = 0;
	int hundreds = 0;
	int quarters = 0;
	int dimes = 0;
	int nickles = 0;
	int pennies = 0;*/
	
	//gets input for the ammount of bills/coins and checks to see if input type is correct then adds the ammount to  the total
	int hundreds = checkType("$100 bills");
	double total = hundreds * 100;
	
	int twenties = checkType("$20 bills");
	total += twenties * 20;
	
	int tens = checkType("$10 bills ");
	total += tens * 10;
	
	int fives = checkType("$5 bills");
	total += fives * 5;
	
	int dollars = checkType("$1 bills");
	total += dollars * 1;
	
	int quarters = checkType("quarters");
	total += quarters * .25;
	
	int dimes = checkType("dimes");
	total += dimes * .10;
	
	int nickles = checkType("nickles");
	total += nickles * .05;
	
	int pennies = checkType("pennies");
	total += pennies * .01;
	
	
	cout << "You have a total of $" << total << endl;
	//cout << pennies << nickles << dimes << quarters  << hundreds  << twenties <<tens << fives << dollars << endl;
	return 0;
	
}