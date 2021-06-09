#include <iostream>
using namespace std;

#include <cstring>

class MyString {
public:
	MyString(const char* p = 0);
	MyString(const MyString& s);
	MyString& operator=(const MyString& s);
	~MyString();
	char* get_char_pointer() const {
		return p; 
	}
	int length() const;
private:
	MyString& createStr(const char* p);
	MyString& copyStr(const MyString& str);
	char* p;
};

inline MyString& MyString::createStr(const char* p) {
	if (p) {
		this->p = new char[strlen(p) + 1];
		strcpy(this->p, p);
	} else {
	  this->p = new char[1];
      *(this->p) = '\0';
	}
	return *this;
}

// ctor, copy c style string using c methods
// why constructor receive and create a pointer rather than an object?
// Because rather than int, couble and etc, string doesn't have strict length. On the other hand, pointer length is always the same.
inline MyString::MyString(const char* p) {
	createStr(p);
} 

// dtro
inline MyString::~MyString() {
	// must delete[], delete without [] is wrong
	if (this->p != NULL) {
	    delete[] (this->p);
	}
}

// make a deep copy
inline MyString& MyString::copyStr(const MyString& s) {
	// check whether it's the same string. If yes, we cannot move on because we are going to delete old string.
	if (this == &s) return *this;

    if (this->p != NULL) {
	    delete[] (this->p);
    }
	return createStr(s.p);
}
// copy ctor
inline MyString::MyString(const MyString& s) {
	copyStr(s);
}

inline int MyString::length() const {
	return strlen(p);
}

inline MyString& MyString::operator=(const MyString& s) {
    return copyStr(s);
}

ostream& operator<<(ostream& os, const MyString& s) {
	int len = s.length();
	char* p = s.get_char_pointer();
	for (int i = 0; i < len; i++, p++) {
		os << *p;
	}
	return os;
}