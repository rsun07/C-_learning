#include<iostream>
using namespace std;

class Base {
public:
	int a;
	Base(int a, int b, int c) : a(a), b(b), c(c) {
		cout << "Base constructor" << endl;
	}

	~Base() {
		cout << "Base disstructor" << endl;
	}

	void show () {
		cout << "Show in Base, a = " << a << ", b = " << b << " , c = " << c << endl;
	}

	static int getD() {
		return d;
	}

protected:
	int b;
private:
	int c;
	static int d;
};

// non-const static data member must be initialized out of line
int Base::d = 10;

class Derived : public Base {
public:
	Derived(int a, int b) : Base(a, b, 0) {
		this->a = a;
		this->b = b;
		Base::a = a+100;
		cout << "Derived constructor" << endl;
	}

	~Derived() {
		cout << "Derived disstructor" << endl;
	}

	void show() {
		cout << "Show in Derived, base a = " << Base::a << " ,a = " << a << ", b = " << b << endl;
	}

	static int getD() {
		return d;
	}
private:
	int a;
	static int d;
};

int Derived::d = 20;


int main() {

	Derived d(1,2);
	d.show();

	cout << endl;

	d.Base::a = 9;
	d.show();

	cout << endl;

	cout << d.getD() << endl;
	cout << d.Base::getD() << endl;
	cout << Derived::getD() << endl;
	cout << Base::getD() << endl;

	return 0;
}

/*
Base constructor
Derived constructor
Show in Derived, base a = 101 ,a = 1, b = 2

Show in Derived, base a = 9 ,a = 1, b = 2

20
10
20
10
Derived disstructor
Base disstructor
*/