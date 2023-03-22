#include <iostream>
#include <vector>
using namespace std;

int f(int* n, int m) {
    *n = 10;
    m = 10;
    return *n + m;
}