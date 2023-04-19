#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int basicReadIn() {
    ifstream file;
    string filePath = "this is a filepath";
    file.open(filePath);
    char c;
    vector <char> v;

    while(file.get(&c)) {
        v.push_back(c);
    }

    file.close();
    return 0;
}

int main() {
    ifstream in_stream;
    ofstream out_stream;

    string inputFile = "input.txt";
    in_stream.open(inputFile);
    out_stream.open("output.txt");
    string filePath = "this is a filepath";
    in_stream.open(filePath);

    if(in_stream) {
        cout<<"Fail";
        return 1;
    }

    char c;
    vector<int> allNumbers;
    string currLine;
    int currNum;
    while(getline(in_stream, currLine)) {
        for (int i = 2; i < currLine.length(); i++) {
            char c = currLine[i];
            out_stream<< c;
        }
        out_stream << "\n";
    }

    return 0;
}



