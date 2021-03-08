#include "parent.h"
#include "student.h"

Parent::Parent(std::string name, std::string email) : Person(name , email)
{

}

void Parent::add_student(Student& s)
{
	_students.push_back(&s); //WORKS NOW yayy adds students to std::vector<Student*>
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
	//TODO: NO HARDCODE need to find a way to not segfault by using for loop
	info =  "\nname: " + _name + " Email: (" + _email + ")" + " Student: " + _students[0]->to_string();
	/*for(int i = 0; i > _students.size(); i++)
	{
		info += _students[i]->to_string() + " ";
	}*/
	return info;
}
