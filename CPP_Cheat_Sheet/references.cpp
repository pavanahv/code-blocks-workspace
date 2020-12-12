#include<iostream>

using namespace std;

void sum(int &a, int &b){
    cout << (a+b) << endl;
}

int referencesStart(){

    // simple reference
    int a = 0;
    int &p = a;
    p = 10;
    cout<< a << endl;

    // references in functions
    int x = 10, y = 20;
    sum(x,y);

    // references in loops
    string strs[2] = {"hi","hello"};
    for(const auto &s : strs){
        cout << s << endl;
    }

    return 0;
}
