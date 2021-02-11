#include "deck.h"
#include "card.h"
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <algorithm>


int main()
{
	/*
	•Object-Oriented Programming (OOP) – A style of programming focused on the use of classes andclass hierarchies
	
	•Inheritance – Reuse and extension of fields and method implementations from another class
	
	•Encapsulation – Bundling data and code into a restricted container
	
	•Abstraction – Specifying a general interface while hiding implementation details (sometimes listed as a4th fundamental concept of OOP, though I believe it's common to most paradigms)
	
	•Primitive type – A data type that can typically be handled directly by the underlying hardware
	
	•Enumerated type – A data type consisting of a fixed set of constant values called enumerators (C++has both enum and enum class)
	
	•Class – A template encapsulating data and code that manipulates it (C++ also has struct, which isidentical other than default visibility)
	
	•Instance – An encapsulated bundle of data and code (e.g., an instance of a program is a process; aninstance of a class is an object)
	
	•Object – An instance of a class containing a set of encapsulated data and associated methods
	
	•Variable – A block of memory associated with a symbolic name that contains an object instance or aprimitive data value
	
	•Operator – A short string representing a mathematical, logical, or machine control action
	
	•Attribute – A class member variable•Constructor – A special class member that creates and initializes an object from the class
	
	•Destructor – A special class member that cleans up when an object is deleted
	
	•Method – A function that manipulates data in a class
	
	•Friend – A class or a function (NOT a method!) that is granted access to its friend class’ privatemembers
	
	•Operator Overloading – Providing a user-defined meaning to a pre-defined operator (e.g., +, ==, <<) fora user-defined type (e.g., a class)
	
	•Getter – A method that returns the value of a private variable
	
	•Setter – A method that changes the value of a private variable
	*/

	std::regex integer{"-?\\d+"};
	std::vector<std::string> vocab; 
	std::vector<std::string> ans;
	std::vector<std::string> false_ans;
	std::vector<Card> ns;
	std::string choice;
	int c;
	
	vocab.push_back("Object-Oriented Programming (OOP)");
	ans.push_back("A style of programming focused on the use of classes andclass hierarchies");
	
	vocab.push_back("Inheritance");
	ans.push_back("Reuse and extension of fields and method implementations from another class");
	
	vocab.push_back("Encapsulation");
	ans.push_back("Bundling data and code into a restricted container");
	
	vocab.push_back("Abstraction");
	ans.push_back("Specifying a general interface while hiding implementation details (sometimes listed as a4th fundamental concept of OOP, though I believe it's common to most paradigms)");
	
	vocab.push_back("Primitive type");
	ans.push_back("A data type that can typically be handled directly by the underlying hardware");
	
	vocab.push_back("Enumerated type");
	ans.push_back("A data type consisting of a fixed set of constant values called enumerators (C++has both enum and enum class)");
	
	vocab.push_back("Class");
	ans.push_back("A template encapsulating data and code that manipulates it (C++ also has struct, which isidentical other than default visibility)");
	
	vocab.push_back("Instance");
	ans.push_back("An encapsulated bundle of data and code (e.g., an instance of a program is a process; aninstance of a class is an object)");
	
	vocab.push_back("Object");
	ans.push_back("An instance of a class containing a set of encapsulated data and associated methods");
	
	vocab.push_back("Variable");
	ans.push_back("A block of memory associated with a symbolic name that contains an object instance or aprimitive data value");
	//10
	false_ans.push_back("Operator");
	//ans.push_back("A short string representing a mathematical, logical, or machine control action");
	
	false_ans.push_back("Attribute");
	//ans.push_back("A class member variable");
	
	false_ans.push_back("Constructor");
	//ans.push_back("A special class member that creates and initializes an object from the class");
	
	false_ans.push_back("Destructor");
	//ans.push_back("A special class member that cleans up when an object is deleted");
	
	false_ans.push_back("Method");
	//ans.push_back("A function that manipulates data in a class");
	
	Deck o_cards;
	for (int i = 0; i < vocab.size(); i++)
	{
		o_cards.add_card(ans[i],vocab[i]);
	}
	for (int i = 0; i < false_ans.size(); i++)
	{
		o_cards.add_false_answer(false_ans[i]);
	}
	false_ans.erase (false_ans.begin(),false_ans.begin());
	false_ans = o_cards.options();
	for(int i = 0; i < ans.size() ; i++)
	{
		ns.push_back(o_cards.deal());
	}

	for (int i = 0; i < ns.size() - 1; i++) {
		int j = i + std::rand() % (ns.size() - i);
		std::swap(ns[i], ns[j]);
	}











	std::cout << "Select the number of the term for each definition (-1 to exit)" << std::endl;
	for (int i = 0; i <= ns.size(); i++)
	{
		std::cout << std::endl;	
		for (int j = 0; j < false_ans.size(); j++)
		{
			std::cout << j <<") " <<false_ans[j]  << std::endl;
		}
		std::cout << "\n" << ns[i];		
	
	while(std::cin>>choice) {
		if(std::regex_match(choice , integer)) 
		{
			c = std::stoi(choice);
			if (c <= -2 || c >= 15)
			{
				std::cout << "***INVALID INPUT***" << std::endl;
			}
			else
				break;
		}	
		else
			std::cout << "***INVALID INPUT***" << std::endl;
		}
	
	c = std::stoi(choice);
	
	if(c == -1)
	{
		std::cout << "***Ending***" << std::endl;
		return 0;
	}
	std::cout << ns[i].attempt(false_ans[c]);
	}	


	/*for (int i = 0; i < ns.size(); i++)
	{
		std::cout << ns[i].attempt("attempt");
	}*/
	
	
	
	
	
	
	
}
