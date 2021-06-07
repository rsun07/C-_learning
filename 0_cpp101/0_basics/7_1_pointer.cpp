#include<iostream>
using namespace std;

int main() {
	int a = 1;
	// declare pointer
	int * p;

	// assign a's memory address to pointer p
	p = &a;
	cout << "a's memory address : " << &a << endl;
	cout << "p's value : " << p << endl;
	cout << "memory value p point to : " << *p << endl;
	
	cout << endl;
	*p = 2;
	cout << "a = " << a << endl;

	cout << endl;
	cout << sizeof(int *) << endl;
	cout << sizeof(long long *) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(string *) << endl;
	cout << sizeof(float *) << endl;
	cout << sizeof(double *) << endl;

    system("pause");
    return 0;
}