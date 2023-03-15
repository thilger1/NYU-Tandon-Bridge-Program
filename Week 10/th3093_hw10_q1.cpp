#include <iostream>
#include <string.h>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize) {
    //setting first spaceIndex to -1 to start first word before the sentence starts
    //subsequent words will start after spaces
    int spaceIndex = -1;
    int words = 0;
    int sentenceLength = sentence.length();
    string* wordsArray = new string[sentenceLength];

    for (int i = 0; i < sentenceLength; i++) {
        if (sentence[i] == ' ' || sentence[i] == '.') {
            wordsArray[words] = sentence.substr(spaceIndex + 1, i - spaceIndex - 1);
            words++;
            spaceIndex = i;
        }
    
    //if no spaces or periods in the sentence
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

    string* wordsArray = createWordsArray(userSentence, words);
    cout<<"[";
    for (int i = 0; i < words; i++) { 
        cout<<"\""<<wordsArray[i]<<"\"";
        if (i != words-1)
            cout<<", ";
        else
            cout<<"]";
    }
    cout<<endl;
    delete[] wordsArray;
    wordsArray = nullptr;
    return 0;
}
