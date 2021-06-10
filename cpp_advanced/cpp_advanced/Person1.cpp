#include "Person1.h"

template<class T1, class T2>
Person1<T1, T2>::Person1(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void Person1<T1, T2>::show() {
	cout << "Person1 show, name = " << this->name << ", name type is " << typeid(this->name).name() << ", Age  = " << this->age << ", Age type is " << typeid(this->age).name() << endl;
}