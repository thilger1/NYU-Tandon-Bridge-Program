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
    int x = 3;
    int *ptr = nullptr;
    ptr = &x;
    *ptr += 1;
    for (int i =0; i < 10; i++) {
        cout<<numbers[i] << endl;
    }
    cout<<"x: " + x<<endl;

    return 0;
}