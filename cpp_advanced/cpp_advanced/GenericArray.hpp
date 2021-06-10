#pragma once
#include <iostream>
using namespace std;

template<class T>
class GenericArray {
private:
	int capacity;
	int index;
	T* pArr;

	void deepCopy(const GenericArray& genericArr) {
		this->capacity = genericArr.capacity;
		this->index = genericArr.index;
		if (this->pArr != NULL) {
			delete[] pArr;
			this->pArr = NULL;
		}
		this->pArr = new T[capacity];

		for (int i = 0; i < index; i++) {
			// deep copy, T should overload = operator
			this->pArr[i] = genericArr.pArr[i];
		}
	}

public:
	GenericArray(int capacity) {
		this->capacity = capacity;
		this->index = 0;
		this->pArr = new T[capacity];
	}

	// copy constructor
	GenericArray(const GenericArray & genericArr) {
		deepCopy(genericArr);
	}

	// overload = operator, avoid shawllow copy
	GenericArray& operator=(const GenericArray& genericArr) {
		deepCopy(genericArr);
		return *this;
	}

	// overload [] operator
	T& operator [](int index) {
		if (index < 0 || index >= this.index) {
			cout << "Element not exist" << endl;
			return NULL;
		}
		return this->pArr[index];
	}

	~GenericArray() {
		if (this->pArr != NULL) {
			delete[] this->pArr;
			this->pArr = NULL;
		}
	}

	bool add(const T & t) {
		if (index == capacity) {
			cout << "Array is full, cannot insert " << t << endl;
			return false;
		}
		this->pArr[this->index++] = t;
		return true;
	}

	// remove tail by default
	T remove() {
		if (index == 0) {
			cout << "Array is empty " << endl;
			return NULL;
		}
		return this->pArr[this->index--];
	}

	int size() {
		return this->index;
	}

	void printArray() {
		if (this->index == 0) {
			cout << endl;
			return;
		}
		for (int i = 0; i < this->index; i++) {
			cout << this->pArr[i] << ", ";
		}
		cout << endl;
	}
};