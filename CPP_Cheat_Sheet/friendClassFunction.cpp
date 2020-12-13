#include<iostream>

using namespace std;

class A;

class C{
public:
    void setA(A&, int);
};

class A{

private:
    int a = 0;
    // usage of friend class
    friend class B;

    // usage of friend function with in class
    friend void C::setA(A&, int);

public:
    void setA(int value){
        a = value;
    }
    void print(){
        cout << a << endl;
    }
    // usage of global function as friend
    friend void setA(A &a, int value);
};

class B{

public:
    void setA(A &a, int value){
        a.a = value;
    }
};

void C::setA(A &a, int value){
    a.a = value;
}

void setA(A &a, int value){
    a.a = value;
}

int friendStart(){
    A a;
    a.setA(10);
    a.print();

    B b;
    b.setA(a, 20);
    a.print();

    C c;
    c.setA(a,30);
    a.print();

    setA(a, 40);
    a.print();
    return 0;
}
