#include "pet.h"


std::string to_string(Type pet) 
{
	std::map <Type, std::string> q = {{Type:: IGUANA , "Iguana"},{Type::BAT, "Bat"},{Type::WHALE , "Whale"},{Type::KOOKABURRA , "Kookaburra"}};
	return q[pet];
}

Pet::Pet( std::string n , double a , Type p) : _name{n} , _age{a} , pet{p} 
{
	/*if (::to_string(pet) == "Iguana"){
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
	}*/
	
	
	
	/*if (::to_string(pet) == _t[0]){
		_pet_lifespan = _v[0];
		human_years();	
	}
	else if (::to_string(pet) == _t[1]){
		_pet_lifespan = _v[1];
		human_years();	
	}
	else if (::to_string(pet) == _t[2]){
		_pet_lifespan = _v[2];
		human_years();	
	}
	else if (::to_string(pet) == _t[3]){
		_pet_lifespan = _v[3];
		human_years();	
	}*/
	
	
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
int Pet::human_years()
{

	return _human_equivalent_years  = (_age * 80) / _pet_lifespan;
	 
	
}
