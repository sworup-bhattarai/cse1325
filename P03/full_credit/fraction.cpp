#include "fraction.h"

//Fraction operator+(Fraction& rhs){
//
//}

Fraction::Fraction( int n = 0 , int d = 0) :  _n{n}, _d{d}
{

}


std::ostream& operator<<(std::ostream& m, Fraction& fraction)
{
	m << fraction._n << "/" << fraction._d;
	return m;
}
