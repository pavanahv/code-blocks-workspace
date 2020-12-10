#include<iostream>

using namespace std;

int loopsStart(){

    // for loop
    for (int i=0;i<10;i++){
        cout << i << " ";
    }
    cout << endl;

    // while loop
    int i = 0;
    while(true){
        if(i>10)
            break;
        cout << i << " ";
        i++;
    }
    cout << endl;

    // do while loop
    int j = 0;
    do{
        cout << j << " ";
        j++;
    }while(j<10);\
    cout << endl;

    // range loop
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    for(int i:a){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
