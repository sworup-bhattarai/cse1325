#ifndef __SEMESTER_H
#define __SEMESTER_H

#include <map>
#include <vector>
#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>

enum class Semester{FALL, SPRING, SUMMER};

std::string to_string(Semester semester);

std::ostream& operator<<(std::ostream& ost, const Semester& semester);

std::string load_semester(std::istream& ist);

#endif
