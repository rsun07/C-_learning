#include<iostream>
using namespace std;

int main() {

	int arr[10] = {1,2,3,4,5,6,7,8};

	// here not 10, it's 10*4 bytes (assume int is 4 byte in current compiler)
	cout << "Size of the whole array: " << sizeof(arr) << endl;
	cout << "Size of each element: " << sizeof(arr[0]) << endl;
	cout << "Element count : " << sizeof(arr) / sizeof(arr[0]) << endl;

	cout << "\n" << endl;

	cout << "Array memory address: " << (long long)arr << endl;
	cout << "Array first element memory address : " << (long long)&arr[0] << endl;
	cout << "Array second element memory address : " << (long long)&arr[1] << endl;

	cout << "\n" << endl;

	// output 1,2,3,4,5,6,7,8,0,0,%
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << ",";
	}


    system("pause");
    return 0;
}