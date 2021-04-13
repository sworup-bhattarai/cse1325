#ifndef __COURSE_H
#define __COURSE_H

#include <ostream>
#include <istream>
#include <map>
#include <iostream>
#include <sstream>
#include "subject.h"

class Course {

	private:
		int _grade;
		Subject _subject;
	public:
		Course(Subject subject, int grade);
		//Course(std::istream& ist);
		void save(std::ostream& ost);
		friend std::ostream& operator<<(std::ostream& ost,const Course& course );
};
#endif

	
