#include "fraction.h"

Fraction Fraction::operator-()
{
	
	if (_d > 0 && _n > 0)
	{
		_n *= -1;
	}
	else if (_d > 0 && _n < 0 )
	{
		_n = abs(_n);
	}
	return *this;	
}
Fraction operator+(Fraction& rhs)
{
	_n = (rhs._n * _d + rhs._d * _n);
	_d = (_d * rhs._d );
	
	//rhs(a/b) + (c/d) = (ad+bc)/bd;
	
}
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
Fraction::Fraction( int n = 0 , int d = 1) :  _n{n}, _d{d}
{
	reduce();
}
Fraction::Fraction( ) 
{
	_n = 0;
	_d = 1;
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

