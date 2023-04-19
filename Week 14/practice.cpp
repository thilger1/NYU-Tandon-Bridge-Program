#include <iostream>
using namespace std;

int sortedSearch(int strArr[], int srtArrSize, int val);

int main() {
    int srtArr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout<<sortedSearch(srtArr, 10, 13)<<endl;
    return 0;
}

int sortedSearch(int srtArr[], int srtArrSize, int val) {
    int low, high, mid, ind;
    bool found;
    low = 0;
    high = srtArrSize - 1;
    found = false;
    while (found == false) {
        mid = (low + high) / 2;
        if (srtArr[mid] == val) {
            ind = mid;
            found = true;
        }
        else if (val < srtArr[mid])
            high = mid - 1;
        else //val > srt[mid]
            low = mid + 1;
    }
}