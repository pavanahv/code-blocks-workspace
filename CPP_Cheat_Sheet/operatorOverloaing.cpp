#include <iostream>

using namespace std;

class Test{

private:
    int a, b;
public:
    Test() :  Test(0, 0){
    }
    Test(int a,int b){
        this -> a = a;
        this -> b = b;
    }

    Test operator + (Test test){
        Test res;
        res.a = a + test.a;
        res.b = b + test.b;
        cout << res.a << " " << res.b << " " << &res << endl;
        return res;
    }

    void operator + (int a){
        this -> a = this -> a + a;
        b = b + a;
    }
    void operator ++(){
        a = a+1;
        b = b+1;
        cout << "++ done" << endl;
    }

    void print(){
        cout << a << " " << b<< endl;
    }
};

class ATest{
private:
    int *p;
public:
    ATest(int value = 0){
        p = new int(value);
    }

    void setValue(int value =0){
        *p = value;
    }

    void destroy(){
        delete p;
    }

    void print(){
        cout << "value : "<< *p << endl;
    }

    ATest & operator = (ATest const &test){
        if(this != &test){
            *p = *(test.p);
        }
        return *this;
    }
};

int operatorOverloadingStart(){
    // + operator overloading
    Test obj1(1,2), obj2(3,4);
    Test res;
    cout << &res<< endl;
    res.print();
    res = obj1 + obj2;
    res.print();
    cout << &res<< endl;

    // unary operator overloading
    ++obj1;
    obj1.print();

    // + operator overloading with primitive data type
    obj1+100;
    obj1.print();

    // Assignment operator problems
    ATest aobj1(10),aobj2;
    aobj1.print();
    aobj2.print();

    aobj2 = aobj1;
    aobj1.print();
    aobj2.print();

    aobj2.setValue(1000);
    aobj1.print();
    aobj2.print();

    aobj1.destroy();

    // solving such problem with assignment operator overloading => for reproducing the problem, remove = operator overloading code

    return 0;
}
