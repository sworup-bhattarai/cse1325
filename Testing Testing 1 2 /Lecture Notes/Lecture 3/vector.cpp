#include <iostream>
#include <vector>

enum Month { JAN = 1 , FEB , MAR , APR , MAY , JUN , JUL ,AUG , SEP , OCT , NOV , DEC };
std::string to_string(Month m) {
	std::vector<std::string> to_string = {"", "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" ,
							  	          "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec"  };
	return to_string[m];
	}
enum Size { LARGE, XLARGE, NORMAL};
std::string to_string(Size s) {
	std::vector<std::string> to_string = { "Large" , "Extra Large" , "Normal" };
	
	return to_string[s];
}

int main() {
	/*Month  m = APR;
	std::cout << to_string(m) << std::endl;
	Size s = NORMAL;
	std::cout << to_string(s) << std::endl;*/
	
	for (Month m = JAN; m <= DEC; m = (Month)((int)m+1)) std::cout << to_string(m) << std::endl;
}