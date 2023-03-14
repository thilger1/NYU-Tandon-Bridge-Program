#include <iostream>
#include <string.h>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string words[];
    return words;
}

int main() {
    string userSentence;
    cout<<"Please enter a sentence"<<endl;
    getline(cin, userSentence);
    int words = 0;
    if (userSentence.length() > 0)
        words += 1;
    for (int i = 0; i < userSentence.length(); i++) {
        if (userSentence[i] == " ")
            words++;
    }
    createWordsArray(userSentence, &words);
    return 0;
}
