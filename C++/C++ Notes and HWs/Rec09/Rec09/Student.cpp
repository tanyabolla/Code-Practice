#include "Course.h"
#include "Student.h"
#include "Registrar.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace BrooklynPoly{
	Student::Student(const string& name){}
	void Student::addCourse(Course* course){
		courses.push_back(course);
	}
	void Student::dropCourse(Course* course){
		for (size_t i = 0; i < courses.size(); i++){
			if (courses[i]->getName() == course->getName()){
				courses[i] = courses[courses.size() - 1];
				courses.pop_back();
			}
		}
	}
	void Student::display() const {
		cout << name << endl;
	}
	string Student::getName() const { return name; }
}
