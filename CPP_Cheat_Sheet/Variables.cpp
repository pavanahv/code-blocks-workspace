#include<iostream>

using namespace std;

class Student{
public:
    int marks;

    static int count;

    Student(){
        count++;
    };
};
int Student::count = 0;
int variableStart(){
    Student student1;
    student1.marks = 100;

    cout << sizeof(student1) << endl;
    cout << "Student marks : " << student1.marks << endl;
    cout << "Number of students : " << Student::count << endl;
    return 0;
}
