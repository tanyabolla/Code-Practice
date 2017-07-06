#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//Operator overloading

//Arithmetic overloaders: +, -, ++, --
//String concatenation using + operator
//Assignment operator (=)
//Combination operator +=, -=, *=
//Bracket operator []
//Equality operator and comparison operator ==, !=, >, <, >=, <=
//Dereference operator *

class Person {
	//Methods marked friend have access to the class's private variables
	friend ostream& operator<<(ostream& os, const Person& rhs);
	// friend ostream& operator<<(ostream& os, const Person& rhs) {
	//     os << rhs.name << ", " << rhs.height;
	//     return os;
	// }
	friend bool operator==(const Person& lhs, const Person& rhs);
	friend bool operator<(const Person& lhs, const Person& rhs);
public:
	Person(const string& name, int height) : name(name), height(height) {}
	void display(ostream& os = cout) const {
		os << "Name: " << name << "; Height: " << endl;
	}

	// Coercion / conversion
	operator bool() const {
		return height > 0;
	}
private:
	string name;
	int height;
};

//    cout << fred;
//    operator<<(cout, fred);
//<< defining what it does
ostream& operator<<(ostream& os, const Person& rhs) {
	os << rhs.name << ", " << rhs.height << endl; //using what it does to implement it, not recursion
	//the << in the function don't have the same meaning that we are trying to overload
	return os;
	//^it's accessing the private fields of the class
	//Defining getters: we don't want to be bothered to do it
	//I wrote the class, I ought to be able use it. Tell the compiler that
	//Tell the compiler that this function should have the same permissions as a method
	//Say I trust this function. Who do you trust? Your friends
	//Keyword friend
}

bool operator==(const Person& lhs, const Person& rhs) {
	return lhs.name == rhs.name && lhs.height == rhs.height;
}

bool operator<(const Person& lhs, const Person& rhs) {
	return lhs.height < rhs.height;
}

bool operator<=(const Person& lhs, const Person& rhs) {
	return lhs == rhs || lhs < rhs;
}

int main(){
	Person fred("Fred", 70);

	// What we want?
	cout << "The Person fred object: " << fred << endl;

	// What we have to write:
	cout << "The Person fred object: ";
	fred.display();

	cout << fred << endl;
	//We have to find the function that monitors printing out and overload it.
	//operator<<(cout, fred);
	//Change << to a function call
	//ostream& operator<<(ostream& os, const Person& rhs){}
	//Also chain it
	//cout << 42 << "cat";
	//(4 + 5) + 6
	//Looks at the operator, combines them, then sees it again, and does it again
	//cout (<< 42) (<< "cat"); //return the same stream that was passed in to chain them
	//so that's why ostream is the return type
	//if return type is ostream, you are returning a copy, so use ostream& to pass by reference

	//+ operator
	//You can't change the meaning for primitive built-in types
	//like 4 + 5
	//if it was fred + 5 then you can change it
	//Atleast one has to be a defined type

	Person george("George", 63);
	if (fred == george) {} //maybe they have the last name, or same height
	//Make it whatever we want it to be

	//while (ifs >> s) {} //coerced to be a boolean

	if (fred) {}

	system("pause");
}