#include "pet.h"

int main(){
	Pet one{"Charlie", 25 , IGUANA};
	Pet two{"Blinky", 23 , BAT};
	Pet three{"Bluie", 24 , WHALE};
	Pet four{"Chester", 25 , KOOKABURRA};
	std::cout << one.to_string() << std::endl;
	std::cout << two.to_string() << std::endl;
	std::cout << three.to_string() << std::endl;
	std::cout << four.to_string() << std::endl;
}

