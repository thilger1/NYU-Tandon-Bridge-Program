#include <iostream>
#include <vector>
using namespace std;

void script(int line) {
    if (line == 1) {
        cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl
        <<"End your input by typing -1."<<endl;
    }
    if (line == 2) {
        cout<<"Please enter a number you want to search"
    }
}

void versionOne() {
    int search_num;
    int input;
    script(1);
    while (input != -1) {
        cin>>input;
    }
    script(2);
    cin>>search_num;
}

void versionTwo() {
    vector<int> vect;
    int search_num;
    int input;
    script(1);

    while(input != -1) {
        cin >> input;
        vect.push_back(input);
    }
    script(2);
    cin >> search_num;


}




int main() {
    
}


