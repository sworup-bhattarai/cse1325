#include"fraction.h"
#include<iostream>
#include<sstream>
int main(){Fraction f,e,j;std::string sfr;std::cout<<"Please enter two fractions: ";std::cin>>f>>e;j=-f;std::ostringstream oss,osss;oss<<"You entered : "<<f<<" and: "<<e<<std::endl;oss<<"The inverse of: "<<f<<" is: "<<j<<std::endl;j=-e;oss<<"The inverse of: "<<e<<" is: "<<j<<std::endl;j=f*e;oss<<f<<" * "<<e<<" is: "<<j<<std::endl;j=f/e;oss<<f<<" / "<<e<<" is: "<<j<<std::endl;j=f+e;oss<<f<<" + "<<e<<" is: "<<j<<std::endl;j=f-e;oss<<f<<" - "<<e<<" is: "<<j<<std::endl;std::cout<<oss.str();if(f==e){osss<<f<<" is equal to "<<e<<std::endl;}else{osss<<f<<" is NOT equal to "<<e<<std::endl;}if(f<e){osss<<f<<" is less than "<<e<<std::endl;}else{osss<<f<<" is NOT less than "<<e<<std::endl;}if(f>e){osss<<f<<" is greater than "<<e<<std::endl;}else{osss<<f<<" is NOT greater than "<<e<<std::endl;}if(f>=e){osss<<f<<"is greater than or equal to "<<e<<std::endl;}else{osss<<f<<" is NOT greater than nor equal to "<<e<<std::endl;}if(f<=e){osss<<f<<" is less than or equal to "<<e<<std::endl;}else{osss<<f<<" is NOT less than nor equal to "<<e<<std::endl;}std::cout<<osss.str();}

//what have i done and why is it still working?!?!?!?!?
