#include "deck.h"
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <algorithm>



int main()
{

	std::regex integer{"-?\\d+"};
	std::vector<std::string> vocab; 
	std::vector<std::string> ans;
	std::vector<std::string> false_ans;
	std::vector<Card> ns;
	std::string choice, k;
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
	ans.push_back("A data type consisting of a fixed set of constant values called enumerators (C++ has both enum and enum class)");
	
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
	
	 vocab.push_back("Friend ");
	 ans.push_back("A class or a function (NOT a method!) that is granted access to its friend class’ private members");
	 vocab.push_back("Operator Overloading ");
	 ans.push_back("Providing a user-defined meaning to a pre-defined operator (e.g., +, ==, <<) for a user-defined type (e.g., a class)");
	 vocab.push_back("Getter ");
	 ans.push_back("A method that returns the value of a private variable");
	 vocab.push_back("Setter ");
	 ans.push_back("A method that changes the value of a private variable");

	 vocab.push_back("Multiple Inheritance ");
	 ans.push_back("A derived class inheriting class members from two or more base classes");
	 vocab.push_back("Base Class ");
	 ans.push_back("The class from which members are inherited");
	 vocab.push_back("Derived Class ");
	 ans.push_back("The class inheriting members");
	 vocab.push_back("Override ");
	 ans.push_back("A derived class replacing its base class’ implementation of a metho");

	 vocab.push_back("Namespace ");
	 ans.push_back("A named scope");
	 vocab.push_back("Declaration ");
	 ans.push_back("A statement that introduces a name with an associated type into a scope");
	 vocab.push_back("Definition ");
	 ans.push_back("A declaration that also fully specifies the entity declared");
	 vocab.push_back("Shadowing† ");
	 ans.push_back("A variable declared in a narrower scope than that of a variable of the same name declared in a broader scope");
	 vocab.push_back("Reference Counter† ");
	 ans.push_back("A managed memory technique that tracks the number of references to allocated memory, so that the memory can be freed when the count reaches zero");
	 vocab.push_back("Garbage Collector† ");
	 ans.push_back("In managed memory systems, program that periodically runs to free unreferenced memory");


	 vocab.push_back("Algorithm ");
	 ans.push_back("A procedure for solving a specific problem, expressed in terms of an ordered set of actions to execute");
	 

	 vocab.push_back("Exception ");
	 ans.push_back("An object created to represent an error or other unusual occurrence and then propagated via special mechanisms until caught by special handling code");
	 vocab.push_back("Assertion† ");
	 ans.push_back("An expression that, if false, indicates a program error (in C++, often via the assert keyword)");
	 vocab.push_back("Invariant† ");
	 ans.push_back("Code for which specified assertions are guaranteed to be true (often, a class in which attributes cannot change after instantiation)");
	 vocab.push_back("Data Validation ");
	 ans.push_back("Ensuring that a program operates on clean, correct and useful data");
	 vocab.push_back("Validation Rules ");
	 ans.push_back("Algorithmically enforceable constraints on the correctness, meaningfulness, and security of input data");


	 vocab.push_back("Version Control† ");
	 ans.push_back("The task of keeping a system consisting of many versions well organized");


	 vocab.push_back("Unified Modeling Language (UML)† ");
	 ans.push_back("The standard visual modeling language used to describe, specify, design, and document the structure and behavior of object-oriented systems");
	 vocab.push_back("Agile Process† ");
	 ans.push_back("Prioritizing individuals and interactions, frequent delivery of working software, customer collaboration, and flexible response to change");
	 vocab.push_back("Waterfall Process† ");
	 ans.push_back("Separating software development into long, discrete phases such as Requirements, Design, Implementation, Verification, and Validation");
	 vocab.push_back("Class Hierarchy ");
	 ans.push_back("Defines the inheritance relationships between a set of classes");
	 vocab.push_back("Class Library ");
	 ans.push_back("A collection of classes designed to be used together efficiently");
	 vocab.push_back("Generalization† ");
	 ans.push_back("The process of extracting shared characteristics from two or more classes, and combining them into a generalized base class.");
	 vocab.push_back("Specialization†");
	 ans.push_back("The process of identifying and specifying derived classes from a base class.");
	 vocab.push_back("Principle of Least Astonishment† ");
	 ans.push_back("A user interface component should behave as the users expect it to behave");
	 vocab.push_back("Second System Effect");
	 ans.push_back("The common mistake of attempting to include far too many features in (typically) version 2.0, causing catastrophic schedule slips");
	
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
		int count = 1;
		for (int i = 0; i < ns.size() ; i++) {
			int j = i + std::rand() % (ns.size() - i);
			std::swap(ns[i], ns[j]);
		}

		std::cout << "Select the number of the term for each definition (-1 at any time to exit)" << std::endl;
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
						std::cout << "------------------------Hit ENTER to continue------------------" <<std::endl;
						while(getline(std::cin , k)) {
							
							if(k == "-1")
							{
							std::cout << "***Ending***" << std::endl;
							return 0;
							}
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
