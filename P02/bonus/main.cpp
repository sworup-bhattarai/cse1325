#include "pet.h"

int main(){
	Pet one{"Charlie", 10 , IGUANA, 20};
	Pet two{"Blinky", 23 , BAT, 30};
	Pet three{"Bluie", 80 , WHALE, 200};
	Pet four{"Chester", 15 , KOOKABURRA , 15};
	one.human_years();
	two.human_years();
	three.human_years();
	four.human_years();
	std::cout << one.to_string() << std::endl;
	std::cout << two.to_string() << std::endl;
	std::cout << three.to_string() << std::endl;
	std::cout << four.to_string() << std::endl;
}

