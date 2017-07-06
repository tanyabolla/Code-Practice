#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//Inheritance

//Three classes that have similar attributes and fuctions
//Inheritance - taking those commanalities and creating a class
//Base/Parent class - main class with the common attributes
//Derived/Child class - classes that use the attributes and methods from the parent class
//ISA relationship - Cat is a Pet

class Pet{
public:
	//Purpose of Inheritance - Code Reuse
	//All the derived class inherits the interface of the base class
	//Derived classes inherit the methods and are available to use
	//Dervied classes want to do their own thing sometimes
	virtual void display() const { cout << "Pet" << endl; } //override
	//Polymorphism - less efficient, but better program
	virtual void eat() {} //override with virutal
private:
};

class Cat : public Pet{ //Syntax to become a derived class
	//: public because when derived it makes everything in the class essentially private
public:
	void display() const { cout << "Cat" << endl; } //override
	void eat() { cout << "Cat eating\n"; } //override
private:
};

class Slug : public Pet {
public:
private:
};

class Roach : public Pet {
public:
private:
};

void displayAPet(const Pet& aPet){
	aPet.display();
	//Prints pet both times
	//When this function is called, and the parameter is a Pet, felix is considered a pet and pet's display is called
	//GETS THE FASTEST POSSIBLE FUNCTION
	//Default call needed to be efficient, so it waits till runtime to call
	//compiler doesn't know which method, looks at the class of the parameter
}

int main(){
	Pet peeve;
	peeve.display(); //prints Pet
	Cat felix;
	felix.display(); //prints Cat - since calling the display function of Cat class - no need for virtual
	//If Cat doesn't have a display method, the Pet display method will be used
	cout << "==================" << endl;

	displayAPet(peeve); //prints Pet
	displayAPet(felix); //prints Pet, even when overridden (there is a display method in Cat)
	//Principle of subtitutability - even though the base class was passed in, if the parameter is of a derived class, it will still work
	//but it won't use the display method of Cat, it will use the display method of Pet
	cout << "==================" << endl;

	//Polymorphism - virtual keyword
	//Figure out what to call because originially just calls the base class' methods
	//Polymorphism - call it at runtime instead of at compile time
	//Will make it slower, use the keyword virtual - take that extra second to get the right one

	//If I want to copy a Cat into a Pet, Pet is smaller cuz Cat has Pet info and it's own info.
	//Slicing Problem
	vector<Pet> menagerie;
	menagerie.push_back(peeve);
	menagerie.push_back(felix); //push_back copies and it's a collection of pet objects so smaller
	for (size_t i = 0; i < menagerie.size(); i++){
		menagerie[i].display(); //slicing problem
		//Since it's a vector of pets, everything is going to get copied into the pet class
		//derived to base and since everything doesn't fit, it gets sliced.
		//happening at push_back - copies using pass by value
	}

	cout << "====================" << endl;
	vector<Pet*> menageriePtr; //collection of base pointers
	menageriePtr.push_back(&peeve);
	menageriePtr.push_back(&felix);
	for (size_t i = 0; i < menageriePtr.size(); i++){
		menageriePtr[i]->display();
	}
	//vector<Pet&> menagerieRef; doesn't work

	//Dangling pointer
	//Thing* tp = new Thing;
	//delete tp;
	//What happens to tp?
	//Nothing - it is still pointing to the memory address but there is nothing there
	//tp = nullptr; gets your through the logical error
	//pop_back the tp if it's in a vector, then .clear() the vector to remove everything 
	//as not to refer to it accidentally in the future
	system("pause");
}