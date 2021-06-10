#include<iostream>
using namespace std;

template<typename T>
bool myCompare(T& a, T& b) {
	return a == b;
}

class Student {
public:
	string name;
	int id;

	Student(string name, int id) : name(name), id(id) {}
};


template<> bool myCompare(Student &s1, Student &s2) {
	return s1.name == s2.name && s1.id == s2.id;
}

int main() {
	int a = 10, b = 10, c = 20;

	cout << myCompare(a, b) << endl;

	cout << myCompare(a, c) << endl;


	cout << endl;

	// myCompare doesn't work for Student type. two ways to solve this, 
	// one is overload == for Student class, 
	// another is overload myCompare template with specific Student type

	Student s1("John", 1), s2("John", 2), s3("John", 1);
	
	cout << myCompare(s1, s2) << endl;

	cout << myCompare(s1, s3) << endl;


	system("pause");
	return 0;
}