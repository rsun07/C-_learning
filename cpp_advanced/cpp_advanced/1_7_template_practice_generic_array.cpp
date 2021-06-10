#include "GenericArray.hpp"

void test_int() {
	GenericArray<int> arr(3);
	arr.add(1);
	arr.add(2);
	arr.printArray();
	cout << arr.size() << endl;
	arr.remove();
	arr.add(3);
	arr.printArray();
	cout << arr.size() << endl;

	cout << endl;

	GenericArray<int> copy = arr;
	copy.remove();
	copy.add(4);

	arr.printArray();
	copy.printArray();

	cout << endl;

	GenericArray<int> copy2 = GenericArray<int>(arr);
	copy2.remove();
	copy2.add(5);

	arr.printArray();
	copy2.printArray();
}

template<class T1, class T2>
class Person {
private:
	T1 name;
	T2 age;

public:
	// GenericArray create array need default constructor
	Person() {};

	Person(T1 name, T2 age) : name(name), age(age) {};

	Person& operator=(const Person person) {
		this->name = person.name;
		this->age = person.age;
		return *this;
	}

	friend ostream& operator<<(ostream& out, Person person) {
		out << "name = " << person.name << ", name type is " << typeid(person.name).name() << ", Age  = " << person.age << ", Age type is " << typeid(person.age).name();
		return out;
	}
};

void test_Person() {
	cout << endl;

	GenericArray<Person<string, int>> arr(5);
	arr.add(Person<string, int>("John", 20));
	arr.add(Person<string, int>("Marry", 20));

	arr.printArray();
}

int main() {

	test_int();

	test_Person();

	system("pause");
	return 0;
}