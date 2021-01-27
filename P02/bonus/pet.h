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
	int pet_lifespan;
	double _human_equivalent_years;
  public:
	Pet(std::string _name , double _age , Type p, int pet_lifespan );
	void human_years();
	std::string to_string();

};

#endif

