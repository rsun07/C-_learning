#include <iostream>
using namespace std;
#include <string>

struct Utils {
	static void printTestMsg(string msg) {
		cout << "\n\n" << endl;
		cout << "***  " << msg << "  ***" << endl;
	}

	template<typename Collection>
	static void printCollection(const Collection& c) {
		for (auto e : c) {
			cout << e  << ", ";
		}
		cout << endl;
	}
};