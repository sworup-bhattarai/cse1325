#include "teacher.h"

Teacher::Teacher(std::string name, std::string email) : Person(name , email)
{

}

void Teacher::save(std::ostream& ost)
{
	ost << "Teacher" << std::endl;
	ost << _name << std::endl;
	ost << _email << std::endl;
	ost << "End Teacher" << std::endl;
}

std::string Teacher::full_info()  const
{
	std::string info;
	info = _name + " (" + _email + ")\n" ;
	return info;

}
