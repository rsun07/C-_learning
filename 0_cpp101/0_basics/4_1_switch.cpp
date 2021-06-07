#include<iostream>
using namespace std;

int main() {

	int score = 0;

	cout << "input score" << endl;

	cin >> score;
	cout << "\n" << endl;

	switch (score) {
		// Wrong, switch condition must be a single value, cannot be a condition
		// case score > 90 : cout << "A" << endl; break;
		
		case 100 : cout << "Full Score" << endl; break;
		case 90 : cout << "Great Score" << endl; break;
		case 60 : cout << "Pass" << endl; break;
		default : cout << "Unknow" << endl; break;
	}

	cout << "\n" << endl;

	// without break will print all after
	switch (score) {		
		case 100 : cout << "Full Score" << endl; 
		case 90 : cout << "Great Score" << endl;
		case 60 : cout << "Pass" << endl;
		default : cout << "Unknow" << endl;
	}


    system("pause");
    return 0;
}