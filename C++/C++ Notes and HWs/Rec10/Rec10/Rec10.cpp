/*
	Recitation 10
	CS1124
	cb3172
	Chaitanya Bolla
	Focus: Copy Control.  Uses dynamic array of pointers.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Position {
public:
	Position(const string& aTitle, double aSalary) : title(aTitle), salary(aSalary) {}
	string getTitle() const { return title; }
	double getSalary() const { return salary; }
	void changeSalaryTo(double d) { salary = d; }
private:
	string title;
	double salary;
}; // class Position

class Entry {
public:
	Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition)
		: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {}
	friend ostream& operator<<(ostream& os, const Entry& e) {
		os << e.name << ' ' << e.room << ' ' << e.phone;
		return os;
	} // operato<<
	string getName() { return name; }
	int getNumber() { return phone; }
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // class Entry

class Directory {
public:
	//Constructor
	Directory() : capacity(2), size(0), entries(new Entry*[2]) {
		//Should we do this? What do you think?
		for (size_t i = 0; i < capacity; i++) {
			entries[i] = nullptr;
		} //for
	} //Directory()

	//Copy Constructor
	Directory(const Directory& rhs){
		cout << "Copy Constructor" << endl;
		size = rhs.size;
		capacity = rhs.capacity;
		entries = new Entry*[capacity];
		for (size_t i = 0; i < rhs.size; i++){
			entries[i] = new Entry(*(rhs.entries[i]));
		}
	}

	//Assignment Operator
	Directory& operator=(const Directory& rhs){
		cout << "Assignment Operator" << endl;
		if (this != &rhs){
			for (size_t i = 0; i < size; i++){
				delete entries[i];
			}
			delete[] entries;
			size = rhs.size;
			capacity = rhs.capacity;
			entries = new Entry*[capacity];
			for (size_t i = 0; i < size; i++){
				entries[i] = new Entry(*(rhs.entries[i]));
			}
		}
		return *this;
	}

	void add(const string& name, unsigned room, unsigned ph, Position& pos){
		if (size == capacity){
			// something is missing!!!  Add it!
			cout << "Increase Capacity Size" << endl;
			size_t newCapacity = (capacity *= 2);
			Entry** newEntries = new Entry*[newCapacity];
			for (size_t i = 0; i < size; i++){
				newEntries[i] = new Entry(*entries[i]);
			}
			for (size_t i = 0; i < size; i++){
				delete entries[i];
			}
			delete[] entries;
			entries = newEntries;
		} // if
		entries[size] = new Entry(name, room, ph, pos);
		++size;
	} // add

	unsigned operator[](const string& name){
		cout << "Square bracket operator" << endl;
		for (size_t i = 0; i < size; i++){
			string newName;
			newName = entries[i]->getName();
			if (name == newName){
				return entries[i]->getNumber();
				break;
			}
		}
	}

	friend ostream& operator<<(ostream& os, Directory directory){
		os << "Output Operator" << endl;
		for (size_t i = 0; i < directory.size; i++){
			os << *(directory.entries[i]) << endl;
		}
		return os;
	}

	//Destructor
	~Directory(){
		cout << "Destructor" << endl;
		for (size_t i = 0; i < size; i++){
			delete entries[i];
		}
		delete[] entries;
	}

private:
	Entry** entries;
	size_t size;
	size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {

	// Model as if there are these four kinds 
	// of position in the problem:
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	cout << d << endl;

	Directory d2 = d;	// What function is being used??
	d2.add("Gallagher", 111, 2222, techie);
	d2.add("Carmack", 314, 1592, techie);
	cout << d2 << endl;

	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;

	system("pause");
} // main
