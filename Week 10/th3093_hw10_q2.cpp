#include <iostream>
using namespace std;

//int* findMissing(int arr[], int n, int& resArrSize) {

//}

int main() {
    int arr[6] = {3, 1, 3, 0, 6, 4};
    int resArrSize = 0;
    int newArr[] = findMissing(arr, arr.length(), resArrSize);
    return 0;
}