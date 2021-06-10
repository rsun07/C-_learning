#include<iostream>
using namespace std;

#include <queue>
#include <string>

int main() {
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "q.back() = " << q.back() << endl;

	while (!q.empty()) {
		cout << q.front() << ", ";
		q.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}