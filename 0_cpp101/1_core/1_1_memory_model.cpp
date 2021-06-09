#include<iostream>
using namespace std;

int g_a = 1;
int g_b = 2;

const int c_g_a = 3;
const int c_g_b = 4;

int* new_g_a = new int(1);
int* new_g_b = new int(2);

int main() {

	// local variable
	int a = 1;
	int b = 2;

	static int s_l_a = 1;
	static int s_l_b = 2;

	const int c_l_a = 1;
	const int c_l_b = 2;

	string hw = "hello world";

	int* new_l_a = new int(1);
	int* new_l_b = new int(2);

	cout << "Memory address of global variable a: " << (long long)&g_a << endl;
	cout << "Memory address of global variable b: " << (long long)&g_b << endl;
	cout << "Memory address of constant global variable a: " << (long long)&c_g_a << endl;
	cout << "Memory address of constant global variable b: " << (long long)&c_g_b << endl;
	cout << "Memory address of static local variable a: " << (long long)&s_l_a << endl;
	cout << "Memory address of static local variable b: " << (long long)&s_l_b << endl;
	cout << "Memory address of constant local variable a: " << (long long)&c_l_a << endl;
	cout << "Memory address of constant local variable b: " << (long long)&c_l_b << endl;
	cout << "Memory address of string hw: " << (long long)&hw << endl;
	cout << "Memory address of string hello world: " << (long long)&"hello world" << endl;
	cout << "Memory address of local variable a: " << (long long)&a << endl;
	cout << "Memory address of local variable a: " << (long long)&b << endl;
	cout << "Memory address of global new variable a: " << (long long)new_g_a << endl;
	cout << "Memory address of global new variable b: " << (long long)new_g_b << endl;
	cout << "Memory address of local new variable a: " << (long long)new_l_a << endl;
	cout << "Memory address of local new variable b: " << (long long)new_l_b << endl;

	system("pause");
    return 0;
}

/*
Memory address of global variable a: 4452491488
Memory address of global variable b: 4452491492
Memory address of constant global variable a: 4452474696
Memory address of constant global variable b: 4452474700
Memory address of static local variable a: 4452491496
Memory address of static local variable b: 4452491500
Memory address of constant local variable a: 140732763264496
Memory address of constant local variable b: 140732763264492
Memory address of string hw: 140732763264464
Memory address of string hello world: 4452474056
Memory address of local variable a: 140732763264504
Memory address of local variable a: 140732763264500
Memory address of global new variable a: 0x7f9e50c05990
Memory address of global new variable b: 0x7f9e50c059a0
Memory address of local new variable a: 0x7f9e50c059b0
Memory address of local new variable b: 0x7f9e50c059c0
*/