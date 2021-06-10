#include<iostream>
using namespace std;

// can have default type value, same as function default value, if one has, all following ones after it must also have default values
template<class NameType, class IDType = int>
class Student {
public:
	Student(NameType name, IDType id) : name(name), id(id) {}

	void show() {
		cout << "name = " << this->name << ", id = " << id << endl;
	}
private:
	NameType name;
	IDType id;
};

// Three ways to pass in template class as variable
// 1. specify the types, this is the most commonly used way
void print(Student<string, int> &student) {
	student.show();
}

//2. use template params
template<class T1, class T2>
void print(Student<T1, T2> &student) {
	cout << "Name Type is " << typeid(T1).name() << ", id type is " << typeid(T2).name() << endl;
	student.show();
}

// 3. use template class
template<class T>
void print(T& t) {
	cout << "T's type is  " << typeid(T).name() << endl;
	t.show();
}

template<class T>
void print2(T& t) {
	cout << "T's type is  " << typeid(T).name() << endl;
	// though T could not have method show(), we can still write like this
	// the template itself could pass the first compiler. And compiler will check this again when reach the caller. If t doens't have method show(), will raise compiler error.
	t.show();
}

int main() {

	// cannot use this way, must specify type
	// Student student("John", 1);

	Student<char, double> s1('c', 1.1);
	Student<string> s2("John", 2);
	s1.show();
	s2.show();

	cout << endl;

	// use the specified function
	print(s2);
	// use the second function
	print(s1);

	cout << endl;

	// T's type is  class Student<char,double>
	print2(s1);

	cout << endl;

	// Error	C2228	left of '.show' must have class / struct / union
	// print2("abc");

	system("pause");
	return 0;
}

/*
name = c, id = 1.1
name = John, id = 2

name = John, id = 2
Name Type is char, id type is double
name = c, id = 1.1

T's type is  class Student<char,double>
name = c, id = 1.1*/