#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>

//need to account for if vector is empty BEFORE calling pop
using namespace std;

ifstream fin;

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
    //checks each char within content
    for (int i = 0; i < content.length(); i++) {
        //opening bracket is pushed onto stack
        if (content[i] == '{' || content[i] == '(' || content[i] == '[') {
            checker.push(content[i]);
        }
        //a closing bracket is checked against most recent push
        if (content[i] == '}' || content[i] == ')' || content[i] == ']') {
            if (!checker.isEmpty()) {
                check = checker.pop();
                switch(check) {
                    case '{':
                        if (content[i] != '}')
                            return false;
                    case '(':
                        if (content[i] != ')')
                            return false;
                    case '[':
                        if (content[i] != ']')
                            return false;
                }
            }
            //if the Stack is empty and a closing bracket is added, that would be not allowed
            else
                return false;
        }
    }
    //finally, check if there are any unattended opening brackets left after the full length of content
    if(!checker.isEmpty())
        return false;
    //if all of this passes, then it is legitimate
    else
        return true;
}

int main() {
    if(pascal())
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}