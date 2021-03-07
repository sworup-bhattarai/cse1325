#ifndef __STUDENT_H
#define __STUDENT_H


#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>
class Parent;

class Student : public Person{

	protected:
		int grade;
		std::vector<Parent*> parents;
	public:
		Student(std::string name, std::string email, int grade);
		void add_parent(Parent& p);
		int parents();
		Parent& parent(int index);

};
#endif
