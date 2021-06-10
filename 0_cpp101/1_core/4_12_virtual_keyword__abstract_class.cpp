#include<iostream>
using namespace std;

namespace abstract_basic {
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

	void run() {
		// null pointer is ok
		Base * base = NULL;

		//  error: allocating an object of abstract class type 'Base'
		// base = new Base;
		
		// error: allocating an object of abstract class type 'Derived1'
		// Derived1 d1 = new Derived1;

		base = new Derived2;
		cout << base->getName() << endl; // GetName: Derived2
		delete base;
	}
}

// classical example
namespace virtual_func_and_normal_func_in_inherit {
	class Base {
	public:
		Base() {}

		Base(int n1, int n2, int n3) : num1(n1), num2(n2), num3(n3) {};

		virtual void vfunc1() {
			cout << "Base virtual func1" << endl;
		}

		virtual void vfunc2() {
			cout << "Base virtual func2" << endl;
		}

		void func1() {
			cout << "Base func1" << endl;
		}

		void func2() {
			cout << "Base func2" << endl;
		}
	private:
		int num1, num2, num3;
	};

	class Derived1 : public Base {
	public:
		Derived1() {}

		Derived1(int n1) : num1(n1) {};

		virtual void vfunc1() {
			cout << "Derived1 virtual func1" << endl;
		}

		void func1() {
			cout << "Derived1 func1" << endl;
		}
	private:
		int num1;
	};

	class Derived2 : public Derived1 {
	public:
		Derived2() {}

		Derived2(int n1) : num1(n1) {};

		virtual void vfunc1() {
			cout << "Derived2 virtual func1" << endl;
		}

	private:
		int num1;
	};

	// only virtual function could be override. 
	// non-virtual function with the same name, are different functions, though looks like override, but in fact it isn't
	void func_test() {
		Base b(1,2,3);
		Derived1 d1(4);
		Derived2 d2(5);

		b.vfunc1();
		b.vfunc2();
		b.func1();
		b.func2();
		cout << endl;

		d1.vfunc1();
		d1.vfunc2();
		d1.func1();
		d1.func2();
		cout << endl;

		d2.vfunc1();
		d2.vfunc2();
		d2.func1();
		d2.func2();
		cout << endl;

		d2.Base::vfunc1();
		d2.Base::func1();
		cout << endl;
	}
	/*
	Base virtual func1
	Base virtual func2
	Base func1
	Base func2

	Derived1 virtual func1
	Base virtual func2
	Derived1 func1
	Base func2

	Derived2 virtual func1
	Base virtual func2
	Derived1 func1
	Base func2

	Base virtual func1
	Base func1
	*/


	// though private field, Derived class doens't have access to. It will still inherit and take space
	void size_test() {
		cout << "sizeof(Base) = " << sizeof(Base) << endl; // non-initialized int also take space
		cout << "sizeof(Base(1,2,3)) = " << sizeof(Base(1,2,3)) << endl;
		cout << "sizeof(Derived1()) = " << sizeof(Derived1(4)) << endl;
		cout << "sizeof(Derived2()) = " << sizeof(Derived2(5)) << endl;
	}
	/*
	sizeof(Base) = 24
	sizeof(Base(1,2,3)) = 24
	sizeof(Derived1()) = 24
	sizeof(Derived2()) = 32
	*/
}

int main() {
	abstract_basic::run();
	cout << "\n\n" << endl;

	virtual_func_and_normal_func_in_inherit::func_test();
	cout << endl;
	virtual_func_and_normal_func_in_inherit::size_test();

	return 0;
}

