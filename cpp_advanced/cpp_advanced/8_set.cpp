#include<iostream>
using namespace std;

#include <list>
#include <set>
#include <iterator>
#include <string>

template<typename T>
void printSet(const set<T>& s) {
	for (auto e : s) {
		cout << e << ";  ";
	}
	cout << endl;
}

// simiar to vector, deque and list
void testCreation() {
	set<int> s1;
	s1.insert(1);
	s1.insert(2);

	set<int> s2{ 3,2,1 };

	// initialize with five value 1
	// because set doesn't allow duplicate value, so this one is not meaningful, and will cause error
	// set<int> s3(5, 1);

	int arr[] = { 4,5,6 };
	set<int> s4(arr, arr + 2);

	list<int> l{ 6,7,8 };
	set<int> s5(l.begin(), l.end());

	set<int> s6(++s2.begin(), s2.end());

	set<int> s7(s1);

	set<int> s8;
	s8 = s2;

	//set<int> s9;
	// no assign method, because set has no order
	// s9.assign(s3.begin(), s3.end());

	printSet(s1);
	printSet(s2);
	// printSet(s3);
	printSet(s4);
    printSet(s5);
	printSet(s6);
	printSet(s7);
	printSet(s8);
}

void testBasicConfig() {
	set<int> s{ 1,2,3,4,5,6 };
	set<int> s2{ 9,8,7 };

	printSet(s);
	printSet(s2);

	s.my_swap(s2);

	cout << endl;
	printSet(s);
	printSet(s2);
	// set doesn't support resize.
}

void testEditValue() {
	set<int> s{ 1,2,3 };
	s.insert(4);
	s.insert(0);
	printSet(s);

	// erase element
	s.erase(2);
	printSet(s);

	s.erase(6);
	printSet(s);

	// erase by iterator
	s.erase(s.begin());
	printSet(s);

	s.erase(++s.begin(), --s.end());
	printSet(s);

	// illegal as set doesn't have order, implementation is binary tree
	//s.begin() + 2;

	s.clear();
	printSet(s);
}

template<typename T>
void printMultiset(const multiset<T>& s) {
	for (auto e : s) {
		cout << e << ";  ";
	}
	cout << endl;
}

void setVsMultiset() {
	set<int> s{ 1,1,1,2,3 };
	multiset<int> ms{ 1,1,1,2,3 };
	pair<set<int>::iterator, bool> res = s.insert(1);
	multiset<int>::iterator it = ms.insert(1);
	printSet(s);
	printMultiset(ms);
	cout << "set insert result, iterator value is "<< *(res.first) <<  ", res bool val " << res.second << endl;
	cout << "multiset insert result, iterator value is " << *it << endl;
	cout << "set insert result, iterator next value is " << *(++res.first) << endl;
	cout << "multiset insert result, iterator next value is " << *(++it) << endl;

	cout << endl;
	set<int>::iterator searchRes1 = s.find(1);
	set<int>::iterator searchRes2 = s.find(9);
	cout << "s search res for 1: " << (searchRes1 != s.end()) << endl;
	cout << "s search res for 9: " << (searchRes2 != s.end()) << endl;

	multiset<int>::iterator msSearchRes1 = ms.find(1);
	multiset<int>::iterator msSearchRes2 = ms.find(9);
	cout << "ms search res for 1: " << (msSearchRes1 != ms.end()) << endl;
	cout << "ms search res for 9: " << (msSearchRes2 != ms.end()) << endl;


	cout << endl;
	int count1 = s.count(1), count2 = s.count(9), count3 = ms.count(1), count4 = ms.count(9);
	cout << "s count res for 1: " << count1 << endl;
	cout << "s count res for 9: " << count2 << endl;
	cout << "ms count res for 1: " << count3 << endl;
	cout << "ms count res for 9: " << count4 << endl;
}

// functor
class SetDescCompare {
public:
	bool operator()(int n1, int n2) const {
		return n1 > n2;
	}
};

// default order is ascend
void setOrder() {
	set<int, SetDescCompare> s{ 1,1,4,2,3,7,5,4,2,1 };
	
	// cannot use this method as this set has two template types
	// printSet(s);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
}

int main() {
	testCreation();
	cout << "\n\n" << endl;
	testBasicConfig();
	cout << "\n\n" << endl;
	testEditValue();
	cout << "\n\n" << endl;
	setVsMultiset();
	cout << "\n\n" << endl;
	setOrder();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}