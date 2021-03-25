#include <iostream>
#include <fstream>
int main()
{
	std::ifstream ist{"text.txt"};
	if (!ist) throw std::runtime_error{"cant open text"};
	
	
	std::ofstream ost("text2.txt");
	
	std::string s ;
	int i = 1;
	while (std::getline(ist , s)) 
	{
		ost << i << " " << s << std::endl;
		i++;
	}
	return 0;
}
