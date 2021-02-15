#ifndef __DECK_H
#define __DECK_H

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>
#include <vector>
#include "card.h"
#include "hintcard.h"


class Deck{
	public:
		void add_card( std::string question, std::string answer );
		void add_false_answer(std::string false_answer);
		Card deal();
		std::vector<std::string> options();
	private:
		std::vector<Card> _cards;
		std::vector<std::string> _options;
		int _next_card = -1;

};
#endif
