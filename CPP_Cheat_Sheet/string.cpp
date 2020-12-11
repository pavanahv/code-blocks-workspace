#include<iostream>

using namespace std;

int stringStart(){
    // basic string creation
    string s = "Hi this is pavan";
    // priting string and its length
    cout << s << " " << s.length() << endl;

    // printing char wise in string
    const int slen = s.length();
    for(int i=0;i<slen;i++){
        cout << s[i];
    }
    cout << endl;

    // creating array of string using char pointer array
    char *strs[4] = {"Hi","This","Is","Pavan"};
    for(int i=0;i<4;i++){

        // printing string
        char *st = strs[i];
        while(*st!='\0'){
            cout << *st;
            st++;
        }
        cout << endl;

        // reversing string
        do{
            st--;
            cout << *st;
        }while(st!=strs[i]);

        cout << endl;
    }

    // creating string array using string class array
    string astr[4] = {"hi","this","is","pavan"};
    for(int i=0;i<4;i++){
        cout << astr[i] << endl;
    }
    return 0;
}
