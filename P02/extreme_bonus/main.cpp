#include "pet.h"
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

int main(){
	
	std::vector<double> v;
	std::vector<Pet> q ;
	double o, t, h, f ;
	double age;
	std::string name;
	
	
	
	std::cout << ("Please enter the name of your Iguana: ");
	std::getline(std::cin , name);
	std::cout << ("Please enter the age of your Iguana: ");
	std::cin >> age;
	q.push_back(Pet{name , age , Type::IGUANA});
	//Pet one{name , age , Type::IGUANA};
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Bat: ");
	std::getline(std::cin , name); 
	std::cout << ("Please enter the age of your Bat: ");
	std::cin >> age;
	q.push_back(Pet{name , age , Type::BAT});
	//Pet two{name , age , Type::BAT};
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Whale: ");
	std::getline(std::cin , name);
	std::cout << ("Please enter the age of your Whale: ");
	std::cin >> age;
	q.push_back(Pet{name , age , Type::WHALE});
	//Pet three{name , age , Type::WHALE};
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Kookaburra: ");
	std::getline(std::cin , name);	
	std::cout << ("Please enter the age of your Kookaburra: ");
	std::cin >> age;
	q.push_back(Pet{name , age , Type::KOOKABURRA});
	//Pet four{name , age , Type::KOOKABURRA };
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

