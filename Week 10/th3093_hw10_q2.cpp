#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize) {
    int* missing = new int[n + 1];
    for (int i = 0; i <= n; i++)
        missing[i] = 0;
    for (int i = 1; i < n; i++)
        missing[arr[i] - 1] = 1;
    for (int i = 0; i < n; i++){}
    int* existing = arr[highest-lowest];
    int count = 0;
    for (int i = lowest; i < highest; i++) {
        if ()
    }
}

int main() {
    int arr[6] = {3, 1, 3, 0, 6, 4};
    int resArrSize = 0;
    int* newArr = findMissing(arr, arr.length(), resArrSize);
    delete[] newArr;
    newArr = nullptr;
    return 0;
}