#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void readContent(ifstream& inFile) {
    string line;
    cout<<"start...";
    inFile.open("content.txt");
    if (!inFile)
        cout<<"Failed to open";
    if (getline(inFile, line)) {
        string begin;
        string content;
        string end;

        cin>>begin;
        cin>>content;
        cin>>end;
        cout<<content<<endl;
    }
}

main() {
    ifstream inFile;
    readContent(inFile);
}