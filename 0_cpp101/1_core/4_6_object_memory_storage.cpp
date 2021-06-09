#include<iostream>
using namespace std;

class Student1{};

class Student2{
	// non-static member variable takes object space
	string m_name;
	int m_id;

public:
	// same as non-static method, all the objects share the same constructor instance
	Student2(string name, int id) : m_name(name), m_id(id){}
};

class Student3{
	// non-static member variable takes object space
	string m_name;
	int m_id;

public:
	// same as non-static method, all the objects share the same constructor instance
	Student3(string name, int id) : m_name(name), m_id(id){}

	Student3(string name) : m_name(name){}

	Student3(int id) : m_id(id){}
};

class Student4{
	// non-static member variable takes object space
	string m_name;
	int m_id;

public:
	// same as non-static method, all the objects share the same constructor instance
	Student4(string name, int id) : m_name(name), m_id(id){}

	// error: non-const static data member must be initialized out of line
	// static int passScore = 60;
	// must declear outside of this class
	static int passScore;
};

int Student4::passScore = 60;


class Student5{
	// non-static member variable takes object space
	string m_name;
	int m_id;

public:
	// same as non-static method, all the objects share the same constructor instance
	Student5(string name, int id) : m_name(name), m_id(id){}

	// all the objects share the same non-static method instance
	void show() {
		cout << "name = " << m_name << " , id = " << m_id << endl;
	}
};


class Student6 {
private: 
	// non-static member variable takes object space
	string m_name;
	int m_id;

	// static member variable don't take object space

	// error: non-const static data member must be initialized out of line
	// static int passScore = 60;
	// must declear outside of this class
	static int passScore;

public: 
	// same as non-static method, all the objects share the same constructor instance
	Student6(string name, int id) : m_name(name), m_id(id){}

	~Student6() {}

	// all the objects share the same non-static method instance
	void show() {
		cout << "name = " << m_name << " , id = " << m_id << endl;
	}

	// static method don't take object memory space
	static int getPassScore() {
		return passScore;
	}
};

int Student6::passScore = 60;

class Student7{
	// non-static member variable takes object space
	string m_name;
	int m_id;
	int score;
	int zipcode;
	string address;
};

int main() {

	Student1 student1;
	Student2 student2("John", 1);
	Student3 student3("John", 1);
	Student4 student4("John", 1);
	Student5 student5("John", 1);
	Student6 student6("John", 1);
	Student7 student7;

	cout << sizeof(student1) << endl; // 1
	cout << sizeof(student2) << endl; // 40
	cout << sizeof(student3) << endl; // 40
	cout << sizeof(student4) << endl; // 40
	cout << sizeof(student5) << endl; // 40
	cout << sizeof(student6) << endl; // 40
	cout << sizeof(student7) << endl; // 80

	// string 4 bytes, int 4 bytes. In debug mode it will have more overheads. Have cookie at begin and end to indicate the object, 4 bytes each. Have padding to make it mod of 8

    return 0;
}