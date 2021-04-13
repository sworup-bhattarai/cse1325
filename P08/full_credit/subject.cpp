#include "subject.h"

std::string to_string(Subject subject)
{
	std::map <Subject, std::string> q = { { Subject::READING , "Reading"} ,
	 									  { Subject::WRITING , "Writing"} ,
	 									  { Subject::MATH , "Math"} ,
	 									  { Subject::SCIENCE , "Science"} ,
	 									  { Subject::HISTORY , "History"} ,
	 									  { Subject::ART , "Art"} ,};
	 									  
	 return q[subject];
	
}


std::ostream& operator<<(std::ostream& ost, const Subject& sub)
{
	ost << to_string(sub);
	return ost;
}

std::string load_subject(std::istream& ist)
{
	std::string s;
	std::getline(ist, s);
	return s;
}
