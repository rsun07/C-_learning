#include<iostream>
using namespace std;

template<typename T>
void my_swap(T& a, T& b) {
	cout << "Calling template my_swap(T& a, T& b)\n" << endl;
	T temp = a;
	a = b;
	b = temp;
}

// normal func overload
// in practice, we'd better avoid this type of overload to avoid ambiguty
// Or write a template<> to make it specialization
void my_swap(char& a, char& b) {
	cout << "Calling my_swap(char& a, char& b)\n" << endl;

	char temp = a;
	a = b;
	b = temp;
}


// template specialization
// const not allowed for non member function. with const, is considered as a different function signature
template<>
void my_swap<double>(double& a, double& b) /*const */ {
	cout << "Calling template my_swap(double& a, double& b)\n" << endl;
	double temp = a;
	a = b;
	b = temp;
}


// class is the same as typename. This is because historical reasons, before, there is no typename keyword, so use class
template<class T>
void print(T& a, T& b) {
	cout << "a = " << a << ", b = " << b << endl;
}

template<class T>
void func() {
	cout << "Call function func\n" << endl;
}

int main() {
	int a = 10;
	int b = 20;

	print(a, b);
	// auto detect type
	my_swap(a, b);
	print(a, b);

	std::cout << std::endl;

	double c = 1.5, d = 3.5;
	print(c, d);
	// indicate type
	my_swap<double>(c, d);
	print(c, d);

	// must be the same type
	// swap(a, c);

	cout << endl;

	// Error(active)	E0304	no instance of function template "func" matches the argument list
	// func();

	// must indicate type
	func<std::string>();

	cout << endl;

	char ca = 'a', cb = 'b';
	// func overload will be called in this case
	my_swap(ca, cb);

	// specify calling template
	my_swap<>(ca, cb);

	cout << endl;


	// doesn't work for array
	// cannot assign value to an array use operator =
	int arr1[3] = { 1,2,3 }, arr2[3] = { 3,4,5 };
	// swap(arr1, arr2);

	system("pause");
	return 0;
}

/*
a = 10, b = 20
Calling template my_swap(T& a, T& b)

a = 20, b = 10

a = 1.5, b = 3.5
Calling template my_swap(double& a, double& b)

a = 3.5, b = 3.5

Call function func


Calling my_swap(char& a, char& b)

Calling template my_swap(T& a, T& b)
*/