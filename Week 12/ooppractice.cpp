#include <iostream>
using std::string;

class Dog :public Pet {
    double erSize;

    public:
        Dog() : Pet (2000) {}
        void speak() const {cout << "WOOF!"<<endl;}
        void setSize (double newSize) {earSize = newSize;}
        double getSize()const{ return earSize; }
};

int main() {
    Pet** pArray = new Pet*[3];
    pArray[0] = new Cat();
    pArray[1] = new Dog();
    pArray[2] = new Cat();
    for (int i = 0; i < 3; i++)
        pArray[i]->speak();
}