#include "Course.h"
#include "Student.h"
#include "Registrar.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace BrooklynPoly{
	void Registrar::addCourse(const string& name){
		if (courses.size() == 0){
			Course* newCourse = new Course(name);
			courses.push_back(newCourse);
		}
		else{
			for (size_t i = 0; i < courses.size(); i++){
				if (courses[i]->getName() == name){ 
					cerr << "Error. Course exists already" << endl;
					exit(1);
				}
				else{
					Course* newCourse = new Course(name);
					courses.push_back(newCourse);
					i = courses.size();
				}
			}
		}
	}
	void Registrar::addStudent(const string& name){
		if (students.size() == 0){
			Student* newStudent = new Student(name);
			students.push_back(newStudent);
		}
		else{
			for (size_t i = 0; i < students.size(); i++){
				if ((students[i]->getName()) == name){
					cerr << "Error. Student exists already" << endl;
					exit(1);
				}
				else{
					Student* newStudent = new Student(name);
					students.push_back(newStudent);
					i = students.size();
				}
			}
		}
	}
	void Registrar::enrollStudentInCourse(const string& sName, const string& cName){
		size_t index = find(cName);
		for (size_t j = 0; j < students.size(); j++){
			if (students[j]->getName() == sName){
				courses[index]->addStudent(students[j]);
				students[j]->addCourse(courses[index]);
			}
		}
	}
	void Registrar::cancelCourse(const string& cName){
		size_t index = find(cName);
		if (courses.size() > index){
			courses[index] = courses[courses.size() - 1];
			courses.pop_back();
		}
	}
	void Registrar::purge(){
		for (size_t i = 0; i < courses.size(); i++) {
			delete courses[i];
			courses[i] = nullptr;
		}
		for (size_t j = 0; j < students.size(); j++) {
			delete students[j];
			students[j] = nullptr;
		}
		courses.clear();
		students.clear();
	}
	size_t Registrar::find(const Course& course){
		for (size_t i = 0; i < courses.size(); i++){
			if (courses[i] == &course){
				return i;
			}
		}
		return courses.size();
	}
	ostream& operator<<(ostream& os, Registrar& output){
		output.printReport(os);
		return os;
	}
	void Registrar::printReport(ostream& os){
		os << "University Report: " << endl;
		os << "Courses: " << endl;
		for (size_t i = 0; i < courses.size(); i++){
			os << courses[i]->getName() << endl;
			//courses[i]->display();
		}
		for (size_t j = 0; j < students.size(); j++){
			os << students[j]->getName() << endl;
		}
		os << endl;
	}
}