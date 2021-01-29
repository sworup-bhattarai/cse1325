#include "pet.h"


std::string to_string(Type pet) 
{
	std::map <Type, std::string> q = {{Type:: IGUANA , "Iguana"},{Type::BAT, "Bat"},{Type::WHALE , "Whale"},{Type::KOOKABURRA , "Kookaburra"}};
	return q[pet];
}

Pet::Pet( std::string n , double a , Type p, int l) : _name{n} , _age{a} , pet{p} /*, _pet_lifespan{l}*/
{
	
	if (::to_string(pet) == "Iguana"){
		_pet_lifespan = v[0];
		human_years();	
	}
	else if (::to_string(pet) == "Bat"){
		_pet_lifespan = v[1];
		human_years();	
	}
	else if (::to_string(pet) == "Whale"){
		_pet_lifespan = v[2];
		human_years();	
	}
	else if (::to_string(pet) == "Kookaburra"){
		_pet_lifespan = v[3];
		human_years();	
	}
	
}

std::string Pet::to_string() 
{
	
	return _name + " is a " + ::to_string(pet) + " age " + std::to_string(_age) + " or " + std::to_string(_human_equivalent_years) + " in human-equivalent years.\n";
	
}
int Pet::human_years()
{

	return _human_equivalent_years  = (_age * 80) / _pet_lifespan;
	 
	
}
