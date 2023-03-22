#include <iostream>
#include <vector>
using namespace std;

//Given an array of numbers, write a function to move all 0s to the end of the array while maintaining the relative order of the non-zero elements. Do this in-place. Should run O(n)
//Example: [0, 2, 0, 1, 0] -> [2, 1, 0, 0, 0]

//making changes in place means that you cannot create a new array, need to redo

void moveZeroes(int nums[], int n) {
    int zeroCount = 0;
    int count = 0;
    int newNums[n];
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zeroCount++;
        }
        else { 
            newNums[count] = nums[i];
            count++;
        }
    }
    for (int i = 0; i < zeroCount; i++) {
        newNums[count + i] = 0;
        }
    for (int i = 0; i < n; i++) {
        cout<<newNums[i]<<" ";
        }
    cout<<endl;
}

int main() {
    int nums[5] = {0, 2, 0, 1, 0};
    int length = 5;
    moveZeroes(nums, length);
    return 0;
}