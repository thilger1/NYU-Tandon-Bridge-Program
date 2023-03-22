#include <iostream>
#include <vector>
using namespace std;

//back to passing pointers

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int first = 1;
    int second = 2;
    swap(&first, &second);
    cout<<first<<" "<<second<<endl;
    return 0;
}