#include <iostream>
using namespace std;

class Thing {
    int num;
public:
    Thing(int newnum = 0) :num(newnum) {}
    int getNum() const{};
    void setNum(int newnum) {num = newnum;}

};

int main() {
    Thing one(1);
    cout<<one.getNum()<<endl;
    return 0;
}