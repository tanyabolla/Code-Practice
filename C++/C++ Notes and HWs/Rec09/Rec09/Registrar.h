#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly{
	class Student;
	class Course;
	class Registrar{
	public:
		void addCourse(const std::string& name);
		void addStudent(const std::string& name);
		void enrollStudentInCourse(const std::string& sName, const std::string& cName);
		void cancelCourse(const std::string& cName);
		void printReport(std::ostream& os);
		void purge();
	private:
		std::vector<Course*> courses;
		std::vector<Student*> students;
		size_t find(const Course& course);
	};
	std::ostream& operator<<(std::ostream& os, Registrar& output);
}
#endif

