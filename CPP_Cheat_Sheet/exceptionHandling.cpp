#include<iostream>

using namespace std;

class A{
public:
    ~A(){
        cout << "A des.."<< endl;
    };
};

class B : public A{

};

void f3() throw (int){
    cout << "f3 start.."<<endl;
    //try{
        A a;
        throw 10;
        cout<<"after throw"<< endl;
    //}
    //catch(int){
    //    cout<<"catch in f3"<< endl;
    //}
}

void f2() throw (int){
    cout <<"f2 start"<< endl;
    f3();
    cout<<"f2 end.."<< endl;
}
void f1(){
    cout<<"f1 start.."<< endl;
    try{
        f2();
    }catch(int x){
        cout<<"catch in f1"<<x<< endl;
    }

    cout << "f1 end.."<< endl;
}


int exceptionStart(){
    // stack unwinding when exception is thrown and base class is std::exception
    f1();

    // derived class catch should be first else base will take it
    try{
        B b;
        throw b; // can throw user defined or primitive types
    }catch(A a){
        cout<<"A class caught"<<endl;
    }
    catch(B b){
        cout << "B class caught"<<endl;
    }catch(...){ //  default catch block for all throws
        cout<<"default caught"<<endl;
    }
    return 0;
}
