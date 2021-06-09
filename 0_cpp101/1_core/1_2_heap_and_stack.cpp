#include<iostream>
using namespace std;

int* func1(int b) { // formal variable b will be also put in stack
	b = 100;

	// local variable, will be put in stack
	// memory will be released after func1 execution
	int a = 1;
	cout << "Memory address of a in func1: " << (long long)&a << ", a value is : " << a << endl;
	cout << "Memory address of b in func1: " << (long long)&b << ", b value is : " << b << endl;

	// warning: address of stack memory associated with local variable 'a' returned [-Wreturn-stack-address]
	return &a;
}

int* func2() {
	int* a = new int(1); // heap is created by new by developer
	cout << "Memory address of a in func2: " << (long long)a << ", a value is : " << *a << endl;
	return a;
}

int main() {

	int b = 1;
	int* pa = func1(b);

	// sometimes can get the same address in func1 because compiler will keep the value for once.
	// if print multiple times, it will loss the address of variable a
	cout << "Memory address of a in main: " << (long long)pa << endl;
	cout << "Memory address of b in main: " << (long long)&b << ", b value is : " << b << endl;
	
	int* pa2 = func2();
	cout << "Memory address of a2 in main: " << (long long)pa2 << ", a2 value is : " << *pa2 << endl;

	delete pa2;
	cout << "Memory address of a2 in main: " << (long long)pa2 << ", a2 value is : " << *pa2 << endl;

	system("pause");
    return 0;
}


/*

Memory address of a in func1: 140737452071028, a value is : 1
Memory address of b in func1: 140737452071020, b value is : 100
Memory address of a in main: 0
Memory address of b in main: 140737452071060, b value is : 1
Memory address of a in func2: 94565736221760, a value is : 1
Memory address of a2 in main: 94565736221760, a2 value is : 1
Memory address of a2 in main: 94565736221760, a2 value is : -1275982536
*/