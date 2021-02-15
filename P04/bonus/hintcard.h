#ifndef __HINTCARD_H
#define __HINTCARD_H

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>

class Hintcard {
	public:
		Hintcard(std::string question , std::string answer , std::string hint);
		std::string attempt(std::string recponce);
	private:
		std::string _hint;

};
#endif
