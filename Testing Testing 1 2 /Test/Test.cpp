#include <iostream>
#include <iomanip>



int checkTypeMenu();

int openMenu(){
	int pick;
	
	std::cout << "Please type the number corresponding with what you would like to do: \n\n" << "1) Deposit Money \n2) Donate All My Money \n3) Check Balence \n4) EXIT \n" << std::endl;
	std::cout << "----------------------------------------\n" << std::endl;
	pick = checkTypeMenu();
	return pick;
	
	return 0;
}


int checkTypeMenu() {
	double quantity;		
	int qcheck;
	
	while (true) {
		
			
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
		//checks to see if what was entered is a number or not
		if(std::cin >> quantity) 
		{
			qcheck = quantity;
			//checks to makesure the number is not negative 
			if (quantity < 0 || quantity > 4)
			{
				std::cout << "Enter a number from 1-4\n" << std::endl;
				std::cin.clear(); // clear the fail state
				std::cin.ignore(99999,'\n'); // clear the buffer
			}
			else if (qcheck != quantity)
			{
				std::cout << "Enter Please enter whole numbers\n" << std::endl;
				std::cin.clear(); // clear the fail state
				std::cin.ignore(99999,'\n'); // clear the buffer
			}
			else
			{
			std::cin.clear(); // clear the fail state
			std::cin.ignore(99999,'\n'); // clear the buffer	
			return (int) quantity;
			}
		}
		
		//no idea what this even is 
		else if (std::cin.eof() || std::cin.bad()) // fatal states, e.g., control-d
		{
			std::cerr << "BAD DON'T DO THAT!!!!" << "\nInput terminated. Aborted." << std::endl;
			exit(-1);
		}
		else if (std::cin.fail())  //catches chars 
		{
			std::cin.clear(); // clear the fail state
			std::cin.ignore(99999,'\n'); // clear the buffer
			std::cout << "Enter number not letters" << std::endl;

		}
		else 
		{
			return quantity;
		}


	}	

	
	
}


//Inputs and checks if the value entered is an int or not and returns it to be calculated 
int checkTypeCash(std::string currency) {
	double quantity;
	int qcheck;
	
	while (true) {
		std::cout << "\nPlease enter the number of "<< currency << " you have : " ;
		
		//checks to see if what was entered is a number or not
		if(std::cin >> quantity) 
		{
			qcheck = quantity;
			//checks to makesure the number is not negative 
			if (quantity < 0 )
			{
				std::cout << "Enter a number grater than 0\n" << std::endl;
			}
			else if (quantity > 100 )
			{
				std::cout << "Please enter a more believable quantity" << std::endl;
			}
			else if (qcheck != quantity)
			{
				std::cout << "Enter Please enter whole numbers\n" << std::endl;
			}
			else
			{
			return (int) quantity;
			}
		}
		
		//no idea what this even is 
		else if (std::cin.eof() || std::cin.bad()) // fatal states, e.g., control-d
		{
			std::cerr << "BAD DON'T DO THAT!!!!" << "\nInput terminated. Aborted." << std::endl;
			exit(-1);
		}
		else if (std::cin.fail())  //catches chars 
		{
			std::cin.clear(); // clear the fail state
			std::cin.ignore(99999,'\n'); // clear the buffer
			std::cout << "Enter number not letters" << std::endl;

		}
		else 
		{
			return quantity;
		}


	}		
}

double total () {

	
	//gets input for the ammount of bills/coins and checks to see if input type is correct then adds the ammount to  the total
	int hundreds = checkTypeCash("$100 bills");
	double total = hundreds * 100;
	
	int twenties = checkTypeCash("$20 bills");
	total += twenties * 20;
	
	int tens = checkTypeCash("$10 bills ");
	total += tens * 10;
	
	int fives = checkTypeCash("$5 bills");
	total += fives * 5;
	
	int dollars = checkTypeCash("$1 bills");
	total += dollars * 1;
	
	int quarters = checkTypeCash("quarters");
	total += quarters * .25;
	
	int dimes = checkTypeCash("dimes");
	total += dimes * .10;
	
	int nickles = checkTypeCash("nickles");
	total += nickles * .05;
	
	int pennies = checkTypeCash("pennies");
	total += pennies * .01;
	
	
	std::cout << "\nYou are depositing: $" << std::setprecision(2) << std::fixed << total << "\n" <<std::endl;
	return total;
}




int main(){
	
	double totalMoney = 452.30;
	int menuChoice;
	
	std::cout << "HELLO AND WELCOME TO THE BUGGY BANK" << std::endl;
	std::cout << "Where we can guarentee that you will loose your money to some kind of bug or another!\n" << std::endl;
	
	while (true){
		
		menuChoice = openMenu();
		if (menuChoice == 1){
			totalMoney += total();
			std::cout << "You have a total of $" << std::setprecision(2) << std::fixed << totalMoney << "\n\n"<< std::endl;
		}
		else if (menuChoice == 2){
			if (totalMoney == 0){
				std::cout << "\nYou're flat broke! \nNo money at all \n$" << totalMoney << std::endl;
			}
			else{
				std::cout << "\nYou have $" << std::setprecision(2) << std::fixed << totalMoney << " in your account" << std::endl;
			}
		}
		else if (menuChoice == 3){
			totalMoney = 0; //removes all the money from the bank
			std::cout << "\nThank you for Donating all of your money! \n\nYou have $" << std::setprecision(2) << std::fixed << totalMoney << " left." << std::endl;
		}
		else if (menuChoice == 4){
			std::cout << "\nThank you for your patronage have a good day!!" << std::endl;
			break;
		}
	}
	
	
	return 0;
	
}