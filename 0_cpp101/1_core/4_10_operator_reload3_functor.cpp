#include<iostream>
using namespace std;

// reload () operator, it looks like a function, so called functor
// functor is wildly used in STL, also cpp 11 lambda could replace functor. Will see and learn later.

class MyPrint {
public:
	void operator()(string text) {
		cout << "from my print: " << text << endl;
	}
};

class MyAdd {
public:
	int operator()(int n1, int n2) {
		return n1 + n2;
	}
};

int main() {
	MyPrint print;
	// these are objects, not function call
	print("1");
	print("Hello World");

	MyAdd myAdd;
	int sum = myAdd(1,2);
	print(std::to_string(sum));

	// use anonymous instance
	cout << "MyAdd()(3,4) = " << MyAdd()(3,4) << endl;

	return 0;
}

