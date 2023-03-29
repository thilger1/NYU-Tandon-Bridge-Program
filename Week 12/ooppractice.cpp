#include <iostream>
#include <string.h>
using namespace std;

class Vorlon {
public: 
    Vorlon(const string& aName) : myName(aName) {}
    void display() {cout << "Displaying a Vorlon named " << myName << endl;}
private:
    string myName;
}
//remember semicolon at the end or it wil get an error

int main() {
    Vorlon v2("Kosh");
    Vorlon v3(v1);
    Vorlon v4 = v1;
    return 0;
}

