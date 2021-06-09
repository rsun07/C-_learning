#include<iostream>
using namespace std;
#include "SystemManager.h"

int main() {
	SystemManager manager;
	int command = 0;
	while (true) {
		manager.showMenu();

		cout << "Plean input command number: " << endl;
		cin >> command;

		switch (command) {
		case 0: 
			manager.exitSystem();
			break;
		case 1: 
			manager.addPerson();
			break;
		case 2: 
			manager.showAllRecords();
			break;
		case 3:
			manager.deleteById();
			break;
		case 4:
			manager.findById();
			break;
		case 5:
			manager.truncate();
			break;
		default:
			// clear the screen
			system("cls");
			cout << "Unknown command, please type again" << endl;
			break;
		}
	}

	system("pause");

	return 0;
}