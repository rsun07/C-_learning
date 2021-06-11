#include<iostream>
using namespace std;

#include <algorithm>
#include <vector>
#include <list>

void printNumFunc(int num) {
	cout << num << ", ";
}

class PrintNumFunctor {
public:
	void operator()(int num) {
		cout << num << ", ";
	}
};

class TransformNum {
public:
	int operator()(int num) {
		return num * 10;
	}
};

int main() {

	vector<int> v{ 1,2,3,4,5 };
	for_each(v.begin(), v.end(), printNumFunc);
	cout << endl;

	for_each(v.begin(), v.end(), PrintNumFunctor());
	cout << endl;

	cout << endl;
	list<int> target;
	
	// need resize before transforming, otherwise will cause run time error "Cannot rereference end iterator"
	 target.resize(v.size());
	transform(v.begin(), v.end(), target.begin(), TransformNum());
	for_each(target.begin(), target.end(), PrintNumFunctor());
	cout << endl;

	// must get the iterator before resize, and cannot use the end iterator, must use last value iterator, because end iterator is a fake node.
	// Only list iterator could be used after resize because it's linked list implementation.
	// Other iterators, they will change after resize. E.g, vector, will move all element to a new memory space. 
	list<int>::iterator valueEndIt = --target.end();
	target.resize(target.size() * 2);

	// append to existing list end
	transform(target.begin(), valueEndIt, ++valueEndIt, TransformNum());
	for_each(target.begin(), target.end(), PrintNumFunctor());
	cout << endl;

	system("pause");
	return 0;
}