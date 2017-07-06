#include "Rational.h"
#include <iostream>
using namespace std;

namespace CS1124{
	Rational::Rational(int num) : numerator(num), denominator(1){}
	int Rational::greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}
	void Rational::normalize(){
		if (denominator < 0){
			//numerator = -1;
			denominator *= -1;
		}
		int temp = numerator;
		if (numerator < 0){
			//denominator = -1;
			temp *= -1;
		}
		int gcd;
		gcd = greatestCommonDivisor(temp, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}
	void Rational::setNumerator(int num){ numerator = num; }
	void Rational::setDenominator(int den){ denominator = den; }
	int Rational::getNumerator() const{ return numerator; }
	int Rational::getDenominator() const{ return denominator; }
	istream& operator>>(istream& is, Rational& input){
		char slash;
		is >> input.numerator;
		is >> slash;
		is >> input.denominator;
		input.normalize();
		return is;
	}
	ostream& operator<<(ostream& os, const Rational& output){
		os << output.numerator << "/" << output.denominator << endl;
		return os;
	}
	Rational& Rational::operator+=(Rational rhs){
		int gcd;
		numerator = (numerator * rhs.denominator) + (denominator * rhs.numerator);
		denominator = denominator * rhs.denominator;
		gcd = greatestCommonDivisor(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		return *this;
	}
	Rational& Rational::operator++(){
		numerator += denominator;
		return *this;
	}
	Rational Rational::operator++(int dummy){
		Rational temp(*this);
		numerator += denominator;
		return temp;
	}
	bool Rational::operator==(Rational rhs){
		rhs.normalize();
		this->normalize();
		return(numerator == rhs.getNumerator() && denominator == rhs.getDenominator());
	}
	Rational operator+(const Rational& lhs, const Rational& rhs){
		Rational temp = lhs;
		temp += rhs;
		return temp;
	}
	Rational& operator--(Rational& lhs){
		lhs.setNumerator(lhs.getNumerator() - lhs.getDenominator());
		return lhs;
	}
	Rational operator--(Rational& lhs, int dummy){
		Rational temp(lhs);
		lhs.setNumerator(lhs.getNumerator() - lhs.getDenominator());
		return temp;
	}
	bool operator!=(Rational& rhs, Rational& lhs){
		return !(lhs.Rational::operator==(rhs));
	}
	bool operator==(int rat, Rational& rhs){
		Rational r(rat);
		return rhs.Rational::operator==(rat);
	}
}