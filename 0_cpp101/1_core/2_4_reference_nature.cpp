#include<iostream>
using namespace std;

// reference nature is constant pointer

// compiler will convert to int* const ref = &a
void func(int& ref) {
	// convert to *ref = 100;
	ref = 100;
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

	system("pause");
    return 0;
}
