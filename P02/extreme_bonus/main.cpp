#include "pet.h"

int main(){
	Pet one{"Charlie", 10 , Type::IGUANA, 20};
	Pet two{"Blinky", 23 , Type::BAT, 30};
	Pet three{"Bluie", 80 , Type::WHALE, 200};
	Pet four{"Chester", 15 , Type::KOOKABURRA , 15};
	
	std::cout << one.to_string() << std::endl;
	std::cout << two.to_string() << std::endl;
	std::cout << three.to_string() << std::endl;
	std::cout << four.to_string() << std::endl;
}

