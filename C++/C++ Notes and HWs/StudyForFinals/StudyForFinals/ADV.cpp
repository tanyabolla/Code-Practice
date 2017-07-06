#include <iostream> //preprocessor directive
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Employee{ //Just a declaration, no memory allocated
	//Members(fields)
	short id;
	int age;
	double wage;
};
class Date{
public:
	//Member functions/methods
	void SetDate(int nMonth, int nDay, int nYear)
	{
		m_nMonth = nMonth;
		m_nDay = nDay;
		m_nYear = nYear;
	}
private:
	int m_nMonth;
	int m_nDay;
	int m_nYear;
};
int factorial(int n){
	if (n == 1) return 1; //base case - ending point to terminate the process
	return n * factorial(n - 1);
}
void printInformation(Employee employee);
int main(){
	//Structs
	//There are many instances in programming where we need more than one variable 
	//in order to represent an object.For example, to represent yourself, you might want 
	//to store your name, your birthday, your height, your weight, or any other number of 
	//characteristics about yourself.

	/*string myName;
	int myBirthYear;
	int myBirthMonth;
	int myBirthDay;
	int myHeightInches;
	int myWeightPounds;*/

	//But they are independent - separate - not related
	//Aggregate data type - groups bunch of variables together. Ex: Structs

	//Struct Person
	Employee joe; //memory is allocated after it is defined as joe is a definition
	//Joe refers to the whole struct which contains member variables
	//Member selection operator (.) is used to access the individual members
	joe.id = 12;
	joe.age = 32;
	joe.wage = 35.90;
	//member variables are not intialized, must be initialized

	Employee frank;
	frank.id = 11;
	frank.age = 40;
	frank.wage = 40.90;

	if (joe.wage > frank.wage){
		cout << "Joe makes more than Frank" << endl;
	}
	else{
		cout << "Frank makes more than Joe" << endl;
	}

	//Initializer list - define faster
	//Employee joe = { 14, 32, 24.15 };
	//Employee frank = { 15, 28, 18.27 };
	// Print Joe's information
	printInformation(joe);
	cout << "\n";
	// Print Frank's information
	printInformation(frank);

	//can have a return type of struct
	/*Point3d getZeroPoint()
	{
		Point3d temp = { 0.0, 0.0, 0.0 };
		return temp;
	}*/
	//Point3d zero = getZeroPoint();

	//Can nest structs
	//struct Company
	//{
	//	Employee CEO; // Employee is a struct within the Company struct
	//	int numberOfEmployees;
	//};
	//Company myCompany;

	//Type conversion - process of converting a value from one data type to another
	float a = 3;
	//3 is first converted into a float then assigned
	//Implicit type conversion (coercion) - when the compiler does it for you

	//Numeric Promotion - oen type is converted into a vlaue of a larger data type
	//Ex: int to long
	//Integral Promotion - smaller to int. Ex: char, bool, short to int
	//Floating point promotion - float to double
	//Promotions make sure memory isn't lost

	//Numeric conversions - larger to smaller/diff data types - may result in loss of data
	int i = 30000;
	char c = i;
	std::cout << static_cast<int>(c) << endl;

	//Explicit type conversion - developer uses a casting operator to direct the conversion
	//int i1 = 10;
	//int i2 = 4;
	//float f = i1 / i2; //uses integer division instead of float point division
	//The answer is 2 then it is assigned to float so it becomes 2.0
	//cast - explicit request by the user to do a type conversion
	//C-style casts //avoid - misues of const, etc
	//int i1 = 10;
	//int i2 = 4;
	//float f = float(i1) / i2;
	//Static casts
	int i1 = 10;
	int i2 = 4;
	float f = static_cast<float>(i1) / i2;

	//Arrays - aggregate data type that lets you access 
	//multiple variables through a single name by use of an index
	/*int nTestScoreStudent1;
	int nTestScoreStudent2;
	int nTestScoreStudent3;*/
	// ...
	//int nTestScoreStudent30;

	int anTestScores[30]; // allocate 30 integers, each variable is an element (30 elements)
	//[] subscript operator - tells the compileer how many variables to allocate
	//use index to get the variable we want
	anTestScores[0] = 78;
	anTestScores[1] = 89;
	anTestScores[2] = 88;
	anTestScores[3] = 68;

	//Assign size of an array later
	const int arraySize = 5;
	int aArray[arraySize];
	//arrays can hold structs
	Employee asArray[5];
	asArray[0].wage = 24;

	//Initializing arrays
	int anArray[5] = { 3, 2, 7, 5, 8 }; //initializer list
	cout << anArray[0] << endl;
	cout << anArray[1] << endl;
	cout << anArray[2] << endl;
	cout << anArray[3] << endl;
	cout << anArray[4] << endl;
	//when all are not initialized in a list, 0 is assigned to the remaining ones
	//int anArray[5] = {0}; to assign 0 to all
	//int anArray[] = {0, 1, 2, 3, 4}; //size is inputted by the compiler
	//Arrays using loops

	int afArray[5] = { 9, 7, 5, 3, 1 };
	cout << *(afArray + 1) << endl; // prints 7

	//Dynamic memory allocation
	//don't know how big/how many
	//we can't determine the size at compile time
	//Dynamic memory allocation allows us to allocate memory of whatever size we want 
	//when we need it.
	int* pnValue = new int; // dynamically allocate an integer
	//The new operator returns the address of the variable that has been allocated. 
	//This address can be stored in a pointer, and the pointer can then be dereferenced 
	//to access the variable.
	*pnValue = 7;
	cout << pnValue << endl;
	cout << *pnValue << endl;
	delete pnValue; // unallocate memory assigned to pnValue
	//It doesn't delete the pointer (it is still pointing to that location), it just 
	//deletes the memory. The memory is up for use but there's a pointer at it.
	pnValue = 0;

	int nSize = 12;
	int *psArray = new int[nSize]; // note: nSize does not need to be constant!
	psArray[4] = 7;
	delete[] psArray; //indicates multiple deletes rather than one

	//Memory Leaks
	int nValue = 5;
	int *plValue = new int;
	plValue = &nValue; // old address lost, memory leak results

	int *pkValue = new int;
	pkValue = new int; // old address lost, memory leak results
	//set the value to 0 after deleting - not a good idea to leave a pointer pointing to 
	//deallocated memory

	Date date;
	date.SetDate(5, 14, 2015);
	//In C++, when we declare a variable of a class, we call it instantiating the class.
	//The variable itself is called an instance of the class.A variable of a class type 
	//is also called an object.

	//Public members are members of a struct or class that can be accessed by any 
	//function in the program.
	//Private members are members of a class that can only be accessed by other 
	//functions within the class.
	//Class member variables are automatically private.

	//Access Functions - short public function whose job is to return the value of a private.
	//Setters and getters
	//Getters simply return the value of a private member variable. -has a return type
	//Setters simply set the value of private member variable. - void, has a parameter

	//Encapsulation is the idea of hiding the details of how something is implemented and 
	//instead exposing an interface to the user. This allows the user to use the item without
	//having to worry about how it is implemented.

	//A constructor is a special kind of class member function that is executed when an 
	//object of that class is instantiated. Constructors are typically used to initialize 
	//member variables of the class to appropriate default values, or to allow the user 
	//to easily initialize those member variables to whatever values are desired.

	// Allocate a Simple on the stack
	//Simple cSimple(1);
	//cout << cSimple.GetID() << endl;

	// Allocate a Simple dynamically
	//Simple *pSimple = new Simple(2);
	//cout << pSimple->GetID() << endl;
	//delete pSimple;
	
	cout << factorial(7) << endl;

	//Files/ I/O


	system("pause");
}
void printInformation(Employee employee)
{
	std::cout << "ID:   " << employee.id << "\n";
	std::cout << "Age:  " << employee.age << "\n";
	std::cout << "Wage: " << employee.wage << "\n";
}
void doSomething()
{
	//Dynamically allocated memory effectively has no scope.That is, it stays allocated 
	//until it is explicitly deallocated or until the program ends.
	int *pnValue = new int; //value is created, memory allocated
	delete pnValue; //memory deleted
} //pnValue goes out of scope at the end of function and pointer is deleted
//Because pnValue is the only variable holding the address of the dynamically allocated 
//integer, when pnValue is destroyed there are no more references to the dynamically 
//allocated memory. This is called a memory leak. As a result, the dynamically allocated 
//integer can not be deleted, and thus can not be reallocated or reused.
