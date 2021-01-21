#include <iostream>


using namespace std;

int main(){
	cout << "Hello World!" << endl;
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
		
	}while(count >= 0); 
	
	
	double total = 0;
	int quarters = 0;
	int dimes = 0;
	int nickles = 0;
	int pennies = 0;
	cin.clear();
	cout << "Please enter the number of quarters you have: " ;
	cin >> quarters;
	
	cin.clear();
	cout << "Please enter the number of dimes you have: " ;
	cin >> dimes;

	cin.clear();
	cout << "Please enter the number of nickles you have: " ;
	cin >> nickles;

	cin.clear();
	cout << "Please enter the number of pennies you have: " ;
	cin >> pennies;
	
	/*while (true) {
		
		try{
			cin >> quarters;
			if (cin.fail())
			{
				throw 1;
			}
			else
			{
				break;
			}
		}
		catch (int err){
			cout << "wrong try again" << endl;
			cin.clear();
			cout << "Please enter the number of quarters you have: " << endl;
			cin >> quarters;
			cout << quarters;
		}						
	}*/
	
	cout << quarters << " " <<  dimes << " " << nickles << " " <<pennies << endl;
	
	total = quarters * .25;
	total += (dimes * .10);
	total += nickles * .05;
	total += pennies * .01;
	cout << "You have a total of $" << total << endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}