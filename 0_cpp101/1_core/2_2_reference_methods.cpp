#include<iostream>
using namespace std;

// value
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

// address
void swap(int* a, int* b) {
	int temp = *a;
	*a= *b;
	*b = temp;
}

//reference.
// Same outcome as address pass, but more convenient than address 
void swap2(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1, b = 2;
	cout << "Initial " << "a:" << a << " b:" << b << endl;

	swap(a, b);
	cout << "swap " << "a:" << a << " b:" << b << endl;

	// call pointer method need pass reference
	swap(&a, &b);
	cout << "swap * " << "a:" << a << " b:" << b << endl;

	// call reference param method, same as normal method, but will pass reference, more convenient
	swap2(a, b);
	cout << "swap2 " << "a:" << a << " b:" << b << endl;

	system("pause");
    return 0;
}
