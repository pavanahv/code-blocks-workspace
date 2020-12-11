#include<iostream>
#include<cstdlib>

using namespace std;

int arraysStart(){
    int a[10];
    for(int i=0;i<10;i++){
        a[i] = i+1;
    }

    // new way of printing array
    for(int i=0;i<10;i++){
        cout << i[a] << " ";
    }
    cout << endl;

    // size of int array vs int ptr
    int *p;
    int *q = a;
    cout << "size of int ptr : " << sizeof(p) << endl;
    cout << "size of int array : " << sizeof(a) << endl;
    cout << "size of int array ptr : " << sizeof(q) << endl;
    for(int i=0;i<10;i++){
        cout << q[i] << " ";
    }
    cout << endl;

    int *ma = (int *) malloc(sizeof(int) * 10);
    for(int i=0;i<10;i++){
        ma[i] = i+1;
    }
    for(int i=0;i<10;i++){
        cout << ma[i] << " ";
    }
    cout << endl;
    cout << "size of dynamically allocated memory : " << sizeof(ma) <<  endl;
    free(ma);
    return 0;
}
