#include<iostream>
using namespace std;

// marco 宏 constant
#define day 7
int main() {
    cout << "There are " << day << " in a day" << endl;
    //day = 8; // Error，cannot edit marco variable
    //2、const varaible
    const int month = 12;
    cout << "There " << month << " in a year" << endl;
    //month = 24; //Error，cannot modify constant
    system("pause");
    return 0;
}