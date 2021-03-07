#ifndef __PERSON_H
#define __PERSON_H

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>

class student;

class Parent : public Person
	
	protected:
		std::vector<Student*> students;
	
	public:
		Parent(std::string name, std::string email);
		void add_student(Student& student);
		int students();
		Student& student(int index);
		std::string full_info() override;

};
#endif
