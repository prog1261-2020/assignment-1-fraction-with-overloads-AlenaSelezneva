/*
Alena Selezneva
*/

#include <iostream>

#pragma once
class Fraction
{
public:
	Fraction();
	Fraction(int num);
	Fraction(int num, int denom);

	/*
	Member operator functions (Fraction + Fraction)
	*/
	Fraction operator+(const Fraction& rhs) const;
	Fraction operator-(const Fraction& rhs) const;
	Fraction operator*(const Fraction& rhs) const;
	Fraction operator/(const Fraction& rhs) const;

	/*
	Member comparison functions (Fraction == Fraction)
	*/
	bool operator==(const Fraction& rhs) const;
	bool operator!=(const Fraction& rhs) const;
	bool operator<(const Fraction& rhs) const;
	bool operator>(const Fraction& rhs) const;
	bool operator<=(const Fraction& rhs) const;
	bool operator>=(const Fraction& rhs) const;

	/*
	free math operator functions (int + Fraction)
	*/
	friend Fraction operator +(int, Fraction rhs);
	friend Fraction operator -(int, Fraction rhs);
	friend Fraction operator *(int, Fraction rhs);
	friend Fraction operator /(int, Fraction rhs);

	/*
	member operation assignment functions (Fraction += Fraction(int))
	*/
	Fraction& operator+=(const Fraction& rhs);
	Fraction& operator-=(const Fraction& rhs);
	Fraction& operator*=(const Fraction& rhs);
	Fraction& operator/=(const Fraction& rhs);

	/*
	free comparison functions (int < Fraction)
	*/
	friend bool operator<(const int this_, const  Fraction& rhs);
	friend bool operator>(const int this_, const  Fraction& rhs);
	friend bool operator<=(const int this_, const  Fraction& rhs);
	friend bool operator>=(const int this_, const  Fraction& rhs);

	/*
	input / output operators
	*/
	friend std::ostream& operator <<(std::ostream& os, const Fraction& rhs);
	friend std::istream& operator >>(std::istream& is, Fraction& rhs);

private:
	int numenator;
	int denomenator;

	void reduce();

};

/*
free math operator functions (int + Fraction)
*/
Fraction operator +(int, Fraction rhs);
Fraction operator -(int, Fraction rhs);
Fraction operator *(int, Fraction rhs);
Fraction operator /(int, Fraction rhs);

/*
free comparison functions (int < Fraction)
*/
bool operator<(const int this_, const  Fraction& rhs);
bool operator>(const int this_, const  Fraction& rhs);
bool operator<=(const int this_, const  Fraction& rhs);
bool operator>=(const int this_, const  Fraction& rhs);

/*
input / output operators
*/
std::ostream& operator <<(std::ostream& os, const Fraction& rhs);
std::istream& operator >>(std::istream& is, Fraction& rhs);