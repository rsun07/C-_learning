#include "SystemManager.h"

SystemManager::SystemManager() {
	this->id = 0;
	this->personSize = 0;
	this->persons = NULL;
}

void SystemManager::showMenu() {
	cout << "******************************************" << endl;
	cout << "** Welcome to Student Management System **" << endl;
	cout << "*********** 0.Exit System ****************" << endl;
	cout << "*********** 1.Register a Record **********" << endl;
	cout << "*********** 2.Show all Records ***********" << endl;
	cout << "*********** 3.Delete Record **************" << endl;
	cout << "*********** 4.Find by ID *****************" << endl;
	cout << "*********** 5.Truncate *******************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void SystemManager::exitSystem() {
	cout << "Exiting, thank you!" << endl;
	system("pause");
	exit(0);
}

void SystemManager::addPerson() {
	cout << "Please enter the number of person to be registered :" << endl;

	Person** newPersons = new Person * [this->personSize + 1];

	if (this->persons != NULL) {
		for (int i = 0; i < this->personSize; i++)
			newPersons[i] = this->persons[i];
	}

	int id = this->id++;
	string name;

	cout << "Please enter name : " << endl;
	cin >> name;

	cout << "Please select register person type : " << endl;
	cout << "1.Student" << endl;
	cout << "2.Teacher" << endl;
	int personType;
	cin >> personType;

	Person* person = NULL;
	switch (personType) {
	case 1:
		cout << "Please enter grade : " << endl;
		int grade;
		cin >> grade;
		person = new Student(id, name, grade);
		break;
	case 2:
		cout << "Please enter subject : " << endl;
		string subject;
		cin >> subject;
		person = new Teacher(id, name, subject);
		break;
	}

	newPersons[this->personSize] = person;

	delete[] this->persons;
	this->persons = newPersons;
	this->personSize++;

	cout << "Successfully add person : ";
	person->displayInfo();
	cout << endl;
}

void SystemManager::showAllRecords() {
	if (this->persons == NULL) {
		cout << "System is empty!" << endl;
		return;
	}

	for (int i = 0; i < this->personSize; i++) {
		this->persons[i]->displayInfo();
	}

	system("pause");
	system("cls");
}

int SystemManager::getIndex(int id) {
	if (id < 0 || id >= this->personSize) return -1;
	for (int i = 0; i < this->personSize; i++) {
		if (this->persons[i]->getId() == id) return i;
	}
	return -1;
}

void SystemManager::findById() {
	cout << "Please enter the id for search : " << endl;
	int id;
	cin >> id;

	int index = this->getIndex(id);
	if (-1 == index) {
		cout << "person with id " << id << " not exist" << endl;
		return;
	}
	this->persons[index]->displayInfo();
}

void SystemManager::deleteById() {
	cout << "Please enter the id to delete : " << endl;
	int id;
	cin >> id;

	int index = this->getIndex(id);
	if (-1 == index) {
		cout << "person with id " << id << " not exist" << endl;
		return;
	}
	Person* person = this->persons[index];
	for (int i = index+1; i < personSize; i++) {
		this->persons[i - 1] = this->persons[i];
	}
	this->personSize = this->personSize - 1;
	cout << "Successfully delete id " << id << endl;
	person->displayInfo();
	delete person;
}

void SystemManager::truncate() {
	delete[] this->persons;
	this->persons = NULL;
	this->id = 0;
	this->personSize = 0;
	cout << "Successfully clean all records" << endl;
	
	system("pause");
	system("cls");
}

SystemManager::~SystemManager() {
	if (this->persons != NULL) {
		delete[] this->persons;
	}
}