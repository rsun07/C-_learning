#include<iostream>
using namespace std;

#include<functional>

void arithmeticFuncs() {
	negate<int> neg;
	cout << neg(1) << endl;
	cout << neg(-1) << endl;
	cout << neg(99999999999999999) << endl;

	//negate<string> neg2;
	//cout << neg2("abc") << endl;

	cout << endl;

	plus<double> p;
	cout << p(1.1,2.2) << endl;

	// similarly, minus<T>, multiplies<T>, divides<T>, moduleus<T>
}

#include <vector>
#include <algorithm>

template<class T>
void printVector(const vector<T> & v) {
	for (auto e : v) {
		cout << e << ", ";
	}
	cout << endl;
}

void relationFuncs() {
	equal_to<double> et;
	cout << et(1, 1) << endl;
	cout << et(1.00000000000001, 1) << endl;
	cout << endl;

	vector<int> v{3,7,5,6,8,11,23,1,14};
	printVector(v);
	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
	// use less<int>() is the same here
	sort(v.begin(), v.end(), less_equal<int>());
	printVector(v);
}

void logicFuncs() {
	logical_not<bool> ln;
	cout << ln(true) << endl;
	cout << ln(false) << endl;
}

int main() {

	arithmeticFuncs();
	cout << "\n\n" << endl;
	
	relationFuncs();
	cout << "\n\n" << endl;

	logicFuncs();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}