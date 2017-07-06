#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Registrar.h"

namespace BrooklynPoly{
	class Registrar;
	class Student;
	class Course{
	public:
		Course(const std::string& cName);
		void addStudent(Student*& student);
		void display() const;
		std::string getName() const;
	private:
		std::vector<Student*> students;
		std::string cName;
	};
}
#endif