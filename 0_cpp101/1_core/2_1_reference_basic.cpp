#include<iostream>
using namespace std;

int main() {

	int a = 1;
	int &b = a;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 2;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	// error: declaration of reference variable 'c' requires an initializer
	// int &c;

	int c = 3;
	// once initialize, cannot change reference
	int &d = a;
	// this is value assignment, not change reference;
	d = c;

	cout << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	system("pause");
    return 0;
}
