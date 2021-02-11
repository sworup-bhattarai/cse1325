#include "deck.h"
#include "card.h"
#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>
#include <vector>

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


	std::vector<std::string> vocab; 
	std::vector<std::string> ans;
	std::vector<Card> ns;
	
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
	ans.push_back(" A block of memory associated with a symbolic name that contains an object instance or aprimitive data value");
	
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
	
	std::string a , b;
	Deck o_cards;
	for (int i = 0; i < vocab.size(); i++)
	{
		a = ans[i];
		b = vocab[i];
		o_cards.add_card(a,b);
	}
	
	ns.push_back(o_cards.deal());
	ns.push_back(o_cards.deal());
	ns.push_back(o_cards.deal());
	ns.push_back(o_cards.deal());
	for (int i = 0; i < ns.size(); i++)
	{
		std::cout << ns[i].attempt("attempt");
	}
	
	
	
	
	
	
	
}
