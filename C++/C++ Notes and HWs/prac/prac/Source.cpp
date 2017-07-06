#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class Base {
//public:
//	~Base() { cout << "Base" << endl; }
//};
//class Derived : public Base{
//public:
//	~Derived() { cout << "Derived" << endl; }
//};

//class Foo{
//public:
//	Foo(string s, int n = 0) { str = s; num = n; }
//	void display() { cout << str << ':' << num << endl; }
//private:
//	string str;
//	int num;
//};

//class Member{
//public:
//	Member() { cout << 1; }
//	~Member() { cout << 2; }
//};
//class Base{
//	Member member;
//public: 
//	Base() { cout << 3; }
//	~Base() { cout << 4; }
//};
//class Derived : public Base{
//public:
//	Derived() { cout << 5; }
//	~Derived() { cout << 6; }
//};
//
//int towers(int n, char start, char target, char spare){
//	if (n == 0) return 0;
//	int count = 0;
//	count += towers(n - 1, start, spare, target);
//	++count;
//	count += towers(n - 1, spare, target, start);
//	return count;
//}

class Animal{
public:
	virtual void eat() {
		cout << "Animal eat" << endl; 
	}
};

class Dog : public Animal {
public:
	void eat() { cout << "Dog eat" << endl; }
};
int main(){
	Animal any;
	any.eat();
	Dog b;
	b.eat();
	Animal* ap = &b; //polymorphism
	ap->eat();
	//Dog* bp = &any; //derived pointers cannot point to base pointers

	//Derived* dp = new Derived();
	//delete dp;

	/*Foo thingOne("abc", 17);
	string s = "def";
	thingOne = s;
	thingOne.display();*/
	
	//cout << towers(64, 'a', 'c', 'b') << endl;

	system("pause");
}