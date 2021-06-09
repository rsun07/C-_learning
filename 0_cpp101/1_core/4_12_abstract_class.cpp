#include<iostream>
using namespace std;

// Class has at least one pure virtual func, class is an abstract class, cannot be initialized
// Java has key word abstract, C++ doesn't have yet
class Base {
public:
	// pure virtual function, no implementation
	virtual string getName() = 0;

	// pure virtual distructor, must be implementated, see below
	virtual ~Base() = 0;
};

// distructor cannot be pure virtual. The Class may allocate stack resources need to be deleted
Base::~Base() {

}

// If a class inherits an abstract class and not implement all virtual functions, this derived class is also an abstract class
class Derived1 : public Base {
public:
	string getMyName() {
		return "GetMyName: Derived1";
	}
};

class Derived2 : public Base {
public:
	// here the impl of a virtual function should also add virtual at signature
	virtual string getName() {
		return "GetName: Derived2";
	}
};

int main() {

	// null pointer is ok
	Base * base = NULL;

	//  error: allocating an object of abstract class type 'Base'
	// base = new Base;
	
	// error: allocating an object of abstract class type 'Derived1'
	// Derived1 d1 = new Derived1;

	base = new Derived2;
	cout << base->getName() << endl;
	delete base;

	return 0;
}

