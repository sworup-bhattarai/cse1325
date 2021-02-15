#include <iostream>
#include <regex>
using namespace std;
int main() {
string input;
regex integer{"-?\\d+"};
cout << "Enter some integers:" << endl;
while(cin>>input) {
if(regex_match(input,integer)) cout << "That’s an int!" << endl;
else
cout << "***INVALID INPUT***" << endl;
}
}

