#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3};
    v1.push_back(9);
    cout<< v1.capacity() << endl;
    return 0;
}