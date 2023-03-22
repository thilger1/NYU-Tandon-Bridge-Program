#include <iostream>
#include <vector>
using namespace std;

//back to passing pointers

void increasePrice(double* price) {
    *price *= 1.2;
}

int main() {
    double price = 100;
    increasePrice(&price);
    cout << price;

    return 0;
}