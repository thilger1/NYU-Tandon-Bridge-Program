#include <iostream>
using namespace std;

void printAscending(int start, int end) {
    //step 1: base case
    if (start == end) {
        cout<<start<<endl;
    //step 2: recursive step
    //define the inductive hypothesis (if we call print ascending, it will print the numbers in that range)
    }
    else {
        printAscending(start, end-1);
        cout<<end<<endl;
    }
}

int main() {

    printAscending(3, 6);
    return 0;
}