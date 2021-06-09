#include<iostream>
using namespace std;

class MyNum {

	friend ostream& operator<<(ostream& out, MyNum myNum);

private:
	int num;
public:
	MyNum(int num) : num(num) {}

	// ++myNum;
	// why return reference here rather than return MyNum object?
	// we should do ++ operator for the same object, return a new Object doesn't make sense here. 
	MyNum& operator++() {
		++num;
		return *this;
	}

	// myNum++; 
	// this is C++ compiler rule, to add and int for the suffix ++, no meaning for the parameter int. Just for distinguish prefix ++
	// suffix ++ return value, prefix ++ return reference, which is C language tradition.
	// ++++i => ++(++i) however, i++++ doesn't equal to (i++)++
	MyNum operator++(int) {
		MyNum temp = *this;
		++num;
		return temp;
	}

	// there will be an implicit this pointer pass in as first parameter
	MyNum& operator+=(const MyNum& myNum) {
		// all the same class objects are friend to each other, so they have access to private fields and methods	
		this->num += myNum.num;
		return *this;
	}

	// overload method to catering different type
	MyNum& operator+=(const int num) {
		// all the same class objects are friend to each other, so they have access to private fields and methods	
		this->num += num;
		return *this;
	}

	MyNum& operator+=(const double num) {
		this->num += num;
		return *this;
	}

	MyNum& operator+(const int num) {
		return *(new MyNum(this->num + num));
	}

	// wrong, invalide
	// error: 'MyNum& MyNum::operator+(double, const MyNum&)' must have either zero or one argument
	// MyNum& operator+(const double x, const MyNum& myNum) {
	// 	return *(new MyNum(x + myNum.getNum()));
	//}

	int getNum() const {
		return this->num;
	}
};


// reload << operator for ostream!
// here because cout is in left, compiler will try to find the operator override for the left which is cout.
// That's why we need override this outside of the class becuase this is override for cout not for MyNum, cout type is ostream.
// If we override MyNum operator <<, then it should be {MyNum_object} << cout, which isn't common. 
// return ostream& here is for catering multi situation, e.g. cout << 1 << mynum << 2 << " ". 
// If only cout << mynum, then here could return void
ostream& operator<<(ostream& out, MyNum myNum) {
	out << "My number is: " << myNum.num;
	return out;
}

inline MyNum& operator+(const double x, const MyNum& myNum) {
	return *(new MyNum(x + myNum.getNum()));
}

int main() {
	MyNum num1(1);
	cout << "num1 : " << num1 << endl;

	cout << "num1++ : " << num1++ << endl;
	cout << "++num1 : " << ++num1 << endl;

	cout << endl;

	MyNum num2(0);
	cout << "(num2++)++ : " << (num2++)++ << endl;
	cout << "num2 : " << num2 << endl;
	cout << endl;

	MyNum num3(0);
	cout << "++(++num3) : " << ++(++num3) << endl;
	cout << "num3 : " << num3 << endl;
	cout << endl;

	int i = 0;
	// error: lvalue required as increment operand
	// ++ and -- can only operate on variable, here after i++, the return is an constant, cannot apply
	// cout << "i++++ = " << i++++ << endl;
	// cout << "i = " << i << endl;


	i = 0;
	cout << "++++i = " << ++++i << endl;
	cout << "i = " << i << endl;

	cout << endl;

	MyNum num4(1), num5(2), num6(3);
	num4 += num5 += num6;
	cout << "num4 = " << num4 << endl; // 6
	cout << "num5 = " << num5 << endl; // 5
	cout << "num6 = " << num6 << endl; // 3
	// this result is different from `4_10_operator_reload` num1 + num2 + num3; 
	// here num5 value also changed, so for operator +=, compiler will go from right to left.

	cout << endl;

	num4 += 10;
	cout << "num4 = " << num4 << endl; // 16

	num4 += 10.97;
	cout << "num4 = " << num4 << endl; // 26

	cout << endl;

	MyNum sumNum = num4 + 10;
	cout << "num4 = " << num4 << endl; // 26
	cout << "sumNum = " << sumNum << endl; // 36

	// ERROR no match for 'operator+' (operand types are 'int' and 'MyNum')
	// using this need to override operator+ in int class or global/or member func(int, myNum)
	// sumNum = 10 + num4;
	cout << endl;

	sumNum = 10.99 + num4;
	cout << "num4 = " << num4 << endl; // 26
	cout << "sumNum = " << sumNum << endl; // 36

	return 0;
}

