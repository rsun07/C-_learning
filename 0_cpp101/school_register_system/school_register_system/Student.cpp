#include "Student.h"

Student::Student(int id, string name, int grade) {
	this->id = id;
	this->name = name;
	this->grade = grade;
}

void Student::displayInfo() {
	cout << "ID = " << this->id << "\tName = " << this->name << "\tGrade = " << this->grade << endl;
}