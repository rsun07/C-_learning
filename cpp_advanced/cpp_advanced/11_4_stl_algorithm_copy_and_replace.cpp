#include<iostream>
using namespace std;

#include <algorithm>
#include <vector>
#include <list>

void testCopy() {
	vector<int> v{ 1,2,3 };
	list<int> l(v.size());

	copy(v.begin(), v.end(), l.begin());
	for_each(l.begin(), l.end(), [](int num) {cout << num << ", "; });
	cout << endl;

	cout << endl;
	v.push_back(4);
	v.push_back(5);
	list<int>::iterator lastElemIt = --l.end();
	l.resize(l.size() + v.size());
	for_each(l.begin(), l.end(), [](int num) {cout << num << ", "; });
	cout << endl;

	// only list could keep the iterator after resize
	copy(v.begin(), v.end(), ++lastElemIt);
	for_each(l.begin(), l.end(), [](int num) {cout << num << ", "; });
	cout << endl;
}

template<class T>
void printVector(const vector<T> v) {
	for (auto e : v) {
		cout << e << ", ";
	}
	cout << endl;
}

void testReplace() {
	vector<int> v{ 1,2,3,3,2,3,2,3 };

	// replace all 3 to 300
	replace(v.begin(), v.end(), 3, 300);
	printVector(v);
}

void testReplaceIf() {
	vector<int> v{ 1,2,3,4,2,3,2,4 };

	// can only replace qualified to a constant value, cannot to varailbe
	// replace_if(v.begin(), v.end(), [](int num) {return num % 2 == 0; }, [](int num) {return num * 10; });
	replace_if(v.begin(), v.end(), [](int num) {return num % 2 == 0; }, 100);

	printVector(v);
}

template<class T>
void printVectorAndSize(const vector<T> v) {
	printVector(v);

	cout << "vector size = " << v.size() << ", vector capacity = " << v.capacity() << endl;
}


void testSwap() {
	vector<int> v1{ 1,2,3 };
	vector<int> v2{ 4,5,6,7,8,9 };
	printVectorAndSize(v1);
	printVectorAndSize(v2);
	cout << endl;

	my_swap(v1, v2);
	printVectorAndSize(v1);
	printVectorAndSize(v2);

	list<int> l{ 0,10,11,12 };
	// swap two container must be the same type
	// swap(l, v1);
}

int main() {
	testCopy();
	cout << "\n\n" << endl;

	testReplace();
	cout << "\n\n" << endl;

	testReplaceIf();
	cout << "\n\n" << endl;

	testSwap();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}