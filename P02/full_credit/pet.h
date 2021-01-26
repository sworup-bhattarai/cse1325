#ifndef __PET_H
#define __PET_H


#include <iostream>
#include <vector>
#include <map>

enum Type {IGUANA, BAT, WHALE, KOOKABURRA};
std::string to_string(Type pet);

class Pet {
	double _age;
	Type pet;
	std::string _name;
  public:
	Pet(std::string _name , double _age , Type p);
	std::string to_string();

};

#endif

