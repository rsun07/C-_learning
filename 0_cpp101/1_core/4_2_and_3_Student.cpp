#include <iostream>
using namespace std;

class Student {
private: // without this, default is also private
	string m_name;
	int m_id;

public: 
	Student() {
		cout << "Student 'no-arg'/'default' constructor call " << endl;
	}

	Student(string name, int id) {
		cout << "Student all-arg constructor call " << endl;
		m_name = name;
		m_id = id;
	}

	// copy constructor
	Student(const Student& s) {
		m_name = s.m_name;
		m_id = s.m_id;
		cout << "Student copy constructor call " << endl;
	}

	// Destructor, cannot have param, cannot be reloaded
	~Student() {
		cout << "Student destructor call " << endl;
	}

	Student& operator=(const Student& s) {
		cout << "Call operator= override" << endl;
		// though s is from another object, but it's the same class, still have access to its private fields
		this->m_name = s.m_name;
		this->m_id = s.m_id;
		return *this;
	}

	void setName(string name) {
		m_name = name;
	}

	void setId(int id) {
		m_id = id;
	}

	string getName() const {
		return m_name;
	}

	int getId() const {
		return m_id;
	}

	void show() {
		cout << "name = " << m_name << " , id = " << m_id << endl;
	}
};