#include "fraction.h"

/*Fraction Fraction::operator-()
{
	
	if (_d > 0 && _n > 0)
	{
		_n *= -1;
	}
	else if (_d > 0 && _n < 0 )
	{
		_n = abs(_n);
	}	
}
Fraction operator+(Fraction& rhs)
{
	rhs._n = (rhs._n * *this._d + rhs._d * *this._n)
	rhs._d = (*this._d * rhs._d )
	return rhs;
	//rhs(a/b) + *this(c/d) = (ad+bc)/bd;
}*/
void Fraction::reduce()
{
	if (_d < 0 && _n < 0 )
	{
		_n = abs(_n);
		_d = abs(_d);
	}
	else if (_d < 0 && _n > 0 )
	{
		_n *= -1;
		_d = abs(_d);
	}
	for (int i = _d * _n; i > 1; i--) 
        {  
        	if ((_d % i == 0) && (_n % i == 0)) 
      	  	{  
    			_d /= i;  
        		_n /= i;  
		}  
          
 	}
}
Fraction::Fraction( int n = 0 , int d = 0) :  _n{n}, _d{d}
{
	reduce();
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

