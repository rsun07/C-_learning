#include<iostream>
using namespace std;

class Base {
public:
	string getName() {
		return "Base Class";
	}

	virtual string getNameVirtual() {
		return "Base Class";
	}
};

class Derived : public Base {
public:
	string getName() {
		return "Derived";
	}

	virtual string getNameVirtual() {
		return "Derived";
	}
};

// For virtual function, compiler cannot confirm function call at compiler time.
// It will be determined at run time dymanically.
void show(Base& base) {
	cout << "base.getName() : " << base.getName() << endl;
	cout << "base.getNameVirtual() " << base.getNameVirtual() << endl;
}

class Base2 {
public:
	string getName() {
		return "Base Class";
	}
};

class Base3 {
public:
	virtual string getName() {
		return "Base Class";
	}
};

// How to use polymorphic?
// 1. Inerit and subclass override super class virtual function
// 2. Super class pointer or reference points to subclass instance
int main() {

	Derived d;
	// here we pass d's reference as Base& to show method
	show(d);	

	cout << endl;

	// Base 2 is an empty class, the non-virtual method will be shared by all instances
	// so its size is 1
	cout << sizeof(Base2) << endl;

	// Base 3 is not empty, it has an vfptr (virtual function pointer) which point to vftable
	// When subclass override the virtual class, the vfptr in subclass will be different than it in the super class
	// Becase it has one more pointer, so the size will be 4 or 8 based on operating system
	cout << sizeof(Base3) << endl;

	return 0;
}

/*

base.getName() : Base Class
base.getNameVirtual() Derived

1
8
*/