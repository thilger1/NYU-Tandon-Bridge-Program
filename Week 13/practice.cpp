#include <iostream>
using namespace std;

int findLargest(int* array, int n) {
    int largest = *array;
    for (int i = 1; i < n; i++) {
        if (array[i] > largest)
            largest = array[i];
    }
    return largest;
}

int main() {
    int arr[5] = {3, 20, 5, 9, 1};
    int answer = findLargest(arr, 5);
    cout<<answer<<endl;
    return 0;
}