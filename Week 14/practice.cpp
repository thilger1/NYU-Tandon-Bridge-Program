#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v) { //Runtime: Theta(N^2)
    for (int i = 0; i < v.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
            if (v[j] < v[minIndex])
                    minIndex = j;
            int temp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = temp;
    }
}
void insertionSort(vector)
