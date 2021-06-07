#include<iostream>
using namespace std;

int main() {
	int a = 1;
	int b = 2;

	//const modify type, can change pointer target, cannot change variable value
	const int* p1 = &a;
	p1 = &b; // valid, change pointer target
	// *p1 = 100; // invalid, read-only variable is not assignable
	cout << "a = " << a << ", b = " << b << endl;

	//const is decorate/modify variable p2. So cannot change pointer target, but can change target value
	int* const p2 = &a;
	// p2 = &b; // invalid, cannot assign to variable 'p2' with const-qualified type 'int *const'
	*p2 = 10; // valid
	cout << "a = " << a << ", b = " << b << endl;	

	const int* const p3 = &a;
	//p3 = &b; // invalid
	//*p3 = 100; // invalid
	
	system("pause");
	return 0;
}