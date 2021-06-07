#include<iostream>
using namespace std;

int main() {

	int score = 0;

	cout << "input score" << endl;

	cin >> score;

	if (score > 100 || score < 0) {
		cout << "Invalid Score" << endl;
	} else {
		if (score >= 90) {
			cout << "A" << endl;
		} else if (score >= 80) {
			cout << "B" << endl;
		} else if (score >= 70) {
			cout << "C" << endl;
		} else if (score >= 60) {
			cout << "D" << endl;
		} else {
			cout << "F" << endl;
		}
	}

	cout << "\n" << endl;

	bool is_pass = false;
	is_pass = score >= 60 ? true : false;
	cout << is_pass << endl;

	cout << "\n" << endl;
	int a = 10;
	int b = 20;

	// assign 100 to a or b depending on left return
	(a > b ? a : b) = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

    system("pause");
    return 0;
}