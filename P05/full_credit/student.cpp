#include student.h

Student::Student(std::string name, std::string email, int grade) : _grade(grade), Person(name , email)
{

}

void Student::add_parent(Parent& p)
{
	_parent.push_back(p);
}

int Student::parents()
{
	return parent.size();
}

Parents& Student::parent(int index)
{
	if (index > _parents.size())
	{
		throw std::out_of_range("The parameter is not within range");
	}
	else
	{
		return _parents.at(index);
	}
}

std::string Student::full_info()
{
	std::string info;
	
	info =  "name: " + _name + "\nEmail: (" + _email + ")" + "\nGrade: " + _grade + "\nParents: ";
	for(int i = 0; i > _parents.size(); i++)
	{
		info += _parent.at(i).to_string() + " ";
	}
}
