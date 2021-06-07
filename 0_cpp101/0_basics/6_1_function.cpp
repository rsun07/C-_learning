#include<iostream>
using namespace std;

// can declare multiple times, but only define once
void swap(int a, int b);
void swap(int a, int b);
void swap(int a, int b);

// must declare here or move print before swap() method
// otherwise will see compile error swap don't know print(a,b)
void print(int a, int b);


void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	print(a, b);
	return;
}

// overload
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void printArr(int arr[], int size) {
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << ",";
	cout << endl;
}

void print(int a, int b) {
	cout << "a = " << a << ", b = " << b << endl;
}

int main() {

	int a = 1, b = 2;

	print(a, b);
	swap(a, b);
	cout << "after swap" << endl;
	print(a, b);

	cout << endl;
	int arr[3] = {1,2,3};
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	swap(arr, 0, 2);
	printArr(arr, sizeof(arr) / sizeof(arr[0]));

    system("pause");
    return 0;
}