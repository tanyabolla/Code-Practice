/* 
	cb3172
	Chaitanya Bolla
	Rec06 - Using classes, create a lab that a labworker is assigned to which has a certain amount of students. Each student has grades for each week.
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Timeslot{
public:
	Timeslot(const string& day, unsigned hour) : day(day), hours(hour){}
	void display() const {
		if (hours <= 12){
			cout << hours << "AM" << endl;
		}
		else if (hours >= 12){
			int pm = hours - 12;
			cout << pm << "PM" << endl;
		}
	}
private:
	string day;
	unsigned hours;
};

class StudentRecord{
public:
	StudentRecord(const string& name) : name(name), grades(13, -1) {}
	string getName() const { return name; }
	void addGrade(int grade, int week){
		grades[week] = grade;
	}
	void display() const {
		cout << "Student Name: " << name << "; Grades: ";
		for (size_t i = 0; i < grades.size(); i++){
			cout << grades[i] << " ";
		}
		cout << endl;
	}
private:
	string name;
	vector<int> grades;
};

class Section{
public:
	Section(const string& sectionName, const string& day, int hours) : secName(sectionName), time(day, hours), stuRec(NULL){}
	void addStudent(const string& student){
		stuRec.push_back(new StudentRecord(student));
	}
	void addGrade(const string& name, int grade, int week){
		for (size_t i = 0; i < stuRec.size(); i++){
			if (name == stuRec[i]->getName()){
				stuRec[i]->addGrade(grade, week);
			}
		}
	}
	void display() const {
		cout << "Section: " << secName << " ";
		time.display();
		for (size_t i = 0; i < stuRec.size(); i++){
			stuRec[i]->display();
		}
		cout << endl;
	}
	void reset(){
		for (size_t i = 0; i < stuRec.size(); i++){
			delete stuRec[i];
			stuRec[i] = nullptr;
		}
		stuRec.clear();
	}
private:
	string secName;
	Timeslot time;
	vector<StudentRecord*> stuRec;
};

class LabWorker{
public:
	LabWorker(const string& name) : workerName(name) {}
	void addGrade(const string& name, int grade, int week){
		labSec->addGrade(name, grade, week);
	}
	void addSection(Section& secName){
		labSec = &secName;
	}
	void displayGrades() const {
		cout << workerName << endl;
		labSec->display();
	}
private:
	string workerName;
	Section* labSec;
};

int main(){
	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


	// setup is complete, now a real world scenario can be written in the code
	// [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

	// week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();

	system("pause");
}