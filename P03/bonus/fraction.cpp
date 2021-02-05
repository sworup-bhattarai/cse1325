#include "fraction.h"

Fraction::Fraction( int n = 0 , int d = 1) :  _n{n}, _d{d}
{

	reduce();
}
Fraction::Fraction( ) 
{
	_n = 0;
	_d = 1;
	reduce();
}

Fraction Fraction::operator-()
{
	
	Fraction f{_n , _d};
	if (f._d > 0 && f._n > 0)
	{
		f._n *= -1;
	}
	else if (f._d > 0 && f._n < 0 )
	{
		f._n = abs(f._n);
	}
	return f;	
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
	};
	if (_n < 0)
	{
		_n = abs(_n);
		for (int i = _d * _n; i > 1; i--) 
		{  
			if ((_d % i == 0) && (_n % i == 0)) 
	      	  	{  
	    			_d /= i;  
				_n /= i;  
			}  
		  
	 	}
	 	_n *= -1;
	}
	else 
	{
		for (int i = _d * _n; i > 1; i--) 
		{  
			if ((_d % i == 0) && (_n % i == 0)) 
	      	  	{  
	    			_d /= i;  
				_n /= i;  
			}  
		  
	 	}
	 }
}

std::ostream& operator<<(std::ostream& m, Fraction& fraction)
{
	m << fraction._n << "/" << fraction._d;
	return m;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	char v;
	is >> fraction._n;
	is >> v;
	is >> fraction._d;
	fraction.reduce();
	return is;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) 
{

	Fraction f{rhs._n * lhs._d + rhs._d * lhs._n, lhs._d * rhs._d };;
	//rhs(a/b) + (c/d) = (ad+bc)/bd;
	return f;
}
Fraction operator-(const Fraction& lhs, const Fraction& rhs) 
{
	int c = rhs._n * -1;
	Fraction f{lhs._n * rhs._d + lhs._d * c, lhs._d * rhs._d };
	//rhs(a/b) + (c/d) = (ad+bc)/bd;
	return f;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
	Fraction f {lhs._n * rhs._n, lhs._d * rhs._d};
	return f;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
	Fraction f {lhs._n * rhs._d, lhs._d * rhs._n};
	return f;
}


bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs._n != rhs._n) || (lhs._d != rhs._d);
}

















