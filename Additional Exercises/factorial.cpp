#include <iostream>
using namespace std;

int factorial(int n) {
    int res;
    if (n == 1) {
        return 1;
    }
    else {
        res = factorial(n-1);
        res *= n;
        return res;
    }
}

bool areAllEven(int[] arr, int n) {
    bool res;
    if (n == 1) {
        return (arr[0] % 2 == 0);
    }

    else {
        res = areAllEven(arr, n-1);
        if (res == true) {
            return (arr[n-1] % 2 == 0);
        }
        else { 
            return false;
        }
    }
}


int main() {
    int arr[4] = {2, 20, 46, 14};
    if (areAllEven(arr, 4) == true) {
        cout<<"All are even"<<endl;
    }
    else {
        cout<<"Not all are even"<<endl;
    }
    return 0;
}