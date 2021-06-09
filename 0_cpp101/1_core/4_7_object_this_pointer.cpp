#include<iostream>
using namespace std;

class Student {
	string name;
	int id;

public: 
	Student(string name, int id) {
		this->name = name;
		this->id = id;
	}

	// copy constructor
	Student(const Student& s) {
		this->name = s.name;
		this->id = s.id;
	}

	Student& copyStudent(const Student& s) {
		this->name = s.name;
		this->id = s.id;
		return *this;
	}

	void setName(string name) {
		this->name = name;
	}

	void setId(int id) {
		this->id = id;
	}

	string getName() {
		return this->name;
	}

	int getId() {
		return this->id;
	}

	// all class method, will have *this as the first parameter. Just it's omitted here, but it exist. 
	// This will be the caller object for this method. 
	// This also align with the fact we see before that all class object share the same function instance in memory.
	// In this case, compiler need to know which object call this function, the solution is pass in *this pointer points to the object initial the call.
	void show() {
		// warning: 'this' pointer cannot be null in well-defined C++ code; comparison may be assumed to always evaluate to false [-Wtautological-undefined-compare]
		if (this == NULL) return;
		cout << "name = " << this->name << " , id = " << this->id << endl;
	}

	void showClassName() {
		cout << "Student" << endl;
	}
};
	
int main() {

	Student student("John", 1);
	student.setId(2);
	Student student2(student);

	Student student3("Marry", 3);
	student.copyStudent(student3);

	student.show(); // equals to "Student::show(student)", student is this pointer passed into the show() function
	student2.show();
	student3.show();

	cout << endl;

	// can use null poiter to call method because the method is shared by all object instances
	Student *p = NULL;
	p->showClassName();
	// will cause exit[1] if don't check in show() function
	p->show();

	system("pause");
    return 0;
}
