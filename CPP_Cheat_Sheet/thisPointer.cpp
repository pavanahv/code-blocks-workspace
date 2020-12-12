#include<iostream>

using namespace std;

class ATest{
private:
    int x;
    int y;
public:
    ATest(int x, int y){
        this -> x = x;
        this -> y = y;
    }

    void setX(int x){
        this -> x = x;
    }
    void setY(int y){
        this -> y = y;
    }

    void print(){
        cout << " x -> " << x << " y -> " << y << endl;
    }

    ATest &setXR(int x){
        this -> x = x;
        return *this;
    }

    ATest &setYR(int y){
        this -> y = y;
        return *this;
    }

    ATest * getPTR(){
        return this;
    }

    ATest get(){
        return *this;
    }

    ATest &getRef(){
        return *this;
    }

    void destroy(){
        delete this;
    }

};

int thisPointerStart(){
    // creating obj
    ATest obj1(1,2);
    obj1.setX(10);
    obj1.setY(20);
    obj1.print();

    // chaining using ref
    obj1.setXR(1).setYR(2).print();

    // using pointers
    ATest *ptr;
    ptr = obj1.getPTR();
    ptr->setX(1000);
    obj1.print();

    // creating one more object with same content
    ATest obj2 = ptr->get();
    obj2.print();
    obj2.setXR(0).print();
    ptr->print();

    // creating ref
    ATest &obj3 = obj1;
    obj3.setXR(100).print();
    ptr->print();
    obj1.print();

    ATest *obj4 = new ATest(22,22);
    obj4->print();
    obj4->destroy();
    obj4->print();
    return 0;
}
