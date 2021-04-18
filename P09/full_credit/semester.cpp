#include "semester.h"

std::string to_string(Semester semester)
{
	std::map <Semester, std::string> q = { { Semester::FALL , "Fall"} ,
	 									   { Semester::SPRING , "Spring"} ,
	 									   { Semester::SUMMER , "Summer"}};
	 									  
	 return q[semester];
	
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester)
{
	ost << to_string(semester);
	return ost;
}

std::string load_semester(std::istream& ist)
{
	std::string s;
	std::getline(ist, s);
	return s;
	
}
