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
    int size() { return vec.size(); }
    bool isEmpty { return vec.size() == 0;}
    void clear() { vec.clear(); }

};

bool pascal(){

}

int main() {
    if(pascal())
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}