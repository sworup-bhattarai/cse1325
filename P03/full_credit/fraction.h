#ifndef __FRACTION_H
#define __FRACTION_H

#include <ostream>
#include <istream>

class Fraction{
	int _n, _d;
	reduce();
  public;
  	void Fraction(int numeerator = 0 , int denominator = 0);
  	int value();
	Fraction operator-();
	Fraction operator+(Fraction& rhs);
	Fraction operator-(Fraction& rhs);
	Fraction operator*(Fraction& rhs);
	Fraction operator/(Fraction& rhs);
	
	friend ostream& operator<<(ostream& m, Fraction&);
	friend istream& operator<<(istream& m, Fraction&);
	friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
	
};

#endif
