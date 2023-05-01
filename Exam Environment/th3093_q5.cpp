// Ted Hilger - th3093

#include <iostream>
#include <string.h>
using namespace std;

int countConsonants(string S, int length) {
    int count = 0;
    char checker;
    if (length == 0) {
        return count;
    }
    else {
        checker = S[length-1];
        if ((int)checker > 10) {
            if (checker != 'A' && checker != 'E' && checker != 'I'  && checker != 'O' && checker != 'U' && checker != 'a' && checker != 'e' && checker != 'i' && checker != 'o' && checker != 'u') {
                count++;
            }
            countConsonants(S, length - 1);
        }
    }
}

int main() {
    string s = "todayissunny";
    int length = s.length();
    int consonants = countConsonants(s, length);
    cout<<consonants<<endl;
    return 0;
}