#include<iostream>

using namespace std;

class Test{

    int privatea = 0;
    void setPrivateA(int value){
        privatea = value;
    }
private:
    int privateb = 0;
    void setPrivateB(int value){
        privateb = value;
    }
protected:
    int proc = 0;
    void setProC(int value){
        proc = value;
    }
public:
    int publicv = 0;
    void printVars(int a, int b, int c){
        privatea = a;
        privateb = b;
        proc = c;
        cout << privatea << " " << privateb << " " << proc << endl;
    }
};

class SubTest : public Test{
public:
    void setProcValue(int value){
        proc = value;
    }

    void setPrivateAVal(int value){
        // error: 'void Test::setPrivateA(int)' is private within this context|
        //setPrivateA(value);
    }

    void print(){
        cout << proc << endl;
    }
};

int accessModifiersStart(){
    Test test;

    // error: 'int Test::privatea' is private within this context|
    //test.privatea = 10;
    // |error: 'int Test::privateb' is private within this context|
    //test.privateb = 20;
    // |error: 'int Test::proc' is protected within this context|
    //test.proc = 30;
    // |error: 'void Test::setPrivateA(int)' is private within this context|
    //test.setPrivateA(10);
    // error: 'void Test::setProC(int)' is protected within this context|
    //test.setProC(30);
    test.publicv = 40;
    test.printVars(1,2,3);

    SubTest subTest;
    // |error: 'int Test::proc' is protected within this context|
    //subTest.proc = 10;
    subTest.setProcValue(30);
    subTest.print();
    return 0;
}
