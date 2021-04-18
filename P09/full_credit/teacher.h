#ifndef __TEACHER_H
#define __TEACHER_H

#include "person.h"
#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>

class Teacher : public Person {
	public:
	Teacher(std::string name, std::string email);
	void save(std::ostream& ost);
	std::string full_info() const override;
	
	};
#endif
