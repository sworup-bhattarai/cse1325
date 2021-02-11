#ifndef __CARD_H
#define __CARD_H

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>

class Card{
	public:
		Card( std::string question , std::string answer );
		std::string attempt (std::string responce);
		friend std::ostream& operator<<(std::ostream& ost, Card& m);
	private:
		std::string _question;
		std::string _answer;
};
#endif
