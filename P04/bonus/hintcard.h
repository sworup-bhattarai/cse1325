#ifndef __HINTCARD_H
#define __HINTCARD_H

#include "card.h"
#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>


class Hintcard : public Card
{
	public:
		Hintcard(std::string question , std::string answer , std::string hint);
		std::string attempt(std::string responce) override;
	private:
		std::string _hint;

};
#endif
