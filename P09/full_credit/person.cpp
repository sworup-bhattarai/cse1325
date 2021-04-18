#include "person.h"


Person::Person(std::string name , std::string email) : _name(name) , _email(email)
{

}

std::string Person::to_string() const
{
	return  _name;
}


std::string Person::full_info() const
{
	return  "name: " + _name + "\nEmail: (" + _email + ")";
}

std::ostream& operator<<(std::ostream& ost, const Person person)
{
	ost << person._name;
	return ost;
}
