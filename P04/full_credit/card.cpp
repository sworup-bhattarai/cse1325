#include "card.h"

Card::Card( std::string question , std::string answer ): _question(question) , _answer(answer) {}


std::string Card::attempt(std::string responce)
{
	std::string a;
	if (responce == _answer)
	{
	 	return "\nCorrect!\n\n";
	}
	else 
	{
	 	return  std::string("\nX - Correct answer is ") + _answer + "\n\n";
	 	
	}
}

std::ostream& operator<<(std::ostream& ost, Card& m)
{
	ost << m._question << std::endl;
	return ost;
}
