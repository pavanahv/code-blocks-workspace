#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class FTest
{
public:
    int x, y;
    float f;
    string s;

    void print()
    {
        cout << "x:"<< x << endl;
        cout << "y:"<< y<< endl;
        cout << "f:"<<f<<endl;
        cout <<"s:"<<s<<endl;
    }
};
int objSerilizationStart()
{
    fstream fio;
    fio.open("ftest.txt",ios::trunc | ios::out);

    FTest test;
    stringstream str;
    for (int i = 0; i<5;i++){
        str << i;
        test.x = i+1;
        test.y = i+2;
        test.f = (float)(i+1);
        test.s = str.str();
        fio.write((char*)&test,sizeof(test));
    }
    fio.close();

    fio.open("ftest.txt",ios::in);

    FTest inTest;
    while(!fio.eof()){
        fio.read((char*)&inTest,sizeof(inTest));
        inTest.print();
        cout << endl;
    }
    fio.close();
    return 0;
}
