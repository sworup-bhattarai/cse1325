#include "pet.h"


std::string to_string(Type pet) 
{
	std::map<Type, std::string> q = {{Type:: IGUANA , "Iguana"},{Type::BAT, "Bat"},{Type::WHALE , "Whale"},{Type::KOOKABURRA , "Kookaburra"}};
	return q[pet];
}

Pet::Pet( std::string n , double a , Type p, int l) : _name{n} , _age{a} , pet{p} , pet_lifespan{l}
{

}

std::string Pet::to_string() 
{
	human_years();
	return _name + " is a " + ::to_string(pet) + " age " + std::to_string(_age) + " or " + std::to_string(_human_equivalent_years) + " in human-equivalent years.\n";
	
}
void Pet::human_years()
{

	_human_equivalent_years  = (_age * 80) / pet_lifespan;
	 
	
}
