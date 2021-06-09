#pragma once
#include<iostream>
using namespace std;
#include "Person.h"

class Student : public Person {
public:
	Student(int id, string name, int grade);

	virtual void displayInfo();

private:
	int grade;
};