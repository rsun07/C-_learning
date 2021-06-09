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