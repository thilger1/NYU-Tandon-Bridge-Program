#include <iostream>
#include <string.h>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize) {
    int spaceIndex = 0;
    int words = 0;
    int sentenceLength = sentence.length();
    string* wordsArray = new string[sentenceLength];

    for (int i = 0; i < sentenceLength; i++) {
        if (sentence[i] == ' ' || sentence[i] == '.') {
            wordsArray[words] = sentence.substr(spaceIndex + 1, i - spaceIndex);
            words++;
            spaceIndex = i;
        }
        //if no spaces or periods in the sentece
        
    }
    wordsArray[words] = sentence.substr(spaceIndex + 1);
    words++;
    outWordsArrSize = words;
    return wordsArray;
}

int main() {
    string userSentence;
    cout<<"Please enter a sentence"<<endl;
    getline(cin, userSentence);
    int words;

    string* wordsArray = createWordsArray(userSentence, &words);
    cout<<"Words: ";
    for (int i = 0; i < words; i++) { 
        cout<<wordsArray[i];
        if (i != words-1)
            cout<<", ";
    }
    cout<<endl;
    delete[] wordsArray;
    wordsArray = nullptr;
    return 0;
}
