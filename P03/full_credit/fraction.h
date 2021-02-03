#ifndef __FRACTION_H
#define __FRACTION_H

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>

class Fraction{
  public:
  	Fraction(int n , int d );
  	Fraction();
  	//int value();
	//Fraction operator-();
	//Fraction operator+(Fraction& rhs);
	//Fraction operator-(Fraction& rhs);
	//Fraction operator*(Fraction& rhs);
	//Fraction operator/(Fraction& rhs);
	
	friend std::ostream& operator<<(std::ostream& m, Fraction& );
	friend std::istream& operator>>(std::istream& is, Fraction&);
	friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
  private:
  	int _n;
	int _d;
	char _v;
	//reduce();
	
};

#endif
