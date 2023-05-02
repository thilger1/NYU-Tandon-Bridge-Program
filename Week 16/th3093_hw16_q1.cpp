#include <vector>
#include <iostream>

using namespace std;

class Stack {
private:
    vector<char> vec;
    int popTrack = 0;
public:
    void push(char newItem) { vec.push_back(newItem);}
    char pop() { popTrack += 1; return vec[popTrack-1];}
    char top() { return vec[popTrack]; }
    char 
};

int main() {
    return 0;
}