#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//What is OOP?
//have their own functions such as push_back(), I/O stream, etc.
//setters/getter or accessors/mutators
//Structs just have attributes, no functions/methods
//model - dragon/catapults, SIMS, heart/physiology

//Encapsulation - binds together functions and attributes that manipulate data, protected from outside code
//Polymorphism - Inheritance
//Data hiding - protect variables from being used by other classes/code, only methods inside of the class can change/use the attributes

//Encapsulation - Instead of passing john into a function, we can do something like john.display() such as a size method, etc
//Implement a display function inside of the class

struct Person{
private: //access marker
	//In what order you place here, will be done first, so name will be initialized first then age
	//And if one of the variables depends on another one and it gets initialized later, could throw you into a tailspin - warning not error
	string name;
	int age;
	//put private below public
public:
	//Constructor
	//no return type
	//Constructor has to be the name of the class or it won't work or compile
	//sets it to an empty string then initializes
	//Setters and constructors aren't the same
	//Constructors are initializing by setting it into an empty string then assigning the name to the name variable and this all happens in between
	//the ){  
	//We can change that making our own initialization list
	//Since it's initalizing then redoing it - too much time
	//Efficiency - intiliaze it with a colon in between the ){
	Person(const string& theName, int someAge) : name(theName), age(someAge) { //avoided the empty string part and initialization list
		//initilazing things correctly and preventing undoing of work
		//name = theName;
		//age = someAge; //if you put this line here, nothing is getting undone since nothing was initialized in the first place
		//If it's a primitive field, nothing gets done to it - random bits/numbers will get printed - garbage
		//Primitives don't get intialized by default
	}
	//Display can't be private, can't call it in the main
	//Method/member function: function is inside the class/struct
	void display() const { //Don't need a parameter, need to improve
		cout << "Person: " << name << ", Age: " << age << endl;
		//Function defined inside the type
	}

	//Setter or Mutator
	//john.setName("John");
	void setName(const string& theName){
		name = theName;
	}
	//function defined inside a type that is dealing is with things inside of the type - OOP
};

//This function is not allowed to modify due to const
//The method doesn't have anything being protected
//The function below is better - const would've made it a compilation error to change any of the information
//void displayPerson(const Person& aPerson){ //aPerson is just a paramter, name doesn't matter
//	cout << "Person: " << aPerson.name << endl;
//}
void displayPerson(const Person& aPerson){ //aPerson is just a paramter, name doesn't matter
	aPerson.display(); //compilation error - since it's not const in the .display() so there needs to be const there 
	//where to put the const - can't do it before the return type, no parameters so can't do it there
	//Put the key word between ){ to promise not to modify the information
}

//Data Hiding - preventing variables/fields being directly accessible to anything outside the class
//Some are private, some are public
//Only code from the person class can access or modify the information in the attribute string name in Person
//Protect data from other code
//If something goes wrong, debugging is easier and information recovery
//Gives you flexibility
//Since it's prevented from being modified, do you have to initalize from the beginning??

int main(){
	//Person john;
	//john.name = "John"; //accessing a private attribute here
	//Define a public function that has access to that function and name it - setters and getters/ mutators and accessors
	//displayPerson(john);
	//john.display(); //displaying is a behavior
	//.display() is being called on a particular person (object) so no need to pass in as a parameter
	//john.setName("John"); //Before u do setName, calling display will give you a empty string - therapy - 
	//use a constructor to prevent that since you have to set it 
	Person john("John", 42); //have to initialize since it has a constructor
	john.display();
	system("pause");
}