#include<iostream>
using namespace std;

class Student {
	string name;
	int id;

public: 
	Student(string name, int id) {
		this->name = name;
		this->id = id;
	}

	void show() const {
		// error: expression is not assignable
		// this = NULL;
		// this is constant pointer, cannot change object it point to

		// error: cannot assign to non-static data member within const member function 'show'
		// this->id = 2;

 		// error: cannot assign to non-static data member within const member function 'show'
		// id = 2;

		cout << "name = " << this->name << " , id = " << this->id << endl;
	}
};
	
class Student2 {
	string name;
	mutable int id;

public: 
	Student2(string name, int id) {
		this->name = name;
		this->id = id;
	}

	void show() const {
 		// error: no viable overloaded '='
 		// same error as above, different error message because this string is immutable. If add mutable for string name, then it will pass
		// name = "Marry";

		id = 2;

		cout << "name = " << this->name << " , id = " << this->id << endl;
	}

	void showClassName() {
		cout << "Studnet2" << endl;
	}
};

int main() {

	Student student("John", 1);
	student.show();

	Student2 student21("John", 1);
	student2.show();

	// const object can only access const method, cannot access non const method.
	const Student2 student22("Marry", 3);
	student22.show();

	// error: 'this' argument to member function 'showClassName' has type 'const Student2', but function is not marked const
	// student22.showClassName();

	system("pause");
    return 0;
}
