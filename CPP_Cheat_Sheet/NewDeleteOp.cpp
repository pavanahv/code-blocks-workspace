#include<iostream>

using namespace std;

int newDeleteOpStart(){
    // creating variables in heap
    int *p = new int;
    *p = 10;
    cout << *p << endl;
    delete p;

    // creating memory in heap and checking whether memory create or not
    int *q = NULL;
    q = new (nothrow) int;
    if(!q){
        cout << "error in crating memory";
    }else{
        *q = 20;
        cout << *q << endl;
    }
    delete q;

    // creating array kind of memory in heap
    int *a = NULL;
    a = new (nothrow) int[10];
    for(int i=0;i<10;i++){
        a[i] = i;
    }
    for(int i=0;i<10;i++){
        cout << a[i] << " ";
    }
    delete []a;
    return 0;
}
