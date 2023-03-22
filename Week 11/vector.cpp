#include <iostream>
#include <vector>
using namespace std;

int f(int* n, int m) {
    *n = 10;
    m = 10;
    return *n + m;
}

int main() {
    int n = 5;
    int m = 5;
    int res = f(&n, m);
    cout<<res + n + m <<endl;
}