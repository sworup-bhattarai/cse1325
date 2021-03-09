#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) : _grade(grade), Person(name , email)
{

}

void Student::add_parent(Parent& parent)
{
	int i = 1;
	for(auto p : _parents)
	{
		if (p->to_string() == parent.to_string())
		{
			i = 0;
			break;
		}
	}
	if (i ==1)
	{
		_parents.push_back(&parent);
	}
}

int Student::parents()
{
	return _parents.size();
}

Parent& Student::parent(int index)
{
	if (index > _parents.size())
	{
		throw std::out_of_range("The parameter is not within range");
	}
	else
	{
		return *_parents.at(index);
	}
}

std::string Student::full_info()
{
	std::string info;
	std::string inf = "";
	
	info =  "\nname: " + _name + " Email: (" + _email + ")" + " Grade: " + std::to_string(_grade) + " Parents: " ;
	for(int i = 0; i < parents(); i++)
	{
		inf = inf + _parents[i]->to_string() + " ";
	}
	return info + inf;
}
