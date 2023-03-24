#include <iostream>
#include <vector>
#include <string>
using namespace std;

string analyzeString(string S, int length) {
    
}

int main() {
    string userString;
    int length;
    while (userString != " "){
        getline(cin, userString);
        length = userString.length();
        if (userString == " ") {
            return;
        }
        else {
            analyzeString(userString, length)
        }
    }
    return 0;
}