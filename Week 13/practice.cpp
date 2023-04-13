#include <iostream>
#include <string.h>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout<<"Animal speaks" <<endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout<< "Meow" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout<< "Woof" << endl;
    }
};

void speakTwice(Animal* animalPtr) {
    animalPtr->speak();
    animalPtr->speak();
}

int main() {
    Cat cat;
    Dog dog;
    speakTwice(&cat);
    speakTwice(&dog);
    return 0;
}