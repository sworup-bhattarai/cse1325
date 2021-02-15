#include "deck.h"
#include "card.h"
#include "hintcard.h"
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <algorithm>
#include <thread>         
#include <chrono>


int main()
{

	std::regex integer{"-?\\d+"};
	std::vector<std::string> vocab; 
	std::vector<std::string> ans;
	std::vector<std::string> false_ans;
	std::vector<Card> ns;
	std::string choice;
	int c;
	
	vocab.push_back("Object-Oriented Programming (OOP)");
	ans.push_back("A style of programming focused on the use of classes and class hierarchies");
	
	vocab.push_back("Inheritance");
	ans.push_back("Reuse and extension of fields and method implementations from another class");
	
	vocab.push_back("Encapsulation");
	ans.push_back("Bundling data and code into a restricted container");
	
	vocab.push_back("Abstraction");
	ans.push_back("Specifying a general interface while hiding implementation details (sometimes listed as a 4th fundamental concept of OOP, though I believe it's common to most paradigms)");
	
	vocab.push_back("Primitive type");
	ans.push_back("A data type that can typically be handled directly by the underlying hardware");
	
	vocab.push_back("Enumerated type");
	ans.push_back("A data type consisting of a fixed set of constant values called enumerators (C++ 4has both enum and enum class)");
	
	vocab.push_back("Class");
	ans.push_back("A template encapsulating data and code that manipulates it (C++ also has struct, which isidentical other than default visibility)");
	
	vocab.push_back("Instance");
	ans.push_back("An encapsulated bundle of data and code (e.g., an instance of a program is a process; aninstance of a class is an object)");
	
	vocab.push_back("Object");
	ans.push_back("An instance of a class containing a set of encapsulated data and associated methods");
	
	vocab.push_back("Variable");
	ans.push_back("A block of memory associated with a symbolic name that contains an object instance or aprimitive data value");
	//10
	vocab.push_back("Operator");
	ans.push_back("A short string representing a mathematical, logical, or machine control action");
	
	vocab.push_back("Attribute");
	ans.push_back("A class member variable");
	
	vocab.push_back("Constructor");
	ans.push_back("A special class member that creates and initializes an object from the class");
	
	vocab.push_back("Destructor");
	ans.push_back("A special class member that cleans up when an object is deleted");
	
	vocab.push_back("Method");
	ans.push_back("A function that manipulates data in a class");
	
	false_ans.push_back("Vector");
	false_ans.push_back("Map");
	false_ans.push_back("iostream");
	false_ans.push_back("C++");
	false_ans.push_back("std::cout");
	
	Deck o_cards;
	for (int i = 0; i < vocab.size(); i++)
	{
		o_cards.add_card(ans[i],vocab[i]);
	}
	for (int i = 0; i < false_ans.size(); i++)
	{
		o_cards.add_false_answer(false_ans[i]);
	}
	
	false_ans.erase (false_ans.begin(),false_ans.begin()); // empties false_ans vector 
	false_ans = o_cards.options();			 // adds the option choice into false_ans vectorz
	
	for(int i = 0; i < ans.size() ; i++)       //creats all the cards
	{
		ns.push_back(o_cards.deal());
	}


	while (true)  // goes through the cards 
	{
		for (int i = 0; i < ns.size() ; i++) {
			int j = i + std::rand() % (ns.size() - i);
			std::swap(ns[i], ns[j]);
		}

		std::cout << "Select the number of the term for each definition (-1 to exit)" << std::endl;
		for (int i = 0; i < ns.size(); i++)
		{
			std::cout << std::endl;	
			for (int j = 0; j < false_ans.size(); j++)
			{
				std::cout << j <<") " << false_ans[j]  << std::endl;
			}
		std::cout << "\n" << ns[i];
		
		if (std::cin.eof() || std::cin.bad()) // fatal states
		{
			std::cerr << "BAD DON'T DO THAT!!!!" << "\nInput terminated. Aborted." << std::endl;
			exit(-1);
		}
		
		while(getline(std::cin , choice)) {
			
			if(std::regex_match(choice , integer)) // int check
			{
				c = std::stoi(choice);
				int p = false_ans.size();
				if (c <= -2 || c >= p )  // int value check
				{
					std::cout << "***INVALID INPUT PLEASE ENTER A NUMBER BETWEEN -1 AND " << p - 1 << "***"<< std::endl;
				}
				else
				{
					c = std::stoi(choice);
		
					if(c == -1)
					{
						std::cout << "***Ending***" << std::endl;
						return 0;
					}
					std::cout << ns[i].attempt(false_ans[c]); //checks answer
					std::cout << "------------------------Hit enter to continue------------------" <<std::endl;
					while(getline(std::cin , choice)) {
						break;
					}
					
					break;
				}	

				
			}	
			else 
				std::cout << "***INVALID INPUT PLEASE ENTER A NUMBER***" << std::endl;
			}
		

		
		}
	
	}
	
	
}
