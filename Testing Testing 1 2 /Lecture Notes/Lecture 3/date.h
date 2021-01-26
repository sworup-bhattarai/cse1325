#ifndef __DATE_H
#define __DATE_H


#include <iostream>
#include <vector>
#include <map>

enum Month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
std::string to_string(Month month);

class Date {
    std::string _year;
    Month month;
    int _day;
 public:
	Date(std::string y, Month m, int d);
	void next_day();
	std::string to_string();
	
};
#endif
