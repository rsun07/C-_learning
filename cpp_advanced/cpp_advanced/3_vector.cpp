#include <iostream>
using namespace std;
#include <string>

#include <vector>
#include <iterator>
#include "utils.cpp"

template<class T>
void printVector(const vector<T>& v) {
	for (auto element : v) {
		cout << element << ", ";
	}
	cout << endl;
}

template<class T>
void printVectorAndCapacity(const vector<T>& v) {
	printVector<T>(v);
	cout << "v capacity = " << v.capacity() << ", v size = " << v.size() << endl;
	cout << endl;
}

void testCreation() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);
	
	// initialize an vector with five 1
	vector<int> v2(5, 1);
	printVector(v2);

	vector<int> v3{ 1,2,3,4,5 };
	printVector(v3);

	int arr[] = { 5,4,3,2,1 };
	// initial with first 3 element in array;
	vector<int> v4(arr, arr + 3);
	printVector(v4);

	vector<int> v5(v2.begin(), v2.end());
	printVector(v5);

	vector<int> v6(v2.begin(), v2.end() - 3);
	printVector(v6);

	// will cause run time error out of boundary
	// vector<int> v62(v2.begin(), v2.end() + 3);
	// printVector(v62);

	// here the 6 is initial capacity
	vector<int> v7(6);
	// fill with value 0
	fill(v7.begin(), v7.end(), 0);
	printVector(v7);

	vector<int> v8;
	v8 = v6;
	printVector(v8);

	vector<int> v9;
	v9.assign(v6.begin(), v6.end());
	printVector(v9);

	vector<int> v10;
	// assign three value 101 into vector;
	v10.assign(3, 101);
	printVector(v10);
}

void testBasicConfig() {
	vector<int> v1{ 1,2,3,4,5 };
	cout << v1.empty() << endl; // 0

	vector<string> v2;
	cout << v2.empty() << endl; // 1

	cout << "v1 capacity = " << v1.capacity() << ", v1 size = " << v1.size() << endl;
	cout << "v2 capacity = " << v2.capacity() << ", v2 size = " << v2.size() << endl;
	// v1 capacity = 5, v1 size = 5
	// v2 capacity = 0, v2 size = 0
	cout << endl;

	// this value set 7 or 8 or 9 will cause later capacity value different among (10 or 12 or 13), maybe due to the resize alghrotihm, need some source code learning
	v1.resize(9);
	printVectorAndCapacity(v1);

	// resize to 10, empty part use value 11 to fill
	v1.resize(10, 11);
	printVectorAndCapacity(v1);

	// resize to 3, remove element from index 3
	v1.resize(3, 22);
	printVectorAndCapacity(v1);
}

void testGetValue() {
	vector<string> v1{ "a", "aa", "abc" };
	cout << v1[1] << endl;
	cout << v1.at(2) << endl;
	// out of boundary, run time error
	// cout << v1[20] << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;
	
	// binary '<<': no operator found which takes a right - hand operand of type 'std::_Vector_iterator<std::_Vector_val<std::_Simple_types<_Ty>>>' (or there is no acceptable conversion)
	//cout << v1.begin() << endl;
	//cout << v1.end() << endl;
	cout << *v1.begin() << endl;
	// end is not the last, end - 1 is the last
	cout << *(v1.end()-1) << endl;
}

void testEditValue() {
	vector<int> v{ 1,2,3,4,5 };
	printVectorAndCapacity(v);
	
	v.push_back(1);
	printVectorAndCapacity(v);

	v.pop_back();
	printVectorAndCapacity(v);

	// v.begin() gives an iterator
	v.insert(v.begin(), 0);
	printVectorAndCapacity(v);

	v.insert(v.begin() + 2, 0);
	printVectorAndCapacity(v);

	// insert three element 11 at the iterator position
	v.insert(v.end(), 3, 11);
	printVectorAndCapacity(v);

	v.erase(v.end() - 3);
	printVectorAndCapacity(v);

	v.erase(v.begin() + 2, v.end() - 2);
	printVectorAndCapacity(v);

	v.clear();
	printVectorAndCapacity(v);
}

void testSwap() {
	vector<int> v1{ 1,2,3,4,5 }, v2{5,4,3,2,1};
	printVector(v1);
	printVector(v2);
	cout << endl;

	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	cout << endl;

	v2.swap(v1);
	printVector(v1);
	printVector(v2);
	cout << endl;

	vector<int> v3;
	v3.assign(20, 1);
	
	v1.swap(v3);
	printVectorAndCapacity(v1);
	printVectorAndCapacity(v3);

	v3.swap(v1);
	v3.resize(2);
	printVectorAndCapacity(v3);

	// use anonymous vector object to resize capacity
	vector<int>(v3).swap(v3);
	printVectorAndCapacity(v3);
}

// check and print how many time of resize(auto scale) during insertion
void reserveTestHelper(vector<int> & v) {
	int count = 0;
	int* pFirstElem = NULL;
	printVectorAndCapacity(v);

	for (int i = 0; i < 100; i++) {
		v.push_back(i);
		// means an new vector arr, resize happened
		if (pFirstElem != &v[0]) {
			pFirstElem = &v[0];
			count++;
		}
	}

	cout << count << endl;
}

// reserve space in advance if you know the capacity in advance to avoid vector resizing multiple times when adding new elements
void testReserve() {
	vector<int> v1;
	reserveTestHelper(v1);

	vector<int> v2;
	v2.reserve(100);
	reserveTestHelper(v2);

	
	// vector<int> v3;
	// v3.reserve(100);
	
	// will cause out of boundary run time issue
	// cout << v3[10] << endl;
}

int main() {
	Utils::printTestMsg("testCreation");
	testCreation();
	Utils::printTestMsg("testBasicConfig");
	testBasicConfig();
	Utils::printTestMsg("testGetValue");
	testGetValue();
	Utils::printTestMsg("testEditValue");
	testEditValue();
	Utils::printTestMsg("testSwap");
	testSwap();
	Utils::printTestMsg("testReserve");
	testReserve();
	Utils::printTestMsg("");

	system("pause");
	return 0;
}