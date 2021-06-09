#include<iostream>
using namespace std;

// biggest difference is default access permission for struct is public, for class is private

// In C++ there's only one difference between a struct and a class: in a struct the default visibility is public while in a class it is private.
// Other than that you can do anything you would do in a class in a structand it will look exactly the same.

class Student {
	string name;
	int id;

public: 
	void show() {
		cout << "name = " << name << " , id = " << id << endl;
	}
};

struct Student2 {
	string name;
	int id;

	void show() {
		cout << "name = " << name << " , id = " << id << endl;
	}
};

int main() {

	Student student;
	// error: 'name' is a private member of 'Student'
	// student.name = "John";

	Student2 student2 = {"Marry", 2};

	// string will be empty, int will be random number if not initialized or 0 depending on compiler
	student.show();
	student2.show();


	system("pause");
    return 0;
}
