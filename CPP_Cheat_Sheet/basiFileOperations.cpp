#include<iostream>
#include<stdlib.h>

using namespace std;

int basicFileOperationsStart(){

    // creating file pinter by opening for reding
    FILE *fp = fopen("info.txt","rb");

    // checking for file presence
    if(fp==NULL){
        cout<<"file does not exist"<<endl;
        return 0;
    }

    // taking pointer to start of the file
    fseek(fp,0,SEEK_END);

    // getting size of the file
    unsigned long long int siz = ftell(fp);
    cout << "file size : " << siz << endl;

    // closing the file
    fclose(fp);

    // opening the file
    FILE *f = fopen("file.txt","wb");
    // checking for presence
    if(f==NULL){
        cout<<"file does not exist"<<endl;
        return 0;
    }
    // closing the file
    fclose(f);

    // renaming file
    rename("file.txt","renameFile.txt");

    // deleting file
    remove("renameFile.txt");

    return 0;
}
