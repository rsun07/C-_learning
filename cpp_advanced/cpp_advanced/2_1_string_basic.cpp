#include<iostream>
using namespace std;

void testConstructors() {
	string s1;

	// char* is a pointer, string is a class, encapsulating a char* inside to manage the char array
	const char* str = "hello world";
	string s2(str); 

	// use copy constructor
	string s3(s2);

	string s4(10, '*');
	
	cout << "s1 empty string = " << s1 << endl;
	cout << "s2 string = " << s2 << endl;
	cout << "s3 string = " << s3 << endl;
	cout << "s4 string = " << s4 << endl;
}

void testAssign() {
	string str1;
	str1 = "hello world";

	string str2 = str1;

	string str3;
	str3 = str1;

	// Error(active)	E0415	no suitable constructor exists to convert from "char" to "std::basic_string<char, std::char_traits<char>, std::allocator<char>>"
	// string str4 = 'a';

	string str4;
	str4 = 'a';

	string str5;
	str5.assign("hello c++");

	string str6;
	str6.assign(str5);

	string str7;
	str7.assign(8, '*');

	// assign from index 3 to all rest chars
	string str8;
	str8.assign(str5, 3);

	// not exist
	string str9;
	// str9.assign(5, str5);

	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
	cout << "str5 = " << str5 << endl;
	cout << "str6 = " << str6 << endl;
	cout << "str7 = " << str7 << endl;
	cout << "str8 = " << str8 << endl;
}

void testAppend() {
	string str1 = "Hello ";
	cout << str1 << endl;
	str1 += "World";
	cout << str1 << endl;
	str1 += "!";
	cout << str1 << endl;

	string str2 = " C++";
	str1 += str2;
	cout << str1 << endl;

	string str3("ABC");
	str3.append("DE");
	str3.append("abcdef", 3); // from index 0, pick 3 chars
	str3.append("12345", 2, 3); // from index 2, pick 3 chars

	cout << str3 << endl;

	int i = 5;
	char c = 'z';
	double d = 5.05;
	// + only apply to string, cannot apply to other type. For custom class, you need a conversion function to make it work.
	string str4 = str1 + "\t" + str2 + "\t" + str3 + "\t"  + c + '\t' + 'q' /*+ 1 + "\t"   + i + '\t' + d + '\t' + 5.06*/;
	cout << str4 << endl;
}

void testCompare() {
	string s1 = "a", s2 = "aaa", s3 = "ab";
	cout << "a compare aaa:  " << s1.compare(s2) << endl;
	cout << "aaa compare ab:  " << s2.compare(s3) << endl;
	cout << "a compare a:  " << s1.compare(s1) << endl;

	// wrong
	// "a".compare("a");
	s1.compare("aab");

	char* s4 = new char[5];
	s4[0] = 'b';
	s4[1] = 'z';

	// wrong
	// s4.compare(s1);
	cout << "s1 compare char* s4:  " << s1.compare(s4) << endl;
}

void printStrByChar(string &str) {
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << ", ";
	}
	cout << endl;
}

void testCharAccess() {
	string str = "abcdefg";
	printStrByChar(str);

	str[1] = 'z';
	str.at(5) = 'q';
	printStrByChar(str);

	// c and c++ don't have boundary check and restriction
	// won't have compiler error, will cause run time error
	str[19] = 'k';
	cout << str << endl;
}

int main() {
	testConstructors();
	cout << endl;
	testAssign();
	cout << endl;
	testAppend();
	cout << endl;
	testCompare();
	cout << endl;
	testCharAccess();

	system("pause");
	return 0;
}