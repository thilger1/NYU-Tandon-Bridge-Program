#include <iostream>
#include <string.h>
using namespace std;

class Simple {
public:
    void display() {cout << "Displaying a Simple object\n";}
};

class Vorlon {
public:
    Vorlon(const string& aName) {myName = aName;}
    void display() {cout << "Displaying a Vorlon named " << myName << endl;}
private:
    string myName;
};
//remember semicolon at the end or it wil get an error

int main() {
    Vorlon v2("Kosh");
    v2.display();
    return 0;
}

