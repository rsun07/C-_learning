#include<iostream>
using namespace std;

// class declaration
template<class T1, class T2> class Person;

// friend function, implement outside of class
template<class T1, class T2>
void describe(Person<T1, T2>& person) {
	cout << "describe person outside class function, name = " << person.name << ", name type is " << typeid(person.name).name() << ", Age  = " << person.age << ", Subject type is " << typeid(person.age).name() << endl;
}

// class implementation, cannot emit the template line
template<class T1, class T2>
class Person {
public:
	Person(T1 name, T2 age) : name(name), age(age) {};

	// global function, implement inside class
	friend void show(Person<T1, T2>& person) {
		cout << "show person inside class function, name = " << person.name << ", name type is " << typeid(person.name).name() << ", Age  = " << person.age << ", Age type is " << typeid(person.age).name() << endl;
	}

	friend void describe<>(Person<T1, T2>& person);

private:
	T1 name;
	T2 age;
};

int main() {
	Person<string, int> person("John", 2);
	describe(person);
	cout << endl;

	// show is a global function, doesn't need to call by object or class
	show(person);

	system("pause");
	return 0;
}