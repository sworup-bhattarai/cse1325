#ifndef __PET_H
#define __PET_H


#include <iostream>
#include <vector>
#include <map>

enum class Type {IGUANA, BAT, WHALE, KOOKABURRA};
std::string to_string(Type pet);

class Pet {
	double _age;
	int _count = 0 ;
	Type pet;
	std::string _name;
	int _pet_lifespan;
	std::vector<int> _v = {20,30,200,15};
	std::vector<std::string>  _t = { "Iguana" , "Bat" , "Whale" , "Kookaburra"};
	double _human_equivalent_years;
  public:
	Pet(std::string _name , double _age , Type p );
	void human_years();
	std::string to_string();

};

#endif

