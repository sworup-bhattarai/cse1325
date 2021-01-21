#include <iostream>
using namespace std;



//Inputs and checks if the value entered is an int or now and returns it to be calculated 
int checkType(string currency) {
	int quantity;
	cout << "Please enter the number of "<< currency << " you have: " ;
	cin >> quantity;	
	
	while (true) {
		
		
		try{
			if (cin.fail())  //catches chars 
			{
				cin.clear(); // clear the fail state
				cin.ignore(32767,'\n'); // clear the buffer
				throw 1;
			}
			else
			{
				return quantity;
			}
		}
		catch (int err){
			cout << "wrong try again" << endl;
			cout << "Please enter the number of "<< currency << " you have: " ;
			cin >> quantity;
			
		}	
		
	}
	return quantity;
}


int main(){
	
	/*cout << "Hello World!" << endl;
	string s;
	s = "#";
	
	//for loop 
	for (int i = 1; i <= 6 ; i ++){
	
		cout << i << " " << s << endl;
		s += "#";
	}
	int count = 1;
	
	//while loop
	while (count <= 12){
		cout << "Count still not 12 yet. It is currently: " << count << endl;
		count++;
	}
	
	//do while loop
	do{
		if (count != 0){
			cout << "Count still not 0 yet. It is currently: " << count << endl;
			count--;
		} else {
			cout << "Count is now: " << count << endl;
			count--;
		}
		
	}while(count >= 0); */
	
	
	double total = 0;
	int quarters = 0;
	int dimes = 0;
	int nickles = 0;
	int pennies = 0;
	
	quarters = checkType("quarters");
	total = quarters * .25;
	
	dimes = checkType("dimes");
	total += dimes * .10;
	
	nickles = checkType("nickles");
	total += nickles * .05;
	
	pennies = checkType("pennies");
	total += pennies * .01;
	cout << "You have a total of $" << total << endl;
	
	
}