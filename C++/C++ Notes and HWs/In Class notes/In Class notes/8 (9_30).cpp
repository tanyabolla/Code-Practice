#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
//Association and Composition

//Composition/Containtment
//Come into existence at the same time and get destroyed at the same time
//Warrior is born with weapon, or Person with a name or birthdate
//An object is part of an other object
class Bar{}; 
class Foo{
private:
	Bar bar;
public:
	void display() const { cout << "Always has a bar." << endl; }
};

//Association
//Marriage doesn't have to be that way, marry after you exist and divorce
//It can refer to another class sometimes, and sometimes it doesn't have to
//Established sometime after both objects exist
//Use pointer to an object
class Person{
public:
	Person(const string& name) : name(name), spouse(nullptr) 
		//not married when you are born so initialize it to NULL
		//nullptr - instead of leaving it empty use nullptr
		//nullptr - not pointing to anything so there's no accidental garbage
		//NULL has some problems, code is safer with nullptr
	{}
	void display(ostream& os = cout) const {
		os << "Name: " << name << ", Married?: " << endl;
		if (spouse != nullptr){
			os << "yes: " << spouse->name; 
			//*spouse.name;
			//dot operator has higher precedence (order of operations) - thinks *(spouse.name)
			//(*spouse).name; - parentheses have higher precedence than dot operator
			//cleaner - spouse->name
		}
		else{
			os << "no";
		}
		os << endl;
		//then set the false to true then we are done
		//but who else was invovlved - who did I get married to?
	}

	//john.marries(mary);
	//void marries(Person& betrothed){ //needs & - betrothed shouldn't be a copy so use pass by reference instead of pass by value
	bool marries(Person& betrothed){ 
		//OPTIMIZE
		//Make sure either the betrothed, or this person aren't already married
		//so sally can't steal john from mary
		if (spouse == nullptr && betrothed.spouse == nullptr){
			//fails silently - no way to tell this happened in the main
			spouse = &betrothed;
			betrothed.spouse = this;
			return true;
		}
		return false;
	}
private:
	string name;
	Person* spouse; 
};

int main(){
	Person john("John");
	Person mary("Mary");
	john.display();
	mary.display();
	john.marries(mary);

	Person sally("Sally");
	sally.marries(john);
	//John and Sally get married, but Mary doesn't know about it. She still thinks she's still married to John.

	//Two collections - poly and brooklyn - there's overlap - some people live in both brooklyn and attend poly
	//Third vector, and the two small vectors point to it
	//Solution: create it on the heap and make both the vector point to it

	//Memory of your program when it's running
	/* 
	Call stack - top, growing down (runtime stack) 
		//What is call stack? - order of functions being called
		//Main then i.e. Foo, Bar, etc
		//When run, entry gets pushed onto the call stack, then when the call is done, it gets popped out
		//What's it for? - the varibles - where they actually live
		//this is why scope exists, because they are physically deleted
	Heap - middle, grows upwards - gives a block of memory, ask for another one, grows and gives more space
	Globals - things you won't use
	Code
	*/

	ifstream ifs("person.txt");
	if (!ifs){
		exit(1);
	}

	vector<Person*> poly;
	string name;
	while (ifs >> name){
		Person somebody(name); //local variable - only one in main
		poly.push_back(&somebody);
		//everytime we push_back that address, we push_back that variable's address
		//Every loop, somebody got reinitialized in the call stack and it was the same space everytime
		//we need a different entry every time, a different region, so we get to the HEAP
	}

	for (Person* pp : poly){
		//pp->display(); //not working
		cout << pp << endl; //just prints out the addresses instead
		//all the addresses are the same (look at Person somebody(name);)
	}

	//How to allocate memory on the heap?
	//Keyword new - allocates space on the heap
	//int* intptr is in call stack
	//gets an int, initializes it to 28, then stores the address in the call stack
	//The call stack memory is deleted at the end of the scope, and the memory on the heap is only freed up
	//if specifically asked to delete or the program ends
	int* intptr = new int(28); //initialize the value 28
	//intptr - stores the address of the number 28
	//intptr points to 28 in the heap
	cout << intptr << endl;
	cout << *intptr << endl;

	//Memory doesn't clear itself - only if you state that you want the memory to freed or if your program ends
	delete intptr; //does nothing to the variable intptr 
	//intptr - pointer variable holding an address and still pointing to it
	//memory is cleared except intptr is still pointing to the memory address of int
	cout << intptr << endl;
	cout << *intptr << endl; //garbage, not 28
	intptr = nullptr; //to make sure you don't use the garbage

	//new - returns the address of the value that was allocated of the heap, and size of the space allocated
	
	//Before deleting, memory isn't freed up yet
	int* intptr = new int(6);
	//the memory of 28 is still sitting in there but we have forgotten where it is
	//Memory leak

	while (ifs >> name){
		Person* personPtr = new Person(name);
		poly.push_back(personPtr);
		//poly.push_back(new Person(name));
	}

	for (Person* pp : poly){
		pp->display();
		cout << pp << endl;
		delete pp;
	}
	system("pause");
}

