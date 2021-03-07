#ifndef __PERSON_H
#define __PERSON_H

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>

class Person{
	protected:
		std::string name;
		std::string email;
	
	public:
		Person(std::string name, std::string email);
		std::string to_sting();
		virtual std::string full_info();
		friend std::ostream& operator<<(ostream& ost, const Person person);

};
#endif
