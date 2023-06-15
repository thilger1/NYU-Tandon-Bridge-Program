#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Stack {
    vector<char> vec;
    char popped;
public:
    void push(char newItem) {vec.push_back(newItem);}
    char pop() {
        popped = vec[vec.size() - 1];
        vec.pop_back();
        return popped;
    }
    char top() { return vec[vec.size() - 1]; }
    int size() 


    inFile.open("content.txt");
    for (int i = 0; i < content.length(); i++) {
        if (content[i] == '{')
    }
    inFile.close();
}