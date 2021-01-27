#include "pet.h"

int main(){
	Pet one{"Charlie", 25 , Type:: IGUANA};
	Pet two{"Blinky", 23 , Type::BAT};
	Pet three{"Bluie", 24 , Type::WHALE};
	Pet four{"Chester", 25 , Type::KOOKABURRA};
	std::cout << one.to_string() << std::endl;
	std::cout << two.to_string() << std::endl;
	std::cout << three.to_string() << std::endl;
	std::cout << four.to_string() << std::endl;
}

