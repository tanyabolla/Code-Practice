/*
	Chaitanya Bolla
	cb3172
	CS1124
	Implement the class Rational, so that the following program works.
*/
#include "Rational.h"
#include <iostream>
using namespace std;
using namespace CS1124;

int main(){
	Rational a, b;
	cout << "Input two rational numbers.\n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	Rational one = 1;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "one = " << one << endl;
	cout << "a += b: " << (a += b) << endl;	// Implement as member
	cout << "a = " << a << endl;
	cout << "a + one: " << (a + one) << endl;	// Implement as non-member, but not a friend
	cout << "a == one: " << boolalpha << (a == one) << endl;
	cout << "1 == one: " << boolalpha << (1 == one) << endl;  // How does this work?
	cout << "a != one: " << boolalpha << (a != one) << endl;  // Do not implement as friend.

	cout << "a = " << a << endl;
	cout << "++a = " << (++a) << endl;
	cout << "a = " << a << endl;
	cout << "a++ = " << (a++) << endl;
	cout << "a = " << a << endl;
	cout << "--a = " << (--a) << endl;
	cout << "a = " << a << endl;
	cout << "a-- = " << (a--) << endl;
	cout << "a = " << a << endl;

	system("pause");
}