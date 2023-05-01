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
void insertionSort(vector<int>&v) { //Runtime: Theta(N^2)  best: Theta(N)   worst case: Theta(N^2)
    for (int i = 1; i < v.size(); i++) {
        int j = i;
        int temp = v[i];
        while (j > 0 && v[j - 1] > temp) {
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
}
