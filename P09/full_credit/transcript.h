#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H

#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>
#include "section.h"
#include "student.h"
#include "grade.h"


class Transcript{
	public:
		Transcript(Student& student, Section& section);
		void assign_grade(Grade grade);
		friend std::ostream& operator<<(std::ostream& ost,const Transcript& transcript);
	private:
		Section& _section;
		Student& _student;
		Grade _grade;


};

#endif

