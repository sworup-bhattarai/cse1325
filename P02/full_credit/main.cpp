#include "pet.h"

int main(){
	Pet one{"Charlie", 12 , Type:: IGUANA};
	Pet two{"Blinky", 19 , Type::BAT};
	Pet three{"Bluie", 124 , Type::WHALE};
	Pet four{"Chester", 2 , Type::KOOKABURRA};
	std::cout << one.to_string() << std::endl;
	std::cout << two.to_string() << std::endl;
	std::cout << three.to_string() << std::endl;
	std::cout << four.to_string() << std::endl;
	
}

