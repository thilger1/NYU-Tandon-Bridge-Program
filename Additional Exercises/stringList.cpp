#include <iostream>
#include <vector>
#include <string>
using namespace std;

string analyzeString(string S, int length) {
    bool pass = true;
    for (int i = 0; i < length; i++) {
        if (S[i] != 'A' || S[i] != 'E' || S[i] != 'I' S[i] != 'O' || S[i] != 'U') {
            pass = false;
        }
    }
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
            analyzeString(userString, length);
        }
    }
    return 0;
}