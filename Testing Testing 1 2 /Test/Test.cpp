
#include <iostream>
using namespace std;

int main(){
	cout << "Hello World!" << endl;
	string s;
	s = "#";
	
	//for loop 
	for (int i = 1; i <= 6 ; i ++){
	
		cout << i << " " << s << endl;
		s += "#";
	}
	int count = 1;
	
	//while loop
	while (count <= 12){
		cout << "Count still not 12 yet. It is currently: " << count << endl;
		count++;
	}
	
	//do while loop
	do{
		if (count != 0){
			cout << "Count still not 0 yet. It is currently: " << count << endl;
			count--;
		} else {
			cout << "Count is now: " << count << endl;
			count--;
		}
		
	}while(count >= 0); 
	
	
}