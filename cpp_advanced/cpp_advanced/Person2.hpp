#pragma once
#include<iostream>
#include<string>
using namespace std;

// normally, header file we only include declarision
template<class NameType, class AgeType>
class Person2 {
public:
	Person2(NameType name, AgeType age);

	void show();

private:
	NameType name;
	AgeType age;
};

template<class T1, class T2>
Person2<T1, T2>::Person2(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void Person2<T1, T2>::show() {
	cout << "Person2 show, name = " << this->name << ", name type is " << typeid(this->name).name() << ", Age  = " << this->age << ", Age type is " << typeid(this->age).name() << endl;
}