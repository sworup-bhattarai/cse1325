#include "parent.h"
#include "student.h"

Parent::Parent(std::string name, std::string email) : Person(name , email)
{

}

void Parent::add_student(Student& s)
{
	_students.push_back(s); // adds students to std::vector<Student*>
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

std::string Parent::full_info()
{
	std::string info;
	
	info =  "name: " + _name + "\nEmail: (" + _email + ")" + "\nStudent: ";
	for(int i = 0; i > _students.size(); i++)
	{
		info += _students[i]->to_string() + " ";
	}
	return info;
}
