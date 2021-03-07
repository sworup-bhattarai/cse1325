#include student.h

Student::Student(std::string name, std::string email, int grade) : this->grade(grade), Person(name , email)
{

}

void Student::add_parent(Parent& p)
{
	parent.push_back(p);
}

int Student::parents()
{
	return parent.size();
}

Parent& Student::parent(int index)
{
	if (index > this->parent.size())
	{
		throw std::out_of_range("The parameter is not within range");
	}
	else
	{
		return this->parent.at(index);
	}
}

std::string Student::full_info()
{
	std::string info;
	
	info =  "name: " + name + "\nEmail: (" + email + ")" + "\nGrade: " + grade + "\nParents: ";
	for(int i = 0; i > parent.size(); i++)
	{
		info += parent.at(i).to_string() + " ";
	}
	return info;
}
