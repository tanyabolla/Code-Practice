#include <iostream>
#include <vector>
using namespace std;

class Base{
public:
	Base(){}
};

class Derived : public Base{
public:
	virtual void foo() { cout << "In Derived foo()"; }
};

class Cat{
public:
	int someMethod(string a){ return 17;}
	double weight;
};

class Foo{
public:
	Foo(int a, double b) { 
		x = a; 
		y = b; 
	}
private:
	int x;
	double y;
};

class Bar{
public:
	Bar(int a, double b, const string& s) : thing(a, b), z(s) {}
private:
	string z;
	Foo thing;
};

int main(){
	//vector<int> num;
	//num.push_back(1);
	//num.push_back(2);
	//num.push_back(3);
	//num.push_back(4);
	//num.push_back(5);
	//for (size_t i = num.size(); i > 0; i--){
	//	num[i-1] = num[i];
	//}

	Base* p = new Derived();
	//p->foo();

	Bar bar(5, 3.14, "foo");

	system("pause");
}