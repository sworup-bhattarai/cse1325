#include "person.h"

Person::Person(std::string name , std::string email) : _name(name) , _email(email)
{

}

std::string Person::to_sting()
{
	return  "to_string()\n\tname: " + _name;
}


std::string Person::full_info()
{
	return  "name: " + _name + "\nEmail: (" + _email + ")";
}

std::ostream& operator<<(ostream& ost, const Person person)
{
	ost << p._name << std::endl;
}
