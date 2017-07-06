#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//No polymorphism inside of a constructor

class Base{
public:
	virtual void foo() const { cout << "Base::foo()\n"; }
	virtual void foo(int n) const { cout << "Base::foo()\n"; }
};

class Derived : public Base{
public:
	using Base::foo;
	void foo(string s){}
};

class Shape{
public:
	Shape(int x, int y) : x(x), y(y) {}
	virtual void draw() { cout << "Default stuff...." << endl; }
	void move(int x, int y) { this->x = x; this->y = y; }
private:
	int x;
	int y;
};

class Triangle : public Shape {
public:
	Triangle(int x, int y) : Shape(x, y) {}
	virtual void draw() {}
private:
};

class Circle : public Shape{
public:
	Circle(int x, int y) : Shape(x, y) {}
	virtual void draw() {}
private:

};

int main(){
	Derived der;
	der.foo();
	der.foo(17);

	Shape shape(6, 28);
	shape.draw(); //draw what shape, what is it going to be?

	Triangle tri(3, 4);
	tri.draw();
	Circle circ(10, 10);
	circ.draw();
	system("pause");
}