#include <iostream>
#include <string.h>
using namespace std;

class Animal {
public:
    ~Animal(){}
    virtual void eat(){
        cout<<"The animal ate!"<<endl;
    }
    virtual void makeSound() {
        cout<<"ANIMAL NOISE!"<<endl;
    }
};

class Cat : public Animal {
public:
    void eat() {
        cout<<"The cat ate!"<<endl;
    }
    void makeSound() {
        cout<<"CAT NOISE!"<<endl;
    }
};

class Dog : public Animal {
public:
    void eat() {
        cout<<"The dog ate!"<<endl;
    }
    void makeSound() {
        cout<<"DOG NOISE!"<<endl;
    }
};

int main() {
    Animal* dogPtr = new Dog();
    Animal* catPtr = new Cat();
    dogPtr->makeSound();
    catPtr->makeSound();
    delete dogPtr;
    delete catPtr;
    return 0;
}