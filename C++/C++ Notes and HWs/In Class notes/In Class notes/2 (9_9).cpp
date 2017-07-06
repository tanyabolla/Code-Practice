#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
//Functions, collections/containers, define types
//vectors, foreach/ranged for loops, size_t, 
//pass by value, pass by reference, and pass by constant reference

//Most programmers don't want functions to be before main to prevent clutter and readability
//Prototype - name and type of a function before the main
void addOne(int someInt);
int addOneReturning(int someInt);
void addOneByReference(int& x);
void printString(const string& s);

int main(){
	//Array - simplistic; cannot change size once it's established; continuous memory
	//When passed, the array doesn't know how many elements it has - makes them obsolete
	//Vectors are prefered - major aspects we have to have
	//As long as there are no graphics, vectors could be used - unimportant for this class

	//vector v; //not primitive - growing and shrinking, etc, so library is needed
	//^undefined - need to define a type of stuff that are in there
	//the data type is vector
	//vectors can hold only one type of data- homogenous
	//unlike lists in python where a list can hold multiple types of data such as ints, strings, objects - heterogenous
	vector<string> v; //not a potential reference to a vector, will work like in Java

	//Prints out size
	cout << v.size() << endl; //will work, will print 0
	//Nothing is pushed back and since 0 items are in the vectors, prints out 0
	//Array list wouldn't compile because you haven't stated the size

	//Vectors are easy to grow, by pushing things on to the END using push_back
	v.push_back("some string");
	//copies the input and puts it in there by growing the vector
	//COPIES - important
	v.push_back("some other string");

	//Square brackets used to access elements inside the vector
	//Print out a specific vector element
	cout << v[0] << endl;
	//Java creator - Gossling - didn't want the ability to overload operators in his language so can't use square brackets
	//Overloading operators - can overload for a non primitive types, things that weren't already defined.
	//Can change the meaning of + for objects in a class, can't change it outside of class though.
	//Provide different meaning for operators as in they can be made to do other things

	//Loop to print out all the elements in a vector
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}

	//Signed or unsigned?
	//Warnings are to be avoided; get rid of as many warnings are possible so the important ones stick out
	//.size() doesn't return an int type because half the values in int aren't useful since they are negative
	//some computer have ints, some have unsigned, some give doubles - depends on compiler, OS
	//.size() method returns unsinged int on this computer
	//use size_t - it will match whatever the type is given/appropiate type
	for (size_t index = 0; index < v.size(); index++){
		cout << v[index] << endl;
		//index is an artifact, has no connection with the vector
		//v[index] = "string"; //pass by reference - has the ability to modify the value
	}

	//Ranged for/foreach loop
	//Short and to the point
	//for(dataTye variable : collectionName){}
	//loops through till the collection ends - don't have to state when it ends

	//Making a copy
	for (string s : v){ //for each string in v
		cout << s << endl;
		s = "Some garbage";
		//can't modify elements of the vector, since it is a copy and will get destroyed as it goes out of scope at the end of the loop
	}
	//However, it copies each element into s then printing it. Copying takes a lot of TIME and makes it slow.
	//TIME IS MONEY!!!
	
	//OPTIMIZE
	//Do not optimize prematurely - correctness comes first vs readability
	for (string& s : v){ //pass-by-reference - avoids the copy
		cout << s << endl;
		s = "Some garbage";
		//& - alias - says s is just another name (a reference)
		//since it's an alias, what's in the collection is changed 
		//and doesn't change back at the end of the for loop when it goes out of scope
	}

	//a reference that cannot be used to modify - pass-by-constant-reference
	for (const string& s : v){
		cout << s << endl;
		//s = "some garbage"; //<- will be flagged as an error
		//the const prevents anything from modifying the elements of the vector
	}

	cout << v[v.size()] << endl; //error! runtime error because it won't know the size till it runs --- don't know what's going to happen
	//Size 10: goes from 0-9, there is no v[10] element
	//Java throws an exception
	cout << v.at(v.size()) << endl; //no square brackets - does a test - takes time
	//Efficiency vs safe
	cout << v.back() << endl; //describes the last element since it was used to get the last element anyway
	
	//Delete an element
	v.pop_back(); //takes off the last element, reduces the size, no arguments
	//If you want to delete something from the middle of the vector, you have to move the next one to override the one you want to delete, 
	//till u reach the end of the vector and pop the last element
	
	//unsigned - all positive
	//signed - both positive and negative
	//automatically - signed

	//Calling functions
	int someInt = 42;
	addOne(someInt); //pass by value so does not modify the someInt value
	cout << someInt << endl; //prints 42
	//doesn't always have to catch an int
	someInt = addOneReturning(someInt); //returning and catching an int
	cout << someInt << endl; //prints 43, but only in the main
	addOneByReference(someInt); //pass-by-reference - modifies it everywhere
	cout << someInt << endl; //prints 44

	//Count up
	for (unsigned int i = 0; i < 10; ++i){
		cout << i << endl;
	}

	//Count down
	//for (unsigned int i = 9; i >=0; --i){ //possible to go into an infinite loop if it overflows and goes back to the highest value
	//since 0 is included
	for (unsigned int i = 10; i > 0; --i) {
		cout << i - 1 << endl;
	}
	system("pause");
}

//returnType functionName(parameters){ body }
void addOne(int someInt){ //pass-by-value - the copy gets modified, not the original
	++someInt;
} //end of scope

int addOneReturning(int someInt){
	++someInt;
	return someInt;
}

void addOneByReference(int& x) { // pass-by-reference - alias - modifies it
	++x;
}

//Pass by value of something big
//Change it to pass by reference however, the string s can be modified by mistake
//Pass by constant reference prevents it from being changed in that function
void printString(const string& s){ //Pass by constant-reference
	cout << s << endl;
	//s = "some garbage"; //compilation error
}