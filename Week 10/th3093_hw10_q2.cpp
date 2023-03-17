#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize) {

    int* temp = new int[n + 1];
    for (int i = 0; i < n; i++){
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++){
        temp[arr[i]]++;
    }
    int* missing = new int[n];
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (temp[i] == 0) {
            missing[count] = i;
            count++;
        }
    }
    resArrSize = count;
    delete[] temp;
    temp = nullptr;
    return missing;
}

int main() {
    int arr[6] = {3, 1, 3, 0, 6, 4};
    int resArrSize;
    int* newArr = findMissing(arr, 6, resArrSize);
    cout<<"[";
    for (int i = 0; i < resArrSize; i++) {
        cout<<newArr[i];
        if (i != resArrSize - 1)
            cout<<", ";
    }
    cout<<"]";
    delete[] newArr;
    newArr = nullptr;
    return 0;
}