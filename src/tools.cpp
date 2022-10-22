#include <iostream>
#include <fstream>
using namespace std;

fstream create_file(string filename)
{
    fstream FileObj;
    FileObj.open(filename, ios::out);
    if (!FileObj)
        cout << "Error opening file";
    else
        FileObj.close();
    return FileObj;
}

void read_file(string filename)
{
    string filestreambuffer;
    fstream filestream;
    if (!filestream.is_open())
    {
        filestream.open(filename, ios::in);
    }
    while (getline(filestream, filestreambuffer))
        cout << filestreambuffer << endl;

    filestream.close();
}
