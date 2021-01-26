#include "date.h"

int main() {
    Date moon{"matto", JUL, 20};
	
    Date space{"catto", APR, 12}; // Runtime: "Invalid day: 1961"
    std::cout << moon.to_string() << std::endl;
    std::cout << space.to_string() << std::endl << std::endl;
    moon.next_day(); // Compiler: "error: ‘int Date::day’ is private"
    space.next_day();
    std::cout << moon.to_string() << std::endl;
    std::cout << space.to_string() << std::endl << std::endl;
 
}
