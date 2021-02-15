#include "hintcard.h"

Hintcard::Hintcard (std::string question , std::string answer , std::string hint) : _hint(hint) 
{
	Card::Card(question, answer);
}
