#include "grade.h"





std::string to_string(Grade grade)
{
	std::map <Grade , std::string> g = {{Grade::A , "A"} , {Grade::B , "B"},
										{Grade::C , "C"} , {Grade::D , "D"},
										{Grade::F , "F"} , {Grade::I , "I"},
										{Grade::X , "X"}};
	return g[grade];
}

std::ostream& operator<<(std::ostream& ost, const Grade& grade)
{
	ost << to_string(grade);
	return ost;
}

