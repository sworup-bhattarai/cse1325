#include "deck.h"

void Deck::add_card( std::string question, std::string answer )
{
	Card a {question , answer};
	_cards.push_back(a);
	_options.push_back(answer);
}

void Deck::add_false_answer(std::string false_answer){_options.push_back(false_answer);}

Card Deck::deal()
{
	_next_card++;
	return _cards[_next_card];


}
std::vector<std::string> Deck::options(){return _options;}
