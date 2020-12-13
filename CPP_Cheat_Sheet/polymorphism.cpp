#include<iostream>

using namespace std;

class At{
    int a = 0;
public:
    At(){
        cout << " A cons"<< endl;
    }
    void setA(int value){
        a = value;
    }
    // virtual keyword used. if not only base class print will be used; remove virtual and check output
    virtual void print(){
        cout << "base class print" << endl;
    }
};

class Bt : public At{
public:
    Bt(){
        cout << " B cons"<< endl;
    }
    void print(){
        cout << "B class print"<< endl;
    }
    void hi(){
        cout <<"Hi from B. only from B"<<endl;
    }

};

class Ct : public At{
public:
    Ct(){
        cout <<"C cons"<< endl;
    }
    void print(){
        cout << "C class print"<< endl;
    }
};

class Dt: public At{
};
int polymorphismStart(){
    At a;
    a.print();

    Bt b;
    b.print();

    Ct c;
    c.print();

    Dt d;
    d.print();

    At *p = NULL;
    p = &b;
    p->print();
    p=&c;
    p->print();

    // Able to retrive Bt pointer from At pointer by not loosing member funcitons
    Bt *bp = NULL;
    bp = (Bt*)p;
    bp -> hi();
    return 0;
}
