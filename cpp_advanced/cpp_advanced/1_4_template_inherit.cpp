#include<iostream>
using namespace std;

template<class T>
class Person {
public:
	Person() {};

	Person(T name) : name(name) {};

	virtual void show() = 0;

protected:
	T name;
};

// wrong, must specify type for base class
// class Student : public Person {};

class Student : public Person<string> {
	
};

template<class T1, class T2>
class Teacher : public Person<T1> {
public:
	// also works
	// Teacher(T1 name, T2 subject) : name(name), subject(subject) {};
	Teacher(T1 name, T2 subject) {
		this->name = name;
		this->subject = subject;
	}

	virtual void show() {
		cout << " Teacher name = " << this->name << ", name type is " << typeid(this->name).name() << ", Subject  = " << this->subject << ", Subject type is " << typeid(this->subject).name() << endl;
	}
private:
	T2 subject;
};

class Base {};

class Derived : public Base {};

template<typename T>
class MyTempC {
public:
	MyTempC() : t(new T()) {};

	// member template
	template<typename U>
	// here should use *u rather than u
	MyTempC(const U& u) : t(*u) {}

	void show() {
		cout << "T type is " << typeid(t).name() << endl;
	}
private:
	T t;
};

int main() {
	Teacher<string, string> teacher("John", "Math");
	teacher.show();

	cout << "\n\n" << endl;


	Base* p1 = new Derived; // up-cast
	cout << "*p1 type is " << typeid(*p1).name() << endl; // *p1 type is class Base

	MyTempC<Derived> c1(new Derived);
	c1.show(); // T type is class Derived

	MyTempC<Base> c2(new Base);
	c2.show(); // T type is class Base

	MyTempC<Base> c3(new Derived);
	c3.show(); // T type is class Base

	// wrong, up-cast is ok, it's polymorphism, but cannot down-cast
	// Error	C2664	'Derived::Derived(const Derived &)': cannot convert argument 1 from 'Base' to 'const Derived &'
	// MyTempC<Derived> c4(new Base);
	// c4.show();

	system("pause");
	return 0;
}