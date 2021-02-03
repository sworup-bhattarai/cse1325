#include "fraction.h"

//Fraction operator+(Fraction& rhs){
//
//}

Fraction::Fraction( int n = 0 , int d = 0) :  _n{n}, _d{d}
{

}
Fraction::Fraction( ) 
{
	_n = 0;
	_d = 0;
}


std::ostream& operator<<(std::ostream& m, Fraction& fraction)
{
	m << fraction._n << "/" << fraction._d;
	return m;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	is >> fraction._n;
	is >> fraction._v;
	is >> fraction._d;
	return is;
}

bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs._n != rhs._n) || (lhs._d != rhs._d);
}
