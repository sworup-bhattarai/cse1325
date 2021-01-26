#include <iostream>

enum Month { JAN = 1 , FEB , MAR , APR , MAY , JUN , JUL ,AUG , SEP , OCT , NOV , DEC };
std:: string to_string[13] = {"", "Jan", "Feb" , "Mar" , "Apr" , "May" , "Jun" ,
							  	  "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec"  };

int main() {
	Month  m = APR;
	std::cout << to_string[m] << std::endl;
}