#include <iostream>
#include <vector>
using namespace std;

void divAndConq(vector <int> vec, int n, int &max, int &min) {
    if (n < 1)
        cout<<"Vector is empty!"<<endl;
    if (n == 1) {
        max = vec[0];
        min = vec[0];
    }
    if (n == 2) {
        if (vec[0] > vec[1]) {
            max = vec[0];
            min = vec[1];
        }
        if (vec[0] < vec[1]) {
            max = vec[1];
            min = vec[0];
        }
        else
            cout<<"Max and min are equal";
    }
}

int main() {
    vector <int> vec = {1, 2, 4, 5, 6, 7};
    int n = vec.size();
    int max, min;
    divAndConq(vec, n, max, min);
    cout<<"Max: "<<max<<", Min: "<<min<<endl;
    return 0;
}