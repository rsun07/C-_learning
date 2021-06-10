#include<iostream>
using namespace std;

#include <map>
#include <iterator>
#include <string>

/**
 * map is almost the same as set.
 * We can treat map as a special set that the value is an pair<K,V>
*/


void testPair() {
	pair<string, int> p("John", 1);
	// not p.first() but p.first
	cout << "name = " << p.first << ", id = " << p.second << endl;
	
	pair<string, double> p2 = make_pair("Marry", 2.0);
	cout << "name = " << p2.first << ", id = " << p2.second << endl;
}

template<class K, class V>
void printMap(map<K, V> & m) { 
	for (typename map<K, V>::iterator it = m.begin(); it != m.end(); it++) {
	// for (auto it = m.begin(); it != m.end(); it++) {
		cout << "Key = " << it->first << " : Value = " << it->second << ";\t";
	}
	cout << endl;
}

#define ENGLISH 0
#define CHINESE 1
#define JAPANESE 2

void testMapBasic() {
	map<int, string> m{ pair<int, string>(1,"1"), pair<int, string>(2,"2")};
	cout << m.size() << endl;

	m.insert(pair<int, string>(0, "0"));
	printMap(m);

	// erase by key
	m.erase(1);
	printMap(m);

	m.erase(++m.begin());
	printMap(m);

	cout << "m.find(0) = " << (m.find(0) != m.end()) << endl;
	cout << "m.find(7) = " << (m.find(7) != m.end()) << endl;
	cout << "m.count(0) = " << m.count(0) << endl;
	cout << "m.count(7) = " << m.count(7) << endl;

	// also has a multimap, which is similar to multiset\\

	cout << endl;

	map<int, int> lanToCount;
	lanToCount.insert(pair<int, int>(0, 3));
	lanToCount.insert(pair<int, int>(1, 5));
	printMap(lanToCount);

	cout << (lanToCount.find(ENGLISH) != lanToCount.end()) << endl;
}

class Person {
	friend ostream& operator<<(ostream& out, Person person) {
		out << "id = " << person.id << ", name = " << person.name;
		return out;
	}

public:
	int id;
	string name;

	Person(int id, string name) :id(id), name(name) {};
};

// this is a functor or function object. Also because it returns bool, it called predicator
class PersonIdDescCompare {
public:
	bool operator()(const Person& p1, const Person& p2) const {
		return p1.id > p2.id;
	}
};

void testMapSort() {
	// will through run time error because Person doesn't override operator <, there is no order
	// map<Person, Person> internToMentor{ {Person(1,"John"), Person(2,"Marry")}, {Person(3,"Paul"), Person(4,"Jane")}, {Person(5,"Peter"), Person(6,"Lisa")} };
	// printMap(internToMentor);

	map<Person, Person, PersonIdDescCompare> internToMentor{ {Person(1,"John"), Person(2,"Marry")}, {Person(3,"Paul"), Person(4,"Jane")}, {Person(5,"Peter"), Person(6,"Lisa")} };
	for (auto it = internToMentor.begin(); it != internToMentor.end(); it++) {
		cout << "Intern : " << it->first << ", Mentor : " << it->second << ";\t";
	}
	cout << endl;
}

int main() {
	testPair();
	cout << "\n\n" << endl;
	testMapBasic();
	cout << "\n\n" << endl;
	testMapSort();

	system("pause");
	return 0;
}