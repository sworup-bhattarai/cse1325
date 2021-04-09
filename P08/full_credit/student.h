#ifndef __STUDENT_H
#define __STUDENT_H
class Parent;

#include "person.h"
#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>


class Student : public Person {

	protected:
		int _grade;
		std::vector<Parent*> _parents;
	public:
		Student(std::string name, std::string email, int grade);
		void add_parent(Parent& parent);
		int parents();
		Parent& parent(int index);
		std::string full_info() const override;
		void save(std::ostream& ost);

};
#endif
