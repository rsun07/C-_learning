#pragma once
#include<iostream>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "Teacher.h"

class SystemManager {
public:
	SystemManager();
	
	void showMenu();

	void exitSystem();

	void addPerson();

	void showAllRecords();

	int getIndex(int id);

	void findById();

	void deleteById();

	void truncate();

	~SystemManager();
private:
	int id;

	int personSize;

	Person** persons;
};