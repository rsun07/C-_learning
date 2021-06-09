#include<iostream>
using namespace std;

class MyNum {
private:
	int num;
public:
	MyNum(int num) : num(num) {}

	// int some case, operator+ just add o value into this value
	// return this to cater the multi add situation. num1 + num2 + num3;
	MyNum& operator+(const MyNum& o) {
		this->num += o.num;
		return *this;
	}

	void show() {
		cout << this->num << endl;
	}
};

class MyNum2 {
private:
	int num;
public:
	MyNum2(int num) : num(num) {}

	// different definition of add, return a new object
	// this return reference, will be faster
	MyNum2& operator+(const MyNum2& o) {
		// must use a pointer to accept new object
		MyNum2* sum = new MyNum2(this->num + o.num);
		cout << "MyNum2 sum address in operator+ : " << (long) sum << endl;
		return *sum;
	}

	void show() {
		cout << this->num << endl;
	}
};

class MyNum3 {
private:
	int num;
public:
	MyNum3(int num) : num(num) {}

	// this return value, need copy, slower
	MyNum3 operator+(const MyNum3& o) {
		MyNum3 sum(this->num + o.num);
		cout << "MyNum3 sum address in operator+ : " << (long) &sum << endl;
		return sum;
	}

	void show() {
		cout << this->num << endl;
	}
};


class MyNum4 {
private:
	int num;
public:
	MyNum4(int num) : num(num) {}

	void show() {
		cout << this->num << endl;
	}

	int getNum() const {
		return this->num;
	}
};

// global implementation
MyNum4& operator+(const MyNum4& num1, const MyNum4& num2) {
	return *(new MyNum4(num1.getNum() + num2.getNum()));
}

int main() {
	MyNum num1(1), num2(2), num3(3);
	num1 + num2 + num3;
	num1.show();
	num2.show();
	num3.show();
	
	cout << endl;

	num1 + (num2 + num3);
	num1.show();
	num2.show();
	num3.show();

	cout << endl;

	MyNum2 num21(1), num22(2);
	// be aware, if here write MyNum2 num23 = num21 + num22; 
	// It will call copy constructor of MyNum2 and create a new one
	MyNum2& num23 = num21 + num22;
	cout << "MyNum2 sum address in operator+ : " << (long) &num23 << endl;
	num23.show();
	cout << endl;

	MyNum3 num31(1), num32(2);
	MyNum3 num33 = num31 + num32;
	cout << "MyNum3 sum address in operator+ : " << (long) &num33 << endl;
	num23.show();

	return 0;
}

/*
6
2
3

11
5
3

MyNum2 sum address in operator+ : 30034976
MyNum2 sum address in operator+ : 30034976
3

MyNum3 sum address in operator+ : 140720669893276
MyNum3 sum address in operator+ : 140720669893356
3
*/