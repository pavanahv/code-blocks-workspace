#include<iostream>

using namespace std;

void sum(int *x, int y){
    *x = *x + y;
}
int pointersBasicsStart(){

    int *p; // wild pointer
    int a = 0;
    p = &a; // normal pointer
    *p = 10;
    cout << a << endl;

    // pointer in array
    int arr[2] = {1,2};
    p = arr;
    for(int i=0;i<2;i++){
        cout << p[i] << " ";
    }
    cout << endl;
    for(int i=0;i<2;i++,p++){
        cout << *p << " ";
    }
    cout << endl;

    // pointers in fucntions
    a = 10;
    sum(&a,2);
    cout << a << endl;

    // double pointers
    int f = 10;
    int *ptr = &f;
    int **ptr1 = &ptr;
    **ptr1 = 40;
    cout << f << endl;

    return 0;
}
