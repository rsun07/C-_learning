#include<iostream>
using namespace std;

class Student {
protected: 
	string m_name;
	int* m_id;

public: 
	Student(string name, int id) {
		m_name = name;
		// put id into memory heap
		m_id = new int(id);
	}

	// compiler will create a default copy constructor which make shallow copy only

	~Student() {
		if (m_id != NULL) {
			delete m_id;
			m_id = NULL;
		}
		cout << "Student destructor call " << endl;
	}

	void setId(int id) {
		*m_id = id;
	}

	void show() {
		cout << "name = " << m_name << " , id = " << *m_id << ", name memory address is : " << (long long)&m_name << " , id memory address = " << (long long)m_id << endl;
	}
};

class Student2 : public Student {
public:
	Student2(string name, int id) : Student(name, id) {}

	// override copy constructor
	Student2(const Student2& student) : Student(student) {
		m_name = student.m_name;
		// make a deep copy
		m_id = new int(*student.m_id);
	}
};

int main() {

	Student s1_1("John", 1);
	Student s1_2(s1_1);
	s1_1.show();
	s1_2.show();
	s1_2.setId(2);
	cout << endl;
	s1_1.show();
	s1_2.show();

	// because it's shallow copy, s1_2 will be distructor first, then s1_1.
	// while distruct s1_1, the m_id is already deleted

	// Student destructor call
    // malloc: *** error for object 0x7fecc3c05990: pointer being freed was not allocated
    // malloc: *** set a breakpoint in malloc_error_break to debug

	cout << endl;

	Student2 s2_1("Marry", 10);
	Student2 s2_2(s2_1);
	s2_1.show();
	s2_2.show();
	s2_2.setId(20);
	cout << endl;
	s2_1.show();
	s2_2.show();

	cout << endl;

	system("pause");
    return 0;
}

/*
name = John , id = 1, name memory address is : 140732666566136 , id memory address = 140584861850000
name = John , id = 1, name memory address is : 140732666566064 , id memory address = 140584861850000

name = John , id = 2, name memory address is : 140732666566136 , id memory address = 140584861850000
name = John , id = 2, name memory address is : 140732666566064 , id memory address = 140584861850000

name = Marry , id = 10, name memory address is : 14073266656603210 , id memory address = 140584861850016
name = Marry , id = 10, name memory address is : 14073266656597610 , id memory address = 140584861850032

name = Marry , id = 10, name memory address is : 14073266656603210 , id memory address = 140584861850016
name = Marry , id = 20, name memory address is : 14073266656597610 , id memory address = 140584861850032

sh: pause: command not found
Student2 destructor call
Student2 destructor call
Student destructor call
*/
