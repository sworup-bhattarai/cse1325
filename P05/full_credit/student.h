#ifndef __STUDENT_H
#define __STUDENT_H

class Parent;
#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>

class Student : public Person{
	protected:
		int _grade;
		std::vector<Parent*> _parents;
	public:
		Student(std::string name, std::string email, int grade);
		void add_parent(Parent& p);
		int parents();
		Parents& parent(int index);
		std::string full_info() override;
	
