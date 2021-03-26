#include "parent.h"
#include "student.h"

Parent::Parent(std::string name, std::string email) : Person(name , email)
{

}

void Parent::add_student(Student& s)
{
	int i = 1;
	for(auto p : _students)
	{
		if (p->to_string() == s.to_string())
		{
			i = 0;
			
		}
	}
	if (i ==1)
	{
		_students.push_back(&s);
	}
}

void Parent::save(std::ostream& ost)
{
	ost << "Parent" << std::endl;
	ost << _name << std::endl;
	ost << _email << std::endl;
	for (auto s : _students)
	{
		ost << s->to_string() << std::endl;
	
	}
	ost << "End Parent" << std::endl;
	
}


int Parent::students()
{
	return _students.size();
}

Student& Parent::student(int index)
{

	if (index > _students.size())
	{
		throw std::out_of_range("The parameter is not within range");
	}
	else
	{
		return *_students.at(index);
	}
}

std::string Parent::full_info() const
{
	std::string info = "";
	std::string c = " ";

	info = _name + " (" + _email + ")" + " Student: " ;
	for(int i = 0; i < _students.size(); i++)
	{
	
		info +=  c + _students.at(i)->to_string() ;
		c = ", ";
	}
	info += "\n";
	return info ;
}
