#include <iostream>
#include <string>
using namespace std;

int main() {
    int a[10];
    int *p = a;
    int i;
    for (i = 0; i < 10; i++) {
        a[i] = i;
    }
    for (i = 0; i < 10; i++) {
        cout<<a[i] << " ";
    }
    cout<<endl;
    
    return 0;
}