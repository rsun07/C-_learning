#include<iostream>
using namespace std;

// reference nature is constant pointer

// compiler will convert to int* const ref = &a
void func(int& ref) {
	// convert to *ref = 100;
	ref = 100;
}


class MyNum {
public:
	MyNum(const int num) : num(num){};
	int getNum() const {return this->num;}

	MyNum(const MyNum& myNum) {
		this->num = myNum.num;
		cout << "MyNum copy ctor" << endl;
	}

private:
	int num;
};

namespace ref_vs_pointer_2 {
	void test() {
		int x = 0;
		int* p = &x;
		int& r = x;
		cout << "x = " << x << ", p = " << p << ", *p = " << *p << ", r = " << r << endl;

		r = 1;
		cout << "x = " << x << ", p = " << p << ", *p = " << *p << ", r = " << r << endl;

		int x2 = 2;
		p = &x2;
		cout << "x = " << x << ", p = " << p << ", *p = " << *p << ", r = " << r << endl;

		// reference cannot change target, it's const pointer, so it only change target value
		int x3 = 3;
		r = x3;
		cout << "x = " << x << ", p = " << p << ", *p = " << *p << ", r = " << r << endl;

		// same as above, reference is const pointer, r2 also a reference of x;
		int& r2 = r;
		cout << "x = " << x << ", x2 = " << x2 << ", r = " << r << ", r2 = " << r2 << endl;
		r2 = 5;
		cout << "x = " << x << ", x2 = " << x2 << ", r = " << r << ", r2 = " << r2 << endl;	

		cout << endl;
		cout << "sizeof(p) = " << sizeof(p) << endl;
		cout << "sizeof(r) = " << sizeof(r) << endl;
		cout << "sizeof(r2) = " << sizeof(r2) << endl;
		cout << "sizeof(x) = " << sizeof(x) << endl;
	}

	/*
		x = 0, p = 0x7ffdc237bacc, *p = 0, r = 0
		x = 1, p = 0x7ffdc237bacc, *p = 1, r = 1
		x = 1, p = 0x7ffdc237bad0, *p = 2, r = 1
		x = 3, p = 0x7ffdc237bad0, *p = 2, r = 3
		x = 3, x2 = 2, r = 3, r2 = 3
		x = 5, x2 = 2, r = 5, r2 = 5

		sizeof(p) = 8
		sizeof(r) = 4
		sizeof(r2) = 4
		sizeof(x) = 4
	*/
}

int main() {
	
	int num = 10;

	// compiler will convert to 
	// int* const ref = &num;
	// pointer constant is immutable, that's why ref is immutable
	// it cannot change target heap memory address, but can change target heap value.
	int& ref = num;

	// conver to *ref = 20;
	ref = 20;

	cout << "num = " << num << endl;
	func(num);

	cout << "num = " << num << endl;

	cout << endl;

	cout << "pointer and reference" << endl;
	MyNum num1 = MyNum(1);
	MyNum* numP1 = &num1;
	cout << num1.getNum() << endl;
	cout << numP1->getNum() << endl;
	// *numP1 is an MyNum object
	cout << (*numP1).getNum() << endl;

	MyNum num2 = *numP1; // copy ctor called

	cout << endl;
	MyNum* numP2 = numP1; // just point to same memory address, won't call copy ctor
	// get object first, then get reference to a pointer
	cout << (&(*numP2))->getNum() << endl;

	cout << endl;

	ref_vs_pointer_2::test();

	system("pause");
    return 0;
}

/*
num = 20
num = 100

pointer and reference
1
1
1
MyNum copy ctor

1
*/