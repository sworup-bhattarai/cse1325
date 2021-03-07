#include "person.h"

Person::Person(std::string name , std::string email) : this->name(name) , this->email(email)
{

}

std::string Person::to_sting()
{
	return  "to_string()\n\tname: " + name;
}


std::string Person::full_info()
{
	return  "name: " + name + "\nEmail: (" + email + ")";
}

std::ostream& operator<<(ostream& ost, const Person person)
{
	ost << p._name << std::endl;
}
