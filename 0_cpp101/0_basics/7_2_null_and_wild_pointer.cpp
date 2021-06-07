#include<iostream>
using namespace std;

int main() {
	// assign memory index 0 address to p
	int* p = NULL;

	// memory address 0-255 is taken by system, cannot be accessed.
	cout << "p = " << p << endl;
	
	// will cause error exit
	// cout << "*p = " << *p << endl;

	// wild pointer
	// https://baike.baidu.com/item/%E9%87%8E%E6%8C%87%E9%92%88
	// https://www.geeksforgeeks.org/what-are-wild-pointers-how-can-we-avoid/

	// new feature since cpp11
	int* p2 = nullptr;
	cout << "p2 = " << p2 << endl;
	// won't be printed
	cout << "*p2 = " << *p2 <<endl;

	system("pause");
    return 0;
}