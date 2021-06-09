#include "MyString.hpp"


class MyS {
public:
	MyS() {
		cout << "MyS constructor" << endl;
	}

	~MyS() {
		cout << "MyS destructor" << endl;
	}
};

int main() {
	MyString s1 = "abc";
	cout << s1 << endl;

	MyString s2("bcdef");
	cout << s2 << endl;
	
	MyString s3 = s1, s4(s2);
	cout << s3 << endl;
	cout << s4 << endl;

	cout << endl;

	MyS arr[] = { MyS(), MyS(), MyS() };
	delete[] arr;

	cout << endl;

	// wrong, will cause program crash, it will keep calling destructor
	// MyS arr2[] = { MyS(), MyS(), MyS() };
	// delete arr2;

	cout << endl;

	return 0;
}

