//#include <iostream> //preprocessor directive
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cmath>
//using namespace std;
//
////Function Prototypes
//void doPrint();
//int return5();
//int getValueFromUser();
//int add(int x, int y);
//
//int main(){
//	//Object Oriented Programming
//
//	//Structure of a Program
//	//Statements and Expressions
//	//Statement is a sentence, smallest independent unit, terminated by a semicolon.
//	int x; //declaration statement
//	x = 5; //assignment statement
//	cout << x << endl; //output statement
//	//Expressions - mathematical entity that evaluates to a value
//	x = 2 + 3;
//	cout << x << endl;
//	x = x + 5;
//	cout << x << endl;
//	//The expression is evaluated and then assigned to the variable
//
//	//Functions - a collection of statments that execute sequentially
//	//Every program has to have a special function called main() because
//	//when run execution starts with the first statement in main()
//
//	//Libraries - collection of precompiled code, packaged up for reuse
//	//extend the abilities of your programs
//	//Declarations of libaries are called preprocessor directives ex: #include
//	//We are tellng the compiler to add the contents of the iostream header
//	
//	// << output operator - prints to the screen
//	// return statement - when a program stops running, main() sends a value back to the OS
//	// to indicate whether the program ran successfully or not
//
//	//Syntax error - violating syntactial (grammar) rules of C++
//
//	//Comments - text ignored by the compiler and provdies info about a program/function
//	//to a programmer that is reading it
//	/*Multi-line comment*/
//
//	//Variables - piece of memory used to store information, in RAM
//	//integer - 1, 2, 3, -1, -11112323324
//	int y; //declaration statement
//	//When this statement is executed by CPU, a piece of memory will be set aside - instantiation
//	y = 140; //When program sees y, goes to RAM and looks at the memory, then prints it
//	cout << y << endl;
//
//	int z;
//	z = 4;
//	z = 2 + 5;
//	int a;
//	a = z;
//	cout << a << endl;
//	a = a; //Useless!
//	a = a + 1;
//
//	//C++ does not initialize; variables are not automatically assigned the number 0
//	int b; //the default is whatever garbage happens to be in that location
//	//cout << b << endl; //give a compilation error
//	b = 12032830;
//	cout << b << endl;
//
//	//Concatenation
//	int c = 9;
//	cout << "C is equal to: " << c << endl;
//
//	//endl - newline character
//
//	//cin - >> - reads input from the user
//	int d = 0;
//	//cout << "Enter a number: ";
//	//cin >> d;
//	cout << "You entered: " << d << endl;
//
//	//std namespace
//	//Whenever we use something like cout that is part of the standard library, we need to 
//	//tell the compiler that it is inside the std library namespace
//	//OR
//	std::cout << "EYY" << std::endl;
//
//	//using declaration - tells the compiler that cout is in the standard namspace
//	//it assmues std::cout from there on forward whenever you use cout 
//	using std::cout;
//	cout << "EYY" << std::endl;
//
//	//using directive - tells the compiler that we are using everything in the std namespace
//	//using namespace std;
//
//	//Function - resuable sequence of statements desgined for a specific job
//	//Function call - tells the CPU to interrupt the current function and execute
//	//another function - puts a bookmark to do something else and comes ball
//
//	//calls - executes
//
//	//Example
//	cout << "In main()" << endl;
//	doPrint();
//	cout << "Back in main()" << endl;
//
//	//Functions you write also can have return values
//	//Return type is declared before the function's name
//	//int funcName(), etc
//	//Return type of void means the function does not return a value
//	//Return type of int means the function returns an integer value
//
//	//Example
//	cout << return5();
//	cout << endl;
//	cout << return5() + 2;
//	cout << endl;
//	//void functions will not compile with cout because they do not return anything
//
//	//Example
//	//int e = getValueFromUser(); // first call to getValueFromUser
//	//int f = getValueFromUser(); // second call to getValueFromUser
//	//cout << e << " + " << f << " = " << e + f << endl;
//
//	//Nested Functions - illegal; new functions cannot be defined within a function
//	
//	//Parameters - pass information into a function
//	cout << add(4, 5) << endl;
//	cout << add(4+3, 5*3) << endl;
//	int g = 99;
//	cout << add(g, g) << endl;
//	cout << add(4, add(g, g)) << endl;
//	//Looks at the first integer, then goes to the second integer spot, goes to the add func
//	//solves it, then returns the value and the returned value is assigned to int y
//	//Inner call then outer call
//
//	//Local Scope - scope determines who can see and use the variable during the time it is
//	//instantiated. Local variables are created at the top of the function and destroyed at
//	//the end of the function.
//	int h = 5; // a is initialized here
//	int i = 6; // b is initialized here
//	// a and b are usable within this function only
//	cout << add(h, i) << endl; // evaluates (5 + 6)
//
//	/*main() is executed
//	main’s variable a is created and given value 5
//	main’s variable b is created and given value 6
//	function add() is called with values 5 and 6 for parameters
//	add’s variable x is created and given value 5
//	add’s variable y is created and given value 6
//	operator + adds 5 and 6 to produce the value 11
//	add returns the value 11 to the caller(main)
//	add’s x and y are destroyed
//	main prints 11 to the console
//	main returns 0 to the operating system
//	main’s a and b are destroyed*/
//
//	//Identifier - the name of a variable, function, class, or other object in C++
//
//	//Literals - value that has been hardcoded into the source code
//	int j = 2; // j is a variable, 2 is a literal
//	cout << 3 + 4 << endl; // 3 + 4 is an expression, 3 and 4 are literals
//	cout << "Hello, world!" << endl; // "Hello, world" is a literal too
//
//	//Operators - +,-,*,/,%,=,==,!=
//	//Unary operators - ++, --, +=, -=
//	//Binary operator - two operands, 3 + 4, etc
//	//Ternary opeartors - one thernary operator
//
//	//A definition actually implements or 
//	//instantiates (causes memory to be allocated for) the identifier.
//	//Declaration - statement that defines an identifier
//
//	//Header files - As programs grow larger and larger(and include more files), 
//	//it becomes increasingly tedious to have to forward declare every function
//	//Header files put all the forward declarations in one place.
//	//.h extension
//	//#include "header.h" - quotes bc not given with the system/compiler
//	//Headers and libraries are run before the main and anything else - preprocessor
//
//	//Memory is organized into sequential units called addresses: 01101011
//	//Use data types to interpret the contents: int, double, etc.
//	//Fundamental data types - basic types, primitive types, built-in types
//	//Boolean - true or false
//	
//	//Defining variables
//	//bool bValue;
//	//char cValue;
//	//double dValue;
//
//	//Initialization - giving a value to a variable
//	//Explicit initialization
//	int k = 5;
//	//Implicit initialization
//	int l(5); 
//	//Assignment
//	int m;
//	m = 90;
//	//Defining multiple variables
//	//int n, o;
//	int p = 9, q = 0;
//	int r, s = 89; //wrong since r is uninitialized
//
//	//Void - no type; used in 2 instances: return type, no parameters
//	//void x; //can't define variables of type void
//
//	//Variable sizes are constricted and are determined by the data type
//	//sizeof determines the size of a data type
//	cout << sizeof(bool) << endl;
//	cout << sizeof(int) << endl;
//
//	//Integer type - holds integers
//	//Five types - char, short, int, long, long long
//	//Char (special) - holds characters and integers
//
//	//char c;
//	//short int si; // valid
//	//short s; // preferred
//	//int i;
//	//long int li; // valid
//	//long l; // preferred
//	//long long int lli; // valid
//	//long long ll; // preferred
//
//	//Signed integers - hold negative as well as positive
//	//unsigned integers - holds positive only
//
//	//Overflow occurs when bits are lost because enough memory hasn't been allocated
//	//Wraps around after overflow
//
//	//Integer division - results in a integer answer; in case of decimal, truncates down/fraction part gone
//	//Float - does decimal/fractions
//	bool b1 = true;
//	bool b2 = !false;
//	//boolaplha - prints true or false instead of 1, 0
//	//1 - true, 0 - false
//	//Operator== returns true if the operands are equal, and false if they are not
//	//== comparison operator
//
//	//Char - 1 byte, value interpreted as ASCII
//	char ch1(97); // initialize with integer 97
//	char ch2('a'); // initialize with code point for 'a' (97)
//	cout << ch1 << endl;
//	cout << ch2 << endl; //print the same thing
//
//	//Example
//	cout << "Input a keyboard character: ";
//	char ch;
//	cin >> ch;
//	cout << ch << " has ASCII code " << static_cast<int>(ch) << endl;
//	//static_cast<int> - changes the character into an int
//
//	//Escape characters
//	//Newline - \n
//	//Tab - \t
//	//Quotes - \' \" \\
//	//Alert - \a
//
//	//Single quotes - char
//	//Double quotes - string
//
//	//Symbolic constants - to keep variables from changing and shit
//	//const - keeps the variable constant; initialized when defined; 
//	//compilation error if changed or leaving it uninitialized
//	//allows for easy debugging, scope settings
//
//	//Operator precedence - operators have precedence/PEMDAS
//	//If the same precedence - associativity rules - left to right/right to left
//
//	//Arithmetic operators
//	//Unary - unary plus and unary minus (negative numbers)
//	//Binary - two operands; +,-,*,/,%
//	//Floating point division - 7.0/3, 7/3.0, 7.0/3.0 = 2.333
//	//static_cast<double>(x)/y - floating point division with integers
//	//Modulus - remainder; only int
//	//Arithmetic assignment operators - =,+=,-=,*=,/=,%=
//	x = x + 5;
//	cout << x << endl;
//	x += 5;
//	cout << x << endl;
//
//	int t = pow(8, 2); //8 = base, 2 = exponent
//	cout << t << endl;
//
//	//Increment/decrement
//	/*Prefix increment - ++x
//	Prefix decrement - --x
//	Postfix increment - x++
//	Postfix decrement - x--*/
//
//	int u = 9;
//	cout << u << endl;
//	int v = ++u;
//	cout << v << endl;
//
//	u = 43;
//	cout << u << endl;
//	v = u++;
//	cout << v << endl;
//	cout << u << endl;
//	//Side effects - has the effect of changing the value of the variable permanently
//	//Favors pre
//
//	//Relational Operators
//	//>,<,==,!=, <=, >=
//
//	//Logical Operators - !, &&, ||
//
//	//Block - group of statements {} - functions, if statements, loops, no semicolon
//	//blocks can be nested
//
//	//Local variables - created at the beginning of the block and deleted at the end
//	//Scope - where the variable is available
//	//Duration - where it is created and destroyed
//	//Block scope - accessible in a block
//	//int main() 
//		// outer block, n created here
//	//{
//	//	int n(5); // n initialized here
//
//	//	{ // begin nested block, d created here
//	//		double d(4.0); // d initialized here
//	//	} // d destroyed here
//
//	//	// d can not be used here because it was already destroyed!
//
//	//	return 0;
//	//} // n destroyed here
//	//Function parameters have block scope
//
//	//Global variables - static duration: created at the beginning of the program and destroyed
//	//when the program terminates. ---- global scope - any function can access it
//	//declared at the top of a file, below includes, and above any code
//	//local variables can be of the same name as global and :: before global variable to 
//	//indicate that we wish to use the global variable instead of the local one
//	//g_variableName - to indicate it's global
//	//Linkage - access in other files
//	//static g_...=...; - one files
//	//extern g_...=...; - other files
//	//extern g_...; - forward declaration
//
//	//Namespace defines an aread of code in which all identifiers are unique
//	//Everything usually belongs in the global namespace
//	//We can create our own namespace and it won't be in the global namespace
//	//namespace Foo
//	//{
//	//	// This doSomething() belongs to namespace Foo
//	//	int doSomething(int x, int y)
//	//	{
//	//		return x + y;
//	//	}
//	//}
//	//namespace Goo
//	//{
//	//	// This doSomething() belongs to namespace Goo
//	//	int doSomething(int x, int y)
//	//	{
//	//		return x - y;
//	//	}
//	//}
//	//cout << Foo::doSomething(4, 3) << endl;
//	//cout << Goo::doSomething(4, 3) << endl;
//
//	//Multiple namespace blocks with the same name allowed
//
//	//String - collection of sequential characters
//	string name; //built in data type
//
//	//Programs have sequential flow - top to bottom straight
//	//Control flow statements - CPU's path changes (if/else statements lol)
//	//halt - quits program - using exit()
//	//Jump - jumps to a statement
//	//Conditional Branch - change path of execution based on the value of a expression
//	//Example - if statement
//	//Loops - repeatedly execute a series of statements until condition isn't met anymore
//	//Example - while, do while, for loops
//	//Exceptions - jumps to a function that can catch the errors
//
//	//If the expression evalutes to true (non-zero), the statement executes. 
//	//If the expression evaluates to false, the else statement is executed if it exists.
//	if (a > b){
//		cout << "a is greater than b" << endl;
//	}
//	else{
//		cout << "b is greater than a" << endl;
//	}
//
//	//Switch statements - doing if-else chains on a single variable testing for equality 
//	//is so common
//	/*switch (eColor) //char, short, int, long, or enum as parameters
//	{
//		case COLOR_BLACK:
//			cout << "Black";
//			break; //tells the compiler we are done with this case
//		case COLOR_WHITE:
//			cout << "White";
//			break;
//		case COLOR_RED:
//			cout << "Red";
//			break;
//		case COLOR_GREEN:
//			cout << "Green";
//			break;
//		case COLOR_BLUE:
//			cout << "Blue";
//			break;
//		default:
//			cout << "Unknown";
//			break;
//	}*/
//	//The switch expression is evalutated to produce a value, and each case label is 
//	//tested against this value for equality.If a case label matches, the statements 
//	//after the case label are executed.If no case label matches the switch expression, 
//	//the code under the default label is executed(if it exists).
//
//	//while statement - declared using the while keyword. When a while statement is 
//	//executed, the expression is evaluated.If the expression evaluates to true (non - zero),
//	//the statement executes.
//	int iii = 0;
//	while (iii < 10)
//	{
//		cout << iii << " ";
//		iii++;
//	}
//	cout << endl;
//	//Infinite loop - when the condition is always true
//	//while(1){}
//
//	//Loop variable - integer variable that is declared for the sole purpose of counting 
//	//how many times a loop has executed
//
//	//Each time a loop executes, it is called an iteration.
//
//	//Do while loop - when we want something to execute something at least once
//
//	//For loop - when we know how many times to iterate
//	for (int i = 0; i < 5; ++i){
//		cout << "HI! ";
//	} //i only exists in this loop and gets destroyed at the end of the loop
//	cout << endl;
//
//	//Continue allows a way to jump back to the loop with finishing the iteration
//	for (int iii = 0; iii < 20; iii++){
//		// if the number is divisible by 4, skip this iteration
//		if ((iii % 4) == 0){
//			continue;
//		}
//		cout << iii << endl;
//	}
//
//	system("pause"); 
//}
//
//void doPrint(){
//	cout << "In doPrint()" << endl;
//}
//int return5(){
//	return 5;
//}
//int getValueFromUser(){
//	cout << "Enter an integer: ";
//	int a;
//	cin >> a;
//	return a;
//}
//int add(int x, int y){
//	return x + y;
//}