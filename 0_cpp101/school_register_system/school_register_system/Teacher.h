#pragma once
#include<iostream>
using namespace std;
#include "Person.h"

class Teacher : public Person {
public:
	Teacher(int id, string name, string subject);

	virtual void displayInfo();

private:
	string subject;
};