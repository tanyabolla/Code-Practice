#include <iostream>
#include <string>
using namespace std;

int add(int num1, int num2){
	return (num1 + num2);
}
int main(){

	////Basic pointers
	//int x = 17;
	//cout << x << endl;
	//cout << &x << endl; //address operator - gets address of x 
	////&x is an address not a pointer
	//int* p = &x; //store the address as a pointer
	//cout << p << endl;
	//cout << *p << endl; //dereference operator - get the number back from address
	//*p = 42; //modified x without changing p
	////it holds the same address except the x is different
	//cout << *p << endl; 
	//cout << p << endl;
	//cout << x << endl; //prints 42

	////pass-by value makes a temporary variable that is gone at the end of the function
	////make it pass-by reference by using the & symbol so it's not a copy and has depth
	////this keyword holds the address of the method we are calling.
	////in the case of mary and john, mary is being assigned to john.
	////bool marries(Person& betrothed) { //betrothed takes in a parameter in the main john.marries(mary); where john is the object
	////	if (spouse == nullptr && betrothed.spouse == nullptr) {
	////		spouse = &betrothed; //spouse is given the address of the parameter - john knows that he is married to mary but she doeesn't know this
	////		betrothed.spouse = this; //this keyword holds and points to the address of john which allows mary to know that she is married to john
	////		//have to make the parameter in the function passy by reference so john doesn't forget who he is married to at the end of the funtion
	////		return true;
	////	}
	////	return false;
	////}

	////Pointers with strings
	//string name = "paul";
	//cout << name << endl;
	//cout << &name << endl;

	////int* a = &name;
	//string* a = &name;
	//cout << a << endl;
	//cout << *a << endl;
	////all primitives can be interpreted as true or false: ints, strings, etc.


	////Pass-by value, pass-by reference, pass-by constant reference
	//int num1 = 5;
	//int num2 = 7;
	//int num3;
	//num3 = add(num1, num2);
	//cout << num3 << endl;
	//const int num4 = 8;
	////num4 = 7; //won't compile, if it is const int num1 because you cannot redefine it



	////cyclic association - forward declarations of classes to keep compilers happy.
	//class D; //removes errors from Class C
	//class C{
	//public:
	//	void cFunc();
	//private:
	//	D* z;
	//};
	//class D{
	//public:
	//	void dFunc(){}
	//private:
	//	C* y;
	//};
	////above example is cyclic association
	////However, the compiler doesn't know the size of the forward declared class and if there are functions in the class, they will pose erros.
	////implement the functions outside of the class
	////void C::cFunc(){ z->cFunc(); }



	////Separate Compilation
	////Declare the class and surround with namespace in the header file.
	///*namespace WarriorCraft{
	//	class C;
	//	class D{
	//	public:
	//		void display();
	//	private:
	//		string name;
	//	};
	//}*/
	////Include Gaurd in the header file too
	////the gaurd will prevent the compiler from including the class twice in implementation files.
	///*#ifndef HEADER_H
	//#define HEADER_H
	//#endif*/
	////can't use the same gaurd headers in different implementation files; it will give an error. 
	////DO NOT USE USING NAMESPACE IN THE HEADER FILE - USE STD:: INSTEAD TO QUALIFY
	////implement in the functions in the .cpp file
	////#include "Noble.h"
	////#include "Warrior.h"
	////using namespace std;
	////implement all your functions
	////use Class::function to realate your functions

	for (int i = 10; i = 1; i--){
		cout << i << endl;
	}
	system("pause");
}