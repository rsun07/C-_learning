#include<iostream>
using namespace std;


void print(int a, int b) {
	cout << "a = " << a << ", b = " << b << endl;
}

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap(int * pa, int * pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

// int* arr is the same as int arr[].
// it's the pointer that point to the first element in the array
void printArray(int* arr, int len) { 
	cout << endl;
	//  warning: sizeof on array function parameter will return size of 'int *' instead of 'int []' [-Wsizeof-array-argument]
	cout << "printArray sizeof(arr) = " << sizeof(arr) << endl;
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}
	cout << endl;
	
	cout << "*arr = " << * arr << " , arr = " << arr << endl;
	cout << endl;
	
	// stop at end indicator
	for (int i = 0; i < len; i++, arr++) {
		cout << *arr << ",";
	}
	cout << endl;

	// the following doesn't work
	// while(arr != '\0')
	// while(arr != NULL)
	
	// because we moved pointer to later
	cout << "*arr = " << * arr << " , arr = " << arr << endl;
	// move 5 element 
	cout << "*(----------arr) = " << *(------------arr) << " , arr = " << arr << endl;
	cout << endl;
}

int main() {
	int a = 1;
	int b = 2;

	// pass as value, method swap will create new a and b varialbes using copy constructor
	swap(a, b);
	print(a, b);

	// pass as reference, same a and b passed into method swap
	swap(&a, &b);
	print(a, b);


	int arr[10] = {1,3,5,7,9};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	cout << "\n" << "main sizeof(arr) = " << sizeof(arr) << endl;

	printArray(arr, len);

	system("pause");
	return 0;
}