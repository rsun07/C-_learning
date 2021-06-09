#include "4_2_and_3_Student.cpp"

int main() {

	// error: no viable conversion from 'Student *' to 'Student'
	// must use a pointer to accept `new` object
	// Student student = new Student();

	// warning: empty parentheses interpreted as a function declaration [-Wvexing-parse]
	// compiler will treat it as function name student, return value Student, no param.
	// Student student(); 

   	cout << "Call constructors: " << endl;
	Student student;
	student.setName("John");
	student.setId(1);
	student.show();
	cout << endl;

	Student student2("Marry", 0);
	student2.show();
	student2.setId(2);
	student2.show();
	cout << endl;

	Student student3 = Student("Paul", 3);
	student3.show();
	cout << endl;

	Student* student4 = new Student("Jack", 4);
	// *student4.show(), this is wrong
	(*student4).show();
	student4->show();
	cout << endl;
	
	cout << " student 3 memory address : " << (long long) &student3 << endl;
	cout << " student 4 memory address : " << (long long) student4 << endl;

	// need manually clear, won't tirgger destructor
	delete student4;

   	cout << "\nCall copy constructors: " << endl;

    // call copy constructor
	Student student51 = student;
	// Same as above
	Student student52(student);
	student51.show();
	student52.show();
	cout << endl;

    // call copy constructor
	Student student6 = Student(student);
	student6.setId(60);
	student.show();
	student6.show();
	cout << endl;

	// won't call copy constructor, call no arg constructor first, then assign values.
	Student student7;
	// different than Java. If you need reference of student, you should use reference& or pointer *
	student7 = student;
	student7.setId(70);
	student.show();
	student7.show();
	cout << endl;

   	cout << "\nAnonymous Object: " << endl;

	// anonymous object, system will discard it as soon as this line running completed.
	// will call all arg constructor then call no arg Distructor
	Student("Paul_a", 30);
	cout << endl;

	// Don't use anonymous to call copy constructor;
	// error: redefinition of 'student'. This equals to `Student student;`
	// Student(student);
	Student(student_anonymous);
	// destructor won't be called here
	cout << endl;

	system("pause");
    return 0;
}

/*
Call constructors: 
Student 'no-arg'/'default' constructor call 
name = John , id = 1

Student all-arg constructor call 
name = Marry , id = 0
name = Marry , id = 2

Student all-arg constructor call 
name = Paul , id = 3

Student all-arg constructor call 
name = Jack , id = 4
name = Jack , id = 4

 student 3 memory address : 140729026899216
 student 4 memory address : 93937894177856
Student destructor call 

Call copy constructors: 
Student copy constructor call 
Student copy constructor call 
name = John , id = 1
name = John , id = 1

Student copy constructor call 
name = John , id = 1
name = John , id = 60

Student 'no-arg'/'default' constructor call 
Call operator= override
name = John , id = 1
name = John , id = 70


Anonymous Object: 
Student all-arg constructor call 
Student destructor call 

Student 'no-arg'/'default' constructor call 

sh: 
pause: not found
Student destructor call 
Student destructor call 
Student destructor call 
Student destructor call 
Student destructor call 
Student destructor call 
Student destructor call 
Student destructor call 


** Process exited - Return Code: 0 **
*/