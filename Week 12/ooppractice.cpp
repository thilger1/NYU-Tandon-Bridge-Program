#include <iostream>
#include <string>
using namespace std;

int main() {
    typedef char* CharArray;
    CharArray charptr = new char[10];
    for (int i = 0; i < 10; i++) {
        charptr[i] = 'a';
        cout<<charptr[i]<<" ";
    }
    delete[] charptr;
    
    return 0;
}