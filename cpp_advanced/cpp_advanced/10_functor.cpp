// function object or functor, it is an class.
// its object can be called like a function, but it could have its own state and can be passed like an parameter

#include<iostream>
using namespace std;

class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	}

	// override () operator
	void operator()(string msg) {
		cout << msg << endl;
		count++;
	}

	int getCount() {
		return this->count;
	}

private:
	// internal status
	int count;
};

void doPrint(MyPrint &printer, string msg) {
	printer(msg);
}

int main() {
	MyPrint printer;
	printer("P 1");
	printer("P 2");
	printer("P 3");

	cout << printer.getCount() << endl;

	cout << endl;
	doPrint(printer, "Pass to doPrint() method");

	system("pause");
	return 0;
}