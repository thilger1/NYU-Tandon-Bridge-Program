#include <iostream>
#include <vector>
using namespace std;

void script(int line) {
    if (line == 1) {
        cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl
        <<"End your input by typing -1."<<endl;
    }
    if (line == 2) {
        cout<<"Please enter a number you want to search: ";
    }
}



void doubleArray(int*& arr, int& size, int doubled_size) {
    int* temp = new int[doubled_size];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    delete[] arr;

    arr = temp;
    size = doubled_size;
}

void wheresNumArr(int search_num, int arr[], int size) {
    int results[size];
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == search_num) {
            results[count] = i;
            count++;
        }
    }
    cout<<search_num<<" shows in lines: ";
    for (int i = 0; i < count; i++) {
        cout<<(results[i]) + 1;
        if (i != count -1)
            cout<<", ";
    }
    cout<<endl;
}

void wheresNumVect(int search_num, vector<int>& vect, int size) {
    vector<int> results;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (vect[i] == search_num) {
            results.push_back(i);
            count++;
        }
    }
    cout<<search_num<<" shows in lines: ";
    for (int i = 0; i < count; i++) {
        cout<<(results[i]) + 1;
        if (i != count -1)
            cout<<", ";
    }
}

void main1() {
    int search_num;
    int input;
    int counter = 0;
    int size = 20;
    int* arr = new int[size];
    script(1);
    while (input != -1) {
        cin >> input;
        if (input != -1) {
            if (counter == size) {
                doubleArray(arr, size, size * 2);
            }
            else {
                arr[counter] = input;
                counter++;
            }
        }
    }
    script(2);
    cin>>search_num;
    wheresNumArr(search_num, arr, size);
}

void main2() {
    vector<int> vect;
    int search_num;
    int input;
    int count = 0;
    script(1);

    while(input != -1) {
        cin >> input;
        if (input != -1) {
            count++;
            vect.push_back(input);
        }
    }
    script(2);
    cin >> search_num;
    wheresNumVect(search_num, vect, count);
}

int main() {
    main1();
    main2();
    return 0;
}


