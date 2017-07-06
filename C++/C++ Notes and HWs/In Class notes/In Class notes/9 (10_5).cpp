#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Person{
public:
	Person(const string& name) : name(name), spouse(nullptr){}
	void display(ostream& os = cout) const {
		os << "Name: " << name << ", Married?: " << endl;
		if (spouse != nullptr) os << "yes: " << spouse->name;
		else os << "no";
		os << endl;
	}

	//john.marries(mary);
	bool marries(Person& betrothed){
		if (spouse == nullptr && betrothed.spouse == nullptr){
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

void simpleFunc(const Person& somebody){
	//Person* pp = &somebody; //can change information
	const Person* pp = &somebody; //can't change the information of somebody
	//Can't call the marries method since it's not marked constant
	pp->display();
	//Invalid conversion from const Person* ptr to  Person* ptr
	//because pp can be changed in any way as we are not promising that it cannot be changed
	//upside - less likely to do something disastarous like blowing up a nuclear plant
}

int main(){
	int x;
	int* p = &x; //nothing is constant
	const int* p = &x; //the value of x can't be changed but the &x (variable) can be changed
	int* const p = &x; //the value of x can be changed but the &x can't be changed
	const int* const p = &x; //neither x not the memory address can be changed

	//Rest of the notes are in the next notes
	system("pause");
}