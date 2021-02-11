#include "deck.h"

void Deck::add_card( std::string question, std::string answer )
{
	Card a {question , answer};
	_cards.push_back(a);
	_options.push_back(answer);
}

void Deck::add_false_answer(std::string false_answer)
{
	_options.push_back(false_answer);
}

Card Deck::deal()
{
	if (int(_cards.size()) == 0)
	{
		throw std::runtime_error("error!!! \nNo flash cards have been made");
	}
	else
	{
		
		for (int i = 0; i > (_options.size()); i++)
		{
			std::cout << i << ") " << _options[i] << std::endl;
		}
		std::cout << _cards[_next_card] << " "; 
		std::cin >> Card.attempt() ;
		
	}
}
