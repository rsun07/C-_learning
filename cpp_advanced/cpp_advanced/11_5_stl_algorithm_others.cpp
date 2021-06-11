#include<iostream>
using namespace std;

#include <numeric>
#include <vector>
#include <set>

#include <algorithm>

#include "Utils.cpp"

void testAccumulate() {
	vector<int> v{1, 2, 3};
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << "sum = " << sum << endl;

	set<double> s{ 1.1, 1.2, 3.5, -15.1 };
	cout << "sum = " << accumulate(s.begin(), s.end(), 100) << endl; // 89
	cout << "sum = " << accumulate(s.begin(), s.end(), 100.0) << endl; // 90.7
}

void testFill() {
	cout << "Test fill()" << endl;
	vector<int> v1;
	fill(v1.begin(), v1.end(), 11);
	// both following two print empty
	Utils::printCollection(v1);
	for_each(v1.begin(), v1.end(), [](int num) { cout << num << ", "; }); 
	cout << endl;

	v1.resize(3);
	Utils::printCollection(v1);
	fill(v1.begin(), v1.end(), 11);
	Utils::printCollection(v1);

	// overwrite the previous values
	fill(v1.begin(), v1.end(), 22);
	Utils::printCollection(v1);
	cout << "v1.capacity = " << v1.capacity() << endl;

	// will resize the vector automatically and fill with ten `33`
	vector<int> v2(10, 33);
	Utils::printCollection(v2);
}

int main() {
	testAccumulate();
	cout << "\n\n" << endl;

	testFill();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}