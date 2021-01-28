#include <iostream>
#include <map>

enum class Size {L, XL, N};
std::string to_string(Size s) {
	std::map<Size, std::string> v = {{Size:: L ,"Large" } , {Size:: XL , "Extra Large"} , {Size:: N , "Normal"}};
	return v[s];

/*	switch(s){
		case Size::L : return "Large";
		case Size::XL : return "Extra Large";
		case Size::N : return "Normal";
	}
	return "Invalid";
*/
	
}

int main() {
	Size s = Size::XL;
	std::cout << to_string(s) << std::endl;

}