
#include <iostream>
using namespace std;

int main(){
	cout << "Hello World!" << endl;
	string s;
	s = "#";
	
	for (int i = 0; i <= 100 ; i ++){
	
		cout << s << endl;
		s += "#";
	}
}