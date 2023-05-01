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
    else {
        vector<int> left_vec;
        vector<int> right_vec;
        int vec_mid = vec.size() / 2;

        for (int i = 0; i < vec_mid; i++) {
            left_vec.push_back(vec[i]);
        }
        for (int i = vec_mid; i < vec.size(); i++) {
            right_vec.push_back(vec[i]);
        }
        divAndConq(right_vec, right_vec.size(), max, min);
        divAndConq(left_vec, left_vec.size(), max, min);
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