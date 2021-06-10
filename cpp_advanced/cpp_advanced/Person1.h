#pragma once
#include<iostream>
#include<string>
using namespace std;

// normally, header file we only include declarision
template<class NameType, class AgeType>
class Person1 {
public:
	Person1(NameType name, AgeType age);

	void show();

private:
	NameType name;
	AgeType age;
};