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
	ost << "Section" << std::endl;
	ost << _course ;
	ost << ::to_string(_semester) << std::endl;
	ost << _year << std::endl;
	ost << "End Section" << std::endl;
	
}

std::ostream& operator<<(std::ostream& oat, const Section& section)
{
	oat << section._course << "\t\tfor "<< to_string(section._semester) << " " << section._year << std::endl;
	return oat;
}
