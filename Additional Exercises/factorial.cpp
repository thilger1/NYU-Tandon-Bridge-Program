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

bool areAllEven(int[], arr, int n);


int main() {
    cout<<factorial(4)<<endl;
    areAllEven([4, 6, 0, 2], 4);
    return 0;
}