#ifndef __SECTION_H
#define __SECTION_H

#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>
#include "course.h"
#include "semester.h"

class Section{
	private:
		int _year;
		Course _course;
		Semester _semester;
		
	public:
		Section(Course course, Semester semester, int year);
		//Section(std::istream& ist);
		void save(std::ostream& ost);
		friend std::ostream& operator << (std::ostream& ost,const Section& section );
};
#endif

