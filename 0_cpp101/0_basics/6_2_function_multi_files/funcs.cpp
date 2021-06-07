#include "funcs.h"

void print(int a, int b) {
	cout << "a = " << a << ", b = " << b << endl;
}

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	print(a, b);
	return;
}