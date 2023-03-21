#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    for (int i = 1; i <= 10; i++) {
        numbers.push_back(i);
    }

    for (int j = 0; j < 10; j++) {
        cout<<numbers[i] <<endl;
    }

    return 0;
}