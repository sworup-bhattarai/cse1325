#ifndef __PET_H
#define __PET_H


#include <iostream>
#include <vector>
#include <map>

enum class Type {IGUANA, BAT, WHALE, KOOKABURRA};
std::string to_string(Type pet);

class Pet {
	double _age;
	Type pet;
	std::string _name;
	int _pet_lifespan;
	std::vector<int> v = {20,30,200,15};
	double _human_equivalent_years;
  public:
	Pet(std::string _name , double _age , Type p, int pet_lifespan );
	int human_years();
	std::string to_string();

};

#endif

