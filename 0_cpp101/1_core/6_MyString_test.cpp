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
	MyString s1 = {"abc", 3};
	cout << s1 << endl;

	MyString s2("bcdef", 5);
	cout << s2 << endl;
	
	MyString s3 = s1, s4(s2);
	cout << s3 << endl;
	cout << s4 << endl;

	cout << endl;

    // static array, will be put in memory stack, you cannot delete[] it. It will be distructed automatically. 
    {
        MyS arr[] = { MyS(), MyS(), MyS()};
    }
    cout << endl;
    
    // dynamic array, most dynamic array, we don't know the size beforehand. need pass in an capacity parameter for size. 
	MyS* arr1 = new MyS[3]{ MyS(), MyS(), MyS() };
	delete[] arr1;

	cout << endl;

	// wrong, will only distruct one
	MyS* arr2 = new MyS[3]{ MyS(), MyS(), MyS() };
	delete arr2;

	cout << endl;

	return 0;
}

/*
abc
bcdef
abc
bcdef

MyS constructor
MyS constructor
MyS constructor
MyS destructor
MyS destructor
MyS destructor

MyS constructor
MyS constructor
MyS constructor
MyS destructor
MyS destructor
MyS destructor

MyS constructor
MyS constructor
MyS constructor
MyS destructor
*/