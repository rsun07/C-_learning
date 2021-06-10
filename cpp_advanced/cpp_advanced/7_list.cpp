#include<iostream>
using namespace std;

#include <list>
#include <vector>
#include <iterator>
#include <string>

template<typename T>
void printList(const list<T> & l) {
	for (auto e : l) {
		cout << e << ";  ";
	}
	cout << endl;
}

// similar to vector
void testCreation() {
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_front(0);

	list<int> l2{ 3,2,1 };

	// initialize with five value 1
	list<int> l3(5, 1);

	int arr[] = { 6,7,8 };
	list<int> l4(arr, arr+2);

	vector<int> v{ 4,5,6 };

	// not exist following two
	// list<int> l5(v);
	// list<int> l5(v, v+2);
	list<int> l5(v.begin(), v.end() - 1);

	list<int> l6(l5.begin(), l5.end());

	list<int> l7(l1);

	list<int> l8;
	l8 = l2;

	list<int> l9;
	l9.assign(v.begin(), v.end());

	list<int> l10;
	// asign three value 11 to list
	l10.assign(3, 11);

	printList(l1);
	printList(l2);
	printList(l3);
	printList(l4);
	printList(l5);
	printList(l6);
	printList(l7);
	printList(l8);
	printList(l9);
	printList(l10);
}

void testBasicConfig() {
	list<int> l1{ 1,2,3,4,5 };

	// list is linkedlist implementation, so don't have capacity
	cout << "l1.size() = " << l1.size() << " ,l1.max_size() = " << l1.max_size() << endl;
	
	// resize to size 11, use value 22 to fill if have empty spot
	l1.resize(11, 22);
	cout << "l1.size() = " << l1.size() << " ,l1.max_size() = " << l1.max_size() << endl;
	printList(l1);

	l1.resize(6);

	list<int> l2{ 3,2,1 };
	l1.my_swap(l2);
	cout << endl;
	printList(l1);
	printList(l2);
}

// because list is Linked List implementation, so don't have array like access methods. Iterator also doens't allow random/index access
void testGetValue() {
	list<int> l{ 1,2,3,4,5 };
	
	// no [] override
	// l[1];

	// no .at() function
	// l.at(1);

	cout << "l.front() = " << l.front() << ", l.back() = " << l.back() << endl;
	
	cout << *l.begin() << endl;
	// end is not the last, end - 1 is the last. Will cause out of boundary run time error
	// cout << *(l.end()) << endl;

	// doesn't support random/index access
	// l.begin() + 2;
	// l.end() - 1
}

void testEditValue() {
	list<int> l{ 1,2,3 };

	l.push_back(4);
	l.push_front(0);
	printList(l);

	l.pop_back();
	l.pop_front();
	printList(l);

	list<int>::iterator it = l.begin();
	l.insert(++it, 100);
	l.insert(it, 200);
	printList(l);

	cout << endl;
	l.erase(++it);
	printList(l);

	cout << endl;
	it = l.begin();
	
	// invalid
	// it += 2;
	// it = it + 2;

	it++;
	it++;
	l.erase(l.begin(), it);
	printList(l);

	cout << endl;
	l.push_front(100);
	l.push_back(100);
	l.push_back(100);
	printList(l);
	l.remove(100);
	printList(l);

	cout << endl;
	l.clear();
	printList(l);
}

class Person {

	friend ostream& operator<<(ostream& out, Person person) {
		out << "id = " << person.id << ", name = " << person.name << ", age = " << person.age;
		return out;
	}

public:
	Person(string name, int age, int id) : name(name), age(age), id(id) {};

	int getAge() {
		return this->age;
	}

	int getId() {
		return this->id;
	}

	string getName() {
		return this->name;
	}
private:
	string name;
	int age;
	int id;
};

#include <algorithm>

bool ageDescCompare(Person p1, Person p2) {
	return p1.getAge() > p2.getAge();
}

bool ageAscCompare(Person p1, Person p2) {
	return p1.getAge() < p2.getAge();
}

bool nameCompare(Person p1, Person p2) {
	return p1.getName() < p2.getName();
}

void testReverseAndSort() {
	list<Person>  l{ Person("John", 22, 1), Person("Marry", 23, 2), Person("Paul", 21, 3) };
	printList(l);

	l.reverse();
	printList(l);

	cout << endl;
	// will cause run time error because there is no order for class Person
	//l.sort();
	
	l.sort(ageDescCompare);
	printList(l);

	l.sort(ageAscCompare);
	printList(l);

	cout << endl;
	l.sort(nameCompare);
	printList(l);
}

int main() {
	testCreation();
	cout << "\n\n" << endl;
	testBasicConfig();
	cout << "\n\n" << endl;
	testGetValue();
	cout << "\n\n" << endl;
	testEditValue();
	cout << "\n\n" << endl;
	testReverseAndSort();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}