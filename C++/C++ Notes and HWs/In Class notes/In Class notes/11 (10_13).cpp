#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//Inheritance continued

//Inheritance - code reuse
//Polymorphism - when you don't want to use code reuse

class Pet{
public:
	//Constructors aren't methods - each dervied class needs to have a constructor
	Pet(const string& name) : name(name) {} //good for peeve but not for felix
	virtual void display() const { cout << "Pet" << endl; }
	virtual void eat() {} //make it abstract
	//Even if each of the derived classes has a different eat method, it needs to exist in the base class
	//Now, all derived class have a display and eat method - reduces errors if you do no want to forget the eat method in any derived class
	string getName() const { return name; } //but this has given access to everybody
protected:
	//2. Provide access to derived classes but no other classes
	string getName() const { return name; }
private:
	string name;
};

class Cat : public Pet{ 
public:
	//Constructors aren't inherited since they aren't methods
	//Cat(const string& name) : name(name) {} //you don't have the private variable name - Pet class has it
	//Call the base class and ask it to initialize the variable
	Cat(const string& name) : Pet(name) {}
	//calls the default constructor of Pet class - whether you write it in the initializatiion list or not
	//if you write it or not, it calls the default constructor of the parent class
	void display() const {
		cout << "Cat" << getName() << endl; //have no way to access private variables, so have to use a getter
		//1. To bypass using getters, we can call the display method of the base class
		cout << "Cat ";
		Pet::display();
		cout << endl;

	}
	void eat() { cout << "Cat eating\n"; } //override
private:
};

class Slug : public Pet {
public:
	void eat() { cout << "Slug eating\n"; } //override
private:
}; 

class Roach : public Pet {
public:
	void eat() { cout << "Roach eating\n"; } //override
private:
};

//Principle of subtitutability - even though the base class was passed in, if the parameter is of a derived class, it will still work
void displayAPet(const Pet& aPet){
	//void displayAPet(Pet aPet){
	//Polymorphism is broken if pass by value is used
	//when that call is made, it copies felix into pet and causes the slicing problem
	aPet.display();
}

int main(){
	Pet peeve("Peeve");
	peeve.display(); //prints Pet
	Cat felix("Felix");
	felix.display(); //prints Cat - since calling the display function of Cat class - no need for virtual
	cout << "==================" << endl;

	displayAPet(peeve); //prints Pet
	displayAPet(felix); //prints Pet, even when overridden
	//Principle of subtitutability - even though the base class was passed in, if the parameter is of a derived class, it will still work
	cout << "==================" << endl;

	cout << "====================" << endl;
	vector<Pet*> menageriePtr;
	menageriePtr.push_back(&peeve);
	menageriePtr.push_back(&felix);
	for (size_t i = 0; i < menageriePtr.size(); i++){
		menageriePtr[i]->display();
	}
	//vector<Pet&> menagerieRef; doesn't work

	for (Pet* pp : menageriePtr){
		pp->eat();
		//Even if each of the derived classes has a different eat method, it needs to exist in the base class
		//now, all derived class have a display and eat method - reduces errors if you do no want to forget the eat method in any derived class
	}

	//peeve = felix; //Slicing problem
	//felix = peeve; //Compilation error!

	system("pause");
}