#include<iostream>
using namespace std;

// In C++ there's only one difference between a struct and a class: in a struct the default visibility is public while in a class it is private.
// Other than that you can do anything you would do in a class in a structand it will look exactly the same.
struct student {
	string name;
	int id;
	int age;
};

int main() {
	// struct can be omitted, see s2
	struct student s1;
	s1.name = "John";
	s1.id = 1;
	s1.age = 16;

	student s2 = {"Marry", 2, 16};

	student students[3] = {s1, s2, {"Paul", 3, 17}};
	
	for (int i = 0; i < 3; i++) {
		cout << "student id = " << students[i].id << " , student name : " << students[i].name << endl; 
	}

	student* p = &s1;
	p->id = 5;

	cout << "student id = " << s1.id << " , student name : " << p-> name << endl;

	system("pause");
	return 0;
}