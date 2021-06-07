#include<iostream>
using namespace std;

struct student {
	string name;
	int id;
	int age;
};

void printStudent(student s) {
	s.id = 100;
	cout << "in void printStudent(student s) : " << "student id = " << s.id << " , student name : " << s.name << endl; 
}

void printStudent(student *s) {
	s->id = 200;
	cout << "in void printStudent(student *s) : " <<  "student id = " << s->id << " , student name : " << s->name << endl; 
}

void printStudentConst(const student *s) {
	// s->id = 100; Error variable 's' declared const here
	cout << "in void printStudentConst(student *s) : " <<  "student id = " << s->id << " , student name : " << s->name << endl; 
}

int main() {
	struct student s;
	s.name = "John";
	s.id = 1;
	s.age = 16;

	cout << "in Main : " <<  "student id = " << s.id << " , student name : " << s.name << endl; 

	printStudent(s);
	cout << "in Main : " <<  "student id = " << s.id << " , student name : " << s.name << endl; 
	printStudent(&s);
	cout << "in Main : " <<  "student id = " << s.id << " , student name : " << s.name << endl; 

	system("pause");
	return 0;
}

