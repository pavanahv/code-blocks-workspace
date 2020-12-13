#include<iostream>

using namespace std;

// simple inheritance
class A{
private:
    int a;
protected:
    int b;
public:
    A(){
        cout << " A cons.." << endl;
    }
    int c;
};

class B : public A{
public:
    B(){
        cout << "B cons "<< endl;
    }

    // overloading
    void set(int b){
        this -> b = b;
    }
    void set(int b, int c){
        this -> b = b;
        this -> c = c;
    }

    void print(){
        cout << b << " "<< c<<endl;
    }
};

// multilevel
class C : protected A{
public:
    C(){
        cout << "C cons "<< endl;
    }
};

// hybrid => in detail multipath. other hand its multiple
class D : public B, public C{
public:
    D(){
        cout << "D cons" << endl;
    }
};

class E : private A{
public:
    E(){
        cout << "E cons"<< endl;
    }
};

int inheritanceOverloadingStart(int argc, char argv[]){
    A a;
    a.c = 10;

    B b;
    // accessing A::c value via B since sub class
    b.c = 20;
    b.print();
    b.set(30); // overloading
    b.print();
    b.set(40,50); // overloading
    b.print();

    C c;
    // |error: 'int A::c' is inaccessible within this context|
    //c.c = 10; // since class C : protected A => base class is protected so base class public vars also became protected

    D d;
    // |error: request for member 'c' is ambiguous|
    //d.c = 10;

    d.B::c = 20; // to solve above problem either use :: operator or use virtual at this time of inheriting along with access specifier
    d.print();

    E e;
    // |error: 'int A::c' is inaccessible within this context|
    //e.c = 10; // as : private A => so public var in A became private to E
    return 0;
}
