#ifndef RATIONAL_HPP 
#define RATIONAL_HPP 

class Rational {
	public:
		Rational(int n, int d)
			:num(n), den(d)
		{
			
		};
		
	private:
		int num;
		int den;
		
	friend bool operator==(Rational r1, Rational r2)
	{
		return (r1.num*r2.den) == (r2.num*r1.den);
	}
	
	friend bool operator<(Rational r1, Rational r2)
	{
		return r1.num == r2.num;
	}
	
	friend bool operator<=(Rational r1, Rational r2)
	{
		return r1.num == r2.num;
	}
	
	friend bool operator>(Rational r1, Rational r2)
	{
		return r1.num == r2.num;
	}
	
	friend bool operator>=(Rational r1, Rational r2)
	{
		return r1.num == r2.num;
	}
};

#endif 