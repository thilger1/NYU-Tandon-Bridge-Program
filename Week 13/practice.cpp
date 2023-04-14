#include <iostream>
#include <string.h>
using namespace std;

int findLargest(int* array, int n) {
    int largest = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > largest)
            largest = array[i];
    }
    return largest;
}

int main() {
    int arr[5] = {3, 20, 5, 9, 1};
    findLargest(arr, 5);
    return 0;
}