#include<iostream>
using namespace std;

int main() {

	char ch = 'a';
	cout << ch << endl;
	cout << sizeof(char) << endl;
	//ch = "abcde"; //Error
	//ch = 'abcde'; //Error
	cout << (int)ch << endl; // convert char to int, ASCII code
	ch = 65; // use ASCII code to initialize char
	cout << ch << endl;

	cout << "" << endl;

	// escape character
	cout << "\\" << endl;
	cout << "\tHello" << endl;
	cout << "\n" << endl;

	cout << "" << endl;

	// C style
	char str1[] = "hello world";
	cout << str1 << endl;

	// c++ style
	string str = "hello world";
	cout << str << endl;

	cout << "" << endl;

    system("pause");
    return 0;
}