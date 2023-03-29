#include <iostream>
#include <string.h>
using namespace std;

class Simple {
public:
    void display() {cout << "Displaying a Simple object\n";}
};

class Vorlon {
public:
    void display() {cout << "Displaying a Vorlon named " << myName << endl;}
private:
    string myName;
};
//remember semicolon at the end or it wil get an error

int main() {
    Vorlon v1;
    v1.myName = "Kosh";
    v1.display();
    return 0;
}

