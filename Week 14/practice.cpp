#include <iostream>
using namespace std;

int findIndexOfMin(int arr[], int low, int high) {
    int min, minInd;

    min = arr[low];
    minInd = low;
    for (int i = low+1; i <= high; i++){
        if (arr[i] < min) {
            min = arr[i];
            minInd = i;
        }
    }
    return minInd;
}

void selectionSort(int arr[], int arrSize) {
    int i, minInd;

    for (i = 0; i < arrSize; i++) {
        minInd = findIndexOfMin(arr, i, arrSize-1);
        swap(arr[i], arr[minInd]);
    }
}