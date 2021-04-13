#include "course.h"

Course::Course(Subject subject, int grade) : _subject(subject), _grade(grade)
{

}

//Course::Course(std::istream& ist)
//{

//}

void Course::save(std::ostream& ost)
{
	
	ost << to_string(_subject) << std::endl;
	ost << _grade << std::endl;
	
}

std::ostream& operator<<(std::ostream& oat, const Course& course )
{
	oat << to_string(course._subject) ;
	oat << " (grade " << course._grade << ")" << std::endl;
	return oat;
}
