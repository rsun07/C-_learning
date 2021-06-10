#include<iostream>
using namespace std;

#include <algorithm>
#include <vector>
#include <list>
#include <deque>

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

	for_each(v.begin(), v.end(), [](int num) {cout << num << ", "; });
	cout << endl;

	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int num) {cout << num << ", "; });
	cout << endl;
}

void testMerge() {
	vector<int> v{ 1,2,3 };
	deque<int> d{ 4,5,6,7 };
	list<int> l(v.size() + d.size());
	for_each(l.begin(), l.end(), [](int num) {cout << num << ", "; });
	cout << endl;

	merge(v.begin(), v.end(), d.begin(), d.end(), l.begin());
	for_each(l.begin(), l.end(), [](int num) {cout << num << ", "; });
	cout << endl;
}

void testReverse() {
	vector<int> v{1,2,3,4,5,6,7};

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int num) {cout << num << ", "; });
	cout << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int num) {cout << num << ", "; });
	cout << endl;

	reverse(v.begin() + 1, v.end() - 2);
	for_each(v.begin(), v.end(), [](int num) {cout << num << ", "; });
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