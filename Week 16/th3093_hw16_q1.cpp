#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>

//need to account for if vector is empty BEFORE calling pop
using namespace std;

class Stack {
private:
    vector<char> vec;
    char popped;
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
    void check_checker(){
        for(int i = 0; i < vec.size(); i++) {
            cout<<vec[i];
        }
        cout<<endl;
    }

};

bool pascal(ifstream& inFile){
    string begin;
    string content;
    string end;
    char check;
    Stack checker;

    //reads in file and targets content between start and end
    inFile.open("content.txt");
    if (!inFile) {
        cout<<"Failed to open file";
        return false;
    }
    inFile >> begin >> content >> end;
    inFile.close();
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
                if (check == '{') {
                    if (content[i] != '}')
                        return false;
                }
                if (check == '[') {
                    if (content[i] != ']')
                        return false;
                }
                if (check == '(') {
                    if (content[i] != ')')
                        return false;
                }

            }
            else
                return false;
        }
        //if the Stack is empty and a closing bracket is added, that would be not allowed
    }

    //finally, check if there are any unattended opening brackets left after the full length of content
    if(!checker.isEmpty())
        return false;
    //if all of this passes, then it is legitimate
    else
        return true;
}

int main() {
    ifstream inFile;
    if(pascal(inFile))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}