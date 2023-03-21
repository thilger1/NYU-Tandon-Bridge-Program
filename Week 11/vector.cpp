#include <iostream>
#include <vector>
using namespace std;

void fun (vector<int>& blah) {
    for (int i = 1; i < 10; i++) {
        blah.push_back(i);
    }
}

int main() {
    vector<int> numbers;
    fun(numbers);

    for (int i =0; i < 10; i++) {
        cout<<numbers[i] << endl;
    }

    return 0;
}