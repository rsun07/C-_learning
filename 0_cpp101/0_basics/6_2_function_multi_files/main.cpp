#include "funcs.h"

int main() {

	int a = 1, b = 2;

	print(a, b);
	swap(a, b);
	cout << "after swap" << endl;
	print(a, b);

    system("pause");
    return 0;
}