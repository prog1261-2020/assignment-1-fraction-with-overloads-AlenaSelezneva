/*
Alena Selezneva
*/

#include "Fraction.h"
#include <stdexcept>
#include <numeric>
#include <iostream>

/*
Constructors
*/
Fraction::Fraction() :numenator(0), denomenator(1) {}
Fraction::Fraction(int num) : numenator(num), denomenator(1) {  }
Fraction::Fraction(int num, int denom) : numenator(num), denomenator(denom) {
	if (denomenator == 0)
		throw std::out_of_range("Attempt to have 0 in denominator");
	reduce();
}

// 
void Fraction::reduce() {
	if (denomenator < 0) {
		numenator = -numenator;
		denomenator = -denomenator;
	}
	if (numenator != 0 && denomenator != 0)
	{
		int d = std::gcd(numenator, denomenator);
		numenator /= d;
		denomenator /= d;
	}
}

/*
	Member operator functions (Fraction + Fraction)
*/
Fraction Fraction::operator+(const Fraction& rhs) const {
	int num = numenator * rhs.denomenator + denomenator * rhs.numenator;
	int denom = denomenator * rhs.denomenator;
	Fraction f1(num, denom);
	f1.reduce();
	return f1;
}
Fraction Fraction::operator-(const Fraction& rhs) const {
	int num = numenator * rhs.denomenator - denomenator * rhs.numenator;
	int denom = denomenator * rhs.denomenator;
	Fraction f1(num, denom);
	f1.reduce();
	return f1;
}
Fraction Fraction::operator*(const Fraction& rhs) const {
	int num = numenator * rhs.numenator;
	int denom = denomenator * rhs.denomenator;
	Fraction f1(num, denom);
	f1.reduce();
	return f1;
}
Fraction Fraction::operator/(const Fraction& rhs) const {
	int num = numenator * rhs.denomenator;
	int denom = denomenator * rhs.numenator;
	Fraction f1(num, denom);
	f1.reduce();
	return f1;
}

/*
	free math operator functions (int + Fraction)
*/
Fraction operator +(int this_, Fraction rhs) {
	Fraction f1 = rhs + (Fraction(this_));
	f1.reduce();
	return f1;
}
Fraction operator -(int this_, Fraction rhs) {
	Fraction f1(this_);
	f1 = f1 - rhs;
	f1.reduce();
	return f1;
}
Fraction operator *(int this_, Fraction rhs) {
	Fraction f1 = rhs * (Fraction(this_));
	f1.reduce();
	return f1;
}
Fraction operator /(int this_, Fraction rhs) {
	Fraction f1(this_);
	f1 = f1 /rhs;
	f1.reduce();
	return f1;
}

/*
Member comparison functions (Fraction == Fraction)
*/
bool Fraction::operator==(const Fraction& rhs) const {
	return (numenator == rhs.numenator) && (denomenator == rhs.denomenator);
}
bool Fraction::operator!=(const Fraction& rhs) const {
	return !((*this) == rhs);
}
bool Fraction::operator<(const Fraction& rhs) const {
	return (((*this) - rhs).numenator < 0) ? true : false;
}
bool Fraction::operator>(const Fraction& rhs) const {
	return !((*this) < rhs || (*this) == rhs);
}
bool Fraction::operator<=(const Fraction& rhs) const {
	return !(*this > rhs);
}
bool Fraction::operator>=(const Fraction& rhs) const {
	return !(*this < rhs);
}

/*
free comparison functions (int < Fraction)
*/
bool operator<(const int this_, const  Fraction& rhs) {
	Fraction f(this_);
	return f < rhs;
}
bool operator>(const int this_, const  Fraction& rhs) {
	Fraction f(this_);
	return f > rhs;
}
bool operator<=(const int this_, const  Fraction& rhs) {
	Fraction f(this_);
	return f <= rhs;
}
bool operator>=(const int this_, const  Fraction& rhs) {
	Fraction f(this_);
	return f >= rhs;
}

/*
input / output operators
*/
std::ostream& operator <<(std::ostream& os, const Fraction& rhs) {
	os << rhs.numenator << "/" << rhs.denomenator;
	return os;
}
std::istream& operator >>(std::istream& is, Fraction& rhs) {
	char c;
	is >> rhs.numenator >> c >> rhs.denomenator;
	rhs.reduce();
	return is;
}

Fraction& Fraction::operator+=(const Fraction& rhs) {
	(*this) = (*this) + rhs;
	reduce();
	return (*this);
}
Fraction& Fraction::operator-=(const Fraction& rhs) {
	(*this) = (*this) - rhs;
	reduce();
	return (*this);
}
Fraction& Fraction::operator*=(const Fraction& rhs) {
	(*this) = (*this) * rhs;
	reduce();
	return (*this);
}
Fraction& Fraction::operator/=(const Fraction& rhs) {
	(*this) = (*this) / rhs;
	reduce();
	return (*this);
}