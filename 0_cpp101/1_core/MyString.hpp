#include <iostream>
#include <cstring>

using namespace std;

class MyString {
public:
	MyString(const char* p = 0, const int length = 0);
	MyString(const MyString& s);
	MyString& operator=(const MyString& s);
	~MyString();
	char* get_char_pointer() const {
		return p; 
	}
	int getLength() const;
private:
	MyString& createStr(const char* p = 0, const int length = 0);
	MyString& copyStr(const MyString& str);
	char* p;
	int length;
};

inline MyString& MyString::createStr(const char* p, const int length) {
	if (length > 0) {
	    this->length = length;
		this->p = new char[length + 1];
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
inline MyString::MyString(const char* p, int length) {
	createStr(p, length);
} 

// dtro
inline MyString::~MyString() {
	// must delete[], delete without [] is wrong, then only delete the first element
	if (this->p != NULL) {
	    delete[] (this->p);
	    this->p = NULL;
	}
}

// make a deep copy
inline MyString& MyString::copyStr(const MyString& s) {
	// check whether it's the same string. If yes, we cannot move on because we are going to delete old string.
	if (this == &s) return *this;

	// have issue here, remove this make the program works but may cause memory leak.
    if (this->p != NULL) {
	    delete[] (this->p);
	    this->p = NULL;
    }
	return createStr(s.p);
}
// copy ctor
inline MyString::MyString(const MyString& s) {
	copyStr(s);
}

inline int MyString::getLength() const {
	return this->length;
}

inline MyString& MyString::operator=(const MyString& s) {
    return copyStr(s);
}

ostream& operator<<(ostream& os, const MyString& s) {
	int len = s.getLength();
	char* p = s.get_char_pointer();
	for (int i = 0; i < len; i++, p++) {
		os << *p;
	}
	return os;
}