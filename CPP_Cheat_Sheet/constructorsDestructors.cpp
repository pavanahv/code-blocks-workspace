#include<iostream>

using namespace std;

class B{
public:
    B(){
        cout << "B cons called.."<< endl;
    }
};
class Test{
    int a;

    // this makes call to B class constructor
    B b;
public:
    // constructor overloading
    Test() : Test(0){
        cout << "Test - 1 cons called.." << endl;
    }
    Test(int value){
        a = value;
        cout << "Test - 2 cons called.." << endl;
    }

    // destructor
    ~Test(){
        cout << "Test Destructor called..." << endl;
    }

    // copy constructor
    Test(Test const & test){
        a = test.a;
        cout << "Test copy cons called..." << endl;
    }

    // assignment operator overloading
    Test & operator =(Test const & test){
        if(this!= &test){
            a = test.a;
        }
        cout << "Test assignment operator called .." << endl;
        return *this;
    }

    void print(){
        cout << a << endl;
    }
};
class A{
    // no constructor so default compiler created cons will be called
public:
    // if virtual key word is omitted then only base class destructor will be called while object dieing.
    virtual ~A(){
        cout << "A destructor .. "<< endl;
    }
};

class C : public A{
public:
    ~C(){
        cout << "C destructor" << endl;
    }
};

class E;

class D{
};

class E{
private:
    ~E(){
        cout << "E private destructor" << endl;
    };
    // deleting object which have private destructors using friend funtions
    friend void destroyE(E * e);
};

void destroyE(E * e){
    delete e;
}

Test createTest(){
    Test test;
    return test;
}

int consDestStart(){
    if(1){
        Test t1;
    }
    Test t1 = createTest();
    Test t2(10);
    t1 = t2;
    t1.print();
    t2.print();
    Test t3 = t1;
    t3.print();

    C *c = new C();
    A *ap = NULL;
    ap = c;
    delete ap;

    E *e = NULL;
    e = new E();
    destroyE(e);

    return 0;
}
