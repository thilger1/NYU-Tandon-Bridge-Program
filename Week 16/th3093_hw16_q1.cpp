#include <vector>
#include <iostream>
#include <string.h>

//need to account for if vector is empty BEFORE calling pop

using namespace std;

class Stack {
private:
    vector<char> vec;
    char popped;
    int size;
public:
    void push(char newItem) { vec.push_back(newItem);}
    char pop() { 
        popped = vec[vec.size() - 1];
        vec.pop_back();
        return popped;
    }
    char top() { return vec[vec.size() - 1]; }
    int size() { return vec.size(); }
    bool isEmpty() { return vec.size() == 0;}
    void clear() { vec.clear(); }

};

bool pascal(){
    string begin;
    string content;
    string end;
    char check;
    Stack checker;
    cout<<"Please enter your content."<<endl;
    cin>>begin;
    cin>>content;
    cin>>end;
    for (int i = 0; i < content.length(); i++) {
        if (content[i] == '{' || content[i] == '(' || content[i] == '[') {
            checker.push(content[i]);
        }
        if (content[i] == '}' || content[i] == ')' || content[i] == ']') {
            check = Stack.
        }
    }

}

int main() {
    if(pascal())
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}