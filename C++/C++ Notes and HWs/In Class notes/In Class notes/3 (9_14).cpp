#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib> //includes exit(1); NULL; etc.
using namespace std;
//Structs, objects, vector of objects

//Struct - defining types
//Type and it has attributes
//Example: Tree
struct Tree{ //similar to variable name, starts with capital letter (convention)
	//Information about a tree -- attributes
	int age; //# of ratons (rings)
	string climate;
	//Tree myBaby; infinite loop/recursive
};//semi-colon

void displayTree(const Tree& theTree){ //Passing in a tree
	//parameter/object is pass by constant reference - because we don't want it to be a copy
	cout << "Age: " << theTree.age << ", Climate: " << theTree.climate << endl;
	//theTree.age so the compiler know which tree and which attribute we are looking for
}

void addTrees(ifstream& ifs, vector<Tree>& forest){ //pass by reference
	//ifstream is always pass by reference - pass by value won't compile
	//streams can't be copied - they only wanted one variable that has the open file
	//they being the ones who wrote the fstream library
	int theAge;
	int theClimate;
	while (ifs >> theAge >> theClimate){ //order matters
		//If climate was tried to cin first, read fails and loop fails 
		//Only continues to work if it is in the right order and works
		Tree addTree; //creates an object
		addTree.age = theAge; //initializes the attributes
		addTree.climate = theClimate;
		forest.push_back(addTree); //pushes back the object into a vector
		//forest was pass by reference, it will modify the vector and not copy it
		//or the trees will get deleted at the end of this funciton
	}
}

int main(){
	//Vectors
	//Syntax - vector<dataType> vectorName;
	//can only store values of one data type - homogenous
	//Index - []square bracket operator; can access, print and change values in the vector
	//.at() - index of vector, promises to test if it is in bounds, sqaure brackets don't test 
	//.at() - throws an exception if it fails the test of bounds/range
	//Pass by refernce since a vector is non primitive - when they are function parameters
	//.push_back(value) - grows the size of vector; it's not a predetermined size; pushes in the value onto the end
	//.pop_back() - no arguments; deletes the last item on the vector
	//To get rid of something in the middle of the vector, loop through the values after the chosen value to delete,
	//then move them up one and pop_back() the last item (which is a duplicate of the previous one now)
	//.size() - size of vector
	//v[v.size()] - WRONG!!! - .size() gives the number of elements in a vector and index starts at position 0
	//so there are v.size() - 1 elements so we are going out of bounds with the v[v.size()]
	//v[v.size()-1] = v.back() CORRECT!!!

	//Create this variable outside, if you want it to stay past the scope of the for loop
	size_t i;
	for (i = 0; i < 100; i++){
		cout << i << endl; 
	}

	//What is size_t?
	//.size() method return a size_t
	//In a for loop, when i is tested, it returns an unsigned value and size_t morphs into whatever is returned
	//It is not always unsigned; changes from compiler to compiler, goes out of bounds, etc.
	//If it's int, the byte size of the int changes from system to system such as 1-bit, 32-bit, 64-bit.
	//size_t prevents the issue of overflow

	//Pass by value, pass by reference, pass by constant reference (Lecture 2)
	//Type is void if it isn't returning anything
	//Uninitialized value => garbage
	//Primitive doesn't initialize the value itself
	//If it's primitive, pass by value is fine

	Tree fred; //an instance of the type tree - object
	//have a tree named fred - object
	//We now have a tree, a real virtual one.
	displayTree(fred); //pass the object tree as a parameter
	//Age - prints out random bits that were sitting in there since it wasn't initialized; 
	//it didn't decide to do it (random), nobody did anything to make it print that number so can't say randomly initialized
	//Climates - nothing prints out after climate (empty string)
	//because it's the difference between primitives (built-in type) and non-primitives (some way in which they initialize themselves)
	//int age is a primitive - garbage values/uninitialized memory
	//string climate is a non primitive - initialized

	//initialize attributes of types
	fred.age = 100; //dot operator to refer to an attribute of a specific type
	fred.climate = "Tropical";

	//Collection of trees (Objects)
	vector<Tree> forest; //homogenous - need to give a data type, vector of trees
	
	//Add fred to the forest
	forest.push_back(fred); //makes a copy (pass by value)
	displayTree(forest[0]); //can do a for loop for multiple trees

	fred.age = 200; //when fred's age is changed
	displayTree(fred); //will print 200
	displayTree(forest[0]); //still prints 100 since it's pass by value (makes a copy)

	//Get some trees from a file
	ifstream ifs("trees.txt");

	//Another way of writing it
	//ifstream ifs;
	//ifs.open("trees.txt");

	//Check to see if it exists
	if (!ifs){
		cerr << "File doesn't exist!" << endl;
		exit(1);
	}

	//Can put this in a function
	int theAge;
	int theClimate;
	while (ifs >> theAge >> theClimate){ //order matters
		//If climate was tried to cin first, read fails and loop fails 
		//Only continues to work if it is in the right order and works
		Tree addTree;
		addTree.age = theAge;
		addTree.climate = theClimate;
		forest.push_back(addTree);
	}
	addTrees(ifs, forest);
	ifs.close(); //close the file as soon as you are done with it

	for (const Tree& trees : forest){
		displayTree(trees);
	}
	system("pause");
}