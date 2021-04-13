#include "section.h"


Section::Section(Course course, Semester semester, int year) : _year(year) , _course(course), _semester(semester)
{
	
}
//Section::Section(std::istream& ist)
//{
	//ist >>  ;
//}

void Section::save(std::ostream& ost)
{
	/* << "Section" << std::endl;
	ost << _course << std::endl;
	ost << ::to_string(_semester) << std::endl;
	ost << _year << std::endl;
	ost << "End Section" << std::endl;*/
	
}

std::ostream& operator<<(std::ostream& oat, Section& section)
{
	return oat;
}
