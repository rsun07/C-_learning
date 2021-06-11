#include<iostream>
using namespace std;

#include <deque>
#include <iterator>
#include <string>

template<class T>
void printDeque(const deque<T> & d) {
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << ", ";
	}
	cout << endl;
}

// almost the same as Vector
void testCreation() {
	deque<int> d1;
	for (int i = 0; i < 5; i++) {
		d1.push_back(i);
	}

	// create five 1 
	deque<int> d2(5, 1);

	deque<int> d3{ 1,2,3 };

	int arr[] = { 3,2,1 };
	deque<int> d4(arr, arr + 2);

	deque<int> d5(d2.begin(), d2.end() - 3);

	// fill with four 0 values
	deque<int> d6(4);

	deque<int> d7(d6);

	deque<int> d8;
	d8 = d7;
	d8.push_back(11);

	deque<int> d9;
	d9.assign(d8.begin(), d8.end() - 3);

	deque<int> d10;
	// assign three value 22 into deque
	d10.assign(3, 22);

	printDeque(d1);
	printDeque(d2);
	printDeque(d3);
	printDeque(d4);
	printDeque(d5);
	printDeque(d6);
	printDeque(d7);
	printDeque(d8);
	printDeque(d9);
	printDeque(d10);
}

template<class T>
void printDequeWithSize(const deque<T>& d) {
	printDeque<T>(d);
	cout << "d.size() = " << d.size() << ", d.max_size() = " << d.max_size() << endl;
	cout << endl;
}

void testBasicConfig() {
	deque<int> d{ 1,2,3};
	cout << "d.size() = " << d.size() << ", d.max_size() = " << d.max_size() << ", d.empty() = " << d.empty() << endl;
	// there is no capacity for deque due to the implementation
	cout << endl;

	d.resize(10);
	printDequeWithSize(d);
	
	d.resize(2);
	printDequeWithSize(d);

	// if longer than size, use * to fill
	d.resize(5, 11);
	printDequeWithSize(d);
}

void testEditValue() {
	deque<int> d{ 1,2,3 };

	d.push_back(4);
	d.push_front(0);
	printDeque(d);

	d.pop_front();
	d.pop_back();
	printDeque(d);

	// wrong, not index, but iterator
	// d.insert(2, 11);
	// d.insert(3, 3, 22);

	 d.insert(d.begin() + 2, 11);
	 printDeque(d);
	 d.insert(d.begin() + 3, 3, 22);
	 printDeque(d);

	 deque<int> d2{100,200,300};
	 d.insert(d.begin() + 1, d2.begin() + 1, d2.end());
	 printDeque(d);

	 d.erase(d.begin());
	 printDeque(d);

	 d.erase(d.begin() + 2, d.end() - 1);
	 printDeque(d);

	 d.clear();
	 printDeque(d);
}

#include <algorithm>

void testSort() {
	deque<int> d1{ 5,3,2,3,4,7,11,2,4 };
	sort(d1.begin() + 2, d1.end() - 1);
	printDeque(d1);

	deque<string> d2{ "ac", "abd", "aaa", "a" };
	sort(d2.begin(), d2.end());
	printDeque(d2);
}

int main() {
	testCreation();
	cout << "\n\n" << endl;

	testBasicConfig();
	cout << "\n\n" << endl;

	// get value is the same as vector, pass here

	testEditValue();
	cout << "\n\n" << endl;

	testSort();

	system("pause");
	return 0;
}