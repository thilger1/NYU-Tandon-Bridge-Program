// Ted Hilger - th3093

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> vect();
int* storeString(string S) {
    string* ptr = &S;
    vect.push_back(ptr);
}

void testString(string S, int length, int &counter) {
    bool pass = false;
    new int arr[length];
    for (int i = 0; i < length; i++) {
        if (S[i] < 97 || S[i] > 123) {
            int pass = true;
        }
        else 
    }
    if (pass = false) {
        delete[] arr;
        counter++;
    }
    else {
        storeString(arr);
    }
}

int main() {
    int notCounter = 0;
    string userInput;
    while (userInput != " "){
        if (userInput == " ") {
            return;
        }
        else {
            getline(cin, userInput);
            int length = userInput.length();
            testString(userInput, length, notCounter);
        }  

        for (int i = 0; i < vect.length(); i++) {
            cout<<&vect[i]<<endl;
        }
    
        cout<<"Number of strings in the input sequence that contain only lowercase English letters: "<<counter<<endl;

    }

    return 0;
}