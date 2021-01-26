#include "pet.h"


std::string to_string(Type pet) 
{
	std::vector<std::string> q = {"Iguana", "Bat", "Whale", "Kookaburra"};
	return q[pet];
}

Pet::Pet( std::string n , double a , Type p) : _name{n} , _age{a} , pet{p} 
{

}

std::string Pet::to_string() 
{
	return _name + " is a " + ::to_string(pet) + " age " + std::to_string(_age);	
}
