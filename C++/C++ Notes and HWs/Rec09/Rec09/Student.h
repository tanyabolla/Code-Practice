#ifndef STUDNET_H
#define STUDNET_H
#include <iostream>
#include <vector>
#include <string>
#include "Course.h"
#include "Registrar.h"

namespace BrooklynPoly{
	class Course;
	class Registrar;
	class Student{
	public:
		Student(const std::string& name);
		void addCourse(Course* course);
		void dropCourse(Course* course);
		void display() const;
		std::string getName() const;
	private:
		std::string name;
		std::vector<Course*> courses;
	};
}
#endif