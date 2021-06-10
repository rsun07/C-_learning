
// with this, no compiler error, ========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
// But will have run time error, "2 unresolved externals"
// This is because, different than normal function, template function is created on run time at call. So compiler won't include Person1.cpp as normal.
// #include "Person1.h"

// To solve the above problem, one way works but not commonly used is include .cpp file
#include "Person1.cpp"

// A wildly used solution is put declaration and implementation together and use .hpp as suffix
// .hpp is an agreement, not enforced.
#include "Person2.hpp"

int main() {
	Person1<string, int> person1("John", 20);
	person1.show();

	cout << endl;

	Person2<string, double> person2("Marry", 2.5);
	person2.show();

	system("pause");
	return 0;
}