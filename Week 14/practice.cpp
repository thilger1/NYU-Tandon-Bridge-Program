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

    string filePath = "this is a filepath";
    in_stream.open(filePath);

    if(in_stream) {
        cout<<"Fail";
        return 1;
    }

    char c;
    while(in_stream) {
        c = in_stream.get();
    }

    return 0;
}
