#include "pet.h"
#include <vector>
#include <bits/stdc++.h>

int main(){
	
	std::vector<int> v;
	int o, t, h, f;
	Pet one{"Charlie" , 12 , Type::IGUANA, 20};
	Pet two{"Blinky" , 30 , Type::BAT, 30};
	Pet three{"Bluie" , 150 , Type::WHALE, 200};
	Pet four{"Chester" , 5 , Type::KOOKABURRA , 15};
	o = one.human_years();  
	v.push_back(o);  		//adds age to array
	t = two.human_years();
	v.push_back(t);
	h = three.human_years();
	v.push_back(h);
	f = four.human_years();
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

