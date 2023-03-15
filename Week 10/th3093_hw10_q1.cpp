#include <iostream>
#include <string.h>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize) {
    int spaceIndex = 0;
    int words = 0;
    int sentenceLength = sentence.length();
    string* wordsArray = new string[sentenceLength];

    for (int i = 0; i < sentenceLength; i++) {
        if (sentence[i] == ' ') {
            wordsArray[words] = sentence.substr(spaceIndex, )
            words++;
        }
    }
    return arr;
}

int main() {
    string userSentence;
    cout<<"Please enter a sentence"<<endl;
    getline(cin, userSentence);
    int words;

    //string* wordsArray = createWordsArray(userSentence, &words);
    return 0;
}
