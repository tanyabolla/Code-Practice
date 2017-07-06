#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace CS1124{
	class Rational{
	public:
		Rational(){}
		Rational(int num);
		//Rational(int numerator, int denominator = 1);
		int greatestCommonDivisor(int x, int y);
		void normalize();
		void setNumerator(int num);
		void setDenominator(int den);
		int getNumerator() const;
		int getDenominator() const;
		friend std::istream& operator>>(std::istream& is, Rational& input);
		friend std::ostream& operator<<(std::ostream& os, const Rational& output);
		Rational& operator+=(Rational rhs);
		Rational& operator++();
		Rational operator++(int denominator);
		bool operator==(Rational rhs);
	private:
		int numerator;
		int denominator;
	};
	Rational operator+(const Rational& lhs, const Rational& rhs);
	Rational& operator--(Rational& rat);
	Rational operator--(Rational& rat, int denominator);
	bool operator!=(Rational& rhs, Rational& lhs);
	bool operator==(int rat, Rational& rhs);
}
#endif