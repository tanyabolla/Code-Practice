#include "Course.h"
#include "Student.h"
#include "Registrar.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace BrooklynPoly{
	Course::Course(const string& cName) : cName(cName){}
	void Course::addStudent(Student*& student){
		students.push_back(student);
	}
	void Course::display() const {
		for (size_t j = 0; j < students.size(); j++){
			cout << students[j]->getName() << endl;
		}
		cout << endl;
	}
	string Course::getName() const { return cName; }
}