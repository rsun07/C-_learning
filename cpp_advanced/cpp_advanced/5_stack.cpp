#include<iostream>
using namespace std;

#include <stack>
#include <string>

// stack doesn't provide iterator
template<class T>
void printStack(stack<T> & s) {
	cout << "s.size() = " << s.size() << endl;

	while (!s.empty()) {
		cout << s.top() << ", ";
		// pop() return type is void
		s.pop();
	}
	cout << endl;
}

void testBasic(){
	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);

	// Don't have this type of initializer because stack doesn't have initializer list constructor
	// stack<int> s{ 1,2,3 };

	printStack(s);
}

void testAdvanced() {
	stack<int> s1, s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);

	s2.push(11);
	s2.push(22);

	s1.swap(s2);

	printStack(s1);
	printStack(s2);
}

int main() {
	testBasic();
	cout << "\n\n" << endl;
	
	testAdvanced();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}