#include "section.h"


Section::Section(Course course, Semester semester, int year, Teacher& teacher) : _year(year) , _course(course), _semester(semester) , _teacher(teacher)
{
	
}
//Section::Section(std::istream& ist)
//{
	//ist >>  ;
//}

void Section::save(std::ostream& ost)
{
	ost << "Section" << std::endl;
	ost << _course << std::endl;;
	ost << ::to_string(_semester) << std::endl;
	ost << _year << std::endl;
	ost << _teacher << std::endl;
	ost << "End Section" << std::endl;
	
}

std::ostream& operator<<(std::ostream& oat, const Section& section)
{
	oat << section._course << " for "<< to_string(section._semester) << " " << section._year << "( taught by " << section._teacher.to_string() << ")";
	return oat;
}
