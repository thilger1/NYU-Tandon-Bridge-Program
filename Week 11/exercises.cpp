#include <iostream>
using namespace std;

//check to see if an array is sorted or not recursively
//base case: 1 element (or 8)
//start at end of array

bool isSorted(int* S, int length) {
    //base case
    if (length == 0 || length == 1) {
        return true;
    }
    if (S[0] >= S[1]) {
        return isSorted(S+1, length-1);
    }
    return false;
}

const int LENGTH = 5;
int main() {
    int arr[LENGTH] = {5, 4, 3, 2, 1};
    cout<< boolalpha << isSorted(arr, LENGTH);
    return 0;
}
