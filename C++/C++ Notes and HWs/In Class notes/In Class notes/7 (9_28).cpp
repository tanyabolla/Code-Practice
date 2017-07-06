#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//Pointers

class Person{
public:
	Person(const string& name) : name(name), ring(false),
		spouse(nullptr) //needs to be set to nullptr
	{}
		//not married when you are born so initialize it to false
	void display(ostream& os = cout) const {
		os << "Name: " << name << ", married? " << endl;
		if (ring) os << "yes";
		else os << "no";
		os << endl;
		//then set the false to true then we are done
		//but who else was invovlved - who did I get married to?
	}

	//john.marries(mary);
	void marries(Person betrothed){ //copy of the object, needs to be by reference
		//assign the address of theh object to the spouse
		//not just the name, since we need an identity (a person) not just a name
		spouse = &betrothed;
		//now, spouse is pointing to the mary if it's john, mary must know that she's married to John.
		//bethroted.setSpouse(...);
		//Data hiding allows access to the private variables of other instances of the class.
		//It doesn't allow access to private variables by functions, however, the methods of other instances can access the private variables.
		//So, no need for a setter method.
		betrothed.spouse = this;
		//the keyword this holds the address of the thing we called the method on. 
		//can only be used in the inside of a method
		//it's pointing to the object you are calling the method on
		//so john object, the this keyword would hold the address of john and assign it to mary
	}
private:
	string name;
	bool ring; //have a ring to symbolize being married
	//Person spouse; //makes it a recursive/infinite sequence
	//Person& spouse; //to answer who did I get married to?
	//can't just hold the wife's name since it just provides a name not an identity
	Person* spouse; //points to the person who they got married to
	//John's spouse pointer points to mary's spouse pointer and vice versa
};

int main(){
	Person john("John");
	Person mary("Mary");
	john.display();
	mary.display();
	john.marries(mary); //what does marries method do?

	//Pointers
	//Programs have some memory 
	//When a variable is defined, it exists somewhere in memory
	//we can find out where it is stored

	int x = 17;
	cout << x << endl;
	cout << &x << endl; //tell me your physical/virtual address-of operator
	//gonna be a bunch of numbers
	//Each thing in memory has a specific location
	//memory address in hexdecimal - basic sixteen
	
	//we want to remember this address in code - store it in something else
	//p = &x; - no data type - cpp is statically typed
	int* p = &x; //states that p is a pointer - memory addresses are allowed to be stored
	//int *p = &x;
	//int * p = &x; //all three mean the same thing

	//If something is written like this int* r, s; - looks like both are goinng to be pointers
	//int *r, s - only r is a pointer, s is an int
	//do not declare more than one pointer per line

	cout << p << endl;
	//print out p's address
	cout << &p << endl;
	//Don't care about addresses, just care about where p is pointing at

	//Dereference operator
	//Print out the originial value of the memory address that is stored in p so print out value of x
	cout << *p << endl;

	//Change what's in x using p
	*p = 42;

	cout << *p << endl;
	cout << x << endl;

	//Pointer to a pointer address
	int** pp = &p;
	cout << *pp << endl; //get p
	cout << **pp << endl; //get x

	system("pause");
}