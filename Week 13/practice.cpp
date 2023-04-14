#include <iostream>
#include <string.h>
using namespace std;

class Vehicle {
public:
    ~Vehicle(){}
    void virtual drive(){
        cout<<"Driving a vehicle"<<endl;
    }
};

class Car : public Vehicle {
public:
    void drive(){
        cout<<"Driving a car"<<endl;
    }
};

class Motorcycle : public Vehicle {
public:
    void drive(){
        cout<<"Driving a motorcycle"<<endl;
    }
};

int main() {
    Vehicle* carPtr = new Car();
    Vehicle* motoPtr = new Motorcycle();
    carPtr->drive();
    motoPtr->drive();
    delete carPtr;
    delete motoPtr;
    return 0;
}