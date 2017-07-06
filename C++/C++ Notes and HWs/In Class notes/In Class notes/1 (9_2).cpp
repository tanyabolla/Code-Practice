#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
//Input/output stream
//Conditionals
//Loops
//Functions
//Methods
//Defining types such as classes, structs
//Vectors/collections, etc.
//Types - int, bool, char, double, long long, float, etc.

//Functional programming??
//Bjarne Stroustrap - creator of C++

int N = 100; //GLOBAL VARIABLES ARE BAD!!!
//Can be seen from everywhere
//Global constants are ok to use

int main(){
	//Python specs:
	//Far more flexible and interactive
	//Don't have to define the type for variables
	//No semi-colons at the end of statements
	//Indentation matters

	//C++ specs:
	//Uses semi-colons at the end of statements
	//Indentation doesn't matter
	//Everything you define has a data type
	//Define the type of the variable before the variable name
	//Primitives - int, double, char, bool
	//Can't store anything else in that variable other than that type
	//Functions have return types
	//Parameters in functions have to have a data type and the passed in value has to 
	//match the data type of the parameter

	//C++ is more efficient, uses a compiler instead of an interpreter
	//Error checking - stating data type will make sure that the variable contains the
	//right value type to an extent and also if you try to assign a value to a variable
	//that doesn't exist, it will throw a compile time error

	//int main(){ return 0; } //Simple program
	//int main(){} - simplest program
	//Stroustrap hard-coded that return 0 into the compiler since it has to be present in every program

	//cout - standard output stream or console output
	//cout << string is going that direction; it is going into the cout
	//Won't work without qualifying std:: or using namespace std;
	//endl - same thing as new line
	cout << "Hello, world!\n";

	int x = 17; //Define a variable and assign a value to the variable
	cout << x << endl; //<< chaining/concatenation
	//use double instead of float since float has half the bytes size (same as int) and less accuracy
	//char - to store one character

	//Primitives - int, char, bool, double - already defined

	//string - fundamentally different
	//other types such as int, double relate to the hardware
	//hardware recognizes these types unlike string - primitives
	//you need a library, and qualify std::
	//not primitive

	//cout wasn't defined anywhere - include header file
	//#include <iostream> - cout defined here
	//meaning of << is also defined in iostream library
	//cout is a short name for the standard output stream
	//Has a long name such as John sterling. Like in a playground, to uniquely identify 
	//full name of cout is std::cout - qualifying cout with its namespace
	//all these are in the std namespace
	//type using namespace std; to avoid typing std:: all the time to qualify

	//string is in the standard namespace as well
	//double quotes for strings
	//single quotes for char

	//Primitive types include int, double, bool, char
	//unsigned - only positives
	//signed - negatives and positives, usually signed

	//Have meaningful variable names

	string s;
	s = "I'm a string!";
	cout << s << endl;

	//Standard input stream
	cin >> s;
	//Skips whitespace and gets to the string and stops when it hits whitespace

	//= assignment operator
	//== equality operator

	//Conditionals
	//if (x = someFunction()) {} Legal because of boolean
	//if (x = 42) { // WRONG!!!
	if (x == 42) {
		cout << "That's the answer!\n";
	}
	else if (s == "a different string") {
		cout << s << endl;
	}
	else {
		cout << "Not the answer" << endl;
	}

	//for and while loops
	//for(initialization, test, increment/decrement){}
	for (int counter = 0; counter < 10; ++counter) {
		cout << counter << endl;
	}
	//Scope of the counter is from the initialization to the ending of the for loop
	//the  counter < 10 is a test, is it less than 10?

	int anotherCounter = 0;
	while (anotherCounter < 10) {
		cout << anotherCounter << endl;
		++anotherCounter; //Pre-increment
	} //Scope of counter is all of main

	//int y = 5;
	////Pre-increment - by value
	//int a = 10;
	//a = ++y;
	//cout << a << endl; //prints 6
	//cout << y << endl; //prints 6
	////Post-increment - by reference
	//a = y++;
	//cout << a << endl; //prints 10 since it increments after it stores it in a and stores in y
	//cout << y << endl; //prints 6

	//File I/O
	//Read or write files
	//stream associated with reading and writing files
	//library fstream

	ifstream ifs("jabberwocky"); //open file
	if (!ifs) {
		cerr << "Couldn't open jabberwocky\n"; //cerr - standard error
		exit(1);
	}

	ifs >> s; //>> direction of arrow shows where it is going into
	//gets the first word and stores it in s; skips all whitespace till it gets to the string
	cout << s << endl; //prints it out

	//Loops through the whole file instead of just one word
	while (ifs >> s) { //till you reach the end of the file, keep looping
		cout << s << endl; //prints the whole file
	}
	ifs.close(); //closes the file

	cout << "=============\n";
	ifs.open("jabberwocky"); //reopen the file to reset to the beginning
	//Once it loops through the whole file, it stays at the end
	//One way to go back to the top is to close the file then reopen it

	char c; //skips all whitespace and gets one character
	while (ifs >> c) {
		cout << c; //prints character by character
	}
	ifs.close();

	//ifs automatically skips all whitespace.
	//in order to not skip whitespace, ifs >> noskipws;
	//to change it back to skip whitespace, ifs >> skipws;
	cout << "=============\n";
	ifs.open("jabberwocky");
	ifs >> noskipws; //using this will not skip whitespace
	while (ifs >> c) {
		cout << c; 
	}
	ifs.close();

	cout << "=============\n";
	ifs.open("jabberwocky");

	//Keyword: getline(ifs, variable string)
	while (getline(ifs, s)) { //inputs the whole line of the file into the s variable
		//prints out the whole line
		cout << s << endl;
	}
	ifs.close();
	system("pause");
}