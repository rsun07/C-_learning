#include<iostream>
using namespace std;

int main() {

	int num = 0;
	while (num++ < 3) {
		cout << num << endl;
	}

	cout << "\n" << endl;

	num = 0;
	do {
		cout << num << endl;
	} while (num++ < 3);


	cout << "\n" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == 1) continue;
			if (j == 4) break;
			cout << "i = " << i << " , j = " << j << endl;
		}			
		cout << endl;
	}

    system("pause");
    return 0;
}