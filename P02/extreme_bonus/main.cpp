#include "pet.h"
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

int main(){
	
	std::vector<int> v;
	int o, t, h, f ;
	double age;
	std::string name;
	
	
	
	std::cout << ("Please enter the name of your Iguana: ");
	std::getline(std::cin , name);
	std::cout << ("Please enter the age of your Iguana: ");
	std::cin >> age;
	Pet one{name , age , Type::IGUANA};
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Bat: ");
	std::getline(std::cin , name); 
	std::cout << ("Please enter the age of your Bat: ");
	std::cin >> age;
	Pet two{name , age , Type::BAT};
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Whale: ");
	std::getline(std::cin , name);
	std::cout << ("Please enter the age of your Whale: ");
	std::cin >> age;
	Pet three{name , age , Type::WHALE};
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	std::cout << ("Please enter the name of your Kookaburra: ");
	std::getline(std::cin , name);	
	std::cout << ("Please enter the age of your Kookaburra: ");
	std::cin >> age;
	Pet four{name , age , Type::KOOKABURRA };
	std::cin.ignore(99999,'\n'); // clear the buffer
	
	
	
	o = one.human_years() + .001;     //literly the WORST way of doing this  
	v.push_back(o);  		//adds age to array
	t = two.human_years() + .002;
	v.push_back(t);
	h = three.human_years() + .003;
	v.push_back(h);
	f = four.human_years() + .004;
	v.push_back(f);
	std::sort(v.begin(), v.end()); //sorts array
	for (int i = 0; i < v.size(); i++){
		if (v[i] == o){	//checks if value of array is the same as age
        		std::cout << one.to_string() << std::endl;	
        	}
      		else if (v[i] == t){
        		std::cout << two.to_string() << std::endl;
        	}
        	else if (v[i] == h){ 
        		std::cout << three.to_string() << std::endl;
		}
		else if (v[i] == f){
			std::cout << four.to_string() << std::endl;
		}
		
	}
}

