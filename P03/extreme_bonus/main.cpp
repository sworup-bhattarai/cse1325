#include "fraction.h"
#include <iostream>
#include <sstream>

int main() {
	Fraction f , e , j;
	int a;
	std::string sfr;
	std::cout << "Please enter two fractions: ";
	std::cin >> f >> e;
	
	
	j = -f;
	std::ostringstream oss; //ALL THE ssssss
	oss << "You entered: " << f << " and: " << e << std::endl;
	oss << "The inverse of : " << f << " is: " << j << std::endl;
	j = -e;
	oss << "The inverse of : " << e << " is: " << j << std::endl;
	j = f*e;
	oss << f << " * " << e << " = " << j << std::endl;
	j = f/e;
	oss << f << " / " << e << " = " << j << std::endl; 
	j = f+e;
	oss << f << " + " << e << " = " << j << std::endl;
	j = f-e;
	oss << f << " - " << e << " = " << j << std::endl;
	
	oss << "\n---------------------------------------------------------------------------\n";
	oss << "----------------------------------Bonus------------------------------------\n";
	oss << "---------------------------------------------------------------------------\n\n";
	if (f == e){
	oss << f << " is equal to " << e<< std::endl;
	}
	else 
	{
	oss << f << " is NOT equal to " << e<< std::endl;
	}
	
	if (f < e){
	oss << f << " is less than " << e<< std::endl;
	}
	else 
	{
	oss << f << " is NOT less than " << e<< std::endl;
	}
	
	if (f <= e){
	oss << f << " is less than or equal to " << e<< std::endl;
	}
	else 
	{
	oss << f << " is NOT less than nor equal to " << e <<std::endl;
	}
	
	
	if (f > e){
	oss << f << " is greater than " << e<< std::endl;
	}
	else 
	{
	oss << f << " is NOT greater than " << e<< std::endl;
	}
	
	if (f >= e){
	oss << f << " is greater than or equal to " << e<< std::endl;
	}
	else 
	{
	oss << f << " is NOT greater than nor equal to " << e<< std::endl;
	}
	
	oss << "\n---------------------------------------------------------------------------\n";
	oss << "-------------------------------Extreme-Bonus-------------------------------\n";
	oss << "---------------------------------------------------------------------------\n\n";
	std::cout << "Please enter an int: ";
	std::cin >> a;
	j = a + f;
	oss << a << " + " << f << " = " << j << std::endl;
	j = f + a;
	oss << f << " + " << a << " = " << j << std::endl;
	j = a - f;
	oss << a << " - " << f << " = " << j << std::endl;
	j = f - a;
	oss << f << " - " << a << " = " << j << std::endl;
	j = a * f;
	oss << a << " * " << f << " = " << j << std::endl;
	j = f * a;
	oss << f << " * " << a << " = " << j << std::endl;
	j = a / f;
	oss << a << " / " << f << " = " << j << std::endl;
	j = f / a;
	oss << f << " / " << a << " = " << j << std::endl << "++" << f;
	f++;
	oss << " is = " << f << std::endl << f;
	++f;
	oss << "++ is = " << f<< std::endl;
	std::cout << oss.str();
	



}
