#ifndef __GRADE_H
#define __GRADE_H

#include <map>
#include <vector>
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

enum class Grade {A, B, C, D, F, I, X};

std::string to_string(Grade grade);

std::ostream& operator<<(std::ostream& ost, const Grade& grade);

#endif
