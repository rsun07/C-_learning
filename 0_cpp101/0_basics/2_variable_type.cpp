#include<iostream>
using namespace std;

#include<typeinfo>

int main() {
	cout << "short size :\t\t" << sizeof(short) << endl;
	cout << "int size :\t\t" << sizeof(int) << endl;
	cout << "long size :\t\t" << sizeof(long) << endl;
	cout << "long long size :\t" << sizeof(long long) << endl;
	cout << "float size :\t" << sizeof(float) << endl;
	cout << "double size :\t" << sizeof(double) << endl;


	cout << "" << endl;
	float f1 = 3.14f;
	double d1 = 3.14;

	cout << f1 << endl;
	cout << d1 << endl;

	cout << "float sizeof = " << sizeof(f1) << endl;
	cout << "double sizeof = " << sizeof(d1) << endl;	


	cout << "" << endl;

	float f2 = 3e2; // 3* 10^2
	float f3 = 3e-2; // 3* 10^-2, 3*0.1^2
	cout << f2 << endl;
	cout << f3 << endl;


	cout << "" << endl;

	bool flag = true;
	cout << flag << endl; // 1
	flag = false;
	cout << flag << endl; // 0
	cout << "size of bool = " << sizeof(bool) << endl; //1


	cout << "" << endl;

	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;
	cout << typeid(d1).name() << endl;
	cout << typeid(flag).name() << endl;

    system("pause");
    return 0;
}