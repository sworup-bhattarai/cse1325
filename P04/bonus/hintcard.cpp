#include "hintcard.h"
#include "card.h"



Hintcard::Hintcard (std::string question , std::string answer , std::string hint) : _hint(hint) 
{
	Card::Card(question, answer);
}

std::string Hintcard::attempt(std::string responce)
{
	std::string a;
	if (responce == _answer)
	{
	 	return "\nCorrect!\n\n";
	}
	else 
	{
	 	return std::string("\n") + responce + std::string(" is not the correct answer \n\n Hint: ") + _hint + "\n\n";
	 	

