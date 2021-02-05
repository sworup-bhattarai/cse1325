#include "fraction.h"
#include <iostream>
#include <sstream>

int main() {
	Fraction f , e , j;
	std::string sfr;
	std::cout << "Please enter two fractions: ";
	std::cin >> f >> e;
	
	j = -f;
	std::ostringstream oss;
	oss << "You entered: " << f << " and: " << e << std::endl;
	oss << "The inverse of : " << f << " is: " << j << std::endl;
	j = -e;
	oss << "The inverse of : " << e << " is: " << j << std::endl;
	j = f*e;
	oss << f << " * " << e << " is: " << j << std::endl;
	j = f/e;
	oss << f << " / " << e << " is: " << j << std::endl; 
	j = f+e;
	oss << f << " + " << e << " is: " << j << std::endl;
	j = f-e;
	oss << f << " - " << e << " is: " << j << std::endl;
	std::cout << oss.str();
	

}
