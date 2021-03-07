#include "deck.h"

void Deck::add_card( std::string question, std::string answer, std::string hint )
{
	_cards.push_back(new Hintcard(question , answer, hint));
	
	_options.push_back(answer);
}

void Deck::add_false_answer(std::string false_answer)
{
	_options.push_back(false_answer);
}

Card& Deck::deal()
{
	_next_card++;
	return *(_cards[_next_card]);
		
	
}
std::vector<std::string> Deck::options()
{
	std::vector<std::string> v;
	for (int i = 0; i < (_options.size()); i++)
	{
		v.push_back(_options[i]);
	}
	return v;
	
}
