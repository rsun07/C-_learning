#include<iostream>
using namespace std;

class Address {
private: 
	string m_street;
	int m_zipcode;

public: 
	Address(string street, int zipcode) : m_street(street), m_zipcode(zipcode) {
		cout << "Address constructor call " << endl;
	}

	Address(const Address& a) {
		m_street = a.m_street;
		m_zipcode = a.m_zipcode;
		cout << "Address copy constructor call " << endl;
	}

	~Address() {
		cout << "Address destructor call " << endl;
	}

	int getZipcode() {
		return m_zipcode;
	}

	void show() {
		cout << "street = " << m_street << " , zipcode = " << m_zipcode << endl;
	}
};

class Student {
private: 
	string m_name;
	Address m_address;

public: 

	// Student(string name, Address address) {
	// 	m_name = name;
	// 	m_address = address;
	// }

	// same as above
	Student(string name, Address address) : m_name(name), m_address(address) {
		cout << "Student constructor call " << endl;
	}

	~Student() {
		cout << "Student destructor call " << endl;
	}

	void show() {
		cout << "name = " << m_name << " , address zipcode = " << m_address.getZipcode() << endl;
		m_address.show();
	}
};

int main() {

	Student student("John", Address("123 Main", 12345));
	student.show();

    return 0;
}

/*
Address constructor call
Address copy constructor call
Student constructor call
Address destructor call
name = John , address zipcode = 12345
street = 123 Main , zipcode = 12345
Student destructor call
Address destructor call
*/