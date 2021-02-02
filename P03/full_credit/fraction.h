#ifndef __FRACTION_H
#define __FRACTION_H

#include <ostream>
#include <istream>

class Fraction{
  public:
  	Fraction(int n  , int d );
  	//int value();
	//Fraction operator-();
	//Fraction operator+(Fraction& rhs);
	//Fraction operator-(Fraction& rhs);
	//Fraction operator*(Fraction& rhs);
	//Fraction operator/(Fraction& rhs);
	
	friend std::ostream& operator<<(std::ostream& m, Fraction& );
	//friend istream& operator>>(istream& m, Fraction&);
	//friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
  private:
  	int _n;
	int _d;
	//reduce();
	
};

#endif
