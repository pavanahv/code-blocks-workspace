#include<iostream>

using namespace std;

class Test{
    int a = 0;
public:
    Test * setA(int value){
        a = value;
        return this;
    }

    void print(){
        cout << a << endl;
    }

};

class B{
public:
    // can use reference but after going out of this function obj will die.
    Test getTest(){
        Test test;
        test.setA(100);
        cout << &test << endl;
        return test;
    }

    void updateTest(Test & test, int value){
        test.setA(value);
    }
};
int classesObjectsStart(){
    // object creation
    Test test;
    test.setA(10);
    test.print();
    cout << &test << endl;

    B helper;
    // return object
    test = helper.getTest();
    test.print();
    cout << &test << endl;

    // sending object as reference
    helper.updateTest(test,200);
    test.print();

    // creating pointer to object
    Test *alias = NULL;
    alias = test.setA(20);
    test.print();
    alias->setA(30);
    test.print();
    return 0;
}
