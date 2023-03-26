#include <iostream>
using namespace std;

void printAscending(int start, int end) {
    //step 1: base case
    int mid;
    if (start == end) {
        cout<<start<<endl;
    //step 2: recursive step
    //define the inductive hypothesis (if we call print ascending, it will print the numbers in that range)
    }
    else {
        mid = (start + end)/2;
        printAscending(start, mid);
        printAscending(mid+1, end);
    }
}

void printAscAndDesc (int start, int end) {
    if (start == end) {
        cout<<start<<endl;
    }
    else {

    }
}

int main() {

    printAscending(3, 6);
    printAscAndDesc(3, 6);
    return 0;
}