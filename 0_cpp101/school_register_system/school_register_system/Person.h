#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	virtual void displayInfo() = 0;

	int getId() {
		return this->id;
	}

protected:
	int id;
	string name;
};