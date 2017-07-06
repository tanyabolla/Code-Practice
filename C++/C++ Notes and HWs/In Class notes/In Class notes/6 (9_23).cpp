#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//If they are primitive, leave it be if no info is provided as to what to do
//If they are non primitive, it puts random bits inside

//Avoid global variables - since any function in the whole file can get changed and takes hours to debug
//Once data hiding and encapsulation has been implemented, convention has it that you call it a class not a struct
//There's a possiblity of defining the Date class inside of the Person class but not in this class *not required
class Date{
public:
	Date(const int& theDay, int theMonth, int theYear) : day(theDay), month(theMonth), year(theYear) {}
	//void display() const {
		//cout << "Date of Birth: " << month << "/" << day << "/" << year << endl;
		//display(cout);
	//}
	void display(ostream& os = cout) const {
		os << "Date of Birth: " << month << "/" << day << "/" << year << endl;
	}
	//overloaded the display function
	//But two functions, take too long, more possiblity for error
	//Can just use it this way
	//But don't want parameters
	//Default parameter value - If you don't provide a parameter and allow for a default, state ostream& os = cout
private:
	int day;
	int month;
	int year;
};

class Person{
	//If you don't say anything such as private and public, automatically struct would make it public, class would make it private
	//Person::Person() - in the person class :: this function etc...
	//System automatically uses a default constructor
	//If you create a constructor to any extent, system automatically uses that instead
public:
	//Can have mutliple constructors
	//Can have mulitple functions of the same name - function overloading
	//Default constructor
	//Person(){} //no need to write
	//Constructor
	//If you have field that's not primitive, it needs to get initialized in the initialization list and has to use that type's default constructor
	Person(const string& theName, int someAge, int day, int month, int year) 
		: name(theName), age(someAge), //Initialization list
		dob(day, month, year) //uses the Date constructor
		{} 
		//Order matters in initialization list - order in which they are created in the private part of the class
	void display() const { //Improved using the keyword const
		//it's technically telling the compiler that no information will be changed since there are no parameters
		//Marking the whole method const
		cout << "Person: " << name << ", Age: " << age;
		dob.display(); //Delegating the task to the date class; you have the info, so do it instead getting the information using getters
		cout << endl;
	}
	//Setter or Mutator
	//john.setName("John");
	void setName(const string& theName){
		name = theName;
	}
private: //only methods/code in the class will have access, no one outside can touch it - Data hiding
	//Safety - can't change values in the attributes
	//allow you (developer) to change your mind as to how you represent an attribute
	string name;
	int age;
	Date dob; //date class with dob object
	//Data hiding - make a lot of changes to your code so it works
};

void displayPerson(const Person& aPerson){
	aPerson.display(); //works if the originial function in the class/struct provides certainity that the
	//information will not be changed
	//const keyword is used to give that certainity
	//In the class, the display function is defined as void display() const {...}, the const is placed between ) const {
}

int main(){
	//What is encapsulation?
	//Storing the functions along with attributes together within a type definition

	//Person john; //create a instance of person; it's uninitialized - empty string, random bits
	Person john("John", 42, 7, 14, 1990); //Create an object named john of type person with initialized attributes of name "John" and age 42
	john.display();

	//Person mary; //- for a default constructor
	Person mary("Mary", 28, 8, 31, 1989);

	ofstream ofs("someFileName.txt");
	Date someDate(2, 14, 1980);
	someDate.display();
	system("pause");
}