#include<iostream>
using namespace std;

#include <algorithm>
#include <vector>

class Person {
public:
	Person(int age, string name) : age(age), name(name) {};

	bool operator==(const Person& p) {
		if (this->name == p.name && this->age == p.age) {
			return true;
		}
		return false;
	}

	int getAge() {
		return this->age;
	}
private:
	int age;
	string name;
};

void testFind() {
	vector<int> v{ 2,3,5,3,4,7,5,6,5,8,9,0,5,5,4,5};
	int count = 0;
	vector<int>::iterator it = v.begin();
	while ((it = find(it, v.end(), 5)) != v.end()) {
		count++;
		it++;
	}

	cout << "Find (" << count << ") `5` in vector" << endl;

	vector<Person> pv{ Person(21, "John"), Person(22, "Marry"), Person(22, "John"), Person(25, "Paul") };
	vector<Person>::iterator pit;
	pit = find(pv.begin(), pv.end(), Person(22, "John"));
	if (pit == pv.end()) cout << "Person not found" << endl;
	else cout << "Person find " << endl;

	pit = find(pv.begin(), pv.end(), Person(25, "John"));
	if (pit == pv.end()) cout << "Person not found" << endl;
	else cout << "Person find " << endl;
}


class OlderThanAge {
public:
	OlderThanAge(int threshold) : threshold(threshold) {};

	bool operator()(Person p) {
		return p.getAge() > threshold;
	}

private:
	int threshold;
};

void countOlderThan(vector<Person> & v, int threshold) {
	int count = 0;
	vector<Person>::iterator it = v.begin();
	while ((it = find_if(it, v.end(), OlderThanAge(threshold))) != v.end()) {
		count++;
		it++;
	}
	cout << "Find " << count << " person(s) older than " << threshold << endl;
}

void testFindif() {
	vector<Person> pv{ Person(21, "John"), Person(22, "Marry"), Person(22, "John"), Person(25, "Paul") };
	countOlderThan(pv, 21);
	countOlderThan(pv, 22);
	countOlderThan(pv, 25);
}

void testAdjacentFind() {
	vector<int> v{1,2,3,3,4,3,4,3,5,5,6,1};
	vector<int>::iterator it = v.begin();
	while ((it = adjacent_find(it, v.end())) != v.end()) {
		cout << "Find adjencent value " << *it << endl;
		it++;
	}
}

void testBinarySearch() {
	// though there is no error, but we should make sure it sorted
	vector<int> v{ 1,3,2,4,6,5 };
	bool res = binary_search(v.begin(), v.end(), 2);
	// will return 0 though it exist because the input is not sorted
	cout << res << endl;

	sort(v.begin(), v.end());
	res = binary_search(v.begin(), v.end(), 2);
	cout << res << endl;
}

void testCount() {
	vector<int> v{ 1,2,3,3,4,3,4,3,5,5,6,1 };
	int count = std::count(v.begin(), v.end(), 3);
	cout << "Count for 3 is " << count << endl;
}

bool divideBy2(int num) {
	return num % 2 == 0;
}

void testCountIf() {
	vector<int> v{ 1,2,3,3,4,3,4,3,5,5,6,1 };
	int count = count_if(v.begin(), v.end(), divideBy2);
	cout << "Count for num can be divided by 2 is " << count << endl;
}

int main() {
	testFind();
	cout << "\n\n" << endl;

	testFindif();
	cout << "\n\n" << endl;

	testAdjacentFind();
	cout << "\n\n" << endl;

	testBinarySearch();
	cout << "\n\n" << endl;

	testCount();
	cout << "\n\n" << endl;

	testCountIf();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}