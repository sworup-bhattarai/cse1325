#include "pet.h"
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

int checkType() {
	double quantity;		
	int qcheck;
	while (true) {

		//checks to see if what was entered is a number or not
		if(std::cin >> quantity) 
		{
			qcheck = quantity;
			//checks to makesure the number is not negative 
			if (quantity < 0 || quantity > 400)
			{
				std::cout << "Ya there's no way your pet is that old try again.\nEnter it's age:" << std::endl;
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
			return (int) quantity;
			}
		}
		
		//no idea what this even is 
		else if (std::cin.eof() || std::cin.bad()) // fatal states, e.g., control-d
		{
			std::cerr << "\nBAD DON'T DO THAT!!!!" << "\nInput terminated. Aborted.\n" << std::endl;
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

int main(){
	
	std::vector<double> v;
	std::vector<Pet> q ;
	double o, t, h, f ;
	double age;
	std::string name;
	
	
	
	std::cout << ("Please enter the name of your Greenland Shark: ");
	std::getline(std::cin , name);
	std::cout << ("Please enter the age of your Greenland Shark: ");
	age = checkType();
	q.push_back(Pet{name , age , Type::SHARK});
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Bat: ");
	std::getline(std::cin , name); 
	std::cout << ("Please enter the age of your Bat: ");
	age = checkType();
	q.push_back(Pet{name , age , Type::BAT});
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Whale: ");
	std::getline(std::cin , name);
	std::cout << ("Please enter the age of your Whale: ");
	age = checkType();
	q.push_back(Pet{name , age , Type::WHALE});
	std::cin.ignore(99999,'\n'); // clear the buffer
	std::cout << ("Please enter the name of your Kookaburra: ");
	std::getline(std::cin , name);	
	std::cout << ("Please enter the age of your Kookaburra: ");
	age = checkType();
	q.push_back(Pet{name , age , Type::KOOKABURRA});
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	
	
	o = q[0].human_years() + .1;    //literly_the_WORST_way_of_doing_this.exe  
	v.push_back(o);   		//adds age to array
	t = q[1].human_years() + .2;
	v.push_back(t);
	h = q[2].human_years() + .3;
	v.push_back(h);
	f = q[3].human_years() + .4;
	v.push_back(f);
	std::sort(v.begin(), v.end()); //sorts array
	for (int i = 0; i < v.size(); i++){

		if (v[i] == o){	//checks if value of array is the same as age
        		std::cout << q[0].to_string() << std::endl;	
        	}
      		else if (v[i] == t){
        		std::cout << q[1].to_string() << std::endl;
        	}
        	else if (v[i] == h){ 
        		std::cout << q[2].to_string() << std::endl;
		}
		else if (v[i] == f){
			std::cout << q[3].to_string() << std::endl;
		}
		
	}
}

