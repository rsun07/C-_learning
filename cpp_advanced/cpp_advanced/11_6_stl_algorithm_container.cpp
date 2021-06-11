#include<iostream>
using namespace std;

#include <algorithm>>
#include <vector>
#include <list>
#include <deque>

void testIntersection() {
	vector<int> v1{ 1,2,3,4,5 }, v2{ 3,4,4,4,5,6,7 }, vTarget(min(v1.size(), v2.size()));
	// can use `auto` here if don't want to write the long typename
	vector<int>::iterator lastElemIt = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	
	for_each(vTarget.begin(), vTarget.end(), [](int num) { cout << num << ", "; });
	cout << endl;

	// because we don't know the insersection length before, so will very likely assign more spaces/size. Here use the returned last element iterator to find the last element. 
	for_each(vTarget.begin(), lastElemIt, [](int num) { cout << num << ", "; });
	cout << endl;

	cout << "Last Element Value = " << *lastElemIt << endl;
	cout << endl;

	list<int> l{ 4,5,6,7,8 };
	// can be used between different types of containers. Return type decided by target container
	
	// doesn't support
	// set<int> s(min(l.size(), v1.size()));
	deque<int> d(min(l.size(), v1.size()));

	deque<int>::iterator dequeLastElemIt = set_intersection(v1.begin(), v1.end(), l.begin(), l.end(), d.begin());
	for_each(d.begin(), d.end(), [](int num) { cout << num << ", "; });
	cout << endl;

	for_each(d.begin(), dequeLastElemIt, [](int num) { cout << num << ", "; });
	cout << endl;
}

void testUnion() {
	vector<int> v{ 1,2,3,4,5 };
	list<int> l{ 4,5,6 };

	deque<int> d(v.size() + l.size());
	
	deque<int>::iterator dequeLastElemIt = set_union(v.begin(), v.end(), l.begin(), l.end(), d.begin());

	for_each(d.begin(), d.end(), [](int num) { cout << num << ", "; });
	cout << endl;

	for_each(d.begin(), dequeLastElemIt, [](int num) { cout << num << ", "; });
	cout << endl;
}

/*
1, 2, 3, 0, 0, 0, 0, 0, 0,
1, 2, 3,
6, 7, 3, 0, 0, 0, 0, 0, 0,
6, 7,
*/
void testDifference() {
	vector<int> v{ 1,2,3,4,5 };
	list<int> l{ 4,5,6,7 };

	deque<int> d(v.size() + l.size());

	// must be sequencial containers, cannot use set here
	// though deque isn't perfectly sequencial in fact, but it pretend to be sequencial to outside
	deque<int>::iterator dequeLastElemIt = set_difference(v.begin(), v.end(), l.begin(), l.end(), d.begin());

	for_each(d.begin(), d.end(), [](int num) { cout << num << ", "; });
	cout << endl;

	for_each(d.begin(), dequeLastElemIt, [](int num) { cout << num << ", "; });
	cout << endl;

	// put l first, then v
	dequeLastElemIt = set_difference(l.begin(), l.end(), v.begin(), v.end(), d.begin());

	for_each(d.begin(), d.end(), [](int num) { cout << num << ", "; });
	cout << endl;

	for_each(d.begin(), dequeLastElemIt, [](int num) { cout << num << ", "; });
	cout << endl;
}

int main() {
	testIntersection();
	cout << "\n\n" << endl;

	testUnion();
	cout << "\n\n" << endl;
	
	testDifference();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}