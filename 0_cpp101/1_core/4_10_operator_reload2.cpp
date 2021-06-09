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
	return 0;
}

