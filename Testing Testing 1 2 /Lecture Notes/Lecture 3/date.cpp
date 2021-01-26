#include "date.h"
		
std::string to_string(Month month) {
    std::vector<std::string> v = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return v[month];
}


Date::Date(std::string y, Month m, int d) : _day{d}, month{m} , _year{y} {
        if (1 > d || d > 31) std::cerr << "ERROR: Invalid day: " << std::endl;
}
void Date::next_day() {++_day;}
std::string Date::to_string() {
		return std::to_string(_year) + " "
			 +    ::to_string(month) + " "
			 + std::to_string(_day);
} 
