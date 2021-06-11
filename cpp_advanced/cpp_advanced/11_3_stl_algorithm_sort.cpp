#include<iostream>
using namespace std;

#include <algorithm>
#include <vector>
#include <list>
#include <deque>

#include "Utils.cpp"

void testSort() {
	// used before muiltiple times
}

void testShuffle() {
	vector<int> v{ 1,2,3,4,5 };

	// give different seed every time when run random
	// if use rand(), then everytime will be the same seed
	srand((unsigned int)time(NULL));

	// use lambda
	for_each(v.begin(), v.end(), [](int num) {cout << num << ", "; });
	cout << endl;

	random_shuffle(v.begin(), v.end());
	Utils::printCollection(v);
	cout << endl;

	random_shuffle(v.begin(), v.end());
	Utils::printCollection(v);
	cout << endl;
}

// Can merge among different type of containers using iterators
void testMerge() {
	vector<int> v{ 1,2,3 };
	deque<int> d{ 4,5,6,7 };
	// I believe initial with size is not required for list due to the linked list implementation
	// But in fact, must initialize with size, otherwise will cause run time error: Cannot differentiate list end iterator
	list<int> l(v.size() + d.size());
	Utils::printCollection(v);
	Utils::printCollection(d);
	Utils::printCollection(l);
	cout << endl;

	merge(v.begin(), v.end(), d.begin(), d.end(), l.begin());
	Utils::printCollection(l);
	cout << endl;
}

void testReverse() {
	vector<int> v{1,2,3,4,5,6,7};

	reverse(v.begin(), v.end());
	Utils::printCollection(v);
	cout << endl;

	reverse(v.begin(), v.end());
	Utils::printCollection(v);
	cout << endl;

	reverse(v.begin() + 1, v.end() - 2);
	Utils::printCollection(v);
	cout << endl;
}

int main() {
	testSort();
	cout << "\n\n" << endl;

	testShuffle();
	cout << "\n\n" << endl;

	testMerge();
	cout << "\n\n" << endl;

	testReverse();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}