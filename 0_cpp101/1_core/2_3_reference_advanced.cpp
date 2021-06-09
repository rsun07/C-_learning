#include<iostream>
using namespace std;

// return local variable reference
int& getLocalNum() {
	int num = 1;
	// warning: reference to stack memory associated with local variable 'num' returned [-Wreturn-stack-address]
	return num;
}

// address
int& getLocalStaticNum() {
	static int num = 2;
	return num;
}

// use constant reference to avoid value change
void showValue(const int& v) {

	// error: cannot assign to variable 'v' with const-qualified type 'const int &'
	// v = 20;
	cout << " v in show value is : " << v << endl;
}

int main() {
	// cannot get reference because local variable will be destroyed after function execution
	int& ref1 = getLocalNum();
	cout << "ref1 = " << ref1 << endl;

	int& ref2 = getLocalStaticNum();
	cout << "ref2 = " << ref2 << endl;

	getLocalStaticNum() = 3;
	cout << "ref2 = " << ref2 << endl;


	cout << endl;

	// error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
	// must assign valid memory address before assign to a reference
	// int& ref = 5;

	// this works, compiler will improve the code to
	// int temp = 5; const int& ref = temp;
	const int& ref = 5;

	// error: cannot assign to variable 'ref' with const-qualified type 'const int &'
	// ref = 6;
	cout << "ref = " << ref << endl;


	int num = 7;
	showValue(num);

	system("pause");
    return 0;
}
