#include <iostream>
#include <string>
using namespace std;

class Thing {
public:
    string name;
    int age;

void demoThisFunc() const{
    cout<<this<<endl;
}
};

int main() {
    Thing lamp;
    lamp.demoThisFunc();
    return 0;
}