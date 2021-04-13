#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <map>
#include <vector>
#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>

enum class Subject {READING, WRITING, MATH, SCIENCE, HISTORY, ART};

std::string to_string(Subject subject);

std::ostream& operator<<(std::ostream& ost, const Subject& sub);

std::string load_subject(std::istream& ist);

#endif
