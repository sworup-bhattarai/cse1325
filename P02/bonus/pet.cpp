#include "pet.h"


std::string to_string(Type pet) 
{
	std::map <Type, std::string> q = {{Type:: IGUANA , "Iguana"},{Type::BAT, "Bat"},{Type::WHALE , "Whale"},{Type::KOOKABURRA , "Kookaburra"}};
	return q[pet];
}

Pet::Pet( std::string n , double a , Type p) : _name{n} , _age{a} , pet{p} 
{
		
	while (true) {
		if (::to_string(pet) == _t[_count]){
			_pet_lifespan = _v[_count];
			human_years();
			break;
		}
		else if (_count < 4){
			_count ++;
		}
		else{
		std::cerr << "Something went worng " << std::endl;
		break;
		}
	}
	

}

std::string Pet::to_string() 
{
	
	return _name + " is a " + ::to_string(pet) + " age " + std::to_string(_age) + " or " + std::to_string(_human_equivalent_years) + " in human-equivalent years.\n";
	
}
void Pet::human_years()
{

	 _human_equivalent_years  = (_age * 80) / _pet_lifespan;
	 
	
}
