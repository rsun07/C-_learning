#include<iostream>
using namespace std;

#include <algorithm>
#include <vector>
#include <list>

#include "Utils.cpp"

void testCopy() {
	vector<int> v{ 1,2,3 };
	// must initialize with size, otherwise will cause run time error: Cannot differentiate list end iterator
	list<int> l(v.size());
	Utils::printCollection(l);
	copy(v.begin(), v.end(), l.begin());
	Utils::printCollection(l);
	cout << endl;

	cout << endl;
	v.push_back(4);
	v.push_back(5);
	list<int>::iterator lastElemIt = --l.end();
	l.resize(l.size() + v.size());
	Utils::printCollection(l);
	cout << endl;

	// only list could keep the iterator after resize
	// copy v begin until v end into list. insert from the list iterator given here
	copy(v.begin(), v.end(), ++lastElemIt);
	Utils::printCollection(l);
	cout << endl;
}

void testReplace() {
	vector<int> v{ 1,2,3,3,2,3,2,3 };

	// replace all 3 to 300
	replace(v.begin(), v.end(), 3, 300);
	Utils::printCollection(v);
}

void testReplaceIf() {
	vector<int> v{ 1,2,3,4,2,3,2,4 };

	// can only replace qualified to a constant value, cannot to a dynamic expression
	// replace_if(v.begin(), v.end(), [](int num) {return num % 2 == 0; }, [](int num) {return num * 10; });
	replace_if(v.begin(), v.end(), [](int num) {return num % 2 == 0; }, 100);

	Utils::printCollection(v);
}

template<class T>
void printVectorAndSize(const vector<T> v) {
	Utils::printCollection(v);

	cout << "vector size = " << v.size() << ", vector capacity = " << v.capacity() << endl;
}


void testSwap() {
	vector<int> v1{ 1,2,3 };
	vector<int> v2{ 4,5,6,7,8,9 };
	printVectorAndSize(v1);
	printVectorAndSize(v2);
	cout << endl;

	swap(v1, v2);
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