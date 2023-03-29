#include <iostream>
using namespace std;

class Simple {
public:
    void display() {cout << "Displaying a Simple object\n";}
};
//remember semicolon at the end or it wil get an error

int main() {
    Simple simpleton;
    simpleton.display();
    return 0;
}

