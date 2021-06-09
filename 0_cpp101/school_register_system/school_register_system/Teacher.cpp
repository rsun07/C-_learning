#include "Teacher.h"

Teacher::Teacher(int id, string name, string subject) {
	this->id = id;
	this->name = name;
	this->subject = subject;
}

void Teacher::displayInfo() {
	cout << "ID = " << this->id << "\tName = " << this->name << "\tSubject = " << this->subject << endl;
}