#include<iostream>

using namespace std;

void hi(void);

void sum(int x, int y, int z=0){
    cout << (x+y+z) << endl;
    return;
}

inline void max(int x,int y){
    if(x>y){
        cout <<  x << endl;
    }else {
        cout << y << endl;
    }
}

void update(int*);

void update(int *p){
    *p = *p + 1;
}

int functionsStart(){
    // normal fucntion
    hi();
    // function without complete parameter i.e default parameters
    sum(1,2);
    // function with overriding default parameters
    sum(1,2,3);
    // function that is inline
    max(10,2);

    // function that uses pass by reference
    int a = 0;
    update(&a);
    cout << a << endl;

    return 0;
}

void hi(void){
    cout << "Hi" << endl;
}
