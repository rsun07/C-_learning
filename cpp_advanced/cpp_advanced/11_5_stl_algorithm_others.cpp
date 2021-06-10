#include<iostream>
using namespace std;

#include <numeric>
#include <vector>
#include <set>

void testAccumulate() {
	vector<int> v{1, 2, 3};
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << "sum = " << sum << endl;

	set<double> s{ 1.1, 1.2, 3.5, -15.1 };
	cout << "sum = " << accumulate(s.begin(), s.end(), 100) << endl;
	cout << "sum = " << accumulate(s.begin(), s.end(), 100.0) << endl;
}

template<class T>
void printVector(const vector<T> v) {
	for (auto e : v) {
		cout << e << ", ";
	}
	cout << endl;
}

void testFill() {
	vector<int> v1;
	fill(v1.begin(), v1.end(), 11);
	printVector(v1);

	v1.resize(3);
	printVector(v1);
	fill(v1.begin(), v1.end(), 11);
	printVector(v1);

	// overwrite the previous values
	fill(v1.begin(), v1.end(), 22);
	printVector(v1);

	// same result
	vector<int> v2(5, 33);
	printVector(v2);
}

int main() {
	testAccumulate();
	cout << "\n\n" << endl;

	testFill();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}