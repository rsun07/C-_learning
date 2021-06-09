#include<iostream>
using namespace std;

class Base {
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Derived1 : public Base {
public:
	int add() {
		int d = a;
		d += b;
		// don't have access to private field
		// d += c;
		return d;
	}
};

class Derived11 : public Derived1 {
public:
	int add() {
		int d = a;
		d += b;
		// don't have access to private field
		// d += c;
		return d;
	}
};

class Derived2 : protected Base {
public:
	int add() {
		int d = a;
		d += b;
		// don't have access to private field
		// d += c;
		return d;
	}
};

class Derived22 : protected Derived2 {
public:
	int add() {
		int d = a;
		d += b;
		// don't have access to private field
		// d += c;
		return d;
	}
};

class Derived3 : private Base {
public:
	int add() {
		int d = a;
		d += b;
		// don't have access to private field
		// d += c;
		return d;
	}
};

class Derived33 : public Derived3 {
public:
	int add() {
		// Don't have access to any
		// int d = a;
		// d += b;
		// don't have access to private field
		// d += c;
		return 0;
	}
};

int main() {

	Derived1 derived1;
	derived1.add();
	derived1.a;
	// other class don't have access to protected member
	// derived1.b;

	Derived11 derived11;
	derived11.add();
	derived11.a;
	// other class don't have access to protected member
	// derived11.b;

	Derived2 derived2;
	derived2.add();
	// don't have access to public member
	// derived2.a;

	Derived22 derived22;
	derived22.add();
	// derived22.a;

	Derived3 derived3;
	derived3.add();

	Derived33 derived33;
	derived33.add();

	return 0;
}

