#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void readContent(ifstream& inFile) {
    inFile.open("content.txt");
    if (!inFile) {
        cout<<"Failed to open file";
        return;
    }
    string begin;
    string content;
    string end;
    inFile >> begin >> content >> end;
    cout<<content;
    inFile.close();
}

main() {
    ifstream inFile;
    readContent(inFile);
}