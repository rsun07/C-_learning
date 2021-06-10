#include<iostream>
using namespace std;

void testFind() {
	string str1 = "abcdefg";
	cout << "Find char `c` in \"abcdefg\"  " << str1.find('c') << endl;
	cout << "Find string `cd` in \"abcdefg\"  " << str1.find("cd") << endl;
	cout << "Find string `ca` in \"abcdefg\"  " << str1.find("ca") << endl;

	string str2 = "abcebcdf";
	cout << "Find string `bc` from pos 1 in \"abcebcdf\"  " << str2.find("bc", 1) << endl;
	cout << "Find string `bc` from pos 2 in \"abcebcdf\"  " << str2.find("bc", 2) << endl;
	cout << "Find string `bcd`'s first 2 chars from pos 1 in \"abcebcdf\"  " << str2.find("bc", 1, 2) << endl;

	cout << endl;
	cout << "RFind string `bc` in \"abcebcdf\"  " << str2.rfind("bc") << endl;
	cout << "RFind string `bc` from rear pos 1 in \"abcebcdf\"  " << str2.rfind("bc", 1) << endl;
	// position still be the index from 0, return value is count from rear
	// find the last position query string appear in original string. find() is find the first appear from left
	cout << "RFind string `bc` from rear pos 2 in \"abcebcdf\"  " << str2.rfind("bc", 2) << endl;
}

void testReplace() {
	string str1 = "abcdefg";
	cout << "original string is " << str1 << endl;

	// replace from position, n chars to str or char* 
	str1.replace(2, 3, "12345");
	cout << "after str1.replace(2, 3, \"12345\") : " << str1 << endl;
	
	// this is ok, will extend the length of the string append
	str1.replace(5, 5, "ABCDEFG");
	cout << "after str1.replace(5, 5, \"ABCDEFG\") : " << str1 << endl;

	// out of boundary, will cause run time error
	// str1.replace(20, 2, "*****");
	// cout << "after str1.replace(20, 2, \"*****\") : " << str1 << endl;
}

void testInsertAndErase() {
	string str = "abcdefg";
	str.insert(2, "123");
	cout << "str.insert(2, \"123\")\t\t" << str << endl;

	// May think it has this function, insert in position 3, first 2 chars for string "*****", but STL doesn't have it
	//str.insert(3, 2, "******");
	str.insert(3, 2, '*');
	cout << "str.insert(3, 2, '*')\t\t" << str << endl;

	str.erase(2, 1);
	cout << "str.erase(2, 1)\t\t" << str << endl;

	str.erase(7, 10);
	cout << "str.erase(7, 10)\t\t" << str << endl;
}


void testSubstring() {
	string str = "hello_cpp@gmail.com";
	cout << "str.substr(2, 5)\t" << str.substr(2, 5) << endl;
	cout << "str.substr(15, 25)\t" << str.substr(15, 25) << endl;

	int pos = str.find('@');
	string userName = str.substr(0, pos);
	cout << "user name is " << userName << endl;
}

int main() {
	testFind();
	cout << endl;
	testReplace();
	cout << endl;
	testInsertAndErase();
	cout << endl;
	testSubstring();

	system("pause");
	return 0;
}