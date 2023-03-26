#include <iostream>
using namespace std;

void printAscending(int start, int end) {
    //step 1: base case
    if (start == end) {
        cout<<start<<endl;
    }
}

int main() {

    printAscending(3, 6);
    return 0;
}