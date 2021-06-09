#include<iostream>
using namespace std;

// delare first, otherwise class Parent cannot use it
class Student;

// 3. Use other class's method as friend, only allow this method to access
class Parent {
private:
	Student* student;
public:
	Parent(Student* student) : student(student) {}

	// because class Student is not defined here, so `name` and `id` are not exist here. Must implement the method after class Student
	// on the other hand, must declare this method before Student friend declaration.
	void showStudent();

	// error: 'name' is a private member of 'Student'
	// void showStudent2() {
	// 	cout << "name = " << student->name << " , id = " << student->id << endl;
	// }
};

class Student {
	string name;
	int id;

// 1. global method, tell compiler this global method is friend of Student class, can access private fileds
friend void showStudent(Student* student);
// 2. Use class to access as friend
friend class Teacher;
// 3. Use other class's method as friend, only allow this method to access
friend void Parent::showStudent();

public: 
	Student(string name, int id) : name(name), id(id) {}

	void show() const {
		cout << "name = " << this->name << " , id = " << this->id << endl;
	}

	// inside student, can access private fields
	void showOtherStudent(Student* other) {
		cout << "name = " << other->name << " , id = " << other->id << endl;
	}

};

// without friend delaration in Student class, will see this error
// error: 'name' is a private member of 'Student'
void showStudent(Student* student) {
	cout << "name = " << student->name << " , id = " << student->id << endl;
} 

class Teacher {
private:
	Student* student;
public:
	// define constructor and method here, implement outside of this class
	Teacher(Student * student);

	void showStudent();
};

Teacher::Teacher(Student * student) {
	this->student = student;
}

void Teacher::showStudent() {
	cout << "name = " << student->name << " , id = " << student->id << endl;
}

void Parent::showStudent() {
	cout << "name = " << student->name << " , id = " << student->id << endl;
}

int main() {

	Student student1("John", 1);
	Student student2("Marry", 2);
	student2.showOtherStudent(&student1);

	showStudent(&student1);

	cout << endl;

	Teacher teacher(&student2);
	teacher.showStudent();

	cout << endl;
	Parent parent(&student2);
	parent.showStudent();
	// parent.showStudent2();

	system("pause");
    return 0;
}
