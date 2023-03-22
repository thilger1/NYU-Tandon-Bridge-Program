#include <iostream>
using namespace std;

//check to see if an array is sorted or not recursively
//base case: 1 element (or 8)
//start at end of array

bool isSorted(int* S, int length){
    //base case
    if (length == 1 || length == 0) {
        return true;
    }
    //recursive case check if the first element is greather than or equal to second element
    if (S[0] >= S[1]) {
        return isSorted(S+1, length-1);

    }
    return false;
}

const int LENGTH = 8;
int main() {
    int arr[LENGTH] = {100, 75, 27, 15, 8, -5, -5, -10};
    cout<< boolalpha << isSorted(arr, LENGTH);

    return 0;
}
