#include<iostream>
using namespace std;

// error: missing default argument on parameter 'c'
// if b has default value, all the parameters later must also have
// int func(int a, int b = 10, int c) {
// 	return a+b+c;
// }

int func(int a, int b = 1, int c = 2) {
	return a+b+c;
}

// func reload
int func(int a, int b) {
	return a+b;
}

int main() {

	cout << "res = " << func(10) << endl;
	// error: call to 'func' is ambiguous
	// cout << "res = " << func(10, 20) << endl;
	cout << "res = " << func(10, 20, 30) << endl;

	system("pause");
    return 0;
}
