#include<iostream>
#include<fstream>

using namespace std;

void useFStream()
{
    // class to open, read , write file
    fstream fio;

    // opening file
    fio.open("fio.txt",ios::in | ios::out | ios::trunc);
    // checking file opened or not
    if(fio)
    {
        string text = "This is some string\nInside a file -1";
        // writing into file
        fio << text << endl;
        cout << text << endl;
    }
    // going to start of the file to read from starting
    fio.seekg(ios::beg);

    string line;
    // checking EOF
    while(fio)
    {
        // reading a string from file
        fio >> line;
        if(line == "-1")
            break;
        cout << line << " ";
    }
    cout << endl;
    // closing file
    fio.close();

}

int iofstreamStart()
{

    // class to output to file
    ofstream fout;

    string text = " Hi this is pavan \n i am working \n i am from ap \n i am an software enginner -1";
    string line;

    // opening file. if file not exits it will be created
    fout.open("info.txt");

    // checking whether it is null or not
    if(fout)
    {
        // writing string to file
        fout << text << endl;
        cout << text << endl;
    }
    // closing file
    fout.close();

    // class to read from file
    ifstream fin;

    // opening file to read
    fin.open("info.txt");

    // checking whether it is null or not
    while(fin)
    {
        // reading a string from file. lines will be decided based on space and enter char
        fin>>line;
        cout << line << " ";
        // checking whether EOF file reached
        if(line == "-1")
            break;
    }
    cout << endl;
    // closing the file
    fin.close();

    useFStream();
    return 0;
}
